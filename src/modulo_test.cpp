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

#define ALIGNMENT 0

namespace tuddbs{

  template<typename T>
    void modulo_by_column_scalar(
      T * __restrict__ out,
      T const * __restrict__ data,
      T const * __restrict__ modulos,
      size_t element_count
    ) {
      auto const data_end = data + element_count;
      for (; data != data_end; ++data, ++modulos, ++out) {
        *out = *data % *modulos;
      }
    }
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
    void modulo_by_column_kernel(
      OutPtrT out,
      InPtrT data,
      InPtrT modulos,
      size_t element_count
    ) {
      auto const data_end = data + element_count;
      [[intel::fpga_register]] std::array<typename SimdT::base_type, SimdT::vector_element_count()> data_vec{};
      [[intel::fpga_register]] std::array<typename SimdT::base_type, SimdT::vector_element_count()> modulos_vec{};
      [[intel::fpga_register]] std::array<typename SimdT::base_type, SimdT::vector_element_count()> result_vec{};
      for (; data != data_end; data += SimdT::vector_element_count(), modulos += SimdT::vector_element_count(), out += SimdT::vector_element_count()) {
        #pragma unroll
        for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
          data_vec[i] = data[i];
        }
        #pragma unroll
        for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
          modulos_vec[i] = modulos[i];
        }
        #pragma unroll
        for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
          result_vec[i] = data_vec[i] % modulos_vec[i];
          // result_vec[i] = data_vec[i] - ((data_vec[i] / modulos_vec[i]) * modulos_vec[i]);
        }
        #pragma unroll
        for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
          out[i] = result_vec[i];
        }
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
      for (; data != data_end; data += SimdT::vector_element_count(), out += SimdT::vector_element_count()) {
        #pragma unroll
        for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
          data_vec[i] = data[i];
        }
        #pragma unroll
        for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
          result_vec[i] = data_vec[i] % modulos_val;
          // result_vec[i] = data_vec[i] - ((data_vec[i] / modulos_val) * modulos_val);
        }
        #pragma unroll
        for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
          out[i] = result_vec[i];
        }
      }
    }

  template <typename SimdT>
    double modulo_by_column_fpga_wrapper(
      sycl::queue* q,
      typename SimdT::base_type * __restrict__ out_ptr,
      typename SimdT::base_type const * __restrict__ data_ptr,
      typename SimdT::base_type const * __restrict__ modulos_ptr,
      size_t element_count
    ) {
      using namespace sycl;
      using base_t = typename SimdT::base_type;

      auto start = high_resolution_clock::now();
      q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
              host_ptr<const base_t> in(data_ptr);
              host_ptr<const base_t> mod(modulos_ptr);
#ifdef FPGA_WRITE_TO_DEV
              device_ptr<base_t> out(out_ptr);
#else
              host_ptr<base_t> out(out_ptr);
#endif
              modulo_by_column_kernel<SimdT>(out, in, mod, element_count);
          });
      }).wait();
      auto end = high_resolution_clock::now();
      return static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }

    template <typename SimdT>
    double modulo_by_value_fpga_wrapper(
      sycl::queue* q,
      typename SimdT::base_type * __restrict__ out_ptr,
      typename SimdT::base_type const * __restrict__ data_ptr,
      typename SimdT::base_type const modulo,
      size_t element_count
    ) {
      using namespace sycl;
      using base_t = typename SimdT::base_type;

      auto start = high_resolution_clock::now();
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
      auto end = high_resolution_clock::now();
      return static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }


  template <typename T, size_t VectorSize>
    void bench_and_test_vector_size(
      sycl::queue* q,
      T * __restrict__ out_fpga,
      T const * __restrict__ data,
      T const * __restrict__ modulos,
      T * __restrict__ out_host,
      size_t element_count
    ) {
      auto result_buffer_fpga_on_host = create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, element_count * sizeof(uint64_t), ALIGNMENT);
      {
        modulo_by_column_scalar<T>(out_host, data, modulos, element_count);
        auto offloading_and_execution_time = modulo_by_column_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, modulos, element_count);
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

        auto execution_time = modulo_by_column_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, modulos, element_count);
#ifdef FPGA_WRITE_TO_DEV
      q->memcpy(result_buffer_fpga_on_host, out_fpga, 10 * sizeof(uint64_t));
      q->wait();
