#include "agg_helper.hpp"
#include "scalar_agg.hpp"
#include "autovec_agg.hpp"
#include "../include/data.hpp"
#include "../include/utils.hpp"
#include <data.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <CL/sycl.hpp>
#include <sycl/ext/intel/fpga_extensions.hpp>


#define ALIGNMENT 0

std::ofstream aggregate_results;
std::ofstream masked_aggregate_results;

// void exception_handler(sycl::exception_list exceptions) {
//     for (std::exception_ptr const& e : exceptions) {
//         try {
//             std::rethrow_exception(e);
//         } catch (sycl::exception const& e) {
//             std::cout << "Caught asynchronous SYCL exception:\n"
//                       << e.what() << std::endl;
//         }
//     }
// }

namespace tuddbs {

  template<typename T, int BS>
    void run_aggregate_autovec(
      sycl::queue* q,
      T const * __restrict__ measurement_data, 
      size_t byte_size
    ) {
      using namespace sycl;
      // AUTOVEC_AGG.HPP
      std::cerr << "\t\tAutovec (Vec size: " << BS << ")" << std::flush;
      for (size_t i = 0; i < 2; ++i){
        std::cerr << i << " ACCUM. " << std::flush;
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const T> in(measurement_data);
            host_ptr<uint64_t> out(result);
            *out = aggregate_autovec_N<T, BS, HORIZONTAL_AGGREGATION_STRATEGY::ACCUM>(in, byte_size/sizeof(T));
          });
        }).wait();
        auto end = current_time();
        aggregate_results << COMPILER << "\t"
                          << VERSION << "\t"
                          << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
                          << i << "\t"
                          << "aggregate" << "\t" 
                          << "autovec - horizontal accum" << "\t"
                          << BS << "\t"
                          << byte_size << "\t"
                          << sizeof(T) << "\t"
                          << byte_size/sizeof(T) << "\t"
                          << result << "\t"
                          << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      for (size_t i = 0; i < 2; ++i){
        std::cerr << i << " ARRAY_ADDER_TREE. " << std::flush;
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const T> in(measurement_data);
            host_ptr<uint64_t> out(result);
            *out = aggregate_autovec_N<T, BS, HORIZONTAL_AGGREGATION_STRATEGY::ARRAY_ADDER_TREE>(in, byte_size/sizeof(T));
          });
        }).wait();
        auto end = current_time();
        aggregate_results << COMPILER << "\t"
                          << VERSION << "\t"
                          << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
                          << i << "\t"
                          << "aggregate" << "\t" 
                          << "autovec - horizontal array adder tree" << "\t"
                          << BS << "\t"
                          << byte_size << "\t"
                          << sizeof(T) << "\t"
                          << byte_size/sizeof(T) << "\t"
                          << result << "\t"
                          << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      for (size_t i = 0; i < 2; ++i){
        std::cerr << i << " TUPL_ADDER_TREE. " << std::flush;
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const T> in(measurement_data);
            host_ptr<uint64_t> out(result);
            *out = aggregate_autovec_N<T, BS, HORIZONTAL_AGGREGATION_STRATEGY::TUPL_ADDER_TREE>(in, byte_size/sizeof(T));
          });
        }).wait();
        auto end = current_time();
        aggregate_results << COMPILER << "\t"
                          << VERSION << "\t"
                          << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
                          << i << "\t"
                          << "aggregate" << "\t" 
                          << "autovec - horizontal tuple adder tree" << "\t"
                          << BS << "\t"
                          << byte_size << "\t"
                          << sizeof(T) << "\t"
                          << byte_size/sizeof(T) << "\t"
                          << result << "\t"
                          << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      std::cerr << std::endl;
    }

  template<typename T>
    void run_aggregate(
      sycl::queue* q,
      T const * __restrict__ measurement_data,
      size_t byte_size
    ) {
      using namespace sycl;
      std::cerr << "\t\tScalar" << std::flush; 
      // SCALAR_AGG.HPP
      for (size_t i = 0; i < 2; ++i){
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const T> in(measurement_data);
            host_ptr<uint64_t> out(result);
            *out = aggregate<T>(in, byte_size/sizeof(T));
          });
        }).wait();
        auto end = current_time();
        aggregate_results << "FPGA" << "\t"
                          << COMPILER << "\t"
                          << VERSION << "\t"
                          << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
                          << i << "\t"
                          << "aggregate" << "\t" 
                          << "scalar" << "\t"
                          << "1" << "\t"
                          << byte_size << "\t"
                          << sizeof(T) << "\t"
                          << byte_size/sizeof(T) << "\t"
                          << result << "\t"
                          << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      std::cerr << std::endl;
