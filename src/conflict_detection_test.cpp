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

  template <typename SimdT, typename InPtrT, typename OutPtrT>
    void conflict_detection_kernel(
      OutPtrT out,
      InPtrT data,
      size_t element_count
    ) {
      auto const data_end = data + element_count;
      for (; data != data_end; data += SimdT::vector_element_count(), out += SimdT::vector_element_count()) {
        auto data_vec = tsl::loadu<SimdT>(data);
        auto result = tsl::conflict<SimdT>(data_vec);
        tsl::store<SimdT>(out, result);
      }
      }
  // template <typename InPtrT, typename OutPtrT>
  //   void conflict_detection_kernel_man_unrolled(
  //     OutPtrT out,
  //     InPtrT data,
  //     size_t element_count
  //   ) {
  //     auto const data_end = data + element_count;
  //     for (; data != data_end; data += 8, out += 8) {
  //       __attribute__((register)) std::array<uint64_t, 8> data_vec{};
  //       for (size_t i = 0; i < 8; ++i) {
  //         data_vec[i] = data[i];
  //       }
  //       __attribute__((register)) std::array<uint64_t, 8> result{};
  //       result[7] = ((data_vec[7] == data_vec[6]) ? 0b1000000 : 0) | ((data_vec[7] == data_vec[5]) ? 0b100000 : 0) | ((data_vec[7] == data_vec[4]) ? 0b10000 : 0) | ((data_vec[7] == data_vec[3]) ? 0b1000 : 0) | ((data_vec[7] == data_vec[2]) ? 0b100 : 0) | ((data_vec[7] == data_vec[1]) ? 0b10 : 0) | ((data_vec[7] == data_vec[0]) ? 0b1 : 0);
  //       result[6] = ((data_vec[6] == data_vec[5]) ? 0b100000 : 0) | ((data_vec[6] == data_vec[4]) ? 0b10000 : 0) | ((data_vec[6] == data_vec[3]) ? 0b1000 : 0) | ((data_vec[6] == data_vec[2]) ? 0b100 : 0) | ((data_vec[6] == data_vec[1]) ? 0b10 : 0) | ((data_vec[6] == data_vec[0]) ? 0b1 : 0);
  //       result[5] = ((data_vec[5] == data_vec[4]) ? 0b10000 : 0) | ((data_vec[5] == data_vec[3]) ? 0b1000 : 0) | ((data_vec[5] == data_vec[2]) ? 0b100 : 0) | ((data_vec[5] == data_vec[1]) ? 0b10 : 0) | ((data_vec[5] == data_vec[0]) ? 0b1 : 0);
  //       result[4] = ((data_vec[4] == data_vec[3]) ? 0b1000 : 0) | ((data_vec[4] == data_vec[2]) ? 0b100 : 0) | ((data_vec[4] == data_vec[1]) ? 0b10 : 0) | ((data_vec[4] == data_vec[0]) ? 0b1 : 0);
  //       result[3] = ((data_vec[3] == data_vec[2]) ? 0b100 : 0) | ((data_vec[3] == data_vec[1]) ? 0b10 : 0) | ((data_vec[3] == data_vec[0]) ? 0b1 : 0);
  //       result[2] = ((data_vec[2] == data_vec[1]) ? 0b10 : 0) | ((data_vec[2] == data_vec[0]) ? 0b1 : 0);
  //       result[1] = ((data_vec[1] == data_vec[0]) ? 0b1 : 0);
  //       for (size_t i = 0; i < 8; ++i) {
  //         out[i] = result[i];
  //       }
  //     }
  //   }
  
  // double bench_manual(
  //   sycl::queue * q, 
  //   size_t elemendata_size);conflict_detection_kernel_man_unrolled

  template <typename SimdT>
    double conflict_detection_fpga_wrapper(
      sycl::queue* q,
      typename SimdT::base_type * __restrict__ out_ptr,
      typename SimdT::base_type const * __restrict__ data_ptr,
      size_t element_count
    ) {
      using namespace tsl;
      using namespace sycl;
      using base_t = typename SimdT::base_type;

      auto start = high_resolution_clock::now();
      q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
              host_ptr<const base_t> in(data_ptr);
              host_ptr<base_t> out(out_ptr);
              conflict_detection_kernel<SimdT>(out, in, element_count);
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
      T * __restrict__ out_host,
      size_t element_count
    ) {
      conflict_detection_scalar<T, VectorSize>(out_host, data, element_count);
      auto offloading_and_execution_time = conflict_detection_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, element_count);
      for (size_t i = 0; i < element_count; ++i) {
        if (out_host[i] != out_fpga[i]) {
          std::cerr << "Error at index " << i << ": " << out_host[i] << " != " << out_fpga[i] << std::endl;
          std::cerr << "Respective data: " << std::endl;
          auto const batch_size = VectorSize/(CHAR_BIT*sizeof(T));
          auto const start = (i/batch_size)*batch_size;
          for (size_t j = start; j < start + batch_size; ++j) {
            std::cerr << data[j] << " ";
          }
          std::cerr << std::endl;
          throw std::runtime_error("Error in conflict detection.");
        }
      }
      auto execution_time = conflict_detection_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, element_count);
      file_logging::log_to_file<true>(
        "FPGA",
        tsl::type_name<T>(), 
        std::to_string(VectorSize), 
        std::to_string(element_count*sizeof(T)), 
        std::to_string(offloading_and_execution_time), 
        std::to_string(execution_time), 
        std::to_string((((element_count * sizeof(T)) / (1024.0 * 1024.0)) / (execution_time / 1000000.0))),
        file_logging::concat_pointer_to_string<T>(data, 10),
        file_logging::concat_pointer_to_string<T>(out_fpga, 10),
        "-", "-"
      );
    }

  template <typename T>
    void bench_and_test_data_type(
      sycl::queue* q,
      size_t data_size
    ) {
      using namespace tsl;
      auto const buffer_count = data_size / sizeof(T);
      auto in = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size, 64);
      auto out_fpga = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size, 64);
      auto out_host = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size, 64);
      fill_buffer_random_in_range<T>(in, buffer_count, (T)0, (T)30);

      if constexpr (is_conflict_detection_possible<T, 128>()) {
        bench_and_test_vector_size<T,  128>(q, out_fpga, in, out_host, buffer_count);
      } else {
        std::cerr << "Skipping 128 bit vector size for type " << tsl::type_name<T>() << std::endl;
      }
      if constexpr (is_conflict_detection_possible<T, 256>()) {
        bench_and_test_vector_size<T,  256>(q, out_fpga, in, out_host, buffer_count);
      } else {
        std::cerr << "Skipping 256 bit vector size for type " << tsl::type_name<T>() << std::endl;
      }
      if constexpr (is_conflict_detection_possible<T, 512>()) {
        bench_and_test_vector_size<T,  512>(q, out_fpga, in, out_host, buffer_count);
      } else {
        std::cerr << "Skipping 512 bit vector size for type " << tsl::type_name<T>() << std::endl;
      }
      if constexpr (is_conflict_detection_possible<T, 1024>()) {
        bench_and_test_vector_size<T, 1024>(q, out_fpga, in, out_host, buffer_count);
      } else {
        std::cerr << "Skipping 1024 bit vector size for type " << tsl::type_name<T>() << std::endl;
      }
      if constexpr (is_conflict_detection_possible<T, 2048>()) {
        bench_and_test_vector_size<T, 2048>(q, out_fpga, in, out_host, buffer_count);
      } else {
        std::cerr << "Skipping 2048 bit vector size for type " << tsl::type_name<T>() << std::endl;
      }
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

    /**
      * Conflict detection needs at least as many bits per value as there are values in a vector register.
      * - 128 bit Vector:
      *    -> 8 bit values: 16 values per vector --> not possible
      *    -> 16 bit values: 8 values per vector --> possible
      *    -> 32 bit values: 4 values per vector --> possible
      *    -> 64 bit values: 2 values per vector --> possible
      * - 256 bit Vector:
      *    -> 8 bit values: 32 values per vector --> not possible
      *    -> 16 bit values: 16 values per vector --> possible
      *    -> 32 bit values: 8 values per vector --> possible
      *    -> 64 bit values: 4 values per vector --> possible
      * - 512 bit Vector:
      *    -> 8 bit values: 64 values per vector --> not possible
      *    -> 16 bit values: 32 values per vector --> not possible
      *    -> 32 bit values: 16 values per vector --> possible
      *    -> 64 bit values: 8 values per vector --> possible
      * - 1024 bit Vector:
      *    -> 8 bit values: 128 values per vector --> not possible
      *    -> 16 bit values: 64 values per vector --> not possible
      *    -> 32 bit values: 32 values per vector --> possible
      *    -> 64 bit values: 16 values per vector --> possible
      * - 2048 bit Vector:
      *    -> 8 bit values: 256 values per vector --> not possible
      *    -> 16 bit values: 128 values per vector --> not possible
      *    -> 32 bit values: 64 values per vector --> not possible
      *    -> 64 bit values: 32 values per vector --> possible
      * =====================================================================================================
      * Conclusion:
      * 8 bit values can not be used.
    **/
    
#ifdef UI16
    tuddbs::bench_and_test_data_type<uint16_t>(&q, data_size);
#endif
#ifdef UI32
    tuddbs::bench_and_test_data_type<uint32_t>(&q, data_size);
#endif
#ifdef UI64
    tuddbs::bench_and_test_data_type<uint64_t>(&q, data_size);
#endif


    // tuddbs::bench_manual(&q, data_size);

    file_logging::close_log_file();

    return 0;
}
