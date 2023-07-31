#ifndef TEST_CIDR_AGG_AUTVEC_AGG_HPP
#define TEST_CIDR_AGG_AUTVEC_AGG_HPP
#include <cstdint>
#include <cstddef>
#include <climits>
#include <array>
#include <tuple>
#include <type_traits>
#include <iostream>
#include "agg_helper.hpp"
#if defined(FPGA_EMULATOR) || defined(FPGA_HARDWARE)
// T NAME[N] = {0}
#define TUDDBS_CREATE_ARRAY(T, N, NAME) [[intel::fpga_register]] std::array<T, N> NAME{}
#define TUDDBS_LOOP_CARRYING_DEP_ATTR(N, NAME) [[intel::loop_coalesce(N), intel::ivdep(NAME)]]
#else
#define TUDDBS_CREATE_ARRAY(T, N, NAME) std::array<T, N> NAME{}
#define TUDDBS_LOOP_CARRYING_DEP_ATTR(N, NAME)
#endif
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

  template<typename T, int BS, HORIZONTAL_AGGREGATION_STRATEGY HorizontalAggregateStrat>
    uint64_t aggregate_autovec_N(T const * data, size_t element_count) {
      // assumption: element_count % BS == 0
      TUDDBS_CREATE_ARRAY(uint64_t, BS, intermediate_results);
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += BS) {
        #pragma unroll
        for (size_t j = 0; j < BS; ++j) {
          intermediate_results[j] += data[j];
        }
      }
      if constexpr(HorizontalAggregateStrat == HORIZONTAL_AGGREGATION_STRATEGY::ACCUM) {
        uint64_t result = 0;
        // std::cerr << "INTERMEDIATE[0] = " << intermediate_results[0] << "\n";
        // std::cerr << "INTERMEDIATE[1] = " << intermediate_results[1] << "\n";
        for (size_t i = 0; i < BS; ++i ) {
          result += intermediate_results[i];
        }
        // std::cerr << "RESULT: " << result << "\n";
        return result;
      } else if constexpr(HorizontalAggregateStrat == HORIZONTAL_AGGREGATION_STRATEGY::ARRAY_ADDER_TREE) {
        TUDDBS_CREATE_ARRAY(uint64_t, BS, adder_results);
        #pragma unroll
        for (size_t i = 0; i < (BS>>1); ++i) {
          adder_results[i] = intermediate_results[i<<1] + intermediate_results[(i<<1)+1];
        }
        unsigned current_result_position = BS>>1;
        int previous_stage_start_idx = 0;
        #pragma unroll 
        TUDDBS_LOOP_CARRYING_DEP_ATTR(BS, adder_results)
        for(size_t current_upper_idx = (BS>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
          for(size_t i = 0; i < current_upper_idx; ++i) {
            adder_results[current_result_position + i] = 
              adder_results[previous_stage_start_idx + (i<<1)] + adder_results[previous_stage_start_idx + (i<<1)+1];
          }
          current_result_position += current_upper_idx;
          previous_stage_start_idx += current_upper_idx<<1;
        }
        return adder_results[BS-2];
      } else {
        return reducer::apply<uint64_t, BS, reducer::add_fn<uint64_t>>(intermediate_results);
      }
    }
  template<typename T, size_t BS, SCALAR_MASKED_AGGREGATE_STRATEGY AggregateStrat, HORIZONTAL_AGGREGATION_STRATEGY HorizontalAggregateStrat>
    uint64_t aggregate_autovec_N(T const * __restrict__ data, size_t element_count, void const * __restrict__ bitmap) {
      uint64_t result = 0;
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);
      TUDDBS_CREATE_ARRAY(uint64_t, BS, intermediate_results);
      auto const data_ptr_end = data + element_count;
      if constexpr (CHAR_BIT > BS) {
        uint8_t shift;
        for (; data != data_ptr_end; data += CHAR_BIT, ++bm) {
          auto const bitmap_value = *bm;
          shift = 0;
          #pragma unroll
          for (size_t m = 0; m < CHAR_BIT / BS; ++m) {
            #pragma unroll
            for (size_t d = 0; d < BS; ++d, ++shift) {
              auto bmv = (bitmap_value >> shift)&0x1;
              // if constexpr(AggregateStrat == SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY) {
                intermediate_results[d] += (bmv == 0) ? 0 : data[shift];
              // } else {
                // intermediate_results[d] += static_cast<T>(~((bmv)-1)) & data[shift];
              // }
            }
          }
        }
      } else if constexpr (CHAR_BIT == BS) {
        for (; data != data_ptr_end; data += BS, ++bm) {
          auto const bitmap_value = *bm;
          #pragma unroll
          for (size_t i = 0; i < BS; ++i) {
            auto bmv = (bitmap_value >> i)&0x1;
            // if constexpr(AggregateStrat == SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY) {
              intermediate_results[i] += (bmv == 0) ? 0 : data[i];
            // } else {
              // intermediate_results[i] += static_cast<T>(~((bmv)-1)) & data[i];
            // }
          }
        }
      } else {
        for (; data != data_ptr_end; data += BS) {
          size_t data_offset = 0;
          #pragma unroll
          for (size_t m = 0; m < BS / CHAR_BIT; ++m) {
            auto const bitmap_value = *bm;
            #pragma unroll
            for (size_t i = 0; i < CHAR_BIT; ++i) {
              auto bmv = (bitmap_value >> i)&0x1;
              // if constexpr(AggregateStrat == SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY) {
                intermediate_results[i] += (bmv == 0) ? 0 : data[data_offset];
              // } else {
                // intermediate_results[i] += static_cast<T>(~((bmv)-1)) & data[data_offset];
              // }
              ++data_offset;
            }
            ++bm;
          }
        }
      }
      if constexpr(HorizontalAggregateStrat == HORIZONTAL_AGGREGATION_STRATEGY::ACCUM) {
        #pragma unroll
        for (size_t i = 0; i < BS; ++i ) {
          result += intermediate_results[i];
        }
        return result;
      } else if constexpr(HorizontalAggregateStrat == HORIZONTAL_AGGREGATION_STRATEGY::ARRAY_ADDER_TREE) {
        TUDDBS_CREATE_ARRAY(uint64_t, BS, adder_results);
        #pragma unroll
        for (size_t i = 0; i < (BS>>1); ++i) {
          adder_results[i] = intermediate_results[i<<1] + intermediate_results[(i<<1)+1];
        }
        unsigned current_result_position = BS>>1;
        int previous_stage_start_idx = 0;
        #pragma unroll 
        TUDDBS_LOOP_CARRYING_DEP_ATTR(BS, adder_results)
        for(size_t current_upper_idx = (BS>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
          for(size_t i = 0; i < current_upper_idx; ++i) {
            adder_results[current_result_position + i] = 
              adder_results[previous_stage_start_idx + (i<<1)] + adder_results[previous_stage_start_idx + (i<<1)+1];
          }
          current_result_position += current_upper_idx;
          previous_stage_start_idx += current_upper_idx<<1;
        }
        return adder_results[BS-2];
      } else {
        return reducer::apply<uint64_t, BS, reducer::add_fn<uint64_t>>(intermediate_results);
      }
    }
}

#endif //TEST_CIDR_AGG_AUTVEC_AGG_HPP