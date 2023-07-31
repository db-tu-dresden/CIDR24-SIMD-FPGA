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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/src/test/mask_unit_test.cpp
 * \date 2023-07-22
 * \brief Unit test file for TSL Primitives using Catch2
 * \note
 *
 */

#include <tslintrin.hpp>
#include <cstddef>
#include <array>
#include <iostream>
#include <bitset>
#include "test_functions.hpp"

namespace tsl {
    template<VectorProcessingStyle Vec>
    bool test_to_integral_mask_match_alternate() {
        using namespace tsl;
        using T = typename Vec::base_type;
        bool allOk = true;
        if constexpr (std::is_same_v<bool, typename Vec::mask_type>) {
          std::cerr << "implement me" << std::endl;
          return true;
        } else if constexpr (std::is_same_v<typename Vec::mask_type, typename Vec::imask_type>) {
          //we don't need to do anything here since it is a NOP.
          return true;
        } else {
            //e.g., SSE, AVX2, ...
            auto data_create_lambda = [](T* data, std::size_t element_count) {
              for (size_t i = 0; i < element_count; ++i) {
                data[i] = i % 2 == 0 ? -1 : 0;
              }
            };
            testing::test_memory_helper_t<Vec> test_helper{Vec::vector_element_count(), Vec::vector_element_count(), false, data_create_lambda};
            tsl::storeu<Vec>(test_helper.result_target(), tsl::set1<Vec>(0));
            auto reference_result_ptr = reinterpret_cast<typename Vec::imask_type*>(test_helper.result_ref());
            typename Vec::imask_type expected_result = 0;
            for (size_t i = 0; i < Vec::vector_element_count(); ++i) {
              expected_result |= i % 2 == 0 ? 0b1 << i : 0;
            }
            *reference_result_ptr = expected_result;
            auto test_data_ptr = test_helper.data_target();
            auto test_result_ptr = reinterpret_cast<typename Vec::imask_type*>(test_helper.result_target());
            auto vec_mask = loadu<Vec>(test_data_ptr);
            auto mask_integral = to_integral<Vec>(vec_mask);
            *test_result_ptr = mask_integral;
            test_helper.synchronize();
            /*std::cerr << tsl::type_name<Vec>() << std::endl;
            std::cerr << "expected_result: " << std::bitset<64>{(unsigned long long)expected_result} << std::endl;
            std::cerr << "test_result: " << std::bitset<64>{(unsigned long long)mask_integral} << std::endl;
            std::cerr << "Same values? " << ((expected_result == mask_integral) ? "True" : "False")<< std::endl;
            std::cerr << "Same values? " << ((test_helper.validate()) ? "True" : "False")<< std::endl;*/
            return test_helper.validate();
        }

    }
    template<VectorProcessingStyle Vec>
    bool test_to_integral_mask_match_zero_to_vec_count() {
        using namespace tsl;
        using T = typename Vec::base_type;
        bool allOk = true;
        // For Vec::mask_type == Vec::register_type testing
        std::array< T, Vec::vector_element_count() > pseudo_mask;
        typename Vec::mask_type vec_mask;
        for(std::size_t i = 0; i < Vec::vector_element_count() + 1; i++) {
          // To check if we are at AVX512/Scalar or any register type mask
          if constexpr (std::is_same_v<bool, typename Vec::mask_type>) {
              // e.g. Scalar (bool)
              vec_mask = false;
              for ( std::size_t j = 0; j < i; ++j ) {
                vec_mask = (vec_mask << 1) | 0b1;
              }
          } else if constexpr (std::is_same_v<typename Vec::mask_type, typename Vec::imask_type>) {
              // // e.g. AVX512
              vec_mask = 0;
              typename Vec::mask_type one = 0b1;
              for ( std::size_t j = 0; j < i; ++j ) {
                vec_mask |= one << j;
              }
          } else {
              // e.g. SSE, AVX2
              pseudo_mask.fill( 0 );
              T val = -1;
              for ( std::size_t j = 0; j < i; ++j ) {
                pseudo_mask[ j ] = val;
              }
              vec_mask = loadu<Vec>( pseudo_mask.data() );
          }
          auto mask_integral = to_integral<Vec>( vec_mask );
          std::size_t matches = 0;
          for ( std::size_t k = 0; k < Vec::vector_element_count(); ++k ) {
            if(((mask_integral >> k) & 0b1) == 1 ) {
              ++matches;
            }
          }
          allOk &= (matches == i);
        }
        return allOk;

    }
}

