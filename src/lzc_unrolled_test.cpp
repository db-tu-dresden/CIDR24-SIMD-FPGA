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

#include <cstddef>
#include <cstdint>
#include <bitset>
#include <algorithm>
#include <array>

#include <cstring>
#include <ctime>
#include <type_traits>
#include <utils.h>
#include <exec.h>
#include <sycl.h>
#include <type_traits>
#include <climits>
#include <tslintrin.hpp>
#include <data.h>
#include <kernels.h>
#include "dbsbenchmark.hpp"

#define ALIGNMENT 0



namespace tuddbs{

  template<typename T>
  void leading_zero_scalar(
    T * __restrict__ out_ptr, 
    T const * __restrict__ data_ptr, 
    size_t element_count
  ) {
    for (size_t i = 0; i < element_count; ++i) {
      T data = data_ptr[i];
      if constexpr(sizeof(T) <= sizeof(unsigned int)) {
        out_ptr[i] = data == 0 ? std::numeric_limits<T>::digits : __builtin_clz(data) - (sizeof(unsigned int) * CHAR_BIT - sizeof(T) * CHAR_BIT);
      } else if constexpr(sizeof(T) <= sizeof(unsigned long)) {
        out_ptr[i] = data == 0 ? std::numeric_limits<T>::digits : __builtin_clzl(data) - (sizeof(unsigned long) * CHAR_BIT - sizeof(T) * CHAR_BIT);
      } else if constexpr(sizeof(T) <= sizeof(unsigned long long)) {
        out_ptr[i] = data == 0 ? std::numeric_limits<T>::digits : __builtin_clzll(data) - (sizeof(unsigned long long) * CHAR_BIT - sizeof(T) * CHAR_BIT);
      }
      
    }
  }

