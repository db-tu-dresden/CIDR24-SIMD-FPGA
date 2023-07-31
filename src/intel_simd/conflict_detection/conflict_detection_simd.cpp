#include <immintrin.h>
#include <cstring>
#include <fstream>
#include <cstdint>
#include <cstddef>
#include <bit>
#include <type_traits>
#include <array>
#include <limits>
#include <iomanip>
#include <climits>
#include "../include/datagen.hpp"
#include "../include/utils.hpp"


std::ofstream results_out;
std::string cpu_name(tuddbs::get_cpu_name());
size_t REPEATS;

namespace tuddbs{
  enum class MEM_TRANSFER_KIND {
    STREAM,
    LOAD
  };
  template<typename T, size_t VectorSizeInBit>
    constexpr bool is_conflict_detection_possible() {
      return (VectorSizeInBit / (CHAR_BIT * sizeof(T)) <= (CHAR_BIT * sizeof(T)));
    }


  template<typename T, size_t VectorSizeInBit>
    void run_conflict_detection_scalar(
      T * __restrict__ out,
      T const * __restrict__ data,
      size_t element_count
    ) {
      auto const batch_size = VectorSizeInBit/(CHAR_BIT*sizeof(T));
      auto const data_end = data + element_count;
      for (; data != data_end; data += batch_size, out += batch_size) {
        *out = 0;
        for (size_t i = 1; i < batch_size; ++i) {
          T val = 0;
          for (size_t j = 0; j < i; ++j) {
            val |= (data[i] == data[j]) ? ((T)1<<(T)j) : (T)0;
          }
          out[i] = val;
        }
      }
    }

  template<typename T, MEM_TRANSFER_KIND MTK, size_t SimdStepWidth = (16/sizeof(T))>
    void run_conflict_detection_sse(
      T * __restrict__ out,
      T const * __restrict__ data,
      size_t element_count
    ) {
      static_assert(sizeof(T) >= 4, "Conflict detection with Intel Intrinsics requires at least 4 byte per element.");
      auto const data_end = data + element_count;
      __m128i data_vec;
      __m128i result_vec;
      for (; data < data_end; data += SimdStepWidth, out += SimdStepWidth) {
        if constexpr (MTK == MEM_TRANSFER_KIND::LOAD) {
          data_vec = _mm_load_si128(reinterpret_cast<__m128i const *>(data));
        } else {
          data_vec = _mm_stream_load_si128(reinterpret_cast<__m128i *>(const_cast<T*>(data)));
        }
        if constexpr (sizeof(T) == 4) {
          result_vec = _mm_conflict_epi32(data_vec);
        } else {
          result_vec = _mm_conflict_epi64(data_vec);
        }
        if constexpr (MTK == MEM_TRANSFER_KIND::LOAD) {
          _mm_storeu_si128(reinterpret_cast<__m128i *>(out), result_vec);
        } else {
          _mm_stream_si128(reinterpret_cast<__m128i *>(out), result_vec);
        }
      }
    }

  template<typename T, MEM_TRANSFER_KIND MTK, size_t SimdStepWidth = (32/sizeof(T))>
    void run_conflict_detection_avx(
      T * __restrict__ out,
      T const * __restrict__ data,
      size_t element_count
    ) {
      static_assert(sizeof(T) >= 4, "Conflict detection with Intel Intrinsics requires at least 4 byte per element.");
      auto const data_end = data + element_count;
      __m256i data_vec;
      __m256i result_vec;
      for (; data < data_end; data += SimdStepWidth, out += SimdStepWidth) {
        if constexpr (MTK == MEM_TRANSFER_KIND::LOAD) {
          data_vec = _mm256_load_si256(reinterpret_cast<__m256i const *>(data));
        } else {
          data_vec = _mm256_stream_load_si256(reinterpret_cast<__m256i const *>(data));
        }
        if constexpr (sizeof(T) == 4) {
          result_vec = _mm256_conflict_epi32(data_vec);
        } else {
          result_vec = _mm256_conflict_epi64(data_vec);
        }
        if constexpr (MTK == MEM_TRANSFER_KIND::LOAD) {
          _mm256_storeu_si256(reinterpret_cast<__m256i *>(out), result_vec);
        } else {
          _mm256_stream_si256(reinterpret_cast<__m256i *>(out), result_vec);
        }
      }
    }