#ifdef ELC2
      run_aggregate_autovec<T,  2>(q, measurement_data,  byte_size);
#endif
#ifdef ELC4
      run_aggregate_autovec<T,  4>(q, measurement_data,  byte_size);
#endif
#ifdef ELC8
      run_aggregate_autovec<T,  8>(q, measurement_data,  byte_size);
#endif
#ifdef ELC16
      run_aggregate_autovec<T, 16>(q, measurement_data, byte_size);
#endif
#ifdef ELC32
      run_aggregate_autovec<T, 32>(q, measurement_data, byte_size);
#endif
#ifdef ELC64
      run_aggregate_autovec<T, 64>(q, measurement_data, byte_size);
#endif
#ifdef ELC128
      run_aggregate_autovec<T, 128>(q, measurement_data, byte_size);
#endif
#ifdef ELC256
      run_aggregate_autovec<T, 256>(q, measurement_data, byte_size);
#endif
      std::cerr << std::endl;
    }

  template<typename T, int BS>
    void run_masked_aggregate_autovec(
      sycl::queue* q,
      T const * __restrict__ measurement_data, void * __restrict__ measurement_bitmap, 
      size_t byte_size, size_t selectivity
    ) {
      using namespace sycl;
      std::cerr << "\t\t\tAutovec (Vec size: " << BS << ")" << std::flush; 
      for (size_t i = 0; i < 2; ++i){
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const T> in(measurement_data);
            host_ptr<void> bm(measurement_bitmap);
            host_ptr<uint64_t> out(result);
            *out = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY, HORIZONTAL_AGGREGATION_STRATEGY::ACCUM>(in, byte_size/sizeof(T), bm);
          });
        }).wait();
        auto end = current_time();
        masked_aggregate_results << "FPGA" << "\t"
                                  << COMPILER << "\t"
                          << VERSION << "\t"
                          << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
                          << i << "\t"
                          << "masked aggregate" << "\t" 
                          << "autovec - ternary add, horizontal accum" << "\t"
                          << BS << "\t"
                          << byte_size << "\t"
                          << sizeof(T) << "\t"
                          << byte_size/sizeof(T) << "\t"
                          << (float)selectivity/100.0f << "\t"
                          << result << "\t"
                          << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      // for (size_t i = 0; i < 2; ++i){
      //   auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
      //   auto start = current_time();
      //   q->submit([&](handler& h) {
      //     h.single_task([=]() [[intel::kernel_args_restrict]] {
      //       host_ptr<const T> in(measurement_data);
      //       host_ptr<void> bm(measurement_bitmap);
      //       host_ptr<uint64_t> out(result);
      //       *out = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE, HORIZONTAL_AGGREGATION_STRATEGY::ACCUM>(in, byte_size/sizeof(T), bm);
      //     });
      //   }).wait();
      //   auto end = current_time();
      //   masked_aggregate_results << "FPGA" << "\t"
      //                             << COMPILER << "\t"
      //                     << VERSION << "\t"
      //                     << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
      //                     << i << "\t"
      //                     << "masked aggregate" << "\t" 
      //                     << "autovec - bitmask add, horizontal accum" << "\t"
      //                     << BS << "\t"
      //                     << byte_size << "\t"
      //                     << sizeof(T) << "\t"
      //                     << byte_size/sizeof(T) << "\t"
      //                     << (float)selectivity/100.0f << "\t"
      //                     << result << "\t"
      //                     << time_diff(start, end) << std::endl;
      //   remove_buffer(q, result);
      // }
      for (size_t i = 0; i < 2; ++i){
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const T> in(measurement_data);
            host_ptr<void> bm(measurement_bitmap);
            host_ptr<uint64_t> out(result);
            *out = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY, HORIZONTAL_AGGREGATION_STRATEGY::ARRAY_ADDER_TREE>(in, byte_size/sizeof(T), bm);
          });
        }).wait();
        auto end = current_time();
        masked_aggregate_results << "FPGA" << "\t"
                                  << COMPILER << "\t"
                          << VERSION << "\t"
                          << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
                          << i << "\t"
                          << "masked aggregate" << "\t" 
                          << "autovec - ternary add, horizontal array adder tree" << "\t"
                          << BS << "\t"
                          << byte_size << "\t"
                          << sizeof(T) << "\t"
                          << byte_size/sizeof(T) << "\t"
                          << (float)selectivity/100.0f << "\t"
                          << result << "\t"

                          << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      // for (size_t i = 0; i < 2; ++i){
      //   auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
      //   auto start = current_time();
      //   q->submit([&](handler& h) {
      //     h.single_task([=]() [[intel::kernel_args_restrict]] {
      //       host_ptr<const T> in(measurement_data);
      //       host_ptr<void> bm(measurement_bitmap);
      //       host_ptr<uint64_t> out(result);
      //       *out = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE, HORIZONTAL_AGGREGATION_STRATEGY::ARRAY_ADDER_TREE>(in, byte_size/sizeof(T), bm);
      //     });
      //   }).wait();
      //   auto end = current_time();
      //   masked_aggregate_results << "FPGA" << "\t"
      //                             << COMPILER << "\t"
      //                     << VERSION << "\t"
      //                     << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
      //                     << i << "\t"
      //                     << "masked aggregate" << "\t" 
      //                     << "autovec - bitmask add, horizontal array adder tree" << "\t"
      //                     << BS << "\t"
      //                     << byte_size << "\t"
      //                     << sizeof(T) << "\t"
      //                     << byte_size/sizeof(T) << "\t"
      //                     << (float)selectivity/100.0f << "\t"
      //                     << result << "\t"
      //                     << time_diff(start, end) << std::endl;
      //   remove_buffer(q, result);
      // }
      for (size_t i = 0; i < 2; ++i){
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const T> in(measurement_data);
            host_ptr<void> bm(measurement_bitmap);
            host_ptr<uint64_t> out(result);
            *out = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY, HORIZONTAL_AGGREGATION_STRATEGY::TUPL_ADDER_TREE>(in, byte_size/sizeof(T), bm);
          });
        }).wait();
        auto end = current_time();
        masked_aggregate_results << "FPGA" << "\t"
                                  << COMPILER << "\t"
                          << VERSION << "\t"
                          << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
                          << i << "\t"
                          << "masked aggregate" << "\t" 
                          << "autovec - ternary add, horizontal tuple adder tree" << "\t"
                          << BS << "\t"
                          << byte_size << "\t"
                          << sizeof(T) << "\t"
                          << byte_size/sizeof(T) << "\t"
                          << (float)selectivity/100.0f << "\t"
                          << result << "\t"
                          << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      // for (size_t i = 0; i < 2; ++i){
      //   auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
      //   auto start = current_time();
      //   q->submit([&](handler& h) {
      //     h.single_task([=]() [[intel::kernel_args_restrict]] {
      //       host_ptr<const T> in(measurement_data);
      //       host_ptr<void> bm(measurement_bitmap);
      //       host_ptr<uint64_t> out(result);
      //       *out = aggregate_autovec_N<T, BS, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE, HORIZONTAL_AGGREGATION_STRATEGY::TUPL_ADDER_TREE>(in, byte_size/sizeof(T), bm);
      //     });
      //   }).wait();
      //   auto end = current_time();
      //   masked_aggregate_results << "FPGA" << "\t"
      //                             << COMPILER << "\t"
      //                     << VERSION << "\t"
      //                     << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
      //                     << i << "\t"
      //                     << "masked aggregate" << "\t" 
      //                     << "autovec - bitmask add, horizontal tuple adder tree" << "\t"
      //                     << BS << "\t"
      //                     << byte_size << "\t"
      //                     << sizeof(T) << "\t"
      //                     << byte_size/sizeof(T) << "\t"
      //                     << (float)selectivity/100.0f << "\t"
      //                     << result << "\t"
      //                     << time_diff(start, end) << std::endl;
      //   remove_buffer(q, result);
      // }
      std::cerr << std::endl;
    }

  template<typename T>
    void run_masked_aggregate(
      sycl::queue* q,
      T const * __restrict__ measurement_data, void * __restrict__ measurement_bitmap, 
      size_t byte_size, size_t selectivity
    ) {
      using namespace sycl;
      tuddbs::read_bytes_from_file(
        measurement_bitmap, 
        tuddbs::get_bitmask_size<T>(byte_size), 
        tuddbs::get_bitmask_filename_from_size_and_selectivity<T>(byte_size, selectivity, false)
      );

      std::cerr << "\t\t\tScalar: " << std::flush;
      // SCALAR_AGG.HPP
      for (size_t i = 0; i < 2; ++i){
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const T> in(measurement_data);
            host_ptr<void> bm(measurement_bitmap);
            host_ptr<uint64_t> out(result);
            *out = aggregate<T, SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY>(in, byte_size/sizeof(T), bm);
          });
        }).wait();
        auto end = current_time();
        masked_aggregate_results  << "FPGA" << "\t"
                                  << COMPILER << "\t"
                                  << VERSION << "\t"
                                  << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
                                  << i << "\t"
                                  << "masked aggregate" << "\t" 
                                  << "scalar - ternary add" << "\t"
                                  << "1" << "\t"
                                  << byte_size << "\t"
                                  << sizeof(T) << "\t"
                                  << byte_size/sizeof(T) << "\t"
                                  << (float)selectivity/100.0f << "\t"
                                  << result << "\t"
                                  << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      // for (size_t i = 0; i < 2; ++i){
      //   auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
      //   auto start = current_time();
      //   q->submit([&](handler& h) {
      //     h.single_task([=]() [[intel::kernel_args_restrict]] {
      //       host_ptr<const T> in(measurement_data);
      //       host_ptr<void> bm(measurement_bitmap);
      //       host_ptr<uint64_t> out(result);
      //       *out = aggregate<T, SCALAR_MASKED_AGGREGATE_STRATEGY::BITWISE>(in, byte_size/sizeof(T), bm);
      //     });
      //   }).wait();
      //   auto end = current_time();
      //   masked_aggregate_results  << "FPGA" << "\t"
      //                             << COMPILER << "\t"
      //                             << VERSION << "\t"
      //                             << "FPGA" << ((i == 0) ? " - warmup" : "") << "\t"
      //                             << i << "\t"
      //                             << "masked aggregate" << "\t" 
      //                             << "scalar - bitmask add" << "\t"
      //                             << "1" << "\t"
      //                             << byte_size << "\t"
      //                             << sizeof(T) << "\t"
      //                             << byte_size/sizeof(T) << "\t"
      //                             << (float)selectivity/100.0f << "\t"
      //                             << result << "\t"
      //                             << time_diff(start, end) << std::endl;
      //   remove_buffer(q, result);
      // }
      std::cerr << std::endl;
