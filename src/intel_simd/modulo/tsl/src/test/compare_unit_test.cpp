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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/src/test/compare_unit_test.cpp
 * \date 2023-07-22
 * \brief Unit test file for TSL Primitives using Catch2
 * \note
 *
 */

#include <tslintrin.hpp>
#include <cstddef>
#include <limits>
#include "test_functions.hpp"

namespace tsl {
    template<VectorProcessingStyle Vec>
    bool test_count_matches_with_only_zero_searching_one() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{1, false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto vec = set1<Vec>(0);
        auto val = 1;
        *reference_result_ptr = 0;
        *test_result_ptr = count_matches<Vec>(vec, val);
        test_helper.synchronize();
        return test_helper.validate();

    }
    template<VectorProcessingStyle Vec>
    bool test_count_matches_with_only_zero_searching_zero() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{1, false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto vec = set1<Vec>(0);
        auto val = 0;
        *reference_result_ptr = Vec::vector_element_count();
        *test_result_ptr = count_matches<Vec>(vec, val);
        test_helper.synchronize();
        return test_helper.validate();

    }
    template<VectorProcessingStyle Vec>
    bool test_count_matches_with_one_match() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{Vec::vector_element_count(), 1, false, testing::seq_init<T>, 1};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        auto vec = loadu<Vec>(test_data_ptr);
        auto val = Vec::vector_element_count();
        *reference_result_ptr = 1;
        *test_result_ptr = count_matches<Vec>(vec, val);
        test_helper.synchronize();
        return test_helper.validate();

    }
    template<VectorProcessingStyle Vec>
    bool test_unequal_zero_with_only_one() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{1, false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto vec = set1<Vec>(1);
        *reference_result_ptr = 1;
        *test_result_ptr = unequal_zero<Vec>(vec);
        test_helper.synchronize();
        return test_helper.validate();

    }
    template<VectorProcessingStyle Vec>
    bool test_unequal_zero_with_only_zero() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{1, false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto vec = set1<Vec>(0);
        *reference_result_ptr = 0;
        *test_result_ptr = unequal_zero<Vec>(vec);
        test_helper.synchronize();
        return test_helper.validate();

    }
    template<VectorProcessingStyle Vec>
    bool test_unequal_zero_with_sequence() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{1, false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto vec = sequence<Vec>();
        *reference_result_ptr = (bool) (Vec::vector_element_count() - 1);
        *test_result_ptr = unequal_zero<Vec>(vec);
        test_helper.synchronize();
        return test_helper.validate();

    }
    template<VectorProcessingStyle Vec>
    bool test_equal_all_equal() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, 1, false};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          reference_result_ptr[0] = Vec::vector_element_count();
          auto vec1 = loadu<Vec>( &test_data_ptr[i] );
          auto vec2 = loadu<Vec>( &test_data_ptr[i] );
          auto result_mask = equal<Vec>( vec1, vec2 );
          auto result_integral = to_integral<Vec>( result_mask );
          size_t matches = 0;
          for ( size_t i = 0; i < Vec::vector_element_count(); ++i ) {
            if(((result_integral >> i) & 0b1) == 1 ) {
              matches += 1;
            }
          }
          test_result_ptr[0] = matches;
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_equal_none_equal() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, 1, false};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        auto vec1 = set1<Vec>( -1 );
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          reference_result_ptr[0] = 0;
          auto vec2 = loadu<Vec>( &test_data_ptr[i] );
          auto result_mask = equal<Vec>( vec1, vec2 );
          auto result_integral = to_integral<Vec>( result_mask );
          size_t matches = 0;
          for ( size_t i = 0; i < Vec::vector_element_count(); ++i ) {
            if(((result_integral >> i) & 0b1) == 1 ) {
              matches += 1;
            }
          }
          test_result_ptr[0] = matches;
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_greater_than_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count * 2, 0, false};
        bool allOk = true;
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            auto vec1 = &test_helper.data_target()[i];
            auto vec2 = &test_helper.data_target()[element_count + i];
            auto result_mask = greater_than<Vec>(loadu<Vec>(vec1), loadu<Vec>(vec2));
            auto result_integral = to_integral<Vec>(result_mask);
            for (size_t i = 0; i < Vec::vector_element_count(); ++i) {
                allOk &= (((result_integral >> i) & 0b1) == (vec1[i] > vec2[i]));
            }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_greater_than_equal() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, 0, false};
        bool allOk = true;
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            auto vec1 = loadu<Vec>(&test_helper.data_target()[i]);
            auto result_mask = greater_than<Vec>(vec1, vec1);
            auto result_integral = to_integral<Vec>(result_mask);
            for (size_t i = 0; i < Vec::vector_element_count(); ++i) {
                allOk &= (((result_integral >> i) & 0b1) == 0);
            }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_greater_than_or_equal_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count * 2, 0, false};
        bool allOk = true;
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            auto vec1 = &test_helper.data_target()[i];
            auto vec2 = &test_helper.data_target()[element_count + i];
            auto result_mask = greater_than_or_equal<Vec>(loadu<Vec>(vec1), loadu<Vec>(vec2));
            auto result_integral = to_integral<Vec>(result_mask);
            for (size_t i = 0; i < Vec::vector_element_count(); ++i) {
                allOk &= (((result_integral >> i) & 0b1) == (vec1[i] >= vec2[i]));
            }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_greater_than_or_equal_equal() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, 0, false};
        bool allOk = true;
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            auto vec1 = loadu<Vec>(&test_helper.data_target()[i]);
            auto result_mask = greater_than_or_equal<Vec>(vec1, vec1);
            auto result_integral = to_integral<Vec>(result_mask);
            for (size_t i = 0; i < Vec::vector_element_count(); ++i) {
                allOk &= (((result_integral >> i) & 0b1) == 1);
            }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_less_than_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count * 2, 0, false};
        bool allOk = true;
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            auto vec1 = &test_helper.data_target()[i];
            auto vec2 = &test_helper.data_target()[element_count + i];
            auto result_mask = less_than<Vec>(loadu<Vec>(vec1), loadu<Vec>(vec2));
            auto result_integral = to_integral<Vec>(result_mask);
            for (size_t i = 0; i < Vec::vector_element_count(); ++i) {
                allOk &= (((result_integral >> i) & 0b1) == (vec1[i] < vec2[i]));
            }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_less_than_equal() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, 0, false};
        bool allOk = true;
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            auto vec1 = loadu<Vec>(&test_helper.data_target()[i]);
            auto result_mask = less_than<Vec>(vec1, vec1);
            auto result_integral = to_integral<Vec>(result_mask);
            for (size_t i = 0; i < Vec::vector_element_count(); ++i) {
                allOk &= (((result_integral >> i) & 0b1) == 0);
            }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_less_than_or_equal_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count * 2, 0, false};
        bool allOk = true;
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            auto vec1 = &test_helper.data_target()[i];
            auto vec2 = &test_helper.data_target()[element_count + i];
            auto result_mask = less_than_or_equal<Vec>(loadu<Vec>(vec1), loadu<Vec>(vec2));
            auto result_integral = to_integral<Vec>(result_mask);
            for (size_t i = 0; i < Vec::vector_element_count(); ++i) {
                allOk &= (((result_integral >> i) & 0b1) == (vec1[i] <= vec2[i]));
            }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_less_than_or_equal_equal() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, 0, false};
        bool allOk = true;
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            auto vec1 = loadu<Vec>(&test_helper.data_target()[i]);
            auto result_mask = less_than_or_equal<Vec>(vec1, vec1);
            auto result_integral = to_integral<Vec>(result_mask);
            for (size_t i = 0; i < Vec::vector_element_count(); ++i) {
                allOk &= (((result_integral >> i) & 0b1) == 1);
            }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_mask_equal_all_equal() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, 1, false};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          reference_result_ptr[0] = Vec::vector_element_count();
          auto vec1 = loadu<Vec>( &test_data_ptr[i] );
          auto vec2 = loadu<Vec>( &test_data_ptr[i] );
          auto result_mask = equal<Vec>( vec1, vec2 );
          auto result_integral = to_integral<Vec>( result_mask );
          size_t matches = 0;
          for ( size_t i = 0; i < Vec::vector_element_count(); ++i ) {
            if(((result_integral >> i) & 0b1) == 1 ) {
              matches += 1;
            }
          }
          test_result_ptr[0] = matches;
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
}

