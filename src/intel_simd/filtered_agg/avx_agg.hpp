#ifndef TEST_CIDR_AGG_AVX_AGG_HPP
#define TEST_CIDR_AGG_AVX_AGG_HPP
#include <cstdint>
#include <cstddef>
#include <array>
#include <immintrin.h>
#include "immintrin.h"
namespace tuddbs {
  template<typename T>
    uint64_t aggregate_AVX(T const * data, size_t element_count);

  template<>  
    uint64_t aggregate_AVX<uint8_t>(uint8_t const * data, size_t element_count) {
      auto intermediate_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 32) {
        auto data_vec = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));
        intermediate_result = _mm256_add_epi8(intermediate_result, data_vec);
      }
      alignas(32) std::array<uint8_t, 32> intermediate_result_array{};
      _mm256_store_si256(reinterpret_cast<__m256i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 32; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }
  template<>  
    uint64_t aggregate_AVX<uint16_t>(uint16_t const * data, size_t element_count) {
      auto intermediate_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 16) {
        auto data_vec = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));
        intermediate_result = _mm256_add_epi16(intermediate_result, data_vec);
      }
      alignas(32) std::array<uint16_t, 16> intermediate_result_array{};
      _mm256_store_si256(reinterpret_cast<__m256i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 16; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }
  template<>  
    uint64_t aggregate_AVX<uint32_t>(uint32_t const * data, size_t element_count) {
      auto intermediate_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8) {
        auto data_vec = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));
        intermediate_result = _mm256_add_epi32(intermediate_result, data_vec);
      }
      __m128i vlow = _mm256_castsi256_si128(intermediate_result);
      __m128i vhigh = _mm256_extractf128_si256(intermediate_result, 1);
      vlow = _mm_add_epi32(vlow, vhigh);
      __m128i res = _mm_hadd_epi32(vlow, vlow);
      return _mm_cvtsi128_si32(res) + _mm_cvtsi128_si32(_mm_bsrli_si128(res,sizeof(uint32_t)));
    }
  template<>
    uint64_t aggregate_AVX<uint64_t>(uint64_t const * data, size_t element_count) {
      auto intermediate_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 4) {
        auto data_vec = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));
        intermediate_result = _mm256_add_epi64(intermediate_result, data_vec);
      }
      __m128i vlow = _mm256_castsi256_si128(intermediate_result);
      __m128i vhigh = _mm256_extractf128_si256(intermediate_result, 1);
      vlow = _mm_add_epi64(vlow, vhigh);
      __m128i high64 = _mm_unpackhi_epi64(vlow, vlow);
      return _mm_cvtsi128_si64(_mm_add_epi64(vlow, high64));
    }


  template<typename T>
    uint64_t aggregate_AVX(T const * data, size_t element_count, void const * __restrict__ bitmap);


#ifndef AVX512VL
  template<>
    uint64_t aggregate_AVX<uint8_t>(uint8_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint32_t const *>(bitmap);
      auto const mask_valid_reg = _mm256_set_epi8(0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1,0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1,0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1,0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1);
      auto const mask_combine_reg = _mm_set_epi8(0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00);

      auto intermediate_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 32, ++bm) {
        auto data_reg = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));

        auto const mask = *bm;
        auto const mask_lower_reg = 
          _mm256_zextsi128_si256(
              _mm_or_si128(
                _mm_set1_epi8(uint8_t(mask&0xFF)), 
                _mm_and_si128(
                  _mm_set1_epi8(uint8_t((mask>>8)&0xFF)),
                  mask_combine_reg)
              )
          );
        auto const mask_upper_reg = 
            _mm_or_si128(
              _mm_set1_epi8(uint8_t((mask>>16)&0xFF)), 
              _mm_and_si128(
                _mm_set1_epi8(uint8_t((mask>>24)&0xFF)),
                mask_combine_reg)
            );
        auto tmp_mask_reg = _mm256_inserti128_si256(mask_lower_reg, mask_upper_reg, 1);
        auto const mask_reg = _mm256_cmpeq_epi8(mask_valid_reg, _mm256_and_si256(mask_valid_reg, tmp_mask_reg));

        intermediate_result = _mm256_add_epi8(intermediate_result, _mm256_and_si256(data_reg, mask_reg));
      }
      alignas(32) std::array<uint8_t, 32> intermediate_result_array{};
      _mm256_store_si256(reinterpret_cast<__m256i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 32; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_AVX<uint16_t>(uint16_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint16_t const *>(bitmap);
      auto const mask_valid_reg = _mm256_set_epi16(0x8000, 0x4000, 0x2000, 0x1000, 0x800, 0x400, 0x200, 0x100, 0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1);

      auto intermediate_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 16, ++bm) {
        auto data_reg = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));
        auto const mask = *bm;
        auto const mask_reg = _mm256_cmpeq_epi16(mask_valid_reg, _mm256_and_si256(_mm256_set1_epi16(mask), mask_valid_reg));
        intermediate_result = _mm256_add_epi16(intermediate_result, mask_reg);
      }
      alignas(32) std::array<uint16_t, 16> intermediate_result_array{};
      _mm256_store_si256(reinterpret_cast<__m256i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 16; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_AVX<uint32_t>(uint32_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);
      auto const mask_valid_reg = _mm256_set_epi32(0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1);

      auto intermediate_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8, ++bm) {
        
        auto const mask = *bm;
        auto mask_reg = _mm256_cmpeq_epi32(mask_valid_reg, _mm256_and_si256(_mm256_set1_epi32(mask), mask_valid_reg));

        auto data_reg = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));
        
        intermediate_result = _mm256_add_epi32(intermediate_result, _mm256_and_si256(data_reg, mask_reg));        
      }
      alignas(32) std::array<uint32_t, 8> intermediate_result_array{};
      _mm256_store_si256(reinterpret_cast<__m256i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 8; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_AVX<uint64_t>(uint64_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);
      auto const mask_valid_reg = _mm256_set_epi64x(0x8,0x4,0x2,0x1);

      auto intermediate_1_result = _mm256_setzero_si256();
      auto intermediate_2_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 4, ++bm) {

        auto const mask = *bm;
        auto const mask1 = mask&0xF;
        auto const mask2 = (mask>>4)&0xF;
        auto mask_1_reg = _mm256_cmpeq_epi64(mask_valid_reg, _mm256_and_si256(_mm256_set1_epi64x(mask1), mask_valid_reg));
        auto mask_2_reg = _mm256_cmpeq_epi64(mask_valid_reg, _mm256_and_si256(_mm256_set1_epi64x(mask2), mask_valid_reg));

        auto data_1_reg = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));
        auto data_2_reg = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data+4));
        
        intermediate_1_result = _mm256_add_epi64(intermediate_1_result, _mm256_and_si256(data_1_reg, mask_1_reg));        
        intermediate_2_result = _mm256_add_epi64(intermediate_2_result, _mm256_and_si256(data_2_reg, mask_2_reg));
      }
      auto const intermediate_result = _mm256_add_epi64(intermediate_1_result, intermediate_2_result);
      alignas(32) std::array<uint64_t, 4> intermediate_result_array{};
      _mm256_store_si256(reinterpret_cast<__m256i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 4; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }
#else //AVX512VL defined
  template<>
    uint64_t aggregate_AVX<uint8_t>(uint8_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint32_t const *>(bitmap);

      auto intermediate_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 32, ++bm) {
        auto data_reg = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));
        auto const mask = *bm;
        intermediate_result = _mm256_mask_add_epi8(intermediate_result, mask, intermediate_result, data_reg);
      }
      alignas(32) std::array<uint8_t, 32> intermediate_result_array{};
      _mm256_store_si256(reinterpret_cast<__m256i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 32; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_AVX<uint16_t>(uint16_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint16_t const *>(bitmap);

      auto intermediate_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 16, ++bm) {
        auto data_reg = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));
        auto const mask = *bm;
        intermediate_result = _mm256_mask_add_epi16(intermediate_result, mask, intermediate_result, data_reg);
      }
      alignas(32) std::array<uint16_t, 16> intermediate_result_array{};
      _mm256_store_si256(reinterpret_cast<__m256i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 16; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_AVX<uint32_t>(uint32_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);

      auto intermediate_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8, ++bm) {
        auto const mask = *bm;
        auto data_reg = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));
        intermediate_result = _mm256_mask_add_epi32(intermediate_result, mask, intermediate_result, data_reg);        
      }
      alignas(32) std::array<uint32_t, 8> intermediate_result_array{};
      _mm256_store_si256(reinterpret_cast<__m256i *>(intermediate_result_array.data()), intermediate_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 8; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }

  template<>
    uint64_t aggregate_AVX<uint64_t>(uint64_t const * data, size_t element_count, void const * __restrict__ bitmap) {
      auto const * bm = reinterpret_cast<uint8_t const *>(bitmap);
      auto const mask_valid_reg = _mm_set_epi64x(0x2,0x1);

      auto intermediate_1_result = _mm256_setzero_si256();
      auto intermediate_2_result = _mm256_setzero_si256();
      auto const data_ptr_end = data + element_count;
      for (; data != data_ptr_end; data += 8, ++bm) {
        auto const mask = *bm;
        auto const mask1 = mask&0x15;
        auto const mask2 = (mask>>4)&0x15;
        auto data_1_reg = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data));
        auto data_2_reg = _mm256_loadu_si256(reinterpret_cast<__m256i const *>(data+4));
        intermediate_1_result = _mm256_mask_add_epi64(intermediate_1_result, mask1, intermediate_1_result, data_1_reg);
        intermediate_2_result = _mm256_mask_add_epi64(intermediate_2_result, mask2, intermediate_2_result, data_2_reg);
      }
      auto const intermediate_3_result = _mm256_add_epi64(intermediate_1_result, intermediate_2_result);
      alignas(32) std::array<uint64_t, 4> intermediate_result_array{};
      _mm256_store_si256(reinterpret_cast<__m256i *>(intermediate_result_array.data()), intermediate_3_result);
      uint64_t result = 0;
      for (size_t i = 0; i < 4; ++i) {
        result += intermediate_result_array[i];
      }
      return result;
    }
#endif
}

#endif //TEST_CIDR_AGG_AVX_AGG_HPP