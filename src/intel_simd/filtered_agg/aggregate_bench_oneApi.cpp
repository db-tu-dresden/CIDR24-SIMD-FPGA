#include "agg_helper.hpp"
#include "scalar_agg.hpp"
#include "autovec_agg.hpp"
#include "../include/data.hpp"
#include "../include/datagen.hpp"
#include "../include/utils.hpp"
#include <data.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <CL/sycl.hpp>
#include <sycl/ext/intel/fpga_extensions.hpp>
#include "dbsbenchmark.hpp"

#define ALIGNMENT 0

namespace tuddbs {
  template<typename T>
    void run_aggregate(
      sycl::queue* q,
      T const * __restrict__ measurement_data,
      size_t byte_size,
      tuddbs::csv_filewriter_t & writer
    ) {
      using namespace sycl;
      auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
      auto start_offload = default_clock_t::now();
      q->submit([&](handler& h) {
        h.single_task([=]() [[intel::kernel_args_restrict]] {
          host_ptr<const T> in(measurement_data);
          host_ptr<uint64_t> out(result);
          *out = aggregate<T>(in, byte_size/sizeof(T));
        });
      }).wait();
      auto end_offload = default_clock_t::now();
      auto offload_result = std::to_string(result[0]);
      auto start_exec = default_clock_t::now();
      q->submit([&](handler& h) {
        h.single_task([=]() [[intel::kernel_args_restrict]] {
          host_ptr<const T> in(measurement_data);
          host_ptr<uint64_t> out(result);
          *out = aggregate<T>(in, byte_size/sizeof(T));
        });
      }).wait();
      auto end_exec = default_clock_t::now();
      writer.write_line(
          PLATFORM, COMPILER, VERSION,
          "fpga",
          "aggregate",
          "plain",
          tsl::type_name<T>(), std::to_string((sizeof(T)*CHAR_BIT)), 
          byte_size/sizeof(T),
          byte_size,
          default_clock_t::duration(start_offload, end_offload), default_clock_t::duration(start_exec, end_exec),
          default_tput_t::throughput(start_exec, end_exec, byte_size),
          offload_result,std::to_string(result[0])
        );
        remove_buffer(q, result);
    }
  template<typename T>
  void run(sycl::queue* q, tuddbs::csv_filewriter_t & writer, size_t byte_size) {
    auto measurement_data = create_buffer<T>(q, MALLOC_TARGET::HOST, byte_size, ALIGNMENT);
    generate_values<T>(measurement_data, byte_size/sizeof(T), tuddbs::generator);
    run_aggregate<T>(q, reinterpret_cast<T const *>(measurement_data), byte_size, writer);
    remove_buffer(q, measurement_data);
    
  }

}

int main(int argc, char** argv) {

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
  tuddbs::csv_filewriter_t writer("benchmark_results_aggregate", "\t");
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
  tuddbs::run<uint8_t>(&q, writer, data_size);
#endif
#ifdef UI16
  tuddbs::run<uint16_t>(&q, writer, data_size);
#endif
#ifdef UI32
  tuddbs::run<uint32_t>(&q, writer, data_size);
#endif
#ifdef UI64
  tuddbs::run<uint64_t>(&q, writer, data_size);
#endif
  return 0;
}

