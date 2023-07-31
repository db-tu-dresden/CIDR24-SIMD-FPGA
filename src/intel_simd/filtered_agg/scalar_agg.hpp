#ifndef TEST_CIDR_AGG_SCALAR_AGG_HPP
#define TEST_CIDR_AGG_SCALAR_AGG_HPP
#include <cstdint>
#include <cstddef>
#include <climits>
#include "agg_helper.hpp"

namespace tuddbs {
  template<typename T>
    uint64_t aggregate(T const * data, size_t element_count) {
      uint64_t result = 0;
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; ++data) {
        result += *data;
      }
      return result;
    }

  template<typename T, SCALAR_MASKED_AGGREGATE_STRATEGY AggregateStrat>
    uint64_t aggregate(T const * __restrict__ data, size_t element_count, void const * __restrict__ bitmap) {
      uint64_t result = 0;
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += CHAR_BIT, ++bm) {
        auto const bitmap_value = *bm;
        #pragma unroll
        for (size_t i = 0; i < CHAR_BIT; ++i) {
          auto bmv = (bitmap_value >> i)&0x1;
          if constexpr(AggregateStrat == SCALAR_MASKED_AGGREGATE_STRATEGY::TERNARY) {
            result += (bmv == 0) ? 0 : data[i];
          } else {
            result += static_cast<T>(~((bmv)-1)) & data[i];
          }
        }
      }
      return result;
    }
}

#endif //TEST_CIDR_AGG_SCALAR_AGG_HPP