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
#include "dbsbenchmark.hpp"


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
      std::array<uint32_t, VectorSizeInBit/(CHAR_BIT*sizeof(T))> results{};
      for (; data != data_end; data += batch_size) {
        *out = 0;
        for (size_t i = 1; i < batch_size; ++i) {
          T val = 0;
          for (size_t j = 0; j < i; ++j) {
            val |= (data[i] == data[j]) ? ((T)1<<(T)j) : (T)0;
          }
          results[i] |= val;
        }
      }
      for (size_t i = 0; i < batch_size; ++i) {
        out[i] = results[i];
      }
    }

    auto conflict_detection_fpga_wrapper(
      sycl::queue* q,
      uint32_t * __restrict__ out_ptr,
      uint32_t const * __restrict__ data_ptr,
      size_t element_count
    ) {
      using namespace sycl;

      auto start = default_clock_t::now();
      q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
              host_ptr<const uint32_t> in(data_ptr);
              host_ptr<uint32_t> out(out_ptr);
              [[intel::fpga_register]] std::array<uint32_t, 16> data_vec{};
              [[intel::fpga_register]] std::array<uint32_t, 16> result_vec{};
              [[intel::fpga_register]] std::array<uint32_t, 16> conflict_vec{};
              auto const data_end = in + element_count;
              for (; in != data_end; in+=16) {
                #pragma unroll
                for (size_t i = 0; i < 16; ++i) {
                  data_vec[i] = in[i];
                }
                conflict_vec[15] = 
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
                conflict_vec[14] = 
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
                conflict_vec[13] = 
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
                conflict_vec[12] = 
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
                conflict_vec[11] = 
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
                conflict_vec[10] = 
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
                conflict_vec[9] =
                  ((data_vec[ 9] == data_vec[ 8]) ? 0b100000000       : 0) | 
                  ((data_vec[ 9] == data_vec[ 7]) ? 0b10000000        : 0) | 
                  ((data_vec[ 9] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[ 9] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[ 9] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[ 9] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 9] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 9] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 9] == data_vec[ 0]) ? 0b1               : 0);
                conflict_vec[8] =
                  ((data_vec[ 8] == data_vec[ 7]) ? 0b10000000        : 0) | 
                  ((data_vec[ 8] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[ 8] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[ 8] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[ 8] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 8] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 8] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 8] == data_vec[ 0]) ? 0b1               : 0);
                conflict_vec[7] =
                  ((data_vec[ 7] == data_vec[ 6]) ? 0b1000000         : 0) | 
                  ((data_vec[ 7] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[ 7] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[ 7] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 7] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 7] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 7] == data_vec[ 0]) ? 0b1               : 0);
                conflict_vec[6] =
                  ((data_vec[ 6] == data_vec[ 5]) ? 0b100000          : 0) | 
                  ((data_vec[ 6] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[ 6] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 6] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 6] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 6] == data_vec[ 0]) ? 0b1               : 0);
                conflict_vec[5] =
                  ((data_vec[ 5] == data_vec[ 4]) ? 0b10000           : 0) | 
                  ((data_vec[ 5] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 5] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 5] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 5] == data_vec[ 0]) ? 0b1               : 0);
                conflict_vec[4] =
                  ((data_vec[ 4] == data_vec[ 3]) ? 0b1000            : 0) | 
                  ((data_vec[ 4] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 4] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 4] == data_vec[ 0]) ? 0b1               : 0);
                conflict_vec[3] =
                  ((data_vec[ 3] == data_vec[ 2]) ? 0b100             : 0) | 
                  ((data_vec[ 3] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 3] == data_vec[ 0]) ? 0b1               : 0);
                conflict_vec[2] =
                  ((data_vec[ 2] == data_vec[ 1]) ? 0b10              : 0) | 
                  ((data_vec[ 2] == data_vec[ 0]) ? 0b1               : 0);
                conflict_vec[1] =
                  ((data_vec[ 1] == data_vec[ 0]) ? 0b1               : 0);
                conflict_vec[0] = 0;
                #pragma unroll
                for (size_t i = 0; i < 16; ++i) {
                  result_vec[i] |= conflict_vec[i];
                }
              }
              #pragma unroll
              for (size_t i = 0; i < 16; ++i) {
                out[i] = result_vec[i];
              }
          });
      }).wait();
      auto end = default_clock_t::now();
      return std::make_pair(start, end);
    }

    void bench_and_test_vector_size(
      sycl::queue* q,
      uint32_t * __restrict__ out_fpga,
      uint32_t const * __restrict__ data,
      uint32_t * __restrict__ out_host,
      size_t element_count,
      tuddbs::csv_filewriter_t & writer
    ) {
      conflict_detection_scalar<uint32_t, 512>(out_host, data, element_count);
      auto [start_offload_exec, end_offload_exec] = conflict_detection_fpga_wrapper(q, out_fpga, data, element_count);
      for (size_t i = 0; i < element_count; ++i) {
        if (out_host[i] != out_fpga[i]) {
          std::cerr << "Error at index " << i << ": " << out_host[i] << " != " << out_fpga[i] << std::endl;
          std::cerr << "Respective data: " << std::endl;
          auto const batch_size = 512/(CHAR_BIT*sizeof(uint32_t));
          auto const start = (i/batch_size)*batch_size;
          for (size_t j = start; j < start + batch_size; ++j) {
            std::cerr << data[j] << " ";
          }
          std::cerr << std::endl;
          throw std::runtime_error("Error in conflict detection.");
        }
      }
      auto [start_exec, end_exec] = conflict_detection_fpga_wrapper(q, out_fpga, data, element_count);
      writer.write_line(
        PLATFORM, COMPILER, VERSION,
        "fpga",
        "conflict_detection",
        "unrolled",
        tsl::type_name<uint32_t>(), 512,
        element_count,
        element_count * sizeof(uint32_t),
        default_clock_t::duration(start_offload_exec, end_offload_exec), default_clock_t::duration(start_exec, end_exec),
        default_tput_t::throughput(start_exec, end_exec, element_count * sizeof(uint32_t)),
        file_logging::concat_pointer_to_string<uint32_t>(out_host, 10), file_logging::concat_pointer_to_string<uint32_t>(out_fpga, 10)
      );
    }

    void bench_and_test_data_type(
      sycl::queue* q,
      tuddbs::csv_filewriter_t & writer,
      size_t data_size
    ) {
      auto const buffer_count = data_size / sizeof(uint32_t);
      auto in = create_buffer<uint32_t>(q, MALLOC_TARGET::HOST, data_size, 64);
      auto out_fpga = create_buffer<uint32_t>(q, MALLOC_TARGET::HOST, data_size, 64);
      auto out_host = create_buffer<uint32_t>(q, MALLOC_TARGET::HOST, data_size, 64);
      fill_buffer_random_in_range<uint32_t>(in, buffer_count, (uint32_t)0, (uint32_t)30);
      bench_and_test_vector_size(q, out_fpga, in, out_host, buffer_count, writer);
      
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

  tuddbs::csv_filewriter_t writer("benchmark_results_conflict_detection_and_aggregate", "\t");
    auto fields = writer.create_field_names_description();
    fields.append_bulk(
      "platform",
      "compiler",
      "version",
      "target", 
      "operation", 
      "flavor", 
      "type", "vectorsize", 
      "element_count",
      "datasize", 
      "offloading_and_execution_time [" + tuddbs::default_clock_t::unit_str() + "]",
      "execution_time [" + tuddbs::default_clock_t::unit_str() + "]",
      "throughput [" + tuddbs::default_tput_t::unit_str() + "]", 
      "1st result@10", "2nd result@10");
    writer.set_field_names(fields);

    tuddbs::bench_and_test_data_type(&q, writer, data_size);

    return 0;
}