  template<typename T, MEM_TRANSFER_KIND MTK, size_t SimdStepWidth = (64/sizeof(T))>
    void run_conflict_detection_avx512(
      T * __restrict__ out,
      T const * __restrict__ data,
      size_t element_count
    ) {
      static_assert(sizeof(T) >= 4, "Conflict detection with Intel Intrinsics requires at least 4 byte per element.");
      auto const data_end = data + element_count;
      __m512i data_vec;
      __m512i result_vec;
      for (; data < data_end; data += SimdStepWidth, out += SimdStepWidth) {
        if constexpr (MTK == MEM_TRANSFER_KIND::LOAD) {
          data_vec = _mm512_load_si512(reinterpret_cast<void const *>(data));
        } else {
          data_vec = _mm512_stream_load_si512(reinterpret_cast<__m512i *>(const_cast<T*>(data)));
        }
        if constexpr (sizeof(T) == 4) {
          result_vec = _mm512_conflict_epi32(data_vec);
        } else {
          result_vec = _mm512_conflict_epi64(data_vec);
        }
        if constexpr (MTK == MEM_TRANSFER_KIND::LOAD) {
          _mm512_storeu_si512(reinterpret_cast<void *>(out), result_vec);
        } else {
          _mm512_stream_si512(reinterpret_cast<__m512i *>(out), result_vec);
        }
      }
    }
  
  template<typename T>
    std::string my_type_name() {
      if constexpr(sizeof(T)==4) {
        return "uint32_t";
      } else if constexpr(sizeof(T)==8) {
        return "uint64_t";
      } else {
        return "unknown";
      }
    }

