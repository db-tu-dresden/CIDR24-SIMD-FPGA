#include "agg_helper.hpp"
#include "../include/data.hpp"
#include "../include/utils.hpp"
#include <data.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <CL/sycl.hpp>
#include <array>
#include <cstdint>
#include <cstddef>
#include <sycl/ext/intel/fpga_extensions.hpp>


#define ALIGNMENT 0

std::ofstream aggregate_results;
std::ofstream masked_aggregate_results;

namespace tuddbs {
  namespace reducer {
    template<typename /*LEFT_TUPLE*/, typename /*RIGHT_TUPLE*/>
      struct join_tuples {};
    template<typename... LEFT, typename... RIGHT>
      struct join_tuples<std::tuple<LEFT...>, std::tuple<RIGHT...>> {
        using type = std::tuple<LEFT..., RIGHT...>;
      };
    template<typename T, unsigned N>
      struct generate_tuple_type {
        using left  = typename generate_tuple_type<T, N/2>::type;
        using right = typename generate_tuple_type<T, N/2 + N%2>::type;
        using type  = typename join_tuples<left, right>::type;
      };

    template<typename T>
      struct generate_tuple_type<T, 1> {
        using type = std::tuple<T>;
      };

    template<typename T>
      struct generate_tuple_type<T, 0> {
        using type = std::tuple<>;
      };
    template<int N, int CurrentStage>
      constexpr int getReadPos() {
        if constexpr(CurrentStage == 0) {
          return 0;
        } else {
          return getReadPos<N, CurrentStage-1>() + (N>>CurrentStage);
        }
      }
    template<size_t N, size_t Stage=0>
      constexpr size_t StageCount() {
        if constexpr( (N>>(Stage+1)) == 1) {
          return Stage;
        } else {
          return StageCount<N, Stage+1>();
        }
      }
    template<typename T, size_t N>
      using type = typename generate_tuple_type<T, N-1>::type;
    template<typename T, size_t N, typename Combiner, size_t WritePos, size_t ReadLeftPos, size_t ReadRightPos>
      __attribute__((always_inline)) inline static void apply_reduce(type<T,N>& result) {
        std::get<WritePos>(result) = Combiner::apply(std::get<ReadLeftPos>(result), std::get<ReadRightPos>(result));
      }
    template<typename T, size_t N, typename Combiner, size_t Stage, size_t... Idx>
      __attribute__((always_inline)) inline static void do_reduce_inner_loop(type<T, N>& result, std::index_sequence<Idx...>) {
        (
          (apply_reduce<
            T, N, Combiner,
            getReadPos<N, Stage>() + Idx, 
            getReadPos<N, Stage-1>() + 2*Idx, 
            getReadPos<N, Stage-1>() + 2*Idx+1
          >(result)
          ), ...
        );
      }
    template<typename T, size_t N, typename Combiner, size_t... Stage>
      __attribute__((always_inline)) inline static void do_reduce(type<T, N> & result, std::index_sequence<Stage...>) {
        (
          (
            do_reduce_inner_loop<T, N, Combiner, Stage+1>(result, std::make_index_sequence<(N>>(Stage+2))>{})
          ), ...
      );    
    }
    template<typename T, size_t N, typename Combiner, size_t... Idx>
      __attribute__((always_inline)) inline static void do_reduce_init(std::array<T, N> const & data, type<T, N> & result, std::index_sequence<Idx...>) {
        ((std::get<Idx>(result) = Combiner::apply(data[2*Idx], data[2*Idx+1])),...);
      }
    template<typename T, size_t N, typename Combiner>
      __attribute__((always_inline)) inline static T apply(const std::array<T, N>& data) {
        type<T, N> result{};
        do_reduce_init<T, N, Combiner>(data, result, std::make_index_sequence<(N>>1)>{});
        if constexpr (StageCount<N>() > 0) {
          do_reduce<T, N, Combiner>(result, std::make_index_sequence<StageCount<N>()>{});
        }
        return std::get<N-2>(result);
      }
  
