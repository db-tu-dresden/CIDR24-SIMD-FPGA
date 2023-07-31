#include "agg_helper.hpp"
#ifdef SSE
#include "sse_agg.hpp"
#elif defined(AVX)
#include "avx_agg.hpp"
#elif defined(AVX512)
#include "avx512_agg.hpp"
#endif
#include "../include/data.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

std::string cpu_name(tuddbs::get_cpu_name());
size_t REPEATS;

std::ofstream aggregate_results;
std::ofstream masked_aggregate_results;

#ifdef SSE
  #ifdef AVX512VL
    auto const simd_flavor = "SSE + AVX512VL";
  #else
    auto const simd_flavor = "SSE";
  #endif
  auto const simd_size = 16;
#elif defined(AVX)
  #ifdef AVX512VL
    auto const simd_flavor = "AVX + AVX512VL";
  #else
    auto const simd_flavor = "AVX";
  #endif
  auto const simd_size = 32;
#elif defined(AVX512)
  auto const simd_flavor = "AVX512";
  auto const simd_size = 64;
#endif

namespace tuddbs {
  template<typename T>
    void run_aggregate(
      T const * __restrict__ measurement_data,
      T const * __restrict__ flush_data, 
      size_t byte_size
    ) {
      for (size_t i = 0; i < REPEATS; ++i) {
        std::cerr << i << ". " << std::flush;
        // SCALAR_AGG.HPP
        {
          auto start = current_time();
          #ifdef SSE
            auto result = aggregate_SSE<T>(measurement_data, byte_size/sizeof(T));
          #elif defined(AVX)
            auto result = aggregate_AVX<T>(measurement_data, byte_size/sizeof(T));
          #elif defined(AVX512)
            auto result = aggregate_AVX512<T>(measurement_data, byte_size/sizeof(T));
          #endif
          auto end = current_time();
          aggregate_results << cpu_name << "\t"
                            << COMPILER << "\t"
                            << VERSION << "\t"
                            << ARCH << "\t"
                            << i << "\t"
                            << "aggregate" << "\t" 
                            << simd_flavor << "\t"
                            << simd_size/sizeof(T) << "\t"
                            << byte_size << "\t"
                            << sizeof(T) << "\t"
                            << byte_size/sizeof(T) << "\t"
                            << result << "\t"
                            << time_diff(start, end) << "\t";
        }
        {          
          #ifdef SSE
            auto result_flush = aggregate_SSE<T>(flush_data, FLUSH_SIZE/sizeof(T));
          #elif defined(AVX)
            auto result_flush = aggregate_AVX<T>(flush_data, FLUSH_SIZE/sizeof(T));
          #elif defined(AVX512)
            auto result_flush = aggregate_AVX512<T>(flush_data, FLUSH_SIZE/sizeof(T));
          #endif
          aggregate_results << result_flush << std::endl;
        }
      }
      std::cerr << std::endl;
    }

  template<typename T>
    void run_masked_aggregate(
      T const * __restrict__ measurement_data, void * __restrict__ measurement_bitmap, 
      T const * __restrict__ flush_data, void * __restrict__ flush_bitmap, 
      size_t byte_size, float selectivity
    ) {
      tuddbs::read_bytes_from_file(
        measurement_bitmap, 
        tuddbs::get_bitmask_size<T>(byte_size), 
        tuddbs::get_bitmask_filename_from_size_and_selectivity<T>(byte_size, selectivity, false)
      );
      tuddbs::read_bytes_from_file(
        flush_bitmap, 
        tuddbs::get_bitmask_size<T>(FLUSH_SIZE), 
        tuddbs::get_bitmask_filename_from_size_and_selectivity<T>(FLUSH_SIZE, 1, true)
      );

      for (size_t i = 0; i < REPEATS; ++i) {
        std::cerr << i << ". " << std::flush;
        {
          auto start = current_time();
          #ifdef SSE
            auto result = aggregate_SSE<T>(measurement_data, byte_size/sizeof(T), measurement_bitmap);
          #elif defined(AVX)
            auto result = aggregate_AVX<T>(measurement_data, byte_size/sizeof(T), measurement_bitmap);
          #elif defined(AVX512)
            auto result = aggregate_AVX512<T>(measurement_data, byte_size/sizeof(T), measurement_bitmap);
          #endif
          auto end = current_time();
          masked_aggregate_results  << cpu_name << "\t"
                                    << COMPILER << "\t"
                                    << VERSION << "\t"
                                    << ARCH << "\t"
                                    << i << "\t"
                                    << "masked aggregate" << "\t" 
                                    << simd_flavor << "\t"
                                    << simd_size/sizeof(T) << "\t"
                                    << byte_size << "\t"
                                    << sizeof(T) << "\t"
                                    << byte_size/sizeof(T) << "\t"
                                    << (float)selectivity/100.0f << "\t"
                                    << result << "\t"
                                    << time_diff(start, end) << "\t";
        }
        {
          #ifdef SSE
            auto result_flush = aggregate_SSE<T>(flush_data, FLUSH_SIZE/sizeof(T), flush_bitmap);
          #elif defined(AVX)
            auto result_flush = aggregate_AVX<T>(flush_data, FLUSH_SIZE/sizeof(T), flush_bitmap);
          #elif defined(AVX512)
            auto result_flush = aggregate_AVX512<T>(flush_data, FLUSH_SIZE/sizeof(T), flush_bitmap);
          #endif
          masked_aggregate_results  << result_flush << std::endl;
        }
      }
      std::cerr << std::endl;      
    }


