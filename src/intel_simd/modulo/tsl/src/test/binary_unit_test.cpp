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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/src/test/binary_unit_test.cpp
 * \date 2023-07-22
 * \brief Unit test file for TSL Primitives using Catch2
 * \note
 *
 */

#include <tslintrin.hpp>
#include <cstddef>
#include <climits>
#include <iostream>
#include <algorithm>
#include <limits>
#include <type_traits>
#include "test_functions.hpp"

namespace tsl {
    template<VectorProcessingStyle Vec>
    bool test_lzc_scalar_test_msb() {
        using namespace tsl;
        using T = typename Vec::base_type;
        T data = (T)1 << ((T)sizeof(T)*CHAR_BIT-1);
        return lzc<Vec>(data) == 0;

    }
    template<VectorProcessingStyle Vec>
    bool test_lzc_scalar_test_one() {
        using namespace tsl;
        using T = typename Vec::base_type;
        T data = 1;
        return lzc<Vec>(data) == (sizeof(T)*CHAR_BIT-1);

    }
    template<VectorProcessingStyle Vec>
    bool test_lzc_scalar_test_zero() {
        using namespace tsl;
        using T = typename Vec::base_type;
        T data = 0;
        return lzc<Vec>(data) == (sizeof(T)*CHAR_BIT);

    }
    template<VectorProcessingStyle Vec>
    bool test_binary_and_and_as_compare() {
        using namespace tsl;
        //a & a == a ?
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            std::size_t tester_idx = 0;
            for(size_t j = i; j < i + Vec::vector_element_count(); ++j) {
              reference_result_ptr[tester_idx++] = reference_data_ptr[j];
            }
            auto vec1 = loadu<Vec>( &test_data_ptr[i] );
            auto vec2 = loadu<Vec>( &test_data_ptr[i] );
            auto result = binary_and<Vec>( vec1, vec2 );
            storeu<Vec>( test_result_ptr, result );
            test_helper.synchronize();
            allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_binary_or_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count * 2, Vec::vector_element_count(), false};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            for(size_t j = 0; j < Vec::vector_element_count(); ++j) {
                uint8_t* a = (uint8_t*)&reference_data_ptr[i + j];
                uint8_t* b = (uint8_t*)&reference_data_ptr[element_count + i + j];
                uint8_t* res = (uint8_t*)&reference_result_ptr[j];
                for (int k = 0; k < sizeof(T); k++) res[k] = a[k] | b[k];
            }
            auto vec1 = loadu<Vec>(&reference_data_ptr[i]);
            auto vec2 = loadu<Vec>(&reference_data_ptr[element_count + i]);
            auto result = binary_or<Vec>(vec1, vec2);
            allOk &= test_helper.validate_simd_register(result);
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_binary_xor_xor_as_compare() {
        using namespace tsl;
        //a ^ a == 0 ?
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          std::size_t tester_idx = 0;
          for(size_t j = i; j < i + Vec::vector_element_count(); ++j) {
              reference_result_ptr[tester_idx++] = 0;
          }
          auto vec1 = loadu<Vec>(&test_data_ptr[i]);
          auto vec2 = loadu<Vec>(&test_data_ptr[i]);
          auto result = binary_xor<Vec>(vec1, vec2);
          storeu<Vec>(test_result_ptr, result);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_hor_with_only_one() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{1, false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto vec = set1<Vec>(1);
        *reference_result_ptr = 1;
        *test_result_ptr = hor<Vec>(vec);
        test_helper.synchronize();
        return test_helper.validate();

    }
    template<VectorProcessingStyle Vec>
    bool test_hor_with_only_zero() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{1, false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto vec = set1<Vec>(0);
        *reference_result_ptr = 0;
        *test_result_ptr = hor<Vec>(vec);
        test_helper.synchronize();
        return test_helper.validate();

    }
    template<VectorProcessingStyle Vec>
    bool test_hor_with_rand_values() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, 1, false};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count; i += Vec::vector_element_count()){
          auto vec = loadu<Vec>(&test_data_ptr[i]);
          if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>){
            typename std::conditional<std::is_same_v<T, float>, int32_t,
            typename std::conditional<std::is_same_v<T, double>, int64_t, void>::type>::type result = 0;
            union {
                T val;
                typename std::conditional<std::is_same_v<T, float>, int32_t,
                typename std::conditional<std::is_same_v<T, double>, int64_t, void>::type>::type i_val;
              } u;
            for(size_t j=i; j < i + Vec::vector_element_count(); j++){
              u.val = reference_data_ptr[j];
              result |= u.i_val;
            }
            u.val = hor<Vec>(vec);
            allOk &= (result == u.i_val);
          }
          else{
            std::size_t result = 0;
            for(size_t j=i; j < i + Vec::vector_element_count(); j++){
            result |= reference_data_ptr[j];
            }
            auto vec_result = hor<Vec>(vec);
            * reference_result_ptr = result;
            * test_result_ptr = vec_result;
            test_helper.synchronize();
            allOk &= test_helper.validate();
          }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_inv_with_only_ones() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{Vec::vector_element_count(), false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto vec = set1<Vec>(~0);
        if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>){
          T data[Vec::vector_element_count()];
          storeu<Vec>(data, vec);
          storeu<Vec>(test_result_ptr, inv<Vec>(vec));
          bool allOk = true;
          for(int i = 0; i < Vec::vector_element_count(); i ++){
            union {
              T f_val;
              typename std::conditional<std::is_same_v<T, float>, int32_t,
              typename std::conditional<std::is_same_v<T, double>, int64_t, void>::type>::type i_val;
            } u;
            u.f_val = test_result_ptr[i];
            union {
              T f_val;
              typename std::conditional<std::is_same_v<T, float>, int32_t,
              typename std::conditional<std::is_same_v<T, double>, int64_t, void>::type>::type i_val;
            } v;
            v.f_val = data[i];
            v.i_val = ~v.i_val;
            allOk &= (u.i_val == v.i_val);
          }
          return allOk;
        }
        else{
          storeu<Vec>(reference_result_ptr, ~vec);
          storeu<Vec>(test_result_ptr, inv<Vec>(vec));
          test_helper.synchronize();
          return test_helper.validate();
        }

    }
    template<VectorProcessingStyle Vec>
    bool test_inv_with_only_zero() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{Vec::vector_element_count(), false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto vec = set1<Vec>(0);
        if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>){
          T data[Vec::vector_element_count()];
          storeu<Vec>(data, vec);
          storeu<Vec>(test_result_ptr, inv<Vec>(vec));
          bool allOk = true;
          for(int i = 0; i < Vec::vector_element_count(); i ++){
            union {
              T f_val;
              typename std::conditional<std::is_same_v<T, float>, int32_t,
              typename std::conditional<std::is_same_v<T, double>, int64_t, void>::type>::type i_val;
            } u;
            u.f_val = test_result_ptr[i];
            union {
              T f_val;
              typename std::conditional<std::is_same_v<T, float>, int32_t,
              typename std::conditional<std::is_same_v<T, double>, int64_t, void>::type>::type i_val;
            } v;
            v.f_val = data[i];
            v.i_val = ~v.i_val;
            allOk &= (u.i_val == v.i_val);
          }
          return allOk;
        }
        else{
          storeu<Vec>(reference_result_ptr, ~vec);
          storeu<Vec>(test_result_ptr, inv<Vec>(vec));
          test_helper.synchronize();
          return test_helper.validate();
        }

    }
    template<VectorProcessingStyle Vec>
    bool test_inv_with_rand_values() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count; i += Vec::vector_element_count()){
          auto vec = loadu<Vec>(&test_data_ptr[i]);
          if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>){
            T data[Vec::vector_element_count()];
            storeu<Vec>(data, vec);
            storeu<Vec>(test_result_ptr, inv<Vec>(vec));
            for(int i = 0; i < Vec::vector_element_count(); i ++){
              typename std::conditional<std::is_same_v<T, float>, int32_t,
              typename std::conditional<std::is_same_v<T, double>, int64_t, void>::type>::type test_i_val = 0;
              union {
                T val;
                typename std::conditional<std::is_same_v<T, float>, int32_t,
                typename std::conditional<std::is_same_v<T, double>, int64_t, void>::type>::type i_val;
              } u;
              u.val = test_result_ptr[i];
              test_i_val = u.i_val;

              u.val = data[i];
              allOk &= (~u.i_val == test_i_val);
            }
          }
          else{
            storeu<Vec>(reference_result_ptr, ~vec);
            storeu<Vec>(test_result_ptr, inv<Vec>(vec));
            test_helper.synchronize();
            allOk &= test_helper.validate();
          }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_shift_left_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false, testing::alternate_init<T>};
        bool allOk = true;
        auto ref_data = test_helper.data_ref();
        auto expected_result = test_helper.result_ref();

        auto test_data = test_helper.data_target();
        auto test_result = test_helper.result_target();
        for (size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          for (unsigned shift = 0; shift < sizeof(typename Vec::base_type)*CHAR_BIT; ++shift) {
            for (size_t j = 0; j < Vec::vector_element_count(); ++j) {
              expected_result[j] = ref_data[i+j] << shift;
            }
            auto vec = loadu<Vec>(&test_data[i]);
            storeu<Vec>(test_result, shift_left<Vec>(vec, (typename Vec::base_type)shift));
            test_helper.synchronize();
            allOk &= test_helper.validate();
          }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_shift_left_vector_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false, testing::alternate_init<T>};
        bool allOk = true;
        auto ref_data = test_helper.data_ref();
        auto expected_result = test_helper.result_ref();

        auto test_data = test_helper.data_target();
        auto test_result = test_helper.result_target();
        for (size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          for (unsigned shift = 0; shift < sizeof(typename Vec::base_type)*CHAR_BIT; ++shift) {
            for (size_t j = 0; j < Vec::vector_element_count(); ++j) {
              expected_result[j] = ref_data[i+j] << shift;
            }
            auto vec = loadu<Vec>(&test_data[i]);
            storeu<Vec>(test_result, shift_left<Vec>(vec, set1<Vec>((typename Vec::base_type)shift)));
            test_helper.synchronize();
            allOk &= test_helper.validate();
          }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_shift_right_shift_right_arithmetic() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false, testing::alternate_init<T>};
        bool allOk = true;
        auto ref_data = test_helper.data_ref();
        auto expected_result = test_helper.result_ref();

        auto test_data = test_helper.data_target();
        auto test_result = test_helper.result_target();
        for (size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          for (unsigned shift = 0; shift < sizeof(typename Vec::base_type)*CHAR_BIT; ++shift) {
            for (size_t j = 0; j < Vec::vector_element_count(); ++j) {
              expected_result[j] = ref_data[i+j] >> shift;
            }
            auto vec = loadu<Vec>(&test_data[i]);
            storeu<Vec>(test_result, shift_right<Vec, true>(vec, shift));
            test_helper.synchronize();
            allOk &= test_helper.validate();
          }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_shift_right_shift_right_ignore_sign() {
        using namespace tsl;
        using T = typename Vec::base_type;
        using UT = typename std::make_unsigned_t<T>;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false, testing::alternate_init<T>};
        bool allOk = true;
        auto ref_data = test_helper.data_ref();
        auto expected_result = test_helper.result_ref();

        auto test_data = test_helper.data_target();
        auto test_result = test_helper.result_target();
        for (size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          for (unsigned shift = 0; shift < sizeof(typename Vec::base_type)*CHAR_BIT; ++shift) {
            for (size_t j = 0; j < Vec::vector_element_count(); ++j) {
              expected_result[j] = static_cast<T>(static_cast<UT>(ref_data[i+j]) >> shift);
            }
            auto vec = loadu<Vec>(&test_data[i]);
            storeu<Vec>(test_result, shift_right<Vec, false>(vec, shift));
            test_helper.synchronize();
            allOk &= test_helper.validate();
          }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_shift_right_vector_shift_right_arithmetic() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false, testing::alternate_init<T>};
        bool allOk = true;
        auto ref_data = test_helper.data_ref();
        auto expected_result = test_helper.result_ref();

        auto test_data = test_helper.data_target();
        auto test_result = test_helper.result_target();
        for (size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          for (unsigned shift = 0; shift < sizeof(typename Vec::base_type)*CHAR_BIT; ++shift) {
            for (size_t j = 0; j < Vec::vector_element_count(); ++j) {
              expected_result[j] = ref_data[i+j] >> shift;
            }
            auto vec = loadu<Vec>(&test_data[i]);
            storeu<Vec>(test_result, shift_right<Vec, true>(vec, set1<Vec>(shift)));
            test_helper.synchronize();
            allOk &= test_helper.validate();
          }
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_shift_right_vector_shift_right_ignore_sign() {
        using namespace tsl;
        using T = typename Vec::base_type;
        using UT = typename std::make_unsigned_t<T>;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false, testing::alternate_init<T>};
        bool allOk = true;
        auto ref_data = test_helper.data_ref();
        auto expected_result = test_helper.result_ref();

        auto test_data = test_helper.data_target();
        auto test_result = test_helper.result_target();
        for (size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          for (unsigned shift = 0; shift < sizeof(typename Vec::base_type)*CHAR_BIT; ++shift) {
            for (size_t j = 0; j < Vec::vector_element_count(); ++j) {
              expected_result[j] = static_cast<T>(static_cast<UT>(ref_data[i+j]) >> shift);
            }
            auto vec = loadu<Vec>(&test_data[i]);
            storeu<Vec>(test_result, shift_right<Vec, false>(vec, set1<Vec>(shift)));
            test_helper.synchronize();
            allOk &= test_helper.validate();
          }
        }
        return allOk;

    }
}

