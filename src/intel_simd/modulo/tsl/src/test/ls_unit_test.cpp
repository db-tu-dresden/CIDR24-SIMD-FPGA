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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/src/test/ls_unit_test.cpp
 * \date 2023-07-22
 * \brief Unit test file for TSL Primitives using Catch2
 * \note
 *
 */

#include <tslintrin.hpp>
#include <cstddef>
#include <algorithm>
#include <limits>
#include <cstring>
#include <type_traits>
#include "test_functions.hpp"

namespace tsl {
    template<VectorProcessingStyle Vec>
    bool test_set1_default() {
        using namespace tsl;
        std::size_t element_count = 1024;
        bool allOk = true;
        testing::test_memory_helper_t<Vec> test_helper{Vec::vector_element_count(), false};
        const std::size_t limit = std::min((std::size_t) 4096, (std::size_t) std::numeric_limits<typename Vec::base_type>::max());
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < limit; ++i) {
          auto vec = set1<Vec>(i);
          for(std::size_t j = 0; j < Vec::vector_element_count(); j++) {
              reference_result_ptr[j] = i;
          }
          allOk &= test_helper.validate_simd_register(vec);
        }
        const auto maxval = std::numeric_limits<typename Vec::base_type>::max();
        auto max_vec = set1<Vec>(maxval);
        for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
          reference_result_ptr[i] = maxval;
        }
        allOk &= test_helper.validate_simd_register(max_vec);
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_store_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{Vec::vector_element_count(), true};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          for(size_t j = i; j < i + Vec::vector_element_count(); ++j) {
              reference_result_ptr[j-i] = i;
          }
          auto loaded = set1<Vec>(i);
          store<Vec>(test_result_ptr, loaded);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_storeu_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{Vec::vector_element_count(), false};
        bool allOk = true;
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          for(size_t j = i; j < i + Vec::vector_element_count(); ++j) {
              reference_result_ptr[j-i] = i;
          }
          auto loaded = set1<Vec>(i);
          storeu<Vec>(test_result_ptr, loaded);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_load_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), true};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
          for(size_t j = i; j < i + Vec::vector_element_count(); ++j) {
              reference_result_ptr[j-i] = reference_data_ptr[j];
          }
          auto loaded = load<Vec>(&test_data_ptr[i]);
          storeu<Vec>(test_result_ptr, loaded);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_loadu_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false};
        bool allOk = true;
        auto reference_data_ptr = test_helper.data_ref();
        auto reference_result_ptr = test_helper.result_ref();
        auto test_data_ptr = test_helper.data_target();
        auto test_result_ptr = test_helper.result_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); ++i) {
          for(size_t j = i; j < i + Vec::vector_element_count(); ++j) {
              reference_result_ptr[j-i] = reference_data_ptr[j];
          }
          auto loaded = loadu<Vec>(&test_data_ptr[i]);
          storeu<Vec>(test_result_ptr, loaded);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_set_default() {
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
          for(size_t j = i; j < i + Vec::vector_element_count(); ++j) {
              reference_result_ptr[j-i] = reference_data_ptr[j];
          }
          auto loaded = testing::set_call_helper_t<Vec>::call_set(&test_data_ptr[i]);
          storeu<Vec>(test_result_ptr, loaded);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_extract_value_default() {
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
          *reference_result_ptr = reference_data_ptr[i];

          auto vec = loadu<Vec>(&test_data_ptr[i]);
          *test_result_ptr = extract_value<Vec, 0>(vec);
          test_helper.synchronize();
          allOk &= test_helper.validate();
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec, VectorProcessingStyle IndicesType>
    bool test_gather_default() {
        using namespace tsl;
        constexpr size_t test_mem_size = 256;
        constexpr size_t test_mem_offset = test_mem_size / 2;
        constexpr size_t iteration_count = 16;
        testing::test_memory_helper_t<Vec> test_helper{test_mem_size, Vec::vector_element_count(), true, testing::seq_init_start_0<typename Vec::base_type>};
        testing::test_memory_helper_t<IndicesType> test_helper_indices{
            iteration_count * Vec::vector_element_count(), 0, true,
            testing::rnd_init_bounded<typename IndicesType::base_type>,
            (typename IndicesType::base_type)(std::is_signed_v<typename IndicesType::base_type> ? -test_mem_offset : 0),
            (typename IndicesType::base_type)(test_mem_offset - 1)
        };
        for(size_t i = 0; i < iteration_count; i++) {
            for(size_t j = 0; j < Vec::vector_element_count(); j++) {
                test_helper.result_ref()[j] = test_helper.data_ref()[test_helper_indices.data_ref()[i * Vec::vector_element_count() + j] + test_mem_offset];
            }
            auto indices = loadu<IndicesType>(test_helper_indices.data_target() + (i * Vec::vector_element_count()));
            auto result = gather<Vec, IndicesType>(test_helper.data_target() + test_mem_offset, indices);
            store<Vec>(test_helper.result_target(), result);
            test_helper.synchronize();
            if (!test_helper.validate()) return false;
        }
        return true;

    }
    template<VectorProcessingStyle Vec>
    bool test_mask_mov_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        bool allOk = true;
        testing::test_memory_helper_t<Vec> test_helper{element_count * 2, Vec::vector_element_count(), false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto test_data_ptr = test_helper.data_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            typename Vec::imask_type random_integral;
            testing::rnd_init(&random_integral, 1);
            auto src = &test_data_ptr[i];
            auto data = &test_data_ptr[element_count + i];
            auto result = mask_mov<Vec>(loadu<Vec>(src), random_integral, loadu<Vec>(data));
            for(std::size_t j = 0; j < Vec::vector_element_count(); j++) {
                reference_result_ptr[j] = (random_integral >> j) & 1 ? data[j] : src[j];
            }
            allOk &= test_helper.validate_simd_register(result);
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_masked_set1_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        bool allOk = true;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto test_data_ptr = test_helper.data_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
            T random_value;
            testing::rnd_init(&random_value, 1);
            typename Vec::imask_type random_integral;
            testing::rnd_init(&random_integral, 1);
            auto vec_src = loadu<Vec>( &test_data_ptr[i] );
            auto result = masked_set1<Vec>(vec_src, random_integral, random_value);
            for(std::size_t j = 0; j < Vec::vector_element_count(); j++) {
                reference_result_ptr[j] = (random_integral >> j) & 1 ? random_value : test_data_ptr[i + j];
            }
            allOk &= test_helper.validate_simd_register(result);
        }
        return allOk;

    }
    template<VectorProcessingStyle Vec>
    bool test_maskz_mov_default() {
        using namespace tsl;
        using T = typename Vec::base_type;
        std::size_t element_count = 1024;
        bool allOk = true;
        testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false};
        auto reference_result_ptr = test_helper.result_ref();
        auto test_result_ptr = test_helper.result_target();
        auto test_data_ptr = test_helper.data_target();
        for(std::size_t i = 0; i < element_count - Vec::vector_element_count(); i+=Vec::vector_element_count()) {
           typename Vec::imask_type random_integral;
           testing::rnd_init(&random_integral, 1);
           auto src = &test_data_ptr[i];
           auto result = maskz_mov<Vec>(random_integral, loadu<Vec>(src));
           for(std::size_t j = 0; j < Vec::vector_element_count(); j++) {
              reference_result_ptr[j] = (random_integral >> j) & 1 ? src[j] : 0;
           }
           allOk &= test_helper.validate_simd_register(result);
        }
        return allOk;

    }
}

