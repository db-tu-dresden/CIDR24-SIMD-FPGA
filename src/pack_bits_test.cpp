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

#include <utils.h>
#include <exec.h>
#include <sycl.h>

#include <tslintrin.hpp>
#include <data.h>
#include <kernels.h>

#include <iostream>
#include <regex>
#include <algorithm>

namespace tuddbs{

    
    template<typename T>
    void bit_pack_scalar(
        T * out_ptr, T const * data_ptr, unsigned bitwidth, std::size_t element_count
    ) {
        // for the moment we make the following assumptions:
        // - bitwidth is const for whole data
        // - element_count is a multiple of sizeof(T) * CHAR_BIT
        auto const chunk_size = sizeof(T) * CHAR_BIT;
        auto unsigned_data_ptr = reinterpret_cast<std::make_unsigned_t<T> const *>(data_ptr);
        auto unsigned_out_ptr = reinterpret_cast<std::make_unsigned_t<T> *>(out_ptr);
        auto const data_end_ptr = unsigned_data_ptr + element_count;
        if(bitwidth == (sizeof(T)*CHAR_BIT)) {
            std::copy(unsigned_data_ptr, data_end_ptr, unsigned_out_ptr);
            return;
        }
        while (unsigned_data_ptr < data_end_ptr) {
            std::make_unsigned_t<T> result = 0;
            std::make_unsigned_t<T> current_bitwidth = 0;
            for (size_t i = 0; i < chunk_size; ++i) {
                auto const val = (*unsigned_data_ptr++);
                result |= (val << current_bitwidth);
                current_bitwidth += bitwidth;
                if (current_bitwidth >= chunk_size) {
                    *unsigned_out_ptr = result;
                    ++unsigned_out_ptr;
                    current_bitwidth -= chunk_size;
                    result = (val >> (bitwidth - current_bitwidth));
                }
            }
        }
    }

    template<typename SimdT>
    double bit_pack_linear_fpga_wrapper(
        sycl::queue* q,
        typename SimdT::base_type * __restrict__ out_ptr, 
        typename SimdT::base_type const * __restrict__ data_ptr_host, 
        unsigned bitwidth, size_t element_count
    ) {
        using namespace tsl;
        using namespace sycl;
        using base_t = typename SimdT::base_type;

        auto start = high_resolution_clock::now();
        q->submit([&](handler& h) {
            h.single_task([=]() [[intel::kernel_args_restrict]] {
                host_ptr<const base_t> in(data_ptr_host);
                host_ptr<base_t> out(out_ptr);
                packbits_linear<SimdT>(out, in, bitwidth, element_count);
            });
        }).wait();
        auto end = high_resolution_clock::now();
        return static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }
        template<typename SimdT>
    double bit_pack_treelike_fpga_wrapper(
        sycl::queue* q,
        typename SimdT::base_type * __restrict__ out_ptr, 
        typename SimdT::base_type const * __restrict__ data_ptr_host, 
        unsigned bitwidth, size_t element_count
    ) {
        using namespace tsl;
        using namespace sycl;
        using base_t = typename SimdT::base_type;

        auto start = high_resolution_clock::now();
        q->submit([&](handler& h) {
            h.single_task([=]() [[intel::kernel_args_restrict]] {
                host_ptr<const base_t> in(data_ptr_host);
                host_ptr<base_t> out(out_ptr);
                packbits_treelike<SimdT>(out, in, bitwidth, element_count);
            });
        }).wait();
        auto end = high_resolution_clock::now();
        return static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }

    template<typename T>
    void color_print(T value, unsigned bitwidth) {
        auto const bw = sizeof(T) * CHAR_BIT;
        std::cout << "\033[90m";
        for (size_t i = 0; i < (bw - bitwidth); ++i) {
            std::cout << "0";
        }
        std::cout << "\033[0m\033[42m";
        auto v = std::bitset<sizeof(T) * CHAR_BIT>{static_cast<unsigned long long>(value)};
        for (size_t i = 0; i < bitwidth; ++i) {
            std::cout << v[bitwidth - i - 1];
        }
        std::cout << "\033[0m (0x" << std::hex << value << std::dec << ")\t";
    }
    template<typename T>
    void print_packed(T value, unsigned bitwidth) {
        auto const bw = sizeof(T) * CHAR_BIT;
        auto v = std::bitset<sizeof(T) * CHAR_BIT>{static_cast<unsigned long long>(value)};
        for (size_t i = 0; i < bw; i+=bitwidth) {
            for (size_t j = 0; j < bitwidth; ++j) {
                std::cout << v[bw - i - j - 1];
            }
            std::cout << "|"; 
        }
        std::cout << "\t";
    }
    template<typename T>
    size_t print_differences_packed(T value1, T value2, unsigned bitwidth, size_t value_idx) {
        auto const bw = sizeof(T) * CHAR_BIT;
        auto v1 = std::bitset<sizeof(T) * CHAR_BIT>{static_cast<unsigned long long>(value1)};
        auto v2 = std::bitset<sizeof(T) * CHAR_BIT>{static_cast<unsigned long long>(value2)};
        auto current_value_idx = value_idx + (bw/bitwidth) - 1;
        for (size_t i = 0; i < bw; i+=bitwidth) {
            std::cout << "(" << std::setw(4) << current_value_idx << ")";
            for (size_t j = 0; j < bitwidth; ++j) {
                if(v1[bw - i - j - 1] != v2[bw - i - j - 1]){
                    std::cout << "\033[41m";
                }
                std::cout << v1[bw - i - j - 1];
                std::cout << "\033[0m";
            }
            --current_value_idx;
            std::cout << "|"; 
        }
        std::cout << "\t";
        current_value_idx = value_idx + (bw/bitwidth) - 1;
        for (size_t i = 0; i < bw; i+=bitwidth) {
            std::cout << "(" << std::setw(4) << current_value_idx << ")";
            for (size_t j = 0; j < bitwidth; ++j) {
                if(v1[bw - i - j - 1] != v2[bw - i - j - 1]){
                    std::cout << "\033[41m";
                }
                std::cout << v2[bw - i - j - 1];
                std::cout << "\033[0m";
            }
            std::cout << "|"; 
            --current_value_idx;
        }
        std::cout << "\n";
        return value_idx + (bw/bitwidth);
    }


