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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/calc/calc_sse.hpp
 * \date 2023-07-22
 * \brief This file contains arithmetic primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CALC_CALC_SSE_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CALC_CALC_SSE_HPP

#include <array>
#include <cstddef>
#include <cmath>
#include "../../declarations/calc.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::106
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct add<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of add for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::106
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct add<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of add for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::106
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct add<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of add for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::106
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct add<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi64(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of add for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::106
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct add<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of add for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::106
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct add<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of add for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::106
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct add<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of add for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::106
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct add<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi64(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of add for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/calc.yaml::111
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct add<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_ps(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of add for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::115
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct add<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_pd(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of add for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::244
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sub<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_sub_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of sub for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::244
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sub<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_sub_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of sub for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::244
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sub<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_sub_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of sub for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::244
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sub<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_sub_epi64(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of sub for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::244
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sub<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_sub_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of sub for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::244
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sub<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_sub_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of sub for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::244
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sub<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_sub_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of sub for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::244
         * @note: Signed addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sub<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_sub_epi64(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of sub for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/calc.yaml::249
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sub<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_sub_ps(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of sub for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::253
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sub<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_sub_pd(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of sub for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::313
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_add<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi8(vec_a, _mm_and_si128(vec_b, mask));
            }
        };
    } // end of namespace functors for template specialization of mask_add for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::313
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_add<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi8(vec_a, _mm_and_si128(vec_b, mask));
            }
        };
    } // end of namespace functors for template specialization of mask_add for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::313
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_add<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi16(vec_a, _mm_and_si128(vec_b, mask));
            }
        };
    } // end of namespace functors for template specialization of mask_add for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::313
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_add<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi16(vec_a, _mm_and_si128(vec_b, mask));
            }
        };
    } // end of namespace functors for template specialization of mask_add for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::313
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_add<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi32(vec_a, _mm_and_si128(vec_b, mask));
            }
        };
    } // end of namespace functors for template specialization of mask_add for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::313
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_add<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi32(vec_a, _mm_and_si128(vec_b, mask));
            }
        };
    } // end of namespace functors for template specialization of mask_add for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::313
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_add<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi64(vec_a, _mm_and_si128(vec_b, mask));
            }
        };
    } // end of namespace functors for template specialization of mask_add for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::313
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_add<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_epi64(vec_a, _mm_and_si128(vec_b, mask));
            }
        };
    } // end of namespace functors for template specialization of mask_add for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/calc.yaml::317
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_add<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_ps(vec_a, _mm_and_ps(vec_b, mask));
            }
        };
    } // end of namespace functors for template specialization of mask_add for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_add" (primitive add).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::321
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_add<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_add_pd(vec_a, _mm_and_pd(vec_b, mask));
            }
        };
    } // end of namespace functors for template specialization of mask_add for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/calc.yaml::440
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mul<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_mul_ps(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of mul for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::444
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mul<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_mul_pd(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of mul for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::448
         * @note: Signed multiplication.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mul<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_mullo_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of mul for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::448
         * @note: Signed multiplication.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mul<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_mullo_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of mul for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/calc.yaml::453
         * @note: Signed multiplication.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mul<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_mullo_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of mul for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/calc.yaml::453
         * @note: Signed multiplication.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mul<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_mullo_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of mul for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512dq', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/calc.yaml::458
         * @note: Signed multiplication.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mul<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_mullo_epi64(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of mul for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512dq', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/calc.yaml::458
         * @note: Signed multiplication.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mul<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_mullo_epi64(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of mul for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::463
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mul<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mul is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_a;
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_b;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_a.data()), vec_a);
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_b.data()), vec_b);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    buffer_a[i] *= buffer_b[i];
                }
                return _mm_load_si128(reinterpret_cast<__m128i const *>(buffer_a.data()));
            }
        };
    } // end of namespace functors for template specialization of mul for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::463
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mul<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mul is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_a;
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_b;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_a.data()), vec_a);
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_b.data()), vec_b);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    buffer_a[i] *= buffer_b[i];
                }
                return _mm_load_si128(reinterpret_cast<__m128i const *>(buffer_a.data()));
            }
        };
    } // end of namespace functors for template specialization of mul for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::661
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::base_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type value
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive hadd is not supported by your hardware natively while it is forced by using native" );

                return _mm_cvtsd_f64(value) + _mm_cvtsd_f64(_mm_castsi128_pd(_mm_bsrli_si128(_mm_castpd_si128(value),sizeof(double))));
            }
        };
    } // end of namespace functors for template specialization of hadd for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2', 'avx']
         *      Yaml Source: primitive_data/primitives/calc.yaml::675
         * @note: Signed Addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::base_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type value
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive hadd is not supported by your hardware natively while it is forced by using native" );

                return _mm_cvtsi128_si64(value) + _mm_cvtsi128_si64(_mm_bsrli_si128(value,sizeof(uint64_t)));
            }
        };
    } // end of namespace functors for template specialization of hadd for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2', 'avx']
         *      Yaml Source: primitive_data/primitives/calc.yaml::675
         * @note: Signed Addition.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::base_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type value
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive hadd is not supported by your hardware natively while it is forced by using native" );

                return _mm_cvtsi128_si64(value) + _mm_cvtsi128_si64(_mm_bsrli_si128(value,sizeof(uint64_t)));
            }
        };
    } // end of namespace functors for template specialization of hadd for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::690
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::base_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type value
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive hadd is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer;
                typename Vec::base_type result = 0;
                _mm_store_si128(reinterpret_cast<__m128i *>(buffer.data()), value);
                for  (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result += buffer[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of hadd for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::690
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::base_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type value
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive hadd is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer;
                typename Vec::base_type result = 0;
                _mm_store_si128(reinterpret_cast<__m128i *>(buffer.data()), value);
                for  (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result += buffer[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of hadd for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::690
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::base_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type value
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive hadd is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer;
                typename Vec::base_type result = 0;
                _mm_store_si128(reinterpret_cast<__m128i *>(buffer.data()), value);
                for  (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result += buffer[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of hadd for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::690
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::base_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type value
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive hadd is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer;
                typename Vec::base_type result = 0;
                _mm_store_si128(reinterpret_cast<__m128i *>(buffer.data()), value);
                for  (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result += buffer[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of hadd for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/calc.yaml::811
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct min<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_min_ps(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of min for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::815
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct min<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_min_epu8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of min for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::815
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct min<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_min_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of min for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::815
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct min<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_min_pd(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of min for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/calc.yaml::819
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct min<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_min_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of min for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/calc.yaml::819
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct min<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_min_epu16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of min for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/calc.yaml::819
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct min<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_min_epu32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of min for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/calc.yaml::819
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct min<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_min_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of min for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/calc.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct div<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_div_ps(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of div for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/calc.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct div<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_div_pd(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of div for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::953
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct div<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive div is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_a;
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_b;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_a.data()), vec_a);
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_b.data()), vec_b);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer_a[i] /= buffer_b[i];
                }
                return _mm_load_si128(reinterpret_cast<__m128i const *>(buffer_a.data()));
            }
        };
    } // end of namespace functors for template specialization of div for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::953
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct div<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive div is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_a;
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_b;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_a.data()), vec_a);
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_b.data()), vec_b);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer_a[i] /= buffer_b[i];
                }
                return _mm_load_si128(reinterpret_cast<__m128i const *>(buffer_a.data()));
            }
        };
    } // end of namespace functors for template specialization of div for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::953
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct div<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive div is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_a;
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_b;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_a.data()), vec_a);
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_b.data()), vec_b);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer_a[i] /= buffer_b[i];
                }
                return _mm_load_si128(reinterpret_cast<__m128i const *>(buffer_a.data()));
            }
        };
    } // end of namespace functors for template specialization of div for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::953
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct div<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive div is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_a;
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_b;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_a.data()), vec_a);
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_b.data()), vec_b);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer_a[i] /= buffer_b[i];
                }
                return _mm_load_si128(reinterpret_cast<__m128i const *>(buffer_a.data()));
            }
        };
    } // end of namespace functors for template specialization of div for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::953
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct div<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive div is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_a;
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_b;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_a.data()), vec_a);
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_b.data()), vec_b);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer_a[i] /= buffer_b[i];
                }
                return _mm_load_si128(reinterpret_cast<__m128i const *>(buffer_a.data()));
            }
        };
    } // end of namespace functors for template specialization of div for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::953
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct div<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive div is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_a;
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_b;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_a.data()), vec_a);
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_b.data()), vec_b);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer_a[i] /= buffer_b[i];
                }
                return _mm_load_si128(reinterpret_cast<__m128i const *>(buffer_a.data()));
            }
        };
    } // end of namespace functors for template specialization of div for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::953
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct div<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive div is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_a;
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_b;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_a.data()), vec_a);
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_b.data()), vec_b);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer_a[i] /= buffer_b[i];
                }
                return _mm_load_si128(reinterpret_cast<__m128i const *>(buffer_a.data()));
            }
        };
    } // end of namespace functors for template specialization of div for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::953
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct div<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive div is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_a;
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer_b;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_a.data()), vec_a);
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer_b.data()), vec_b);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer_a[i] /= buffer_b[i];
                }
                return _mm_load_si128(reinterpret_cast<__m128i const *>(buffer_a.data()));
            }
        };
    } // end of namespace functors for template specialization of div for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1179
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mod<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mod is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer.data()), vec);
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer[i] = buffer[i] % val;
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(buffer.data()));
            }
        };
    } // end of namespace functors for template specialization of mod for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1179
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mod<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mod is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer.data()), vec);
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer[i] = buffer[i] % val;
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(buffer.data()));
            }
        };
    } // end of namespace functors for template specialization of mod for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1179
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mod<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mod is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer.data()), vec);
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer[i] = buffer[i] % val;
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(buffer.data()));
            }
        };
    } // end of namespace functors for template specialization of mod for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1179
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mod<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return false;
            }
            [[nodiscard]] TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mod is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> buffer;
                _mm_store_si128(reinterpret_cast<__m128i*>(buffer.data()), vec);
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  buffer[i] = buffer[i] % val;
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(buffer.data()));
            }
        };
    } // end of namespace functors for template specialization of mod for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1191
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mod<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = float;
                __m128 vec_d = tsl::cast<Vec, typename Vec::template transform_extension<T>>(vec);
                __m128 val_d = _mm_set1_ps(static_cast<T>(val));

                __m128 temp = tsl::div<typename Vec::template transform_extension<T>>(vec_d, val_d);
                temp = _mm_round_ps(temp, _MM_FROUND_TO_ZERO);
                temp = _mm_mul_ps(temp, val_d);
                temp = _mm_sub_ps(vec_d, temp);

                return tsl::cast<typename Vec::template transform_extension<T>,Vec>(temp);
            }
        };
    } // end of namespace functors for template specialization of mod for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1191
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mod<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = float;
                __m128 vec_d = tsl::cast<Vec, typename Vec::template transform_extension<T>>(vec);
                __m128 val_d = _mm_set1_ps(static_cast<T>(val));

                __m128 temp = tsl::div<typename Vec::template transform_extension<T>>(vec_d, val_d);
                temp = _mm_round_ps(temp, _MM_FROUND_TO_ZERO);
                temp = _mm_mul_ps(temp, val_d);
                temp = _mm_sub_ps(vec_d, temp);

                return tsl::cast<typename Vec::template transform_extension<T>,Vec>(temp);
            }
        };
    } // end of namespace functors for template specialization of mod for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1206
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mod<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = double;

                __m128d vec_d = tsl::cast<Vec, typename Vec::template transform_extension<T>>(vec);
                __m128d val_d = _mm_set1_pd(static_cast<T>(val));

                __m128d temp = tsl::div<typename Vec::template transform_extension<T>>(vec_d, val_d);
                temp = _mm_round_pd(temp, _MM_FROUND_TO_ZERO);
                temp = _mm_mul_pd(temp, val_d);
                temp = _mm_sub_pd(vec_d, temp);

                return tsl::cast<typename Vec::template transform_extension<T>,Vec>(temp);
            }
        };
    } // end of namespace functors for template specialization of mod for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1206
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mod<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = double;

                __m128d vec_d = tsl::cast<Vec, typename Vec::template transform_extension<T>>(vec);
                __m128d val_d = _mm_set1_pd(static_cast<T>(val));

                __m128d temp = tsl::div<typename Vec::template transform_extension<T>>(vec_d, val_d);
                temp = _mm_round_pd(temp, _MM_FROUND_TO_ZERO);
                temp = _mm_mul_pd(temp, val_d);
                temp = _mm_sub_pd(vec_d, temp);

                return tsl::cast<typename Vec::template transform_extension<T>,Vec>(temp);
            }
        };
    } // end of namespace functors for template specialization of mod for sse using uint64_t.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CALC_CALC_SSE_HPP