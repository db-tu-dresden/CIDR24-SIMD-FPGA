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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/binary/binary_sse.hpp
 * \date 2023-07-22
 * \brief Bit manipulation primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_BINARY_BINARY_SSE_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_BINARY_BINARY_SSE_HPP

#include <climits>
#include "../../declarations/binary.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::74
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint8_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_and_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_and for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::74
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint16_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_and_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_and for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::74
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint32_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_and_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_and for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::74
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint64_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_and_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_and for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::74
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int8_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_and_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_and for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::74
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int16_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_and_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_and for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::74
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int32_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_and_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_and for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::74
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int64_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_and_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_and for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/binary.yaml::78
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<float, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_and_ps(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_and for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::82
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<double, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_and_pd(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_and for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::209
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint8_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_or_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_or for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::209
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint16_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_or_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_or for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::209
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint32_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_or_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_or for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::209
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint64_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_or_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_or for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::209
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int8_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_or_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_or for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::209
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int16_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_or_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_or for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::209
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int32_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_or_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_or for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::209
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int64_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_or_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_or for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::213
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<float, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_or_ps(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_or for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::217
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<double, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_or_pd(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_or for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::332
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint8_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_xor_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_xor for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::332
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint16_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_xor_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_xor for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::332
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint32_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_xor_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_xor for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::332
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint64_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_xor_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_xor for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::332
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int8_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_xor_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_xor for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::332
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int16_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_xor_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_xor for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::332
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int32_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_xor_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_xor for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::332
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int64_t, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_xor_si128(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_xor for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/binary.yaml::336
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<float, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_xor_ps(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_xor for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::340
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<double, sse>, Idof> {
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
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                return _mm_xor_pd(a, b);
            }
        };
    } // end of namespace functors for template specialization of binary_xor for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::440
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                return _mm_slli_epi16(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::440
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                return _mm_slli_epi32(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::440
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                return _mm_slli_epi64(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::440
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                return _mm_slli_epi16(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::440
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                return _mm_slli_epi32(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::440
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                return _mm_slli_epi64(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/binary.yaml::538
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<uint16_t, sse>, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                return _mm_sllv_epi16(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/binary.yaml::538
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<int16_t, sse>, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                return _mm_sllv_epi16(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::542
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<uint32_t, sse>, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                return _mm_sllv_epi32(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::542
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<uint64_t, sse>, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                return _mm_sllv_epi64(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::542
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<int32_t, sse>, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                return _mm_sllv_epi32(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::542
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<int64_t, sse>, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                return _mm_sllv_epi64(data, shift);
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::681
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<uint16_t, sse>, PreserveSign, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (PreserveSign)) {
                  return _mm_srai_epi16(data, shift);
                } else {
                  return _mm_srli_epi16(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::681
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<uint32_t, sse>, PreserveSign, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (PreserveSign)) {
                  return _mm_srai_epi32(data, shift);
                } else {
                  return _mm_srli_epi32(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::681
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<int16_t, sse>, PreserveSign, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (PreserveSign)) {
                  return _mm_srai_epi16(data, shift);
                } else {
                  return _mm_srli_epi16(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::681
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<int32_t, sse>, PreserveSign, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (PreserveSign)) {
                  return _mm_srai_epi32(data, shift);
                } else {
                  return _mm_srli_epi32(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::681
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<uint64_t, sse>, PreserveSign, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (PreserveSign)) {
                  return _mm_srai_epi64(data, shift);
                } else {
                  return _mm_srli_epi64(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/binary.yaml::690
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<int64_t, sse>, PreserveSign, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned int>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type data, const unsigned int shift
            ) {
                if constexpr (PreserveSign) {
                  return _mm_srai_epi64(data, shift);
                } else {
                  return _mm_srli_epi64(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::939
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<int32_t, sse>, PreserveSign, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (PreserveSign)) {
                  return _mm_srav_epi32(data, shift);
                } else {
                  return _mm_srlv_epi32(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::939
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<uint32_t, sse>, PreserveSign, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (PreserveSign)) {
                  return _mm_srav_epi32(data, shift);
                } else {
                  return _mm_srlv_epi32(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::939
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<uint64_t, sse>, PreserveSign, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (PreserveSign)) {
                  return _mm_srav_epi64(data, shift);
                } else {
                  return _mm_srlv_epi64(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::948
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<int64_t, sse>, PreserveSign, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                if constexpr (PreserveSign) {
                  auto const shifted = _mm_srlv_epi64(data, shift);
                  auto const msb_as_lsb = _mm_srli_epi64(data, sizeof(int64_t)*CHAR_BIT-1);
                  auto const lsb_shifted = _mm_sllv_epi64(msb_as_lsb, shift);
                  auto const lsb_all_set = _mm_sub_epi64(lsb_shifted, _mm_set1_epi64x(1));
                  auto const lsb_mask = _mm_sub_epi64(_mm_srli_epi64(data, sizeof(int64_t)*CHAR_BIT-1), _mm_set1_epi64x(1));
                  auto const result_msb_as_lsb = _mm_andnot_si128(lsb_mask, lsb_all_set);
                  auto const result_msb = _mm_sllv_epi64(result_msb_as_lsb, _mm_sub_epi64(_mm_set1_epi64x(sizeof(int64_t)*CHAR_BIT), shift));
                  return _mm_or_si128(shifted, result_msb);
                } else {
                  return _mm_srlv_epi64(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2', 'avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/binary.yaml::965
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<uint16_t, sse>, PreserveSign, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (PreserveSign)) {
                  return _mm_srav_epi16(data, shift);
                } else {
                  return _mm_srlv_epi16(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2', 'avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/binary.yaml::965
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<int16_t, sse>, PreserveSign, Idof> {
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
                const typename Vec::register_type data, const typename Vec::register_type shift
            ) {
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (PreserveSign)) {
                  return _mm_srav_epi16(data, shift);
                } else {
                  return _mm_srlv_epi16(data, shift);
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1155
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::offset_base_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_type apply(
                const typename Vec::base_type data
            ) {
                return details::clz<typename Vec::base_type, typename Vec::offset_base_type>(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1155
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::offset_base_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_type apply(
                const typename Vec::base_type data
            ) {
                return details::clz<typename Vec::base_type, typename Vec::offset_base_type>(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1155
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::offset_base_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_type apply(
                const typename Vec::base_type data
            ) {
                return details::clz<typename Vec::base_type, typename Vec::offset_base_type>(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1155
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::offset_base_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_type apply(
                const typename Vec::base_type data
            ) {
                return details::clz<typename Vec::base_type, typename Vec::offset_base_type>(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1155
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::offset_base_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_type apply(
                const typename Vec::base_type data
            ) {
                return details::clz<typename Vec::base_type, typename Vec::offset_base_type>(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1155
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::offset_base_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_type apply(
                const typename Vec::base_type data
            ) {
                return details::clz<typename Vec::base_type, typename Vec::offset_base_type>(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1155
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::offset_base_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_type apply(
                const typename Vec::base_type data
            ) {
                return details::clz<typename Vec::base_type, typename Vec::offset_base_type>(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1155
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::offset_base_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_type apply(
                const typename Vec::base_type data
            ) {
                return details::clz<typename Vec::base_type, typename Vec::offset_base_type>(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1355
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint16_t, sse>, Idof> {
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
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type vec
            ) {
                // Reduce Lanes dependend on datatype
                Vec::register_type temp = _mm_or_si128(vec, _mm_srli_si128(vec, 8));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 4));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 2));
                return _mm_extract_epi16(temp, 0);
            }
        };
    } // end of namespace functors for template specialization of hor for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1355
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int16_t, sse>, Idof> {
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
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type vec
            ) {
                // Reduce Lanes dependend on datatype
                Vec::register_type temp = _mm_or_si128(vec, _mm_srli_si128(vec, 8));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 4));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 2));
                return _mm_extract_epi16(temp, 0);
            }
        };
    } // end of namespace functors for template specialization of hor for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1355
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec
            ) {
                // Reduce Lanes dependend on datatype
                Vec::register_type temp = _mm_or_si128(vec, _mm_srli_si128(vec, 8));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 4));
                return _mm_extract_epi32(temp, 0);
            }
        };
    } // end of namespace functors for template specialization of hor for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1355
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec
            ) {
                // Reduce Lanes dependend on datatype
                Vec::register_type temp = _mm_or_si128(vec, _mm_srli_si128(vec, 8));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 4));
                return _mm_extract_epi32(temp, 0);
            }
        };
    } // end of namespace functors for template specialization of hor for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1355
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint64_t, sse>, Idof> {
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
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type vec
            ) {
                // Reduce Lanes dependend on datatype
                Vec::register_type temp = _mm_or_si128(vec, _mm_srli_si128(vec, 8));
                return _mm_extract_epi64(temp, 0);
            }
        };
    } // end of namespace functors for template specialization of hor for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1355
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int64_t, sse>, Idof> {
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
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type vec
            ) {
                // Reduce Lanes dependend on datatype
                Vec::register_type temp = _mm_or_si128(vec, _mm_srli_si128(vec, 8));
                return _mm_extract_epi64(temp, 0);
            }
        };
    } // end of namespace functors for template specialization of hor for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1355
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint8_t, sse>, Idof> {
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
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type vec
            ) {
                // Reduce Lanes dependend on datatype
                Vec::register_type temp = _mm_or_si128(vec, _mm_srli_si128(vec, 8));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 4));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 2));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 1));
                return _mm_extract_epi8(temp, 0);
            }
        };
    } // end of namespace functors for template specialization of hor for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1355
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int8_t, sse>, Idof> {
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
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type vec
            ) {
                // Reduce Lanes dependend on datatype
                Vec::register_type temp = _mm_or_si128(vec, _mm_srli_si128(vec, 8));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 4));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 2));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 1));
                return _mm_extract_epi8(temp, 0);
            }
        };
    } // end of namespace functors for template specialization of hor for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1372
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::base_type;
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
            static typename Vec::base_type apply(
                const typename Vec::register_type vec
            ) {
                __m128i temp = _mm_castps_si128(vec);  //convert to int
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 8));
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 4));
                __m128 as_float = _mm_castsi128_ps(temp);
                return _mm_cvtss_f32(as_float);
            }
        };
    } // end of namespace functors for template specialization of hor for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1381
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<double, sse>, Idof> {
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
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::base_type apply(
                const typename Vec::register_type vec
            ) {
                __m128i temp = _mm_castpd_si128(vec);  //convert to int
                temp = _mm_or_si128(temp, _mm_srli_si128(temp, 8));
                __m128d as_double = _mm_castsi128_pd(temp);
                return _mm_cvtsd_f64(as_double);
            }
        };
    } // end of namespace functors for template specialization of hor for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1563
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type vec
            ) {
                Vec::register_type all_ones = _mm_set1_epi32(-1);
                return _mm_xor_si128(vec, all_ones);
            }
        };
    } // end of namespace functors for template specialization of inv for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1563
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type vec
            ) {
                Vec::register_type all_ones = _mm_set1_epi32(-1);
                return _mm_xor_si128(vec, all_ones);
            }
        };
    } // end of namespace functors for template specialization of inv for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1563
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type vec
            ) {
                Vec::register_type all_ones = _mm_set1_epi32(-1);
                return _mm_xor_si128(vec, all_ones);
            }
        };
    } // end of namespace functors for template specialization of inv for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1563
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type vec
            ) {
                Vec::register_type all_ones = _mm_set1_epi32(-1);
                return _mm_xor_si128(vec, all_ones);
            }
        };
    } // end of namespace functors for template specialization of inv for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1563
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type vec
            ) {
                Vec::register_type all_ones = _mm_set1_epi32(-1);
                return _mm_xor_si128(vec, all_ones);
            }
        };
    } // end of namespace functors for template specialization of inv for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1563
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type vec
            ) {
                Vec::register_type all_ones = _mm_set1_epi32(-1);
                return _mm_xor_si128(vec, all_ones);
            }
        };
    } // end of namespace functors for template specialization of inv for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1563
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type vec
            ) {
                Vec::register_type all_ones = _mm_set1_epi32(-1);
                return _mm_xor_si128(vec, all_ones);
            }
        };
    } // end of namespace functors for template specialization of inv for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1563
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type vec
            ) {
                Vec::register_type all_ones = _mm_set1_epi32(-1);
                return _mm_xor_si128(vec, all_ones);
            }
        };
    } // end of namespace functors for template specialization of inv for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1569
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type vec
            ) {
                __m128i all_ones = _mm_set1_epi32(-1);
                __m128i as_int = _mm_castps_si128(vec);
                return _mm_castsi128_ps(_mm_xor_si128(as_int, all_ones));
            }
        };
    } // end of namespace functors for template specialization of inv for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1569
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type vec
            ) {
                __m128i all_ones = _mm_set1_epi32(-1);
                __m128i as_int = _mm_castpd_si128(vec);
                return _mm_castsi128_pd(_mm_xor_si128(as_int, all_ones));
            }
        };
    } // end of namespace functors for template specialization of inv for sse using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_BINARY_BINARY_SSE_HPP