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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/src/test/convert_unit_test.cpp
 * \date 2023-07-22
 * \brief Unit test file for TSL Primitives using Catch2
 * \note
 *
 */

#include <tslintrin.hpp>
#include <iostream>
#include <limits>
#include <cstdint>
#include <algorithm>
#include "test_functions.hpp"

namespace tsl {
    template<VectorProcessingStyle Vec, VectorProcessingStyle ToType>
    bool test_cast_default_int_float_conversion() {
        using namespace tsl;
        using T = typename Vec::base_type; using T_int = typename ToType::base_type;
        if constexpr(std::is_same<typename Vec::target_extension, typename ToType::target_extension>::value){ std::size_t element_count = 1024 * 8 * 10000; testing::test_memory_helper_t<Vec> test_helper{element_count, Vec::vector_element_count(), false}; testing::test_memory_helper_t<ToType> test_helper_float{element_count, Vec::vector_element_count(), false};
        bool allOk = true; auto reference_data_ptr = test_helper.data_ref(); auto reference_result_ptr = test_helper_float.result_ref(); auto test_data_ptr = test_helper.data_target(); auto test_result_ptr = test_helper_float.result_target();
        for(std::size_t i = 0; i < element_count; i += Vec::vector_element_count()){ int idx = 0; for(int j = i; j < i + Vec::vector_element_count(); j++){ reference_result_ptr[idx++] = static_cast<T_int>(reference_data_ptr[j]); } auto vec = loadu<Vec>(&test_data_ptr[i]); storeu<ToType>(test_result_ptr, cast<Vec, ToType>(vec));
        test_helper_float.synchronize(); allOk &= test_helper_float.validate(); } return allOk; } else{ std::cout << "\tPlease implement Testcase for primitive cast with Vec:" << tsl::type_name<Vec>() << " and ToType:"<< tsl::type_name<ToType>() <<"\n"<< std::endl; return true; }
    }
    template<VectorProcessingStyle Vec, VectorProcessingStyle ToType>
    bool test_convert_down_default() {
        using namespace tsl;
        using upper_type = typename Vec::base_type;
        using lower_type = typename ToType::base_type;

        testing::test_memory_helper_t<ToType> test_helper_lower{ToType::vector_element_count(), 1, false, testing::seq_init_start_low<lower_type>};
        auto lower_value_vec = loadu<ToType>(test_helper_lower.data_target());
        auto const lower_inc_vec = set1<ToType>(ToType::vector_element_count());
        uint64_t max = 0;
        if(sizeof(lower_type)>2) {
          max = 1<<16;
        } else {
          max = std::numeric_limits<lower_type>::max();
        }
        for(uint64_t i = 0; i < max; i+= ToType::vector_element_count()) {
          //convert the lower type up to the vec type and convert it back down again -- result should be equal to parameter
          auto result = convert_down<Vec, ToType>(convert_up<ToType, Vec>(lower_value_vec));
          auto mask = to_integral<ToType>(equal<ToType>(result, lower_value_vec));
          for(size_t i = 0; i < ToType::vector_element_count(); ++i) {
            if(((mask>>i)&0b1) != 1) {
              return false;
            }
          }
          lower_value_vec = add<ToType>(lower_value_vec, lower_inc_vec);
        }
        return true;

    }
    template<VectorProcessingStyle Vec, VectorProcessingStyle ToType>
    bool test_convert_up_default() {
        using namespace tsl;
        using lower_type = typename Vec::base_type;
        using upper_type = typename ToType::base_type;
        bool allOk = true;
        upper_type upper_init_start_value;
        lower_type lower_init_start_value;
        if constexpr (std::is_unsigned_v<upper_type>) {
          if constexpr (std::is_unsigned_v<lower_type>) {
            upper_init_start_value = 0;
            lower_init_start_value = 0;
          } else {
            lower_init_start_value = std::numeric_limits<lower_type>::lowest();
            upper_init_start_value = ((upper_type)std::numeric_limits<lower_type>::max())+1;
          }
        } else {
          if constexpr (std::is_unsigned_v<lower_type>) {
            upper_init_start_value = 0;
            lower_init_start_value = 0;
          } else {
            lower_init_start_value = std::numeric_limits<lower_type>::lowest();
            upper_init_start_value = lower_init_start_value;
          }
        }
        uint64_t max = 0;
        if(sizeof(lower_type)>2) {
          max = 1<<16;
        } else {
          max = std::numeric_limits<lower_type>::max();
        }
        auto lower_reg = custom_sequence<Vec>(lower_init_start_value);
        auto const lower_inc = set1<Vec>(Vec::vector_element_count());
        using conversion_type = typename functors::convert_up<Vec, ToType, workaround>::return_type;
        auto upper_regs = conversion_type{};
        auto const upper_inc = set1<ToType>(Vec::vector_element_count());
        for(auto & reg: upper_regs) {
          reg = custom_sequence<ToType>(upper_init_start_value);
          upper_init_start_value += ToType::vector_element_count();
        }
        typename ToType::imask_type const compare_mask = (1<<ToType::vector_element_count())-1;
        for(uint64_t i = 0; i < max; i += Vec::vector_element_count()) {
          auto results = convert_up<Vec, ToType>(lower_reg);
          for(int j = 0; j < results.size(); ++j) {
            auto const mask = to_integral<ToType>(equal<ToType>(results[j], upper_regs[j]));
            if(mask != compare_mask) {
              allOk = false;
            }
          }
          if(!allOk) {
            break;
          }
          for(auto & reg: upper_regs) {
            reg = add<ToType>(reg, upper_inc);
          }
          lower_reg = add<Vec>(lower_reg, lower_inc);
        }
        return allOk;

    }
}

