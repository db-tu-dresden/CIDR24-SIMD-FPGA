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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/compare/compare_avx512.hpp
 * \date 2023-07-22
 * \brief Compare primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_AVX512_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_AVX512_HPP

#include "../../declarations/compare.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::79
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_cmpeq_epi8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::79
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_cmpeq_epi8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::79
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_cmpeq_epi16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::79
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_cmpeq_epi16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::84
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_cmpeq_epi32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::84
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_cmpeq_epi32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::84
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_cmpeq_epi64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::84
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_cmpeq_epi64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::89
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_cmpeq_ps_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::89
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_cmpeq_pd_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::225
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_cmpneq_epi8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::225
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_cmpneq_epi8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::225
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_cmpneq_epi16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::225
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_cmpneq_epi16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::230
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_cmpneq_epi32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::230
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_cmpneq_epi32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::230
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_cmpneq_epi64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::230
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_cmpneq_epi64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::235
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_cmpneq_ps_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::235
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_cmpneq_pd_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::333
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_cmple_epu64_mask( vec_min, vec_data ) & _mm512_cmpge_epu64_mask( vec_max, vec_data );
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::337
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_cmple_ps_mask(vec_min, vec_data) & _mm512_cmple_ps_mask(vec_data, vec_max);
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::337
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_cmple_pd_mask(vec_min, vec_data) & _mm512_cmple_pd_mask(vec_data, vec_max);
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::442
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_cmplt_epi8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::442
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_cmplt_epu8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::442
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_cmplt_epi16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::442
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_cmplt_epu16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::446
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_cmplt_epi32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::446
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_cmplt_epu32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::446
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_cmplt_epi64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::446
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_cmplt_epu64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_cmplt_ps_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_cmplt_pd_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::587
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_cmpgt_epi8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::587
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_cmpgt_epu8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::587
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_cmpgt_epi16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::587
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_cmpgt_epu16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::591
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_cmpgt_epi32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::591
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_cmpgt_epu32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::591
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_cmpgt_epi64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::591
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_cmpgt_epu64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::595
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_cmp_ps_mask(vec_a, vec_b, _CMP_GT_OQ);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::595
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_cmp_pd_mask(vec_a, vec_b, _CMP_GT_OQ);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::729
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_cmple_epi8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::729
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_cmple_epu8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::729
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_cmple_epi16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::729
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_cmple_epu16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::733
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_cmple_epi32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::733
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_cmple_epu32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::733
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_cmple_epi64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::733
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_cmple_epu64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::737
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_cmple_ps_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::737
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_cmple_pd_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::882
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_cmpge_epi8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::882
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_cmpge_epu8_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::882
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_cmpge_epi16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::882
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_cmpge_epu16_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::886
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_cmpge_epi32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::886
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_cmpge_epu32_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::886
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_cmpge_epi64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::886
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_cmpge_epu64_mask(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::890
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_cmp_ps_mask(vec_a, vec_b, _CMP_GE_OQ);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::890
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_cmp_pd_mask(vec_a, vec_b, _CMP_GE_OQ);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1038
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return ~(_mm512_cmpeq_epi8_mask(vec, _mm512_setzero_si512()));
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1038
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return ~(_mm512_cmpeq_epi8_mask(vec, _mm512_setzero_si512()));
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1038
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return ~(_mm512_cmpeq_epi16_mask(vec, _mm512_setzero_si512()));
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1038
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return ~(_mm512_cmpeq_epi16_mask(vec, _mm512_setzero_si512()));
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1042
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return ~(_mm512_cmpeq_epi32_mask(vec, _mm512_setzero_si512())) & 0x1;
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1042
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return ~(_mm512_cmpeq_epi32_mask(vec, _mm512_setzero_si512())) & 0x1;
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1042
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return ~(_mm512_cmpeq_epi64_mask(vec, _mm512_setzero_si512())) & 0x1;
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1042
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return ~(_mm512_cmpeq_epi64_mask(vec, _mm512_setzero_si512())) & 0x1;
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1046
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return (_mm512_cmp_ps_mask(vec, _mm512_setzero_ps(), _CMP_NEQ_OQ) != 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1046
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return (_mm512_cmp_pd_mask(vec, _mm512_setzero_pd(), _CMP_NEQ_OQ) != 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                __m512i target_value = _mm512_set1_epi8(val);
                __mmask64 cmp_result = _mm512_cmpeq_epi8_mask(vec, target_value);
                uint64_t mask_bits = static_cast<uint64_t>(cmp_result);
                while (mask_bits != 0) {
                  result += mask_bits & 1;
                  mask_bits >>= 1;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                __m512i target_value = _mm512_set1_epi8(val);
                __mmask64 cmp_result = _mm512_cmpeq_epi8_mask(vec, target_value);
                uint64_t mask_bits = static_cast<uint64_t>(cmp_result);
                while (mask_bits != 0) {
                  result += mask_bits & 1;
                  mask_bits >>= 1;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1148
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                __m512i target_value = _mm512_set1_epi16(val);
                __mmask32 cmp_result = _mm512_cmpeq_epi16_mask(vec, target_value);
                uint32_t mask_bits = static_cast<uint32_t>(cmp_result);
                while (mask_bits != 0) {
                  result += mask_bits & 1;
                  mask_bits >>= 1;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1148
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                __m512i target_value = _mm512_set1_epi16(val);
                __mmask32 cmp_result = _mm512_cmpeq_epi16_mask(vec, target_value);
                uint32_t mask_bits = static_cast<uint32_t>(cmp_result);
                while (mask_bits != 0) {
                  result += mask_bits & 1;
                  mask_bits >>= 1;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1161
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                __m512i value = _mm512_set1_epi32(val);
                __mmask32 cmp_result = _mm512_cmpeq_epi32_mask(vec, value);
                return _mm_popcnt_u32(cmp_result);
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1161
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                __m512i value = _mm512_set1_epi32(val);
                __mmask32 cmp_result = _mm512_cmpeq_epi32_mask(vec, value);
                return _mm_popcnt_u32(cmp_result);
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1161
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                __m512i value = _mm512_set1_epi64(val);
                __mmask64 cmp_result = _mm512_cmpeq_epi64_mask(vec, value);
                return _mm_popcnt_u64(cmp_result);
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1161
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                __m512i value = _mm512_set1_epi64(val);
                __mmask64 cmp_result = _mm512_cmpeq_epi64_mask(vec, value);
                return _mm_popcnt_u64(cmp_result);
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1168
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                __m512 value = _mm512_set1_ps(val);
                __mmask16 cmp_result = _mm512_cmp_ps_mask(vec, value, _CMP_EQ_OQ);

                uint16_t mask_bits = static_cast<uint16_t>(cmp_result);

                while (mask_bits != 0) {
                  result += mask_bits & 1;
                  mask_bits >>= 1;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1183
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                __m512d value = _mm512_set1_pd(val);
                __mmask8 cmp_result = _mm512_cmp_pd_mask(vec, value, _CMP_EQ_OQ);

                uint8_t mask_bits = static_cast<uint8_t>(cmp_result);

                while (mask_bits != 0) {
                  result += mask_bits & 1;
                  mask_bits >>= 1;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx512 using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_AVX512_HPP