  template<typename T>
    void run_dtype(
      void * __restrict__ measurement_data,
      void * __restrict__ flush_data,
      size_t byte_size
    ) {
      auto measurement_bitmap = malloc(byte_size);
      auto flush_bitmap = malloc(tuddbs::get_bitmask_size<T>(FLUSH_SIZE));

      tuddbs::read_bytes_from_file(
        measurement_data, 
        byte_size, 
        tuddbs::get_data_filename_from_size<T>(byte_size, false)
      );
      tuddbs::read_bytes_from_file(
        flush_data, 
        FLUSH_SIZE, 
        tuddbs::get_data_filename_from_size<T>(FLUSH_SIZE, true)
      );

      std::cerr << "\tRunning aggregate. " << std::endl;
      run_aggregate<T>(reinterpret_cast<T const *>(measurement_data), reinterpret_cast<T const *>(flush_data), byte_size);
      std::cerr << "\tRunning masked aggregate. " << std::endl;
      for (auto i : selectivities) {
        std::cerr << "\t\tSelectivity: " << (float)i/100.0f << std::endl;
        run_masked_aggregate<T>(reinterpret_cast<T const *>(measurement_data), measurement_bitmap, reinterpret_cast<T const *>(flush_data), flush_bitmap, byte_size, i);
      }

      free(flush_bitmap);
      free(measurement_bitmap);
    }

  void run(size_t byte_size) {
    auto measurement_data = malloc(byte_size);
    auto flush_data = malloc(FLUSH_SIZE);
    
    std::cerr << "Running uint8_t. " << std::endl;
    run_dtype< uint8_t>(measurement_data, flush_data, byte_size);
    std::cerr << "Running uint16_t. " << std::endl;
    run_dtype<uint16_t>(measurement_data, flush_data, byte_size);
    std::cerr << "Running uint32_t. " << std::endl;
    run_dtype<uint32_t>(measurement_data, flush_data, byte_size);
    std::cerr << "Running uint64_t. " << std::endl;
    run_dtype<uint64_t>(measurement_data, flush_data, byte_size);

    free(flush_data);
    free(measurement_data);
    
  }

}

int main(int argc, char** argv) {

  if (!tuddbs::fileExists("masked_aggregate_results.tsv")) {
    masked_aggregate_results.open("masked_aggregate_results.tsv", std::ofstream::out | std::ofstream::app);
    masked_aggregate_results  << "device" << "\t"
                              << "compiler" << "\t"
                              << "version" << "\t"
                              << "arch-flags" << "\t"
                              << "rep" << "\t"
                              << "function" << "\t" 
                              << "variant" << "\t"
                              << "SIMD-elementCount" << "\t"
                              << "byte_size" << "\t"
                              << "element_size" << "\t"
                              << "element_count" << "\t"
                              << "selectivity" << "\t"
                              << "result" << "\t"
                              << "time_ns" << "\t"
                              << "flush_result" << std::endl;
  } else {
    masked_aggregate_results.open("masked_aggregate_results.tsv", std::ofstream::out | std::ofstream::app);
  }
  if (!tuddbs::fileExists("aggregate_results.tsv")) {
    aggregate_results.open("aggregate_results.tsv", std::ofstream::out | std::ofstream::app);
    aggregate_results << "device" << "\t"
                    << "compiler" << "\t"
                    << "version" << "\t"
                    << "arch-flags" << "\t"
                    << "rep" << "\t"
                    << "function" << "\t" 
                    << "variant" << "\t"
                    << "SIMD-elementCount" << "\t"
                    << "byte_size" << "\t"
                    << "element_size" << "\t"
                    << "element_count" << "\t"
                    << "result" << "\t"
                    << "time_ns" << "\t"
                    << "flush_result" << std::endl;
  } else {
    aggregate_results.open("aggregate_results.tsv", std::ofstream::out | std::ofstream::app);
  }

  char repeat_param[] = "--repeats";
  bool found_repeat = false;
  for (int i = 0; i < argc; ++i) {
    if (memcmp(argv[i], repeat_param, 6) == 0) {
      REPEATS = std::atoll(argv[i + 1]);
      found_repeat = true;
      break;
    }
  }
  if (!found_repeat) {
    std::cerr << "[WARNING] No --repeat given. Defaulting to 10." << std::endl;
    REPEATS = 10;
  } else {
    std::cerr << "[INFO] Executing experiments " << REPEATS << " times." << std::endl;
  }

  for (auto const size : tuddbs::data_sizes) {
    tuddbs::run(size);
  }

  masked_aggregate_results.close();
  aggregate_results.close();
  return 0;
}

