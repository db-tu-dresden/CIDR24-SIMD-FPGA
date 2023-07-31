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
#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <tslintrin.hpp>
#include "dbsbenchmark.hpp"

namespace tuddbs {
template <typename SimdT, typename InPtrT, typename OutPtrT>
void hadd_kernel(
    OutPtrT out_ptr, InPtrT data_ptr, std::size_t element_count) {
    uint64_t overall_result = 0;
    const auto data_end_ptr = data_ptr + element_count;
    for (; data_ptr != data_end_ptr; data_ptr += SimdT::vector_element_count()) {
        auto load_vec = tsl::loadu<SimdT>(data_ptr);
        auto result = tsl::hadd<SimdT>(load_vec);
        overall_result += result;
    }
    *out_ptr = overall_result;
}

template <typename SimdT>
auto hadd_tuple_fpga_wrapper(
    sycl::queue* q,
    uint64_t* __restrict__ out_ptr,
    typename SimdT::base_type const* __restrict__ data_ptr,
    size_t element_count) {
    using namespace tsl;
    using namespace sycl;
    using base_t = typename SimdT::base_type;

    auto start = default_clock_t::now();
    q->submit([&](handler& h) {
         h.single_task([=]() [[intel::kernel_args_restrict]] {
             host_ptr<const base_t> in(data_ptr);
             host_ptr<uint64_t> out(out_ptr);
             hadd_kernel<SimdT>(out, in, element_count);
         });
     }).wait();
    auto end = default_clock_t::now();
    return std::make_pair(start, end);
}
template <typename SimdT>
auto hadd_array_fpga_wrapper(
    sycl::queue* q,
    uint64_t* __restrict__ out_ptr,
    typename SimdT::base_type const* __restrict__ data_ptr,
    size_t element_count) {
    using namespace tsl;
    using namespace sycl;
    using base_t = typename SimdT::base_type;

    auto start = default_clock_t::now();
    q->submit([&](handler& h) {
         h.single_task([=]() [[intel::kernel_args_restrict]] {
             host_ptr<const base_t> in(data_ptr);
             host_ptr<uint64_t> out(out_ptr);
             hadd_kernel<SimdT>(out, in, element_count);
         });
     }).wait();
    auto end = default_clock_t::now();
    return std::make_pair(start, end);
}

template <typename T, size_t VectorSize>
void test_vector_size(sycl::queue* q, size_t const element_count, T* in, uint64_t* out, tuddbs::csv_filewriter_t & writer) {
    using namespace tsl;
    {
      auto [start_offload_exec, end_offload_exec] = hadd_tuple_fpga_wrapper<simd<T, oneAPIfpga, VectorSize>>(q, out, in, element_count);
      auto offload_result = std::to_string(out[0]);
      auto [start_exec, end_exec] = hadd_tuple_fpga_wrapper<simd<T, oneAPIfpga, VectorSize>>(q, out, in, element_count);
        writer.write_line(
          PLATFORM, COMPILER, VERSION,
          "fpga", 
          "hadd", 
          "tuple aggregate",
          tsl::type_name<T>(), std::to_string(VectorSize),
          element_count,
          element_count * sizeof(T),
          default_clock_t::duration(start_offload_exec, end_offload_exec), default_clock_t::duration(start_exec, end_exec),
          default_tput_t::throughput(start_exec, end_exec, element_count * sizeof(T)),
          offload_result, std::to_string(out[0])
        );
    }
    {
      auto [start_offload_exec, end_offload_exec] = hadd_array_fpga_wrapper<simd<T, oneAPIfpga, VectorSize>>(q, out, in, element_count);
      auto offload_result = std::to_string(out[0]);
      auto [start_exec, end_exec] = hadd_array_fpga_wrapper<simd<T, oneAPIfpga, VectorSize>>(q, out, in, element_count);
        writer.write_line(
          PLATFORM, COMPILER, VERSION,
          "fpga", 
          "hadd", 
          "array aggregate",
          tsl::type_name<T>(), std::to_string(VectorSize),
          element_count,
          element_count * sizeof(T),
          default_clock_t::duration(start_offload_exec, end_offload_exec), default_clock_t::duration(start_exec, end_exec),
          default_tput_t::throughput(start_exec, end_exec, element_count * sizeof(T)),
          offload_result, std::to_string(out[0])
        );
    }
}

template <typename T>
void test_datatype(sycl::queue* q,tuddbs::csv_filewriter_t & writer, size_t data_size) {
    using namespace tsl;
    auto const element_count = data_size / sizeof(T);
    auto in = create_buffer<T>(q, MALLOC_TARGET::HOST, data_size);
    auto out_fpga = create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, 80);
    fill_buffer_with_value<T>(in, element_count, (T)1);
#ifdef VL128
    test_vector_size<T, 128>(q, element_count, in, out_fpga, writer);
#endif
#ifdef VL256
    test_vector_size<T, 256>(q, element_count, in, out_fpga, writer);
#endif
#ifdef VL512
    test_vector_size<T, 512>(q, element_count, in, out_fpga, writer);
#endif
#ifdef VL1024
    test_vector_size<T, 1024>(q, element_count, in, out_fpga, writer);
#endif
#ifdef VL2048
    test_vector_size<T, 2048>(q, element_count, in, out_fpga, writer);
#endif
#ifdef VL4096
    test_vector_size<T, 4096>(q, element_count, in, out_fpga, writer);
#endif
    remove_buffer(q, out_fpga);
    remove_buffer(q, in);
}

}  // namespace tuddbs

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

    tuddbs::csv_filewriter_t writer("benchmark_results_hadd_aggregate", "\t");
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
    tuddbs::test_datatype<uint8_t>(&q, writer, data_size);
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

    file_logging::close_log_file();

    return 0;
}