TEST_CASE("Testing primitive 'count_matches' for avx2", "[count_matches],[avx2]") {
    using namespace tsl;
    SECTION("with_only_zero_searching_one") {
        CHECK(test_count_matches_with_only_zero_searching_one<simd<double, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<float, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int16_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int32_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int64_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int8_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint16_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint32_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint64_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint8_t, avx2>>());

    }
    SECTION("with_only_zero_searching_zero") {
        CHECK(test_count_matches_with_only_zero_searching_zero<simd<double, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<float, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int16_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int32_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int64_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int8_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint16_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint32_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint64_t, avx2>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint8_t, avx2>>());

    }
    SECTION("with_one_match") {
        CHECK(test_count_matches_with_one_match<simd<double, avx2>>());

        CHECK(test_count_matches_with_one_match<simd<float, avx2>>());

        CHECK(test_count_matches_with_one_match<simd<int16_t, avx2>>());

        CHECK(test_count_matches_with_one_match<simd<int32_t, avx2>>());

        CHECK(test_count_matches_with_one_match<simd<int64_t, avx2>>());

        CHECK(test_count_matches_with_one_match<simd<int8_t, avx2>>());

        CHECK(test_count_matches_with_one_match<simd<uint16_t, avx2>>());

        CHECK(test_count_matches_with_one_match<simd<uint32_t, avx2>>());

        CHECK(test_count_matches_with_one_match<simd<uint64_t, avx2>>());

        CHECK(test_count_matches_with_one_match<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'count_matches' for avx512", "[count_matches],[avx512]") {
    using namespace tsl;
    SECTION("with_only_zero_searching_one") {
        CHECK(test_count_matches_with_only_zero_searching_one<simd<double, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<float, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int16_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int32_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int64_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int8_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint16_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint32_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint64_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint8_t, avx512>>());

    }
    SECTION("with_only_zero_searching_zero") {
        CHECK(test_count_matches_with_only_zero_searching_zero<simd<double, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<float, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int16_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int32_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int64_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int8_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint16_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint32_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint64_t, avx512>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint8_t, avx512>>());

    }
    SECTION("with_one_match") {
        CHECK(test_count_matches_with_one_match<simd<double, avx512>>());

        CHECK(test_count_matches_with_one_match<simd<float, avx512>>());

        CHECK(test_count_matches_with_one_match<simd<int16_t, avx512>>());

        CHECK(test_count_matches_with_one_match<simd<int32_t, avx512>>());

        CHECK(test_count_matches_with_one_match<simd<int64_t, avx512>>());

        CHECK(test_count_matches_with_one_match<simd<int8_t, avx512>>());

        CHECK(test_count_matches_with_one_match<simd<uint16_t, avx512>>());

        CHECK(test_count_matches_with_one_match<simd<uint32_t, avx512>>());

        CHECK(test_count_matches_with_one_match<simd<uint64_t, avx512>>());

        CHECK(test_count_matches_with_one_match<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'count_matches' for scalar", "[count_matches],[scalar]") {
    using namespace tsl;
    SECTION("with_only_zero_searching_one") {
        CHECK(test_count_matches_with_only_zero_searching_one<simd<double, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<float, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int16_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int32_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int64_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int8_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint16_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint32_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint64_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint8_t, scalar>>());

    }
    SECTION("with_only_zero_searching_zero") {
        CHECK(test_count_matches_with_only_zero_searching_zero<simd<double, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<float, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int16_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int32_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int64_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int8_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint16_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint32_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint64_t, scalar>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint8_t, scalar>>());

    }
    SECTION("with_one_match") {
        CHECK(test_count_matches_with_one_match<simd<double, scalar>>());

        CHECK(test_count_matches_with_one_match<simd<float, scalar>>());

        CHECK(test_count_matches_with_one_match<simd<int16_t, scalar>>());

        CHECK(test_count_matches_with_one_match<simd<int32_t, scalar>>());

        CHECK(test_count_matches_with_one_match<simd<int64_t, scalar>>());

        CHECK(test_count_matches_with_one_match<simd<int8_t, scalar>>());

        CHECK(test_count_matches_with_one_match<simd<uint16_t, scalar>>());

        CHECK(test_count_matches_with_one_match<simd<uint32_t, scalar>>());

        CHECK(test_count_matches_with_one_match<simd<uint64_t, scalar>>());

        CHECK(test_count_matches_with_one_match<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'count_matches' for sse", "[count_matches],[sse]") {
    using namespace tsl;
    SECTION("with_only_zero_searching_one") {
        CHECK(test_count_matches_with_only_zero_searching_one<simd<double, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<float, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int16_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int32_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int64_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<int8_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint16_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint32_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint64_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_one<simd<uint8_t, sse>>());

    }
    SECTION("with_only_zero_searching_zero") {
        CHECK(test_count_matches_with_only_zero_searching_zero<simd<double, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<float, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int16_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int32_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int64_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<int8_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint16_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint32_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint64_t, sse>>());

        CHECK(test_count_matches_with_only_zero_searching_zero<simd<uint8_t, sse>>());

    }
    SECTION("with_one_match") {
        CHECK(test_count_matches_with_one_match<simd<double, sse>>());

        CHECK(test_count_matches_with_one_match<simd<float, sse>>());

        CHECK(test_count_matches_with_one_match<simd<int16_t, sse>>());

        CHECK(test_count_matches_with_one_match<simd<int32_t, sse>>());

        CHECK(test_count_matches_with_one_match<simd<int64_t, sse>>());

        CHECK(test_count_matches_with_one_match<simd<int8_t, sse>>());

        CHECK(test_count_matches_with_one_match<simd<uint16_t, sse>>());

        CHECK(test_count_matches_with_one_match<simd<uint32_t, sse>>());

        CHECK(test_count_matches_with_one_match<simd<uint64_t, sse>>());

        CHECK(test_count_matches_with_one_match<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'unequal_zero' for avx2", "[unequal_zero],[avx2]") {
    using namespace tsl;
    SECTION("with_only_one") {
        CHECK(test_unequal_zero_with_only_one<simd<double, avx2>>());

        CHECK(test_unequal_zero_with_only_one<simd<float, avx2>>());

        CHECK(test_unequal_zero_with_only_one<simd<int16_t, avx2>>());

        CHECK(test_unequal_zero_with_only_one<simd<int32_t, avx2>>());

        CHECK(test_unequal_zero_with_only_one<simd<int64_t, avx2>>());

        CHECK(test_unequal_zero_with_only_one<simd<int8_t, avx2>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint16_t, avx2>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint32_t, avx2>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint64_t, avx2>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint8_t, avx2>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_unequal_zero_with_only_zero<simd<double, avx2>>());

        CHECK(test_unequal_zero_with_only_zero<simd<float, avx2>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int16_t, avx2>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int32_t, avx2>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int64_t, avx2>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int8_t, avx2>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint16_t, avx2>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint32_t, avx2>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint64_t, avx2>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint8_t, avx2>>());

    }
    SECTION("with_sequence") {
        CHECK(test_unequal_zero_with_sequence<simd<double, avx2>>());

        CHECK(test_unequal_zero_with_sequence<simd<float, avx2>>());

        CHECK(test_unequal_zero_with_sequence<simd<int16_t, avx2>>());

        CHECK(test_unequal_zero_with_sequence<simd<int32_t, avx2>>());

        CHECK(test_unequal_zero_with_sequence<simd<int64_t, avx2>>());

        CHECK(test_unequal_zero_with_sequence<simd<int8_t, avx2>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint16_t, avx2>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint32_t, avx2>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint64_t, avx2>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'unequal_zero' for avx512", "[unequal_zero],[avx512]") {
    using namespace tsl;
    SECTION("with_only_one") {
        CHECK(test_unequal_zero_with_only_one<simd<double, avx512>>());

        CHECK(test_unequal_zero_with_only_one<simd<float, avx512>>());

        CHECK(test_unequal_zero_with_only_one<simd<int16_t, avx512>>());

        CHECK(test_unequal_zero_with_only_one<simd<int32_t, avx512>>());

        CHECK(test_unequal_zero_with_only_one<simd<int64_t, avx512>>());

        CHECK(test_unequal_zero_with_only_one<simd<int8_t, avx512>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint16_t, avx512>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint32_t, avx512>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint64_t, avx512>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint8_t, avx512>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_unequal_zero_with_only_zero<simd<double, avx512>>());

        CHECK(test_unequal_zero_with_only_zero<simd<float, avx512>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int16_t, avx512>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int32_t, avx512>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int64_t, avx512>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int8_t, avx512>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint16_t, avx512>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint32_t, avx512>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint64_t, avx512>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint8_t, avx512>>());

    }
    SECTION("with_sequence") {
        CHECK(test_unequal_zero_with_sequence<simd<double, avx512>>());

        CHECK(test_unequal_zero_with_sequence<simd<float, avx512>>());

        CHECK(test_unequal_zero_with_sequence<simd<int16_t, avx512>>());

        CHECK(test_unequal_zero_with_sequence<simd<int32_t, avx512>>());

        CHECK(test_unequal_zero_with_sequence<simd<int64_t, avx512>>());

        CHECK(test_unequal_zero_with_sequence<simd<int8_t, avx512>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint16_t, avx512>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint32_t, avx512>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint64_t, avx512>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'unequal_zero' for scalar", "[unequal_zero],[scalar]") {
    using namespace tsl;
    SECTION("with_only_one") {
        CHECK(test_unequal_zero_with_only_one<simd<double, scalar>>());

        CHECK(test_unequal_zero_with_only_one<simd<float, scalar>>());

        CHECK(test_unequal_zero_with_only_one<simd<int16_t, scalar>>());

        CHECK(test_unequal_zero_with_only_one<simd<int32_t, scalar>>());

        CHECK(test_unequal_zero_with_only_one<simd<int64_t, scalar>>());

        CHECK(test_unequal_zero_with_only_one<simd<int8_t, scalar>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint16_t, scalar>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint32_t, scalar>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint64_t, scalar>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint8_t, scalar>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_unequal_zero_with_only_zero<simd<double, scalar>>());

        CHECK(test_unequal_zero_with_only_zero<simd<float, scalar>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int16_t, scalar>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int32_t, scalar>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int64_t, scalar>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int8_t, scalar>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint16_t, scalar>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint32_t, scalar>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint64_t, scalar>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint8_t, scalar>>());

    }
    SECTION("with_sequence") {
        CHECK(test_unequal_zero_with_sequence<simd<double, scalar>>());

        CHECK(test_unequal_zero_with_sequence<simd<float, scalar>>());

        CHECK(test_unequal_zero_with_sequence<simd<int16_t, scalar>>());

        CHECK(test_unequal_zero_with_sequence<simd<int32_t, scalar>>());

        CHECK(test_unequal_zero_with_sequence<simd<int64_t, scalar>>());

        CHECK(test_unequal_zero_with_sequence<simd<int8_t, scalar>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint16_t, scalar>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint32_t, scalar>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint64_t, scalar>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'unequal_zero' for sse", "[unequal_zero],[sse]") {
    using namespace tsl;
    SECTION("with_only_one") {
        CHECK(test_unequal_zero_with_only_one<simd<double, sse>>());

        CHECK(test_unequal_zero_with_only_one<simd<float, sse>>());

        CHECK(test_unequal_zero_with_only_one<simd<int16_t, sse>>());

        CHECK(test_unequal_zero_with_only_one<simd<int32_t, sse>>());

        CHECK(test_unequal_zero_with_only_one<simd<int64_t, sse>>());

        CHECK(test_unequal_zero_with_only_one<simd<int8_t, sse>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint16_t, sse>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint32_t, sse>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint64_t, sse>>());

        CHECK(test_unequal_zero_with_only_one<simd<uint8_t, sse>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_unequal_zero_with_only_zero<simd<double, sse>>());

        CHECK(test_unequal_zero_with_only_zero<simd<float, sse>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int16_t, sse>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int32_t, sse>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int64_t, sse>>());

        CHECK(test_unequal_zero_with_only_zero<simd<int8_t, sse>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint16_t, sse>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint32_t, sse>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint64_t, sse>>());

        CHECK(test_unequal_zero_with_only_zero<simd<uint8_t, sse>>());

    }
    SECTION("with_sequence") {
        CHECK(test_unequal_zero_with_sequence<simd<double, sse>>());

        CHECK(test_unequal_zero_with_sequence<simd<float, sse>>());

        CHECK(test_unequal_zero_with_sequence<simd<int16_t, sse>>());

        CHECK(test_unequal_zero_with_sequence<simd<int32_t, sse>>());

        CHECK(test_unequal_zero_with_sequence<simd<int64_t, sse>>());

        CHECK(test_unequal_zero_with_sequence<simd<int8_t, sse>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint16_t, sse>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint32_t, sse>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint64_t, sse>>());

        CHECK(test_unequal_zero_with_sequence<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'equal' for avx2", "[equal],[avx2]") {
    using namespace tsl;
    SECTION("all_equal") {
        CHECK(test_equal_all_equal<simd<double, avx2>>());

        CHECK(test_equal_all_equal<simd<float, avx2>>());

        CHECK(test_equal_all_equal<simd<int16_t, avx2>>());

        CHECK(test_equal_all_equal<simd<int32_t, avx2>>());

        CHECK(test_equal_all_equal<simd<int64_t, avx2>>());

        CHECK(test_equal_all_equal<simd<int8_t, avx2>>());

        CHECK(test_equal_all_equal<simd<uint16_t, avx2>>());

        CHECK(test_equal_all_equal<simd<uint32_t, avx2>>());

        CHECK(test_equal_all_equal<simd<uint64_t, avx2>>());

        CHECK(test_equal_all_equal<simd<uint8_t, avx2>>());

    }
    SECTION("none_equal") {
        CHECK(test_equal_none_equal<simd<double, avx2>>());

        CHECK(test_equal_none_equal<simd<float, avx2>>());

        CHECK(test_equal_none_equal<simd<int16_t, avx2>>());

        CHECK(test_equal_none_equal<simd<int32_t, avx2>>());

        CHECK(test_equal_none_equal<simd<int64_t, avx2>>());

        CHECK(test_equal_none_equal<simd<int8_t, avx2>>());

        CHECK(test_equal_none_equal<simd<uint16_t, avx2>>());

        CHECK(test_equal_none_equal<simd<uint32_t, avx2>>());

        CHECK(test_equal_none_equal<simd<uint64_t, avx2>>());

        CHECK(test_equal_none_equal<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'equal' for avx512", "[equal],[avx512]") {
    using namespace tsl;
    SECTION("all_equal") {
        CHECK(test_equal_all_equal<simd<double, avx512>>());

        CHECK(test_equal_all_equal<simd<float, avx512>>());

        CHECK(test_equal_all_equal<simd<int16_t, avx512>>());

        CHECK(test_equal_all_equal<simd<int32_t, avx512>>());

        CHECK(test_equal_all_equal<simd<int64_t, avx512>>());

        CHECK(test_equal_all_equal<simd<int8_t, avx512>>());

        CHECK(test_equal_all_equal<simd<uint16_t, avx512>>());

        CHECK(test_equal_all_equal<simd<uint32_t, avx512>>());

        CHECK(test_equal_all_equal<simd<uint64_t, avx512>>());

        CHECK(test_equal_all_equal<simd<uint8_t, avx512>>());

    }
    SECTION("none_equal") {
        CHECK(test_equal_none_equal<simd<double, avx512>>());

        CHECK(test_equal_none_equal<simd<float, avx512>>());

        CHECK(test_equal_none_equal<simd<int16_t, avx512>>());

        CHECK(test_equal_none_equal<simd<int32_t, avx512>>());

        CHECK(test_equal_none_equal<simd<int64_t, avx512>>());

        CHECK(test_equal_none_equal<simd<int8_t, avx512>>());

        CHECK(test_equal_none_equal<simd<uint16_t, avx512>>());

        CHECK(test_equal_none_equal<simd<uint32_t, avx512>>());

        CHECK(test_equal_none_equal<simd<uint64_t, avx512>>());

        CHECK(test_equal_none_equal<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'equal' for scalar", "[equal],[scalar]") {
    using namespace tsl;
    SECTION("all_equal") {
        CHECK(test_equal_all_equal<simd<double, scalar>>());

        CHECK(test_equal_all_equal<simd<float, scalar>>());

        CHECK(test_equal_all_equal<simd<int16_t, scalar>>());

        CHECK(test_equal_all_equal<simd<int32_t, scalar>>());

        CHECK(test_equal_all_equal<simd<int64_t, scalar>>());

        CHECK(test_equal_all_equal<simd<int8_t, scalar>>());

        CHECK(test_equal_all_equal<simd<uint16_t, scalar>>());

        CHECK(test_equal_all_equal<simd<uint32_t, scalar>>());

        CHECK(test_equal_all_equal<simd<uint64_t, scalar>>());

        CHECK(test_equal_all_equal<simd<uint8_t, scalar>>());

    }
    SECTION("none_equal") {
        CHECK(test_equal_none_equal<simd<double, scalar>>());

        CHECK(test_equal_none_equal<simd<float, scalar>>());

        CHECK(test_equal_none_equal<simd<int16_t, scalar>>());

        CHECK(test_equal_none_equal<simd<int32_t, scalar>>());

        CHECK(test_equal_none_equal<simd<int64_t, scalar>>());

        CHECK(test_equal_none_equal<simd<int8_t, scalar>>());

        CHECK(test_equal_none_equal<simd<uint16_t, scalar>>());

        CHECK(test_equal_none_equal<simd<uint32_t, scalar>>());

        CHECK(test_equal_none_equal<simd<uint64_t, scalar>>());

        CHECK(test_equal_none_equal<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'equal' for sse", "[equal],[sse]") {
    using namespace tsl;
    SECTION("all_equal") {
        WARN("Primitive equal<simd<double, sse>> not implemented.");
        WARN("Primitive equal<simd<float, sse>> not implemented.");
        CHECK(test_equal_all_equal<simd<int16_t, sse>>());

        CHECK(test_equal_all_equal<simd<int32_t, sse>>());

        CHECK(test_equal_all_equal<simd<int64_t, sse>>());

        CHECK(test_equal_all_equal<simd<int8_t, sse>>());

        CHECK(test_equal_all_equal<simd<uint16_t, sse>>());

        CHECK(test_equal_all_equal<simd<uint32_t, sse>>());

        CHECK(test_equal_all_equal<simd<uint64_t, sse>>());

        CHECK(test_equal_all_equal<simd<uint8_t, sse>>());

    }
    SECTION("none_equal") {
        WARN("Primitive equal<simd<double, sse>> not implemented.");
        WARN("Primitive equal<simd<float, sse>> not implemented.");
        CHECK(test_equal_none_equal<simd<int16_t, sse>>());

        CHECK(test_equal_none_equal<simd<int32_t, sse>>());

        CHECK(test_equal_none_equal<simd<int64_t, sse>>());

        CHECK(test_equal_none_equal<simd<int8_t, sse>>());

        CHECK(test_equal_none_equal<simd<uint16_t, sse>>());

        CHECK(test_equal_none_equal<simd<uint32_t, sse>>());

        CHECK(test_equal_none_equal<simd<uint64_t, sse>>());

        CHECK(test_equal_none_equal<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'greater_than' for avx2", "[greater_than],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_greater_than_default<simd<double, avx2>>());

        CHECK(test_greater_than_default<simd<float, avx2>>());

        CHECK(test_greater_than_default<simd<int16_t, avx2>>());

        CHECK(test_greater_than_default<simd<int32_t, avx2>>());

        CHECK(test_greater_than_default<simd<int64_t, avx2>>());

        CHECK(test_greater_than_default<simd<int8_t, avx2>>());

        CHECK(test_greater_than_default<simd<uint16_t, avx2>>());

        CHECK(test_greater_than_default<simd<uint32_t, avx2>>());

        CHECK(test_greater_than_default<simd<uint64_t, avx2>>());

        CHECK(test_greater_than_default<simd<uint8_t, avx2>>());

    }
    SECTION("equal") {
        CHECK(test_greater_than_equal<simd<double, avx2>>());

        CHECK(test_greater_than_equal<simd<float, avx2>>());

        CHECK(test_greater_than_equal<simd<int16_t, avx2>>());

        CHECK(test_greater_than_equal<simd<int32_t, avx2>>());

        CHECK(test_greater_than_equal<simd<int64_t, avx2>>());

        CHECK(test_greater_than_equal<simd<int8_t, avx2>>());

        CHECK(test_greater_than_equal<simd<uint16_t, avx2>>());

        CHECK(test_greater_than_equal<simd<uint32_t, avx2>>());

        CHECK(test_greater_than_equal<simd<uint64_t, avx2>>());

        CHECK(test_greater_than_equal<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'greater_than' for avx512", "[greater_than],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_greater_than_default<simd<double, avx512>>());

        CHECK(test_greater_than_default<simd<float, avx512>>());

        CHECK(test_greater_than_default<simd<int16_t, avx512>>());

        CHECK(test_greater_than_default<simd<int32_t, avx512>>());

        CHECK(test_greater_than_default<simd<int64_t, avx512>>());

        CHECK(test_greater_than_default<simd<int8_t, avx512>>());

        CHECK(test_greater_than_default<simd<uint16_t, avx512>>());

        CHECK(test_greater_than_default<simd<uint32_t, avx512>>());

        CHECK(test_greater_than_default<simd<uint64_t, avx512>>());

        CHECK(test_greater_than_default<simd<uint8_t, avx512>>());

    }
    SECTION("equal") {
        CHECK(test_greater_than_equal<simd<double, avx512>>());

        CHECK(test_greater_than_equal<simd<float, avx512>>());

        CHECK(test_greater_than_equal<simd<int16_t, avx512>>());

        CHECK(test_greater_than_equal<simd<int32_t, avx512>>());

        CHECK(test_greater_than_equal<simd<int64_t, avx512>>());

        CHECK(test_greater_than_equal<simd<int8_t, avx512>>());

        CHECK(test_greater_than_equal<simd<uint16_t, avx512>>());

        CHECK(test_greater_than_equal<simd<uint32_t, avx512>>());

        CHECK(test_greater_than_equal<simd<uint64_t, avx512>>());

        CHECK(test_greater_than_equal<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'greater_than' for scalar", "[greater_than],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_greater_than_default<simd<double, scalar>>());

        CHECK(test_greater_than_default<simd<float, scalar>>());

        CHECK(test_greater_than_default<simd<int16_t, scalar>>());

        CHECK(test_greater_than_default<simd<int32_t, scalar>>());

        CHECK(test_greater_than_default<simd<int64_t, scalar>>());

        CHECK(test_greater_than_default<simd<int8_t, scalar>>());

        CHECK(test_greater_than_default<simd<uint16_t, scalar>>());

        CHECK(test_greater_than_default<simd<uint32_t, scalar>>());

        CHECK(test_greater_than_default<simd<uint64_t, scalar>>());

        CHECK(test_greater_than_default<simd<uint8_t, scalar>>());

    }
    SECTION("equal") {
        CHECK(test_greater_than_equal<simd<double, scalar>>());

        CHECK(test_greater_than_equal<simd<float, scalar>>());

        CHECK(test_greater_than_equal<simd<int16_t, scalar>>());

        CHECK(test_greater_than_equal<simd<int32_t, scalar>>());

        CHECK(test_greater_than_equal<simd<int64_t, scalar>>());

        CHECK(test_greater_than_equal<simd<int8_t, scalar>>());

        CHECK(test_greater_than_equal<simd<uint16_t, scalar>>());

        CHECK(test_greater_than_equal<simd<uint32_t, scalar>>());

        CHECK(test_greater_than_equal<simd<uint64_t, scalar>>());

        CHECK(test_greater_than_equal<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'greater_than' for sse", "[greater_than],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_greater_than_default<simd<double, sse>>());

        CHECK(test_greater_than_default<simd<float, sse>>());

        CHECK(test_greater_than_default<simd<int16_t, sse>>());

        CHECK(test_greater_than_default<simd<int32_t, sse>>());

        CHECK(test_greater_than_default<simd<int64_t, sse>>());

        CHECK(test_greater_than_default<simd<int8_t, sse>>());

        CHECK(test_greater_than_default<simd<uint16_t, sse>>());

        CHECK(test_greater_than_default<simd<uint32_t, sse>>());

        CHECK(test_greater_than_default<simd<uint64_t, sse>>());

        CHECK(test_greater_than_default<simd<uint8_t, sse>>());

    }
    SECTION("equal") {
        CHECK(test_greater_than_equal<simd<double, sse>>());

        CHECK(test_greater_than_equal<simd<float, sse>>());

        CHECK(test_greater_than_equal<simd<int16_t, sse>>());

        CHECK(test_greater_than_equal<simd<int32_t, sse>>());

        CHECK(test_greater_than_equal<simd<int64_t, sse>>());

        CHECK(test_greater_than_equal<simd<int8_t, sse>>());

        CHECK(test_greater_than_equal<simd<uint16_t, sse>>());

        CHECK(test_greater_than_equal<simd<uint32_t, sse>>());

        CHECK(test_greater_than_equal<simd<uint64_t, sse>>());

        CHECK(test_greater_than_equal<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'greater_than_or_equal' for avx2", "[greater_than_or_equal],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_greater_than_or_equal_default<simd<double, avx2>>());

        CHECK(test_greater_than_or_equal_default<simd<float, avx2>>());

        CHECK(test_greater_than_or_equal_default<simd<int16_t, avx2>>());

        CHECK(test_greater_than_or_equal_default<simd<int32_t, avx2>>());

        CHECK(test_greater_than_or_equal_default<simd<int64_t, avx2>>());

        CHECK(test_greater_than_or_equal_default<simd<int8_t, avx2>>());

        CHECK(test_greater_than_or_equal_default<simd<uint16_t, avx2>>());

        CHECK(test_greater_than_or_equal_default<simd<uint32_t, avx2>>());

        CHECK(test_greater_than_or_equal_default<simd<uint64_t, avx2>>());

        CHECK(test_greater_than_or_equal_default<simd<uint8_t, avx2>>());

    }
    SECTION("equal") {
        CHECK(test_greater_than_or_equal_equal<simd<double, avx2>>());

        CHECK(test_greater_than_or_equal_equal<simd<float, avx2>>());

        CHECK(test_greater_than_or_equal_equal<simd<int16_t, avx2>>());

        CHECK(test_greater_than_or_equal_equal<simd<int32_t, avx2>>());

        CHECK(test_greater_than_or_equal_equal<simd<int64_t, avx2>>());

        CHECK(test_greater_than_or_equal_equal<simd<int8_t, avx2>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint16_t, avx2>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint32_t, avx2>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint64_t, avx2>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'greater_than_or_equal' for avx512", "[greater_than_or_equal],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_greater_than_or_equal_default<simd<double, avx512>>());

        CHECK(test_greater_than_or_equal_default<simd<float, avx512>>());

        CHECK(test_greater_than_or_equal_default<simd<int16_t, avx512>>());

        CHECK(test_greater_than_or_equal_default<simd<int32_t, avx512>>());

        CHECK(test_greater_than_or_equal_default<simd<int64_t, avx512>>());

        CHECK(test_greater_than_or_equal_default<simd<int8_t, avx512>>());

        CHECK(test_greater_than_or_equal_default<simd<uint16_t, avx512>>());

        CHECK(test_greater_than_or_equal_default<simd<uint32_t, avx512>>());

        CHECK(test_greater_than_or_equal_default<simd<uint64_t, avx512>>());

        CHECK(test_greater_than_or_equal_default<simd<uint8_t, avx512>>());

    }
    SECTION("equal") {
        CHECK(test_greater_than_or_equal_equal<simd<double, avx512>>());

        CHECK(test_greater_than_or_equal_equal<simd<float, avx512>>());

        CHECK(test_greater_than_or_equal_equal<simd<int16_t, avx512>>());

        CHECK(test_greater_than_or_equal_equal<simd<int32_t, avx512>>());

        CHECK(test_greater_than_or_equal_equal<simd<int64_t, avx512>>());

        CHECK(test_greater_than_or_equal_equal<simd<int8_t, avx512>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint16_t, avx512>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint32_t, avx512>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint64_t, avx512>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'greater_than_or_equal' for scalar", "[greater_than_or_equal],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_greater_than_or_equal_default<simd<double, scalar>>());

        CHECK(test_greater_than_or_equal_default<simd<float, scalar>>());

        CHECK(test_greater_than_or_equal_default<simd<int16_t, scalar>>());

        CHECK(test_greater_than_or_equal_default<simd<int32_t, scalar>>());

        CHECK(test_greater_than_or_equal_default<simd<int64_t, scalar>>());

        CHECK(test_greater_than_or_equal_default<simd<int8_t, scalar>>());

        CHECK(test_greater_than_or_equal_default<simd<uint16_t, scalar>>());

        CHECK(test_greater_than_or_equal_default<simd<uint32_t, scalar>>());

        CHECK(test_greater_than_or_equal_default<simd<uint64_t, scalar>>());

        CHECK(test_greater_than_or_equal_default<simd<uint8_t, scalar>>());

    }
    SECTION("equal") {
        CHECK(test_greater_than_or_equal_equal<simd<double, scalar>>());

        CHECK(test_greater_than_or_equal_equal<simd<float, scalar>>());

        CHECK(test_greater_than_or_equal_equal<simd<int16_t, scalar>>());

        CHECK(test_greater_than_or_equal_equal<simd<int32_t, scalar>>());

        CHECK(test_greater_than_or_equal_equal<simd<int64_t, scalar>>());

        CHECK(test_greater_than_or_equal_equal<simd<int8_t, scalar>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint16_t, scalar>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint32_t, scalar>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint64_t, scalar>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'greater_than_or_equal' for sse", "[greater_than_or_equal],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_greater_than_or_equal_default<simd<double, sse>>());

        CHECK(test_greater_than_or_equal_default<simd<float, sse>>());

        CHECK(test_greater_than_or_equal_default<simd<int16_t, sse>>());

        CHECK(test_greater_than_or_equal_default<simd<int32_t, sse>>());

        CHECK(test_greater_than_or_equal_default<simd<int64_t, sse>>());

        CHECK(test_greater_than_or_equal_default<simd<int8_t, sse>>());

        CHECK(test_greater_than_or_equal_default<simd<uint16_t, sse>>());

        CHECK(test_greater_than_or_equal_default<simd<uint32_t, sse>>());

        CHECK(test_greater_than_or_equal_default<simd<uint64_t, sse>>());

        CHECK(test_greater_than_or_equal_default<simd<uint8_t, sse>>());

    }
    SECTION("equal") {
        CHECK(test_greater_than_or_equal_equal<simd<double, sse>>());

        CHECK(test_greater_than_or_equal_equal<simd<float, sse>>());

        CHECK(test_greater_than_or_equal_equal<simd<int16_t, sse>>());

        CHECK(test_greater_than_or_equal_equal<simd<int32_t, sse>>());

        CHECK(test_greater_than_or_equal_equal<simd<int64_t, sse>>());

        CHECK(test_greater_than_or_equal_equal<simd<int8_t, sse>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint16_t, sse>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint32_t, sse>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint64_t, sse>>());

        CHECK(test_greater_than_or_equal_equal<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'less_than' for avx2", "[less_than],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_less_than_default<simd<double, avx2>>());

        CHECK(test_less_than_default<simd<float, avx2>>());

        CHECK(test_less_than_default<simd<int16_t, avx2>>());

        CHECK(test_less_than_default<simd<int32_t, avx2>>());

        CHECK(test_less_than_default<simd<int64_t, avx2>>());

        CHECK(test_less_than_default<simd<int8_t, avx2>>());

        CHECK(test_less_than_default<simd<uint16_t, avx2>>());

        CHECK(test_less_than_default<simd<uint32_t, avx2>>());

        CHECK(test_less_than_default<simd<uint64_t, avx2>>());

        CHECK(test_less_than_default<simd<uint8_t, avx2>>());

    }
    SECTION("equal") {
        CHECK(test_less_than_equal<simd<double, avx2>>());

        CHECK(test_less_than_equal<simd<float, avx2>>());

        CHECK(test_less_than_equal<simd<int16_t, avx2>>());

        CHECK(test_less_than_equal<simd<int32_t, avx2>>());

        CHECK(test_less_than_equal<simd<int64_t, avx2>>());

        CHECK(test_less_than_equal<simd<int8_t, avx2>>());

        CHECK(test_less_than_equal<simd<uint16_t, avx2>>());

        CHECK(test_less_than_equal<simd<uint32_t, avx2>>());

        CHECK(test_less_than_equal<simd<uint64_t, avx2>>());

        CHECK(test_less_than_equal<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'less_than' for avx512", "[less_than],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_less_than_default<simd<double, avx512>>());

        CHECK(test_less_than_default<simd<float, avx512>>());

        CHECK(test_less_than_default<simd<int16_t, avx512>>());

        CHECK(test_less_than_default<simd<int32_t, avx512>>());

        CHECK(test_less_than_default<simd<int64_t, avx512>>());

        CHECK(test_less_than_default<simd<int8_t, avx512>>());

        CHECK(test_less_than_default<simd<uint16_t, avx512>>());

        CHECK(test_less_than_default<simd<uint32_t, avx512>>());

        CHECK(test_less_than_default<simd<uint64_t, avx512>>());

        CHECK(test_less_than_default<simd<uint8_t, avx512>>());

    }
    SECTION("equal") {
        CHECK(test_less_than_equal<simd<double, avx512>>());

        CHECK(test_less_than_equal<simd<float, avx512>>());

        CHECK(test_less_than_equal<simd<int16_t, avx512>>());

        CHECK(test_less_than_equal<simd<int32_t, avx512>>());

        CHECK(test_less_than_equal<simd<int64_t, avx512>>());

        CHECK(test_less_than_equal<simd<int8_t, avx512>>());

        CHECK(test_less_than_equal<simd<uint16_t, avx512>>());

        CHECK(test_less_than_equal<simd<uint32_t, avx512>>());

        CHECK(test_less_than_equal<simd<uint64_t, avx512>>());

        CHECK(test_less_than_equal<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'less_than' for scalar", "[less_than],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_less_than_default<simd<double, scalar>>());

        CHECK(test_less_than_default<simd<float, scalar>>());

        CHECK(test_less_than_default<simd<int16_t, scalar>>());

        CHECK(test_less_than_default<simd<int32_t, scalar>>());

        CHECK(test_less_than_default<simd<int64_t, scalar>>());

        CHECK(test_less_than_default<simd<int8_t, scalar>>());

        CHECK(test_less_than_default<simd<uint16_t, scalar>>());

        CHECK(test_less_than_default<simd<uint32_t, scalar>>());

        CHECK(test_less_than_default<simd<uint64_t, scalar>>());

        CHECK(test_less_than_default<simd<uint8_t, scalar>>());

    }
    SECTION("equal") {
        CHECK(test_less_than_equal<simd<double, scalar>>());

        CHECK(test_less_than_equal<simd<float, scalar>>());

        CHECK(test_less_than_equal<simd<int16_t, scalar>>());

        CHECK(test_less_than_equal<simd<int32_t, scalar>>());

        CHECK(test_less_than_equal<simd<int64_t, scalar>>());

        CHECK(test_less_than_equal<simd<int8_t, scalar>>());

        CHECK(test_less_than_equal<simd<uint16_t, scalar>>());

        CHECK(test_less_than_equal<simd<uint32_t, scalar>>());

        CHECK(test_less_than_equal<simd<uint64_t, scalar>>());

        CHECK(test_less_than_equal<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'less_than' for sse", "[less_than],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_less_than_default<simd<double, sse>>());

        CHECK(test_less_than_default<simd<float, sse>>());

        CHECK(test_less_than_default<simd<int16_t, sse>>());

        CHECK(test_less_than_default<simd<int32_t, sse>>());

        CHECK(test_less_than_default<simd<int64_t, sse>>());

        CHECK(test_less_than_default<simd<int8_t, sse>>());

        CHECK(test_less_than_default<simd<uint16_t, sse>>());

        CHECK(test_less_than_default<simd<uint32_t, sse>>());

        CHECK(test_less_than_default<simd<uint64_t, sse>>());

        CHECK(test_less_than_default<simd<uint8_t, sse>>());

    }
    SECTION("equal") {
        CHECK(test_less_than_equal<simd<double, sse>>());

        CHECK(test_less_than_equal<simd<float, sse>>());

        CHECK(test_less_than_equal<simd<int16_t, sse>>());

        CHECK(test_less_than_equal<simd<int32_t, sse>>());

        CHECK(test_less_than_equal<simd<int64_t, sse>>());

        CHECK(test_less_than_equal<simd<int8_t, sse>>());

        CHECK(test_less_than_equal<simd<uint16_t, sse>>());

        CHECK(test_less_than_equal<simd<uint32_t, sse>>());

        CHECK(test_less_than_equal<simd<uint64_t, sse>>());

        CHECK(test_less_than_equal<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'less_than_or_equal' for avx2", "[less_than_or_equal],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_less_than_or_equal_default<simd<double, avx2>>());

        CHECK(test_less_than_or_equal_default<simd<float, avx2>>());

        CHECK(test_less_than_or_equal_default<simd<int16_t, avx2>>());

        CHECK(test_less_than_or_equal_default<simd<int32_t, avx2>>());

        CHECK(test_less_than_or_equal_default<simd<int64_t, avx2>>());

        CHECK(test_less_than_or_equal_default<simd<int8_t, avx2>>());

        CHECK(test_less_than_or_equal_default<simd<uint16_t, avx2>>());

        CHECK(test_less_than_or_equal_default<simd<uint32_t, avx2>>());

        CHECK(test_less_than_or_equal_default<simd<uint64_t, avx2>>());

        CHECK(test_less_than_or_equal_default<simd<uint8_t, avx2>>());

    }
    SECTION("equal") {
        CHECK(test_less_than_or_equal_equal<simd<double, avx2>>());

        CHECK(test_less_than_or_equal_equal<simd<float, avx2>>());

        CHECK(test_less_than_or_equal_equal<simd<int16_t, avx2>>());

        CHECK(test_less_than_or_equal_equal<simd<int32_t, avx2>>());

        CHECK(test_less_than_or_equal_equal<simd<int64_t, avx2>>());

        CHECK(test_less_than_or_equal_equal<simd<int8_t, avx2>>());

        CHECK(test_less_than_or_equal_equal<simd<uint16_t, avx2>>());

        CHECK(test_less_than_or_equal_equal<simd<uint32_t, avx2>>());

        CHECK(test_less_than_or_equal_equal<simd<uint64_t, avx2>>());

        CHECK(test_less_than_or_equal_equal<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'less_than_or_equal' for avx512", "[less_than_or_equal],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_less_than_or_equal_default<simd<double, avx512>>());

        CHECK(test_less_than_or_equal_default<simd<float, avx512>>());

        CHECK(test_less_than_or_equal_default<simd<int16_t, avx512>>());

        CHECK(test_less_than_or_equal_default<simd<int32_t, avx512>>());

        CHECK(test_less_than_or_equal_default<simd<int64_t, avx512>>());

        CHECK(test_less_than_or_equal_default<simd<int8_t, avx512>>());

        CHECK(test_less_than_or_equal_default<simd<uint16_t, avx512>>());

        CHECK(test_less_than_or_equal_default<simd<uint32_t, avx512>>());

        CHECK(test_less_than_or_equal_default<simd<uint64_t, avx512>>());

        CHECK(test_less_than_or_equal_default<simd<uint8_t, avx512>>());

    }
    SECTION("equal") {
        CHECK(test_less_than_or_equal_equal<simd<double, avx512>>());

        CHECK(test_less_than_or_equal_equal<simd<float, avx512>>());

        CHECK(test_less_than_or_equal_equal<simd<int16_t, avx512>>());

        CHECK(test_less_than_or_equal_equal<simd<int32_t, avx512>>());

        CHECK(test_less_than_or_equal_equal<simd<int64_t, avx512>>());

        CHECK(test_less_than_or_equal_equal<simd<int8_t, avx512>>());

        CHECK(test_less_than_or_equal_equal<simd<uint16_t, avx512>>());

        CHECK(test_less_than_or_equal_equal<simd<uint32_t, avx512>>());

        CHECK(test_less_than_or_equal_equal<simd<uint64_t, avx512>>());

        CHECK(test_less_than_or_equal_equal<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'less_than_or_equal' for scalar", "[less_than_or_equal],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_less_than_or_equal_default<simd<double, scalar>>());

        CHECK(test_less_than_or_equal_default<simd<float, scalar>>());

        CHECK(test_less_than_or_equal_default<simd<int16_t, scalar>>());

        CHECK(test_less_than_or_equal_default<simd<int32_t, scalar>>());

        CHECK(test_less_than_or_equal_default<simd<int64_t, scalar>>());

        CHECK(test_less_than_or_equal_default<simd<int8_t, scalar>>());

        CHECK(test_less_than_or_equal_default<simd<uint16_t, scalar>>());

        CHECK(test_less_than_or_equal_default<simd<uint32_t, scalar>>());

        CHECK(test_less_than_or_equal_default<simd<uint64_t, scalar>>());

        CHECK(test_less_than_or_equal_default<simd<uint8_t, scalar>>());

    }
    SECTION("equal") {
        CHECK(test_less_than_or_equal_equal<simd<double, scalar>>());

        CHECK(test_less_than_or_equal_equal<simd<float, scalar>>());

        CHECK(test_less_than_or_equal_equal<simd<int16_t, scalar>>());

        CHECK(test_less_than_or_equal_equal<simd<int32_t, scalar>>());

        CHECK(test_less_than_or_equal_equal<simd<int64_t, scalar>>());

        CHECK(test_less_than_or_equal_equal<simd<int8_t, scalar>>());

        CHECK(test_less_than_or_equal_equal<simd<uint16_t, scalar>>());

        CHECK(test_less_than_or_equal_equal<simd<uint32_t, scalar>>());

        CHECK(test_less_than_or_equal_equal<simd<uint64_t, scalar>>());

        CHECK(test_less_than_or_equal_equal<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'less_than_or_equal' for sse", "[less_than_or_equal],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_less_than_or_equal_default<simd<double, sse>>());

        CHECK(test_less_than_or_equal_default<simd<float, sse>>());

        CHECK(test_less_than_or_equal_default<simd<int16_t, sse>>());

        CHECK(test_less_than_or_equal_default<simd<int32_t, sse>>());

        CHECK(test_less_than_or_equal_default<simd<int64_t, sse>>());

        CHECK(test_less_than_or_equal_default<simd<int8_t, sse>>());

        CHECK(test_less_than_or_equal_default<simd<uint16_t, sse>>());

        CHECK(test_less_than_or_equal_default<simd<uint32_t, sse>>());

        CHECK(test_less_than_or_equal_default<simd<uint64_t, sse>>());

        CHECK(test_less_than_or_equal_default<simd<uint8_t, sse>>());

    }
    SECTION("equal") {
        CHECK(test_less_than_or_equal_equal<simd<double, sse>>());

        CHECK(test_less_than_or_equal_equal<simd<float, sse>>());

        CHECK(test_less_than_or_equal_equal<simd<int16_t, sse>>());

        CHECK(test_less_than_or_equal_equal<simd<int32_t, sse>>());

        CHECK(test_less_than_or_equal_equal<simd<int64_t, sse>>());

        CHECK(test_less_than_or_equal_equal<simd<int8_t, sse>>());

        CHECK(test_less_than_or_equal_equal<simd<uint16_t, sse>>());

        CHECK(test_less_than_or_equal_equal<simd<uint32_t, sse>>());

        CHECK(test_less_than_or_equal_equal<simd<uint64_t, sse>>());

        CHECK(test_less_than_or_equal_equal<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'mask_equal' for avx2", "[mask_equal],[avx2]") {
    using namespace tsl;
    SECTION("all_equal") {
        WARN("Primitive mask_equal<simd<double, avx2>> not implemented.");
        WARN("Primitive mask_equal<simd<float, avx2>> not implemented.");
        CHECK(test_mask_equal_all_equal<simd<int16_t, avx2>>());

        CHECK(test_mask_equal_all_equal<simd<int32_t, avx2>>());

        CHECK(test_mask_equal_all_equal<simd<int64_t, avx2>>());

        CHECK(test_mask_equal_all_equal<simd<int8_t, avx2>>());

        CHECK(test_mask_equal_all_equal<simd<uint16_t, avx2>>());

        CHECK(test_mask_equal_all_equal<simd<uint32_t, avx2>>());

        CHECK(test_mask_equal_all_equal<simd<uint64_t, avx2>>());

        CHECK(test_mask_equal_all_equal<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'mask_equal' for avx512", "[mask_equal],[avx512]") {
    using namespace tsl;
    SECTION("all_equal") {
        WARN("Primitive mask_equal not implemented for avx512");
    }
}
TEST_CASE("Testing primitive 'mask_equal' for scalar", "[mask_equal],[scalar]") {
    using namespace tsl;
    SECTION("all_equal") {
        WARN("Primitive mask_equal not implemented for scalar");
    }
}
TEST_CASE("Testing primitive 'mask_equal' for sse", "[mask_equal],[sse]") {
    using namespace tsl;
    SECTION("all_equal") {
        WARN("Primitive mask_equal not implemented for sse");
    }
}