  template<typename T>
    void run_benchmark(
      T * __restrict__ out,
      T const * __restrict__ data,
      size_t element_count,
      T * __restrict__ out_reference,
      T const * __restrict__ flush_data,
      T * __restrict__ flush_out 
    ) {
      // validate
      run_conflict_detection_scalar<T, 128>(out_reference, data, element_count);
      run_conflict_detection_sse<T, MEM_TRANSFER_KIND::LOAD>(out, data, element_count);
      for (size_t i = 0; i < element_count; ++i) {
        if (out_reference[i] != out[i]) {
          std::cerr << "Error for SSE (" << my_type_name<T>() << ") at index " << i << ": " << out_reference[i] << " != " << out[i] << std::endl;
          std::cerr << "Respective data: " << std::endl;
          auto const batch_size = 16/sizeof(T);
          auto const start = (i/batch_size)*batch_size;
          std::cerr << "DATA  : ";
          for (size_t j = start; j < start + batch_size; ++j) {
            std::cerr << std::setw(10) << data[j] << " ";
          }
          std::cerr << std::endl;
          std::cerr << "REF   : ";
          for (size_t j = start; j < start + batch_size; ++j) {
            std::cerr << std::setw(10) << out_reference[j] << " ";
          }
          std::cerr << std::endl;
          std::cerr << "RESULT: "; 
          for (size_t j = start; j < start + batch_size; ++j) {
            std::cerr << std::setw(10) << out[j] << " ";
          }
          std::cerr << std::endl;
          throw std::runtime_error("Error in conflict detection.");
        }
      }
      run_conflict_detection_scalar<T, 256>(out_reference, data, element_count);
      run_conflict_detection_avx<T, MEM_TRANSFER_KIND::LOAD>(out, data, element_count);
      for (size_t i = 0; i < element_count; ++i) {
        if (out_reference[i] != out[i]) {
          std::cerr << "Error for AVX (" << my_type_name<T>() << ") at index " << i << ": " << out_reference[i] << " != " << out[i] << std::endl;
          std::cerr << "Respective data: " << std::endl;
          auto const batch_size = 32/sizeof(T);
          auto const start = (i/batch_size)*batch_size;
          for (size_t j = start; j < start + batch_size; ++j) {
            std::cerr << data[j] << " ";
          }
          std::cerr << std::endl;
          throw std::runtime_error("Error in conflict detection.");
        }
      }
      run_conflict_detection_scalar<T, 512>(out_reference, data, element_count);
      run_conflict_detection_avx512<T, MEM_TRANSFER_KIND::LOAD>(out, data, element_count);
      for (size_t i = 0; i < element_count; ++i) {
        if (out_reference[i] != out[i]) {
          std::cerr << "Error for AVX512 (" << my_type_name<T>() << ") at index " << i << ": " << out_reference[i] << " != " << out[i] << std::endl;
          std::cerr << "Respective data: " << std::endl;
          auto const batch_size = 32/sizeof(T);
          auto const start = (i/batch_size)*batch_size;
          for (size_t j = start; j < start + batch_size; ++j) {
            std::cerr << data[j] << " ";
          }
          std::cerr << std::endl;
          throw std::runtime_error("Error in conflict detection.");
        }
      }
      // run measurement
      { // SSE Cached Load
        for (size_t i = 0; i < REPEATS; ++i) {
          run_conflict_detection_sse<T, MEM_TRANSFER_KIND::LOAD>(flush_out, flush_data, element_count);
          auto start = tuddbs::current_time();
          run_conflict_detection_sse<T, MEM_TRANSFER_KIND::LOAD>(out, data, element_count);
          auto end = tuddbs::current_time();
          auto execution_time = tuddbs::time_diff(start, end);
          file_logging::log_to_file<true>(
            cpu_name,
            COMPILER,
            VERSION,
            ARCH,
            i,
            "SSE",
            "conflict_detection",
            "Cache Load",
            my_type_name<T>(), 
            std::to_string(128), 
            std::to_string(element_count*sizeof(T)), 
            std::to_string(0), 
            execution_time,
            tuddbs::throughput(element_count*sizeof(T), execution_time),
            file_logging::concat_pointer_to_string<T>(data, 10),
            file_logging::concat_pointer_to_string<T>(out, 10),
            file_logging::concat_pointer_to_string<T>(flush_data, 10),
            file_logging::concat_pointer_to_string<T>(flush_out, 10)
          );
        }
      }
      { // SSE Cached Load
        for (size_t i = 0; i < REPEATS; ++i) {
          run_conflict_detection_sse<T, MEM_TRANSFER_KIND::STREAM>(flush_out, flush_data, element_count);
          auto start = tuddbs::current_time();
          run_conflict_detection_sse<T, MEM_TRANSFER_KIND::STREAM>(out, data, element_count);
          auto end = tuddbs::current_time();
          auto execution_time = tuddbs::time_diff(start, end);
          file_logging::log_to_file<true>(
            cpu_name,
            COMPILER,
            VERSION,
            ARCH,
            i,
            "SSE",
            "conlict_detection",
            "Stream Load",
            my_type_name<T>(), 
            std::to_string(128), 
            std::to_string(element_count*sizeof(T)), 
            std::to_string(0), 
            execution_time,
            tuddbs::throughput(element_count*sizeof(T), execution_time),
            file_logging::concat_pointer_to_string<T>(data, 10),
            file_logging::concat_pointer_to_string<T>(out, 10),
            file_logging::concat_pointer_to_string<T>(flush_data, 10),
            file_logging::concat_pointer_to_string<T>(flush_out, 10)
          );
        }
      }

      { // AVX Cached Load
        for (size_t i = 0; i < REPEATS; ++i) {
          run_conflict_detection_avx<T, MEM_TRANSFER_KIND::LOAD>(flush_out, flush_data, element_count);
          auto start = tuddbs::current_time();
          run_conflict_detection_avx<T, MEM_TRANSFER_KIND::LOAD>(out, data, element_count);
          auto end = tuddbs::current_time();
          auto execution_time = tuddbs::time_diff(start, end);
          file_logging::log_to_file<true>(
            cpu_name,
            COMPILER,
            VERSION,
            ARCH,
            i,
            "AVX",
            "conflict_detection",
            "Cache Load",
            my_type_name<T>(), 
            std::to_string(256), 
            std::to_string(element_count*sizeof(T)), 
            std::to_string(0), 
            execution_time,
            tuddbs::throughput(element_count*sizeof(T), execution_time),
            file_logging::concat_pointer_to_string<T>(data, 10),
            file_logging::concat_pointer_to_string<T>(out, 10),
            file_logging::concat_pointer_to_string<T>(flush_data, 10),
            file_logging::concat_pointer_to_string<T>(flush_out, 10)
          );
        }
      }
      { // AVX Stream Load
        for (size_t i = 0; i < REPEATS; ++i) {
          run_conflict_detection_avx<T, MEM_TRANSFER_KIND::STREAM>(flush_out, flush_data, element_count);
          auto start = tuddbs::current_time();
          run_conflict_detection_avx<T, MEM_TRANSFER_KIND::STREAM>(out, data, element_count);
          auto end = tuddbs::current_time();
          auto execution_time = tuddbs::time_diff(start, end);
          file_logging::log_to_file<true>(
            cpu_name,
            COMPILER,
            VERSION,
            ARCH,
            i,
            "AVX",
            "conflict_detection",
            "Stream Load",
            my_type_name<T>(), 
            std::to_string(256), 
            std::to_string(element_count*sizeof(T)), 
            std::to_string(0), 
            execution_time,
            tuddbs::throughput(element_count*sizeof(T), execution_time),
            file_logging::concat_pointer_to_string<T>(data, 10),
            file_logging::concat_pointer_to_string<T>(out, 10),
            file_logging::concat_pointer_to_string<T>(flush_data, 10),
            file_logging::concat_pointer_to_string<T>(flush_out, 10)
          );
        }
      }

      { // AVX512 Cached Load
        for (size_t i = 0; i < REPEATS; ++i) {
          run_conflict_detection_avx512<T, MEM_TRANSFER_KIND::LOAD>(flush_out, flush_data, element_count);
          auto start = tuddbs::current_time();
          run_conflict_detection_avx512<T, MEM_TRANSFER_KIND::LOAD>(out, data, element_count);
          auto end = tuddbs::current_time();
          auto execution_time = tuddbs::time_diff(start, end);
          file_logging::log_to_file<true>(
            cpu_name,
            COMPILER,
            VERSION,
            ARCH,
            i,
            "AVX512",
            "conflict_detection",
            "Cache Load",
            my_type_name<T>(), 
            std::to_string(512), 
            std::to_string(element_count*sizeof(T)), 
            std::to_string(0), 
            execution_time,
            tuddbs::throughput(element_count*sizeof(T), execution_time),
            file_logging::concat_pointer_to_string<T>(data, 10),
            file_logging::concat_pointer_to_string<T>(out, 10),
            file_logging::concat_pointer_to_string<T>(flush_data, 10),
            file_logging::concat_pointer_to_string<T>(flush_out, 10)
          );
        }
      }
      { // AVX Cached Load      
        for (size_t i = 0; i < REPEATS; ++i) {
          run_conflict_detection_avx512<T, MEM_TRANSFER_KIND::STREAM>(flush_out, flush_data, element_count);
          auto start = tuddbs::current_time();
          run_conflict_detection_avx512<T, MEM_TRANSFER_KIND::STREAM>(out, data, element_count);
          auto end = tuddbs::current_time();
          auto execution_time = tuddbs::time_diff(start, end);
          file_logging::log_to_file<true>(
            cpu_name,
            COMPILER,
            VERSION,
            ARCH,
            i,
            "AVX512",
            "conflict_detection",
            "Stream Load",
            my_type_name<T>(), 
            std::to_string(512), 
            std::to_string(element_count*sizeof(T)), 
            std::to_string(0), 
            execution_time,
            tuddbs::throughput(element_count*sizeof(T), execution_time),
            file_logging::concat_pointer_to_string<T>(data, 10),
            file_logging::concat_pointer_to_string<T>(out, 10),
            file_logging::concat_pointer_to_string<T>(flush_data, 10),
            file_logging::concat_pointer_to_string<T>(flush_out, 10)
          );
        }
        
      }
    }