TEST_CASE("Testing primitive 'cast' for avx2", "[cast],[avx2]") {
    using namespace tsl;
    SECTION("default_int_float_conversion") {
        CHECK(test_cast_default_int_float_conversion<simd<double, avx2>, simd<int64_t, avx2>>());
        CHECK(test_cast_default_int_float_conversion<simd<double, avx2>, simd<uint64_t, avx2>>());

        CHECK(test_cast_default_int_float_conversion<simd<float, avx2>, simd<double, avx512>>());
        CHECK(test_cast_default_int_float_conversion<simd<float, avx2>, simd<int32_t, avx2>>());
        CHECK(test_cast_default_int_float_conversion<simd<float, avx2>, simd<uint32_t, avx2>>());

        CHECK(test_cast_default_int_float_conversion<simd<int16_t, avx2>, simd<int32_t, avx512>>());

        CHECK(test_cast_default_int_float_conversion<simd<int32_t, avx2>, simd<int64_t, avx512>>());
        CHECK(test_cast_default_int_float_conversion<simd<int32_t, avx2>, simd<float, avx2>>());

        CHECK(test_cast_default_int_float_conversion<simd<int64_t, avx2>, simd<double, avx2>>());

        CHECK(test_cast_default_int_float_conversion<simd<int8_t, avx2>, simd<int16_t, avx512>>());

        CHECK(test_cast_default_int_float_conversion<simd<uint16_t, avx2>, simd<int32_t, avx512>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint16_t, avx2>, simd<uint32_t, avx512>>());

        CHECK(test_cast_default_int_float_conversion<simd<uint32_t, avx2>, simd<int64_t, avx512>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint32_t, avx2>, simd<uint64_t, avx512>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint32_t, avx2>, simd<float, avx2>>());

        CHECK(test_cast_default_int_float_conversion<simd<uint64_t, avx2>, simd<double, avx2>>());

        CHECK(test_cast_default_int_float_conversion<simd<uint8_t, avx2>, simd<int16_t, avx512>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint8_t, avx2>, simd<uint16_t, avx512>>());

    }
}
TEST_CASE("Testing primitive 'cast' for avx512", "[cast],[avx512]") {
    using namespace tsl;
    SECTION("default_int_float_conversion") {
        CHECK(test_cast_default_int_float_conversion<simd<double, avx512>, simd<float, avx2>>());
        CHECK(test_cast_default_int_float_conversion<simd<double, avx512>, simd<int64_t, avx512>>());
        CHECK(test_cast_default_int_float_conversion<simd<double, avx512>, simd<uint64_t, avx512>>());

        CHECK(test_cast_default_int_float_conversion<simd<float, avx512>, simd<int32_t, avx512>>());
        CHECK(test_cast_default_int_float_conversion<simd<float, avx512>, simd<uint32_t, avx512>>());

        CHECK(test_cast_default_int_float_conversion<simd<int16_t, avx512>, simd<int8_t, avx2>>());

        CHECK(test_cast_default_int_float_conversion<simd<int32_t, avx512>, simd<int16_t, avx2>>());
        CHECK(test_cast_default_int_float_conversion<simd<int32_t, avx512>, simd<int8_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<int32_t, avx512>, simd<float, avx512>>());

        CHECK(test_cast_default_int_float_conversion<simd<int64_t, avx512>, simd<int32_t, avx2>>());
        CHECK(test_cast_default_int_float_conversion<simd<int64_t, avx512>, simd<int16_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<int64_t, avx512>, simd<int8_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<int64_t, avx512>, simd<double, avx512>>());

        WARN("Primitive cast<simd<int8_t, avx512>> not implemented.");
        CHECK(test_cast_default_int_float_conversion<simd<uint16_t, avx512>, simd<uint8_t, avx2>>());

        CHECK(test_cast_default_int_float_conversion<simd<uint32_t, avx512>, simd<uint16_t, avx2>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint32_t, avx512>, simd<uint8_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint32_t, avx512>, simd<float, avx512>>());

        CHECK(test_cast_default_int_float_conversion<simd<uint64_t, avx512>, simd<uint32_t, avx2>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint64_t, avx512>, simd<uint16_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint64_t, avx512>, simd<uint8_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint64_t, avx512>, simd<double, avx512>>());

        WARN("Primitive cast<simd<uint8_t, avx512>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'cast' for scalar", "[cast],[scalar]") {
    using namespace tsl;
    SECTION("default_int_float_conversion") {
        CHECK(test_cast_default_int_float_conversion<simd<double, scalar>, simd<int64_t, scalar>>());

        CHECK(test_cast_default_int_float_conversion<simd<float, scalar>, simd<int32_t, scalar>>());

        WARN("Primitive cast<simd<int16_t, scalar>> not implemented.");
        CHECK(test_cast_default_int_float_conversion<simd<int32_t, scalar>, simd<int32_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<int32_t, scalar>, simd<float, scalar>>());

        CHECK(test_cast_default_int_float_conversion<simd<int64_t, scalar>, simd<int64_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<int64_t, scalar>, simd<double, scalar>>());

        WARN("Primitive cast<simd<int8_t, scalar>> not implemented.");
        WARN("Primitive cast<simd<uint16_t, scalar>> not implemented.");
        CHECK(test_cast_default_int_float_conversion<simd<uint32_t, scalar>, simd<uint32_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint32_t, scalar>, simd<float, scalar>>());

        CHECK(test_cast_default_int_float_conversion<simd<uint64_t, scalar>, simd<uint64_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint64_t, scalar>, simd<double, scalar>>());

        WARN("Primitive cast<simd<uint8_t, scalar>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'cast' for sse", "[cast],[sse]") {
    using namespace tsl;
    SECTION("default_int_float_conversion") {
        CHECK(test_cast_default_int_float_conversion<simd<double, sse>, simd<int64_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<double, sse>, simd<uint64_t, sse>>());

        CHECK(test_cast_default_int_float_conversion<simd<float, sse>, simd<int32_t, sse>>());
        CHECK(test_cast_default_int_float_conversion<simd<float, sse>, simd<uint32_t, sse>>());

        CHECK(test_cast_default_int_float_conversion<simd<int16_t, sse>, simd<int16_t, avx2>>());

        CHECK(test_cast_default_int_float_conversion<simd<int32_t, sse>, simd<int32_t, avx2>>());
        CHECK(test_cast_default_int_float_conversion<simd<int32_t, sse>, simd<float, sse>>());

        CHECK(test_cast_default_int_float_conversion<simd<int64_t, sse>, simd<int64_t, avx2>>());
        CHECK(test_cast_default_int_float_conversion<simd<int64_t, sse>, simd<double, sse>>());

        CHECK(test_cast_default_int_float_conversion<simd<int8_t, sse>, simd<int8_t, avx2>>());

        CHECK(test_cast_default_int_float_conversion<simd<uint16_t, sse>, simd<uint16_t, avx2>>());

        CHECK(test_cast_default_int_float_conversion<simd<uint32_t, sse>, simd<uint32_t, avx2>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint32_t, sse>, simd<float, sse>>());

        CHECK(test_cast_default_int_float_conversion<simd<uint64_t, sse>, simd<uint64_t, avx2>>());
        CHECK(test_cast_default_int_float_conversion<simd<uint64_t, sse>, simd<double, sse>>());

        CHECK(test_cast_default_int_float_conversion<simd<uint8_t, sse>, simd<uint8_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'convert_down' for avx2", "[convert_down],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive convert_down<simd<double, avx2>> not implemented.");
        WARN("Primitive convert_down<simd<float, avx2>> not implemented.");
        WARN("Primitive convert_down<simd<int16_t, avx2>> not implemented.");
        CHECK(test_convert_down_default<simd<int32_t, avx2>, simd<int8_t, avx2>>());
        CHECK(test_convert_down_default<simd<int32_t, avx2>, simd<int16_t, avx2>>());

        CHECK(test_convert_down_default<simd<int64_t, avx2>, simd<int8_t, avx2>>());
        CHECK(test_convert_down_default<simd<int64_t, avx2>, simd<int16_t, avx2>>());
        CHECK(test_convert_down_default<simd<int64_t, avx2>, simd<int32_t, avx2>>());

        WARN("Primitive convert_down<simd<int8_t, avx2>> not implemented.");
        WARN("Primitive convert_down<simd<uint16_t, avx2>> not implemented.");
        CHECK(test_convert_down_default<simd<uint32_t, avx2>, simd<uint8_t, avx2>>());
        CHECK(test_convert_down_default<simd<uint32_t, avx2>, simd<uint16_t, avx2>>());

        CHECK(test_convert_down_default<simd<uint64_t, avx2>, simd<uint8_t, avx2>>());
        CHECK(test_convert_down_default<simd<uint64_t, avx2>, simd<uint16_t, avx2>>());
        CHECK(test_convert_down_default<simd<uint64_t, avx2>, simd<uint32_t, avx2>>());

        WARN("Primitive convert_down<simd<uint8_t, avx2>> not implemented.");
    }
}
TEST_CASE("Testing primitive 'convert_down' for avx512", "[convert_down],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive convert_down not implemented for avx512");
    }
}
TEST_CASE("Testing primitive 'convert_down' for scalar", "[convert_down],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive convert_down not implemented for scalar");
    }
}
TEST_CASE("Testing primitive 'convert_down' for sse", "[convert_down],[sse]") {
    using namespace tsl;
    SECTION("default") {
    }
}
TEST_CASE("Testing primitive 'convert_up' for avx2", "[convert_up],[avx2]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive convert_up<simd<double, avx2>> not implemented.");
        WARN("Primitive convert_up<simd<float, avx2>> not implemented.");
        CHECK(test_convert_up_default<simd<int16_t, avx2>, simd<int32_t, avx2>>());
        CHECK(test_convert_up_default<simd<int16_t, avx2>, simd<uint32_t, avx2>>());
        CHECK(test_convert_up_default<simd<int16_t, avx2>, simd<int64_t, avx2>>());
        CHECK(test_convert_up_default<simd<int16_t, avx2>, simd<uint64_t, avx2>>());

        CHECK(test_convert_up_default<simd<int32_t, avx2>, simd<int64_t, avx2>>());
        CHECK(test_convert_up_default<simd<int32_t, avx2>, simd<uint64_t, avx2>>());

        CHECK(test_convert_up_default<simd<int64_t, avx2>, simd<int64_t, avx2>>());
        CHECK(test_convert_up_default<simd<int64_t, avx2>, simd<uint64_t, avx2>>());

        CHECK(test_convert_up_default<simd<int8_t, avx2>, simd<int32_t, avx2>>());
        CHECK(test_convert_up_default<simd<int8_t, avx2>, simd<uint32_t, avx2>>());
        CHECK(test_convert_up_default<simd<int8_t, avx2>, simd<int64_t, avx2>>());
        CHECK(test_convert_up_default<simd<int8_t, avx2>, simd<uint64_t, avx2>>());

        CHECK(test_convert_up_default<simd<uint16_t, avx2>, simd<uint32_t, avx2>>());
        CHECK(test_convert_up_default<simd<uint16_t, avx2>, simd<int32_t, avx2>>());
        CHECK(test_convert_up_default<simd<uint16_t, avx2>, simd<uint64_t, avx2>>());
        CHECK(test_convert_up_default<simd<uint16_t, avx2>, simd<int64_t, avx2>>());

        CHECK(test_convert_up_default<simd<uint32_t, avx2>, simd<uint64_t, avx2>>());
        CHECK(test_convert_up_default<simd<uint32_t, avx2>, simd<int64_t, avx2>>());

        CHECK(test_convert_up_default<simd<uint64_t, avx2>, simd<int64_t, avx2>>());
        CHECK(test_convert_up_default<simd<uint64_t, avx2>, simd<uint64_t, avx2>>());

        CHECK(test_convert_up_default<simd<uint8_t, avx2>, simd<uint32_t, avx2>>());
        CHECK(test_convert_up_default<simd<uint8_t, avx2>, simd<int32_t, avx2>>());
        CHECK(test_convert_up_default<simd<uint8_t, avx2>, simd<uint64_t, avx2>>());
        CHECK(test_convert_up_default<simd<uint8_t, avx2>, simd<int64_t, avx2>>());

    }
}
TEST_CASE("Testing primitive 'convert_up' for avx512", "[convert_up],[avx512]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive convert_up not implemented for avx512");
    }
}
TEST_CASE("Testing primitive 'convert_up' for scalar", "[convert_up],[scalar]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive convert_up not implemented for scalar");
    }
}
TEST_CASE("Testing primitive 'convert_up' for sse", "[convert_up],[sse]") {
    using namespace tsl;
    SECTION("default") {
        WARN("Primitive convert_up<simd<double, sse>> not implemented.");
        WARN("Primitive convert_up<simd<float, sse>> not implemented.");
        CHECK(test_convert_up_default<simd<int16_t, sse>, simd<int32_t, sse>>());
        CHECK(test_convert_up_default<simd<int16_t, sse>, simd<uint32_t, sse>>());
        CHECK(test_convert_up_default<simd<int16_t, sse>, simd<int64_t, sse>>());
        CHECK(test_convert_up_default<simd<int16_t, sse>, simd<uint64_t, sse>>());

        CHECK(test_convert_up_default<simd<int32_t, sse>, simd<int64_t, sse>>());
        CHECK(test_convert_up_default<simd<int32_t, sse>, simd<uint64_t, sse>>());

        WARN("Primitive convert_up<simd<int64_t, sse>> not implemented.");
        CHECK(test_convert_up_default<simd<int8_t, sse>, simd<int32_t, sse>>());
        CHECK(test_convert_up_default<simd<int8_t, sse>, simd<uint32_t, sse>>());
        CHECK(test_convert_up_default<simd<int8_t, sse>, simd<int64_t, sse>>());
        CHECK(test_convert_up_default<simd<int8_t, sse>, simd<uint64_t, sse>>());

        CHECK(test_convert_up_default<simd<uint16_t, sse>, simd<uint32_t, sse>>());
        CHECK(test_convert_up_default<simd<uint16_t, sse>, simd<int32_t, sse>>());
        CHECK(test_convert_up_default<simd<uint16_t, sse>, simd<uint64_t, sse>>());
        CHECK(test_convert_up_default<simd<uint16_t, sse>, simd<int64_t, sse>>());

        CHECK(test_convert_up_default<simd<uint32_t, sse>, simd<uint64_t, sse>>());
        CHECK(test_convert_up_default<simd<uint32_t, sse>, simd<int64_t, sse>>());

        WARN("Primitive convert_up<simd<uint64_t, sse>> not implemented.");
        CHECK(test_convert_up_default<simd<uint8_t, sse>, simd<uint32_t, sse>>());
        CHECK(test_convert_up_default<simd<uint8_t, sse>, simd<int32_t, sse>>());
        CHECK(test_convert_up_default<simd<uint8_t, sse>, simd<uint64_t, sse>>());
        CHECK(test_convert_up_default<simd<uint8_t, sse>, simd<int64_t, sse>>());

    }
}

