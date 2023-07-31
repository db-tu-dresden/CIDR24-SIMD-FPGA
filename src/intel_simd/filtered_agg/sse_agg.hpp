#ifndef TEST_CIDR_AGG_SSE_AGG_HPP
#define TEST_CIDR_AGG_SSE_AGG_HPP
#include <cstdint>
#include <cstddef>
#include <array>
#include "immintrin.h"
namespace tuddbs {
  template<typename T>
    uint64_t aggregate_SSE(T const * data, size_t element_count);

  template<>  
    uint64_t aggregate_SSE<uint8_t>(uint8_t const * data, size_t element_count) {
      auto intermediate_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 16) {
        auto data_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        intermediate_result = _mm_add_epi8(intermediate_result, data_reg);
      }
      alignas(16) std::array<uint8_t, 16> intermediate_result_array{};
      _mm_store_si128(reinterpret_cast<__m128i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 16; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }
  template<>  
    uint64_t aggregate_SSE<uint16_t>(uint16_t const * data, size_t element_count) {
      auto intermediate_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8) {
        auto data_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        intermediate_result = _mm_add_epi16(intermediate_result, data_reg);
      }
      alignas(16) std::array<uint16_t, 8> intermediate_result_array{};
      _mm_store_si128(reinterpret_cast<__m128i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 8; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }
  template<>  
    uint64_t aggregate_SSE<uint32_t>(uint32_t const * data, size_t element_count) {
      auto intermediate_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 4) {
        auto data_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        intermediate_result = _mm_add_epi32(intermediate_result, data_reg);
      }
      auto res = _mm_hadd_epi32(intermediate_result, intermediate_result);
      return _mm_cvtsi128_si32(res) + _mm_cvtsi128_si32(_mm_bsrli_si128(res,sizeof(uint32_t)));
    }
  template<>
    uint64_t aggregate_SSE<uint64_t>(uint64_t const * data, size_t element_count) {
      auto intermediate_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 4) {
        auto data_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        intermediate_result = _mm_add_epi64(intermediate_result, data_reg);
      }
      return _mm_cvtsi128_si64(intermediate_result) + _mm_cvtsi128_si64(_mm_bsrli_si128(intermediate_result,sizeof(uint64_t)));
    }


  template<typename T>
    uint64_t aggregate_SSE(T const * data, size_t element_count, void const * __restrict__ bitmap);

#ifndef AVX512VL
  template<>
    uint64_t aggregate_SSE<uint8_t>(uint8_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint16_t const *>(bitmap);
      auto const mask_valid_reg = _mm_set_epi8(0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1,0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1);
      auto const mask_combine_reg = _mm_set_epi8(0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00);

      auto intermediate_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 16, ++bm) {
        auto data_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        auto const mask = *bm;
        auto const mask_reg = 
          _mm_cmpeq_epi8(
            mask_valid_reg,
              _mm_and_si128(
              _mm_or_si128(
                _mm_set1_epi8(uint8_t(mask&0xFF)), 
                _mm_and_si128(
                  _mm_set1_epi8(uint8_t(mask>>8)),
                  mask_combine_reg)), 
              mask_valid_reg)
          );
        intermediate_result = _mm_add_epi8(intermediate_result, _mm_and_si128(data_reg, mask_reg));
      }
      alignas(16) std::array<uint8_t, 16> intermediate_result_array{};
      _mm_store_si128(reinterpret_cast<__m128i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 16; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_SSE<uint16_t>(uint16_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);
      auto const mask_valid_reg = _mm_set_epi16(0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1);

      auto intermediate_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8, ++bm) {
        auto data_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        auto const mask = *bm;
        auto const mask_reg = _mm_cmpeq_epi16(mask_valid_reg, _mm_and_si128(_mm_set1_epi16(mask), mask_valid_reg));
        intermediate_result = _mm_add_epi16(intermediate_result, _mm_and_si128(data_reg, mask_reg));
      }
      alignas(16) std::array<uint16_t, 8> intermediate_result_array{};
      _mm_store_si128(reinterpret_cast<__m128i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 8; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_SSE<uint32_t>(uint32_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);
      auto const mask_valid_reg = _mm_set_epi32(0x8,0x4,0x2,0x1);

      auto intermediate_1_result = _mm_setzero_si128();
      auto intermediate_2_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8, ++bm) {

        
        auto const mask = *bm;
        auto const mask1 = mask&0xF;
        auto const mask2 = (mask>>4)&0xF;
        auto mask_1_reg = _mm_cmpeq_epi32(mask_valid_reg, _mm_and_si128(_mm_set1_epi32(mask1), mask_valid_reg));
        auto mask_2_reg = _mm_cmpeq_epi32(mask_valid_reg, _mm_and_si128(_mm_set1_epi32(mask2), mask_valid_reg));

        auto data_1_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        auto data_2_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data+4));
        
        intermediate_1_result = _mm_add_epi32(intermediate_1_result, _mm_and_si128(data_1_reg, mask_1_reg));        
        intermediate_2_result = _mm_add_epi32(intermediate_2_result, _mm_and_si128(data_2_reg, mask_2_reg));
      }
      auto const intermediate_result = _mm_add_epi32(intermediate_1_result, intermediate_2_result);
      alignas(16) std::array<uint32_t, 4> intermediate_result_array{};
      _mm_store_si128(reinterpret_cast<__m128i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 4; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_SSE<uint64_t>(uint64_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);
      auto const mask_valid_reg = _mm_set_epi64x(0x2,0x1);

      auto intermediate_1_result = _mm_setzero_si128();
      auto intermediate_2_result = _mm_setzero_si128();
      auto intermediate_3_result = _mm_setzero_si128();
      auto intermediate_4_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8, ++bm) {
        auto const mask = *bm;
        auto const mask1 = mask&0x3;
        auto const mask2 = (mask>>2)&0x3;
        auto const mask3 = (mask>>4)&0x3;
        auto const mask4 = (mask>>6)&0x3;
        auto mask_1_reg = _mm_cmpeq_epi64(mask_valid_reg, _mm_and_si128(_mm_set1_epi64x(mask1), mask_valid_reg));
        auto mask_2_reg = _mm_cmpeq_epi64(mask_valid_reg, _mm_and_si128(_mm_set1_epi64x(mask2), mask_valid_reg));
        auto mask_3_reg = _mm_cmpeq_epi64(mask_valid_reg, _mm_and_si128(_mm_set1_epi64x(mask3), mask_valid_reg));
        auto mask_4_reg = _mm_cmpeq_epi64(mask_valid_reg, _mm_and_si128(_mm_set1_epi64x(mask4), mask_valid_reg));

        auto data_1_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        auto data_2_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data+2));
        auto data_3_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data+4));
        auto data_4_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data+6));

        
        intermediate_1_result = _mm_add_epi64(intermediate_1_result, _mm_and_si128(data_1_reg, mask_1_reg));
        intermediate_2_result = _mm_add_epi64(intermediate_2_result, _mm_and_si128(data_2_reg, mask_2_reg));
        intermediate_3_result = _mm_add_epi64(intermediate_3_result, _mm_and_si128(data_3_reg, mask_3_reg));
        intermediate_4_result = _mm_add_epi64(intermediate_4_result, _mm_and_si128(data_4_reg, mask_4_reg));
      }
      auto const intermediate_5_result = _mm_add_epi64(intermediate_1_result, intermediate_2_result);
      auto const intermediate_6_result = _mm_add_epi64(intermediate_3_result, intermediate_4_result);
      auto const intermediate_result = _mm_add_epi64(intermediate_5_result, intermediate_6_result);
      alignas(16) std::array<uint64_t, 2> intermediate_result_array{};
      _mm_store_si128(reinterpret_cast<__m128i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 2; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }
#else //AVX512VL defined
  template<>
    uint64_t aggregate_SSE<uint8_t>(uint8_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint16_t const *>(bitmap);

      auto intermediate_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 16, ++bm) {
        auto data_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        auto const mask = *bm;
        intermediate_result = _mm_mask_add_epi8(intermediate_result, mask, intermediate_result, data_reg);
      }
      alignas(16) std::array<uint8_t, 16> intermediate_result_array{};
      _mm_store_si128(reinterpret_cast<__m128i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 16; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_SSE<uint16_t>(uint16_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);

      auto intermediate_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8, ++bm) {
        auto data_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        auto const mask = *bm;
        intermediate_result = _mm_mask_add_epi16(intermediate_result, mask, intermediate_result, data_reg);
      }
      alignas(16) std::array<uint16_t, 8> intermediate_result_array{};
      _mm_store_si128(reinterpret_cast<__m128i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 8; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_SSE<uint32_t>(uint32_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);

      auto intermediate_1_result = _mm_setzero_si128();
      auto intermediate_2_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8, ++bm) {
        auto const mask = *bm;
        auto const mask1 = mask&0xF;
        auto const mask2 = (mask>>4)&0xF;
        auto data_1_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        auto data_2_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data+4));
        intermediate_1_result = _mm_mask_add_epi32(intermediate_1_result, mask1, intermediate_1_result, data_1_reg);
        intermediate_2_result = _mm_mask_add_epi32(intermediate_2_result, mask2, intermediate_2_result, data_2_reg);
      }
      auto const intermediate_result = _mm_add_epi32(intermediate_1_result, intermediate_2_result);
      alignas(16) std::array<uint32_t, 4> intermediate_result_array{};
      _mm_store_si128(reinterpret_cast<__m128i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 4; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_SSE<uint64_t>(uint64_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);

      auto intermediate_1_result = _mm_setzero_si128();
      auto intermediate_2_result = _mm_setzero_si128();
      auto intermediate_3_result = _mm_setzero_si128();
      auto intermediate_4_result = _mm_setzero_si128();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8, ++bm) {
        auto const mask = *bm;
        auto const mask1 = mask&0x3;
        auto const mask2 = (mask>>2)&0x3;
        auto const mask3 = (mask>>4)&0x3;
        auto const mask4 = (mask>>6)&0x3;
        auto data_1_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data));
        auto data_2_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data+2));
        auto data_3_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data+4));
        auto data_4_reg = _mm_loadu_si128(reinterpret_cast<__m128i const *>(data+6));
        intermediate_1_result = _mm_mask_add_epi64(intermediate_1_result, mask1, intermediate_1_result, data_1_reg);
        intermediate_2_result = _mm_mask_add_epi64(intermediate_2_result, mask2, intermediate_2_result, data_2_reg);
        intermediate_3_result = _mm_mask_add_epi64(intermediate_3_result, mask3, intermediate_3_result, data_3_reg);
        intermediate_4_result = _mm_mask_add_epi64(intermediate_4_result, mask4, intermediate_4_result, data_4_reg);
      }
      auto const intermediate_5_result = _mm_add_epi64(intermediate_1_result, intermediate_2_result);
      auto const intermediate_6_result = _mm_add_epi64(intermediate_3_result, intermediate_4_result);
      auto const intermediate_result = _mm_add_epi64(intermediate_5_result, intermediate_6_result);
      alignas(16) std::array<uint64_t, 2> intermediate_result_array{};
      _mm_store_si128(reinterpret_cast<__m128i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 2; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }
#endif
  
}

#endif //TEST_CIDR_AGG_SSE_AGG_HPP