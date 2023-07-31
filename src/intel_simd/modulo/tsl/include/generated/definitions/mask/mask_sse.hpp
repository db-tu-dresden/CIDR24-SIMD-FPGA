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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/mask/mask_sse.hpp
 * \date 2023-07-22
 * \brief Mask related primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_SSE_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_SSE_HPP

#include <type_traits>
#include "../../declarations/mask.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::192
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return _mm_movemask_epi8(vec_mask);
            }
        };
    } // end of namespace functors for template specialization of to_integral for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::192
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return _mm_movemask_epi8(vec_mask);
            }
        };
    } // end of namespace functors for template specialization of to_integral for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse', 'sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::201
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive to_integral is not supported by your hardware natively while it is forced by using native" );

                return (typename Vec::imask_type)_mm_movemask_epi8(_mm_packs_epi16(vec_mask, _mm_setzero_si128()));
            }
        };
    } // end of namespace functors for template specialization of to_integral for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse', 'sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::201
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive to_integral is not supported by your hardware natively while it is forced by using native" );

                return (typename Vec::imask_type)_mm_movemask_epi8(_mm_packs_epi16(vec_mask, _mm_setzero_si128()));
            }
        };
    } // end of namespace functors for template specialization of to_integral for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::224
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return _mm_movemask_ps(vec_mask);
            }
        };
    } // end of namespace functors for template specialization of to_integral for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse', 'sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return _mm_movemask_ps(_mm_castsi128_ps(vec_mask));
            }
        };
    } // end of namespace functors for template specialization of to_integral for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse', 'sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return _mm_movemask_ps(_mm_castsi128_ps(vec_mask));
            }
        };
    } // end of namespace functors for template specialization of to_integral for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::232
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return _mm_movemask_pd(_mm_castsi128_pd(vec_mask));
            }
        };
    } // end of namespace functors for template specialization of to_integral for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::232
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return _mm_movemask_pd(_mm_castsi128_pd(vec_mask));
            }
        };
    } // end of namespace functors for template specialization of to_integral for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::236
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return _mm_movemask_pd(vec_mask);
            }
        };
    } // end of namespace functors for template specialization of to_integral for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::320
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
                const typename Vec::mask_type mask
            ) {
                return mask; //mask is a vector already.
            }
        };
    } // end of namespace functors for template specialization of to_vector for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::320
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
                const typename Vec::mask_type mask
            ) {
                return mask; //mask is a vector already.
            }
        };
    } // end of namespace functors for template specialization of to_vector for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::320
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
                const typename Vec::mask_type mask
            ) {
                return mask; //mask is a vector already.
            }
        };
    } // end of namespace functors for template specialization of to_vector for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::320
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
                const typename Vec::mask_type mask
            ) {
                return mask; //mask is a vector already.
            }
        };
    } // end of namespace functors for template specialization of to_vector for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::320
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
                const typename Vec::mask_type mask
            ) {
                return mask; //mask is a vector already.
            }
        };
    } // end of namespace functors for template specialization of to_vector for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::320
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
                const typename Vec::mask_type mask
            ) {
                return mask; //mask is a vector already.
            }
        };
    } // end of namespace functors for template specialization of to_vector for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::320
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
                const typename Vec::mask_type mask
            ) {
                return mask; //mask is a vector already.
            }
        };
    } // end of namespace functors for template specialization of to_vector for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::320
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
                const typename Vec::mask_type mask
            ) {
                return mask; //mask is a vector already.
            }
        };
    } // end of namespace functors for template specialization of to_vector for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::320
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
                const typename Vec::mask_type mask
            ) {
                return mask; //mask is a vector already.
            }
        };
    } // end of namespace functors for template specialization of to_vector for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::320
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
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
                const typename Vec::mask_type mask
            ) {
                return mask; //mask is a vector already.
            }
        };
    } // end of namespace functors for template specialization of to_vector for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::505
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_and_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::505
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_and_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::505
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_and_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::505
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_and_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::505
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_and_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::505
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_and_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::505
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_and_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::505
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_and_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::509
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_and_ps(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::513
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_and_pd(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::557
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first & second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_and for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::557
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first & second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_and for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::557
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first & second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_and for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::557
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first & second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_and for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::557
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first & second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_and for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::557
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first & second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_and for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::557
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first & second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_and for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::557
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first & second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_and for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::557
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first & second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_and for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::557
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first & second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_and for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::613
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_or_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::613
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_or_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::613
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_or_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::613
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_or_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::613
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_or_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::613
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_or_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::613
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_or_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::613
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_or_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_or_ps(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::621
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_or_pd(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::665
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first | second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_or for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::665
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first | second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_or for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::665
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first | second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_or for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::665
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first | second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_or for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::665
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first | second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_or for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::665
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first | second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_or for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::665
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first | second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_or for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::665
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first | second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_or for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::665
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first | second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_or for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::665
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first | second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_or for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::721
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_xor_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::721
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_xor_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::721
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_xor_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::721
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_xor_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::721
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_xor_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::721
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_xor_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::721
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_xor_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::721
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_xor_si128(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::725
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_xor_ps(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::729
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::mask_type>;
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
                const typename Vec::mask_type first, const typename Vec::mask_type second
            ) {
                return _mm_xor_pd(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first ^ second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_xor for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first ^ second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_xor for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first ^ second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_xor for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first ^ second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_xor for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first ^ second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_xor for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first ^ second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_xor for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first ^ second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_xor for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first ^ second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_xor for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first ^ second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_xor for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::imask_type>;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type first, const typename Vec::imask_type second
            ) {
                return first ^ second;
            }
        };
    } // end of namespace functors for template specialization of imask_binary_xor for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::863
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = unsigned int;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
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
            static unsigned int apply(
                const typename Vec::imask_type mask
            ) {
                #if defined(__clang__) || defined(__GNUC__)
                return __builtin_popcount(mask);
                #elif defined(_MSC_VER)
                return  __popcnt16(mask);
                #else
                static_assert(false, "No known implementation for popcount");
                #endif
            }
        };
    } // end of namespace functors for template specialization of imask_population_count for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::863
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = unsigned int;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
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
            static unsigned int apply(
                const typename Vec::imask_type mask
            ) {
                #if defined(__clang__) || defined(__GNUC__)
                return __builtin_popcount(mask);
                #elif defined(_MSC_VER)
                return  __popcnt16(mask);
                #else
                static_assert(false, "No known implementation for popcount");
                #endif
            }
        };
    } // end of namespace functors for template specialization of imask_population_count for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::863
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = unsigned int;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
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
            static unsigned int apply(
                const typename Vec::imask_type mask
            ) {
                #if defined(__clang__) || defined(__GNUC__)
                return __builtin_popcount(mask);
                #elif defined(_MSC_VER)
                return  __popcnt16(mask);
                #else
                static_assert(false, "No known implementation for popcount");
                #endif
            }
        };
    } // end of namespace functors for template specialization of imask_population_count for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::863
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = unsigned int;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
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
            static unsigned int apply(
                const typename Vec::imask_type mask
            ) {
                #if defined(__clang__) || defined(__GNUC__)
                return __builtin_popcount(mask);
                #elif defined(_MSC_VER)
                return  __popcnt16(mask);
                #else
                static_assert(false, "No known implementation for popcount");
                #endif
            }
        };
    } // end of namespace functors for template specialization of imask_population_count for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::874
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = unsigned int;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
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
            static unsigned int apply(
                const typename Vec::imask_type mask
            ) {
                #if defined(__clang__) || defined(__GNUC__)
                return __builtin_popcountl(mask);
                #elif defined(_MSC_VER)
                return  __popcnt32(mask);
                #else
                static_assert(false, "No known implementation for popcount");
                #endif
            }
        };
    } // end of namespace functors for template specialization of imask_population_count for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::874
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = unsigned int;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
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
            static unsigned int apply(
                const typename Vec::imask_type mask
            ) {
                #if defined(__clang__) || defined(__GNUC__)
                return __builtin_popcountl(mask);
                #elif defined(_MSC_VER)
                return  __popcnt32(mask);
                #else
                static_assert(false, "No known implementation for popcount");
                #endif
            }
        };
    } // end of namespace functors for template specialization of imask_population_count for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::874
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = unsigned int;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
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
            static unsigned int apply(
                const typename Vec::imask_type mask
            ) {
                #if defined(__clang__) || defined(__GNUC__)
                return __builtin_popcountl(mask);
                #elif defined(_MSC_VER)
                return  __popcnt32(mask);
                #else
                static_assert(false, "No known implementation for popcount");
                #endif
            }
        };
    } // end of namespace functors for template specialization of imask_population_count for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::885
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = unsigned int;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
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
            static unsigned int apply(
                const typename Vec::imask_type mask
            ) {
                #if defined(__clang__) || defined(__GNUC__)
                return __builtin_popcountll(mask);
                #elif defined(_MSC_VER)
                return  __popcnt64(mask);
                #else
                static_assert(false, "No known implementation for popcount");
                #endif
            }
        };
    } // end of namespace functors for template specialization of imask_population_count for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::885
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = unsigned int;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
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
            static unsigned int apply(
                const typename Vec::imask_type mask
            ) {
                #if defined(__clang__) || defined(__GNUC__)
                return __builtin_popcountll(mask);
                #elif defined(_MSC_VER)
                return  __popcnt64(mask);
                #else
                static_assert(false, "No known implementation for popcount");
                #endif
            }
        };
    } // end of namespace functors for template specialization of imask_population_count for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::885
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = unsigned int;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
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
            static unsigned int apply(
                const typename Vec::imask_type mask
            ) {
                #if defined(__clang__) || defined(__GNUC__)
                return __builtin_popcountll(mask);
                #elif defined(_MSC_VER)
                return  __popcnt64(mask);
                #else
                static_assert(false, "No known implementation for popcount");
                #endif
            }
        };
    } // end of namespace functors for template specialization of imask_population_count for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::921
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                if constexpr(Vec::vector_element_count() < 8) {
                  return (((typename Vec::imask_type)1<<Vec::vector_element_count()) - 1);
                } else {
                  return ~0;
                }
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::921
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                if constexpr(Vec::vector_element_count() < 8) {
                  return (((typename Vec::imask_type)1<<Vec::vector_element_count()) - 1);
                } else {
                  return ~0;
                }
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::921
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                if constexpr(Vec::vector_element_count() < 8) {
                  return (((typename Vec::imask_type)1<<Vec::vector_element_count()) - 1);
                } else {
                  return ~0;
                }
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::921
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                if constexpr(Vec::vector_element_count() < 8) {
                  return (((typename Vec::imask_type)1<<Vec::vector_element_count()) - 1);
                } else {
                  return ~0;
                }
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::921
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                if constexpr(Vec::vector_element_count() < 8) {
                  return (((typename Vec::imask_type)1<<Vec::vector_element_count()) - 1);
                } else {
                  return ~0;
                }
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::921
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                if constexpr(Vec::vector_element_count() < 8) {
                  return (((typename Vec::imask_type)1<<Vec::vector_element_count()) - 1);
                } else {
                  return ~0;
                }
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::921
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                if constexpr(Vec::vector_element_count() < 8) {
                  return (((typename Vec::imask_type)1<<Vec::vector_element_count()) - 1);
                } else {
                  return ~0;
                }
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::921
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                if constexpr(Vec::vector_element_count() < 8) {
                  return (((typename Vec::imask_type)1<<Vec::vector_element_count()) - 1);
                } else {
                  return ~0;
                }
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::921
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                if constexpr(Vec::vector_element_count() < 8) {
                  return (((typename Vec::imask_type)1<<Vec::vector_element_count()) - 1);
                } else {
                  return ~0;
                }
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::921
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                if constexpr(Vec::vector_element_count() < 8) {
                  return (((typename Vec::imask_type)1<<Vec::vector_element_count()) - 1);
                } else {
                  return ~0;
                }
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::954
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                return 0;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::954
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                return 0;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::954
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                return 0;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::954
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                return 0;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::954
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                return 0;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::954
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                return 0;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::954
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                return 0;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::954
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                return 0;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::954
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                return 0;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::954
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<>;
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
            static typename Vec::imask_type apply(
                
            ) {
                return 0;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::984
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<typename Vec::imask_type const*>;
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
                typename Vec::imask_type const* memory
            ) {
                return tsl::to_mask<Vec>(*memory);
            }
        };
    } // end of namespace functors for template specialization of load_mask for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::984
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<typename Vec::imask_type const*>;
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
                typename Vec::imask_type const* memory
            ) {
                return tsl::to_mask<Vec>(*memory);
            }
        };
    } // end of namespace functors for template specialization of load_mask for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::984
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<typename Vec::imask_type const*>;
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
                typename Vec::imask_type const* memory
            ) {
                return tsl::to_mask<Vec>(*memory);
            }
        };
    } // end of namespace functors for template specialization of load_mask for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::984
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<typename Vec::imask_type const*>;
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
                typename Vec::imask_type const* memory
            ) {
                return tsl::to_mask<Vec>(*memory);
            }
        };
    } // end of namespace functors for template specialization of load_mask for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::984
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<typename Vec::imask_type const*>;
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
                typename Vec::imask_type const* memory
            ) {
                return tsl::to_mask<Vec>(*memory);
            }
        };
    } // end of namespace functors for template specialization of load_mask for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::984
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<typename Vec::imask_type const*>;
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
                typename Vec::imask_type const* memory
            ) {
                return tsl::to_mask<Vec>(*memory);
            }
        };
    } // end of namespace functors for template specialization of load_mask for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::984
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<typename Vec::imask_type const*>;
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
                typename Vec::imask_type const* memory
            ) {
                return tsl::to_mask<Vec>(*memory);
            }
        };
    } // end of namespace functors for template specialization of load_mask for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::984
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<typename Vec::imask_type const*>;
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
                typename Vec::imask_type const* memory
            ) {
                return tsl::to_mask<Vec>(*memory);
            }
        };
    } // end of namespace functors for template specialization of load_mask for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::984
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<typename Vec::imask_type const*>;
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
                typename Vec::imask_type const* memory
            ) {
                return tsl::to_mask<Vec>(*memory);
            }
        };
    } // end of namespace functors for template specialization of load_mask for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/mask.yaml::984
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<typename Vec::imask_type const*>;
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
                typename Vec::imask_type const* memory
            ) {
                return tsl::to_mask<Vec>(*memory);
            }
        };
    } // end of namespace functors for template specialization of load_mask for sse using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_SSE_HPP