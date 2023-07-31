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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/src/test/calc_unit_test.cpp
 * \date 2023-07-22
 * \brief Unit test file for TSL Primitives using Catch2
 * \note
 *
 */

#include <tslintrin.hpp>
#include <cstddef>
#include <algorithm>
#include <limits>
#include "test_functions.hpp"

namespace tsl {
    template<VectorProcessingStyle Vec>
    bool test_hadd_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{1, false};
        bool allOk = true;
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        const std::size_t limit = std::min( (size_t) 4096, (size_t) std::numeric_limits<T>::max() / Vec::vector_element_count() );
        for(std::size_t i = 0; i < limit; ++i) {
          *reference_result_ptr =  Vec::vector_element_count() * i;
          auto vec = set1<Vec>(i);
          *test_result_ptr = hadd<Vec>(vec);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_mod_with_check_barrett_reduction_constraint() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{Vec::vector_element_count(), false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto vec = set1<Vec>(73);
        storeu<Vec>(reference_result_ptr, set1<Vec>(1));
        auto result_vec = mod<Vec>(vec, 8);
        storeu<Vec>(test_result_ptr, result_vec);
        test_helper.synchronize();
        return test_helper.validate();

    }
    template<VectorProcessingStyle Vec>
    bool test_mod_with_modulo_one() {
        using namespace tsl;
        using T = typename Vec::base_type;
        testing::test_memory_helper_t<Vec> test_helper{Vec::vector_element_count(), false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto vec = set1<Vec>(0);
        storeu<Vec>(reference_result_ptr, vec);
        storeu<Vec>(test_result_ptr, mod<Vec>(vec, 1));
        test_helper.synchronize();
        return test_helper.validate();

    }
    template<VectorProcessingStyle Vec>
    bool test_mod_with_modulo_rand() {
        using namespace tsl;
        using T = typename Vec::base_type;
        using IntType = std::conditional_t<std::is_same_v<T, float>, int32_t, std::conditional_t<std::is_same_v<T, double>, int64_t, T>>;
        std::size_t element_count = 1024 + (1024 / Vec::vector_element_count());
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false, testing::alternate_init_no_zero<T>};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        auto offset = 1024;
        for(std::size_t i = 0; i < (element_count - offset); i +=Vec::vector_element_count()){
          std::size_t tester_idx = 0;
          for(std::size_t j = i; j < i + Vec::vector_element_count(); j++){
            reference_result_ptr[tester_idx++] = reference_data_ptr[j] % reference_data_ptr[offset];
          }
          auto vec = loadu<Vec>(&test_data_ptr[i]);
          auto val = test_data_ptr[offset];
          auto vec_result = mod<Vec>(vec, val);
          storeu<Vec>(test_result_ptr, vec_result);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_add_running_sum_w_epsilon() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false };
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - 2*Vec::vector_element_count(); i+=2*Vec::vector_element_count()) {
          std::size_t tester_idx = 0;
          for(size_t j = i; j < i + Vec::vector_element_count(); j++) {
              reference_result_ptr[tester_idx++] = reference_data_ptr[j]+reference_data_ptr[j+Vec::vector_element_count()];
          }
          auto elements_vec1 = loadu<Vec>(&test_data_ptr[i]);
          auto elements_vec2 = loadu<Vec>(&test_data_ptr[i+Vec::vector_element_count()]);
          auto vec = add<Vec>(elements_vec1, elements_vec2);
          storeu<Vec>( test_result_ptr, vec );
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_add_zero_cornercase() {
        using namespace tsl;
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
          auto vec = set1<Vec>( 0 );
          auto elements = loadu<Vec>(&test_data_ptr[i]);
          vec = add<Vec>(vec, elements);
          storeu<Vec>( test_result_ptr, vec );
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_div_vec_with_itself() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false, testing::alternate_init_no_zero<T>};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i += Vec::vector_element_count()){
          auto vec = set1<Vec>(1);
          storeu<Vec>(reference_result_ptr, vec);
          auto vec_a = loadu<Vec>(&test_data_ptr[i]);
          vec = div<Vec>(vec_a, vec_a);
          storeu<Vec>(test_result_ptr, vec);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_div_vec_with_one() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false, testing::alternate_init_no_zero<T>};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i += Vec::vector_element_count()){
          std::size_t tester_idx = 0;
          for(size_t j=i; j < i + Vec::vector_element_count(); j++){
            reference_result_ptr[tester_idx++] = reference_data_ptr[j];
          }
          auto vec = set1<Vec>(1);
          auto vec_a = loadu<Vec>(&test_data_ptr[i]);
          auto vec_result = div<Vec>(vec_a, vec);
          storeu<Vec>(test_result_ptr, vec_result);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_min_min_general_case() {
        using namespace tsl;
        using T = typename Vec::base_type;
        const std::size_t element_count = 2048;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        auto vec = set1<Vec>(0);
        for(std::size_t i = 0; i < element_count / 2; i += Vec::vector_element_count()){
          std::size_t tester_idx = 0;
          for(size_t j = i; j < i + Vec::vector_element_count(); j++){
            if(reference_data_ptr[j] < reference_data_ptr[j + (element_count/2)]){
              reference_result_ptr[tester_idx++] = reference_data_ptr[j];
            } else {
              reference_result_ptr[tester_idx++] = reference_data_ptr[j + (element_count/2)];
            }
          }
          auto elements_vec1 = loadu<Vec>(&test_data_ptr[i]);
          auto elements_vec2 = loadu<Vec>(&test_data_ptr[i + (element_count/2)]);
          vec = min<Vec>(elements_vec1, elements_vec2);
          storeu<Vec>(test_result_ptr, vec);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_min_min_zero_case() {
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
          auto vec = set1<Vec>(0);
          storeu<Vec>(reference_result_ptr, vec);
          auto elements_vec = loadu<Vec>(&test_data_ptr[i]);
          vec = min<Vec>(vec, elements_vec);
          storeu<Vec>(test_result_ptr, vec);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_mul_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false };
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - (2*Vec::vector_element_count()); i+=(2*Vec::vector_element_count())) {
          std::size_t j = i;
          for(; j < i + Vec::vector_element_count(); ++j) {
              reference_result_ptr[j-i] = reference_data_ptr[j];
          }
          for(; j < i + (2*Vec::vector_element_count()); ++j) {
              reference_result_ptr[j-(i+Vec::vector_element_count())] *= reference_data_ptr[j];
          }
          auto vec_a = loadu<Vec>(&test_data_ptr[i]);
          auto vec_b = loadu<Vec>(&test_data_ptr[i+Vec::vector_element_count()]);
          auto vec_result = mul<Vec>(vec_a, vec_b);
          storeu<Vec>(test_result_ptr, vec_result);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_sub_running_sum_w_epsilon() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false };
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - 2*Vec::vector_element_count(); i+=2*Vec::vector_element_count()) {
            std::size_t tester_idx = 0;
            for(size_t j = i; j < i + Vec::vector_element_count(); j++) {
              reference_result_ptr[tester_idx++] = reference_data_ptr[j]-reference_data_ptr[j+Vec::vector_element_count()];
            }
            auto elements_vec1 = loadu<Vec>(&test_data_ptr[i]);
            auto elements_vec2 = loadu<Vec>(&test_data_ptr[i+Vec::vector_element_count()]);
            auto vec = sub<Vec>(elements_vec1, elements_vec2);
            storeu<Vec>( test_result_ptr, vec );
            test_helper.synchronize();
            allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_sub_zero_cornercase() {
        using namespace tsl;
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
            auto vec = set1<Vec>( 0 );
            auto elements = loadu<Vec>(&test_data_ptr[i]);
            vec = sub<Vec>(elements, vec);
            storeu<Vec>( test_result_ptr, vec );
            test_helper.synchronize();
            allOk &= test_helper.validate();
        }
        return allOk;

    }
}

TEST_CASE("Testing primitive 'hadd' for avx2", "[hadd],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive hadd<simd<double, avx2>> not implemented.");
        WARN("Primitive hadd<simd<float, avx2>> not implemented.");
        CHECK(test_hadd_default<simd<int16_t, avx2>>());

