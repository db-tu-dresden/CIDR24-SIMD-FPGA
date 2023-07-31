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

#ifndef CIDR24_EXEC_H
#define CIDR24_EXEC_H

#include <sycl.h>
#include <tslintrin.hpp>

namespace tuddbs {
    // template<template<typename>typename Functor, typename FpgaSimdT, typename ResultT>
    // void run_specific_benchmark(
    //     sycl::queue* q, uint64_t * in, uint64_t * out, std::size_t element_count
    // ) {
    //     using BaseT = typename FpgaSimdT::base_type;
    //     auto bench_data_input = reinterpret_cast<BaseT *>(in);
    //     auto bench_data_output = reinterpret_cast<ResultT *>(out);
    //     double const input_size_mib = static_cast<double>(element_count * sizeof(BaseT)) / (1024 * 1024);
    //     volatile double offloading_and_exec_time;
    //     volatile double execution_time;
    //     try {
    //         offloading_and_exec_time = Functor<FpgaSimdT>(q, bench_data_output, bench_data_input, element_count);
    //         execution_time = Functor<FpgaSimdT>(q, bench_data_output, bench_data_input, element_count);
    //     } catch (sycl::exception const &e) {
    //         std::cerr << "Caught a synchronous SYCL exception: " << e.what() << "\n";
    //         std::terminate();
    //     }
    //     std::cout << tsl::type_name<BaseT>()
    //               << "\t" << FpgaSimdT::vector_size_b()
    //               << "\t" << input_size_mib
    //               << "\t" << element_count
    //               << "\t" << execution_time
    //               << "\t" << "us"
    //               << "\t" << (input_size_mib / (execution_time * 1e-6))
    //               << "\t" << "MiB/s"
    //               << "\t" << offloading_and_exec_time
    //               << "\t" << "us"
    //               << std::endl;
    // }
}
#endif //CIDR24_EXEC_H