TEST_CASE("Testing primitive 'lzc_scalar' for avx2", "[lzc_scalar],[avx2]") {
    using namespace tsl;
    SECTION("test_msb") {
        WARN("Primitive lzc_scalar<simd<double, avx2>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, avx2>> not implemented.");
        CHECK(test_lzc_scalar_test_msb<simd<int16_t, avx2>>());

        CHECK(test_lzc_scalar_test_msb<simd<int32_t, avx2>>());

        CHECK(test_lzc_scalar_test_msb<simd<int64_t, avx2>>());

        CHECK(test_lzc_scalar_test_msb<simd<int8_t, avx2>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint16_t, avx2>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint32_t, avx2>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint64_t, avx2>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint8_t, avx2>>());

    }
    SECTION("test_one") {
        WARN("Primitive lzc_scalar<simd<double, avx2>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, avx2>> not implemented.");
        CHECK(test_lzc_scalar_test_one<simd<int16_t, avx2>>());

        CHECK(test_lzc_scalar_test_one<simd<int32_t, avx2>>());

        CHECK(test_lzc_scalar_test_one<simd<int64_t, avx2>>());

        CHECK(test_lzc_scalar_test_one<simd<int8_t, avx2>>());

        CHECK(test_lzc_scalar_test_one<simd<uint16_t, avx2>>());

        CHECK(test_lzc_scalar_test_one<simd<uint32_t, avx2>>());

        CHECK(test_lzc_scalar_test_one<simd<uint64_t, avx2>>());

        CHECK(test_lzc_scalar_test_one<simd<uint8_t, avx2>>());

    }
    SECTION("test_zero") {
        WARN("Primitive lzc_scalar<simd<double, avx2>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, avx2>> not implemented.");
        CHECK(test_lzc_scalar_test_zero<simd<int16_t, avx2>>());

        CHECK(test_lzc_scalar_test_zero<simd<int32_t, avx2>>());

        CHECK(test_lzc_scalar_test_zero<simd<int64_t, avx2>>());

        CHECK(test_lzc_scalar_test_zero<simd<int8_t, avx2>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint16_t, avx2>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint32_t, avx2>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint64_t, avx2>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'lzc_scalar' for avx512", "[lzc_scalar],[avx512]") {
    using namespace tsl;
    SECTION("test_msb") {
        WARN("Primitive lzc_scalar<simd<double, avx512>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, avx512>> not implemented.");
        CHECK(test_lzc_scalar_test_msb<simd<int16_t, avx512>>());

        CHECK(test_lzc_scalar_test_msb<simd<int32_t, avx512>>());

        CHECK(test_lzc_scalar_test_msb<simd<int64_t, avx512>>());

        CHECK(test_lzc_scalar_test_msb<simd<int8_t, avx512>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint16_t, avx512>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint32_t, avx512>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint64_t, avx512>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint8_t, avx512>>());

    }
    SECTION("test_one") {
        WARN("Primitive lzc_scalar<simd<double, avx512>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, avx512>> not implemented.");
        CHECK(test_lzc_scalar_test_one<simd<int16_t, avx512>>());

        CHECK(test_lzc_scalar_test_one<simd<int32_t, avx512>>());

        CHECK(test_lzc_scalar_test_one<simd<int64_t, avx512>>());

        CHECK(test_lzc_scalar_test_one<simd<int8_t, avx512>>());

        CHECK(test_lzc_scalar_test_one<simd<uint16_t, avx512>>());

        CHECK(test_lzc_scalar_test_one<simd<uint32_t, avx512>>());

        CHECK(test_lzc_scalar_test_one<simd<uint64_t, avx512>>());

        CHECK(test_lzc_scalar_test_one<simd<uint8_t, avx512>>());

    }
    SECTION("test_zero") {
        WARN("Primitive lzc_scalar<simd<double, avx512>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, avx512>> not implemented.");
        CHECK(test_lzc_scalar_test_zero<simd<int16_t, avx512>>());

        CHECK(test_lzc_scalar_test_zero<simd<int32_t, avx512>>());

        CHECK(test_lzc_scalar_test_zero<simd<int64_t, avx512>>());

        CHECK(test_lzc_scalar_test_zero<simd<int8_t, avx512>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint16_t, avx512>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint32_t, avx512>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint64_t, avx512>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'lzc_scalar' for scalar", "[lzc_scalar],[scalar]") {
    using namespace tsl;
    SECTION("test_msb") {
        WARN("Primitive lzc_scalar<simd<double, scalar>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, scalar>> not implemented.");
        CHECK(test_lzc_scalar_test_msb<simd<int16_t, scalar>>());

        CHECK(test_lzc_scalar_test_msb<simd<int32_t, scalar>>());

        CHECK(test_lzc_scalar_test_msb<simd<int64_t, scalar>>());

        CHECK(test_lzc_scalar_test_msb<simd<int8_t, scalar>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint16_t, scalar>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint32_t, scalar>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint64_t, scalar>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint8_t, scalar>>());

    }
    SECTION("test_one") {
        WARN("Primitive lzc_scalar<simd<double, scalar>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, scalar>> not implemented.");
        CHECK(test_lzc_scalar_test_one<simd<int16_t, scalar>>());

        CHECK(test_lzc_scalar_test_one<simd<int32_t, scalar>>());

        CHECK(test_lzc_scalar_test_one<simd<int64_t, scalar>>());

        CHECK(test_lzc_scalar_test_one<simd<int8_t, scalar>>());

        CHECK(test_lzc_scalar_test_one<simd<uint16_t, scalar>>());

        CHECK(test_lzc_scalar_test_one<simd<uint32_t, scalar>>());

        CHECK(test_lzc_scalar_test_one<simd<uint64_t, scalar>>());

        CHECK(test_lzc_scalar_test_one<simd<uint8_t, scalar>>());

    }
    SECTION("test_zero") {
        WARN("Primitive lzc_scalar<simd<double, scalar>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, scalar>> not implemented.");
        CHECK(test_lzc_scalar_test_zero<simd<int16_t, scalar>>());

        CHECK(test_lzc_scalar_test_zero<simd<int32_t, scalar>>());

        CHECK(test_lzc_scalar_test_zero<simd<int64_t, scalar>>());

        CHECK(test_lzc_scalar_test_zero<simd<int8_t, scalar>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint16_t, scalar>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint32_t, scalar>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint64_t, scalar>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'lzc_scalar' for sse", "[lzc_scalar],[sse]") {
    using namespace tsl;
    SECTION("test_msb") {
        WARN("Primitive lzc_scalar<simd<double, sse>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, sse>> not implemented.");
        CHECK(test_lzc_scalar_test_msb<simd<int16_t, sse>>());

        CHECK(test_lzc_scalar_test_msb<simd<int32_t, sse>>());

        CHECK(test_lzc_scalar_test_msb<simd<int64_t, sse>>());

        CHECK(test_lzc_scalar_test_msb<simd<int8_t, sse>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint16_t, sse>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint32_t, sse>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint64_t, sse>>());

        CHECK(test_lzc_scalar_test_msb<simd<uint8_t, sse>>());

    }
    SECTION("test_one") {
        WARN("Primitive lzc_scalar<simd<double, sse>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, sse>> not implemented.");
        CHECK(test_lzc_scalar_test_one<simd<int16_t, sse>>());

        CHECK(test_lzc_scalar_test_one<simd<int32_t, sse>>());

        CHECK(test_lzc_scalar_test_one<simd<int64_t, sse>>());

        CHECK(test_lzc_scalar_test_one<simd<int8_t, sse>>());

        CHECK(test_lzc_scalar_test_one<simd<uint16_t, sse>>());

        CHECK(test_lzc_scalar_test_one<simd<uint32_t, sse>>());

        CHECK(test_lzc_scalar_test_one<simd<uint64_t, sse>>());

        CHECK(test_lzc_scalar_test_one<simd<uint8_t, sse>>());

    }
    SECTION("test_zero") {
        WARN("Primitive lzc_scalar<simd<double, sse>> not implemented.");
        WARN("Primitive lzc_scalar<simd<float, sse>> not implemented.");
        CHECK(test_lzc_scalar_test_zero<simd<int16_t, sse>>());

        CHECK(test_lzc_scalar_test_zero<simd<int32_t, sse>>());

        CHECK(test_lzc_scalar_test_zero<simd<int64_t, sse>>());

        CHECK(test_lzc_scalar_test_zero<simd<int8_t, sse>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint16_t, sse>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint32_t, sse>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint64_t, sse>>());

        CHECK(test_lzc_scalar_test_zero<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'binary_and' for avx2", "[binary_and],[avx2]") {
    using namespace tsl;
    SECTION("and_as_compare") {
        CHECK(test_binary_and_and_as_compare<simd<double, avx2>>());

        CHECK(test_binary_and_and_as_compare<simd<float, avx2>>());

        CHECK(test_binary_and_and_as_compare<simd<int16_t, avx2>>());

        CHECK(test_binary_and_and_as_compare<simd<int32_t, avx2>>());

        CHECK(test_binary_and_and_as_compare<simd<int64_t, avx2>>());

        CHECK(test_binary_and_and_as_compare<simd<int8_t, avx2>>());

        CHECK(test_binary_and_and_as_compare<simd<uint16_t, avx2>>());

        CHECK(test_binary_and_and_as_compare<simd<uint32_t, avx2>>());

        CHECK(test_binary_and_and_as_compare<simd<uint64_t, avx2>>());

        CHECK(test_binary_and_and_as_compare<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'binary_and' for avx512", "[binary_and],[avx512]") {
    using namespace tsl;
    SECTION("and_as_compare") {
        CHECK(test_binary_and_and_as_compare<simd<double, avx512>>());

        CHECK(test_binary_and_and_as_compare<simd<float, avx512>>());

        CHECK(test_binary_and_and_as_compare<simd<int16_t, avx512>>());

        CHECK(test_binary_and_and_as_compare<simd<int32_t, avx512>>());

        CHECK(test_binary_and_and_as_compare<simd<int64_t, avx512>>());

        CHECK(test_binary_and_and_as_compare<simd<int8_t, avx512>>());

        CHECK(test_binary_and_and_as_compare<simd<uint16_t, avx512>>());

        CHECK(test_binary_and_and_as_compare<simd<uint32_t, avx512>>());

        CHECK(test_binary_and_and_as_compare<simd<uint64_t, avx512>>());

        CHECK(test_binary_and_and_as_compare<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'binary_and' for scalar", "[binary_and],[scalar]") {
    using namespace tsl;
    SECTION("and_as_compare") {
        CHECK(test_binary_and_and_as_compare<simd<double, scalar>>());

        CHECK(test_binary_and_and_as_compare<simd<float, scalar>>());

        CHECK(test_binary_and_and_as_compare<simd<int16_t, scalar>>());

        CHECK(test_binary_and_and_as_compare<simd<int32_t, scalar>>());

        CHECK(test_binary_and_and_as_compare<simd<int64_t, scalar>>());

        CHECK(test_binary_and_and_as_compare<simd<int8_t, scalar>>());

        CHECK(test_binary_and_and_as_compare<simd<uint16_t, scalar>>());

        CHECK(test_binary_and_and_as_compare<simd<uint32_t, scalar>>());

        CHECK(test_binary_and_and_as_compare<simd<uint64_t, scalar>>());

        CHECK(test_binary_and_and_as_compare<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'binary_and' for sse", "[binary_and],[sse]") {
    using namespace tsl;
    SECTION("and_as_compare") {
        CHECK(test_binary_and_and_as_compare<simd<double, sse>>());

        CHECK(test_binary_and_and_as_compare<simd<float, sse>>());

        CHECK(test_binary_and_and_as_compare<simd<int16_t, sse>>());

        CHECK(test_binary_and_and_as_compare<simd<int32_t, sse>>());

        CHECK(test_binary_and_and_as_compare<simd<int64_t, sse>>());

        CHECK(test_binary_and_and_as_compare<simd<int8_t, sse>>());

        CHECK(test_binary_and_and_as_compare<simd<uint16_t, sse>>());

        CHECK(test_binary_and_and_as_compare<simd<uint32_t, sse>>());

        CHECK(test_binary_and_and_as_compare<simd<uint64_t, sse>>());

        CHECK(test_binary_and_and_as_compare<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'binary_or' for avx2", "[binary_or],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_binary_or_default<simd<double, avx2>>());

        CHECK(test_binary_or_default<simd<float, avx2>>());

        CHECK(test_binary_or_default<simd<int16_t, avx2>>());

        CHECK(test_binary_or_default<simd<int32_t, avx2>>());

        CHECK(test_binary_or_default<simd<int64_t, avx2>>());

        CHECK(test_binary_or_default<simd<int8_t, avx2>>());

        CHECK(test_binary_or_default<simd<uint16_t, avx2>>());

        CHECK(test_binary_or_default<simd<uint32_t, avx2>>());

        CHECK(test_binary_or_default<simd<uint64_t, avx2>>());

        CHECK(test_binary_or_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'binary_or' for avx512", "[binary_or],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_binary_or_default<simd<double, avx512>>());

        CHECK(test_binary_or_default<simd<float, avx512>>());

        CHECK(test_binary_or_default<simd<int16_t, avx512>>());

        CHECK(test_binary_or_default<simd<int32_t, avx512>>());

        CHECK(test_binary_or_default<simd<int64_t, avx512>>());

        CHECK(test_binary_or_default<simd<int8_t, avx512>>());

        CHECK(test_binary_or_default<simd<uint16_t, avx512>>());

        CHECK(test_binary_or_default<simd<uint32_t, avx512>>());

        CHECK(test_binary_or_default<simd<uint64_t, avx512>>());

        CHECK(test_binary_or_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'binary_or' for scalar", "[binary_or],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_binary_or_default<simd<double, scalar>>());

        CHECK(test_binary_or_default<simd<float, scalar>>());

        CHECK(test_binary_or_default<simd<int16_t, scalar>>());

        CHECK(test_binary_or_default<simd<int32_t, scalar>>());

        CHECK(test_binary_or_default<simd<int64_t, scalar>>());

        CHECK(test_binary_or_default<simd<int8_t, scalar>>());

        CHECK(test_binary_or_default<simd<uint16_t, scalar>>());

        CHECK(test_binary_or_default<simd<uint32_t, scalar>>());

        CHECK(test_binary_or_default<simd<uint64_t, scalar>>());

        CHECK(test_binary_or_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'binary_or' for sse", "[binary_or],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_binary_or_default<simd<double, sse>>());

        CHECK(test_binary_or_default<simd<float, sse>>());

        CHECK(test_binary_or_default<simd<int16_t, sse>>());

        CHECK(test_binary_or_default<simd<int32_t, sse>>());

        CHECK(test_binary_or_default<simd<int64_t, sse>>());

        CHECK(test_binary_or_default<simd<int8_t, sse>>());

        CHECK(test_binary_or_default<simd<uint16_t, sse>>());

        CHECK(test_binary_or_default<simd<uint32_t, sse>>());

        CHECK(test_binary_or_default<simd<uint64_t, sse>>());

        CHECK(test_binary_or_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'binary_xor' for avx2", "[binary_xor],[avx2]") {
    using namespace tsl;
    SECTION("xor_as_compare") {
        CHECK(test_binary_xor_xor_as_compare<simd<double, avx2>>());

        CHECK(test_binary_xor_xor_as_compare<simd<float, avx2>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int16_t, avx2>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int32_t, avx2>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int64_t, avx2>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int8_t, avx2>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint16_t, avx2>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint32_t, avx2>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint64_t, avx2>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'binary_xor' for avx512", "[binary_xor],[avx512]") {
    using namespace tsl;
    SECTION("xor_as_compare") {
        CHECK(test_binary_xor_xor_as_compare<simd<double, avx512>>());

        CHECK(test_binary_xor_xor_as_compare<simd<float, avx512>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int16_t, avx512>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int32_t, avx512>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int64_t, avx512>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int8_t, avx512>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint16_t, avx512>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint32_t, avx512>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint64_t, avx512>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'binary_xor' for scalar", "[binary_xor],[scalar]") {
    using namespace tsl;
    SECTION("xor_as_compare") {
        CHECK(test_binary_xor_xor_as_compare<simd<double, scalar>>());

        CHECK(test_binary_xor_xor_as_compare<simd<float, scalar>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int16_t, scalar>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int32_t, scalar>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int64_t, scalar>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int8_t, scalar>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint16_t, scalar>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint32_t, scalar>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint64_t, scalar>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'binary_xor' for sse", "[binary_xor],[sse]") {
    using namespace tsl;
    SECTION("xor_as_compare") {
        CHECK(test_binary_xor_xor_as_compare<simd<double, sse>>());

        CHECK(test_binary_xor_xor_as_compare<simd<float, sse>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int16_t, sse>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int32_t, sse>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int64_t, sse>>());

        CHECK(test_binary_xor_xor_as_compare<simd<int8_t, sse>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint16_t, sse>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint32_t, sse>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint64_t, sse>>());

        CHECK(test_binary_xor_xor_as_compare<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'hor' for avx2", "[hor],[avx2]") {
    using namespace tsl;
    SECTION("with_only_one") {
        CHECK(test_hor_with_only_one<simd<double, avx2>>());

        CHECK(test_hor_with_only_one<simd<float, avx2>>());

        CHECK(test_hor_with_only_one<simd<int16_t, avx2>>());

        CHECK(test_hor_with_only_one<simd<int32_t, avx2>>());

        CHECK(test_hor_with_only_one<simd<int64_t, avx2>>());

        CHECK(test_hor_with_only_one<simd<int8_t, avx2>>());

        CHECK(test_hor_with_only_one<simd<uint16_t, avx2>>());

        CHECK(test_hor_with_only_one<simd<uint32_t, avx2>>());

        CHECK(test_hor_with_only_one<simd<uint64_t, avx2>>());

        CHECK(test_hor_with_only_one<simd<uint8_t, avx2>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_hor_with_only_zero<simd<double, avx2>>());

        CHECK(test_hor_with_only_zero<simd<float, avx2>>());

        CHECK(test_hor_with_only_zero<simd<int16_t, avx2>>());

        CHECK(test_hor_with_only_zero<simd<int32_t, avx2>>());

        CHECK(test_hor_with_only_zero<simd<int64_t, avx2>>());

        CHECK(test_hor_with_only_zero<simd<int8_t, avx2>>());

        CHECK(test_hor_with_only_zero<simd<uint16_t, avx2>>());

        CHECK(test_hor_with_only_zero<simd<uint32_t, avx2>>());

        CHECK(test_hor_with_only_zero<simd<uint64_t, avx2>>());

        CHECK(test_hor_with_only_zero<simd<uint8_t, avx2>>());

    }
    SECTION("with_rand_values") {
        CHECK(test_hor_with_rand_values<simd<double, avx2>>());

        CHECK(test_hor_with_rand_values<simd<float, avx2>>());

        CHECK(test_hor_with_rand_values<simd<int16_t, avx2>>());

        CHECK(test_hor_with_rand_values<simd<int32_t, avx2>>());

        CHECK(test_hor_with_rand_values<simd<int64_t, avx2>>());

        CHECK(test_hor_with_rand_values<simd<int8_t, avx2>>());

        CHECK(test_hor_with_rand_values<simd<uint16_t, avx2>>());

        CHECK(test_hor_with_rand_values<simd<uint32_t, avx2>>());

        CHECK(test_hor_with_rand_values<simd<uint64_t, avx2>>());

        CHECK(test_hor_with_rand_values<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'hor' for avx512", "[hor],[avx512]") {
    using namespace tsl;
    SECTION("with_only_one") {
        CHECK(test_hor_with_only_one<simd<double, avx512>>());

        CHECK(test_hor_with_only_one<simd<float, avx512>>());

        CHECK(test_hor_with_only_one<simd<int16_t, avx512>>());

        CHECK(test_hor_with_only_one<simd<int32_t, avx512>>());

        CHECK(test_hor_with_only_one<simd<int64_t, avx512>>());

        CHECK(test_hor_with_only_one<simd<int8_t, avx512>>());

        CHECK(test_hor_with_only_one<simd<uint16_t, avx512>>());

        CHECK(test_hor_with_only_one<simd<uint32_t, avx512>>());

        CHECK(test_hor_with_only_one<simd<uint64_t, avx512>>());

        CHECK(test_hor_with_only_one<simd<uint8_t, avx512>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_hor_with_only_zero<simd<double, avx512>>());

        CHECK(test_hor_with_only_zero<simd<float, avx512>>());

        CHECK(test_hor_with_only_zero<simd<int16_t, avx512>>());

        CHECK(test_hor_with_only_zero<simd<int32_t, avx512>>());

        CHECK(test_hor_with_only_zero<simd<int64_t, avx512>>());

        CHECK(test_hor_with_only_zero<simd<int8_t, avx512>>());

        CHECK(test_hor_with_only_zero<simd<uint16_t, avx512>>());

        CHECK(test_hor_with_only_zero<simd<uint32_t, avx512>>());

        CHECK(test_hor_with_only_zero<simd<uint64_t, avx512>>());

        CHECK(test_hor_with_only_zero<simd<uint8_t, avx512>>());

    }
    SECTION("with_rand_values") {
        CHECK(test_hor_with_rand_values<simd<double, avx512>>());

        CHECK(test_hor_with_rand_values<simd<float, avx512>>());

        CHECK(test_hor_with_rand_values<simd<int16_t, avx512>>());

        CHECK(test_hor_with_rand_values<simd<int32_t, avx512>>());

        CHECK(test_hor_with_rand_values<simd<int64_t, avx512>>());

        CHECK(test_hor_with_rand_values<simd<int8_t, avx512>>());

        CHECK(test_hor_with_rand_values<simd<uint16_t, avx512>>());

        CHECK(test_hor_with_rand_values<simd<uint32_t, avx512>>());

        CHECK(test_hor_with_rand_values<simd<uint64_t, avx512>>());

        CHECK(test_hor_with_rand_values<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'hor' for scalar", "[hor],[scalar]") {
    using namespace tsl;
    SECTION("with_only_one") {
        CHECK(test_hor_with_only_one<simd<double, scalar>>());

        CHECK(test_hor_with_only_one<simd<float, scalar>>());

        CHECK(test_hor_with_only_one<simd<int16_t, scalar>>());

        CHECK(test_hor_with_only_one<simd<int32_t, scalar>>());

        CHECK(test_hor_with_only_one<simd<int64_t, scalar>>());

        CHECK(test_hor_with_only_one<simd<int8_t, scalar>>());

        CHECK(test_hor_with_only_one<simd<uint16_t, scalar>>());

        CHECK(test_hor_with_only_one<simd<uint32_t, scalar>>());

        CHECK(test_hor_with_only_one<simd<uint64_t, scalar>>());

        CHECK(test_hor_with_only_one<simd<uint8_t, scalar>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_hor_with_only_zero<simd<double, scalar>>());

        CHECK(test_hor_with_only_zero<simd<float, scalar>>());

        CHECK(test_hor_with_only_zero<simd<int16_t, scalar>>());

        CHECK(test_hor_with_only_zero<simd<int32_t, scalar>>());

        CHECK(test_hor_with_only_zero<simd<int64_t, scalar>>());

        CHECK(test_hor_with_only_zero<simd<int8_t, scalar>>());

        CHECK(test_hor_with_only_zero<simd<uint16_t, scalar>>());

        CHECK(test_hor_with_only_zero<simd<uint32_t, scalar>>());

        CHECK(test_hor_with_only_zero<simd<uint64_t, scalar>>());

        CHECK(test_hor_with_only_zero<simd<uint8_t, scalar>>());

    }
    SECTION("with_rand_values") {
        CHECK(test_hor_with_rand_values<simd<double, scalar>>());

        CHECK(test_hor_with_rand_values<simd<float, scalar>>());

        CHECK(test_hor_with_rand_values<simd<int16_t, scalar>>());

        CHECK(test_hor_with_rand_values<simd<int32_t, scalar>>());

        CHECK(test_hor_with_rand_values<simd<int64_t, scalar>>());

        CHECK(test_hor_with_rand_values<simd<int8_t, scalar>>());

        CHECK(test_hor_with_rand_values<simd<uint16_t, scalar>>());

        CHECK(test_hor_with_rand_values<simd<uint32_t, scalar>>());

        CHECK(test_hor_with_rand_values<simd<uint64_t, scalar>>());

        CHECK(test_hor_with_rand_values<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'hor' for sse", "[hor],[sse]") {
    using namespace tsl;
    SECTION("with_only_one") {
        CHECK(test_hor_with_only_one<simd<double, sse>>());

        CHECK(test_hor_with_only_one<simd<float, sse>>());

        CHECK(test_hor_with_only_one<simd<int16_t, sse>>());

        CHECK(test_hor_with_only_one<simd<int32_t, sse>>());

        CHECK(test_hor_with_only_one<simd<int64_t, sse>>());

        CHECK(test_hor_with_only_one<simd<int8_t, sse>>());

        CHECK(test_hor_with_only_one<simd<uint16_t, sse>>());

        CHECK(test_hor_with_only_one<simd<uint32_t, sse>>());

        CHECK(test_hor_with_only_one<simd<uint64_t, sse>>());

        CHECK(test_hor_with_only_one<simd<uint8_t, sse>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_hor_with_only_zero<simd<double, sse>>());

        CHECK(test_hor_with_only_zero<simd<float, sse>>());

        CHECK(test_hor_with_only_zero<simd<int16_t, sse>>());

        CHECK(test_hor_with_only_zero<simd<int32_t, sse>>());

        CHECK(test_hor_with_only_zero<simd<int64_t, sse>>());

        CHECK(test_hor_with_only_zero<simd<int8_t, sse>>());

        CHECK(test_hor_with_only_zero<simd<uint16_t, sse>>());

        CHECK(test_hor_with_only_zero<simd<uint32_t, sse>>());

        CHECK(test_hor_with_only_zero<simd<uint64_t, sse>>());

        CHECK(test_hor_with_only_zero<simd<uint8_t, sse>>());

    }
    SECTION("with_rand_values") {
        CHECK(test_hor_with_rand_values<simd<double, sse>>());

        CHECK(test_hor_with_rand_values<simd<float, sse>>());

        CHECK(test_hor_with_rand_values<simd<int16_t, sse>>());

        CHECK(test_hor_with_rand_values<simd<int32_t, sse>>());

        CHECK(test_hor_with_rand_values<simd<int64_t, sse>>());

        CHECK(test_hor_with_rand_values<simd<int8_t, sse>>());

        CHECK(test_hor_with_rand_values<simd<uint16_t, sse>>());

        CHECK(test_hor_with_rand_values<simd<uint32_t, sse>>());

        CHECK(test_hor_with_rand_values<simd<uint64_t, sse>>());

        CHECK(test_hor_with_rand_values<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'inv' for avx2", "[inv],[avx2]") {
    using namespace tsl;
    SECTION("with_only_ones") {
        CHECK(test_inv_with_only_ones<simd<double, avx2>>());

        CHECK(test_inv_with_only_ones<simd<float, avx2>>());

        CHECK(test_inv_with_only_ones<simd<int16_t, avx2>>());

        CHECK(test_inv_with_only_ones<simd<int32_t, avx2>>());

        CHECK(test_inv_with_only_ones<simd<int64_t, avx2>>());

        CHECK(test_inv_with_only_ones<simd<int8_t, avx2>>());

        CHECK(test_inv_with_only_ones<simd<uint16_t, avx2>>());

        CHECK(test_inv_with_only_ones<simd<uint32_t, avx2>>());

        CHECK(test_inv_with_only_ones<simd<uint64_t, avx2>>());

        CHECK(test_inv_with_only_ones<simd<uint8_t, avx2>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_inv_with_only_zero<simd<double, avx2>>());

        CHECK(test_inv_with_only_zero<simd<float, avx2>>());

        CHECK(test_inv_with_only_zero<simd<int16_t, avx2>>());

        CHECK(test_inv_with_only_zero<simd<int32_t, avx2>>());

        CHECK(test_inv_with_only_zero<simd<int64_t, avx2>>());

        CHECK(test_inv_with_only_zero<simd<int8_t, avx2>>());

        CHECK(test_inv_with_only_zero<simd<uint16_t, avx2>>());

        CHECK(test_inv_with_only_zero<simd<uint32_t, avx2>>());

        CHECK(test_inv_with_only_zero<simd<uint64_t, avx2>>());

        CHECK(test_inv_with_only_zero<simd<uint8_t, avx2>>());

    }
    SECTION("with_rand_values") {
        CHECK(test_inv_with_rand_values<simd<double, avx2>>());

        CHECK(test_inv_with_rand_values<simd<float, avx2>>());

        CHECK(test_inv_with_rand_values<simd<int16_t, avx2>>());

        CHECK(test_inv_with_rand_values<simd<int32_t, avx2>>());

        CHECK(test_inv_with_rand_values<simd<int64_t, avx2>>());

        CHECK(test_inv_with_rand_values<simd<int8_t, avx2>>());

        CHECK(test_inv_with_rand_values<simd<uint16_t, avx2>>());

        CHECK(test_inv_with_rand_values<simd<uint32_t, avx2>>());

        CHECK(test_inv_with_rand_values<simd<uint64_t, avx2>>());

        CHECK(test_inv_with_rand_values<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'inv' for avx512", "[inv],[avx512]") {
    using namespace tsl;
    SECTION("with_only_ones") {
        CHECK(test_inv_with_only_ones<simd<double, avx512>>());

        CHECK(test_inv_with_only_ones<simd<float, avx512>>());

        CHECK(test_inv_with_only_ones<simd<int16_t, avx512>>());

        CHECK(test_inv_with_only_ones<simd<int32_t, avx512>>());

        CHECK(test_inv_with_only_ones<simd<int64_t, avx512>>());

        CHECK(test_inv_with_only_ones<simd<int8_t, avx512>>());

        CHECK(test_inv_with_only_ones<simd<uint16_t, avx512>>());

        CHECK(test_inv_with_only_ones<simd<uint32_t, avx512>>());

        CHECK(test_inv_with_only_ones<simd<uint64_t, avx512>>());

        CHECK(test_inv_with_only_ones<simd<uint8_t, avx512>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_inv_with_only_zero<simd<double, avx512>>());

        CHECK(test_inv_with_only_zero<simd<float, avx512>>());

        CHECK(test_inv_with_only_zero<simd<int16_t, avx512>>());

        CHECK(test_inv_with_only_zero<simd<int32_t, avx512>>());

        CHECK(test_inv_with_only_zero<simd<int64_t, avx512>>());

        CHECK(test_inv_with_only_zero<simd<int8_t, avx512>>());

        CHECK(test_inv_with_only_zero<simd<uint16_t, avx512>>());

        CHECK(test_inv_with_only_zero<simd<uint32_t, avx512>>());

        CHECK(test_inv_with_only_zero<simd<uint64_t, avx512>>());

        CHECK(test_inv_with_only_zero<simd<uint8_t, avx512>>());

    }
    SECTION("with_rand_values") {
        CHECK(test_inv_with_rand_values<simd<double, avx512>>());

        CHECK(test_inv_with_rand_values<simd<float, avx512>>());

        CHECK(test_inv_with_rand_values<simd<int16_t, avx512>>());

        CHECK(test_inv_with_rand_values<simd<int32_t, avx512>>());

        CHECK(test_inv_with_rand_values<simd<int64_t, avx512>>());

        CHECK(test_inv_with_rand_values<simd<int8_t, avx512>>());

        CHECK(test_inv_with_rand_values<simd<uint16_t, avx512>>());

        CHECK(test_inv_with_rand_values<simd<uint32_t, avx512>>());

        CHECK(test_inv_with_rand_values<simd<uint64_t, avx512>>());

        CHECK(test_inv_with_rand_values<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'inv' for scalar", "[inv],[scalar]") {
    using namespace tsl;
    SECTION("with_only_ones") {
        CHECK(test_inv_with_only_ones<simd<double, scalar>>());

        CHECK(test_inv_with_only_ones<simd<float, scalar>>());

        CHECK(test_inv_with_only_ones<simd<int16_t, scalar>>());

        CHECK(test_inv_with_only_ones<simd<int32_t, scalar>>());

        CHECK(test_inv_with_only_ones<simd<int64_t, scalar>>());

        CHECK(test_inv_with_only_ones<simd<int8_t, scalar>>());

        CHECK(test_inv_with_only_ones<simd<uint16_t, scalar>>());

        CHECK(test_inv_with_only_ones<simd<uint32_t, scalar>>());

        CHECK(test_inv_with_only_ones<simd<uint64_t, scalar>>());

        CHECK(test_inv_with_only_ones<simd<uint8_t, scalar>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_inv_with_only_zero<simd<double, scalar>>());

        CHECK(test_inv_with_only_zero<simd<float, scalar>>());

        CHECK(test_inv_with_only_zero<simd<int16_t, scalar>>());

        CHECK(test_inv_with_only_zero<simd<int32_t, scalar>>());

        CHECK(test_inv_with_only_zero<simd<int64_t, scalar>>());

        CHECK(test_inv_with_only_zero<simd<int8_t, scalar>>());

        CHECK(test_inv_with_only_zero<simd<uint16_t, scalar>>());

        CHECK(test_inv_with_only_zero<simd<uint32_t, scalar>>());

        CHECK(test_inv_with_only_zero<simd<uint64_t, scalar>>());

        CHECK(test_inv_with_only_zero<simd<uint8_t, scalar>>());

    }
    SECTION("with_rand_values") {
        CHECK(test_inv_with_rand_values<simd<double, scalar>>());

        CHECK(test_inv_with_rand_values<simd<float, scalar>>());

        CHECK(test_inv_with_rand_values<simd<int16_t, scalar>>());

        CHECK(test_inv_with_rand_values<simd<int32_t, scalar>>());

        CHECK(test_inv_with_rand_values<simd<int64_t, scalar>>());

        CHECK(test_inv_with_rand_values<simd<int8_t, scalar>>());

        CHECK(test_inv_with_rand_values<simd<uint16_t, scalar>>());

        CHECK(test_inv_with_rand_values<simd<uint32_t, scalar>>());

        CHECK(test_inv_with_rand_values<simd<uint64_t, scalar>>());

        CHECK(test_inv_with_rand_values<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'inv' for sse", "[inv],[sse]") {
    using namespace tsl;
    SECTION("with_only_ones") {
        CHECK(test_inv_with_only_ones<simd<double, sse>>());

        CHECK(test_inv_with_only_ones<simd<float, sse>>());

        CHECK(test_inv_with_only_ones<simd<int16_t, sse>>());

        CHECK(test_inv_with_only_ones<simd<int32_t, sse>>());

        CHECK(test_inv_with_only_ones<simd<int64_t, sse>>());

        CHECK(test_inv_with_only_ones<simd<int8_t, sse>>());

        CHECK(test_inv_with_only_ones<simd<uint16_t, sse>>());

        CHECK(test_inv_with_only_ones<simd<uint32_t, sse>>());

        CHECK(test_inv_with_only_ones<simd<uint64_t, sse>>());

        CHECK(test_inv_with_only_ones<simd<uint8_t, sse>>());

    }
    SECTION("with_only_zero") {
        CHECK(test_inv_with_only_zero<simd<double, sse>>());

        CHECK(test_inv_with_only_zero<simd<float, sse>>());

        CHECK(test_inv_with_only_zero<simd<int16_t, sse>>());

        CHECK(test_inv_with_only_zero<simd<int32_t, sse>>());

        CHECK(test_inv_with_only_zero<simd<int64_t, sse>>());

        CHECK(test_inv_with_only_zero<simd<int8_t, sse>>());

        CHECK(test_inv_with_only_zero<simd<uint16_t, sse>>());

        CHECK(test_inv_with_only_zero<simd<uint32_t, sse>>());

        CHECK(test_inv_with_only_zero<simd<uint64_t, sse>>());

        CHECK(test_inv_with_only_zero<simd<uint8_t, sse>>());

    }
    SECTION("with_rand_values") {
        CHECK(test_inv_with_rand_values<simd<double, sse>>());

        CHECK(test_inv_with_rand_values<simd<float, sse>>());

        CHECK(test_inv_with_rand_values<simd<int16_t, sse>>());

        CHECK(test_inv_with_rand_values<simd<int32_t, sse>>());

        CHECK(test_inv_with_rand_values<simd<int64_t, sse>>());

        CHECK(test_inv_with_rand_values<simd<int8_t, sse>>());

        CHECK(test_inv_with_rand_values<simd<uint16_t, sse>>());

        CHECK(test_inv_with_rand_values<simd<uint32_t, sse>>());

        CHECK(test_inv_with_rand_values<simd<uint64_t, sse>>());

        CHECK(test_inv_with_rand_values<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'shift_left' for avx2", "[shift_left],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive shift_left<simd<double, avx2>> not implemented.");
        WARN("Primitive shift_left<simd<float, avx2>> not implemented.");
        CHECK(test_shift_left_default<simd<int16_t, avx2>>());

        CHECK(test_shift_left_default<simd<int32_t, avx2>>());

        CHECK(test_shift_left_default<simd<int64_t, avx2>>());

        WARN("Primitive shift_left<simd<int8_t, avx2>> not implemented.");
        CHECK(test_shift_left_default<simd<uint16_t, avx2>>());

        CHECK(test_shift_left_default<simd<uint32_t, avx2>>());

        CHECK(test_shift_left_default<simd<uint64_t, avx2>>());

        WARN("Primitive shift_left<simd<uint8_t, avx2>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'shift_left' for avx512", "[shift_left],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive shift_left<simd<double, avx512>> not implemented.");
        WARN("Primitive shift_left<simd<float, avx512>> not implemented.");
        CHECK(test_shift_left_default<simd<int16_t, avx512>>());

        CHECK(test_shift_left_default<simd<int32_t, avx512>>());

        CHECK(test_shift_left_default<simd<int64_t, avx512>>());

        WARN("Primitive shift_left<simd<int8_t, avx512>> not implemented.");
        CHECK(test_shift_left_default<simd<uint16_t, avx512>>());

        CHECK(test_shift_left_default<simd<uint32_t, avx512>>());

        CHECK(test_shift_left_default<simd<uint64_t, avx512>>());

        WARN("Primitive shift_left<simd<uint8_t, avx512>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'shift_left' for scalar", "[shift_left],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive shift_left<simd<double, scalar>> not implemented.");
        WARN("Primitive shift_left<simd<float, scalar>> not implemented.");
        CHECK(test_shift_left_default<simd<int16_t, scalar>>());

        CHECK(test_shift_left_default<simd<int32_t, scalar>>());

        CHECK(test_shift_left_default<simd<int64_t, scalar>>());

        CHECK(test_shift_left_default<simd<int8_t, scalar>>());

        CHECK(test_shift_left_default<simd<uint16_t, scalar>>());

        CHECK(test_shift_left_default<simd<uint32_t, scalar>>());

        CHECK(test_shift_left_default<simd<uint64_t, scalar>>());

        CHECK(test_shift_left_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'shift_left' for sse", "[shift_left],[sse]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive shift_left<simd<double, sse>> not implemented.");
        WARN("Primitive shift_left<simd<float, sse>> not implemented.");
        CHECK(test_shift_left_default<simd<int16_t, sse>>());

        CHECK(test_shift_left_default<simd<int32_t, sse>>());

        CHECK(test_shift_left_default<simd<int64_t, sse>>());

        WARN("Primitive shift_left<simd<int8_t, sse>> not implemented.");
        CHECK(test_shift_left_default<simd<uint16_t, sse>>());

        CHECK(test_shift_left_default<simd<uint32_t, sse>>());

        CHECK(test_shift_left_default<simd<uint64_t, sse>>());

        WARN("Primitive shift_left<simd<uint8_t, sse>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'shift_left_vector' for avx2", "[shift_left_vector],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive shift_left_vector<simd<double, avx2>> not implemented.");
        WARN("Primitive shift_left_vector<simd<float, avx2>> not implemented.");
        CHECK(test_shift_left_vector_default<simd<int16_t, avx2>>());

        CHECK(test_shift_left_vector_default<simd<int32_t, avx2>>());

        CHECK(test_shift_left_vector_default<simd<int64_t, avx2>>());

        WARN("Primitive shift_left_vector<simd<int8_t, avx2>> not implemented.");
        CHECK(test_shift_left_vector_default<simd<uint16_t, avx2>>());

        CHECK(test_shift_left_vector_default<simd<uint32_t, avx2>>());

        CHECK(test_shift_left_vector_default<simd<uint64_t, avx2>>());

        WARN("Primitive shift_left_vector<simd<uint8_t, avx2>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'shift_left_vector' for avx512", "[shift_left_vector],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive shift_left_vector<simd<double, avx512>> not implemented.");
        WARN("Primitive shift_left_vector<simd<float, avx512>> not implemented.");
        CHECK(test_shift_left_vector_default<simd<int16_t, avx512>>());

        CHECK(test_shift_left_vector_default<simd<int32_t, avx512>>());

        CHECK(test_shift_left_vector_default<simd<int64_t, avx512>>());

        WARN("Primitive shift_left_vector<simd<int8_t, avx512>> not implemented.");
        CHECK(test_shift_left_vector_default<simd<uint16_t, avx512>>());

        CHECK(test_shift_left_vector_default<simd<uint32_t, avx512>>());

        CHECK(test_shift_left_vector_default<simd<uint64_t, avx512>>());

        WARN("Primitive shift_left_vector<simd<uint8_t, avx512>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'shift_left_vector' for scalar", "[shift_left_vector],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive shift_left_vector<simd<double, scalar>> not implemented.");
        WARN("Primitive shift_left_vector<simd<float, scalar>> not implemented.");
        CHECK(test_shift_left_vector_default<simd<int16_t, scalar>>());

        CHECK(test_shift_left_vector_default<simd<int32_t, scalar>>());

        CHECK(test_shift_left_vector_default<simd<int64_t, scalar>>());

        CHECK(test_shift_left_vector_default<simd<int8_t, scalar>>());

        CHECK(test_shift_left_vector_default<simd<uint16_t, scalar>>());

        CHECK(test_shift_left_vector_default<simd<uint32_t, scalar>>());

        CHECK(test_shift_left_vector_default<simd<uint64_t, scalar>>());

        CHECK(test_shift_left_vector_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'shift_left_vector' for sse", "[shift_left_vector],[sse]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive shift_left_vector<simd<double, sse>> not implemented.");
        WARN("Primitive shift_left_vector<simd<float, sse>> not implemented.");
        CHECK(test_shift_left_vector_default<simd<int16_t, sse>>());

        CHECK(test_shift_left_vector_default<simd<int32_t, sse>>());

        CHECK(test_shift_left_vector_default<simd<int64_t, sse>>());

        WARN("Primitive shift_left_vector<simd<int8_t, sse>> not implemented.");
        CHECK(test_shift_left_vector_default<simd<uint16_t, sse>>());

        CHECK(test_shift_left_vector_default<simd<uint32_t, sse>>());

        CHECK(test_shift_left_vector_default<simd<uint64_t, sse>>());

        WARN("Primitive shift_left_vector<simd<uint8_t, sse>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'shift_right' for avx2", "[shift_right],[avx2]") {
    using namespace tsl;
    SECTION("shift_right_arithmetic") {
        WARN("Primitive shift_right<simd<double, avx2>> not implemented.");
        WARN("Primitive shift_right<simd<float, avx2>> not implemented.");
        CHECK(test_shift_right_shift_right_arithmetic<simd<int16_t, avx2>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<int32_t, avx2>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<int64_t, avx2>>());

        WARN("Primitive shift_right<simd<int8_t, avx2>> not implemented.");
        CHECK(test_shift_right_shift_right_arithmetic<simd<uint16_t, avx2>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<uint32_t, avx2>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<uint64_t, avx2>>());

        WARN("Primitive shift_right<simd<uint8_t, avx2>> not implemented.");
    }
    SECTION("shift_right_ignore_sign") {
        WARN("Primitive shift_right<simd<double, avx2>> not implemented.");
        WARN("Primitive shift_right<simd<float, avx2>> not implemented.");
        CHECK(test_shift_right_shift_right_ignore_sign<simd<int16_t, avx2>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<int32_t, avx2>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<int64_t, avx2>>());

        WARN("Primitive shift_right<simd<int8_t, avx2>> not implemented.");
        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint16_t, avx2>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint32_t, avx2>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint64_t, avx2>>());

        WARN("Primitive shift_right<simd<uint8_t, avx2>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'shift_right' for avx512", "[shift_right],[avx512]") {
    using namespace tsl;
    SECTION("shift_right_arithmetic") {
        WARN("Primitive shift_right<simd<double, avx512>> not implemented.");
        WARN("Primitive shift_right<simd<float, avx512>> not implemented.");
        CHECK(test_shift_right_shift_right_arithmetic<simd<int16_t, avx512>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<int32_t, avx512>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<int64_t, avx512>>());

        WARN("Primitive shift_right<simd<int8_t, avx512>> not implemented.");
        CHECK(test_shift_right_shift_right_arithmetic<simd<uint16_t, avx512>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<uint32_t, avx512>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<uint64_t, avx512>>());

        WARN("Primitive shift_right<simd<uint8_t, avx512>> not implemented.");
    }
    SECTION("shift_right_ignore_sign") {
        WARN("Primitive shift_right<simd<double, avx512>> not implemented.");
        WARN("Primitive shift_right<simd<float, avx512>> not implemented.");
        CHECK(test_shift_right_shift_right_ignore_sign<simd<int16_t, avx512>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<int32_t, avx512>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<int64_t, avx512>>());

        WARN("Primitive shift_right<simd<int8_t, avx512>> not implemented.");
        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint16_t, avx512>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint32_t, avx512>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint64_t, avx512>>());

        WARN("Primitive shift_right<simd<uint8_t, avx512>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'shift_right' for scalar", "[shift_right],[scalar]") {
    using namespace tsl;
    SECTION("shift_right_arithmetic") {
        WARN("Primitive shift_right<simd<double, scalar>> not implemented.");
        WARN("Primitive shift_right<simd<float, scalar>> not implemented.");
        CHECK(test_shift_right_shift_right_arithmetic<simd<int16_t, scalar>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<int32_t, scalar>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<int64_t, scalar>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<int8_t, scalar>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<uint16_t, scalar>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<uint32_t, scalar>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<uint64_t, scalar>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<uint8_t, scalar>>());

    }
    SECTION("shift_right_ignore_sign") {
        WARN("Primitive shift_right<simd<double, scalar>> not implemented.");
        WARN("Primitive shift_right<simd<float, scalar>> not implemented.");
        CHECK(test_shift_right_shift_right_ignore_sign<simd<int16_t, scalar>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<int32_t, scalar>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<int64_t, scalar>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<int8_t, scalar>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint16_t, scalar>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint32_t, scalar>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint64_t, scalar>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'shift_right' for sse", "[shift_right],[sse]") {
    using namespace tsl;
    SECTION("shift_right_arithmetic") {
        WARN("Primitive shift_right<simd<double, sse>> not implemented.");
        WARN("Primitive shift_right<simd<float, sse>> not implemented.");
        CHECK(test_shift_right_shift_right_arithmetic<simd<int16_t, sse>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<int32_t, sse>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<int64_t, sse>>());

        WARN("Primitive shift_right<simd<int8_t, sse>> not implemented.");
        CHECK(test_shift_right_shift_right_arithmetic<simd<uint16_t, sse>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<uint32_t, sse>>());

        CHECK(test_shift_right_shift_right_arithmetic<simd<uint64_t, sse>>());

        WARN("Primitive shift_right<simd<uint8_t, sse>> not implemented.");
    }
    SECTION("shift_right_ignore_sign") {
        WARN("Primitive shift_right<simd<double, sse>> not implemented.");
        WARN("Primitive shift_right<simd<float, sse>> not implemented.");
        CHECK(test_shift_right_shift_right_ignore_sign<simd<int16_t, sse>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<int32_t, sse>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<int64_t, sse>>());

        WARN("Primitive shift_right<simd<int8_t, sse>> not implemented.");
        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint16_t, sse>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint32_t, sse>>());

        CHECK(test_shift_right_shift_right_ignore_sign<simd<uint64_t, sse>>());

        WARN("Primitive shift_right<simd<uint8_t, sse>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'shift_right_vector' for avx2", "[shift_right_vector],[avx2]") {
    using namespace tsl;
    SECTION("shift_right_arithmetic") {
        WARN("Primitive shift_right_vector<simd<double, avx2>> not implemented.");
        WARN("Primitive shift_right_vector<simd<float, avx2>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int16_t, avx2>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int32_t, avx2>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int64_t, avx2>>());

        WARN("Primitive shift_right_vector<simd<int8_t, avx2>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint16_t, avx2>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint32_t, avx2>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint64_t, avx2>>());

        WARN("Primitive shift_right_vector<simd<uint8_t, avx2>> not implemented.");
    }
    SECTION("shift_right_ignore_sign") {
        WARN("Primitive shift_right_vector<simd<double, avx2>> not implemented.");
        WARN("Primitive shift_right_vector<simd<float, avx2>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int16_t, avx2>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int32_t, avx2>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int64_t, avx2>>());

        WARN("Primitive shift_right_vector<simd<int8_t, avx2>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint16_t, avx2>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint32_t, avx2>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint64_t, avx2>>());

        WARN("Primitive shift_right_vector<simd<uint8_t, avx2>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'shift_right_vector' for avx512", "[shift_right_vector],[avx512]") {
    using namespace tsl;
    SECTION("shift_right_arithmetic") {
        WARN("Primitive shift_right_vector<simd<double, avx512>> not implemented.");
        WARN("Primitive shift_right_vector<simd<float, avx512>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int16_t, avx512>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int32_t, avx512>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int64_t, avx512>>());

        WARN("Primitive shift_right_vector<simd<int8_t, avx512>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint16_t, avx512>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint32_t, avx512>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint64_t, avx512>>());

        WARN("Primitive shift_right_vector<simd<uint8_t, avx512>> not implemented.");
    }
    SECTION("shift_right_ignore_sign") {
        WARN("Primitive shift_right_vector<simd<double, avx512>> not implemented.");
        WARN("Primitive shift_right_vector<simd<float, avx512>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int16_t, avx512>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int32_t, avx512>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int64_t, avx512>>());

        WARN("Primitive shift_right_vector<simd<int8_t, avx512>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint16_t, avx512>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint32_t, avx512>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint64_t, avx512>>());

        WARN("Primitive shift_right_vector<simd<uint8_t, avx512>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'shift_right_vector' for scalar", "[shift_right_vector],[scalar]") {
    using namespace tsl;
    SECTION("shift_right_arithmetic") {
        WARN("Primitive shift_right_vector<simd<double, scalar>> not implemented.");
        WARN("Primitive shift_right_vector<simd<float, scalar>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int16_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int32_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int64_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int8_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint16_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint32_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint64_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint8_t, scalar>>());

    }
    SECTION("shift_right_ignore_sign") {
        WARN("Primitive shift_right_vector<simd<double, scalar>> not implemented.");
        WARN("Primitive shift_right_vector<simd<float, scalar>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int16_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int32_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int64_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int8_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint16_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint32_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint64_t, scalar>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'shift_right_vector' for sse", "[shift_right_vector],[sse]") {
    using namespace tsl;
    SECTION("shift_right_arithmetic") {
        WARN("Primitive shift_right_vector<simd<double, sse>> not implemented.");
        WARN("Primitive shift_right_vector<simd<float, sse>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int16_t, sse>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int32_t, sse>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<int64_t, sse>>());

        WARN("Primitive shift_right_vector<simd<int8_t, sse>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint16_t, sse>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint32_t, sse>>());

        CHECK(test_shift_right_vector_shift_right_arithmetic<simd<uint64_t, sse>>());

        WARN("Primitive shift_right_vector<simd<uint8_t, sse>> not implemented.");
    }
    SECTION("shift_right_ignore_sign") {
        WARN("Primitive shift_right_vector<simd<double, sse>> not implemented.");
        WARN("Primitive shift_right_vector<simd<float, sse>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int16_t, sse>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int32_t, sse>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<int64_t, sse>>());

        WARN("Primitive shift_right_vector<simd<int8_t, sse>> not implemented.");
        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint16_t, sse>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint32_t, sse>>());

        CHECK(test_shift_right_vector_shift_right_ignore_sign<simd<uint64_t, sse>>());

        WARN("Primitive shift_right_vector<simd<uint8_t, sse>> not implemented.");
    }
}