  template<typename SimdT>
  auto leading_zero_count_fpga_wrapper(
      sycl::queue* q,
      typename SimdT::base_type * __restrict__ out_ptr, 
      typename SimdT::base_type const * __restrict__ data_ptr_host, 
      size_t element_count
  ) {
      static_assert(sizeof(typename SimdT::base_type) >= 4, "base_type must be at least 4 bytes");
      using namespace tsl;
      using namespace sycl;
      using base_t = typename SimdT::base_type;

      auto start = default_clock_t::now();
      q->submit([&](handler& h) {
        h.single_task([=]() [[intel::kernel_args_restrict]] {
          host_ptr<const base_t> in(data_ptr_host);
#ifdef FPGA_WRITE_TO_DEV
          device_ptr<base_t> out(out_ptr);
#else
          host_ptr<base_t> out(out_ptr);
#endif
          auto const data_ptr_end = in + element_count;
          [[intel::fpga_register]] typename SimdT::base_type leading_zero_lut[16] = {4, 3, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
          [[intel::fpga_register]] std::array<typename SimdT::base_type, SimdT::vector_element_count()> data_vec{};
          [[intel::fpga_register]] std::array<typename SimdT::base_type, SimdT::vector_element_count()> result_vec{};
          for (;in < data_ptr_end; in += SimdT::vector_element_count(), out += SimdT::vector_element_count()) {
            #pragma unroll
            for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
              data_vec[i] = in[i];
            }
            #pragma unroll
            for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
              if constexpr(sizeof(typename SimdT::base_type) == 4) {
                result_vec[i] = 
                  (data_vec[i] >> 16)
                  ?
                    (
                      (data_vec[i] >> 24)
                      ?
                        (
                          (data_vec[i] >> 28)
                          ?
                            (
                              leading_zero_lut[data_vec[i] >> 28]
                            )
                          :
                            (
                              4 + leading_zero_lut[(data_vec[i] >> 24) & 0xf]
                            )
                        )
                      :
                        (
                          8 + (
                            ((data_vec[i] >> 20) & 0xff)
                            ?
                              (
                                leading_zero_lut[(data_vec[i] >> 20) & 0xff]
                              )
                            :
                              (
                                4 + leading_zero_lut[(data_vec[i] >> 16) & 0xf]
                              )
                          )
                        )
                    )
                  :
                    (
                      16 + (
                        ((data_vec[i] >> 8) & 0xffff)
                        ?
                          (
                            ((data_vec[i] >> 12) & 0xffff)
                            ?
                              (
                                leading_zero_lut[(data_vec[i] >> 12) & 0xffff]
                              )
                            :
                              (
                                4 + leading_zero_lut[(data_vec[i] >> 8) & 0xf]
                              )
                          )
                        :
                          (
                            8 + (
                              ((data_vec[i] >> 4) & 0xff)
                              ?
                                (
                                  leading_zero_lut[(data_vec[i] >> 4) & 0xff]
                                )
                              :
                                (
                                  4 + leading_zero_lut[data_vec[i] & 0xf]
                                )
                            )
                          )
                      )
                    );
              } else if constexpr(sizeof(typename SimdT::base_type) == 8) {
                result_vec[i] = 
                  (data_vec[i] >> 32)
                  ?
                    (
                      (data_vec[i] >> 48)
                      ?
                        (
                          (data_vec[i] >> 56)
                          ?
                            (
                              (data_vec[i] >> 60)
                              ?
                                (
                                  leading_zero_lut[data_vec[i] >> 60]
                                )
                              :
                                (
                                  4 + leading_zero_lut[(data_vec[i] >> 56) & 0xf]
                                )
                            )
                          :
                            (
                              8 + (
                                ((data_vec[i] >> 52) & 0xff)
                                ?
                                  (
                                    leading_zero_lut[(data_vec[i] >> 52) & 0xff]
                                  )
                                :
                                  (
                                    4 + leading_zero_lut[(data_vec[i] >> 48) & 0xf]
                                  )
                              )
                            )
                        )
                      :
                        (
                          16 + (
                            ((data_vec[i] >> 40) & 0xffff)
                            ?
                              (
                                ((data_vec[i] >> 44) & 0xffff)
                                ?
                                  (
                                    leading_zero_lut[(data_vec[i] >> 44) & 0xffff]
                                  )
                                :
                                  (
                                    4 + leading_zero_lut[(data_vec[i] >> 40) & 0xf]
                                  )
                              )
                            :
                              (
                                8 + (
                                  ((data_vec[i] >> 36) & 0xff)
                                  ?
                                    (
                                      leading_zero_lut[(data_vec[i] >> 36) & 0xff]
                                    )
                                  :
                                    (
                                      4 + leading_zero_lut[(data_vec[i] >> 32) & 0xf]
                                    )
                                )
                              )
                          )
                        )
                    )
                  :
                    (
                      32 + (
                        ((data_vec[i] >> 16) & 0xffffffff)
                        ?
                          (
                            ((data_vec[i] >> 24)  & 0xffffffff)
                            ?
                              (
                                ((data_vec[i] >> 28) & 0xffffffff)
                                ?
                                  (
                                    leading_zero_lut[(data_vec[i] >> 28) & 0xffffffff]
                                  )
                                :
                                  (
                                    4 + leading_zero_lut[(data_vec[i] >> 24) & 0xf]
                                  )
                              )
                            :
                              (
                                8 + (
                                  ((data_vec[i] >> 20) & 0xff)
                                  ?
                                    (
                                      leading_zero_lut[(data_vec[i] >> 20) & 0xff]
                                    )
                                  :
                                    (
                                      4 + leading_zero_lut[(data_vec[i] >> 16) & 0xf]
                                    )
                                )
                              )
                          )
                        :
                          (
                            16 + (
                              ((data_vec[i] >> 8)& 0xffff)
                              ?
                                (
                                  ((data_vec[i] >> 12) & 0xffff)
                                  ?
                                    (
                                      leading_zero_lut[(data_vec[i] >> 12) & 0xffff]
                                    )
                                  :
                                    (
                                      4 + leading_zero_lut[(data_vec[i] >> 8) & 0xf]
                                    )
                                )
                              :
                                (
                                  8 + (
                                    ((data_vec[i] >> 4) & 0xff)
                                    ?
                                      (
                                        leading_zero_lut[(data_vec[i] >> 4) & 0xff]
                                      )
                                    :
                                      (
                                        4 + leading_zero_lut[data_vec[i] & 0xf]
                                      )
                                  )
                                )
                            )
                          )
                      )
                    );
              } 
            }
            #pragma unroll
            for (size_t i = 0; i < SimdT::vector_element_count(); ++i) {
              out[i] = result_vec[i];
            }
          }
        });
      }).wait();
      auto end = default_clock_t::now();
      return std::make_pair(start, end);
  }

  template<typename T, size_t VectorSize>
  void bench_and_test_vector_size(
      sycl::queue* q, T const * __restrict__ data, T * __restrict__ out_fpga, T * __restrict__ out_host, std::size_t element_count,
      tuddbs::csv_filewriter_t & writer
  ) {
    auto result_buffer_fpga_on_host = create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, element_count * sizeof(uint64_t), ALIGNMENT);
    leading_zero_scalar<T>(out_host, data, element_count);
    auto [start_offload_exec, end_offload_exec] = 
      leading_zero_count_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, element_count);
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

    auto [start_exec, end_exec] = 
      leading_zero_count_fpga_wrapper<tsl::simd<T, tsl::oneAPIfpga, VectorSize>>(q, out_fpga, data, element_count);
