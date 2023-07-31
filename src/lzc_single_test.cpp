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

namespace tuddbs{

    

    template<typename SimdT>
    double leading_zero_count_fpga_wrapper(
        sycl::queue* q,
        typename SimdT::offset_base_type * __restrict__ out_ptr, 
        typename SimdT::base_type const * __restrict__ data_ptr_host, 
        size_t element_count
    ) {
        using namespace tsl;
        using namespace sycl;
        using base_t = typename SimdT::base_type;
        using result_t = typename SimdT::offset_base_type;

        auto start = high_resolution_clock::now();
        q->submit([&](handler& h) {
            h.single_task([=]() [[intel::kernel_args_restrict]] {
                host_ptr<const base_t> in(data_ptr_host);
                host_ptr<result_t> out(out_ptr);
                for (size_t i = 0; i < element_count; ++i) {
                  out[i] = lzc<SimdT>(in[i]);
                }
            });
        }).wait();
        auto end = high_resolution_clock::now();
        return static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());
    }

    template<typename T >
    void print_differences(T value1, T value2) {
      if (value1 != value2) {
        std::cout << "\033[41m";
      }
      std::cout << std::setw(sizeof(T) * CHAR_BIT) << value1;
      std::cout << "\t";
      std::cout << std::setw(sizeof(T) * CHAR_BIT) << value2;
      std::cout << "\033[0m";
    }


    template<typename T, typename ResultT>
    void compare_data(
        T * in, ResultT * out, ResultT * out_ref, std::size_t element_count, bool show_errors
    ) {
        if (memcmp(out, out_ref, element_count * sizeof(T)) != 0) {
            if(show_errors) {
                std::cerr << "ERROR: The FPGA result does not match the reference result!\n";
                std::cout << std::setw(sizeof(T) * CHAR_BIT) << "INPUT" << "\t" << std::setw(sizeof(T) * CHAR_BIT) << "FPGA" << "\t" << std::setw(sizeof(T) * CHAR_BIT) << "CPU" << "\n";
                auto const min = (100 < element_count) ? 100 : element_count;
                for (size_t i = 0; i < min; ++i) {
                    std::cout << std::bitset<sizeof(T) * CHAR_BIT>{(unsigned long long)in[i]} << "\t";
                    print_differences<ResultT>(out[i], out_ref[i]);
                }
            }
            std::terminate();
        }
    }

    template<typename BaseT, typename ResultT, size_t VectorSize>
    void run_specific_test(
        sycl::queue* q, BaseT * test_data_input, ResultT * test_data_output, ResultT * test_data_output_ref, std::size_t element_count,
        bool show_errors = false
    ) {
        std::cout << "\tFPGA implementation:" << std::endl;
        std::cout << "\t\tVector size: " << VectorSize << "b" << std::endl;
        std::cout << "\t\t\tClearing output buffer... " << std::flush;
        fill_buffer_with_zero<ResultT>(test_data_output, element_count);
        std::cout << "Done." << std::endl;
        std::cout << "\t\t\tRunning leading zero count (OneAPI)... " << std::flush;
        try {
            leading_zero_count_fpga_wrapper<tsl::simd<BaseT, tsl::oneAPIfpga, VectorSize>>(q, test_data_output, test_data_input, element_count);
        } catch (sycl::exception const &e) {
            std::cerr << "Caught a synchronous SYCL exception: " << e.what() << "\n";
            std::terminate();
        }
        std::cout << "Done." << std::endl;
        std::cout << "\t\t\tChecking... " << std::flush;
        compare_data<BaseT, ResultT>(test_data_input, test_data_output, test_data_output_ref, element_count, show_errors);
        std::cout << "OK." << std::endl;
    }

    template<typename T>
    void run_test(sycl::queue* q, uint64_t * in, uint64_t * out, uint64_t * out_ref, unsigned bitwidth, size_t buffer_size) {
        size_t element_count = buffer_size / sizeof(T);
        
        using ResultT = std::make_unsigned_t<T>;
        ResultT const lzc_ref = static_cast<T>(sizeof(T)*CHAR_BIT - bitwidth);
        auto test_data_input = reinterpret_cast<T *>(in);
        auto test_data_output = reinterpret_cast<ResultT *>(out);
        auto test_data_output_ref = reinterpret_cast<ResultT *>(out_ref);
        std::cout << "Running test: [data-size = " << buffer_size << "B, bitwidth = " << bitwidth << ", data type: " << tsl::type_name<T>() << "]" << std::endl;
        std::cout << "\tCPU-reference implementation:" << std::endl;
        std::cout << "\t\tClearing output buffer... " << std::flush;
        fill_buffer_with_zero<ResultT>(test_data_output_ref, element_count);
        std::cout << "Done." << std::endl;
        std::cout << "\t\tSetting CPU Result... " << std::flush;
        for(size_t i = 0; i < element_count; ++i) {
            test_data_output_ref[i] = lzc_ref;
        }
        std::cout << "Done." << std::endl;

        run_specific_test<T, ResultT,  512>(q, test_data_input, test_data_output, test_data_output_ref, element_count, true);
    }

    template<typename T>
    void test_datatype(sycl::queue* q, size_t data_size) {
        for(unsigned bw = 1; bw <= sizeof(T)*CHAR_BIT; ++bw) {
            auto [in, out_fpga, out_host, buffer_count] = create_buffers_with_host<T>(q, data_size);
            fill_bufer_random_with_bitwidth<T>(in, buffer_count, bw);
            
            run_test<T>(q, reinterpret_cast<uint64_t*>(in), reinterpret_cast<uint64_t*>(out_fpga), reinterpret_cast<uint64_t*>(out_host), bw, data_size);
        
            remove_buffers(q, in, out_fpga, out_host);
        }
    }
} // namespace tuddbs

int main(void) {
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

    size_t data_size = 1_MiB;
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