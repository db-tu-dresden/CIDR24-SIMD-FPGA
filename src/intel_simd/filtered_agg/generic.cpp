#include "agg_helper.hpp"
#include "scalar_agg.hpp"
#include "autovec_agg.hpp"
#include "../include/data.hpp"
#include "../include/utils.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

std::string cpu_name(tuddbs::get_cpu_name());
size_t REPEATS;

std::ofstream aggregate_results;
std::ofstream masked_aggregate_results;


namespace tuddbs {

  template<typename T, int BS>
    void run_aggregate_autovec(
      T const * __restrict__ measurement_data, 
      T const * __restrict__ flush_data, 
      size_t byte_size
    ) {
      // AUTOVEC_AGG.HPP
      std::cerr << "\t\tAutovec (Vec size: " << BS << ")" << std::flush;
      for (size_t i = 0; i < REPEATS; ++i) {
        std::cerr << i << ". " << std::flush;
        {
          auto start = current_time();
          auto result = aggregate_autovec_N<T, BS, HORIZONTAL_AGGREGATION_STRATEGY::ACCUM>(measurement_data, byte_size/sizeof(T));
          auto end = current_time();
          aggregate_results << cpu_name << "\t"
                            << COMPILER << "\t"
                            << VERSION << "\t"
                            << ARCH << "\t"
                            << i << "\t"
                            << "aggregate" << "\t" 
                            << "autovec - horizontal accum" << "\t"
                            << BS << "\t"
                            << byte_size << "\t"
                            << sizeof(T) << "\t"
                            << byte_size/sizeof(T) << "\t"
                            << result << "\t"
                            << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate_autovec_N<T, BS, HORIZONTAL_AGGREGATION_STRATEGY::ACCUM>(flush_data, FLUSH_SIZE/sizeof(T));
          aggregate_results << result_flush << std::endl;
        }
        {
          auto start = current_time();
          auto result = aggregate_autovec_N<T, BS, HORIZONTAL_AGGREGATION_STRATEGY::ARRAY_ADDER_TREE>(measurement_data, byte_size/sizeof(T));
          auto end = current_time();
          aggregate_results << cpu_name << "\t"
                            << COMPILER << "\t"
                            << VERSION << "\t"
                            << ARCH << "\t"
                            << i << "\t"
                            << "aggregate" << "\t" 
                            << "autovec - horizontal array adder tree" << "\t"
                            << BS << "\t"
                            << byte_size << "\t"
                            << sizeof(T) << "\t"
                            << byte_size/sizeof(T) << "\t"
                            << result << "\t"
                            << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate_autovec_N<T, BS, HORIZONTAL_AGGREGATION_STRATEGY::ARRAY_ADDER_TREE>(flush_data, FLUSH_SIZE/sizeof(T));
          aggregate_results << result_flush << std::endl;
        }
        {
          auto start = current_time();
          auto result = aggregate_autovec_N<T, BS, HORIZONTAL_AGGREGATION_STRATEGY::TUPL_ADDER_TREE>(measurement_data, byte_size/sizeof(T));
          auto end = current_time();
          aggregate_results << cpu_name << "\t"
                            << COMPILER << "\t"
                            << VERSION << "\t"
                            << ARCH << "\t"
                            << i << "\t"
                            << "aggregate" << "\t" 
                            << "autovec - horizontal tuple adder tree" << "\t"
                            << BS << "\t"
                            << byte_size << "\t"
                            << sizeof(T) << "\t"
                            << byte_size/sizeof(T) << "\t"
                            << result << "\t"
                            << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate_autovec_N<T, BS, HORIZONTAL_AGGREGATION_STRATEGY::TUPL_ADDER_TREE>(flush_data, FLUSH_SIZE/sizeof(T));
          aggregate_results << result_flush << std::endl;
        }
      }
      std::cerr << std::endl;
    }
  template<typename T>
    void run_aggregate(
      T const * __restrict__ measurement_data,
      T const * __restrict__ flush_data, 
      size_t byte_size
    ) {
      std::cerr << "\t\tScalar" << std::flush; 
      for (size_t i = 0; i < REPEATS; ++i) {
        std::cerr << i << ". " << std::flush;
        // SCALAR_AGG.HPP
        {
          auto start = current_time();
          auto volatile result = aggregate<T>(measurement_data, byte_size/sizeof(T));
          auto end = current_time();
          aggregate_results << cpu_name << "\t"
                            << COMPILER << "\t"
                            << VERSION << "\t"
                            << ARCH << "\t"
                            << i << "\t"
                            << "aggregate" << "\t" 
                            << "scalar" << "\t"
                            << "1" << "\t"
                            << byte_size << "\t"
                            << sizeof(T) << "\t"
                            << byte_size/sizeof(T) << "\t"
                            << result << "\t"
                            << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate<T>(flush_data, FLUSH_SIZE/sizeof(T));
          aggregate_results << result_flush << std::endl;
        }
      }
      std::cerr << std::endl;
      run_aggregate_autovec<T, 2>(measurement_data, flush_data, byte_size);
      run_aggregate_autovec<T, 4>(measurement_data, flush_data, byte_size);
      run_aggregate_autovec<T, 8>(measurement_data, flush_data, byte_size);
      run_aggregate_autovec<T, 16>(measurement_data, flush_data, byte_size);
      run_aggregate_autovec<T, 32>(measurement_data, flush_data, byte_size);
      run_aggregate_autovec<T, 64>(measurement_data, flush_data, byte_size);
      std::cerr << std::endl;
    }