    template<typename T>
    struct add_fn {
      __attribute__((always_inline)) inline static T apply(T a, T b) {
        return a + b;
      }
    };
  }
    void run_aggregate_autovec(
      sycl::queue* q,
      uint32_t const * __restrict__ measurement_data, 
      size_t byte_size
    ) {
      using namespace sycl;
      // AUTOVEC_AGG.HPP
      std::cerr << "\t\tAutovec (Vec size: " << 512 << ")" << std::flush;
      for (size_t rep = 0; rep < 2; ++rep){
        std::cerr << rep << " ACCUM. " << std::flush;
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const uint32_t> in(measurement_data);
            host_ptr<uint64_t> out(result);
            [[intel::fpga_register]] std::array<uint64_t, 16> intermediate_results{};
            auto const element_count = byte_size/sizeof(uint32_t);
            auto const in_end = in + element_count;
            for (; in != in_end; in += 16) {
              #pragma unroll
              for (size_t j = 0; j < 16; ++j) {
                intermediate_results[j] += in[j];
              }
            }
            uint64_t scalar_result = 0;
            for (size_t i = 0; i < 16; ++i) {
              scalar_result += intermediate_results[i];
            }
            *out = scalar_result;
          });
        }).wait();
        auto end = current_time();
        aggregate_results << COMPILER << "\t"
                          << VERSION << "\t"
                          << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
                          << rep << "\t"
                          << "aggregate" << "\t" 
                          << "autovec - horizontal accum" << "\t"
                          << 512 << "\t"
                          << byte_size << "\t"
                          << sizeof(uint32_t) << "\t"
                          << byte_size/sizeof(uint32_t) << "\t"
                          << result << "\t"
                          << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      for (size_t rep = 0; rep < 2; ++rep){
        std::cerr << rep << " ARRAY_ADDER_TREE. " << std::flush;
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const uint32_t> in(measurement_data);
            host_ptr<uint64_t> out(result);
            [[intel::fpga_register]] std::array<uint64_t, 16> intermediate_results{};
            auto const element_count = byte_size/sizeof(uint32_t);
            auto const in_end = in + element_count;
            for (; in != in_end; in += 16) {
              #pragma unroll
              for (size_t j = 0; j < 16; ++j) {
                intermediate_results[j] += in[j];
              }
            }
            [[intel::fpga_register]] uint64_t adder_results[16] = {0};
            #pragma unroll
            for (size_t i = 0; i < (16>>1); ++i) {
              adder_results[i] = intermediate_results[i<<1] + intermediate_results[(i<<1)+1];
            }
            unsigned current_result_position = 16>>1;
            int previous_stage_start_idx = 0;
            #pragma unroll 
            [[intel::loop_coalesce(16), intel::ivdep(adder_results)]]
            for(size_t current_upper_idx = (16>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
              for(size_t i = 0; i < current_upper_idx; ++i) {
                adder_results[current_result_position + i] = 
                  adder_results[previous_stage_start_idx + (i<<1)] + adder_results[previous_stage_start_idx + (i<<1)+1];
              }
              current_result_position += current_upper_idx;
              previous_stage_start_idx += current_upper_idx<<1;
            }
            *out = adder_results[16-2];
          });
        }).wait();
        auto end = current_time();
        aggregate_results << COMPILER << "\t"
                          << VERSION << "\t"
                          << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
                          << rep << "\t"
                          << "aggregate" << "\t" 
                          << "autovec - horizontal array adder tree" << "\t"
                          << 512 << "\t"
                          << byte_size << "\t"
                          << sizeof(uint32_t) << "\t"
                          << byte_size/sizeof(uint32_t) << "\t"
                          << result << "\t"
                          << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      for (size_t rep = 0; rep < 2; ++rep){
        std::cerr << rep << " TUPL_ADDER_TREE. " << std::flush;
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const uint32_t> in(measurement_data);
            host_ptr<uint64_t> out(result);
            [[intel::fpga_register]] std::array<uint64_t, 16> intermediate_results{};
            auto const element_count = byte_size/sizeof(uint32_t);
            auto const in_end = in + element_count;
            for (; in != in_end; in += 16) {
              #pragma unroll
              for (size_t j = 0; j < 16; ++j) {
                intermediate_results[j] += in[j];
              }
            }
            *out = reducer::apply<uint64_t, 16, reducer::add_fn<uint64_t>>(intermediate_results);
          });
        }).wait();
        auto end = current_time();
        aggregate_results << COMPILER << "\t"
                          << VERSION << "\t"
                          << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
                          << rep << "\t"
                          << "aggregate" << "\t" 
                          << "autovec - horizontal tuple adder tree" << "\t"
                          << 512 << "\t"
                          << byte_size << "\t"
                          << sizeof(uint32_t) << "\t"
                          << byte_size/sizeof(uint32_t) << "\t"
                          << result << "\t"
                          << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      std::cerr << std::endl;
    }


    void run_aggregate(
      sycl::queue* q,
      uint32_t const * __restrict__ measurement_data,
      size_t byte_size
    ) {
      using namespace sycl;
      std::cerr << "\t\tScalar" << std::flush; 
      // SCALAR_AGG.HPP
      for (size_t rep = 0; rep < 2; ++rep){
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const uint32_t> in(measurement_data);
            host_ptr<uint64_t> out(result);            
            auto const element_count = byte_size/sizeof(uint32_t);
            auto const in_end = in + element_count;
            uint64_t scalar_result = 0;
            for (; in != in_end; ++in) {
              scalar_result += *in;
            }
            *out = scalar_result;
          });
        }).wait();
        auto end = current_time();
        aggregate_results << "FPGA" << "\t"
                          << COMPILER << "\t"
                          << VERSION << "\t"
                          << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
                          << rep << "\t"
                          << "aggregate" << "\t" 
                          << "scalar" << "\t"
                          << "1" << "\t"
                          << byte_size << "\t"
                          << sizeof(uint32_t) << "\t"
                          << byte_size/sizeof(uint32_t) << "\t"
                          << result << "\t"
                          << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      std::cerr << std::endl;
      run_aggregate_autovec(q, measurement_data, byte_size);
      std::cerr << std::endl;
    }

    void run_masked_aggregate_autovec(
      sycl::queue* q,
      uint32_t const * __restrict__ measurement_data, void * __restrict__ measurement_bitmap, 
      size_t byte_size, size_t selectivity
    ) {
      using namespace sycl;
      std::cerr << "\t\t\tAutovec (Vec size: " << 512 << ")" << std::flush; 
      for (size_t rep = 0; rep < 2; ++rep){
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const uint32_t> in(measurement_data);
            host_ptr<uint16_t> bm_ui16(reinterpret_cast<uint16_t*>(measurement_bitmap));
            host_ptr<uint64_t> out(result);
            [[intel::fpga_register]] std::array<uint64_t, 16> intermediate_results{};
            auto const element_count = byte_size/sizeof(uint32_t);
            auto const in_end = in + element_count;
            
            for (; in != in_end; in += 16, ++bm_ui16) {
              auto const bm_val = *bm_ui16;
              #pragma unroll
              for (size_t j = 0; j < 16; ++j) {
                intermediate_results[j] += (((bm_val >> j)&0x1) == 0) ? 0 : in[j];
              }
            }
            uint64_t scalar_result = 0;
            for (size_t i = 0; i < 16; ++i) {
              scalar_result += intermediate_results[i];
            }
            *out = scalar_result;
          });
        }).wait();
        auto end = current_time();
        masked_aggregate_results  << "FPGA" << "\t"
                                  << COMPILER << "\t"
                                  << VERSION << "\t"
                                  << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
                                  << rep << "\t"
                                  << "masked aggregate" << "\t" 
                                  << "autovec - ternary add, horizontal accum" << "\t"
                                  << 512 << "\t"
                                  << byte_size << "\t"
                                  << sizeof(uint32_t) << "\t"
                                  << byte_size/sizeof(uint32_t) << "\t"
                                  << (float)selectivity/100.0f << "\t"
                                  << result << "\t"
                                  << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      // for (size_t rep = 0; rep < 2; ++rep){
      //   auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
      //   auto start = current_time();
      //   q->submit([&](handler& h) {
      //     h.single_task([=]() [[intel::kernel_args_restrict]] {
      //       host_ptr<const uint32_t> in(measurement_data);
      //       host_ptr<uint16_t> bm_ui16(reinterpret_cast<uint16_t*>(measurement_bitmap));
      //       host_ptr<uint64_t> out(result);
      //       [[intel::fpga_register]] std::array<uint64_t, 16> intermediate_results{};
      //       auto const element_count = byte_size/sizeof(uint32_t);
      //       auto const in_end = in + element_count;
            
      //       for (; in != in_end; in += 16, ++bm_ui16) {
      //         auto const bm_val = *bm_ui16;
      //         #pragma unroll
      //         for (size_t j = 0; j < 16; ++j) {
      //           intermediate_results[j] += static_cast<uint32_t>(~(((bm_val >> j)&0x1)-1)) & in[j];
      //         }
      //       }
      //       uint64_t scalar_result = 0;
      //       for (size_t i = 0; i < 16; ++i) {
      //         scalar_result += intermediate_results[i];
      //       }
      //       *out = scalar_result;
      //     });
      //   }).wait();
      //   auto end = current_time();
      //   masked_aggregate_results  << "FPGA" << "\t"
      //                             << COMPILER << "\t"
      //                             << VERSION << "\t"
      //                             << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
      //                             << rep << "\t"
      //                             << "masked aggregate" << "\t" 
      //                             << "autovec - bitmask add, horizontal accum" << "\t"
      //                             << 512 << "\t"
      //                             << byte_size << "\t"
      //                             << sizeof(uint32_t) << "\t"
      //                             << byte_size/sizeof(uint32_t) << "\t"
      //                             << (float)selectivity/100.0f << "\t"
      //                             << result << "\t"
      //                             << time_diff(start, end) << std::endl;
      //   remove_buffer(q, result);
      // }
      for (size_t rep = 0; rep < 2; ++rep){
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const uint32_t> in(measurement_data);
            host_ptr<uint16_t> bm_ui16(reinterpret_cast<uint16_t*>(measurement_bitmap));
            host_ptr<uint64_t> out(result);
            [[intel::fpga_register]] std::array<uint64_t, 16> intermediate_results{};
            auto const element_count = byte_size/sizeof(uint32_t);
            auto const in_end = in + element_count;
            
            for (; in != in_end; in += 16, ++bm_ui16) {
              auto const bm_val = *bm_ui16;
              #pragma unroll
              for (size_t j = 0; j < 16; ++j) {
                intermediate_results[j] += (((bm_val >> j)&0x1) == 0) ? 0 : in[j];
              }
            }
            [[intel::fpga_register]] uint64_t adder_results[16] = {0};
            #pragma unroll
            for (size_t i = 0; i < (16>>1); ++i) {
              adder_results[i] = intermediate_results[i<<1] + intermediate_results[(i<<1)+1];
            }
            unsigned current_result_position = 16>>1;
            int previous_stage_start_idx = 0;
            #pragma unroll 
            [[intel::loop_coalesce(16), intel::ivdep(adder_results)]]
            for(size_t current_upper_idx = (16>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
              for(size_t i = 0; i < current_upper_idx; ++i) {
                adder_results[current_result_position + i] = 
                  adder_results[previous_stage_start_idx + (i<<1)] + adder_results[previous_stage_start_idx + (i<<1)+1];
              }
              current_result_position += current_upper_idx;
              previous_stage_start_idx += current_upper_idx<<1;
            }
            *out = adder_results[16-2];
          });
        }).wait();
        auto end = current_time();
        masked_aggregate_results  << "FPGA" << "\t"
                                  << COMPILER << "\t"
                                  << VERSION << "\t"
                                  << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
                                  << rep << "\t"
                                  << "masked aggregate" << "\t" 
                                  << "autovec - ternary add, horizontal array adder tree" << "\t"
                                  << 512 << "\t"
                                  << byte_size << "\t"
                                  << sizeof(uint32_t) << "\t"
                                  << byte_size/sizeof(uint32_t) << "\t"
                                  << (float)selectivity/100.0f << "\t"
                                  << result << "\t"
                                  << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      // for (size_t rep = 0; rep < 2; ++rep){
      //   auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
      //   auto start = current_time();
      //   q->submit([&](handler& h) {
      //     h.single_task([=]() [[intel::kernel_args_restrict]] {
      //       host_ptr<const uint32_t> in(measurement_data);
      //       host_ptr<uint16_t> bm_ui16(reinterpret_cast<uint16_t*>(measurement_bitmap));
      //       host_ptr<uint64_t> out(result);
      //       [[intel::fpga_register]] std::array<uint64_t, 16> intermediate_results{};
      //       auto const element_count = byte_size/sizeof(uint32_t);
      //       auto const in_end = in + element_count;
            
      //       for (; in != in_end; in += 16, ++bm_ui16) {
      //         auto const bm_val = *bm_ui16;
      //         #pragma unroll
      //         for (size_t j = 0; j < 16; ++j) {
      //           intermediate_results[j] += static_cast<uint32_t>(~(((bm_val >> j)&0x1)-1)) & in[j];
      //         }
      //       }
      //       [[intel::fpga_register]] uint64_t adder_results[16] = {0};
      //       #pragma unroll
      //       for (size_t i = 0; i < (16>>1); ++i) {
      //         adder_results[i] = intermediate_results[i<<1] + intermediate_results[(i<<1)+1];
      //       }
      //       unsigned current_result_position = 16>>1;
      //       int previous_stage_start_idx = 0;
      //       #pragma unroll 
      //       [[intel::loop_coalesce(16), intel::ivdep(adder_results)]]
      //       for(size_t current_upper_idx = (16>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
      //         for(size_t i = 0; i < current_upper_idx; ++i) {
      //           adder_results[current_result_position + i] = 
      //             adder_results[previous_stage_start_idx + (i<<1)] + adder_results[previous_stage_start_idx + (i<<1)+1];
      //         }
      //         current_result_position += current_upper_idx;
      //         previous_stage_start_idx += current_upper_idx<<1;
      //       }
      //       *out = adder_results[16-2];
      //     });
      //   }).wait();
      //   auto end = current_time();
      //   masked_aggregate_results  << "FPGA" << "\t"
      //                             << COMPILER << "\t"
      //                             << VERSION << "\t"
      //                             << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
      //                             << rep << "\t"
      //                             << "masked aggregate" << "\t" 
      //                             << "autovec - bitmask add, horizontal array adder tree" << "\t"
      //                             << 512 << "\t"
      //                             << byte_size << "\t"
      //                             << sizeof(uint32_t) << "\t"
      //                             << byte_size/sizeof(uint32_t) << "\t"
      //                             << (float)selectivity/100.0f << "\t"
      //                             << result << "\t"
      //                             << time_diff(start, end) << std::endl;
      //   remove_buffer(q, result);
      // }
      for (size_t rep = 0; rep < 2; ++rep){
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const uint32_t> in(measurement_data);
            host_ptr<uint16_t> bm_ui16(reinterpret_cast<uint16_t*>(measurement_bitmap));
            host_ptr<uint64_t> out(result);
            [[intel::fpga_register]] std::array<uint64_t, 16> intermediate_results{};
            auto const element_count = byte_size/sizeof(uint32_t);
            auto const in_end = in + element_count;
            
            for (; in != in_end; in += 16, ++bm_ui16) {
              auto const bm_val = *bm_ui16;
              #pragma unroll
              for (size_t j = 0; j < 16; ++j) {
                intermediate_results[j] += (((bm_val >> j)&0x1) == 0) ? 0 : in[j];
              }
            }
            *out = reducer::apply<uint64_t, 16, reducer::add_fn<uint64_t>>(intermediate_results);
          });
        }).wait();
        auto end = current_time();
        masked_aggregate_results  << "FPGA" << "\t"
                                  << COMPILER << "\t"
                                  << VERSION << "\t"
                                  << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
                                  << rep << "\t"
                                  << "masked aggregate" << "\t" 
                                  << "autovec - ternary add, horizontal tuple adder tree" << "\t"
                                  << 512 << "\t"
                                  << byte_size << "\t"
                                  << sizeof(uint32_t) << "\t"
                                  << byte_size/sizeof(uint32_t) << "\t"
                                  << (float)selectivity/100.0f << "\t"
                                  << result << "\t"
                                  << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      // for (size_t rep = 0; rep < 2; ++rep){
      //   auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
      //   auto start = current_time();
      //   q->submit([&](handler& h) {
      //     h.single_task([=]() [[intel::kernel_args_restrict]] {
      //       host_ptr<const uint32_t> in(measurement_data);
      //       host_ptr<uint16_t> bm_ui16(reinterpret_cast<uint16_t*>(measurement_bitmap));
      //       host_ptr<uint64_t> out(result);
      //       [[intel::fpga_register]] std::array<uint64_t, 16> intermediate_results{};
      //       auto const element_count = byte_size/sizeof(uint32_t);
      //       auto const in_end = in + element_count;
            
      //       for (; in != in_end; in += 16, ++bm_ui16) {
      //         auto const bm_val = *bm_ui16;
      //         #pragma unroll
      //         for (size_t j = 0; j < 16; ++j) {
      //           intermediate_results[j] += static_cast<uint32_t>(~(((bm_val >> j)&0x1)-1)) & in[j];
      //         }
      //       }
      //       *out = reducer::apply<uint64_t, 16, reducer::add_fn<uint64_t>>(intermediate_results);
      //     });
      //   }).wait();
      //   auto end = current_time();
      //   masked_aggregate_results  << "FPGA" << "\t"
      //                             << COMPILER << "\t"
      //                             << VERSION << "\t"
      //                             << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
      //                             << rep << "\t"
      //                             << "masked aggregate" << "\t" 
      //                             << "autovec - bitmask add, horizontal tuple adder tree" << "\t"
      //                             << 512 << "\t"
      //                             << byte_size << "\t"
      //                             << sizeof(uint32_t) << "\t"
      //                             << byte_size/sizeof(uint32_t) << "\t"
      //                             << (float)selectivity/100.0f << "\t"
      //                             << result << "\t"
      //                             << time_diff(start, end) << std::endl;
      //   remove_buffer(q, result);
      // }
      std::cerr << std::endl;
    }

    void run_masked_aggregate(
      sycl::queue* q,
      uint32_t const * __restrict__ measurement_data, void * __restrict__ measurement_bitmap, 
      size_t byte_size, size_t selectivity
    ) {
      using namespace sycl;
      tuddbs::read_bytes_from_file(
        measurement_bitmap, 
        tuddbs::get_bitmask_size<uint32_t>(byte_size), 
        tuddbs::get_bitmask_filename_from_size_and_selectivity<uint32_t>(byte_size, selectivity, false)
      );

      std::cerr << "\t\t\tScalar: " << std::flush;
      // SCALAR_AGG.HPP
      for (size_t rep = 0; rep < 2; ++rep){
        auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);        
        auto start = current_time();
        q->submit([&](handler& h) {
          h.single_task([=]() [[intel::kernel_args_restrict]] {
            host_ptr<const uint32_t> in(measurement_data);
            host_ptr<uint16_t> bm_ui16(reinterpret_cast<uint16_t*>(measurement_bitmap));
            host_ptr<uint64_t> out(result);
            auto const element_count = byte_size/sizeof(uint32_t);
            auto const in_end = in + element_count;
            
            uint64_t scalar_result = 0;
            for (; in != in_end; in += 16, ++bm_ui16) {
              auto const bm_val = *bm_ui16;
              #pragma unroll
              for (size_t j = 0; j < 16; ++j) {
                scalar_result += (((bm_val >> j)&0x1) == 0) ? 0 : in[j];
              }
            }
            *out = scalar_result;
          });
        }).wait();
        auto end = current_time();
        masked_aggregate_results  << "FPGA" << "\t"
                                  << COMPILER << "\t"
                                  << VERSION << "\t"
                                  << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
                                  << rep << "\t"
                                  << "masked aggregate" << "\t" 
                                  << "scalar - ternary add" << "\t"
                                  << "1" << "\t"
                                  << byte_size << "\t"
                                  << sizeof(uint32_t) << "\t"
                                  << byte_size/sizeof(uint32_t) << "\t"
                                  << (float)selectivity/100.0f << "\t"
                                  << result << "\t"
                                  << time_diff(start, end) << std::endl;
        remove_buffer(q, result);
      }
      // for (size_t rep = 0; rep < 2; ++rep){
      //   auto result =  create_buffer<uint64_t>(q, MALLOC_TARGET::HOST, sizeof(uint64_t), ALIGNMENT);
      //   auto start = current_time();
      //   q->submit([&](handler& h) {
      //     h.single_task([=]() [[intel::kernel_args_restrict]] {
      //       host_ptr<const uint32_t> in(measurement_data);
      //       host_ptr<uint16_t> bm_ui16(reinterpret_cast<uint16_t*>(measurement_bitmap));
      //       host_ptr<uint64_t> out(result);
      //       [[intel::fpga_register]] std::array<uint64_t, 16> intermediate_results{};
      //       auto const element_count = byte_size/sizeof(uint32_t);
      //       auto const in_end = in + element_count;
            
      //       uint64_t scalar_result = 0;
      //       for (; in != in_end; in += 16, ++bm_ui16) {
      //         auto const bm_val = *bm_ui16;
      //         #pragma unroll
      //         for (size_t j = 0; j < 16; ++j) {
      //           intermediate_results[j] += static_cast<uint32_t>(~(((bm_val >> j)&0x1)-1)) & in[j];
      //         }
      //       }
      //       *out = scalar_result;
      //     });
      //   }).wait();
      //   auto end = current_time();
      //   masked_aggregate_results  << "FPGA" << "\t"
      //                             << COMPILER << "\t"
      //                             << VERSION << "\t"
      //                             << "FPGA" << ((rep == 0) ? " - warmup" : "") << "\t"
      //                             << rep << "\t"
      //                             << "masked aggregate" << "\t" 
      //                             << "scalar - bitmask add" << "\t"
      //                             << "1" << "\t"
      //                             << byte_size << "\t"
      //                             << sizeof(uint32_t) << "\t"
      //                             << byte_size/sizeof(uint32_t) << "\t"
      //                             << (float)selectivity/100.0f << "\t"
      //                             << result << "\t"
      //                             << time_diff(start, end) << std::endl;
      //   remove_buffer(q, result);
      // }
      std::cerr << std::endl;
      run_masked_aggregate_autovec(q, measurement_data, measurement_bitmap, byte_size, selectivity);
    }


    void run_dtype(
      sycl::queue* q,
      void * __restrict__ measurement_data,
      size_t byte_size
    ) {
      auto measurement_bitmap = reinterpret_cast<void*>(create_buffer<uint8_t>(q, MALLOC_TARGET::HOST, tuddbs::get_bitmask_size<uint32_t>(byte_size), ALIGNMENT));
      
      tuddbs::read_bytes_from_file(
        measurement_data, 
        byte_size, 
        tuddbs::get_data_filename_from_size<uint32_t>(byte_size, false)
      );      

      std::cerr << "\tRunning aggregate. " << std::endl;
      run_aggregate(q, reinterpret_cast<uint32_t const *>(measurement_data), byte_size);
      std::cerr << "\tRunning masked aggregate. " << std::endl;
      for (auto i : selectivities) {
        std::cerr << "\t\tSelectivity: " << (float)i/100.0f << std::endl;
        run_masked_aggregate(q, reinterpret_cast<uint32_t const *>(measurement_data), measurement_bitmap, byte_size, i);
      }

      remove_buffer(q, measurement_bitmap);
    }

  void run(sycl::queue* q, size_t byte_size) {

    auto measurement_data = reinterpret_cast<void*>(create_buffer<uint8_t>(q, MALLOC_TARGET::HOST, byte_size, ALIGNMENT));
    
    std::cerr << "Running uint32_t. " << std::endl;
    run_dtype(q, measurement_data, byte_size);
    remove_buffer(q, measurement_data);
    
  }

}

int main(int argc, char** argv) {

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
      std::cerr << "[WARNING] No --size given. Defaulting to 4 GiB." << std::endl;
      data_size = 4ULL * 1024 * 1024 * 1024;
  } else {
      std::cerr << "[INFO] Using data size in Bytes: " << data_size << std::endl;
  }

  tuddbs::run(&q, data_size);
  
  masked_aggregate_results.close();
  aggregate_results.close();
  return 0;
}