#ifdef ELC2
      run_masked_aggregate_autovec<T,  2>(q, measurement_data, measurement_bitmap, byte_size, selectivity);
#endif
#ifdef ELC4
      run_masked_aggregate_autovec<T,  4>(q, measurement_data, measurement_bitmap, byte_size, selectivity);
#endif
#ifdef ELC8
      run_masked_aggregate_autovec<T,  8>(q, measurement_data, measurement_bitmap, byte_size, selectivity);
#endif
#ifdef ELC16
      run_masked_aggregate_autovec<T, 16>(q, measurement_data, measurement_bitmap, byte_size, selectivity);
#endif
#ifdef ELC32
      run_masked_aggregate_autovec<T, 32>(q, measurement_data, measurement_bitmap, byte_size, selectivity);
#endif
#ifdef ELC64
      run_masked_aggregate_autovec<T, 64>(q, measurement_data, measurement_bitmap, byte_size, selectivity);
#endif
#ifdef ELC128
      run_masked_aggregate_autovec<T, 128>(q, measurement_data, measurement_bitmap, byte_size, selectivity);
#endif
#ifdef ELC256
      run_masked_aggregate_autovec<T, 256>(q, measurement_data, measurement_bitmap, byte_size, selectivity);
#endif
    }


  template<typename T>
    void run_dtype(
      sycl::queue* q,
      void * __restrict__ measurement_data,
      size_t byte_size
    ) {
      auto measurement_bitmap = reinterpret_cast<void*>(create_buffer<uint8_t>(q, MALLOC_TARGET::HOST, tuddbs::get_bitmask_size<T>(byte_size), ALIGNMENT));
      
      tuddbs::read_bytes_from_file(
        measurement_data, 
        byte_size, 
        tuddbs::get_data_filename_from_size<T>(byte_size, false)
      );      

      std::cerr << "\tRunning aggregate. " << std::endl;
      run_aggregate<T>(q, reinterpret_cast<T const *>(measurement_data), byte_size);
      std::cerr << "\tRunning masked aggregate. " << std::endl;
      for (auto i : selectivities) {
        std::cerr << "\t\tSelectivity: " << (float)i/100.0f << std::endl;
        run_masked_aggregate<T>(q, reinterpret_cast<T const *>(measurement_data), measurement_bitmap, byte_size, i);
      }

      remove_buffer(q, measurement_bitmap);
    }

  void run(sycl::queue* q, size_t byte_size) {

    auto measurement_data = reinterpret_cast<void*>(create_buffer<uint8_t>(q, MALLOC_TARGET::HOST, byte_size, ALIGNMENT));
    
#ifdef UI8    
    std::cerr << "Running uint8_t. " << std::endl;
    run_dtype< uint8_t>(q, measurement_data, byte_size);
#endif
#ifdef UI16
    std::cerr << "Running uint16_t. " << std::endl;
    run_dtype<uint16_t>(q, measurement_data, byte_size);
#endif
#ifdef UI32
    std::cerr << "Running uint32_t. " << std::endl;
    run_dtype<uint32_t>(q, measurement_data, byte_size);
#endif
#ifdef UI64
    std::cerr << "Running uint64_t. " << std::endl;
    run_dtype<uint64_t>(q, measurement_data, byte_size);
#endif
    remove_buffer(q, measurement_data);
    
  }

}