  template <typename T>
    void bench_intel_intrin(
      size_t data_size
    ) {
      auto const buffer_count = data_size / sizeof(T);
      auto out_reference = reinterpret_cast<T*>(_mm_malloc(data_size, 64));
      auto data = reinterpret_cast<T*>(_mm_malloc(data_size, 64));
      auto flush_data = reinterpret_cast<T*>(_mm_malloc(data_size, 64));
      auto out = reinterpret_cast<T*>(_mm_malloc(data_size, 64));
      auto flush_out = reinterpret_cast<T*>(_mm_malloc(data_size, 64));
      std::uniform_int_distribution<T> dist_data(1, 30);
      std::uniform_int_distribution<T> dist_flush(1, 2048);

      for (size_t i = 0; i < buffer_count; ++i) {
          data[i] = dist_data(tuddbs::generator);
          flush_data[i] = dist_flush(tuddbs::generator);
          out[i] = 0;
          flush_out[i] = 0;
          out_reference[i] = 0;
      }
      run_benchmark<T>(out, data, buffer_count, out_reference, flush_data, flush_out);
      _mm_free(flush_out);
      _mm_free(out);
      _mm_free(flush_data);
      _mm_free(data);
      _mm_free(out_reference);
    }
}
int main(int argc, char** argv) {
  size_t data_size;
  char size_param[] = "--size";
  char repeat_param[] = "--repeats";
  bool found_size = false;
  bool found_repeat = false;
  for (int i = 0; i < argc; ++i) {
    if (memcmp(argv[i], size_param, 6) == 0) {
      data_size = tuddbs::strToByte(argv[i + 1]);
      found_size = true;
      break;
    }
  }
  for (int i = 0; i < argc; ++i) {
    if (memcmp(argv[i], repeat_param, 6) == 0) {
      REPEATS = std::atoll(argv[i + 1]);
      found_repeat = true;
      break;
    }
  }
  if (!found_size) {
    std::cerr << "[WARNING] No --size given. Defaulting to 1 MiB." << std::endl;
    data_size = 1_MiB;
  } else {
    std::cerr << "[INFO] Using data size in Bytes: " << data_size << std::endl;
  }
  if (!found_repeat) {
    std::cerr << "[WARNING] No --repeat given. Defaulting to 10." << std::endl;
    REPEATS = 10;
  } else {
    std::cerr << "[INFO] Executing experiments " << REPEATS << " times." << std::endl;
  }

  std::string log_file_name = "./benchmark_conflict_simd_" + file_logging::get_current_time_as_string() + ".log";
  file_logging::open_log_file(log_file_name);

  std::stringstream header;
  file_logging::log_to_file<true>(
    "device",
    "compiler",
    "version",
    "arch-flags",
    "rep",
    "target", 
    "operation",
    "variant",
    "type", 
    "vectorsize", 
    "datasize", 
    "offloading_and_execution_time", 
    "execution_time [ns]", 
    "throughput [MiB/s]", 
    "data@10", 
    "results@10", 
    "flush_data@10", 
    "flush_results@10"
  );

  tuddbs::bench_intel_intrin<uint32_t>(data_size);
  tuddbs::bench_intel_intrin<uint64_t>(data_size);

  file_logging::close_log_file();

  return 0;
}