TEST_CASE("Testing primitive 'set1' for avx2", "[set1],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_set1_default<simd<double, avx2>>());

        CHECK(test_set1_default<simd<float, avx2>>());

        CHECK(test_set1_default<simd<int16_t, avx2>>());

        CHECK(test_set1_default<simd<int32_t, avx2>>());

        CHECK(test_set1_default<simd<int64_t, avx2>>());

        CHECK(test_set1_default<simd<int8_t, avx2>>());

        CHECK(test_set1_default<simd<uint16_t, avx2>>());

        CHECK(test_set1_default<simd<uint32_t, avx2>>());

        CHECK(test_set1_default<simd<uint64_t, avx2>>());

        CHECK(test_set1_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'set1' for avx512", "[set1],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_set1_default<simd<double, avx512>>());

        CHECK(test_set1_default<simd<float, avx512>>());

        CHECK(test_set1_default<simd<int16_t, avx512>>());

        CHECK(test_set1_default<simd<int32_t, avx512>>());

        CHECK(test_set1_default<simd<int64_t, avx512>>());

        CHECK(test_set1_default<simd<int8_t, avx512>>());

        CHECK(test_set1_default<simd<uint16_t, avx512>>());

        CHECK(test_set1_default<simd<uint32_t, avx512>>());

        CHECK(test_set1_default<simd<uint64_t, avx512>>());

        CHECK(test_set1_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'set1' for scalar", "[set1],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_set1_default<simd<double, scalar>>());

        CHECK(test_set1_default<simd<float, scalar>>());

        CHECK(test_set1_default<simd<int16_t, scalar>>());

        CHECK(test_set1_default<simd<int32_t, scalar>>());

        CHECK(test_set1_default<simd<int64_t, scalar>>());

        CHECK(test_set1_default<simd<int8_t, scalar>>());

        CHECK(test_set1_default<simd<uint16_t, scalar>>());

        CHECK(test_set1_default<simd<uint32_t, scalar>>());

        CHECK(test_set1_default<simd<uint64_t, scalar>>());

        CHECK(test_set1_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'set1' for sse", "[set1],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_set1_default<simd<double, sse>>());

        CHECK(test_set1_default<simd<float, sse>>());

        CHECK(test_set1_default<simd<int16_t, sse>>());

        CHECK(test_set1_default<simd<int32_t, sse>>());

        CHECK(test_set1_default<simd<int64_t, sse>>());

        CHECK(test_set1_default<simd<int8_t, sse>>());

        CHECK(test_set1_default<simd<uint16_t, sse>>());

        CHECK(test_set1_default<simd<uint32_t, sse>>());

        CHECK(test_set1_default<simd<uint64_t, sse>>());

        CHECK(test_set1_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'store' for avx2", "[store],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_store_default<simd<double, avx2>>());

        CHECK(test_store_default<simd<float, avx2>>());

        CHECK(test_store_default<simd<int16_t, avx2>>());

        CHECK(test_store_default<simd<int32_t, avx2>>());

        CHECK(test_store_default<simd<int64_t, avx2>>());

        CHECK(test_store_default<simd<int8_t, avx2>>());

        CHECK(test_store_default<simd<uint16_t, avx2>>());

        CHECK(test_store_default<simd<uint32_t, avx2>>());

        CHECK(test_store_default<simd<uint64_t, avx2>>());

        CHECK(test_store_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'store' for avx512", "[store],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_store_default<simd<double, avx512>>());

        CHECK(test_store_default<simd<float, avx512>>());

        CHECK(test_store_default<simd<int16_t, avx512>>());

        CHECK(test_store_default<simd<int32_t, avx512>>());

        CHECK(test_store_default<simd<int64_t, avx512>>());

        CHECK(test_store_default<simd<int8_t, avx512>>());

        CHECK(test_store_default<simd<uint16_t, avx512>>());

        CHECK(test_store_default<simd<uint32_t, avx512>>());

        CHECK(test_store_default<simd<uint64_t, avx512>>());

        CHECK(test_store_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'store' for scalar", "[store],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_store_default<simd<double, scalar>>());

        CHECK(test_store_default<simd<float, scalar>>());

        CHECK(test_store_default<simd<int16_t, scalar>>());

        CHECK(test_store_default<simd<int32_t, scalar>>());

        CHECK(test_store_default<simd<int64_t, scalar>>());

        CHECK(test_store_default<simd<int8_t, scalar>>());

        CHECK(test_store_default<simd<uint16_t, scalar>>());

        CHECK(test_store_default<simd<uint32_t, scalar>>());

        CHECK(test_store_default<simd<uint64_t, scalar>>());

        CHECK(test_store_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'store' for sse", "[store],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_store_default<simd<double, sse>>());

        CHECK(test_store_default<simd<float, sse>>());

        CHECK(test_store_default<simd<int16_t, sse>>());

        CHECK(test_store_default<simd<int32_t, sse>>());

        CHECK(test_store_default<simd<int64_t, sse>>());

        CHECK(test_store_default<simd<int8_t, sse>>());

        CHECK(test_store_default<simd<uint16_t, sse>>());

        CHECK(test_store_default<simd<uint32_t, sse>>());

        CHECK(test_store_default<simd<uint64_t, sse>>());

        CHECK(test_store_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'storeu' for avx2", "[storeu],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_storeu_default<simd<double, avx2>>());

        CHECK(test_storeu_default<simd<float, avx2>>());

        CHECK(test_storeu_default<simd<int16_t, avx2>>());

        CHECK(test_storeu_default<simd<int32_t, avx2>>());

        CHECK(test_storeu_default<simd<int64_t, avx2>>());

        CHECK(test_storeu_default<simd<int8_t, avx2>>());

        CHECK(test_storeu_default<simd<uint16_t, avx2>>());

        CHECK(test_storeu_default<simd<uint32_t, avx2>>());

        CHECK(test_storeu_default<simd<uint64_t, avx2>>());

        CHECK(test_storeu_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'storeu' for avx512", "[storeu],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_storeu_default<simd<double, avx512>>());

        CHECK(test_storeu_default<simd<float, avx512>>());

        CHECK(test_storeu_default<simd<int16_t, avx512>>());

        CHECK(test_storeu_default<simd<int32_t, avx512>>());

        CHECK(test_storeu_default<simd<int64_t, avx512>>());

        CHECK(test_storeu_default<simd<int8_t, avx512>>());

        CHECK(test_storeu_default<simd<uint16_t, avx512>>());

        CHECK(test_storeu_default<simd<uint32_t, avx512>>());

        CHECK(test_storeu_default<simd<uint64_t, avx512>>());

        CHECK(test_storeu_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'storeu' for scalar", "[storeu],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_storeu_default<simd<double, scalar>>());

        CHECK(test_storeu_default<simd<float, scalar>>());

        CHECK(test_storeu_default<simd<int16_t, scalar>>());

        CHECK(test_storeu_default<simd<int32_t, scalar>>());

        CHECK(test_storeu_default<simd<int64_t, scalar>>());

        CHECK(test_storeu_default<simd<int8_t, scalar>>());

        CHECK(test_storeu_default<simd<uint16_t, scalar>>());

        CHECK(test_storeu_default<simd<uint32_t, scalar>>());

        CHECK(test_storeu_default<simd<uint64_t, scalar>>());

        CHECK(test_storeu_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'storeu' for sse", "[storeu],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_storeu_default<simd<double, sse>>());

        CHECK(test_storeu_default<simd<float, sse>>());

        CHECK(test_storeu_default<simd<int16_t, sse>>());

        CHECK(test_storeu_default<simd<int32_t, sse>>());

        CHECK(test_storeu_default<simd<int64_t, sse>>());

        CHECK(test_storeu_default<simd<int8_t, sse>>());

        CHECK(test_storeu_default<simd<uint16_t, sse>>());

        CHECK(test_storeu_default<simd<uint32_t, sse>>());

        CHECK(test_storeu_default<simd<uint64_t, sse>>());

        CHECK(test_storeu_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'load' for avx2", "[load],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_load_default<simd<double, avx2>>());

        CHECK(test_load_default<simd<float, avx2>>());

        CHECK(test_load_default<simd<int16_t, avx2>>());

        CHECK(test_load_default<simd<int32_t, avx2>>());

        CHECK(test_load_default<simd<int64_t, avx2>>());

        CHECK(test_load_default<simd<int8_t, avx2>>());

        CHECK(test_load_default<simd<uint16_t, avx2>>());

        CHECK(test_load_default<simd<uint32_t, avx2>>());

        CHECK(test_load_default<simd<uint64_t, avx2>>());

        CHECK(test_load_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'load' for avx512", "[load],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_load_default<simd<double, avx512>>());

        CHECK(test_load_default<simd<float, avx512>>());

        CHECK(test_load_default<simd<int16_t, avx512>>());

        CHECK(test_load_default<simd<int32_t, avx512>>());

        CHECK(test_load_default<simd<int64_t, avx512>>());

        CHECK(test_load_default<simd<int8_t, avx512>>());

        CHECK(test_load_default<simd<uint16_t, avx512>>());

        CHECK(test_load_default<simd<uint32_t, avx512>>());

        CHECK(test_load_default<simd<uint64_t, avx512>>());

        CHECK(test_load_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'load' for scalar", "[load],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_load_default<simd<double, scalar>>());

        CHECK(test_load_default<simd<float, scalar>>());

        CHECK(test_load_default<simd<int16_t, scalar>>());

        CHECK(test_load_default<simd<int32_t, scalar>>());

        CHECK(test_load_default<simd<int64_t, scalar>>());

        CHECK(test_load_default<simd<int8_t, scalar>>());

        CHECK(test_load_default<simd<uint16_t, scalar>>());

        CHECK(test_load_default<simd<uint32_t, scalar>>());

        CHECK(test_load_default<simd<uint64_t, scalar>>());

        CHECK(test_load_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'load' for sse", "[load],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_load_default<simd<double, sse>>());

        CHECK(test_load_default<simd<float, sse>>());

        CHECK(test_load_default<simd<int16_t, sse>>());

        CHECK(test_load_default<simd<int32_t, sse>>());

        CHECK(test_load_default<simd<int64_t, sse>>());

        CHECK(test_load_default<simd<int8_t, sse>>());

        CHECK(test_load_default<simd<uint16_t, sse>>());

        CHECK(test_load_default<simd<uint32_t, sse>>());

        CHECK(test_load_default<simd<uint64_t, sse>>());

        CHECK(test_load_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'loadu' for avx2", "[loadu],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_loadu_default<simd<double, avx2>>());

        CHECK(test_loadu_default<simd<float, avx2>>());

        CHECK(test_loadu_default<simd<int16_t, avx2>>());

        CHECK(test_loadu_default<simd<int32_t, avx2>>());

        CHECK(test_loadu_default<simd<int64_t, avx2>>());

        CHECK(test_loadu_default<simd<int8_t, avx2>>());

        CHECK(test_loadu_default<simd<uint16_t, avx2>>());

        CHECK(test_loadu_default<simd<uint32_t, avx2>>());

        CHECK(test_loadu_default<simd<uint64_t, avx2>>());

        CHECK(test_loadu_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'loadu' for avx512", "[loadu],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_loadu_default<simd<double, avx512>>());

        CHECK(test_loadu_default<simd<float, avx512>>());

        CHECK(test_loadu_default<simd<int16_t, avx512>>());

        CHECK(test_loadu_default<simd<int32_t, avx512>>());

        CHECK(test_loadu_default<simd<int64_t, avx512>>());

        CHECK(test_loadu_default<simd<int8_t, avx512>>());

        CHECK(test_loadu_default<simd<uint16_t, avx512>>());

        CHECK(test_loadu_default<simd<uint32_t, avx512>>());

        CHECK(test_loadu_default<simd<uint64_t, avx512>>());

        CHECK(test_loadu_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'loadu' for scalar", "[loadu],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_loadu_default<simd<double, scalar>>());

        CHECK(test_loadu_default<simd<float, scalar>>());

        CHECK(test_loadu_default<simd<int16_t, scalar>>());

        CHECK(test_loadu_default<simd<int32_t, scalar>>());

        CHECK(test_loadu_default<simd<int64_t, scalar>>());

        CHECK(test_loadu_default<simd<int8_t, scalar>>());

        CHECK(test_loadu_default<simd<uint16_t, scalar>>());

        CHECK(test_loadu_default<simd<uint32_t, scalar>>());

        CHECK(test_loadu_default<simd<uint64_t, scalar>>());

        CHECK(test_loadu_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'loadu' for sse", "[loadu],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_loadu_default<simd<double, sse>>());

        CHECK(test_loadu_default<simd<float, sse>>());

        CHECK(test_loadu_default<simd<int16_t, sse>>());

        CHECK(test_loadu_default<simd<int32_t, sse>>());

        CHECK(test_loadu_default<simd<int64_t, sse>>());

        CHECK(test_loadu_default<simd<int8_t, sse>>());

        CHECK(test_loadu_default<simd<uint16_t, sse>>());

        CHECK(test_loadu_default<simd<uint32_t, sse>>());

        CHECK(test_loadu_default<simd<uint64_t, sse>>());

        CHECK(test_loadu_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'set' for avx2", "[set],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_set_default<simd<double, avx2>>());

        CHECK(test_set_default<simd<float, avx2>>());

        CHECK(test_set_default<simd<int16_t, avx2>>());

        CHECK(test_set_default<simd<int32_t, avx2>>());

        CHECK(test_set_default<simd<int64_t, avx2>>());

        CHECK(test_set_default<simd<int8_t, avx2>>());

        CHECK(test_set_default<simd<uint16_t, avx2>>());

        CHECK(test_set_default<simd<uint32_t, avx2>>());

        CHECK(test_set_default<simd<uint64_t, avx2>>());

        CHECK(test_set_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'set' for avx512", "[set],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_set_default<simd<double, avx512>>());

        CHECK(test_set_default<simd<float, avx512>>());

        CHECK(test_set_default<simd<int16_t, avx512>>());

        CHECK(test_set_default<simd<int32_t, avx512>>());

        CHECK(test_set_default<simd<int64_t, avx512>>());

        CHECK(test_set_default<simd<int8_t, avx512>>());

        CHECK(test_set_default<simd<uint16_t, avx512>>());

        CHECK(test_set_default<simd<uint32_t, avx512>>());

        CHECK(test_set_default<simd<uint64_t, avx512>>());

        CHECK(test_set_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'set' for scalar", "[set],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_set_default<simd<double, scalar>>());

        CHECK(test_set_default<simd<float, scalar>>());

        CHECK(test_set_default<simd<int16_t, scalar>>());

        CHECK(test_set_default<simd<int32_t, scalar>>());

        CHECK(test_set_default<simd<int64_t, scalar>>());

        CHECK(test_set_default<simd<int8_t, scalar>>());

        CHECK(test_set_default<simd<uint16_t, scalar>>());

        CHECK(test_set_default<simd<uint32_t, scalar>>());

        CHECK(test_set_default<simd<uint64_t, scalar>>());

        CHECK(test_set_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'set' for sse", "[set],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_set_default<simd<double, sse>>());

        CHECK(test_set_default<simd<float, sse>>());

        CHECK(test_set_default<simd<int16_t, sse>>());

        CHECK(test_set_default<simd<int32_t, sse>>());

        CHECK(test_set_default<simd<int64_t, sse>>());

        CHECK(test_set_default<simd<int8_t, sse>>());

        CHECK(test_set_default<simd<uint16_t, sse>>());

        CHECK(test_set_default<simd<uint32_t, sse>>());

        CHECK(test_set_default<simd<uint64_t, sse>>());

        CHECK(test_set_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'extract_value' for avx2", "[extract_value],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_extract_value_default<simd<double, avx2>>());

        CHECK(test_extract_value_default<simd<float, avx2>>());

        CHECK(test_extract_value_default<simd<int16_t, avx2>>());

        CHECK(test_extract_value_default<simd<int32_t, avx2>>());

        CHECK(test_extract_value_default<simd<int64_t, avx2>>());

        CHECK(test_extract_value_default<simd<int8_t, avx2>>());

        CHECK(test_extract_value_default<simd<uint16_t, avx2>>());

        CHECK(test_extract_value_default<simd<uint32_t, avx2>>());

        CHECK(test_extract_value_default<simd<uint64_t, avx2>>());

        CHECK(test_extract_value_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'extract_value' for avx512", "[extract_value],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_extract_value_default<simd<double, avx512>>());

        CHECK(test_extract_value_default<simd<float, avx512>>());

        CHECK(test_extract_value_default<simd<int16_t, avx512>>());

        CHECK(test_extract_value_default<simd<int32_t, avx512>>());

        CHECK(test_extract_value_default<simd<int64_t, avx512>>());

        CHECK(test_extract_value_default<simd<int8_t, avx512>>());

        CHECK(test_extract_value_default<simd<uint16_t, avx512>>());

        CHECK(test_extract_value_default<simd<uint32_t, avx512>>());

        CHECK(test_extract_value_default<simd<uint64_t, avx512>>());

        CHECK(test_extract_value_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'extract_value' for scalar", "[extract_value],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_extract_value_default<simd<double, scalar>>());

        CHECK(test_extract_value_default<simd<float, scalar>>());

        CHECK(test_extract_value_default<simd<int16_t, scalar>>());

        CHECK(test_extract_value_default<simd<int32_t, scalar>>());

        CHECK(test_extract_value_default<simd<int64_t, scalar>>());

        CHECK(test_extract_value_default<simd<int8_t, scalar>>());

        CHECK(test_extract_value_default<simd<uint16_t, scalar>>());

        CHECK(test_extract_value_default<simd<uint32_t, scalar>>());

        CHECK(test_extract_value_default<simd<uint64_t, scalar>>());

        CHECK(test_extract_value_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'extract_value' for sse", "[extract_value],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_extract_value_default<simd<double, sse>>());

        CHECK(test_extract_value_default<simd<float, sse>>());

        CHECK(test_extract_value_default<simd<int16_t, sse>>());

        CHECK(test_extract_value_default<simd<int32_t, sse>>());

        CHECK(test_extract_value_default<simd<int64_t, sse>>());

        CHECK(test_extract_value_default<simd<int8_t, sse>>());

        CHECK(test_extract_value_default<simd<uint16_t, sse>>());

        CHECK(test_extract_value_default<simd<uint32_t, sse>>());

        CHECK(test_extract_value_default<simd<uint64_t, sse>>());

        CHECK(test_extract_value_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'gather' for avx2", "[gather],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive gather not implemented for avx2");
    }
}
TEST_CASE("Testing primitive 'gather' for avx512", "[gather],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_gather_default<simd<double, avx512>, simd<int64_t, avx512>>());
        CHECK(test_gather_default<simd<double, avx512>, simd<uint64_t, avx512>>());
        CHECK(test_gather_default<simd<double, avx512>, simd<int32_t, avx2>>());
        CHECK(test_gather_default<simd<double, avx512>, simd<uint32_t, avx2>>());

        CHECK(test_gather_default<simd<float, avx512>, simd<int32_t, avx512>>());
        CHECK(test_gather_default<simd<float, avx512>, simd<uint32_t, avx512>>());

        WARN("Primitive gather<simd<int16_t, avx512>> not implemented.");
        CHECK(test_gather_default<simd<int32_t, avx512>, simd<int32_t, avx512>>());
        CHECK(test_gather_default<simd<int32_t, avx512>, simd<uint32_t, avx512>>());

        CHECK(test_gather_default<simd<int64_t, avx512>, simd<int64_t, avx512>>());
        CHECK(test_gather_default<simd<int64_t, avx512>, simd<uint64_t, avx512>>());
        CHECK(test_gather_default<simd<int64_t, avx512>, simd<int32_t, avx2>>());
        CHECK(test_gather_default<simd<int64_t, avx512>, simd<uint32_t, avx2>>());

        WARN("Primitive gather<simd<int8_t, avx512>> not implemented.");
        WARN("Primitive gather<simd<uint16_t, avx512>> not implemented.");
        CHECK(test_gather_default<simd<uint32_t, avx512>, simd<int32_t, avx512>>());
        CHECK(test_gather_default<simd<uint32_t, avx512>, simd<uint32_t, avx512>>());

        CHECK(test_gather_default<simd<uint64_t, avx512>, simd<int64_t, avx512>>());
        CHECK(test_gather_default<simd<uint64_t, avx512>, simd<uint64_t, avx512>>());
        CHECK(test_gather_default<simd<uint64_t, avx512>, simd<int32_t, avx2>>());
        CHECK(test_gather_default<simd<uint64_t, avx512>, simd<uint32_t, avx2>>());

        WARN("Primitive gather<simd<uint8_t, avx512>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'gather' for scalar", "[gather],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_gather_default<simd<double, scalar>, simd<int8_t, scalar>>());
        CHECK(test_gather_default<simd<double, scalar>, simd<uint8_t, scalar>>());
        CHECK(test_gather_default<simd<double, scalar>, simd<int16_t, scalar>>());
        CHECK(test_gather_default<simd<double, scalar>, simd<uint16_t, scalar>>());
        CHECK(test_gather_default<simd<double, scalar>, simd<int32_t, scalar>>());
        CHECK(test_gather_default<simd<double, scalar>, simd<uint32_t, scalar>>());
        CHECK(test_gather_default<simd<double, scalar>, simd<int64_t, scalar>>());
        CHECK(test_gather_default<simd<double, scalar>, simd<uint64_t, scalar>>());

        CHECK(test_gather_default<simd<float, scalar>, simd<int8_t, scalar>>());
        CHECK(test_gather_default<simd<float, scalar>, simd<uint8_t, scalar>>());
        CHECK(test_gather_default<simd<float, scalar>, simd<int16_t, scalar>>());
        CHECK(test_gather_default<simd<float, scalar>, simd<uint16_t, scalar>>());
        CHECK(test_gather_default<simd<float, scalar>, simd<int32_t, scalar>>());
        CHECK(test_gather_default<simd<float, scalar>, simd<uint32_t, scalar>>());
        CHECK(test_gather_default<simd<float, scalar>, simd<int64_t, scalar>>());
        CHECK(test_gather_default<simd<float, scalar>, simd<uint64_t, scalar>>());

        CHECK(test_gather_default<simd<int16_t, scalar>, simd<int8_t, scalar>>());
        CHECK(test_gather_default<simd<int16_t, scalar>, simd<uint8_t, scalar>>());
        CHECK(test_gather_default<simd<int16_t, scalar>, simd<int16_t, scalar>>());
        CHECK(test_gather_default<simd<int16_t, scalar>, simd<uint16_t, scalar>>());
        CHECK(test_gather_default<simd<int16_t, scalar>, simd<int32_t, scalar>>());
        CHECK(test_gather_default<simd<int16_t, scalar>, simd<uint32_t, scalar>>());
        CHECK(test_gather_default<simd<int16_t, scalar>, simd<int64_t, scalar>>());
        CHECK(test_gather_default<simd<int16_t, scalar>, simd<uint64_t, scalar>>());

        CHECK(test_gather_default<simd<int32_t, scalar>, simd<int8_t, scalar>>());
        CHECK(test_gather_default<simd<int32_t, scalar>, simd<uint8_t, scalar>>());
        CHECK(test_gather_default<simd<int32_t, scalar>, simd<int16_t, scalar>>());
        CHECK(test_gather_default<simd<int32_t, scalar>, simd<uint16_t, scalar>>());
        CHECK(test_gather_default<simd<int32_t, scalar>, simd<int32_t, scalar>>());
        CHECK(test_gather_default<simd<int32_t, scalar>, simd<uint32_t, scalar>>());
        CHECK(test_gather_default<simd<int32_t, scalar>, simd<int64_t, scalar>>());
        CHECK(test_gather_default<simd<int32_t, scalar>, simd<uint64_t, scalar>>());

        CHECK(test_gather_default<simd<int64_t, scalar>, simd<int8_t, scalar>>());
        CHECK(test_gather_default<simd<int64_t, scalar>, simd<uint8_t, scalar>>());
        CHECK(test_gather_default<simd<int64_t, scalar>, simd<int16_t, scalar>>());
        CHECK(test_gather_default<simd<int64_t, scalar>, simd<uint16_t, scalar>>());
        CHECK(test_gather_default<simd<int64_t, scalar>, simd<int32_t, scalar>>());
        CHECK(test_gather_default<simd<int64_t, scalar>, simd<uint32_t, scalar>>());
        CHECK(test_gather_default<simd<int64_t, scalar>, simd<int64_t, scalar>>());
        CHECK(test_gather_default<simd<int64_t, scalar>, simd<uint64_t, scalar>>());

        CHECK(test_gather_default<simd<int8_t, scalar>, simd<int8_t, scalar>>());
        CHECK(test_gather_default<simd<int8_t, scalar>, simd<uint8_t, scalar>>());
        CHECK(test_gather_default<simd<int8_t, scalar>, simd<int16_t, scalar>>());
        CHECK(test_gather_default<simd<int8_t, scalar>, simd<uint16_t, scalar>>());
        CHECK(test_gather_default<simd<int8_t, scalar>, simd<int32_t, scalar>>());
        CHECK(test_gather_default<simd<int8_t, scalar>, simd<uint32_t, scalar>>());
        CHECK(test_gather_default<simd<int8_t, scalar>, simd<int64_t, scalar>>());
        CHECK(test_gather_default<simd<int8_t, scalar>, simd<uint64_t, scalar>>());

        CHECK(test_gather_default<simd<uint16_t, scalar>, simd<int8_t, scalar>>());
        CHECK(test_gather_default<simd<uint16_t, scalar>, simd<uint8_t, scalar>>());
        CHECK(test_gather_default<simd<uint16_t, scalar>, simd<int16_t, scalar>>());
        CHECK(test_gather_default<simd<uint16_t, scalar>, simd<uint16_t, scalar>>());
        CHECK(test_gather_default<simd<uint16_t, scalar>, simd<int32_t, scalar>>());
        CHECK(test_gather_default<simd<uint16_t, scalar>, simd<uint32_t, scalar>>());
        CHECK(test_gather_default<simd<uint16_t, scalar>, simd<int64_t, scalar>>());
        CHECK(test_gather_default<simd<uint16_t, scalar>, simd<uint64_t, scalar>>());

        CHECK(test_gather_default<simd<uint32_t, scalar>, simd<int8_t, scalar>>());
        CHECK(test_gather_default<simd<uint32_t, scalar>, simd<uint8_t, scalar>>());
        CHECK(test_gather_default<simd<uint32_t, scalar>, simd<int16_t, scalar>>());
        CHECK(test_gather_default<simd<uint32_t, scalar>, simd<uint16_t, scalar>>());
        CHECK(test_gather_default<simd<uint32_t, scalar>, simd<int32_t, scalar>>());
        CHECK(test_gather_default<simd<uint32_t, scalar>, simd<uint32_t, scalar>>());
        CHECK(test_gather_default<simd<uint32_t, scalar>, simd<int64_t, scalar>>());
        CHECK(test_gather_default<simd<uint32_t, scalar>, simd<uint64_t, scalar>>());

        CHECK(test_gather_default<simd<uint64_t, scalar>, simd<int8_t, scalar>>());
        CHECK(test_gather_default<simd<uint64_t, scalar>, simd<uint8_t, scalar>>());
        CHECK(test_gather_default<simd<uint64_t, scalar>, simd<int16_t, scalar>>());
        CHECK(test_gather_default<simd<uint64_t, scalar>, simd<uint16_t, scalar>>());
        CHECK(test_gather_default<simd<uint64_t, scalar>, simd<int32_t, scalar>>());
        CHECK(test_gather_default<simd<uint64_t, scalar>, simd<uint32_t, scalar>>());
        CHECK(test_gather_default<simd<uint64_t, scalar>, simd<int64_t, scalar>>());
        CHECK(test_gather_default<simd<uint64_t, scalar>, simd<uint64_t, scalar>>());

        CHECK(test_gather_default<simd<uint8_t, scalar>, simd<int8_t, scalar>>());
        CHECK(test_gather_default<simd<uint8_t, scalar>, simd<uint8_t, scalar>>());
        CHECK(test_gather_default<simd<uint8_t, scalar>, simd<int16_t, scalar>>());
        CHECK(test_gather_default<simd<uint8_t, scalar>, simd<uint16_t, scalar>>());
        CHECK(test_gather_default<simd<uint8_t, scalar>, simd<int32_t, scalar>>());
        CHECK(test_gather_default<simd<uint8_t, scalar>, simd<uint32_t, scalar>>());
        CHECK(test_gather_default<simd<uint8_t, scalar>, simd<int64_t, scalar>>());
        CHECK(test_gather_default<simd<uint8_t, scalar>, simd<uint64_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'gather' for sse", "[gather],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_gather_default<simd<double, sse>, simd<int64_t, sse>>());
        CHECK(test_gather_default<simd<double, sse>, simd<uint64_t, sse>>());

        CHECK(test_gather_default<simd<float, sse>, simd<int32_t, sse>>());
        CHECK(test_gather_default<simd<float, sse>, simd<uint32_t, sse>>());

        CHECK(test_gather_default<simd<int16_t, sse>, simd<int16_t, sse>>());
        CHECK(test_gather_default<simd<int16_t, sse>, simd<uint16_t, sse>>());

        CHECK(test_gather_default<simd<int32_t, sse>, simd<int32_t, sse>>());
        CHECK(test_gather_default<simd<int32_t, sse>, simd<uint32_t, sse>>());

        CHECK(test_gather_default<simd<int64_t, sse>, simd<int64_t, sse>>());
        CHECK(test_gather_default<simd<int64_t, sse>, simd<uint64_t, sse>>());

        CHECK(test_gather_default<simd<int8_t, sse>, simd<int8_t, sse>>());
        CHECK(test_gather_default<simd<int8_t, sse>, simd<uint8_t, sse>>());

        CHECK(test_gather_default<simd<uint16_t, sse>, simd<int16_t, sse>>());
        CHECK(test_gather_default<simd<uint16_t, sse>, simd<uint16_t, sse>>());

        CHECK(test_gather_default<simd<uint32_t, sse>, simd<int32_t, sse>>());
        CHECK(test_gather_default<simd<uint32_t, sse>, simd<uint32_t, sse>>());

        CHECK(test_gather_default<simd<uint64_t, sse>, simd<int64_t, sse>>());
        CHECK(test_gather_default<simd<uint64_t, sse>, simd<uint64_t, sse>>());

        CHECK(test_gather_default<simd<uint8_t, sse>, simd<int8_t, sse>>());
        CHECK(test_gather_default<simd<uint8_t, sse>, simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'mask_mov' for avx2", "[mask_mov],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_mask_mov_default<simd<double, avx2>>());

        CHECK(test_mask_mov_default<simd<float, avx2>>());

        CHECK(test_mask_mov_default<simd<int16_t, avx2>>());

        CHECK(test_mask_mov_default<simd<int32_t, avx2>>());

        CHECK(test_mask_mov_default<simd<int64_t, avx2>>());

        CHECK(test_mask_mov_default<simd<int8_t, avx2>>());

        CHECK(test_mask_mov_default<simd<uint16_t, avx2>>());

        CHECK(test_mask_mov_default<simd<uint32_t, avx2>>());

        CHECK(test_mask_mov_default<simd<uint64_t, avx2>>());

        CHECK(test_mask_mov_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'mask_mov' for avx512", "[mask_mov],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_mask_mov_default<simd<double, avx512>>());

        CHECK(test_mask_mov_default<simd<float, avx512>>());

        CHECK(test_mask_mov_default<simd<int16_t, avx512>>());

        CHECK(test_mask_mov_default<simd<int32_t, avx512>>());

        CHECK(test_mask_mov_default<simd<int64_t, avx512>>());

        CHECK(test_mask_mov_default<simd<int8_t, avx512>>());

        CHECK(test_mask_mov_default<simd<uint16_t, avx512>>());

        CHECK(test_mask_mov_default<simd<uint32_t, avx512>>());

        CHECK(test_mask_mov_default<simd<uint64_t, avx512>>());

        CHECK(test_mask_mov_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'mask_mov' for scalar", "[mask_mov],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_mask_mov_default<simd<double, scalar>>());

        CHECK(test_mask_mov_default<simd<float, scalar>>());

        CHECK(test_mask_mov_default<simd<int16_t, scalar>>());

        CHECK(test_mask_mov_default<simd<int32_t, scalar>>());

        CHECK(test_mask_mov_default<simd<int64_t, scalar>>());

        CHECK(test_mask_mov_default<simd<int8_t, scalar>>());

        CHECK(test_mask_mov_default<simd<uint16_t, scalar>>());

        CHECK(test_mask_mov_default<simd<uint32_t, scalar>>());

        CHECK(test_mask_mov_default<simd<uint64_t, scalar>>());

        CHECK(test_mask_mov_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'mask_mov' for sse", "[mask_mov],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_mask_mov_default<simd<double, sse>>());

        CHECK(test_mask_mov_default<simd<float, sse>>());

        CHECK(test_mask_mov_default<simd<int16_t, sse>>());

        CHECK(test_mask_mov_default<simd<int32_t, sse>>());

        CHECK(test_mask_mov_default<simd<int64_t, sse>>());

        CHECK(test_mask_mov_default<simd<int8_t, sse>>());

        CHECK(test_mask_mov_default<simd<uint16_t, sse>>());

        CHECK(test_mask_mov_default<simd<uint32_t, sse>>());

        CHECK(test_mask_mov_default<simd<uint64_t, sse>>());

        CHECK(test_mask_mov_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'masked_set1' for avx2", "[masked_set1],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_masked_set1_default<simd<double, avx2>>());

        CHECK(test_masked_set1_default<simd<float, avx2>>());

        CHECK(test_masked_set1_default<simd<int16_t, avx2>>());

        CHECK(test_masked_set1_default<simd<int32_t, avx2>>());

        CHECK(test_masked_set1_default<simd<int64_t, avx2>>());

        CHECK(test_masked_set1_default<simd<int8_t, avx2>>());

        CHECK(test_masked_set1_default<simd<uint16_t, avx2>>());

        CHECK(test_masked_set1_default<simd<uint32_t, avx2>>());

        CHECK(test_masked_set1_default<simd<uint64_t, avx2>>());

        CHECK(test_masked_set1_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'masked_set1' for avx512", "[masked_set1],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_masked_set1_default<simd<double, avx512>>());

        CHECK(test_masked_set1_default<simd<float, avx512>>());

        CHECK(test_masked_set1_default<simd<int16_t, avx512>>());

        CHECK(test_masked_set1_default<simd<int32_t, avx512>>());

        CHECK(test_masked_set1_default<simd<int64_t, avx512>>());

        CHECK(test_masked_set1_default<simd<int8_t, avx512>>());

        CHECK(test_masked_set1_default<simd<uint16_t, avx512>>());

        CHECK(test_masked_set1_default<simd<uint32_t, avx512>>());

        CHECK(test_masked_set1_default<simd<uint64_t, avx512>>());

        CHECK(test_masked_set1_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'masked_set1' for scalar", "[masked_set1],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_masked_set1_default<simd<double, scalar>>());

        CHECK(test_masked_set1_default<simd<float, scalar>>());

        CHECK(test_masked_set1_default<simd<int16_t, scalar>>());

        CHECK(test_masked_set1_default<simd<int32_t, scalar>>());

        CHECK(test_masked_set1_default<simd<int64_t, scalar>>());

        CHECK(test_masked_set1_default<simd<int8_t, scalar>>());

        CHECK(test_masked_set1_default<simd<uint16_t, scalar>>());

        CHECK(test_masked_set1_default<simd<uint32_t, scalar>>());

        CHECK(test_masked_set1_default<simd<uint64_t, scalar>>());

        CHECK(test_masked_set1_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'masked_set1' for sse", "[masked_set1],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_masked_set1_default<simd<double, sse>>());

        CHECK(test_masked_set1_default<simd<float, sse>>());

        CHECK(test_masked_set1_default<simd<int16_t, sse>>());

        CHECK(test_masked_set1_default<simd<int32_t, sse>>());

        CHECK(test_masked_set1_default<simd<int64_t, sse>>());

        CHECK(test_masked_set1_default<simd<int8_t, sse>>());

        CHECK(test_masked_set1_default<simd<uint16_t, sse>>());

        CHECK(test_masked_set1_default<simd<uint32_t, sse>>());

        CHECK(test_masked_set1_default<simd<uint64_t, sse>>());

        CHECK(test_masked_set1_default<simd<uint8_t, sse>>());

    }
}
TEST_CASE("Testing primitive 'maskz_mov' for avx2", "[maskz_mov],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_maskz_mov_default<simd<double, avx2>>());

        CHECK(test_maskz_mov_default<simd<float, avx2>>());

        CHECK(test_maskz_mov_default<simd<int16_t, avx2>>());

        CHECK(test_maskz_mov_default<simd<int32_t, avx2>>());

        CHECK(test_maskz_mov_default<simd<int64_t, avx2>>());

        CHECK(test_maskz_mov_default<simd<int8_t, avx2>>());

        CHECK(test_maskz_mov_default<simd<uint16_t, avx2>>());

        CHECK(test_maskz_mov_default<simd<uint32_t, avx2>>());

        CHECK(test_maskz_mov_default<simd<uint64_t, avx2>>());

        CHECK(test_maskz_mov_default<simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'maskz_mov' for avx512", "[maskz_mov],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_maskz_mov_default<simd<double, avx512>>());

        CHECK(test_maskz_mov_default<simd<float, avx512>>());

        CHECK(test_maskz_mov_default<simd<int16_t, avx512>>());

        CHECK(test_maskz_mov_default<simd<int32_t, avx512>>());

        CHECK(test_maskz_mov_default<simd<int64_t, avx512>>());

        CHECK(test_maskz_mov_default<simd<int8_t, avx512>>());

        CHECK(test_maskz_mov_default<simd<uint16_t, avx512>>());

        CHECK(test_maskz_mov_default<simd<uint32_t, avx512>>());

        CHECK(test_maskz_mov_default<simd<uint64_t, avx512>>());

        CHECK(test_maskz_mov_default<simd<uint8_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'maskz_mov' for scalar", "[maskz_mov],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_maskz_mov_default<simd<double, scalar>>());

        CHECK(test_maskz_mov_default<simd<float, scalar>>());

        CHECK(test_maskz_mov_default<simd<int16_t, scalar>>());

        CHECK(test_maskz_mov_default<simd<int32_t, scalar>>());

        CHECK(test_maskz_mov_default<simd<int64_t, scalar>>());

        CHECK(test_maskz_mov_default<simd<int8_t, scalar>>());

        CHECK(test_maskz_mov_default<simd<uint16_t, scalar>>());

        CHECK(test_maskz_mov_default<simd<uint32_t, scalar>>());

        CHECK(test_maskz_mov_default<simd<uint64_t, scalar>>());

        CHECK(test_maskz_mov_default<simd<uint8_t, scalar>>());

    }
}
TEST_CASE("Testing primitive 'maskz_mov' for sse", "[maskz_mov],[sse]") {
    using namespace tsl;
    SECTION("default") {
        CHECK(test_maskz_mov_default<simd<double, sse>>());

        CHECK(test_maskz_mov_default<simd<float, sse>>());

        CHECK(test_maskz_mov_default<simd<int16_t, sse>>());

        CHECK(test_maskz_mov_default<simd<int32_t, sse>>());

        CHECK(test_maskz_mov_default<simd<int64_t, sse>>());

        CHECK(test_maskz_mov_default<simd<int8_t, sse>>());

        CHECK(test_maskz_mov_default<simd<uint16_t, sse>>());

        CHECK(test_maskz_mov_default<simd<uint32_t, sse>>());

        CHECK(test_maskz_mov_default<simd<uint64_t, sse>>());

        CHECK(test_maskz_mov_default<simd<uint8_t, sse>>());

    }
}