#ifdef FPGA_WRITE_TO_DEV
      q->memcpy(result_buffer_fpga_on_host, out_fpga, 10 * sizeof(uint64_t));
      q->wait();
#else
      std::memcpy(result_buffer_fpga_on_host, out_fpga, 10 * sizeof(uint64_t));
#endif

    writer.write_line(
      "fpga", 
      "leading_zero_count", tsl::type_name<T>(), std::to_string(VectorSize),
      element_count * sizeof(T),
      default_clock_t::duration(start_offload_exec, end_offload_exec), default_clock_t::duration(start_exec, end_exec),
      default_tput_t::throughput(start_exec, end_exec, element_count * sizeof(T))
    );
    remove_buffer(q, result_buffer_fpga_on_host);
  }


  template<typename T>
  void test_datatype(sycl::queue* q, tuddbs::csv_filewriter_t & writer, size_t data_size) {
    static_assert(std::is_unsigned<T>::value, "T must be an unsigned type");
    size_t element_count = data_size / sizeof(T);
    auto in = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size, ALIGNMENT);
#ifdef FPGA_WRITE_TO_DEV
    auto out_fpga = create_buffer<T>(q, MALLOC_TARGET::DEVICE, data_size, ALIGNMENT);
#else
    auto out_fpga = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size, ALIGNMENT);
#endif
    auto out_host = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size, ALIGNMENT);
    
    fill_buffer_random_in_range<T>(in, element_count, (T) 0, (T) 1<<((sizeof(T)*CHAR_BIT - 1)));
    
#ifdef VL128
    bench_and_test_vector_size<T,  128>(q, in, out_fpga, out_host, element_count, writer);
#endif
#ifdef VL256
    bench_and_test_vector_size<T,  256>(q, in, out_fpga, out_host, element_count, writer);
#endif
#ifdef VL512
    bench_and_test_vector_size<T,  512>(q, in, out_fpga, out_host, element_count, writer);
#endif
#ifdef VL1024
    bench_and_test_vector_size<T, 1024>(q, in, out_fpga, out_host, element_count, writer);
#endif
#ifdef VL2048
    bench_and_test_vector_size<T, 2048>(q, in, out_fpga, out_host, element_count, writer);
#endif  
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

    tuddbs::csv_filewriter_t writer("benchmark_results_clz", "\t");
    auto fields = writer.create_field_names_description();
    fields.append_bulk(
      "target", 
      "operation", "type", "vectorsize", 
      "datasize", 
      "offloading_and_execution_time", "execution_time", "throughput " + tuddbs::default_tput_t::unit_str());
    writer.set_field_names(fields);

#ifdef UI8
    tuddbs::test_datatype< uint8_t>(&q, writer, data_size);
#endif
#ifdef UI16    
    tuddbs::test_datatype<uint16_t>(&q, writer, data_size);
#endif
#ifdef UI32    
    tuddbs::test_datatype<uint32_t>(&q, writer, data_size);
#endif
#ifdef UI64
    tuddbs::test_datatype<uint64_t>(&q, writer, data_size);
#endif    
    std::cout << "Everything fine. :)" << std::endl;
    return 0;
}