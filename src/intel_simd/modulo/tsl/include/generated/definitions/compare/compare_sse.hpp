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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/compare/compare_sse.hpp
 * \date 2023-07-22
 * \brief Compare primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_SSE_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_SSE_HPP

#include "../../declarations/compare.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpeq_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpeq_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpeq_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpeq_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpeq_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpeq_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::118
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpeq_epi64(vec_a,vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::118
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpeq_epi64(vec_a,vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::275
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                auto const all_set = _mm_cmpeq_epi8(vec_a,vec_a);
                return _mm_andnot_si128(_mm_cmpeq_epi8(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::275
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                auto const all_set = _mm_cmpeq_epi8(vec_a,vec_a);
                return _mm_andnot_si128(_mm_cmpeq_epi8(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::275
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                auto const all_set = _mm_cmpeq_epi16(vec_a,vec_a);
                return _mm_andnot_si128(_mm_cmpeq_epi16(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::275
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                auto const all_set = _mm_cmpeq_epi16(vec_a,vec_a);
                return _mm_andnot_si128(_mm_cmpeq_epi16(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::275
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                auto const all_set = _mm_cmpeq_epi32(vec_a,vec_a);
                return _mm_andnot_si128(_mm_cmpeq_epi32(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::275
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                auto const all_set = _mm_cmpeq_epi32(vec_a,vec_a);
                return _mm_andnot_si128(_mm_cmpeq_epi32(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::281
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                auto const all_set = _mm_cmpeq_epi64(vec_a,vec_a);
                return _mm_andnot_si128(_mm_cmpeq_epi64(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::281
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                auto const all_set = _mm_cmpeq_epi64(vec_a,vec_a);
                return _mm_andnot_si128(_mm_cmpeq_epi64(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2', 'sse4_2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::352
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                return _mm_andnot_si128( _mm_cmpgt_epi64( vec_min, vec_data ), _mm_andnot_si128( _mm_cmpgt_epi64( vec_data, vec_max ), _mm_set1_epi64x(-1)));
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/compare.yaml::357
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                return _mm_and_ps(_mm_cmpge_ps(vec_data, vec_min), _mm_cmpge_ps(vec_max, vec_data));
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::361
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                return _mm_and_pd(_mm_cmpge_pd(vec_data, vec_min), _mm_cmpge_pd(vec_max, vec_data));
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::477
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmplt_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::477
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmplt_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::477
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmplt_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::477
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmplt_ps(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::477
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmplt_pd(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::482
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpgt_epi64(vec_b, vec_a);
            }
        };
    } // end of namespace functors for template specialization of less_than for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::493
         * @note: Unsigned comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive less_than is not supported by your hardware natively while it is forced by using native" );

                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpeq_epi8(vec_a, _mm_max_epu8(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of less_than for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::493
         * @note: Unsigned comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive less_than is not supported by your hardware natively while it is forced by using native" );

                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpeq_epi16(vec_a, _mm_max_epu16(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of less_than for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::493
         * @note: Unsigned comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive less_than is not supported by your hardware natively while it is forced by using native" );

                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpeq_epi32(vec_a, _mm_max_epu32(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of less_than for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::499
         * @note: Unsigned comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive less_than is not supported by your hardware natively while it is forced by using native" );

                __m128i sign_bits = _mm_set1_epi64x((int64_t)1 << 63); return _mm_cmpgt_epi64(_mm_xor_si128(vec_b, sign_bits), _mm_xor_si128(vec_a, sign_bits));
            }
        };
    } // end of namespace functors for template specialization of less_than for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::621
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpgt_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::621
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpgt_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::621
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpgt_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::621
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpgt_ps(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::621
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpgt_pd(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::626
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpgt_epi64(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::631
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive greater_than is not supported by your hardware natively while it is forced by using native" );

                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpeq_epi8(vec_b, _mm_max_epu8(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of greater_than for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::636
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive greater_than is not supported by your hardware natively while it is forced by using native" );

                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpeq_epi16(vec_b, _mm_max_epu16(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of greater_than for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::636
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive greater_than is not supported by your hardware natively while it is forced by using native" );

                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpeq_epi32(vec_b, _mm_max_epu32(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of greater_than for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::641
         * @note: Using signed comparison as unsigned by flipping the sign bit.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive greater_than is not supported by your hardware natively while it is forced by using native" );

                __m128i sign_bits = _mm_set1_epi64x((int64_t)1 << 63); return _mm_cmpgt_epi64(_mm_xor_si128(vec_a, sign_bits), _mm_xor_si128(vec_b, sign_bits));
            }
        };
    } // end of namespace functors for template specialization of greater_than for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::766
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive less_than_or_equal is not supported by your hardware natively while it is forced by using native" );

                return  _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpgt_epi8(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::766
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive less_than_or_equal is not supported by your hardware natively while it is forced by using native" );

                return  _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpgt_epi16(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::766
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive less_than_or_equal is not supported by your hardware natively while it is forced by using native" );

                return  _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpgt_epi32(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::771
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmple_ps(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::771
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmple_pd(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::775
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpgt_epi64(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::779
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive less_than_or_equal is not supported by your hardware natively while it is forced by using native" );

                return _mm_cmpeq_epi8(vec_b, _mm_max_epu8(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::784
         * @note: Using signed comparison as unsigned by flipping the sign bit.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive less_than_or_equal is not supported by your hardware natively while it is forced by using native" );

                __m128i sign_bits = _mm_set1_epi16(0x8000);
                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpgt_epi16(_mm_xor_si128(vec_a, sign_bits), _mm_xor_si128(vec_b, sign_bits)));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::784
         * @note: Using signed comparison as unsigned by flipping the sign bit.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive less_than_or_equal is not supported by your hardware natively while it is forced by using native" );

                __m128i sign_bits = _mm_set1_epi32(0x80000000);
                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpgt_epi32(_mm_xor_si128(vec_a, sign_bits), _mm_xor_si128(vec_b, sign_bits)));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::784
         * @note: Using signed comparison as unsigned by flipping the sign bit.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive less_than_or_equal is not supported by your hardware natively while it is forced by using native" );

                __m128i sign_bits = _mm_set1_epi64x((int64_t)0x8000000000000000);
                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpgt_epi64(_mm_xor_si128(vec_a, sign_bits), _mm_xor_si128(vec_b, sign_bits)));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::920
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpgt_epi8(vec_b, vec_a));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::920
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpgt_epi16(vec_b, vec_a));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::920
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpgt_epi32(vec_b, vec_a));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::925
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_xor_si128(_mm_set1_epi8(-1), _mm_cmpgt_epi64(vec_b, vec_a));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::930
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpge_ps(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::930
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm_cmpge_pd(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::935
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive greater_than_or_equal is not supported by your hardware natively while it is forced by using native" );

                return _mm_cmpeq_epi8(vec_a, _mm_max_epu8(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::940
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive greater_than_or_equal is not supported by your hardware natively while it is forced by using native" );

                return _mm_cmpeq_epi16(vec_a, _mm_max_epu16(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::940
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive greater_than_or_equal is not supported by your hardware natively while it is forced by using native" );

                return _mm_cmpeq_epi32(vec_a, _mm_max_epu32(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::945
         * @note: Using signed comparison as unsigned by flipping the sign bit.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive greater_than_or_equal is not supported by your hardware natively while it is forced by using native" );

                __m128i sign_bits = _mm_set1_epi64x((int64_t)1 << 63);
                __m128i less_than = _mm_cmpgt_epi64(_mm_xor_si128(vec_b, sign_bits), _mm_xor_si128(vec_a, sign_bits));
                return _mm_xor_si128(_mm_set1_epi8(-1), less_than);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1060
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = bool;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
            static bool apply(
                const typename Vec::register_type vec
            ) {
                return (_mm_movemask_ps(_mm_cmpneq_ps(vec, _mm_setzero_ps())) != 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1060
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = bool;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
            static bool apply(
                const typename Vec::register_type vec
            ) {
                return (_mm_movemask_pd(_mm_cmpneq_pd(vec, _mm_setzero_pd())) != 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1064
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = bool;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
            static bool apply(
                const typename Vec::register_type vec
            ) {
                return (_mm_testz_si128(vec, vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1064
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = bool;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
            static bool apply(
                const typename Vec::register_type vec
            ) {
                return (_mm_testz_si128(vec, vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1064
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = bool;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
            static bool apply(
                const typename Vec::register_type vec
            ) {
                return (_mm_testz_si128(vec, vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1064
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = bool;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
            static bool apply(
                const typename Vec::register_type vec
            ) {
                return (_mm_testz_si128(vec, vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1064
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = bool;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
            static bool apply(
                const typename Vec::register_type vec
            ) {
                return (_mm_testz_si128(vec, vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1064
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = bool;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
            static bool apply(
                const typename Vec::register_type vec
            ) {
                return (_mm_testz_si128(vec, vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1064
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = bool;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
            static bool apply(
                const typename Vec::register_type vec
            ) {
                return (_mm_testz_si128(vec, vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1064
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = bool;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
            static bool apply(
                const typename Vec::register_type vec
            ) {
                return (_mm_testz_si128(vec, vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1243
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T =  Vec::base_type;
                T result = 0;
                __m128i value = _mm_set1_epi16(val);
                __m128i is_equal = _mm_cmpeq_epi16(vec, value);
                T mask[Vec::vector_element_count()];
                _mm_storeu_si128(reinterpret_cast<__m128i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1243
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T =  Vec::base_type;
                T result = 0;
                __m128i value = _mm_set1_epi16(val);
                __m128i is_equal = _mm_cmpeq_epi16(vec, value);
                T mask[Vec::vector_element_count()];
                _mm_storeu_si128(reinterpret_cast<__m128i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1243
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T =  Vec::base_type;
                T result = 0;
                __m128i value = _mm_set1_epi32(val);
                __m128i is_equal = _mm_cmpeq_epi32(vec, value);
                T mask[Vec::vector_element_count()];
                _mm_storeu_si128(reinterpret_cast<__m128i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1243
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T =  Vec::base_type;
                T result = 0;
                __m128i value = _mm_set1_epi32(val);
                __m128i is_equal = _mm_cmpeq_epi32(vec, value);
                T mask[Vec::vector_element_count()];
                _mm_storeu_si128(reinterpret_cast<__m128i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1243
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T =  Vec::base_type;
                T result = 0;
                __m128i value = _mm_set1_epi64x(val);
                __m128i is_equal = _mm_cmpeq_epi64(vec, value);
                T mask[Vec::vector_element_count()];
                _mm_storeu_si128(reinterpret_cast<__m128i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1243
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T =  Vec::base_type;
                T result = 0;
                __m128i value = _mm_set1_epi64x(val);
                __m128i is_equal = _mm_cmpeq_epi64(vec, value);
                T mask[Vec::vector_element_count()];
                _mm_storeu_si128(reinterpret_cast<__m128i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1264
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                Vec::base_type result = 0;

                __m128 value, is_equal;

                value = _mm_set1_ps(val);
                is_equal = _mm_cmpeq_ps(vec, value);
                int mask = _mm_movemask_ps(is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask & (1 << i)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1264
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                Vec::base_type result = 0;

                __m128d value, is_equal;

                value = _mm_set1_pd(val);
                is_equal = _mm_cmpeq_pd(vec, value);
                int mask = _mm_movemask_pd(is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask & (1 << i)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1286
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                Vec::base_type result = 0;
                __m128i value = _mm_set1_epi8(val);
                __m128i is_equal = _mm_cmpeq_epi8(vec, value);
                int mask = _mm_movemask_epi8(is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask & (1 << i)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1286
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                Vec::base_type result = 0;
                __m128i value = _mm_set1_epi8(val);
                __m128i is_equal = _mm_cmpeq_epi8(vec, value);
                int mask = _mm_movemask_epi8(is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask & (1 << i)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for sse using int8_t.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_SSE_HPP