  template<typename T, int BS>
    void run_masked_aggregate_autovec(
      T const * __restrict__ measurement_data, void * __restrict__ measurement_bitmap, 
      T const * __restrict__ flush_data, void * __restrict__ flush_bitmap, 
      size_t byte_size, size_t selectivity
    ) {
      std::cerr << "\t\t\tAutovec (Vec size: " << BS << ")" << std::flush; 
      for (size_t i = 0; i < REPEATS; ++i) {
        std::cerr << i << ". " << std::flush;
        {
          auto start = current_time();
          auto result = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY, HORIZONTAL_AGGREGATION_STRATEGY::ACCUM>(measurement_data, byte_size/sizeof(T), measurement_bitmap);
          auto end = current_time();
          masked_aggregate_results << cpu_name << "\t"
                            << COMPILER << "\t"
                            << VERSION << "\t"
                            << ARCH << "\t"
                            << i << "\t"
                            << "masked aggregate" << "\t" 
                            << "autovec - ternary add, horizontal accum" << "\t"
                            << BS << "\t"
                            << byte_size << "\t"
                            << sizeof(T) << "\t"
                            << byte_size/sizeof(T) << "\t"
                            << (float)selectivity/100.0f << "\t"
                            << result << "\t"
                            << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY, HORIZONTAL_AGGREGATION_STRATEGY::ACCUM>(flush_data, FLUSH_SIZE/sizeof(T), flush_bitmap);
          masked_aggregate_results << result_flush << std::endl;
        }
        {
          auto start = current_time();
          auto result = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE, HORIZONTAL_AGGREGATION_STRATEGY::ACCUM>(measurement_data, byte_size/sizeof(T), measurement_bitmap);
          auto end = current_time();
          masked_aggregate_results << cpu_name << "\t"
                            << COMPILER << "\t"
                            << VERSION << "\t"
                            << ARCH << "\t"
                            << i << "\t"
                            << "masked aggregate" << "\t" 
                            << "autovec - bitmask add, horizontal accum" << "\t"
                            << BS << "\t"
                            << byte_size << "\t"
                            << sizeof(T) << "\t"
                            << byte_size/sizeof(T) << "\t"
                            << (float)selectivity/100.0f << "\t"
                            << result << "\t"
                            << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE, HORIZONTAL_AGGREGATION_STRATEGY::ACCUM>(flush_data, FLUSH_SIZE/sizeof(T), flush_bitmap);
          masked_aggregate_results << result_flush << std::endl;
        }
        {
          auto start = current_time();
          auto result = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY, HORIZONTAL_AGGREGATION_STRATEGY::ARRAY_ADDER_TREE>(measurement_data, byte_size/sizeof(T), measurement_bitmap);
          auto end = current_time();
          masked_aggregate_results << cpu_name << "\t"
                            << COMPILER << "\t"
                            << VERSION << "\t"
                            << ARCH << "\t"
                            << i << "\t"
                            << "masked aggregate" << "\t" 
                            << "autovec - ternary add, horizontal array adder tree" << "\t"
                            << BS << "\t"
                            << byte_size << "\t"
                            << sizeof(T) << "\t"
                            << byte_size/sizeof(T) << "\t"
                            << (float)selectivity/100.0f << "\t"
                            << result << "\t"

                            << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY, HORIZONTAL_AGGREGATION_STRATEGY::ARRAY_ADDER_TREE>(flush_data, FLUSH_SIZE/sizeof(T), flush_bitmap);
          masked_aggregate_results << result_flush << std::endl;
        }
        {
          auto start = current_time();
          auto result = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE, HORIZONTAL_AGGREGATION_STRATEGY::ARRAY_ADDER_TREE>(measurement_data, byte_size/sizeof(T), measurement_bitmap);
          auto end = current_time();
          masked_aggregate_results << cpu_name << "\t"
                            << COMPILER << "\t"
                            << VERSION << "\t"
                            << ARCH << "\t"
                            << i << "\t"
                            << "masked aggregate" << "\t" 
                            << "autovec - bitmask add, horizontal array adder tree" << "\t"
                            << BS << "\t"
                            << byte_size << "\t"
                            << sizeof(T) << "\t"
                            << byte_size/sizeof(T) << "\t"
                            << (float)selectivity/100.0f << "\t"
                            << result << "\t"
                            << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE, HORIZONTAL_AGGREGATION_STRATEGY::ARRAY_ADDER_TREE>(flush_data, FLUSH_SIZE/sizeof(T), flush_bitmap);
          masked_aggregate_results << result_flush << std::endl;
        }
        {
          auto start = current_time();
          auto result = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY, HORIZONTAL_AGGREGATION_STRATEGY::TUPL_ADDER_TREE>(measurement_data, byte_size/sizeof(T), measurement_bitmap);
          auto end = current_time();
          masked_aggregate_results << cpu_name << "\t"
                            << COMPILER << "\t"
                            << VERSION << "\t"
                            << ARCH << "\t"
                            << i << "\t"
                            << "masked aggregate" << "\t" 
                            << "autovec - ternary add, horizontal tuple adder tree" << "\t"
                            << BS << "\t"
                            << byte_size << "\t"
                            << sizeof(T) << "\t"
                            << byte_size/sizeof(T) << "\t"
                            << (float)selectivity/100.0f << "\t"
                            << result << "\t"
                            << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY, HORIZONTAL_AGGREGATION_STRATEGY::TUPL_ADDER_TREE>(flush_data, FLUSH_SIZE/sizeof(T), flush_bitmap);
          masked_aggregate_results << result_flush << std::endl;
        }
        {
          auto start = current_time();
          auto result = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE, HORIZONTAL_AGGREGATION_STRATEGY::TUPL_ADDER_TREE>(measurement_data, byte_size/sizeof(T), measurement_bitmap);
          auto end = current_time();
          masked_aggregate_results << cpu_name << "\t"
                            << COMPILER << "\t"
                            << VERSION << "\t"
                            << ARCH << "\t"
                            << i << "\t"
                            << "masked aggregate" << "\t" 
                            << "autovec - bitmask add, horizontal tuple adder tree" << "\t"
                            << BS << "\t"
                            << byte_size << "\t"
                            << sizeof(T) << "\t"
                            << byte_size/sizeof(T) << "\t"
                            << (float)selectivity/100.0f << "\t"
                            << result << "\t"
                            << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE, HORIZONTAL_AGGREGATION_STRATEGY::TUPL_ADDER_TREE>(flush_data, FLUSH_SIZE/sizeof(T), flush_bitmap);
          masked_aggregate_results << result_flush << std::endl;
        }
      }
      std::cerr << std::endl;
    }