        WARN("Primitive hadd<simd<int32_t, avx2>> not implemented.");
        CHECK(test_hadd_default<simd<int64_t, avx2>>());

        CHECK(test_hadd_default<simd<int8_t, avx2>>());

        CHECK(test_hadd_default<simd<uint16_t, avx2>>());

        WARN("Primitive hadd<simd<uint32_t, avx2>> not implemented.");
        CHECK(test_hadd_default<simd<uint64_t, avx2>>());

        CHECK(test_hadd_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'hadd' for avx512", "[hadd],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_hadd_default<simd<double, avx512>>());

        CHECK(test_hadd_default<simd<float, avx512>>());

        CHECK(test_hadd_default<simd<int16_t, avx512>>());

        CHECK(test_hadd_default<simd<int32_t, avx512>>());

        CHECK(test_hadd_default<simd<int64_t, avx512>>());

        CHECK(test_hadd_default<simd<int8_t, avx512>>());

        CHECK(test_hadd_default<simd<uint16_t, avx512>>());

        CHECK(test_hadd_default<simd<uint32_t, avx512>>());

        CHECK(test_hadd_default<simd<uint64_t, avx512>>());

        CHECK(test_hadd_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'hadd' for scalar", "[hadd],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_hadd_default<simd<double, scalar>>());

        CHECK(test_hadd_default<simd<float, scalar>>());

        CHECK(test_hadd_default<simd<int16_t, scalar>>());

        CHECK(test_hadd_default<simd<int32_t, scalar>>());

        CHECK(test_hadd_default<simd<int64_t, scalar>>());

        CHECK(test_hadd_default<simd<int8_t, scalar>>());

        CHECK(test_hadd_default<simd<uint16_t, scalar>>());

        CHECK(test_hadd_default<simd<uint32_t, scalar>>());

        CHECK(test_hadd_default<simd<uint64_t, scalar>>());

        CHECK(test_hadd_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'hadd' for sse", "[hadd],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_hadd_default<simd<double, sse>>());

        WARN("Primitive hadd<simd<float, sse>> not implemented.");
        CHECK(test_hadd_default<simd<int16_t, sse>>());

        WARN("Primitive hadd<simd<int32_t, sse>> not implemented.");
        CHECK(test_hadd_default<simd<int64_t, sse>>());

        CHECK(test_hadd_default<simd<int8_t, sse>>());

        CHECK(test_hadd_default<simd<uint16_t, sse>>());

        WARN("Primitive hadd<simd<uint32_t, sse>> not implemented.");
        CHECK(test_hadd_default<simd<uint64_t, sse>>());