#else
      std::memcpy(result_buffer_fpga_on_host, out_fpga, 10 * sizeof(uint64_t));
#endif
        file_logging::log_to_file<true>(
          "FPGA - mod by column",
          tsl::type_name<T>(), 
          std::to_string(VectorSize), 
          std::to_string(element_count*sizeof(T)), 
          std::to_string(offloading_and_execution_time), 
          std::to_string(execution_time), 
          std::to_string((((element_count * sizeof(T)) / (1024.0 * 1024.0)) / (execution_time / 1000000.0))),
          file_logging::concat_pointer_to_string<T>(data, 10),
          file_logging::concat_pointer_to_string<T>(modulos, 10),
          file_logging::concat_pointer_to_string<T>(result_buffer_fpga_on_host, 10)
        );
      }
      {
        modulo_by_value_scalar<T>(out_host, data, modulos[0], element_count);
        auto offloading_and_execution_time = modulo_by_value_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, modulos[0], element_count);
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

        auto execution_time = modulo_by_value_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, modulos[0], element_count);
#ifdef FPGA_WRITE_TO_DEV
      q->memcpy(result_buffer_fpga_on_host, out_fpga, 10 * sizeof(uint64_t));
      q->wait();
#else
      std::memcpy(result_buffer_fpga_on_host, out_fpga, 10 * sizeof(uint64_t));
#endif
        file_logging::log_to_file<true>(
          "FPGA - mod by value",
          tsl::type_name<T>(), 
          std::to_string(VectorSize), 
          std::to_string(element_count*sizeof(T)), 
          std::to_string(offloading_and_execution_time), 
          std::to_string(execution_time), 
          std::to_string((((element_count * sizeof(T)) / (1024.0 * 1024.0)) / (execution_time / 1000000.0))),
          file_logging::concat_pointer_to_string<T>(data, 10),
          modulos[0],
          file_logging::concat_pointer_to_string<T>(result_buffer_fpga_on_host, 10)
        );
      }
      remove_buffer(q, result_buffer_fpga_on_host);
    }

  template <typename T>
    void bench_and_test_data_type(
      sycl::queue* q,
      size_t data_size
    ) {
      using namespace tsl;
      auto const buffer_count = data_size / sizeof(T);
      auto in = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size, ALIGNMENT);
      auto modulos = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size, ALIGNMENT);
#ifdef FPGA_WRITE_TO_DEV
      auto out_fpga = create_buffer<uint64_t>(q, MALLOC_TARGET::DEVICE, data_size, 64);
#else
      auto out_fpga = create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, data_size, 64);
#endif
      auto out_host = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size, ALIGNMENT);
      fill_buffer_random_in_range<T>(in, buffer_count, (T)10000, (T)1000000);
      fill_buffer_random_in_range<T>(modulos, buffer_count, (T)1, (T)8000);

      
      // bench_and_test_vector_size<T,  128>(q, out_fpga, in, modulos, out_host, buffer_count);
      // bench_and_test_vector_size<T,  256>(q, out_fpga, in, modulos, out_host, buffer_count);

#ifdef VL512
      bench_and_test_vector_size<T,  512>(q, out_fpga, in, modulos, out_host, buffer_count);
#endif
#ifdef VL1024
      bench_and_test_vector_size<T, 1024>(q, out_fpga, in, modulos, out_host, buffer_count);
#endif
#ifdef VL2048
      bench_and_test_vector_size<T, 2048>(q, out_fpga, in, modulos, out_host, buffer_count);
#endif
      remove_buffer(q, out_host);
      remove_buffer(q, out_fpga);
      remove_buffer(q, modulos);
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

    std::string log_file_name = "./benchmark_modulo_" + file_logging::get_current_time_as_string() + ".tsv";
    file_logging::open_log_file(log_file_name);

    std::stringstream header;
    file_logging::log_to_file<true>("target", "type", "vectorsize", "datasize", "offloading_and_execution_time", "execution_times", "throughput [MiB/s]", "data@10", "modulo(s)", "results@10");
    
#ifdef UI32
    tuddbs::bench_and_test_data_type<uint32_t>(&q, data_size);
#endif
#ifdef UI64
    tuddbs::bench_and_test_data_type<uint64_t>(&q, data_size);
#endif

    file_logging::close_log_file();

    return 0;
}