int main(void) {

  if (!tuddbs::fileExists("masked_aggregate_results.tsv")) {
    masked_aggregate_results.open("masked_aggregate_results.tsv", std::ofstream::out | std::ofstream::app);
    masked_aggregate_results  << "device" << "\t"
                              << "compiler" << "\t"
                              << "version" << "\t"
                              << "arch-flags" << "\t"
                              << "rep" << "\t"
                              << "function" << "\t" 
                              << "variant" << "\t"
                              << "SIMD-elementCount" << "\t"
                              << "byte_size" << "\t"
                              << "element_size" << "\t"
                              << "element_count" << "\t"
                              << "selectivity" << "\t"
                              << "result" << "\t"
                              << "time_ns" << std::endl;
  } else {
    masked_aggregate_results.open("masked_aggregate_results.tsv", std::ofstream::out | std::ofstream::app);
  }
  if (!tuddbs::fileExists("aggregate_results.tsv")) {
    aggregate_results.open("aggregate_results.tsv", std::ofstream::out | std::ofstream::app);
    aggregate_results << "device" << "\t"
                    << "compiler" << "\t"
                    << "version" << "\t"
                    << "arch-flags" << "\t"
                    << "rep" << "\t"
                    << "function" << "\t" 
                    << "variant" << "\t"
                    << "SIMD-elementCount" << "\t"
                    << "byte_size" << "\t"
                    << "element_size" << "\t"
                    << "element_count" << "\t"
                    << "result" << "\t"
                    << "time_ns" << std::endl;
  } else {
    aggregate_results.open("aggregate_results.tsv", std::ofstream::out | std::ofstream::app);
  }

  using namespace sycl;
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
    sycl::ext::intel::fpga_emulator_selector selector;
    std::cout << "Using FPGA Emulator" << std::endl;
  #else
    sycl::ext::intel::fpga_selector selector;
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

  for (auto const size : tuddbs::data_sizes) {
    tuddbs::run(&q, size);
  }
  
  masked_aggregate_results.close();
  aggregate_results.close();
  return 0;
}

