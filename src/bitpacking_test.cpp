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

#include <algorithm>
#include <bitset>
#include <cstddef>
#include <cstdint>
#include <tslintrin.hpp>

namespace tuddbs {

template <typename T>
size_t bitpacking_scalar(
  T* __restrict__ out_host,
  unsigned* __restrict__ out_bw_host,
  T const* __restrict__ in,
  size_t batch_element_count,
  size_t data_element_count) {
  // for the moment we make the following assumptions:
  // - element_count is a multiple of sizeof(T) * CHAR_BIT
  using namespace tsl;
  using UnsignedT = std::make_unsigned_t<T>;

  auto unsigned_data_ptr = reinterpret_cast<std::make_unsigned_t<T> const*>(in);
  auto unsigned_out_ptr = reinterpret_cast<std::make_unsigned_t<T>*>(out_host);
  auto const out_bw_host_orig = out_bw_host;
  auto const data_end_ptr = unsigned_data_ptr + data_element_count;
  auto const type_bit_width = sizeof(T) * CHAR_BIT;
  UnsignedT result = 0;
  UnsignedT current_bitwidth = 0;
  for (; unsigned_data_ptr < data_end_ptr; unsigned_data_ptr += batch_element_count) {
      T logical_ORed_data = 0;
      for (size_t i = 0; i < batch_element_count; ++i) {
          logical_ORed_data |= (unsigned_data_ptr[i]);
      }
      auto const leading_zero_count = __builtin_clzll(static_cast<uint64_t>(logical_ORed_data));
      UnsignedT bitwidth = (sizeof(uint64_t) * CHAR_BIT) - leading_zero_count;
      *out_bw_host++ = bitwidth;
      if (bitwidth == (sizeof(T) * CHAR_BIT)) {
          std::copy(unsigned_data_ptr, unsigned_data_ptr + batch_element_count, unsigned_out_ptr);
          unsigned_out_ptr += batch_element_count;
      } else {
          for (size_t i = 0; i < batch_element_count; ++i) {
              auto const val = (unsigned_data_ptr[i]);
              result |= (val << current_bitwidth);
              current_bitwidth += bitwidth;
              if (current_bitwidth >= type_bit_width) {
                  *unsigned_out_ptr = result;
                  ++unsigned_out_ptr;
                  current_bitwidth -= type_bit_width;
                  result = (val >> (bitwidth - current_bitwidth));
              }
          }
      }
  }
  if (current_bitwidth != 0) {
      *unsigned_out_ptr = result;
      ++unsigned_out_ptr;
  }
  return out_bw_host - out_bw_host_orig;
}

template <typename FpgaSimdT>
double bitpacking_fpga_wrapper(
    sycl::queue* q,
    typename FpgaSimdT::base_type* __restrict__ out_fpga,
    unsigned* __restrict__ out_bw_fpga,
    typename FpgaSimdT::base_type const* __restrict__ in,
    typename FpgaSimdT::base_type* __restrict__ in_buffer_fpga,
    size_t batch_element_count,
    size_t element_count) {
    using namespace tsl;
    using namespace sycl;
    using BaseT = typename FpgaSimdT::base_type;

    auto start = high_resolution_clock::now();
    q->submit([&](handler& h) {
         h.single_task([=]() [[intel::kernel_args_restrict]] {
             host_ptr<BaseT> ptr_out(out_fpga);
             host_ptr<unsigned> ptr_out_bw(out_bw_fpga);
             host_ptr<const BaseT> ptr_in(in);
             device_ptr<BaseT> ptr_buffer(in_buffer_fpga);
             bitpacking_FPGA_specialized_compress<FpgaSimdT>(ptr_out, ptr_out_bw, ptr_in, ptr_buffer, batch_element_count, element_count);
         });
     }).wait();
    auto end = high_resolution_clock::now();
    return static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
}

template <typename T>
void compare_data(
    T* __restrict__ out_fpga,
    T* __restrict__ out_host,
    unsigned* __restrict__ out_bw_fpga,
    unsigned* __restrict__ out_bw_host,
    T const* __restrict__ in,
    size_t batch_element_count,
    size_t data_element_count,
    bool show_errors = false) {
    size_t batch_count = data_element_count / batch_element_count;
    if (memcmp(out_bw_fpga, out_bw_host, batch_count * sizeof(unsigned)) != 0) {
        std::cout << "Error: Bitwdiths are inconsistent" << std::endl;
        if (show_errors) {
            for (size_t i = 0; i < batch_count; ++i) {
                if (out_bw_fpga[i] != out_bw_host[i]) {
                    std::cout << "Batch " << i << ": " << out_bw_fpga[i] << "(FGPA) vs. " << out_bw_host[i] << "(CPU)" << std::endl;
                    for (size_t j = 0; j < batch_element_count; ++j) {
                        std::cout << "[ " << std::setw(6) << i * batch_element_count + j << "]: " << std::bitset<sizeof(T) * CHAR_BIT>(in[i * batch_element_count + j]) << std::endl;
                    }
                }
            }
        }
        std::terminate();
    }
    size_t compressed_bit_count = 0;
    for (size_t i = 0; i < batch_count; ++i) {
        compressed_bit_count += out_bw_host[i] * batch_element_count;
    }
    size_t compressed_byte_count = compressed_bit_count / CHAR_BIT;
    if (memcmp(out_fpga, out_host, compressed_byte_count) != 0) {
        std::cout << "Error: Compressed data is inconsistent" << std::endl;
        if (show_errors) {
            for (size_t i = 0; i < compressed_byte_count; ++i) {
                if (out_fpga[i] != out_host[i]) {
                    std::cout << "Byte " << i << ": " << out_fpga[i] << "(FGPA) vs. " << out_host[i] << "(CPU)" << std::endl;
                }
            }
        }
        std::terminate();
    }
}

template <typename FpgaSimdT>
uint64_t run_specific_test(
    sycl::queue* q,
    typename FpgaSimdT::base_type* __restrict__ out_fpga,
    unsigned* __restrict__ out_bw_fpga,
    typename FpgaSimdT::base_type const* __restrict__ in,
    typename FpgaSimdT::base_type* __restrict__ in_buffer_fpga,
    size_t batch_element_count,
    size_t element_count) {
    using BaseT = typename FpgaSimdT::base_type;
    std::cout << "\t\t\tFPGA-" << FpgaSimdT::vector_size_b() << std::flush;
    fill_buffer_with_zero<BaseT>(out_fpga, element_count);
    fill_buffer_with_zero<unsigned>(out_bw_fpga, element_count / batch_element_count + 1);
    auto t_s = std::chrono::high_resolution_clock::now();
    try {
        bitpacking_fpga_wrapper<FpgaSimdT>(q, out_fpga, out_bw_fpga, in, in_buffer_fpga, batch_element_count, element_count);
    } catch (sycl::exception const& e) {
        std::cerr << "Caught a synchronous SYCL exception: " << e.what() << "\n";
        std::terminate();
    }
    auto t_e = std::chrono::high_resolution_clock::now();
    std::cout << " Done." << std::endl;
    return std::chrono::duration_cast<std::chrono::microseconds>(t_e - t_s).count();
}

template <typename T, bool run_scalar, size_t register_width>
std::pair<uint64_t, uint64_t> run_test(
    sycl::queue* q,
    T* __restrict__ out_fpga,
    T* __restrict__ out_host,
    unsigned* __restrict__ out_bw_fpga,
    unsigned* __restrict__ out_bw_host,
    T const* __restrict__ in,
    T* __restrict__ in_buffer_fpga,
    size_t batch_element_count,
    size_t data_element_count,
    bool show_errors = false
  ) {
    if (run_scalar) {
        std::cout << "\t\tCPU-reference... " << std::flush;
        fill_buffer_with_zero<T>(out_host, data_element_count);
        fill_buffer_with_zero<unsigned>(out_bw_host, data_element_count / batch_element_count + 1);
        uint64_t scalar_time = bitpacking_scalar<T>(out_host, out_bw_host, in, batch_element_count, data_element_count);
        std::cout << "Done." << std::endl;
        return std::make_pair(scalar_time, scalar_time);
    } else {
        const uint64_t offload_time = run_specific_test<
            tsl::simd<T, tsl::oneAPIfpga, register_width> >(q, out_fpga, out_bw_fpga, in, in_buffer_fpga, batch_element_count, data_element_count);
        std::cout << "\t\t\tChecking... " << std::flush;
        compare_data<T>(out_fpga, out_host, out_bw_fpga, out_bw_host, in, batch_element_count, data_element_count, show_errors);
        std::cout << "OK." << std::endl;
        std::cout << "\t\t\tRerun for execuction-only time." << std::endl;
        const uint64_t exec_time = run_specific_test<
            tsl::simd<T, tsl::oneAPIfpga, register_width> >(q, out_fpga, out_bw_fpga, in, in_buffer_fpga, batch_element_count, data_element_count);
        std::cout << "\t\t\tDone." << std::endl;
        return std::make_pair(offload_time, exec_time);
    }

    //     run_specific_test<
    //         tsl::simd<T, tsl::oneAPIfpga, 256> >(q, out_fpga, out_bw_fpga, in, in_buffer_fpga, batch_element_count, data_element_count);
    //     std::cout << "\t\t\tChecking... " << std::flush;
    //     compare_data<T>(out_fpga, out_host, out_bw_fpga, out_bw_host, in, batch_element_count, data_element_count, show_errors);
    //     std::cout << "OK." << std::endl;

    //     run_specific_test<
    //         tsl::simd<T, tsl::oneAPIfpga, 512> >(q, out_fpga, out_bw_fpga, in, in_buffer_fpga, batch_element_count, data_element_count);
    //     std::cout << "\t\t\tChecking... " << std::flush;
    //     compare_data<T>(out_fpga, out_host, out_bw_fpga, out_bw_host, in, batch_element_count, data_element_count, show_errors);
    //     std::cout << "OK." << std::endl;

    // #ifdef BATCH_BUILD
    //     // Building the wider FPGA-SIMD-Bitwidths leed to tremendous compile times. Thats why we only build it if it is a batch build
    //     run_specific_test<
    //         tsl::simd<T, tsl::oneAPIfpga, 1024> >(q, out_fpga, out_bw_fpga, in, in_buffer_fpga, batch_element_count, data_element_count);
    //     std::cout << "\t\t\tChecking... " << std::flush;
    //     compare_data<T>(out_fpga, out_host, out_bw_fpga, out_bw_host, in, batch_element_count, data_element_count, show_errors);
    //     std::cout << "OK." << std::endl;

    //     run_specific_test<
    //         tsl::simd<T, tsl::oneAPIfpga, 2048> >(q, out_fpga, out_bw_fpga, in, in_buffer_fpga, batch_element_count, data_element_count);
    //     std::cout << "\t\t\tChecking... " << std::flush;
    //     compare_data<T>(out_fpga, out_host, out_bw_fpga, out_bw_host, in, batch_element_count, data_element_count, show_errors);
    //     std::cout << "OK." << std::endl;
    // #endif
}

template <typename T>
void test(sycl::queue* q, size_t data_size) {
    uint64_t const lower_bw = 2;
    uint64_t const upper_bw = sizeof(T) * CHAR_BIT - lower_bw;
    auto const data_element_count = data_size / sizeof(T);
    auto in = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size);
    auto out_fpga = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size);
    auto out_host = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size);
    for (int outlier_prob_int = 0; outlier_prob_int < 100; ++outlier_prob_int) {
        float outlier_prob = static_cast<float>(outlier_prob_int) / 100.0f;
        fill_buffer_with_outliers<T>(in, data_element_count, lower_bw, upper_bw, outlier_prob);
        for (size_t batch_element_count = 32; batch_element_count <= 4096; batch_element_count *= 2) {
            auto in_buffer_fpga = create_buffer<T>(q, MALLOC_TARGET::DEVICE, batch_element_count * sizeof(T));
            auto out_bw_fpga = create_buffer<unsigned>(q, MALLOC_TARGET::HOST, data_element_count / batch_element_count + 1);
            auto out_bw_host = create_buffer<unsigned>(q, MALLOC_TARGET::HOST, data_element_count / batch_element_count + 1);
            std::cout << "Running test:" << std::endl;
            std::cout << "\tData type           = " << tsl::type_name<T>() << std::endl;
            std::cout << "\tInput data size     = ";
            data_size_to_ostream(std::cout, data_size);
            std::cout << std::endl;
            std::cout << "\tData element count  = " << data_element_count << std::endl;
            std::cout << "\tLower bitwidth      = " << lower_bw << std::endl;
            std::cout << "\tUpper bitwidth (U)  = " << upper_bw << std::endl;
            std::cout << "\tp(U)                = " << outlier_prob << std::endl;
            std::cout << "\tBatch element count = " << batch_element_count << std::endl;
            std::cout << "\tExecuting:" << std::endl;
            auto time_pair = run_test<T, true, sizeof(T) * 8>(
                q,
                out_fpga,
                out_host,
                out_bw_fpga,
                out_bw_host,
                in,
                in_buffer_fpga,
                batch_element_count,
                data_element_count,
                true);
            file_logging::log_to_file<true>(tsl::type_name<T>(), std::to_string(data_size), std::to_string(data_element_count),
                                            std::to_string(lower_bw), std::to_string(upper_bw), std::to_string(outlier_prob), std::to_string(batch_element_count),
                                            std::to_string(sizeof(T) * 8), std::to_string(time_pair.first), std::to_string(time_pair.second));
#ifdef VL128            
            time_pair = run_test<T, false, 128>(
                q,
                out_fpga,
                out_host,
                out_bw_fpga,
                out_bw_host,
                in,
                in_buffer_fpga,
                batch_element_count,
                data_element_count,
                true);
            file_logging::log_to_file<true>(tsl::type_name<T>(), std::to_string(data_size), std::to_string(data_element_count),
                                            std::to_string(lower_bw), std::to_string(upper_bw), std::to_string(outlier_prob), std::to_string(batch_element_count),
                                            std::to_string(128), std::to_string(time_pair.first), std::to_string(time_pair.second));
#endif
#ifdef VL256
            time_pair = run_test<T, false, 256>(
                q,
                out_fpga,
                out_host,
                out_bw_fpga,
                out_bw_host,
                in,
                in_buffer_fpga,
                batch_element_count,
                data_element_count,
                true);
            file_logging::log_to_file<true>(tsl::type_name<T>(), std::to_string(data_size), std::to_string(data_element_count),
                                            std::to_string(lower_bw), std::to_string(upper_bw), std::to_string(outlier_prob), std::to_string(batch_element_count),
                                            std::to_string(256), std::to_string(time_pair.first), std::to_string(time_pair.second));
#endif
#ifdef VL512
            time_pair = run_test<T, false, 512>(
                q,
                out_fpga,
                out_host,
                out_bw_fpga,
                out_bw_host,
                in,
                in_buffer_fpga,
                batch_element_count,
                data_element_count,
                true);
            file_logging::log_to_file<true>(tsl::type_name<T>(), std::to_string(data_size), std::to_string(data_element_count),
                                            std::to_string(lower_bw), std::to_string(upper_bw), std::to_string(outlier_prob), std::to_string(batch_element_count),
                                            std::to_string(512), std::to_string(time_pair.first), std::to_string(time_pair.second));
#endif

#ifdef VL1024
            time_pair = run_test<T, false, 1024>(
                q,
                out_fpga,
                out_host,
                out_bw_fpga,
                out_bw_host,
                in,
                in_buffer_fpga,
                batch_element_count,
                data_element_count,
                true);
            file_logging::log_to_file<true>(tsl::type_name<T>(), std::to_string(data_size), std::to_string(data_element_count),
                                            std::to_string(lower_bw), std::to_string(upper_bw), std::to_string(outlier_prob), std::to_string(batch_element_count),
                                            std::to_string(1024), std::to_string(time_pair.first), std::to_string(time_pair.second));
#endif
#ifdef VL2048
            time_pair = run_test<T, false, 2048>(
                q,
                out_fpga,
                out_host,
                out_bw_fpga,
                out_bw_host,
                in,
                in_buffer_fpga,
                batch_element_count,
                data_element_count,
                true);
            file_logging::log_to_file<true>(tsl::type_name<T>(), std::to_string(data_size), std::to_string(data_element_count),
                                            std::to_string(lower_bw), std::to_string(upper_bw), std::to_string(outlier_prob), std::to_string(batch_element_count),
                                            std::to_string(2048), std::to_string(time_pair.first), std::to_string(time_pair.second));
#endif
            remove_buffer(q, out_bw_host);
            remove_buffer(q, out_bw_fpga);
            remove_buffer(q, in_buffer_fpga);
        }
    }
    remove_buffer(q, out_host);
    remove_buffer(q, out_fpga);
    remove_buffer(q, in);
}

}  // namespace tuddbs

int main(void) {
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

    std::string log_file_name = "./bitpacking_test_" + file_logging::get_current_time_as_string() + ".log";
    file_logging::open_log_file(log_file_name);
    file_logging::log_to_file<true>("data type", "input data size", "data element count", "lower bitwidth", "upper bitwidth (U)", "tp(U)", "batch element count", "register bitwidth", "offload and execution time", "execution time");

    size_t data_size = 1_MiB;

#ifdef UI8
    tuddbs::test<uint8_t>(&q, data_size);
#endif
#ifdef UI16
    tuddbs::test<uint16_t>(&q, data_size);
#endif
#ifdef UI32
    tuddbs::test<uint32_t>(&q, data_size);
#endif
#ifdef UI64
    tuddbs::test<uint64_t>(&q, data_size);
#endif

    file_logging::close_log_file();

    std::cout << "Everything fine. :)" << std::endl;
    return 0;
}