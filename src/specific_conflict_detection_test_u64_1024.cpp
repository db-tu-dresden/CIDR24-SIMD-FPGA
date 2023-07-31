/*
Copyright 2023 Database Research Group, TU Dresden

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <data.h>
#include <exec.h>
#include <kernels.h>
#include <sycl.h>
#include <utils.h>
#include <tslintrin.hpp>

#include <algorithm>
#include <bitset>
#include <climits>
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>
#include <random>
#include <stdexcept>
#include <array>

#include <immintrin.h>

#define ALIGNMENT 0

namespace tuddbs{

  template<typename T, size_t VectorSizeInBit>
  constexpr bool is_conflict_detection_possible() {
    return (VectorSizeInBit / (CHAR_BIT * sizeof(T)) <= (CHAR_BIT * sizeof(T)));
  }

  template<typename T, size_t VectorSizeInBit>
    void conflict_detection_scalar(
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

    double conflict_detection_fpga_wrapper(
      sycl::queue* q,
      uint64_t * __restrict__ out_ptr,
      uint64_t const * __restrict__ data_ptr,
      size_t element_count
    ) {
      using namespace sycl;

      auto start = high_resolution_clock::now();
      q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
              host_ptr<const uint64_t> in(data_ptr);
#ifdef FPGA_WRITE_TO_DEV
              device_ptr<uint64_t> out(out_ptr);
#else
              host_ptr<uint64_t> out(out_ptr);
#endif
              [[intel::fpga_register]] std::array<uint64_t, 16> data_vec{};
              [[intel::fpga_register]] std::array<uint64_t, 16> result_vec{};
              auto const data_end = in + element_count;
              for (; in != data_end; in+=16, out+=16) {
                for (size_t i = 0; i < 16; ++i) {
                  data_vec[i] = in[i];
                }
                result_vec[15] = 
                  ((data_vec[15] == data_vec[14]) ? 0b100000000000000 : 0) | 
                  ((data_vec[15] == data_vec[13]) ? 0b10000000000000  : 0) | 
                  ((data_vec[15] == data_vec[12]) ? 0b1000000000000   : 0) | 
                  ((data_vec[15] == data_vec[11]) ? 0b100000000000    : 0) | 
                  ((data_vec[15] == data_vec[10]) ? 0b10000000000     : 0) | 
                  ((data_vec[15] == data_vec[ 9]) ? 0b1000000000      : 0) | 
                  ((data_vec[15] == data_vec[ 8]) ? 0b100000000       : 0) | 
                  ((data_vec[15] == data_vec[ 7]) ? 0b10000000        : 0) | 
                  ((data_vec[15] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[15] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[15] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[15] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[15] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[15] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[15] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[14] = 
                  ((data_vec[14] == data_vec[13]) ? 0b10000000000000  : 0) | 
                  ((data_vec[14] == data_vec[12]) ? 0b1000000000000   : 0) | 
                  ((data_vec[14] == data_vec[11]) ? 0b100000000000    : 0) | 
                  ((data_vec[14] == data_vec[10]) ? 0b10000000000     : 0) | 
                  ((data_vec[14] == data_vec[ 9]) ? 0b1000000000      : 0) | 
                  ((data_vec[14] == data_vec[ 8]) ? 0b100000000       : 0) | 
                  ((data_vec[14] == data_vec[ 7]) ? 0b10000000        : 0) | 
                  ((data_vec[14] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[14] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[14] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[14] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[14] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[14] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[14] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[13] = 
                  ((data_vec[13] == data_vec[12]) ? 0b1000000000000   : 0) | 
                  ((data_vec[13] == data_vec[11]) ? 0b100000000000    : 0) | 
                  ((data_vec[13] == data_vec[10]) ? 0b10000000000     : 0) | 
                  ((data_vec[13] == data_vec[ 9]) ? 0b1000000000      : 0) | 
                  ((data_vec[13] == data_vec[ 8]) ? 0b100000000       : 0) | 
                  ((data_vec[13] == data_vec[ 7]) ? 0b10000000        : 0) | 
                  ((data_vec[13] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[13] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[13] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[13] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[13] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[13] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[13] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[12] = 
                  ((data_vec[12] == data_vec[11]) ? 0b100000000000    : 0) | 
                  ((data_vec[12] == data_vec[10]) ? 0b10000000000     : 0) | 
                  ((data_vec[12] == data_vec[ 9]) ? 0b1000000000      : 0) | 
                  ((data_vec[12] == data_vec[ 8]) ? 0b100000000       : 0) | 
                  ((data_vec[12] == data_vec[ 7]) ? 0b10000000        : 0) | 
                  ((data_vec[12] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[12] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[12] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[12] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[12] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[12] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[12] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[11] = 
                  ((data_vec[11] == data_vec[10]) ? 0b10000000000     : 0) | 
                  ((data_vec[11] == data_vec[ 9]) ? 0b1000000000      : 0) | 
                  ((data_vec[11] == data_vec[ 8]) ? 0b100000000       : 0) | 
                  ((data_vec[11] == data_vec[ 7]) ? 0b10000000        : 0) | 
                  ((data_vec[11] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[11] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[11] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[11] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[11] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[11] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[11] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[10] = 
                  ((data_vec[10] == data_vec[ 9]) ? 0b1000000000      : 0) | 
                  ((data_vec[10] == data_vec[ 8]) ? 0b100000000       : 0) | 
                  ((data_vec[10] == data_vec[ 7]) ? 0b10000000        : 0) | 
                  ((data_vec[10] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[10] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[10] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[10] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[10] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[10] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[10] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[9] =
                  ((data_vec[ 9] == data_vec[ 8]) ? 0b100000000       : 0) | 
                  ((data_vec[ 9] == data_vec[ 7]) ? 0b10000000        : 0) | 
                  ((data_vec[ 9] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[ 9] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[ 9] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[ 9] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 9] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 9] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 9] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[8] =
                  ((data_vec[ 8] == data_vec[ 7]) ? 0b10000000        : 0) | 
                  ((data_vec[ 8] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[ 8] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[ 8] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[ 8] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 8] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 8] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 8] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[7] =
                  ((data_vec[ 7] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[ 7] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[ 7] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[ 7] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 7] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 7] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 7] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[6] =
                  ((data_vec[ 6] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[ 6] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[ 6] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 6] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 6] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 6] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[5] =
                  ((data_vec[ 5] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[ 5] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 5] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 5] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 5] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[4] =
                  ((data_vec[ 4] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 4] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 4] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 4] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[3] =
                  ((data_vec[ 3] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 3] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 3] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[2] =
                  ((data_vec[ 2] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 2] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[1] =
                  ((data_vec[ 1] == data_vec[ 0]) ? 0b1               : 0);
                result_vec[0] = 0;
                for (size_t i = 0; i < 16; ++i) {
                  out[i] = result_vec[i];
                }
              }
          });
      }).wait();
      auto end = high_resolution_clock::now();
      return static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }

    void bench_and_test_vector_size(
      sycl::queue* q,
      uint64_t * __restrict__ out_fpga,
      uint64_t const * __restrict__ data,
      uint64_t * __restrict__ out_host,
      size_t element_count
    ) {
      auto result_buffer_fpga_on_host = create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, element_count * sizeof(uint64_t), ALIGNMENT);
      conflict_detection_scalar<uint64_t, 1024>(out_host, data, element_count);
      auto offloading_and_execution_time = conflict_detection_fpga_wrapper(q, out_fpga, data, element_count);
#ifdef FPGA_WRITE_TO_DEV
      q->memcpy(result_buffer_fpga_on_host, out_fpga, element_count * sizeof(uint64_t));
      q->wait();
#else
      std::memcpy(result_buffer_fpga_on_host, out_fpga, element_count * sizeof(uint64_t));
#endif
      for (size_t i = 0; i < element_count; ++i) {
        if (out_host[i] != result_buffer_fpga_on_host[i]) {
          std::cerr << "ERROR: Result mismatch at position" << i << std::endl;
          std::cerr << "Data[" << i << "] = " << data[i] << std::endl;
          std::cerr << "Ref [" << i << "] = " << out_host[i] << std::endl;
          std::cerr << "Dev [" << i << "] = " << result_buffer_fpga_on_host[i] << std::endl;
          std::terminate();
        }
      }
      
      auto execution_time = conflict_detection_fpga_wrapper(q, out_fpga, data, element_count);
 #ifdef FPGA_WRITE_TO_DEV
      q->memcpy(result_buffer_fpga_on_host, out_fpga, 10 * sizeof(uint64_t));
      q->wait();
#else
      std::memcpy(result_buffer_fpga_on_host, out_fpga, 10 * sizeof(uint64_t));
#endif

      file_logging::log_to_file<true>(
        "FPGA",
        "uint64_t", 
        std::to_string(1024), 
        std::to_string(element_count*sizeof(uint64_t)), 
        std::to_string(offloading_and_execution_time), 
        std::to_string(execution_time), 
        std::to_string((((element_count * sizeof(uint64_t)) / (1024.0 * 1024.0)) / (execution_time / 1000000.0))),
        file_logging::concat_pointer_to_string<uint64_t>(data, 10),
        file_logging::concat_pointer_to_string<uint64_t>(result_buffer_fpga_on_host, 10),
        "-", "-"
      );
      remove_buffer(q, result_buffer_fpga_on_host);
    }

    void bench_and_test_data_type(
      sycl::queue* q,
      size_t data_size
    ) {
      auto const buffer_count = data_size / sizeof(uint64_t);
      auto in = create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, data_size, ALIGNMENT);
#ifdef FPGA_WRITE_TO_DEV
      auto out_fpga = create_buffer<uint64_t>(q, MALLOC_TARGET::DEVICE, data_size, ALIGNMENT);
#else
      auto out_fpga = create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, data_size, ALIGNMENT);
#endif
      auto out_host = create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, data_size, ALIGNMENT);
      fill_buffer_random_in_range<uint64_t>(in, buffer_count, (uint64_t)0, (uint64_t)30);
      bench_and_test_vector_size(q, out_fpga, in, out_host, buffer_count);
      
      remove_buffer(q, out_host);
      remove_buffer(q, out_fpga);
      remove_buffer(q, in);
    }

} // namespace tuddbs

int main(int argc, char** argv) {
    // the device selector
#ifdef LATEST
#if FPGA_SIMULATOR
    auto selector = sycl::ext::intel::fpga_simulator_selector_v;
    std::cout << "Using FPGA Simulator" << std::endl;
#elif FPGA_HARDWARE
    auto selector = sycl::ext::intel::fpga_selector_v;
    std::cout << "Using FPGA Hardware" << std::endl;
#else  // #if FPGA_EMULATOR
    auto selector = sycl::ext::intel::fpga_emulator_selector_v;
    std::cout << "Using FPGA Emulator" << std::endl;
#endif
#else
#ifdef FPGA_EMULATOR
    ext::intel::fpga_emulator_selector selector;
    std::cout << "Using FPGA Emulator" << std::endl;
#else
    ext::intel::fpga_selector selector;
    std::cout << "Using FPGA Hardware" << std::endl;
#endif
#endif
    // create the device queue
    auto props = property_list{property::queue::enable_profiling()};
    queue q(selector, exception_handler, props);

    // make sure the device supports USM device allocations
    device d = q.get_device();
    if (!d.get_info<info::device::usm_device_allocations>()) {
        std::cerr << "ERROR: The selected device does not support USM device"
                  << " allocations" << std::endl;
        std::terminate();
    }
    if (!d.get_info<info::device::usm_host_allocations>()) {
        std::cerr << "ERROR: The selected device does not support USM host"
                  << " allocations" << std::endl;
        std::terminate();
    }

    size_t data_size;
    char size_param[] = "--size";
    bool found_size = false;
    for (int i = 0; i < argc; ++i) {
        if (memcmp(argv[i], size_param, 6) == 0) {
            data_size = tuddbs::strToByte(argv[i + 1]);
            found_size = true;
            break;
        }
    }

    if (!found_size) {
        std::cerr << "[WARNING] No --size given. Defaulting to 1 MiB." << std::endl;
        data_size = 1_MiB;
    } else {
        std::cerr << "[INFO] Using data size in Bytes: " << data_size << std::endl;
    }

    std::string log_file_name = "./benchmark_conflict_detection_" + file_logging::get_current_time_as_string() + ".log";
    file_logging::open_log_file(log_file_name);

    std::stringstream header;
    file_logging::log_to_file<true>("target", "type", "vectorsize", "datasize", "offloading_and_execution_time", "execution_times", "(avg) throughput [MiB/s]", "data@10", "results@10", "flush_data@10", "flush_results@10");

    tuddbs::bench_and_test_data_type(&q, data_size);


    file_logging::close_log_file();

    return 0;
}
