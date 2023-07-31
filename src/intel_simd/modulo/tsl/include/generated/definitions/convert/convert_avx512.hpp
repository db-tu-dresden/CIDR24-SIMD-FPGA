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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/convert/convert_avx512.hpp
 * \date 2023-07-22
 * \brief Conversion primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_AVX512_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_AVX512_HPP

#include "../../declarations/convert.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::17
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx512>, simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            using ToType = simd<int8_t, avx512>;
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
    } // end of namespace functors for template specialization of reinterpret for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::17
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx512>, simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            using ToType = simd<uint8_t, avx512>;
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
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::17
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx512>, simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            using ToType = simd<int16_t, avx512>;
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
    } // end of namespace functors for template specialization of reinterpret for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::17
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx512>, simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            using ToType = simd<uint16_t, avx512>;
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
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::17
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx512>, simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            using ToType = simd<int32_t, avx512>;
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
    } // end of namespace functors for template specialization of reinterpret for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::17
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx512>, simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            using ToType = simd<uint32_t, avx512>;
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
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::17
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx512>, simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            using ToType = simd<int64_t, avx512>;
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
    } // end of namespace functors for template specialization of reinterpret for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::17
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx512>, simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            using ToType = simd<uint64_t, avx512>;
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
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::17
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx512>, simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            using ToType = simd<float, avx512>;
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
    } // end of namespace functors for template specialization of reinterpret for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::17
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx512>, simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<double, avx512>;
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
    } // end of namespace functors for template specialization of reinterpret for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx512>, simd<float, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            using ToType = simd<float, avx512>;
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
                return _mm512_castsi512_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx512>, simd<float, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            using ToType = simd<float, avx512>;
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
                return _mm512_castsi512_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx512>, simd<float, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            using ToType = simd<float, avx512>;
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
                return _mm512_castsi512_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx512>, simd<float, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            using ToType = simd<float, avx512>;
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
                return _mm512_castsi512_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx512>, simd<float, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            using ToType = simd<float, avx512>;
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
                return _mm512_castsi512_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx512>, simd<float, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            using ToType = simd<float, avx512>;
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
                return _mm512_castsi512_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx512>, simd<float, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            using ToType = simd<float, avx512>;
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
                return _mm512_castsi512_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx512>, simd<float, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            using ToType = simd<float, avx512>;
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
                return _mm512_castsi512_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::27
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx512>, simd<int8_t, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            using ToType = simd<int8_t, avx512>;
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
                return _mm512_castps_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::27
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx512>, simd<uint8_t, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            using ToType = simd<uint8_t, avx512>;
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
                return _mm512_castps_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::27
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx512>, simd<int16_t, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            using ToType = simd<int16_t, avx512>;
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
                return _mm512_castps_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::27
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx512>, simd<uint16_t, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            using ToType = simd<uint16_t, avx512>;
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
                return _mm512_castps_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::27
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx512>, simd<int32_t, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            using ToType = simd<int32_t, avx512>;
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
                return _mm512_castps_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::27
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx512>, simd<uint32_t, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            using ToType = simd<uint32_t, avx512>;
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
                return _mm512_castps_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::27
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx512>, simd<int64_t, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            using ToType = simd<int64_t, avx512>;
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
                return _mm512_castps_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::27
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx512>, simd<uint64_t, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            using ToType = simd<uint64_t, avx512>;
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
                return _mm512_castps_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::32
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx512>, simd<double, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            using ToType = simd<double, avx512>;
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
                return _mm512_castsi512_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::32
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx512>, simd<double, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            using ToType = simd<double, avx512>;
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
                return _mm512_castsi512_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::32
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx512>, simd<double, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            using ToType = simd<double, avx512>;
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
                return _mm512_castsi512_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::32
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx512>, simd<double, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            using ToType = simd<double, avx512>;
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
                return _mm512_castsi512_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::32
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx512>, simd<double, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            using ToType = simd<double, avx512>;
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
                return _mm512_castsi512_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::32
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx512>, simd<double, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            using ToType = simd<double, avx512>;
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
                return _mm512_castsi512_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::32
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx512>, simd<double, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            using ToType = simd<double, avx512>;
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
                return _mm512_castsi512_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::32
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx512>, simd<double, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            using ToType = simd<double, avx512>;
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
                return _mm512_castsi512_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::37
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx512>, simd<int8_t, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<int8_t, avx512>;
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
                return _mm512_castpd_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::37
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx512>, simd<uint8_t, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<uint8_t, avx512>;
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
                return _mm512_castpd_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::37
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx512>, simd<int16_t, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<int16_t, avx512>;
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
                return _mm512_castpd_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::37
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx512>, simd<uint16_t, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<uint16_t, avx512>;
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
                return _mm512_castpd_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::37
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx512>, simd<int32_t, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<int32_t, avx512>;
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
                return _mm512_castpd_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::37
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx512>, simd<uint32_t, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<uint32_t, avx512>;
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
                return _mm512_castpd_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::37
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx512>, simd<int64_t, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<int64_t, avx512>;
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
                return _mm512_castpd_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::37
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx512>, simd<uint64_t, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<uint64_t, avx512>;
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
                return _mm512_castpd_si512(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::246
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<double, avx512>, simd<float, avx2>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<float, avx2>;
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
                return _mm512_cvtpd_ps(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::246
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int16_t, avx512>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx512>;
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
                return _mm512_cvtepi16_epi8(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::246
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int32_t, avx512>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx512>;
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
                return _mm512_cvtepi32_epi16(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::246
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int64_t, avx512>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx512>;
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
                return _mm512_cvtepi64_epi32(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::246
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint16_t, avx512>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx512>;
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
                return _mm512_cvtepi16_epi8(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::246
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint32_t, avx512>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx512>;
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
                return _mm512_cvtepi32_epi16(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::246
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint64_t, avx512>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx512>;
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
                return _mm512_cvtepi64_epi32(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::266
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int32_t, avx512>, simd<int8_t, sse>, Idof> {
            using Vec = simd<int32_t, avx512>;
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
                return _mm512_cvtepi32_epi8(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::266
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint32_t, avx512>, simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint32_t, avx512>;
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
                return _mm512_cvtepi32_epi8(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::266
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int64_t, avx512>, simd<int16_t, sse>, Idof> {
            using Vec = simd<int64_t, avx512>;
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
                return _mm512_cvtepi64_epi16(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::266
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int64_t, avx512>, simd<int8_t, sse>, Idof> {
            using Vec = simd<int64_t, avx512>;
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
                return _mm512_cvtepi64_epi8(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::266
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint64_t, avx512>, simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint64_t, avx512>;
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
                return _mm512_cvtepi64_epi16(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::266
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint64_t, avx512>, simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint64_t, avx512>;
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
                return _mm512_cvtepi64_epi8(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::283
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<float, avx512>, simd<int32_t, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            using ToType = simd<int32_t, avx512>;
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
                return _mm512_cvtps_epi32(_mm512_roundscale_ps(data, _MM_FROUND_TO_ZERO));
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::288
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<float, avx512>, simd<uint32_t, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            using ToType = simd<uint32_t, avx512>;
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
                return _mm512_cvtps_epu32(_mm512_roundscale_ps(data, _MM_FROUND_TO_ZERO));
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512dq', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::293
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<double, avx512>, simd<int64_t, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<int64_t, avx512>;
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
                return _mm512_cvtpd_epi64(_mm512_roundscale_pd(data, _MM_FROUND_TO_ZERO));
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512dq', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::298
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<double, avx512>, simd<uint64_t, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            using ToType = simd<uint64_t, avx512>;
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
                return  _mm512_cvtpd_epu64(_mm512_roundscale_pd(data, _MM_FROUND_TO_ZERO));
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::344
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint32_t, avx512>, simd<float, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            using ToType = simd<float, avx512>;
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
                return _mm512_cvtepu32_ps(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::344
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int32_t, avx512>, simd<float, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            using ToType = simd<float, avx512>;
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
                return _mm512_cvtepi32_ps(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512dq']
         *      Yaml Source: primitive_data/primitives/convert.yaml::349
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint64_t, avx512>, simd<double, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            using ToType = simd<double, avx512>;
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
                return _mm512_cvtepu64_pd(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512dq']
         *      Yaml Source: primitive_data/primitives/convert.yaml::349
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int64_t, avx512>, simd<double, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            using ToType = simd<double, avx512>;
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
                return _mm512_cvtepi64_pd(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "split" (primitive split).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2', 'avx512dq']
         *      Yaml Source: primitive_data/primitives/convert.yaml::475
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct split<simd<int32_t, avx512>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx512>;
            using ToType = simd<int64_t, avx2>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type) * Vec::vector_element_count() / ToType::vector_element_count()>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type) * Vec::vector_element_count() / ToType::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive split is not supported by your hardware natively while it is forced by using native" );

                return { {
                    _mm512_extracti32x8_epi32(data, 0),
                    _mm512_extracti32x8_epi32(data, 1),
                } };
            }
        };
    } // end of namespace functors for template specialization of split for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "split" (primitive split).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2', 'avx512dq']
         *      Yaml Source: primitive_data/primitives/convert.yaml::475
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct split<simd<uint32_t, avx512>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            using ToType = simd<uint64_t, avx2>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type) * Vec::vector_element_count() / ToType::vector_element_count()>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type) * Vec::vector_element_count() / ToType::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive split is not supported by your hardware natively while it is forced by using native" );

                return { {
                    _mm512_extracti32x8_epi32(data, 0),
                    _mm512_extracti32x8_epi32(data, 1),
                } };
            }
        };
    } // end of namespace functors for template specialization of split for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "split" (primitive split).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2', 'avx512dq']
         *      Yaml Source: primitive_data/primitives/convert.yaml::487
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct split<simd<int32_t, avx512>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx512>;
            using ToType = simd<int32_t, avx2>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type) * Vec::vector_element_count() / ToType::vector_element_count()>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type) * Vec::vector_element_count() / ToType::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive split is not supported by your hardware natively while it is forced by using native" );

                return { {
                    _mm512_extracti32x8_epi32(data, 0),
                    _mm512_extracti32x8_epi32(data, 1),
                } };
            }
        };
    } // end of namespace functors for template specialization of split for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "split" (primitive split).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2', 'avx512dq']
         *      Yaml Source: primitive_data/primitives/convert.yaml::487
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct split<simd<uint32_t, avx512>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            using ToType = simd<uint32_t, avx2>;
            using return_type = std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type) * Vec::vector_element_count() / ToType::vector_element_count()>;
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
            static std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type) * Vec::vector_element_count() / ToType::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive split is not supported by your hardware natively while it is forced by using native" );

                return { {
                    _mm512_extracti32x8_epi32(data, 0),
                    _mm512_extracti32x8_epi32(data, 1),
                } };
            }
        };
    } // end of namespace functors for template specialization of split for avx512 using uint32_t.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_AVX512_HPP