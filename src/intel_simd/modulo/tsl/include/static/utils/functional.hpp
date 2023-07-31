/*==========================================================================*
 * This file is part of the TSL - a template SIMD library.                  *
 *                                                                          *
 * Copyright 2023 TSL-Team, Database Research Group TU Dresden              *
 *                                                                          *
 * Licensed under the Apache License, Version 2.0 (the "License");          *
 * you may not use this file except in compliance with the License.         *
 * You may obtain a copy of the License at                                  *
 *                                                                          *
 *     http://www.apache.org/licenses/LICENSE-2.0                           *
 *                                                                          *
 * Unless required by applicable law or agreed to in writing, software      *
 * distributed under the License is distributed on an "AS IS" BASIS,        *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 * See the License for the specific language governing permissions and      *
 * limitations under the License.                                           *
 *==========================================================================*/
/*
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/static/utils/functional.hpp
 * \date 2023-07-22
 * \brief Helper functions.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_STATIC_UTILS_FUNCTIONAL_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_STATIC_UTILS_FUNCTIONAL_HPP

#include <cstddef>
#include <type_traits>
#include <typeinfo>
#include <cxxabi.h>
#include <memory>
#include <string>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <tuple>
#include <climits>
#include <tuple>

namespace tsl {

    #if ((__cplusplus >= 202002L) && (__has_include(<bit>)))
    #include <bit>
    namespace details {
      template<typename T, typename RetT>
        constexpr RetT clz(T data) {
          return std::countl_zero<std::make_unsigned_t<T>>(data);
        }
    }
    #else
    namespace details {
      template <typename T, typename RetT>
        RetT clz(T data) {
          static_assert(sizeof(T) <= sizeof(unsigned long long), "Unsupported type");
          if constexpr(std::is_unsigned_v<T>) {
            if constexpr(sizeof(T) <= sizeof(unsigned int)) {
              return data == 0 ? std::numeric_limits<T>::digits : __builtin_clz(data) - (sizeof(unsigned int) * CHAR_BIT - sizeof(T) * CHAR_BIT);
            } else if constexpr(sizeof(T) <= sizeof(unsigned long)) {
              return data == 0 ? std::numeric_limits<T>::digits : __builtin_clzl(data) - (sizeof(unsigned long) * CHAR_BIT - sizeof(T) * CHAR_BIT);
            } else if constexpr(sizeof(T) <= sizeof(unsigned long long)) {
              return data == 0 ? std::numeric_limits<T>::digits : __builtin_clzll(data) - (sizeof(unsigned long long) * CHAR_BIT - sizeof(T) * CHAR_BIT);
            }
          } else {
            using UT = std::make_unsigned_t<T>;
            if constexpr(sizeof(UT) <= sizeof(unsigned int)) {
              return data == 0 ? std::numeric_limits<UT>::digits : __builtin_clz(static_cast<UT>(data)) - (sizeof(unsigned int) * CHAR_BIT - sizeof(T) * CHAR_BIT);
            } else if constexpr(sizeof(T) <= sizeof(unsigned long)) {
              return data == 0 ? std::numeric_limits<UT>::digits : __builtin_clzl(static_cast<UT>(data)) - (sizeof(unsigned long) * CHAR_BIT - sizeof(T) * CHAR_BIT);
            } else if constexpr(sizeof(T) <= sizeof(unsigned long long)) {
              return data == 0 ? std::numeric_limits<UT>::digits : __builtin_clzll(static_cast<UT>(data)) - (sizeof(unsigned long long) * CHAR_BIT - sizeof(T) * CHAR_BIT);
            }
          }
        }
    }
    #endif

    namespace details {
      template<typename T, typename RetT>
        struct clz_recursive;
      template<typename RetT>
        struct clz_recursive<uint8_t, RetT> {
          __attribute__((always_inline)) inline static auto apply(uint8_t x) -> RetT {
            static constexpr uint8_t clz_lookup[16] = {4, 3, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
            auto upper = x >> 4;
            auto lower = x & 0x0F;
            return upper ? clz_lookup[upper] : 4 + clz_lookup[lower];
          }
        };
      template<typename RetT>
        struct clz_recursive<uint16_t, RetT> {
          __attribute__((always_inline)) inline static auto apply(uint16_t x) -> RetT {
            auto upper = uint8_t(x >> 8);
            auto lower = uint8_t(x & 0xFF);
            return upper ? clz_recursive<uint8_t, RetT>::apply(upper) : 8 + clz_recursive<uint8_t, RetT>::apply(lower);
          }
        };
      template<typename RetT>
        struct clz_recursive<uint32_t, RetT> {
          __attribute__((always_inline)) inline static auto apply(uint32_t x) -> RetT  {
            auto upper = uint16_t(x >> 16);
            auto lower = uint16_t(x & 0xFFFF);
            return upper ? clz_recursive<uint16_t, RetT>::apply(upper) : 16 + clz_recursive<uint16_t, RetT>::apply(lower);
          }
        };
      template<typename RetT>
        struct clz_recursive<uint64_t, RetT> {
          __attribute__((always_inline)) inline static auto apply(uint64_t x) -> RetT  {
            auto upper = uint32_t(x >> 32);
            auto lower = uint32_t(x & 0xFFFFFFFF);
            return upper ? clz_recursive<uint32_t, RetT>::apply(upper) : 32 + clz_recursive<uint32_t, RetT>::apply(lower);
          }
        };
    }

    namespace reducer {
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
    }

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_STATIC_UTILS_FUNCTIONAL_HPP