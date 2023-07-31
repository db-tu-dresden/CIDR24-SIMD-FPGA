#ifndef TEST_CIDR_AGG_AVX512_AGG_HPP
#define TEST_CIDR_AGG_AVX512_AGG_HPP
#include <cstdint>
#include <cstddef>
#include <array>
#include "immintrin.h"
namespace tuddbs {
  template<typename T>
    uint64_t aggregate_AVX512(T const * data, size_t element_count);

  template<>  
    uint64_t aggregate_AVX512<uint8_t>(uint8_t const * data, size_t element_count) {
      auto intermediate_result = _mm512_setzero_si512();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 64) {
        auto data_vec = _mm512_loadu_si512(reinterpret_cast<void const *>(data));
        intermediate_result = _mm512_add_epi64(intermediate_result, data_vec);
      }
      alignas(64) std::array<uint8_t, 64> intermediate_result_array{};
      _mm512_store_si512(reinterpret_cast<void *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 64; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }
  template<>  
    uint64_t aggregate_AVX512<uint16_t>(uint16_t const * data, size_t element_count) {
      auto intermediate_result = _mm512_setzero_si512();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 32) {
        auto data_vec = _mm512_loadu_si512(reinterpret_cast<void const *>(data));
        intermediate_result = _mm512_add_epi16(intermediate_result, data_vec);
      }
      alignas(64) std::array<uint16_t, 32> intermediate_result_array{};
      _mm512_store_si512(reinterpret_cast<void *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 32; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }
  template<>  
    uint64_t aggregate_AVX512<uint32_t>(uint32_t const * data, size_t element_count) {
      auto intermediate_result = _mm512_setzero_si512();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 16) {
        auto data_vec = _mm512_loadu_si512(reinterpret_cast<void const *>(data));
        intermediate_result = _mm512_add_epi32(intermediate_result, data_vec);
      }
      return _mm512_reduce_add_epi32(intermediate_result);
    }
  template<>
    uint64_t aggregate_AVX512<uint64_t>(uint64_t const * data, size_t element_count) {
      auto intermediate_result = _mm512_setzero_si512();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 4) {
        auto data_vec = _mm512_loadu_si512(reinterpret_cast<void const *>(data));
        intermediate_result = _mm512_add_epi64(intermediate_result, data_vec);
      }
      return _mm512_reduce_add_epi64(intermediate_result);
    }

  template<typename T>
    uint64_t aggregate_AVX512(T const * data, size_t element_count, void const * __restrict__ bitmap);
  template<>
    uint64_t aggregate_AVX512<uint8_t>(uint8_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint64_t const *>(bitmap);

      auto intermediate_result = _mm512_setzero_si512();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 64, ++bm) {
        auto data_reg = _mm512_loadu_si512(reinterpret_cast<void const *>(data));
        auto const mask = *bm;
        intermediate_result = _mm512_mask_add_epi8(intermediate_result, mask, intermediate_result, data_reg);
      }
      alignas(64) std::array<uint8_t, 64> intermediate_result_array{};
      _mm512_store_si512(reinterpret_cast<void *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 64; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_AVX512<uint16_t>(uint16_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint32_t const *>(bitmap);

      auto intermediate_result = _mm512_setzero_si512();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 32, ++bm) {
        auto data_reg = _mm512_loadu_si512(reinterpret_cast<void const *>(data));
        auto const mask = *bm;
        intermediate_result = _mm512_mask_add_epi16(intermediate_result, mask, intermediate_result, data_reg);
      }
      alignas(64) std::array<uint16_t, 32> intermediate_result_array{};
      _mm512_store_si512(reinterpret_cast<void *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 32; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_AVX512<uint32_t>(uint32_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint16_t const *>(bitmap);

      auto intermediate_result = _mm512_setzero_si512();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 16, ++bm) {
        auto const mask = *bm;
        auto data_reg = _mm512_loadu_si512(reinterpret_cast<void const *>(data));
        intermediate_result = _mm512_mask_add_epi32(intermediate_result, mask, intermediate_result, data_reg);        
      }
      alignas(64) std::array<uint32_t, 16> intermediate_result_array{};
      _mm512_store_si512(reinterpret_cast<__m512i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 16; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_AVX512<uint64_t>(uint64_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);

      auto intermediate_result = _mm512_setzero_si512();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8, ++bm) {
        auto const mask = *bm;
        auto data_reg = _mm512_loadu_si512(reinterpret_cast<void const *>(data));
        intermediate_result = _mm512_mask_add_epi64(intermediate_result, mask, intermediate_result, data_reg);        
      }
      alignas(64) std::array<uint32_t, 8> intermediate_result_array{};
      _mm512_store_si512(reinterpret_cast<__m512i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 8; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }
}

#endif //TEST_CIDR_AGG_AVX512_AGG_HPP