TEST_CASE("Testing primitive 'to_integral' for avx2", "[to_integral],[avx2]") {
    using namespace tsl;
    SECTION("mask_match_alternate") {
        CHECK(test_to_integral_mask_match_alternate<simd<double, avx2>>());

        CHECK(test_to_integral_mask_match_alternate<simd<float, avx2>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int16_t, avx2>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int32_t, avx2>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int64_t, avx2>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int8_t, avx2>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint16_t, avx2>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint32_t, avx2>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint64_t, avx2>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint8_t, avx2>>());

    }
    SECTION("mask_match_zero_to_vec_count") {
        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<double, avx2>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<float, avx2>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int16_t, avx2>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int32_t, avx2>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int64_t, avx2>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int8_t, avx2>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint16_t, avx2>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint32_t, avx2>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint64_t, avx2>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'to_integral' for avx512", "[to_integral],[avx512]") {
    using namespace tsl;
    SECTION("mask_match_alternate") {
        CHECK(test_to_integral_mask_match_alternate<simd<double, avx512>>());

        CHECK(test_to_integral_mask_match_alternate<simd<float, avx512>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int16_t, avx512>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int32_t, avx512>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int64_t, avx512>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int8_t, avx512>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint16_t, avx512>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint32_t, avx512>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint64_t, avx512>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint8_t, avx512>>());

    }
    SECTION("mask_match_zero_to_vec_count") {
        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<double, avx512>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<float, avx512>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int16_t, avx512>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int32_t, avx512>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int64_t, avx512>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int8_t, avx512>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint16_t, avx512>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint32_t, avx512>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint64_t, avx512>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'to_integral' for scalar", "[to_integral],[scalar]") {
    using namespace tsl;
    SECTION("mask_match_alternate") {
        CHECK(test_to_integral_mask_match_alternate<simd<double, scalar>>());

        CHECK(test_to_integral_mask_match_alternate<simd<float, scalar>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int16_t, scalar>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int32_t, scalar>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int64_t, scalar>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int8_t, scalar>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint16_t, scalar>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint32_t, scalar>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint64_t, scalar>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint8_t, scalar>>());

    }
    SECTION("mask_match_zero_to_vec_count") {
        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<double, scalar>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<float, scalar>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int16_t, scalar>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int32_t, scalar>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int64_t, scalar>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int8_t, scalar>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint16_t, scalar>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint32_t, scalar>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint64_t, scalar>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'to_integral' for sse", "[to_integral],[sse]") {
    using namespace tsl;
    SECTION("mask_match_alternate") {
        CHECK(test_to_integral_mask_match_alternate<simd<double, sse>>());

        CHECK(test_to_integral_mask_match_alternate<simd<float, sse>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int16_t, sse>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int32_t, sse>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int64_t, sse>>());

        CHECK(test_to_integral_mask_match_alternate<simd<int8_t, sse>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint16_t, sse>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint32_t, sse>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint64_t, sse>>());

        CHECK(test_to_integral_mask_match_alternate<simd<uint8_t, sse>>());

    }
    SECTION("mask_match_zero_to_vec_count") {
        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<double, sse>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<float, sse>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int16_t, sse>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int32_t, sse>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int64_t, sse>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<int8_t, sse>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint16_t, sse>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint32_t, sse>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint64_t, sse>>());

        CHECK(test_to_integral_mask_match_zero_to_vec_count<simd<uint8_t, sse>>());

    }
}

