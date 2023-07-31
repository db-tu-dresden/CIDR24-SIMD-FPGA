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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/mask/mask_avx2.hpp
 * \date 2023-07-22
 * \brief Mask related primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_AVX2_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_AVX2_HPP

#include <type_traits>
#include "../../declarations/mask.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::106
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_movemask_epi8(vec_mask);
            }
        };
    } // end of namespace functors for template specialization of to_integral for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::106
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_movemask_epi8(vec_mask);
            }
        };
    } // end of namespace functors for template specialization of to_integral for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx', 'avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::115
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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

                auto const packed = _mm256_packs_epi16(vec_mask, _mm256_setzero_si256());
                auto const shuffled = _mm256_permute4x64_epi64(packed, 8);
                return (typename Vec::imask_type) _mm256_movemask_epi8(shuffled);
            }
        };
    } // end of namespace functors for template specialization of to_integral for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx', 'avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::115
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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

                auto const packed = _mm256_packs_epi16(vec_mask, _mm256_setzero_si256());
                auto const shuffled = _mm256_permute4x64_epi64(packed, 8);
                return (typename Vec::imask_type) _mm256_movemask_epi8(shuffled);
            }
        };
    } // end of namespace functors for template specialization of to_integral for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::175
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_movemask_ps(vec_mask);
            }
        };
    } // end of namespace functors for template specialization of to_integral for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::179
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_movemask_ps(_mm256_castsi256_ps(vec_mask));
            }
        };
    } // end of namespace functors for template specialization of to_integral for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::179
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_movemask_ps(_mm256_castsi256_ps(vec_mask));
            }
        };
    } // end of namespace functors for template specialization of to_integral for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::183
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_movemask_pd(_mm256_castsi256_pd(vec_mask));
            }
        };
    } // end of namespace functors for template specialization of to_integral for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::183
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_movemask_pd(_mm256_castsi256_pd(vec_mask));
            }
        };
    } // end of namespace functors for template specialization of to_integral for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::187
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_movemask_pd(vec_mask);
            }
        };
    } // end of namespace functors for template specialization of to_integral for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::315
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_vector for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::315
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_vector for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::315
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_vector for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::315
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_vector for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::315
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_vector for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::315
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_vector for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::315
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_vector for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::315
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_vector for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::315
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of to_vector for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::315
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of to_vector for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::358
         * @note: @todo: Verify!
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::imask_type mask
            ) {
                auto const permute_vec = _mm256_set_epi64x(0x303030303030303, 0x202020202020202, 0x101010101010101, 0x0);
                auto const data_vec = _mm256_set1_epi32(mask);
                auto const shuffled_vec = _mm256_shuffle_epi8(data_vec, permute_vec);
                auto const and_vec = _mm256_set1_epi64x(0x8040201008040201);
                auto const and_shuffled_vec = _mm256_and_si256(shuffled_vec, and_vec);
                auto result = _mm256_cmpeq_epi8(and_shuffled_vec, and_vec);
                return result;
            }
        };
    } // end of namespace functors for template specialization of to_mask for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::358
         * @note: @todo: Verify!
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::imask_type mask
            ) {
                auto const permute_vec = _mm256_set_epi64x(0x303030303030303, 0x202020202020202, 0x101010101010101, 0x0);
                auto const data_vec = _mm256_set1_epi32(mask);
                auto const shuffled_vec = _mm256_shuffle_epi8(data_vec, permute_vec);
                auto const and_vec = _mm256_set1_epi64x(0x8040201008040201);
                auto const and_shuffled_vec = _mm256_and_si256(shuffled_vec, and_vec);
                auto result = _mm256_cmpeq_epi8(and_shuffled_vec, and_vec);
                return result;
            }
        };
    } // end of namespace functors for template specialization of to_mask for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::imask_type mask
            ) {
                auto const and_vec = _mm256_set_epi64x(0x8000400020001000, 0x800040002000100, 0x80004000200010, 0x8000400020001);
                auto const data_vec = _mm256_set1_epi16(mask);
                auto const anded_vec = _mm256_and_si256(data_vec, and_vec);
                return _mm256_cmpeq_epi16(anded_vec, and_vec);
            }
        };
    } // end of namespace functors for template specialization of to_mask for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::imask_type mask
            ) {
                auto const and_vec = _mm256_set_epi64x(0x8000400020001000, 0x800040002000100, 0x80004000200010, 0x8000400020001);
                auto const data_vec = _mm256_set1_epi16(mask);
                auto const anded_vec = _mm256_and_si256(data_vec, and_vec);
                return _mm256_cmpeq_epi16(anded_vec, and_vec);
            }
        };
    } // end of namespace functors for template specialization of to_mask for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::imask_type mask
            ) {
                auto const and_vec = _mm256_set_epi64x(0x8000000040, 0x2000000010, 0x800000004, 0x200000001);
                auto const data_vec = _mm256_set1_epi32(mask);
                auto const anded_vec = _mm256_and_si256(data_vec, and_vec);
                return _mm256_cmpeq_epi32(anded_vec, and_vec);
            }
        };
    } // end of namespace functors for template specialization of to_mask for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::imask_type mask
            ) {
                auto const and_vec = _mm256_set_epi64x(0x8000000040, 0x2000000010, 0x800000004, 0x200000001);
                auto const data_vec = _mm256_set1_epi32(mask);
                auto const anded_vec = _mm256_and_si256(data_vec, and_vec);
                return _mm256_cmpeq_epi32(anded_vec, and_vec);
            }
        };
    } // end of namespace functors for template specialization of to_mask for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::386
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::imask_type mask
            ) {
                auto const and_vec = _mm256_set_epi64x(0x8000000040, 0x2000000010, 0x800000004, 0x200000001);
                auto const data_vec = _mm256_set1_epi32(mask);
                auto const anded_vec = _mm256_and_si256(data_vec, and_vec);
                return _mm256_castsi256_ps(_mm256_cmpeq_epi32(anded_vec, and_vec));
            }
        };
    } // end of namespace functors for template specialization of to_mask for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::394
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::imask_type mask
            ) {
                auto const and_vec = _mm256_set_epi64x(0x8, 0x4, 0x2, 0x1);
                auto const data_vec = _mm256_set1_epi64x(mask);
                auto const anded_vec = _mm256_and_si256(data_vec, and_vec);
                return _mm256_cmpeq_epi64(anded_vec, and_vec);
            }
        };
    } // end of namespace functors for template specialization of to_mask for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::394
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::imask_type mask
            ) {
                auto const and_vec = _mm256_set_epi64x(0x8, 0x4, 0x2, 0x1);
                auto const data_vec = _mm256_set1_epi64x(mask);
                auto const anded_vec = _mm256_and_si256(data_vec, and_vec);
                return _mm256_cmpeq_epi64(anded_vec, and_vec);
            }
        };
    } // end of namespace functors for template specialization of to_mask for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::402
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::imask_type mask
            ) {
                auto const and_vec = _mm256_set_epi64x(0x8, 0x4, 0x2, 0x1);
                auto const data_vec = _mm256_set1_epi64x(mask);
                auto const anded_vec = _mm256_and_si256(data_vec, and_vec);
                return _mm256_castsi256_pd(_mm256_cmpeq_epi64(anded_vec, and_vec));
            }
        };
    } // end of namespace functors for template specialization of to_mask for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::428
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_not<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type mask
            ) {
                return (~mask);
            }
        };
    } // end of namespace functors for template specialization of imask_binary_not for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::428
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_not<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type mask
            ) {
                return (~mask);
            }
        };
    } // end of namespace functors for template specialization of imask_binary_not for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::428
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_not<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type mask
            ) {
                return (~mask);
            }
        };
    } // end of namespace functors for template specialization of imask_binary_not for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::428
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_not<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type mask
            ) {
                return (~mask);
            }
        };
    } // end of namespace functors for template specialization of imask_binary_not for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::428
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_not<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type mask
            ) {
                return (~mask);
            }
        };
    } // end of namespace functors for template specialization of imask_binary_not for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::428
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_not<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type mask
            ) {
                return (~mask);
            }
        };
    } // end of namespace functors for template specialization of imask_binary_not for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::432
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_not<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type mask
            ) {
                return (~mask)&(0b1111);
            }
        };
    } // end of namespace functors for template specialization of imask_binary_not for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::432
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_not<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::imask_type mask
            ) {
                return (~mask)&(0b1111);
            }
        };
    } // end of namespace functors for template specialization of imask_binary_not for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::454
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_not<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask
            ) {
                return _mm256_xor_si256(_mm256_set1_epi8(-1), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_not for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::454
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_not<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask
            ) {
                return _mm256_xor_si256(_mm256_set1_epi8(-1), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_not for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::454
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_not<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask
            ) {
                return _mm256_xor_si256(_mm256_set1_epi8(-1), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_not for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::454
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_not<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask
            ) {
                return _mm256_xor_si256(_mm256_set1_epi8(-1), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_not for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::454
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_not<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask
            ) {
                return _mm256_xor_si256(_mm256_set1_epi8(-1), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_not for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::454
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_not<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask
            ) {
                return _mm256_xor_si256(_mm256_set1_epi8(-1), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_not for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::454
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_not<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask
            ) {
                return _mm256_xor_si256(_mm256_set1_epi8(-1), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_not for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_not" (primitive mask_binary_not).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::454
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_not<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::mask_type mask
            ) {
                return _mm256_xor_si256(_mm256_set1_epi8(-1), mask);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_not for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_and_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_and_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_and_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_and_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_and_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_and_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_and_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_and_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::500
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_and_ps(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::500
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_and<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_and_pd(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_and for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_and for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_and for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_and for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_and for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_and for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_and for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_and for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_and for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_and for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_and" (primitive mask_binary_and).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_and<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_and for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::599
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_or_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::599
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_or_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::599
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_or_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::599
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_or_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::599
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_or_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::599
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_or_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::599
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_or_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::599
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_or_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::608
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_or_ps(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::608
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_or<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_or_pd(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_or for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::660
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_or for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::660
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_or for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::660
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_or for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::660
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_or for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::660
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_or for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::660
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_or for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::660
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_or for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::660
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_or for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::660
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_or for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_or" (primitive mask_binary_or).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::660
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_or<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_or for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::707
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_xor_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::707
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_xor_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::707
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_xor_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::707
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_xor_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::707
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_xor_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::707
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_xor_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::707
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_xor_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::707
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_xor_si256(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::716
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_xor_ps(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::716
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_binary_xor<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_xor_pd(first, second);
            }
        };
    } // end of namespace functors for template specialization of mask_binary_xor for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::768
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_xor for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::768
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_xor for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::768
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_xor for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::768
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_xor for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::768
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_xor for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::768
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_xor for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::768
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_xor for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::768
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_xor for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::768
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_xor for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_binary_xor" (primitive mask_binary_xor).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::768
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_binary_xor<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_binary_xor for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::829
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_population_count for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::829
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_population_count for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::829
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_population_count for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::829
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_population_count for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::840
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_population_count for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::840
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_population_count for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::840
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_population_count for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::851
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_population_count for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::851
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_population_count for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_population_count" (primitive mask_population_count).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::851
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_population_count<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of imask_population_count for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::910
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_true for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::910
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_true for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::910
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_true for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::910
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_true for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::910
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_true for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::910
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_true for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::910
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_true for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::910
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_true for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::910
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_true for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::910
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_true for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_false for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_false for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_false for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_false for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_false for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_false for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_false for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_false for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_false for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/mask.yaml::949
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of integral_all_false for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::980
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of load_mask for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::980
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of load_mask for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::980
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of load_mask for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::980
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of load_mask for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::980
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of load_mask for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::980
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of load_mask for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::980
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of load_mask for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::980
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of load_mask for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::980
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of load_mask for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_mask" (primitive load_mask).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/mask.yaml::980
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_mask<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of load_mask for avx2 using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_AVX2_HPP