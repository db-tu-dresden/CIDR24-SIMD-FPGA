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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/compare/compare_avx2.hpp
 * \date 2023-07-22
 * \brief Compare primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_AVX2_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_AVX2_HPP

#include "../../declarations/compare.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::96
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_cmpeq_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::96
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_cmpeq_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::96
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_cmpeq_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::96
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_cmpeq_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::96
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_cmpeq_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::96
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_cmpeq_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::96
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_cmpeq_epi64(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::96
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_cmpeq_epi64(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of equal for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx', 'avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::101
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive equal is not supported by your hardware natively while it is forced by using native" );

                return _mm256_castsi256_ps(_mm256_cmpeq_epi32(_mm256_castps_si256(vec_a), _mm256_castps_si256(vec_b)));
            }
        };
    } // end of namespace functors for template specialization of equal for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx', 'avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::107
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct equal<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive equal is not supported by your hardware natively while it is forced by using native" );

                return _mm256_castsi256_pd(_mm256_cmpeq_epi64(_mm256_castpd_si256(vec_a), _mm256_castpd_si256(vec_b)));
            }
        };
    } // end of namespace functors for template specialization of equal for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::204
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_equal<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm256_and_si256(_mm256_cmpeq_epi8(vec_a, vec_b), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_equal for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::204
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_equal<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm256_and_si256(_mm256_cmpeq_epi8(vec_a, vec_b), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_equal for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::204
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_equal<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm256_and_si256(_mm256_cmpeq_epi16(vec_a, vec_b), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_equal for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::204
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_equal<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm256_and_si256(_mm256_cmpeq_epi16(vec_a, vec_b), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_equal for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::204
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_equal<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm256_and_si256(_mm256_cmpeq_epi32(vec_a, vec_b), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_equal for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::204
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_equal<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm256_and_si256(_mm256_cmpeq_epi32(vec_a, vec_b), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_equal for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::204
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_equal<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm256_and_si256(_mm256_cmpeq_epi64(vec_a, vec_b), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_equal for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_equal" (primitive equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::204
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_equal<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                return _mm256_and_si256(_mm256_cmpeq_epi64(vec_a, vec_b), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_equal for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::242
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive nequal is not supported by your hardware natively while it is forced by using native" );

                auto const all_set = _mm256_cmpeq_epi8(vec_a,vec_a);
                return _mm256_andnot_si256(_mm256_cmpeq_epi8(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::242
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive nequal is not supported by your hardware natively while it is forced by using native" );

                auto const all_set = _mm256_cmpeq_epi8(vec_a,vec_a);
                return _mm256_andnot_si256(_mm256_cmpeq_epi8(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::242
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive nequal is not supported by your hardware natively while it is forced by using native" );

                auto const all_set = _mm256_cmpeq_epi16(vec_a,vec_a);
                return _mm256_andnot_si256(_mm256_cmpeq_epi16(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::242
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive nequal is not supported by your hardware natively while it is forced by using native" );

                auto const all_set = _mm256_cmpeq_epi16(vec_a,vec_a);
                return _mm256_andnot_si256(_mm256_cmpeq_epi16(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::242
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive nequal is not supported by your hardware natively while it is forced by using native" );

                auto const all_set = _mm256_cmpeq_epi32(vec_a,vec_a);
                return _mm256_andnot_si256(_mm256_cmpeq_epi32(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::242
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive nequal is not supported by your hardware natively while it is forced by using native" );

                auto const all_set = _mm256_cmpeq_epi32(vec_a,vec_a);
                return _mm256_andnot_si256(_mm256_cmpeq_epi32(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::242
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive nequal is not supported by your hardware natively while it is forced by using native" );

                auto const all_set = _mm256_cmpeq_epi64(vec_a,vec_a);
                return _mm256_andnot_si256(_mm256_cmpeq_epi64(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::242
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive nequal is not supported by your hardware natively while it is forced by using native" );

                auto const all_set = _mm256_cmpeq_epi64(vec_a,vec_a);
                return _mm256_andnot_si256(_mm256_cmpeq_epi64(vec_a, vec_b), all_set);
            }
        };
    } // end of namespace functors for template specialization of nequal for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx', 'avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::249
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive nequal is not supported by your hardware natively while it is forced by using native" );

                auto const all_set = _mm256_cmpeq_epi32(_mm256_castps_si256(vec_a),_mm256_castps_si256(vec_a));
                return _mm256_castsi256_ps(_mm256_andnot_si256(_mm256_cmpeq_epi32(_mm256_castps_si256(vec_a), _mm256_castps_si256(vec_b)), all_set));
            }
        };
    } // end of namespace functors for template specialization of nequal for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx', 'avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::257
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                static_assert( !std::is_same_v< Idof, native >, "The primitive nequal is not supported by your hardware natively while it is forced by using native" );

                auto const all_set = _mm256_cmpeq_epi64(_mm256_castpd_si256(vec_a),_mm256_castpd_si256(vec_a));
                return
                  _mm256_castsi256_pd(
                    _mm256_andnot_si256(
                      _mm256_cmpeq_epi64(
                        _mm256_castpd_si256(vec_a),
                        _mm256_castpd_si256(vec_b)
                      ),
                      all_set
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of nequal for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::342
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_andnot_si256( _mm256_cmpgt_epi64( vec_min, vec_data ), _mm256_andnot_si256( _mm256_cmpgt_epi64( vec_data, vec_max ), _mm256_set1_epi64x(-1)));
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/compare.yaml::347
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_and_ps(_mm256_cmp_ps(vec_data, vec_min, _CMP_GE_OQ ), _mm256_cmp_ps(vec_max, vec_data, _CMP_GE_OQ));
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/compare.yaml::347
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_and_pd(_mm256_cmp_pd(vec_data, vec_min, _CMP_GE_OQ ), _mm256_cmp_pd(vec_max, vec_data, _CMP_GE_OQ));
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::455
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_cmpgt_epi8(vec_b, vec_a);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::455
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_cmpgt_epi16(vec_b, vec_a);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::455
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_cmpgt_epi32(vec_b, vec_a);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::455
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_cmpgt_epi64(vec_b, vec_a);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/compare.yaml::460
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_cmp_ps(vec_a, vec_b, _CMP_LT_OQ);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/compare.yaml::460
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_cmp_pd(vec_a, vec_b, _CMP_LT_OQ);
            }
        };
    } // end of namespace functors for template specialization of less_than for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::464
         * @note: Unsigned comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpeq_epi8(vec_a, _mm256_max_epu8(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of less_than for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::464
         * @note: Unsigned comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpeq_epi16(vec_a, _mm256_max_epu16(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of less_than for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::464
         * @note: Unsigned comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpeq_epi32(vec_a, _mm256_max_epu32(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of less_than for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::470
         * @note: Unsigned comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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

                __m256i sign_bits = _mm256_set1_epi64x((int64_t)1 << 63); return _mm256_cmpgt_epi64(_mm256_xor_si256(vec_b, sign_bits), _mm256_xor_si256(vec_a, sign_bits));
            }
        };
    } // end of namespace functors for template specialization of less_than for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::600
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_cmpgt_epi8(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::600
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_cmpgt_epi16(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::600
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_cmpgt_epi32(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::600
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_cmpgt_epi64(vec_a, vec_b);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/compare.yaml::605
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_cmp_ps(vec_a, vec_b, _CMP_GT_OQ);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/compare.yaml::605
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_cmp_pd(vec_a, vec_b, _CMP_GT_OQ);
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::609
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpeq_epi8(vec_b, _mm256_max_epu8(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::609
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpeq_epi16(vec_b, _mm256_max_epu16(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::609
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpeq_epi32(vec_b, _mm256_max_epu32(vec_a, vec_b)));
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::614
         * @note: Using signed comparison as unsigned by flipping the sign bit.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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

                __m256i sign_bits = _mm256_set1_epi64x((int64_t)1 << 63); return _mm256_cmpgt_epi64(_mm256_xor_si256(vec_a, sign_bits), _mm256_xor_si256(vec_b, sign_bits));
            }
        };
    } // end of namespace functors for template specialization of greater_than for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::742
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpgt_epi8(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::742
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpgt_epi16(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::742
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpgt_epi32(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::742
         * @note: Signed comparison.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpgt_epi64(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/compare.yaml::748
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_cmp_ps(vec_a, vec_b, _CMP_LE_OQ);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/compare.yaml::748
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_cmp_pd(vec_a, vec_b, _CMP_LE_OQ);
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::752
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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

                return _mm256_cmpeq_epi8(vec_b, _mm256_max_epu8(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::752
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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

                return _mm256_cmpeq_epi16(vec_b, _mm256_max_epu16(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::752
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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

                return _mm256_cmpeq_epi32(vec_b, _mm256_max_epu32(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::757
         * @note: Using signed comparison as unsigned by flipping the sign bit.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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

                __m256i sign_bits = _mm256_set1_epi64x((int64_t)1 << 63);
                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpgt_epi64(_mm256_xor_si256(vec_a, sign_bits), _mm256_xor_si256(vec_b, sign_bits)));
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::895
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpgt_epi8(vec_b, vec_a));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::895
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpgt_epi16(vec_b, vec_a));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::895
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpgt_epi32(vec_b, vec_a));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::895
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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

                return _mm256_xor_si256(_mm256_set1_epi8(-1), _mm256_cmpgt_epi64(vec_b, vec_a));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/compare.yaml::900
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_cmp_ps(vec_a, vec_b, _CMP_GE_OQ);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/compare.yaml::900
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_cmp_pd(vec_a, vec_b, _CMP_GE_OQ);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::904
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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

                return _mm256_cmpeq_epi8(vec_a, _mm256_max_epu8(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::904
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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

                return _mm256_cmpeq_epi16(vec_a, _mm256_max_epu16(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::904
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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

                return _mm256_cmpeq_epi32(vec_a, _mm256_max_epu32(vec_a, vec_b));
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::909
         * @note: Using signed comparison as unsigned by flipping the sign bit.
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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

                __m256i sign_bits = _mm256_set1_epi64x((int64_t)1 << 63);
                __m256i less_than = _mm256_cmpgt_epi64(_mm256_xor_si256(vec_b, sign_bits), _mm256_xor_si256(vec_a, sign_bits));
                return _mm256_xor_si256(_mm256_set1_epi8(-1), less_than);
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1051
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return (_mm256_testz_si256(vec,vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1051
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return (_mm256_testz_si256(vec,vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1051
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return (_mm256_testz_si256(vec,vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1051
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return (_mm256_testz_si256(vec,vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1051
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return (_mm256_testz_si256(vec,vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1051
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return (_mm256_testz_si256(vec,vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1051
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return (_mm256_testz_si256(vec,vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1051
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return (_mm256_testz_si256(vec,vec) == 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1055
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return (_mm256_movemask_ps(_mm256_cmp_ps(vec, _mm256_setzero_ps(), _CMP_NEQ_UQ)) != 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "unequal_zero" (primitive unequal_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1055
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct unequal_zero<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return (_mm256_movemask_pd(_mm256_cmp_pd(vec, _mm256_setzero_pd(), _CMP_NEQ_UQ)) != 0);
            }
        };
    } // end of namespace functors for template specialization of unequal_zero for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1199
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                __m256i value = _mm256_set1_epi16(val);
                __m256i is_equal = _mm256_cmpeq_epi16(vec, value);
                T mask[Vec::vector_element_count()];
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1199
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                __m256i value = _mm256_set1_epi16(val);
                __m256i is_equal = _mm256_cmpeq_epi16(vec, value);
                T mask[Vec::vector_element_count()];
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1199
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                __m256i value = _mm256_set1_epi32(val);
                __m256i is_equal = _mm256_cmpeq_epi32(vec, value);
                T mask[Vec::vector_element_count()];
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1199
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                __m256i value = _mm256_set1_epi32(val);
                __m256i is_equal = _mm256_cmpeq_epi32(vec, value);
                T mask[Vec::vector_element_count()];
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1199
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                __m256i value = _mm256_set1_epi64x(val);
                __m256i is_equal = _mm256_cmpeq_epi64(vec, value);
                T mask[Vec::vector_element_count()];
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1199
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                __m256i value = _mm256_set1_epi64x(val);
                __m256i is_equal = _mm256_cmpeq_epi64(vec, value);
                T mask[Vec::vector_element_count()];
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1199
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                __m256i value = _mm256_set1_epi8(val);
                __m256i is_equal = _mm256_cmpeq_epi8(vec, value);
                T mask[Vec::vector_element_count()];
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1199
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                __m256i value = _mm256_set1_epi8(val);
                __m256i is_equal = _mm256_cmpeq_epi8(vec, value);
                T mask[Vec::vector_element_count()];
                _mm256_storeu_si256(reinterpret_cast<__m256i*>(mask), is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask[i] == ((T)-1)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1220
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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

                __m256 value, is_equal;

                value = _mm256_set1_ps(val);
                is_equal = _mm256_cmp_ps(vec, value, _CMP_EQ_OQ);
                int mask = _mm256_movemask_ps(is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask & (1 << i)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "count_matches" (primitive count_matches).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/compare.yaml::1220
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct count_matches<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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

                __m256d value, is_equal;

                value = _mm256_set1_pd(val);
                is_equal = _mm256_cmp_pd(vec, value, _CMP_EQ_OQ);
                int mask = _mm256_movemask_pd(is_equal);

                for (int i = 0; i < Vec::vector_element_count(); i++){
                  if(mask & (1 << i)){
                    result ++;
                  }
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of count_matches for avx2 using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_AVX2_HPP