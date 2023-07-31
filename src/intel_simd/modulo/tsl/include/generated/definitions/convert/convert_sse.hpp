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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/convert/convert_sse.hpp
 * \date 2023-07-22
 * \brief Conversion primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_SSE_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_SSE_HPP

#include "../../declarations/convert.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::109
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, sse>, simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            using ToType = simd<int8_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::109
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, sse>, simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            using ToType = simd<uint8_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::109
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, sse>, simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            using ToType = simd<int16_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::109
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, sse>, simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            using ToType = simd<uint16_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::109
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, sse>, simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            using ToType = simd<int32_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::109
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, sse>, simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            using ToType = simd<uint32_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::109
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, sse>, simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            using ToType = simd<int64_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::109
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, sse>, simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            using ToType = simd<uint64_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::109
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, sse>, simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            using ToType = simd<float, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::109
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, sse>, simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            using ToType = simd<double, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, sse>, simd<float, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            using ToType = simd<float, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, sse>, simd<float, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            using ToType = simd<float, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, sse>, simd<float, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            using ToType = simd<float, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, sse>, simd<float, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            using ToType = simd<float, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, sse>, simd<float, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            using ToType = simd<float, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, sse>, simd<float, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            using ToType = simd<float, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, sse>, simd<float, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            using ToType = simd<float, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::114
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, sse>, simd<float, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            using ToType = simd<float, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::119
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, sse>, simd<int8_t, sse>, Idof> {
            using Vec = simd<float, sse>;
            using ToType = simd<int8_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castps_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::119
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, sse>, simd<uint8_t, sse>, Idof> {
            using Vec = simd<float, sse>;
            using ToType = simd<uint8_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castps_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::119
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, sse>, simd<int16_t, sse>, Idof> {
            using Vec = simd<float, sse>;
            using ToType = simd<int16_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castps_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::119
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, sse>, simd<uint16_t, sse>, Idof> {
            using Vec = simd<float, sse>;
            using ToType = simd<uint16_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castps_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::119
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, sse>, simd<int32_t, sse>, Idof> {
            using Vec = simd<float, sse>;
            using ToType = simd<int32_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castps_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::119
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, sse>, simd<uint32_t, sse>, Idof> {
            using Vec = simd<float, sse>;
            using ToType = simd<uint32_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castps_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::119
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, sse>, simd<int64_t, sse>, Idof> {
            using Vec = simd<float, sse>;
            using ToType = simd<int64_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castps_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::119
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, sse>, simd<uint64_t, sse>, Idof> {
            using Vec = simd<float, sse>;
            using ToType = simd<uint64_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castps_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::124
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, sse>, simd<double, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            using ToType = simd<double, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::124
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, sse>, simd<double, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            using ToType = simd<double, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::124
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, sse>, simd<double, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            using ToType = simd<double, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::124
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, sse>, simd<double, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            using ToType = simd<double, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::124
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, sse>, simd<double, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            using ToType = simd<double, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::124
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, sse>, simd<double, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            using ToType = simd<double, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::124
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, sse>, simd<double, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            using ToType = simd<double, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::124
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, sse>, simd<double, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            using ToType = simd<double, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castsi128_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::129
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, sse>, simd<int8_t, sse>, Idof> {
            using Vec = simd<double, sse>;
            using ToType = simd<int8_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castpd_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::129
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, sse>, simd<uint8_t, sse>, Idof> {
            using Vec = simd<double, sse>;
            using ToType = simd<uint8_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castpd_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::129
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, sse>, simd<int16_t, sse>, Idof> {
            using Vec = simd<double, sse>;
            using ToType = simd<int16_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castpd_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::129
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, sse>, simd<uint16_t, sse>, Idof> {
            using Vec = simd<double, sse>;
            using ToType = simd<uint16_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castpd_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::129
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, sse>, simd<int32_t, sse>, Idof> {
            using Vec = simd<double, sse>;
            using ToType = simd<int32_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castpd_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::129
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, sse>, simd<uint32_t, sse>, Idof> {
            using Vec = simd<double, sse>;
            using ToType = simd<uint32_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castpd_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::129
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, sse>, simd<int64_t, sse>, Idof> {
            using Vec = simd<double, sse>;
            using ToType = simd<int64_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castpd_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::129
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, sse>, simd<uint64_t, sse>, Idof> {
            using Vec = simd<double, sse>;
            using ToType = simd<uint64_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_castpd_si128(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::203
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int8_t, sse>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, sse>;
            using ToType = simd<int8_t, avx2>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                #if (defined(__GNUC__) && defined(__cplusplus) && (__GNUC__ < 10) && !defined(__clang__))
                return _mm256_inserti128_si256(_mm256_setzero_si256(), data, 0);
                #else
                return _mm256_zextsi128_si256(data);
                #endif
            }
        };
    } // end of namespace functors for template specialization of cast for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::203
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int16_t, sse>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, sse>;
            using ToType = simd<int16_t, avx2>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                #if (defined(__GNUC__) && defined(__cplusplus) && (__GNUC__ < 10) && !defined(__clang__))
                return _mm256_inserti128_si256(_mm256_setzero_si256(), data, 0);
                #else
                return _mm256_zextsi128_si256(data);
                #endif
            }
        };
    } // end of namespace functors for template specialization of cast for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::203
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int32_t, sse>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, sse>;
            using ToType = simd<int32_t, avx2>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                #if (defined(__GNUC__) && defined(__cplusplus) && (__GNUC__ < 10) && !defined(__clang__))
                return _mm256_inserti128_si256(_mm256_setzero_si256(), data, 0);
                #else
                return _mm256_zextsi128_si256(data);
                #endif
            }
        };
    } // end of namespace functors for template specialization of cast for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::203
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int64_t, sse>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, sse>;
            using ToType = simd<int64_t, avx2>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                #if (defined(__GNUC__) && defined(__cplusplus) && (__GNUC__ < 10) && !defined(__clang__))
                return _mm256_inserti128_si256(_mm256_setzero_si256(), data, 0);
                #else
                return _mm256_zextsi128_si256(data);
                #endif
            }
        };
    } // end of namespace functors for template specialization of cast for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::203
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint8_t, sse>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, sse>;
            using ToType = simd<uint8_t, avx2>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                #if (defined(__GNUC__) && defined(__cplusplus) && (__GNUC__ < 10) && !defined(__clang__))
                return _mm256_inserti128_si256(_mm256_setzero_si256(), data, 0);
                #else
                return _mm256_zextsi128_si256(data);
                #endif
            }
        };
    } // end of namespace functors for template specialization of cast for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::203
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint16_t, sse>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, sse>;
            using ToType = simd<uint16_t, avx2>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                #if (defined(__GNUC__) && defined(__cplusplus) && (__GNUC__ < 10) && !defined(__clang__))
                return _mm256_inserti128_si256(_mm256_setzero_si256(), data, 0);
                #else
                return _mm256_zextsi128_si256(data);
                #endif
            }
        };
    } // end of namespace functors for template specialization of cast for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::203
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint32_t, sse>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, sse>;
            using ToType = simd<uint32_t, avx2>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                #if (defined(__GNUC__) && defined(__cplusplus) && (__GNUC__ < 10) && !defined(__clang__))
                return _mm256_inserti128_si256(_mm256_setzero_si256(), data, 0);
                #else
                return _mm256_zextsi128_si256(data);
                #endif
            }
        };
    } // end of namespace functors for template specialization of cast for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::203
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint64_t, sse>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, sse>;
            using ToType = simd<uint64_t, avx2>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                #if (defined(__GNUC__) && defined(__cplusplus) && (__GNUC__ < 10) && !defined(__clang__))
                return _mm256_inserti128_si256(_mm256_setzero_si256(), data, 0);
                #else
                return _mm256_zextsi128_si256(data);
                #endif
            }
        };
    } // end of namespace functors for template specialization of cast for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse4_1', 'sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::317
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<float, sse>, simd<int32_t, sse>, Idof> {
            using Vec = simd<float, sse>;
            using ToType = simd<int32_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_cvtps_epi32(_mm_round_ps(data, _MM_FROUND_TO_ZERO));
            }
        };
    } // end of namespace functors for template specialization of cast for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse4_1', 'sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::317
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<float, sse>, simd<uint32_t, sse>, Idof> {
            using Vec = simd<float, sse>;
            using ToType = simd<uint32_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_cvtps_epi32(_mm_round_ps(data, _MM_FROUND_TO_ZERO));
            }
        };
    } // end of namespace functors for template specialization of cast for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse4_1', 'sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::322
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<double, sse>, simd<int64_t, sse>, Idof> {
            using Vec = simd<double, sse>;
            using ToType = simd<int64_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                __m128i temp = _mm_cvtps_epi32(_mm_round_ps(_mm_cvtpd_ps(_mm_round_pd(data, _MM_FROUND_TO_ZERO)), _MM_FROUND_TO_ZERO));
                return _mm_cvtepi32_epi64(temp);
            }
        };
    } // end of namespace functors for template specialization of cast for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse4_1', 'sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::322
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<double, sse>, simd<uint64_t, sse>, Idof> {
            using Vec = simd<double, sse>;
            using ToType = simd<uint64_t, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                __m128i temp = _mm_cvtps_epi32(_mm_round_ps(_mm_cvtpd_ps(_mm_round_pd(data, _MM_FROUND_TO_ZERO)), _MM_FROUND_TO_ZERO));
                return _mm_cvtepi32_epi64(temp);
            }
        };
    } // end of namespace functors for template specialization of cast for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::407
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int32_t, sse>, simd<float, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            using ToType = simd<float, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                return _mm_cvtepi32_ps(data);
            }
        };
    } // end of namespace functors for template specialization of cast for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::412
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint32_t, sse>, simd<float, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            using ToType = simd<float, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                __m128 temp = _mm_cvtepi32_ps(data);

                __m128i mask = _mm_srai_epi32(data, 31);
                __m128 correction = _mm_castsi128_ps(_mm_and_si128(mask, _mm_set1_epi32((int)0x4f800000)));

                return _mm_add_ps(temp, correction);
            }
        };
    } // end of namespace functors for template specialization of cast for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/convert.yaml::423
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int64_t, sse>, simd<double, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            using ToType = simd<double, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                // https://stackoverflow.com/a/41148578
                __m128i xH = _mm_srai_epi32(data, 16);
                xH = _mm_blend_epi16(xH, _mm_setzero_si128(), 0x33);
                xH = _mm_add_epi64(xH, _mm_castpd_si128(_mm_set1_pd(442721857769029238784.)));                //  3*2^67
                __m128i xL = _mm_blend_epi16(data, _mm_castpd_si128(_mm_set1_pd(0x0010000000000000)), 0x88);  //  2^52
                __m128d f = _mm_sub_pd(_mm_castsi128_pd(xH), _mm_set1_pd(442726361368656609280.));            //  3*2^67 + 2^52
                return _mm_add_pd(f, _mm_castsi128_pd(xL));
            }
        };
    } // end of namespace functors for template specialization of cast for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2', 'sse4_1']
         *      Yaml Source: primitive_data/primitives/convert.yaml::435
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint64_t, sse>, simd<double, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            using ToType = simd<double, sse>;
            using return_type = typename ToType::register_type;
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
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                // https://stackoverflow.com/a/41148578
                __m128i xH = _mm_srli_epi64(data, 32);
                xH = _mm_or_si128(xH, _mm_castpd_si128(_mm_set1_pd(19342813113834066795298816.)));            //  2^84
                __m128i xL = _mm_blend_epi16(data, _mm_castpd_si128(_mm_set1_pd(0x0010000000000000)), 0xcc);  //  2^52
                __m128d f = _mm_sub_pd(_mm_castsi128_pd(xH), _mm_set1_pd(19342813118337666422669312.));       //  2^84 + 2^52
                return _mm_add_pd(f, _mm_castsi128_pd(xL));
            }
        };
    } // end of namespace functors for template specialization of cast for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::793
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int8_t, sse>, simd<int32_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            using ToType = simd<int32_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                return { {
                  _mm_cvtepi8_epi32(data),
                  _mm_cvtepi8_epi32(_mm_bsrli_si128(data,4)),
                  _mm_cvtepi8_epi32(_mm_bsrli_si128(data,8)),
                  _mm_cvtepi8_epi32(_mm_bsrli_si128(data,12))
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::805
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint8_t, sse>, simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            using ToType = simd<uint32_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi32(0xff);
                return { {
                  _mm_and_si128(_mm_cvtepi8_epi32(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi8_epi32(_mm_bsrli_si128(data,4)), upper_zero),
                  _mm_and_si128(_mm_cvtepi8_epi32(_mm_bsrli_si128(data,8)), upper_zero),
                  _mm_and_si128(_mm_cvtepi8_epi32(_mm_bsrli_si128(data,12)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::805
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint8_t, sse>, simd<int32_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            using ToType = simd<int32_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi32(0xff);
                return { {
                  _mm_and_si128(_mm_cvtepi8_epi32(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi8_epi32(_mm_bsrli_si128(data,4)), upper_zero),
                  _mm_and_si128(_mm_cvtepi8_epi32(_mm_bsrli_si128(data,8)), upper_zero),
                  _mm_and_si128(_mm_cvtepi8_epi32(_mm_bsrli_si128(data,12)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::805
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int8_t, sse>, simd<uint32_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            using ToType = simd<uint32_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi32(0xff);
                return { {
                  _mm_and_si128(_mm_cvtepi8_epi32(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi8_epi32(_mm_bsrli_si128(data,4)), upper_zero),
                  _mm_and_si128(_mm_cvtepi8_epi32(_mm_bsrli_si128(data,8)), upper_zero),
                  _mm_and_si128(_mm_cvtepi8_epi32(_mm_bsrli_si128(data,12)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::818
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int8_t, sse>, simd<int64_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            using ToType = simd<int64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                return { {
                  _mm_cvtepi8_epi64(data),
                  _mm_cvtepi8_epi64(_mm_bsrli_si128(data,2)),
                  _mm_cvtepi8_epi64(_mm_bsrli_si128(data,4)),
                  _mm_cvtepi8_epi64(_mm_bsrli_si128(data,6)),
                  _mm_cvtepi8_epi64(_mm_bsrli_si128(data,8)),
                  _mm_cvtepi8_epi64(_mm_bsrli_si128(data,10)),
                  _mm_cvtepi8_epi64(_mm_bsrli_si128(data,12)),
                  _mm_cvtepi8_epi64(_mm_bsrli_si128(data,14)),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::834
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint8_t, sse>, simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            using ToType = simd<uint64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi64x(0xff);
                return { {
                _mm_and_si128(_mm_cvtepi8_epi64(data), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,2)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,4)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,6)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,8)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,10)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,12)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,14)), upper_zero),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::834
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint8_t, sse>, simd<int64_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            using ToType = simd<int64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi64x(0xff);
                return { {
                _mm_and_si128(_mm_cvtepi8_epi64(data), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,2)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,4)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,6)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,8)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,10)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,12)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,14)), upper_zero),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::834
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int8_t, sse>, simd<uint64_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            using ToType = simd<uint64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi64x(0xff);
                return { {
                _mm_and_si128(_mm_cvtepi8_epi64(data), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,2)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,4)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,6)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,8)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,10)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,12)), upper_zero),
                _mm_and_si128(_mm_cvtepi8_epi64(_mm_bsrli_si128(data,14)), upper_zero),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::851
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int16_t, sse>, simd<int32_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            using ToType = simd<int32_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                return { {
                  _mm_cvtepi16_epi32(data),
                  _mm_cvtepi16_epi32(_mm_bsrli_si128(data,8))
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::861
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint16_t, sse>, simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            using ToType = simd<uint32_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi32(0xffff);
                return { {
                  _mm_and_si128(_mm_cvtepi16_epi32(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi32(_mm_bsrli_si128(data,8)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::861
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint16_t, sse>, simd<int32_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            using ToType = simd<int32_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi32(0xffff);
                return { {
                  _mm_and_si128(_mm_cvtepi16_epi32(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi32(_mm_bsrli_si128(data,8)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::861
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int16_t, sse>, simd<uint32_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            using ToType = simd<uint32_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi32(0xffff);
                return { {
                  _mm_and_si128(_mm_cvtepi16_epi32(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi32(_mm_bsrli_si128(data,8)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::872
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int16_t, sse>, simd<int64_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            using ToType = simd<int64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                return { {
                  _mm_cvtepi16_epi64(data),
                  _mm_cvtepi16_epi64(_mm_bsrli_si128(data,4)),
                  _mm_cvtepi16_epi64(_mm_bsrli_si128(data,8)),
                  _mm_cvtepi16_epi64(_mm_bsrli_si128(data,12))
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::884
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint16_t, sse>, simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            using ToType = simd<uint64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi64x(0xffff);
                return { {
                  _mm_and_si128(_mm_cvtepi16_epi64(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi64(_mm_bsrli_si128(data,4)), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi64(_mm_bsrli_si128(data,8)), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi64(_mm_bsrli_si128(data,12)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::884
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint16_t, sse>, simd<int64_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            using ToType = simd<int64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi64x(0xffff);
                return { {
                  _mm_and_si128(_mm_cvtepi16_epi64(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi64(_mm_bsrli_si128(data,4)), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi64(_mm_bsrli_si128(data,8)), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi64(_mm_bsrli_si128(data,12)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::884
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int16_t, sse>, simd<uint64_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            using ToType = simd<uint64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi64x(0xffff);
                return { {
                  _mm_and_si128(_mm_cvtepi16_epi64(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi64(_mm_bsrli_si128(data,4)), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi64(_mm_bsrli_si128(data,8)), upper_zero),
                  _mm_and_si128(_mm_cvtepi16_epi64(_mm_bsrli_si128(data,12)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::897
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int32_t, sse>, simd<int64_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            using ToType = simd<int64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                return { {
                  _mm_cvtepi32_epi64(data),
                  _mm_cvtepi32_epi64(_mm_bsrli_si128(data,8))
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::907
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint32_t, sse>, simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            using ToType = simd<uint64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi64x(0xffffffff);
                return { {
                  _mm_and_si128(_mm_cvtepi32_epi64(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi32_epi64(_mm_bsrli_si128(data,8)), upper_zero),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::907
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint32_t, sse>, simd<int64_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            using ToType = simd<int64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi64x(0xffffffff);
                return { {
                  _mm_and_si128(_mm_cvtepi32_epi64(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi32_epi64(_mm_bsrli_si128(data,8)), upper_zero),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse4_2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::907
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int32_t, sse>, simd<uint64_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            using ToType = simd<uint64_t, sse>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_up is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm_set1_epi64x(0xffffffff);
                return { {
                  _mm_and_si128(_mm_cvtepi32_epi64(data), upper_zero),
                  _mm_and_si128(_mm_cvtepi32_epi64(_mm_bsrli_si128(data,8)), upper_zero),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for sse using int32_t.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_SSE_HPP