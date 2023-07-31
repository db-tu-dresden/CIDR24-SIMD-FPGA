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
#include <string>
#include <sycl.h>
#include <utils.h>

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
#include "dbsbenchmark.hpp"

#define ALIGNMENT 0

namespace tuddbs{

  template<typename T>
    void modulo_by_value_scalar(
      T * __restrict__ out,
      T const * __restrict__ data,
      T const modulos,
      size_t element_count
    ) {
      auto const data_end = data + element_count;
      for (; data != data_end; ++data, ++out) {
        *out = *data % modulos;
      }
    }

  template <typename SimdT, typename InPtrT, typename OutPtrT>
    void modulo_by_value_kernel(
      OutPtrT out,
      InPtrT data,
      typename SimdT::base_type const modulos,
      size_t element_count
    ) {
      auto const data_end = data + element_count;
      [[intel::fpga_register]] std::array<typename SimdT::base_type, SimdT::vector_element_count()> data_vec{};
      [[intel::fpga_register]] typename SimdT::base_type modulos_val = modulos;
      [[intel::fpga_register]] std::array<typename SimdT::base_type, SimdT::vector_element_count()> result_vec{};
      for (; data != data_end; data += SimdT::vector_element_count()) {
        #pragma unroll
        for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
          data_vec[i] = data[i];
        }
        #pragma unroll
        for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
          result_vec[i] |= data_vec[i] % modulos_val;
          // result_vec[i] = data_vec[i] - ((data_vec[i] / modulos_val) * modulos_val);
        }
      }
      #pragma unroll
      for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
        out[i] = result_vec[i];
      }
    }
  template <typename SimdT, typename InPtrT, typename OutPtrT>
    void modulo_by_value_divsub_kernel(
      OutPtrT out,
      InPtrT data,
      typename SimdT::base_type const modulos,
      size_t element_count
    ) {
      auto const data_end = data + element_count;
      [[intel::fpga_register]] std::array<typename SimdT::base_type, SimdT::vector_element_count()> data_vec{};
      [[intel::fpga_register]] typename SimdT::base_type modulos_val = modulos;
      [[intel::fpga_register]] std::array<typename SimdT::base_type, SimdT::vector_element_count()> result_vec{};
      for (; data != data_end; data += SimdT::vector_element_count()) {
        #pragma unroll
        for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
          data_vec[i] = data[i];
        }
        #pragma unroll
        for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
          result_vec[i] |= data_vec[i] - ((data_vec[i] / modulos_val) * modulos_val);
        }
      }
      #pragma unroll
      for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
        out[i] = result_vec[i];
      }
    }

    template <typename SimdT>
    auto modulo_by_value_fpga_wrapper(
      sycl::queue* q,
      typename SimdT::base_type * __restrict__ out_ptr,
      typename SimdT::base_type const * __restrict__ data_ptr,
      typename SimdT::base_type const modulo,
      size_t element_count
    ) {
      using namespace sycl;
      using base_t = typename SimdT::base_type;

      auto start = default_clock_t::now();
      q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
              host_ptr<const base_t> in(data_ptr);
#ifdef FPGA_WRITE_TO_DEV
              device_ptr<base_t> out(out_ptr);
#else
              host_ptr<base_t> out(out_ptr);
#endif
              modulo_by_value_kernel<SimdT>(out, in, modulo, element_count);
          });
      }).wait();
      auto end = default_clock_t::now();
      return std::make_pair(start, end);
    }
    template <typename SimdT>
    auto modulo_by_value_divsub_fpga_wrapper(
      sycl::queue* q,
      typename SimdT::base_type * __restrict__ out_ptr,
      typename SimdT::base_type const * __restrict__ data_ptr,
      typename SimdT::base_type const modulo,
      size_t element_count
    ) {
      using namespace sycl;
      using base_t = typename SimdT::base_type;

      auto start = default_clock_t::now();
      q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
              host_ptr<const base_t> in(data_ptr);
#ifdef FPGA_WRITE_TO_DEV
              device_ptr<base_t> out(out_ptr);
#else
              host_ptr<base_t> out(out_ptr);
#endif
              modulo_by_value_divsub_kernel<SimdT>(out, in, modulo, element_count);
          });
      }).wait();
      auto end = default_clock_t::now();
      return std::make_pair(start, end);
    }

  template <typename T, size_t VectorSize>
    void bench_and_test_vector_size(
      sycl::queue* q,
      T const * __restrict__ data,
      T const modulos,
      size_t element_count,
      tuddbs::csv_filewriter_t & writer
    ) {
#ifdef FPGA_WRITE_TO_DEV
      auto out_fpga = create_buffer<T>(q, MALLOC_TARGET::DEVICE, VectorSize/(sizeof(T)*CHAR_BIT) * sizeof(T), ALIGNMENT);
#else
      auto out_fpga = create_buffer<T>(q, MALLOC_TARGET::HOST, VectorSize/(sizeof(T)*CHAR_BIT) * sizeof(T), ALIGNMENT);
#endif
      auto result_buffer_fpga_on_host = create_buffer<T>(q, MALLOC_TARGET::HOST, VectorSize/(sizeof(T)*CHAR_BIT) * sizeof(T), ALIGNMENT);

      {
        auto [start_offload_exec, end_offload_exec] = modulo_by_value_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, modulos, element_count);
  #ifdef FPGA_WRITE_TO_DEV
        q->memcpy(result_buffer_fpga_on_host, out_fpga, VectorSize/(sizeof(T)*CHAR_BIT) * sizeof(T));
        q->wait();
  #else
        std::memcpy(result_buffer_fpga_on_host, out_fpga, VectorSize/(sizeof(T)*CHAR_BIT) * sizeof(T));
  #endif
        auto offload_result_str = file_logging::concat_pointer_to_string<T>(result_buffer_fpga_on_host, VectorSize/(sizeof(T)*CHAR_BIT));

        auto [start_exec, end_exec] = modulo_by_value_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, modulos, element_count);