        CHECK(test_hadd_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'mod' for avx2", "[mod],[avx2]") {
    using namespace tsl;
    SECTION("with_check_barrett_reduction_constraint") {
        WARN("Primitive mod<simd<double, avx2>> not implemented.");
        WARN("Primitive mod<simd<float, avx2>> not implemented.");
        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int16_t, avx2>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int32_t, avx2>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int64_t, avx2>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int8_t, avx2>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint16_t, avx2>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint32_t, avx2>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint64_t, avx2>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint8_t, avx2>>());

    }
    SECTION("with_modulo_one") {
        WARN("Primitive mod<simd<double, avx2>> not implemented.");
        WARN("Primitive mod<simd<float, avx2>> not implemented.");
        CHECK(test_mod_with_modulo_one<simd<int16_t, avx2>>());

        CHECK(test_mod_with_modulo_one<simd<int32_t, avx2>>());

        CHECK(test_mod_with_modulo_one<simd<int64_t, avx2>>());

        CHECK(test_mod_with_modulo_one<simd<int8_t, avx2>>());

        CHECK(test_mod_with_modulo_one<simd<uint16_t, avx2>>());

        CHECK(test_mod_with_modulo_one<simd<uint32_t, avx2>>());

        CHECK(test_mod_with_modulo_one<simd<uint64_t, avx2>>());

        CHECK(test_mod_with_modulo_one<simd<uint8_t, avx2>>());

    }
    SECTION("with_modulo_rand") {
        WARN("Primitive mod<simd<double, avx2>> not implemented.");
        WARN("Primitive mod<simd<float, avx2>> not implemented.");
        CHECK(test_mod_with_modulo_rand<simd<int16_t, avx2>>());

        CHECK(test_mod_with_modulo_rand<simd<int32_t, avx2>>());

        CHECK(test_mod_with_modulo_rand<simd<int64_t, avx2>>());

        CHECK(test_mod_with_modulo_rand<simd<int8_t, avx2>>());

        CHECK(test_mod_with_modulo_rand<simd<uint16_t, avx2>>());

        CHECK(test_mod_with_modulo_rand<simd<uint32_t, avx2>>());

        CHECK(test_mod_with_modulo_rand<simd<uint64_t, avx2>>());

        CHECK(test_mod_with_modulo_rand<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'mod' for avx512", "[mod],[avx512]") {
    using namespace tsl;
    SECTION("with_check_barrett_reduction_constraint") {
        WARN("Primitive mod<simd<double, avx512>> not implemented.");
        WARN("Primitive mod<simd<float, avx512>> not implemented.");
        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int16_t, avx512>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int32_t, avx512>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int64_t, avx512>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int8_t, avx512>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint16_t, avx512>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint32_t, avx512>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint64_t, avx512>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint8_t, avx512>>());

    }
    SECTION("with_modulo_one") {
        WARN("Primitive mod<simd<double, avx512>> not implemented.");
        WARN("Primitive mod<simd<float, avx512>> not implemented.");
        CHECK(test_mod_with_modulo_one<simd<int16_t, avx512>>());

        CHECK(test_mod_with_modulo_one<simd<int32_t, avx512>>());

        CHECK(test_mod_with_modulo_one<simd<int64_t, avx512>>());

        CHECK(test_mod_with_modulo_one<simd<int8_t, avx512>>());

        CHECK(test_mod_with_modulo_one<simd<uint16_t, avx512>>());

        CHECK(test_mod_with_modulo_one<simd<uint32_t, avx512>>());

        CHECK(test_mod_with_modulo_one<simd<uint64_t, avx512>>());

        CHECK(test_mod_with_modulo_one<simd<uint8_t, avx512>>());

    }
    SECTION("with_modulo_rand") {
        WARN("Primitive mod<simd<double, avx512>> not implemented.");
        WARN("Primitive mod<simd<float, avx512>> not implemented.");
        CHECK(test_mod_with_modulo_rand<simd<int16_t, avx512>>());

        CHECK(test_mod_with_modulo_rand<simd<int32_t, avx512>>());

        CHECK(test_mod_with_modulo_rand<simd<int64_t, avx512>>());

        CHECK(test_mod_with_modulo_rand<simd<int8_t, avx512>>());

        CHECK(test_mod_with_modulo_rand<simd<uint16_t, avx512>>());

        CHECK(test_mod_with_modulo_rand<simd<uint32_t, avx512>>());

        CHECK(test_mod_with_modulo_rand<simd<uint64_t, avx512>>());

        CHECK(test_mod_with_modulo_rand<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'mod' for scalar", "[mod],[scalar]") {
    using namespace tsl;
    SECTION("with_check_barrett_reduction_constraint") {
        WARN("Primitive mod<simd<double, scalar>> not implemented.");
        WARN("Primitive mod<simd<float, scalar>> not implemented.");
        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int16_t, scalar>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int32_t, scalar>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int64_t, scalar>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int8_t, scalar>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint16_t, scalar>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint32_t, scalar>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint64_t, scalar>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint8_t, scalar>>());

    }
    SECTION("with_modulo_one") {
        WARN("Primitive mod<simd<double, scalar>> not implemented.");
        WARN("Primitive mod<simd<float, scalar>> not implemented.");
        CHECK(test_mod_with_modulo_one<simd<int16_t, scalar>>());

        CHECK(test_mod_with_modulo_one<simd<int32_t, scalar>>());

        CHECK(test_mod_with_modulo_one<simd<int64_t, scalar>>());

        CHECK(test_mod_with_modulo_one<simd<int8_t, scalar>>());

        CHECK(test_mod_with_modulo_one<simd<uint16_t, scalar>>());

        CHECK(test_mod_with_modulo_one<simd<uint32_t, scalar>>());

        CHECK(test_mod_with_modulo_one<simd<uint64_t, scalar>>());

        CHECK(test_mod_with_modulo_one<simd<uint8_t, scalar>>());

    }
    SECTION("with_modulo_rand") {
        WARN("Primitive mod<simd<double, scalar>> not implemented.");
        WARN("Primitive mod<simd<float, scalar>> not implemented.");
        CHECK(test_mod_with_modulo_rand<simd<int16_t, scalar>>());

        CHECK(test_mod_with_modulo_rand<simd<int32_t, scalar>>());

        CHECK(test_mod_with_modulo_rand<simd<int64_t, scalar>>());

        CHECK(test_mod_with_modulo_rand<simd<int8_t, scalar>>());

        CHECK(test_mod_with_modulo_rand<simd<uint16_t, scalar>>());

        CHECK(test_mod_with_modulo_rand<simd<uint32_t, scalar>>());

        CHECK(test_mod_with_modulo_rand<simd<uint64_t, scalar>>());

        CHECK(test_mod_with_modulo_rand<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'mod' for sse", "[mod],[sse]") {
    using namespace tsl;
    SECTION("with_check_barrett_reduction_constraint") {
        WARN("Primitive mod<simd<double, sse>> not implemented.");
        WARN("Primitive mod<simd<float, sse>> not implemented.");
        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int16_t, sse>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int32_t, sse>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int64_t, sse>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<int8_t, sse>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint16_t, sse>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint32_t, sse>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint64_t, sse>>());

        CHECK(test_mod_with_check_barrett_reduction_constraint<simd<uint8_t, sse>>());

    }
    SECTION("with_modulo_one") {
        WARN("Primitive mod<simd<double, sse>> not implemented.");
        WARN("Primitive mod<simd<float, sse>> not implemented.");
        CHECK(test_mod_with_modulo_one<simd<int16_t, sse>>());

        CHECK(test_mod_with_modulo_one<simd<int32_t, sse>>());

        CHECK(test_mod_with_modulo_one<simd<int64_t, sse>>());

        CHECK(test_mod_with_modulo_one<simd<int8_t, sse>>());

        CHECK(test_mod_with_modulo_one<simd<uint16_t, sse>>());

        CHECK(test_mod_with_modulo_one<simd<uint32_t, sse>>());

        CHECK(test_mod_with_modulo_one<simd<uint64_t, sse>>());

        CHECK(test_mod_with_modulo_one<simd<uint8_t, sse>>());

    }
    SECTION("with_modulo_rand") {
        WARN("Primitive mod<simd<double, sse>> not implemented.");
        WARN("Primitive mod<simd<float, sse>> not implemented.");
        CHECK(test_mod_with_modulo_rand<simd<int16_t, sse>>());

        CHECK(test_mod_with_modulo_rand<simd<int32_t, sse>>());

        CHECK(test_mod_with_modulo_rand<simd<int64_t, sse>>());

        CHECK(test_mod_with_modulo_rand<simd<int8_t, sse>>());

        CHECK(test_mod_with_modulo_rand<simd<uint16_t, sse>>());

        CHECK(test_mod_with_modulo_rand<simd<uint32_t, sse>>());

        CHECK(test_mod_with_modulo_rand<simd<uint64_t, sse>>());

        CHECK(test_mod_with_modulo_rand<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'add' for avx2", "[add],[avx2]") {
    using namespace tsl;
    SECTION("running_sum_w_epsilon") {
        CHECK(test_add_running_sum_w_epsilon<simd<double, avx2>>());

        CHECK(test_add_running_sum_w_epsilon<simd<float, avx2>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int16_t, avx2>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int32_t, avx2>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int64_t, avx2>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int8_t, avx2>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint16_t, avx2>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint32_t, avx2>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint64_t, avx2>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint8_t, avx2>>());

    }
    SECTION("zero_cornercase") {
        CHECK(test_add_zero_cornercase<simd<double, avx2>>());

        CHECK(test_add_zero_cornercase<simd<float, avx2>>());

        CHECK(test_add_zero_cornercase<simd<int16_t, avx2>>());

        CHECK(test_add_zero_cornercase<simd<int32_t, avx2>>());

        CHECK(test_add_zero_cornercase<simd<int64_t, avx2>>());

        CHECK(test_add_zero_cornercase<simd<int8_t, avx2>>());

        CHECK(test_add_zero_cornercase<simd<uint16_t, avx2>>());

        CHECK(test_add_zero_cornercase<simd<uint32_t, avx2>>());

        CHECK(test_add_zero_cornercase<simd<uint64_t, avx2>>());

        CHECK(test_add_zero_cornercase<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'add' for avx512", "[add],[avx512]") {
    using namespace tsl;
    SECTION("running_sum_w_epsilon") {
        CHECK(test_add_running_sum_w_epsilon<simd<double, avx512>>());

        CHECK(test_add_running_sum_w_epsilon<simd<float, avx512>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int16_t, avx512>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int32_t, avx512>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int64_t, avx512>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int8_t, avx512>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint16_t, avx512>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint32_t, avx512>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint64_t, avx512>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint8_t, avx512>>());

    }
    SECTION("zero_cornercase") {
        CHECK(test_add_zero_cornercase<simd<double, avx512>>());

        CHECK(test_add_zero_cornercase<simd<float, avx512>>());

        CHECK(test_add_zero_cornercase<simd<int16_t, avx512>>());

        CHECK(test_add_zero_cornercase<simd<int32_t, avx512>>());

        CHECK(test_add_zero_cornercase<simd<int64_t, avx512>>());

        CHECK(test_add_zero_cornercase<simd<int8_t, avx512>>());

        CHECK(test_add_zero_cornercase<simd<uint16_t, avx512>>());

        CHECK(test_add_zero_cornercase<simd<uint32_t, avx512>>());

        CHECK(test_add_zero_cornercase<simd<uint64_t, avx512>>());

        CHECK(test_add_zero_cornercase<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'add' for scalar", "[add],[scalar]") {
    using namespace tsl;
    SECTION("running_sum_w_epsilon") {
        CHECK(test_add_running_sum_w_epsilon<simd<double, scalar>>());

        CHECK(test_add_running_sum_w_epsilon<simd<float, scalar>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int16_t, scalar>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int32_t, scalar>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int64_t, scalar>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int8_t, scalar>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint16_t, scalar>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint32_t, scalar>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint64_t, scalar>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint8_t, scalar>>());

    }
    SECTION("zero_cornercase") {
        CHECK(test_add_zero_cornercase<simd<double, scalar>>());

        CHECK(test_add_zero_cornercase<simd<float, scalar>>());

        CHECK(test_add_zero_cornercase<simd<int16_t, scalar>>());

        CHECK(test_add_zero_cornercase<simd<int32_t, scalar>>());

        CHECK(test_add_zero_cornercase<simd<int64_t, scalar>>());

        CHECK(test_add_zero_cornercase<simd<int8_t, scalar>>());

        CHECK(test_add_zero_cornercase<simd<uint16_t, scalar>>());

        CHECK(test_add_zero_cornercase<simd<uint32_t, scalar>>());

        CHECK(test_add_zero_cornercase<simd<uint64_t, scalar>>());

        CHECK(test_add_zero_cornercase<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'add' for sse", "[add],[sse]") {
    using namespace tsl;
    SECTION("running_sum_w_epsilon") {
        CHECK(test_add_running_sum_w_epsilon<simd<double, sse>>());

        CHECK(test_add_running_sum_w_epsilon<simd<float, sse>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int16_t, sse>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int32_t, sse>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int64_t, sse>>());

        CHECK(test_add_running_sum_w_epsilon<simd<int8_t, sse>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint16_t, sse>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint32_t, sse>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint64_t, sse>>());

        CHECK(test_add_running_sum_w_epsilon<simd<uint8_t, sse>>());

    }
    SECTION("zero_cornercase") {
        CHECK(test_add_zero_cornercase<simd<double, sse>>());

        CHECK(test_add_zero_cornercase<simd<float, sse>>());

        CHECK(test_add_zero_cornercase<simd<int16_t, sse>>());

        CHECK(test_add_zero_cornercase<simd<int32_t, sse>>());

        CHECK(test_add_zero_cornercase<simd<int64_t, sse>>());

        CHECK(test_add_zero_cornercase<simd<int8_t, sse>>());

        CHECK(test_add_zero_cornercase<simd<uint16_t, sse>>());

        CHECK(test_add_zero_cornercase<simd<uint32_t, sse>>());

        CHECK(test_add_zero_cornercase<simd<uint64_t, sse>>());

        CHECK(test_add_zero_cornercase<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'div' for avx2", "[div],[avx2]") {
    using namespace tsl;
    SECTION("vec_with_itself") {
        CHECK(test_div_vec_with_itself<simd<double, avx2>>());

        CHECK(test_div_vec_with_itself<simd<float, avx2>>());

        CHECK(test_div_vec_with_itself<simd<int16_t, avx2>>());

        CHECK(test_div_vec_with_itself<simd<int32_t, avx2>>());

        CHECK(test_div_vec_with_itself<simd<int64_t, avx2>>());

        CHECK(test_div_vec_with_itself<simd<int8_t, avx2>>());

        CHECK(test_div_vec_with_itself<simd<uint16_t, avx2>>());

        CHECK(test_div_vec_with_itself<simd<uint32_t, avx2>>());

        CHECK(test_div_vec_with_itself<simd<uint64_t, avx2>>());

        CHECK(test_div_vec_with_itself<simd<uint8_t, avx2>>());

    }
    SECTION("vec_with_one") {
        CHECK(test_div_vec_with_one<simd<double, avx2>>());

        CHECK(test_div_vec_with_one<simd<float, avx2>>());

        CHECK(test_div_vec_with_one<simd<int16_t, avx2>>());

        CHECK(test_div_vec_with_one<simd<int32_t, avx2>>());

        CHECK(test_div_vec_with_one<simd<int64_t, avx2>>());

        CHECK(test_div_vec_with_one<simd<int8_t, avx2>>());

        CHECK(test_div_vec_with_one<simd<uint16_t, avx2>>());

        CHECK(test_div_vec_with_one<simd<uint32_t, avx2>>());

        CHECK(test_div_vec_with_one<simd<uint64_t, avx2>>());

        CHECK(test_div_vec_with_one<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'div' for avx512", "[div],[avx512]") {
    using namespace tsl;
    SECTION("vec_with_itself") {
        CHECK(test_div_vec_with_itself<simd<double, avx512>>());

        CHECK(test_div_vec_with_itself<simd<float, avx512>>());

        CHECK(test_div_vec_with_itself<simd<int16_t, avx512>>());

        CHECK(test_div_vec_with_itself<simd<int32_t, avx512>>());

        CHECK(test_div_vec_with_itself<simd<int64_t, avx512>>());

        CHECK(test_div_vec_with_itself<simd<int8_t, avx512>>());

        CHECK(test_div_vec_with_itself<simd<uint16_t, avx512>>());

        CHECK(test_div_vec_with_itself<simd<uint32_t, avx512>>());

        CHECK(test_div_vec_with_itself<simd<uint64_t, avx512>>());

        CHECK(test_div_vec_with_itself<simd<uint8_t, avx512>>());

    }
    SECTION("vec_with_one") {
        CHECK(test_div_vec_with_one<simd<double, avx512>>());

        CHECK(test_div_vec_with_one<simd<float, avx512>>());

        CHECK(test_div_vec_with_one<simd<int16_t, avx512>>());

        CHECK(test_div_vec_with_one<simd<int32_t, avx512>>());

        CHECK(test_div_vec_with_one<simd<int64_t, avx512>>());

        CHECK(test_div_vec_with_one<simd<int8_t, avx512>>());

        CHECK(test_div_vec_with_one<simd<uint16_t, avx512>>());

        CHECK(test_div_vec_with_one<simd<uint32_t, avx512>>());

        CHECK(test_div_vec_with_one<simd<uint64_t, avx512>>());

        CHECK(test_div_vec_with_one<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'div' for scalar", "[div],[scalar]") {
    using namespace tsl;
    SECTION("vec_with_itself") {
        CHECK(test_div_vec_with_itself<simd<double, scalar>>());

        CHECK(test_div_vec_with_itself<simd<float, scalar>>());

        CHECK(test_div_vec_with_itself<simd<int16_t, scalar>>());

        CHECK(test_div_vec_with_itself<simd<int32_t, scalar>>());

        CHECK(test_div_vec_with_itself<simd<int64_t, scalar>>());

        CHECK(test_div_vec_with_itself<simd<int8_t, scalar>>());

        CHECK(test_div_vec_with_itself<simd<uint16_t, scalar>>());

        CHECK(test_div_vec_with_itself<simd<uint32_t, scalar>>());

        CHECK(test_div_vec_with_itself<simd<uint64_t, scalar>>());

        CHECK(test_div_vec_with_itself<simd<uint8_t, scalar>>());

    }
    SECTION("vec_with_one") {
        CHECK(test_div_vec_with_one<simd<double, scalar>>());

        CHECK(test_div_vec_with_one<simd<float, scalar>>());

        CHECK(test_div_vec_with_one<simd<int16_t, scalar>>());

        CHECK(test_div_vec_with_one<simd<int32_t, scalar>>());

        CHECK(test_div_vec_with_one<simd<int64_t, scalar>>());

        CHECK(test_div_vec_with_one<simd<int8_t, scalar>>());

        CHECK(test_div_vec_with_one<simd<uint16_t, scalar>>());

        CHECK(test_div_vec_with_one<simd<uint32_t, scalar>>());

        CHECK(test_div_vec_with_one<simd<uint64_t, scalar>>());

        CHECK(test_div_vec_with_one<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'div' for sse", "[div],[sse]") {
    using namespace tsl;
    SECTION("vec_with_itself") {
        CHECK(test_div_vec_with_itself<simd<double, sse>>());

        CHECK(test_div_vec_with_itself<simd<float, sse>>());

        CHECK(test_div_vec_with_itself<simd<int16_t, sse>>());

        CHECK(test_div_vec_with_itself<simd<int32_t, sse>>());

        CHECK(test_div_vec_with_itself<simd<int64_t, sse>>());

        CHECK(test_div_vec_with_itself<simd<int8_t, sse>>());

        CHECK(test_div_vec_with_itself<simd<uint16_t, sse>>());

        CHECK(test_div_vec_with_itself<simd<uint32_t, sse>>());

        CHECK(test_div_vec_with_itself<simd<uint64_t, sse>>());

        CHECK(test_div_vec_with_itself<simd<uint8_t, sse>>());

    }
    SECTION("vec_with_one") {
        CHECK(test_div_vec_with_one<simd<double, sse>>());

        CHECK(test_div_vec_with_one<simd<float, sse>>());

        CHECK(test_div_vec_with_one<simd<int16_t, sse>>());

        CHECK(test_div_vec_with_one<simd<int32_t, sse>>());

        CHECK(test_div_vec_with_one<simd<int64_t, sse>>());

        CHECK(test_div_vec_with_one<simd<int8_t, sse>>());

        CHECK(test_div_vec_with_one<simd<uint16_t, sse>>());

        CHECK(test_div_vec_with_one<simd<uint32_t, sse>>());

        CHECK(test_div_vec_with_one<simd<uint64_t, sse>>());

        CHECK(test_div_vec_with_one<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'min' for avx2", "[min],[avx2]") {
    using namespace tsl;
    SECTION("min_general_case") {
        CHECK(test_min_min_general_case<simd<double, avx2>>());

        CHECK(test_min_min_general_case<simd<float, avx2>>());

        CHECK(test_min_min_general_case<simd<int16_t, avx2>>());

        CHECK(test_min_min_general_case<simd<int32_t, avx2>>());

        CHECK(test_min_min_general_case<simd<int64_t, avx2>>());

        CHECK(test_min_min_general_case<simd<int8_t, avx2>>());

        CHECK(test_min_min_general_case<simd<uint16_t, avx2>>());

        CHECK(test_min_min_general_case<simd<uint32_t, avx2>>());

        CHECK(test_min_min_general_case<simd<uint64_t, avx2>>());

        CHECK(test_min_min_general_case<simd<uint8_t, avx2>>());

    }
    SECTION("min_zero_case") {
        CHECK(test_min_min_zero_case<simd<double, avx2>>());

        CHECK(test_min_min_zero_case<simd<float, avx2>>());

        CHECK(test_min_min_zero_case<simd<int16_t, avx2>>());

        CHECK(test_min_min_zero_case<simd<int32_t, avx2>>());

        CHECK(test_min_min_zero_case<simd<int64_t, avx2>>());

        CHECK(test_min_min_zero_case<simd<int8_t, avx2>>());

        CHECK(test_min_min_zero_case<simd<uint16_t, avx2>>());

        CHECK(test_min_min_zero_case<simd<uint32_t, avx2>>());

        CHECK(test_min_min_zero_case<simd<uint64_t, avx2>>());

        CHECK(test_min_min_zero_case<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'min' for avx512", "[min],[avx512]") {
    using namespace tsl;
    SECTION("min_general_case") {
        CHECK(test_min_min_general_case<simd<double, avx512>>());

        CHECK(test_min_min_general_case<simd<float, avx512>>());

        CHECK(test_min_min_general_case<simd<int16_t, avx512>>());

        CHECK(test_min_min_general_case<simd<int32_t, avx512>>());

        CHECK(test_min_min_general_case<simd<int64_t, avx512>>());

        CHECK(test_min_min_general_case<simd<int8_t, avx512>>());

        CHECK(test_min_min_general_case<simd<uint16_t, avx512>>());

        CHECK(test_min_min_general_case<simd<uint32_t, avx512>>());

        CHECK(test_min_min_general_case<simd<uint64_t, avx512>>());

        CHECK(test_min_min_general_case<simd<uint8_t, avx512>>());

    }
    SECTION("min_zero_case") {
        CHECK(test_min_min_zero_case<simd<double, avx512>>());

        CHECK(test_min_min_zero_case<simd<float, avx512>>());

        CHECK(test_min_min_zero_case<simd<int16_t, avx512>>());

        CHECK(test_min_min_zero_case<simd<int32_t, avx512>>());

        CHECK(test_min_min_zero_case<simd<int64_t, avx512>>());

        CHECK(test_min_min_zero_case<simd<int8_t, avx512>>());

        CHECK(test_min_min_zero_case<simd<uint16_t, avx512>>());

        CHECK(test_min_min_zero_case<simd<uint32_t, avx512>>());

        CHECK(test_min_min_zero_case<simd<uint64_t, avx512>>());

        CHECK(test_min_min_zero_case<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'min' for scalar", "[min],[scalar]") {
    using namespace tsl;
    SECTION("min_general_case") {
        CHECK(test_min_min_general_case<simd<double, scalar>>());

        CHECK(test_min_min_general_case<simd<float, scalar>>());

        CHECK(test_min_min_general_case<simd<int16_t, scalar>>());

        CHECK(test_min_min_general_case<simd<int32_t, scalar>>());

        CHECK(test_min_min_general_case<simd<int64_t, scalar>>());

        CHECK(test_min_min_general_case<simd<int8_t, scalar>>());

        CHECK(test_min_min_general_case<simd<uint16_t, scalar>>());

        CHECK(test_min_min_general_case<simd<uint32_t, scalar>>());

        CHECK(test_min_min_general_case<simd<uint64_t, scalar>>());

        CHECK(test_min_min_general_case<simd<uint8_t, scalar>>());

    }
    SECTION("min_zero_case") {
        CHECK(test_min_min_zero_case<simd<double, scalar>>());

        CHECK(test_min_min_zero_case<simd<float, scalar>>());

        CHECK(test_min_min_zero_case<simd<int16_t, scalar>>());

        CHECK(test_min_min_zero_case<simd<int32_t, scalar>>());

        CHECK(test_min_min_zero_case<simd<int64_t, scalar>>());

        CHECK(test_min_min_zero_case<simd<int8_t, scalar>>());

        CHECK(test_min_min_zero_case<simd<uint16_t, scalar>>());

        CHECK(test_min_min_zero_case<simd<uint32_t, scalar>>());

        CHECK(test_min_min_zero_case<simd<uint64_t, scalar>>());

        CHECK(test_min_min_zero_case<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'min' for sse", "[min],[sse]") {
    using namespace tsl;
    SECTION("min_general_case") {
        CHECK(test_min_min_general_case<simd<double, sse>>());

        CHECK(test_min_min_general_case<simd<float, sse>>());

        CHECK(test_min_min_general_case<simd<int16_t, sse>>());

        CHECK(test_min_min_general_case<simd<int32_t, sse>>());

        WARN("Primitive min<simd<int64_t, sse>> not implemented.");
        CHECK(test_min_min_general_case<simd<int8_t, sse>>());

        CHECK(test_min_min_general_case<simd<uint16_t, sse>>());

        CHECK(test_min_min_general_case<simd<uint32_t, sse>>());

        WARN("Primitive min<simd<uint64_t, sse>> not implemented.");
        CHECK(test_min_min_general_case<simd<uint8_t, sse>>());

    }
    SECTION("min_zero_case") {
        CHECK(test_min_min_zero_case<simd<double, sse>>());

        CHECK(test_min_min_zero_case<simd<float, sse>>());

        CHECK(test_min_min_zero_case<simd<int16_t, sse>>());

        CHECK(test_min_min_zero_case<simd<int32_t, sse>>());

        WARN("Primitive min<simd<int64_t, sse>> not implemented.");
        CHECK(test_min_min_zero_case<simd<int8_t, sse>>());

        CHECK(test_min_min_zero_case<simd<uint16_t, sse>>());

        CHECK(test_min_min_zero_case<simd<uint32_t, sse>>());

        WARN("Primitive min<simd<uint64_t, sse>> not implemented.");
        CHECK(test_min_min_zero_case<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'mul' for avx2", "[mul],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_mul_default<simd<double, avx2>>());

        CHECK(test_mul_default<simd<float, avx2>>());

        CHECK(test_mul_default<simd<int16_t, avx2>>());

        CHECK(test_mul_default<simd<int32_t, avx2>>());

        CHECK(test_mul_default<simd<int64_t, avx2>>());

        CHECK(test_mul_default<simd<int8_t, avx2>>());

        CHECK(test_mul_default<simd<uint16_t, avx2>>());

        CHECK(test_mul_default<simd<uint32_t, avx2>>());

        CHECK(test_mul_default<simd<uint64_t, avx2>>());

        CHECK(test_mul_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'mul' for avx512", "[mul],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_mul_default<simd<double, avx512>>());

        CHECK(test_mul_default<simd<float, avx512>>());

        CHECK(test_mul_default<simd<int16_t, avx512>>());

        CHECK(test_mul_default<simd<int32_t, avx512>>());

        CHECK(test_mul_default<simd<int64_t, avx512>>());

        CHECK(test_mul_default<simd<int8_t, avx512>>());

        CHECK(test_mul_default<simd<uint16_t, avx512>>());

        CHECK(test_mul_default<simd<uint32_t, avx512>>());

        CHECK(test_mul_default<simd<uint64_t, avx512>>());

        CHECK(test_mul_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'mul' for scalar", "[mul],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_mul_default<simd<double, scalar>>());

        CHECK(test_mul_default<simd<float, scalar>>());

        CHECK(test_mul_default<simd<int16_t, scalar>>());

        CHECK(test_mul_default<simd<int32_t, scalar>>());

        CHECK(test_mul_default<simd<int64_t, scalar>>());

        CHECK(test_mul_default<simd<int8_t, scalar>>());

        CHECK(test_mul_default<simd<uint16_t, scalar>>());

        CHECK(test_mul_default<simd<uint32_t, scalar>>());

        CHECK(test_mul_default<simd<uint64_t, scalar>>());

        CHECK(test_mul_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'mul' for sse", "[mul],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_mul_default<simd<double, sse>>());

        CHECK(test_mul_default<simd<float, sse>>());

        CHECK(test_mul_default<simd<int16_t, sse>>());

        CHECK(test_mul_default<simd<int32_t, sse>>());

        CHECK(test_mul_default<simd<int64_t, sse>>());

        CHECK(test_mul_default<simd<int8_t, sse>>());

        CHECK(test_mul_default<simd<uint16_t, sse>>());

        CHECK(test_mul_default<simd<uint32_t, sse>>());

        CHECK(test_mul_default<simd<uint64_t, sse>>());

        CHECK(test_mul_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'sub' for avx2", "[sub],[avx2]") {
    using namespace tsl;
    SECTION("running_sum_w_epsilon") {
        CHECK(test_sub_running_sum_w_epsilon<simd<double, avx2>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<float, avx2>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int16_t, avx2>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int32_t, avx2>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int64_t, avx2>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int8_t, avx2>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint16_t, avx2>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint32_t, avx2>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint64_t, avx2>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint8_t, avx2>>());

    }
    SECTION("zero_cornercase") {
        CHECK(test_sub_zero_cornercase<simd<double, avx2>>());

        CHECK(test_sub_zero_cornercase<simd<float, avx2>>());

        CHECK(test_sub_zero_cornercase<simd<int16_t, avx2>>());

        CHECK(test_sub_zero_cornercase<simd<int32_t, avx2>>());

        CHECK(test_sub_zero_cornercase<simd<int64_t, avx2>>());

        CHECK(test_sub_zero_cornercase<simd<int8_t, avx2>>());

        CHECK(test_sub_zero_cornercase<simd<uint16_t, avx2>>());

        CHECK(test_sub_zero_cornercase<simd<uint32_t, avx2>>());

        CHECK(test_sub_zero_cornercase<simd<uint64_t, avx2>>());

        CHECK(test_sub_zero_cornercase<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'sub' for avx512", "[sub],[avx512]") {
    using namespace tsl;
    SECTION("running_sum_w_epsilon") {
        CHECK(test_sub_running_sum_w_epsilon<simd<double, avx512>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<float, avx512>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int16_t, avx512>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int32_t, avx512>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int64_t, avx512>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int8_t, avx512>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint16_t, avx512>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint32_t, avx512>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint64_t, avx512>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint8_t, avx512>>());

    }
    SECTION("zero_cornercase") {
        CHECK(test_sub_zero_cornercase<simd<double, avx512>>());

        CHECK(test_sub_zero_cornercase<simd<float, avx512>>());

        CHECK(test_sub_zero_cornercase<simd<int16_t, avx512>>());

        CHECK(test_sub_zero_cornercase<simd<int32_t, avx512>>());

        CHECK(test_sub_zero_cornercase<simd<int64_t, avx512>>());

        CHECK(test_sub_zero_cornercase<simd<int8_t, avx512>>());

        CHECK(test_sub_zero_cornercase<simd<uint16_t, avx512>>());

        CHECK(test_sub_zero_cornercase<simd<uint32_t, avx512>>());

        CHECK(test_sub_zero_cornercase<simd<uint64_t, avx512>>());

        CHECK(test_sub_zero_cornercase<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'sub' for scalar", "[sub],[scalar]") {
    using namespace tsl;
    SECTION("running_sum_w_epsilon") {
        CHECK(test_sub_running_sum_w_epsilon<simd<double, scalar>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<float, scalar>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int16_t, scalar>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int32_t, scalar>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int64_t, scalar>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int8_t, scalar>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint16_t, scalar>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint32_t, scalar>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint64_t, scalar>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint8_t, scalar>>());

    }
    SECTION("zero_cornercase") {
        CHECK(test_sub_zero_cornercase<simd<double, scalar>>());

        CHECK(test_sub_zero_cornercase<simd<float, scalar>>());

        CHECK(test_sub_zero_cornercase<simd<int16_t, scalar>>());

        CHECK(test_sub_zero_cornercase<simd<int32_t, scalar>>());

        CHECK(test_sub_zero_cornercase<simd<int64_t, scalar>>());

        CHECK(test_sub_zero_cornercase<simd<int8_t, scalar>>());

        CHECK(test_sub_zero_cornercase<simd<uint16_t, scalar>>());

        CHECK(test_sub_zero_cornercase<simd<uint32_t, scalar>>());

        CHECK(test_sub_zero_cornercase<simd<uint64_t, scalar>>());

        CHECK(test_sub_zero_cornercase<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'sub' for sse", "[sub],[sse]") {
    using namespace tsl;
    SECTION("running_sum_w_epsilon") {
        CHECK(test_sub_running_sum_w_epsilon<simd<double, sse>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<float, sse>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int16_t, sse>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int32_t, sse>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int64_t, sse>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<int8_t, sse>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint16_t, sse>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint32_t, sse>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint64_t, sse>>());

        CHECK(test_sub_running_sum_w_epsilon<simd<uint8_t, sse>>());

    }
    SECTION("zero_cornercase") {
        CHECK(test_sub_zero_cornercase<simd<double, sse>>());

        CHECK(test_sub_zero_cornercase<simd<float, sse>>());

        CHECK(test_sub_zero_cornercase<simd<int16_t, sse>>());

        CHECK(test_sub_zero_cornercase<simd<int32_t, sse>>());

        CHECK(test_sub_zero_cornercase<simd<int64_t, sse>>());

        CHECK(test_sub_zero_cornercase<simd<int8_t, sse>>());

        CHECK(test_sub_zero_cornercase<simd<uint16_t, sse>>());

        CHECK(test_sub_zero_cornercase<simd<uint32_t, sse>>());

        CHECK(test_sub_zero_cornercase<simd<uint64_t, sse>>());

        CHECK(test_sub_zero_cornercase<simd<uint8_t, sse>>());

    }
}