  template<typename T>
    void run_masked_aggregate(
      T const * __restrict__ measurement_data, void * __restrict__ measurement_bitmap, 
      T const * __restrict__ flush_data, void * __restrict__ flush_bitmap, 
      size_t byte_size, size_t selectivity
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

      std::cerr << "\t\t\tScalar: " << std::flush;
      for (size_t i = 0; i < REPEATS; ++i) {
        std::cerr << i << ". " << std::flush;
        // SCALAR_AGG.HPP
        {
          auto start = current_time();
          auto result = aggregate<T, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY>(measurement_data, byte_size/sizeof(T), measurement_bitmap);
          auto end = current_time();
          masked_aggregate_results  << cpu_name << "\t"
                                    << COMPILER << "\t"
                                    << VERSION << "\t"
                                    << ARCH << "\t"
                                    << i << "\t"
                                    << "masked aggregate" << "\t" 
                                    << "scalar - ternary add" << "\t"
                                    << "1" << "\t"
                                    << byte_size << "\t"
                                    << sizeof(T) << "\t"
                                    << byte_size/sizeof(T) << "\t"
                                    << (float)selectivity/100.0f << "\t"
                                    << result << "\t"
                                    << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate<T, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY>(flush_data, FLUSH_SIZE/sizeof(T), flush_bitmap);
          masked_aggregate_results  << result_flush << std::endl;
        }
        {
          auto start = current_time();
          auto result = aggregate<T, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE>(measurement_data, byte_size/sizeof(T), measurement_bitmap);
          auto end = current_time();
          masked_aggregate_results  << cpu_name << "\t"
                                    << COMPILER << "\t"
                                    << VERSION << "\t"
                                    << ARCH << "\t"
                                    << i << "\t"
                                    << "masked aggregate" << "\t" 
                                    << "scalar - bitmask add" << "\t"
                                    << "1" << "\t"
                                    << byte_size << "\t"
                                    << sizeof(T) << "\t"
                                    << byte_size/sizeof(T) << "\t"
                                    << (float)selectivity/100.0f << "\t"
                                    << result << "\t"
                                    << time_diff(start, end) << "\t";
        }
        {
          auto result_flush = aggregate<T, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE>(flush_data, FLUSH_SIZE/sizeof(T), flush_bitmap);
          masked_aggregate_results  << result_flush << std::endl;
        }
      }
      std::cerr << std::endl;
      run_masked_aggregate_autovec<T,  2>(measurement_data, measurement_bitmap, flush_data, flush_bitmap, byte_size, selectivity);
      run_masked_aggregate_autovec<T,  4>(measurement_data, measurement_bitmap, flush_data, flush_bitmap, byte_size, selectivity);
      run_masked_aggregate_autovec<T,  8>(measurement_data, measurement_bitmap, flush_data, flush_bitmap, byte_size, selectivity);
      run_masked_aggregate_autovec<T, 16>(measurement_data, measurement_bitmap, flush_data, flush_bitmap, byte_size, selectivity);
      run_masked_aggregate_autovec<T, 32>(measurement_data, measurement_bitmap, flush_data, flush_bitmap, byte_size, selectivity);
      run_masked_aggregate_autovec<T, 64>(measurement_data, measurement_bitmap, flush_data, flush_bitmap, byte_size, selectivity);
    }


  template<typename T>
    void run_dtype(
      void * __restrict__ measurement_data,
      void * __restrict__ flush_data,
      size_t byte_size
    ) {
      auto measurement_bitmap = malloc(tuddbs::get_bitmask_size<T>(byte_size));
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

int main(int argc, char ** argv) {

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
                              << "time_mus" << "\t"
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
                    << "time_mus" << "\t"
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