#ifdef FPGA_WRITE_TO_DEV
        q->memcpy(result_buffer_fpga_on_host, out_fpga, VectorSize/(sizeof(T)*CHAR_BIT) * sizeof(T));
        q->wait();
  #else
        std::memcpy(result_buffer_fpga_on_host, out_fpga, VectorSize/(sizeof(T)*CHAR_BIT) * sizeof(T));
  #endif
      auto execute_result_str = file_logging::concat_pointer_to_string<T>(result_buffer_fpga_on_host, VectorSize/(sizeof(T)*CHAR_BIT));
        writer.write_line(
          PLATFORM, COMPILER, VERSION,
          "fpga",
          "modulo by value",
          "percent operator",
          tsl::type_name<T>(), std::to_string(VectorSize), 
          element_count,
          element_count * sizeof(T),
          default_clock_t::duration(start_offload_exec, end_offload_exec), default_clock_t::duration(start_exec, end_exec),
          default_tput_t::throughput(start_exec, end_exec, element_count * sizeof(T)),
          offload_result_str, execute_result_str
        );
      }
      {
        auto [start_offload_exec, end_offload_exec] = modulo_by_value_divsub_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, modulos, element_count);
  #ifdef FPGA_WRITE_TO_DEV
        q->memcpy(result_buffer_fpga_on_host, out_fpga, VectorSize/(sizeof(T)*CHAR_BIT) * sizeof(T));
        q->wait();
  #else
        std::memcpy(result_buffer_fpga_on_host, out_fpga, VectorSize/(sizeof(T)*CHAR_BIT) * sizeof(T));
  #endif
        auto offload_result_str = file_logging::concat_pointer_to_string<T>(result_buffer_fpga_on_host, VectorSize/(sizeof(T)*CHAR_BIT));

        auto [start_exec, end_exec] = modulo_by_value_divsub_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, modulos, element_count);
#ifdef FPGA_WRITE_TO_DEV
        q->memcpy(result_buffer_fpga_on_host, out_fpga, VectorSize/(sizeof(T)*CHAR_BIT) * sizeof(T));
        q->wait();
  #else
        std::memcpy(result_buffer_fpga_on_host, out_fpga, VectorSize/(sizeof(T)*CHAR_BIT) * sizeof(T));
  #endif
        auto execute_result_str = file_logging::concat_pointer_to_string<T>(result_buffer_fpga_on_host, VectorSize/(sizeof(T)*CHAR_BIT));
        writer.write_line(
          PLATFORM, COMPILER, VERSION,
          "fpga",
          "modulo by value",
          "a-(a/m)*m",
          tsl::type_name<T>(), std::to_string(VectorSize), 
          element_count,
          element_count * sizeof(T),
          default_clock_t::duration(start_offload_exec, end_offload_exec), default_clock_t::duration(start_exec, end_exec),
          default_tput_t::throughput(start_exec, end_exec, element_count * sizeof(T)),
          offload_result_str, execute_result_str
        );
      }
      remove_buffer(q, out_fpga);
      remove_buffer(q, result_buffer_fpga_on_host);
    }

  template <typename T>
    void bench_and_test_data_type(
      sycl::queue* q,
      tuddbs::csv_filewriter_t & writer,
      size_t data_size
    ) {
      using namespace tsl;
      auto const buffer_count = data_size / sizeof(T);
      auto in = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size, ALIGNMENT);
      fill_buffer_random_in_range<T>(in, buffer_count, (T)10000, (T)1000000);
      std::mt19937 engine(0xc01dbadc00ffee);
      std::uniform_int_distribution<T> dist((T)1, (T)8000);
      T modulo = dist(engine);

#ifdef VL128
      bench_and_test_vector_size<T,  12>(q, in, modulo, buffer_count, writer);
#endif
#ifdef VL256
      bench_and_test_vector_size<T,  256>(q, in, modulo, buffer_count, writer);
#endif
#ifdef VL512
      bench_and_test_vector_size<T,  512>(q, in, modulo, buffer_count, writer);
#endif
#ifdef VL1024
      bench_and_test_vector_size<T,  1024>(q, in, modulo, buffer_count, writer);
#endif
#ifdef VL2048
      bench_and_test_vector_size<T,  2048>(q, in, modulo, buffer_count, writer);
#endif
#ifdef VL4096
      bench_and_test_vector_size<T,  4096>(q, in, modulo, buffer_count, writer);
#endif
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

tuddbs::csv_filewriter_t writer("benchmark_results_modulo_aggregate", "\t");
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

#ifdef UI8
    tuddbs::bench_and_test_data_type< uint8_t>(&q, writer, data_size);
#endif
#ifdef UI16    
    tuddbs::bench_and_test_data_type<uint16_t>(&q, writer, data_size);
#endif
#ifdef UI32    
    tuddbs::bench_and_test_data_type<uint32_t>(&q, writer, data_size);
#endif
#ifdef UI64
    tuddbs::bench_and_test_data_type<uint64_t>(&q, writer, data_size);
#endif    

    return 0;
}