    template<typename T>
    void compare_data(
        T* in, T * out, T * out_ref, unsigned bitwidth, std::size_t element_count, bool show_errors
    ) {
        if (memcmp(out, out_ref, element_count * sizeof(T)) != 0) {
            if(show_errors) {
                std::cerr << "ERROR: The FPGA result does not match the reference result!\n";
                std::cout << std::setw(sizeof(T) * CHAR_BIT) << "INPUT" << "\t" << std::setw(sizeof(T) * CHAR_BIT) << "FPGA" << "\t" << std::setw(sizeof(T) * CHAR_BIT) << "CPU" << "\n";
                size_t value_idx = 0;
                auto const min = (100 < element_count) ? 100 : element_count;
                for (size_t i = 0; i < min; ++i) {
                    std::cout << std::setw(4) << i << ":\t";
                    color_print<T>(in[i], bitwidth);
                    value_idx = print_differences_packed<T>(out[i], out_ref[i], bitwidth, value_idx);
                }
            }
            std::terminate();
        }
    }

    template<typename FpgaSimdT>
    void run_specific_test(
        sycl::queue* q, typename FpgaSimdT::base_type * test_data_input, typename FpgaSimdT::base_type * test_data_output, typename FpgaSimdT::base_type * test_data_output_ref, unsigned bitwidth, std::size_t element_count,
        bool show_errors = false
    ) {
        using BaseT = typename FpgaSimdT::base_type;
        std::cout << "\tFPGA implementation:" << std::endl;
        std::cout << "\t\tVector size: " << FpgaSimdT::vector_size_b() << "b" << std::endl;
        std::cout << "\t\t\tClearing output buffer... " << std::flush;
        fill_buffer_with_zero<BaseT>(test_data_output, element_count);
        std::cout << "Done." << std::endl;
        std::cout << "\t\t\tRunning bit-packing (linear)... " << std::flush;
        try {
            bit_pack_linear_fpga_wrapper<FpgaSimdT>(q, test_data_output, test_data_input, bitwidth, element_count);
        } catch (sycl::exception const &e) {
            std::cerr << "Caught a synchronous SYCL exception: " << e.what() << "\n";
            std::terminate();
        }
        std::cout << "Done." << std::endl;
        std::cout << "\t\t\tChecking... " << std::flush;
        compare_data<BaseT>(test_data_input, test_data_output, test_data_output_ref, bitwidth, element_count, show_errors);
        std::cout << "OK." << std::endl;
        std::cout << "\t\t\tClearing output buffer... " << std::flush;
        fill_buffer_with_zero<BaseT>(test_data_output, element_count);
        std::cout << "Done." << std::endl;
        std::cout << "\t\t\tRunning bit-packing (tree-like)... " << std::flush;
        try {
            bit_pack_treelike_fpga_wrapper<FpgaSimdT>(q, test_data_output, test_data_input, bitwidth, element_count);
        } catch (sycl::exception const &e) {
            std::cerr << "Caught a synchronous SYCL exception: " << e.what() << "\n";
            std::terminate();
        }
        std::cout << "Done." << std::endl;
        std::cout << "\t\t\tChecking... " << std::flush;
        compare_data<BaseT>(test_data_input, test_data_output, test_data_output_ref, bitwidth, element_count, show_errors);
        std::cout << "OK." << std::endl;
    }

    template<typename T>
    void run_test(sycl::queue* q, uint64_t * in, uint64_t * out, uint64_t * out_ref, unsigned bitwidth, size_t buffer_size) {
        size_t element_count = buffer_size / sizeof(T);

        auto test_data_input = reinterpret_cast<T *>(in);
        auto test_data_output = reinterpret_cast<T *>(out);
        auto test_data_output_ref = reinterpret_cast<T *>(out_ref);
        std::cout << "Running test: [data-size = " << buffer_size << "B, bitwidth = " << bitwidth << ", data type: " << tsl::type_name<T>() << "]" << std::endl;
        std::cout << "\tCPU-reference implementation:" << std::endl;
        std::cout << "\t\tClearing output buffer... " << std::flush;
        fill_buffer_with_zero<T>(test_data_output_ref, element_count);
        std::cout << "Done." << std::endl;
        std::cout << "\t\tRunning bit-packing... " << std::flush;
        bit_pack_scalar<T>(test_data_output_ref, test_data_input, bitwidth, element_count);
        std::cout << "Done." << std::endl;

        run_specific_test<
            tsl::simd<T, tsl::oneAPIfpga, 128>
        >(q, test_data_input, test_data_output, test_data_output_ref, bitwidth, element_count, true);
        run_specific_test<
            tsl::simd<T, tsl::oneAPIfpga, 256>
        >(q, test_data_input, test_data_output, test_data_output_ref, bitwidth, element_count, true);
        run_specific_test<
            tsl::simd<T, tsl::oneAPIfpga, 512>
        >(q, test_data_input, test_data_output, test_data_output_ref, bitwidth, element_count, true);

#ifdef BATCH_BUILD
        //Building the wider FPGA-SIMD-Bitwidths leed to tremendous compile times. Thats why we only build it if it is a batch build  
        run_specific_test<
            tsl::simd<T, tsl::oneAPIfpga, 1024>
        >(q, test_data_input, test_data_output, test_data_output_ref, bitwidth, element_count, true);
        run_specific_test<
            tsl::simd<T, tsl::oneAPIfpga, 2048>
        >(q, test_data_input, test_data_output, test_data_output_ref, bitwidth, element_count, true);
#endif
    }

    template<typename T>
    void test_datatype(sycl::queue* q, size_t data_size) {
        for(unsigned bw = 1; bw <= sizeof(T)*CHAR_BIT; ++bw) {
            auto [in, out_fpga, out_host, buffer_count] = create_buffers_with_host<T>(q, data_size);
            fill_bufer_random_up_to_bitwidth<T>(in, buffer_count, bw);
            
            run_test<T>(q, reinterpret_cast<uint64_t*>(in), reinterpret_cast<uint64_t*>(out_fpga), reinterpret_cast<uint64_t*>(out_host), bw, data_size);
        
            remove_buffers(q, in, out_fpga, out_host);
        }
    }

    size_t strToByte(std::string param) {
        std::regex opt_ex("([0-9]*)([a-zA-Z]*)");
        std::smatch matches;
        size_t multiplier = 1;
        size_t size = 0;
        std::map< std::string, size_t > suffixes = {
            {"kib",1024},
            {"mib",1024*1024},
            {"gib",1024*1024*1024}
        };
        if (std::regex_search(param, matches, opt_ex)) {
            size = stoll(matches[1].str());
            std::string suffix = matches[2].str();
            std::transform(suffix.begin(), suffix.end(), suffix.begin(), [](unsigned char c){ return std::tolower(c); });
            bool found_suffix = false;
            for ( auto pair : suffixes ) {
                if ( pair.first == suffix ) {
                    multiplier = pair.second;
                    found_suffix = true;
                    break;
                }
            }
            if ( !found_suffix ) {
                std::cerr << "Unrecognized suffix: " << param << std::endl;
                exit(-1);
            }
        } else {
            std::cerr << "Inproper command. Could not deduce size for: " << param << std::endl;
            exit(-2);
        }
        return size*multiplier;
    }
} // namespace tuddbs

int main(int argc, char** argv) {
    // the device selector
  #if FPGA_SIMULATOR
    auto selector = sycl::ext::intel::fpga_simulator_selector_v;
  #elif FPGA_HARDWARE
    auto selector = sycl::ext::intel::fpga_selector_v;
  #else  // #if FPGA_EMULATOR
    auto selector = sycl::ext::intel::fpga_emulator_selector_v;
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
        if ( memcmp( argv[i], size_param, 6 ) == 0 ) {
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

    tuddbs::test_datatype< uint8_t>(&q, data_size);
    tuddbs::test_datatype<  int8_t>(&q, data_size);
    tuddbs::test_datatype<uint16_t>(&q, data_size);
    tuddbs::test_datatype< int16_t>(&q, data_size);
    tuddbs::test_datatype<uint32_t>(&q, data_size);
    tuddbs::test_datatype< int32_t>(&q, data_size);
    tuddbs::test_datatype<uint64_t>(&q, data_size);
    tuddbs::test_datatype< int64_t>(&q, data_size);
    
    std::cout << "Everything fine. :)" << std::endl;
    return 0;
}