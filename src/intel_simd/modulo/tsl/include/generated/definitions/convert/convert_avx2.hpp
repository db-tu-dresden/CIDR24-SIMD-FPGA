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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/convert/convert_avx2.hpp
 * \date 2023-07-22
 * \brief Conversion primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_AVX2_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_AVX2_HPP

#include "../../declarations/convert.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx2>, simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx2>, simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            using ToType = simd<double, avx2>;
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
    } // end of namespace functors for template specialization of reinterpret for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::53
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::53
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::53
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::53
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::53
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::53
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::53
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::58
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::58
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::58
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::58
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::58
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::58
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::58
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::63
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::63
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::63
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::63
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::63
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::63
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::63
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::68
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::68
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::68
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::68
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::68
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::68
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::68
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::73
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::73
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::73
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::73
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::73
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::73
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::73
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::78
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::78
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::78
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::78
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::78
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::78
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::78
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::83
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::83
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::83
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::83
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::83
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::83
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::83
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
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
                return data;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::88
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx2>, simd<float, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
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
                return _mm256_castsi256_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::88
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx2>, simd<float, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
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
                return _mm256_castsi256_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::88
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx2>, simd<float, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
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
                return _mm256_castsi256_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::88
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx2>, simd<float, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
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
                return _mm256_castsi256_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::88
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx2>, simd<float, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
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
                return _mm256_castsi256_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::88
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx2>, simd<float, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                return _mm256_castsi256_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::88
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx2>, simd<float, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
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
                return _mm256_castsi256_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::88
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx2>, simd<float, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
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
                return _mm256_castsi256_ps(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::93
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<float, avx2>;
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
                return _mm256_castps_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::93
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<float, avx2>;
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
                return _mm256_castps_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::93
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<float, avx2>;
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
                return _mm256_castps_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::93
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<float, avx2>;
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
                return _mm256_castps_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::93
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<float, avx2>;
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
                return _mm256_castps_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::93
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<float, avx2>;
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
                return _mm256_castps_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::93
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<float, avx2>;
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
                return _mm256_castps_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::93
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<float, avx2>;
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
                return _mm256_castps_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::98
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, avx2>, simd<double, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            using ToType = simd<double, avx2>;
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
                return _mm256_castsi256_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::98
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, avx2>, simd<double, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            using ToType = simd<double, avx2>;
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
                return _mm256_castsi256_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::98
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, avx2>, simd<double, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            using ToType = simd<double, avx2>;
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
                return _mm256_castsi256_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::98
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, avx2>, simd<double, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            using ToType = simd<double, avx2>;
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
                return _mm256_castsi256_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::98
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, avx2>, simd<double, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            using ToType = simd<double, avx2>;
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
                return _mm256_castsi256_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::98
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, avx2>, simd<double, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            using ToType = simd<double, avx2>;
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
                return _mm256_castsi256_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::98
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, avx2>, simd<double, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            using ToType = simd<double, avx2>;
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
                return _mm256_castsi256_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::98
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, avx2>, simd<double, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            using ToType = simd<double, avx2>;
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
                return _mm256_castsi256_pd(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::103
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<double, avx2>;
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
                return _mm256_castpd_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::103
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<double, avx2>;
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
                return _mm256_castpd_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::103
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<double, avx2>;
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
                return _mm256_castpd_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::103
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<double, avx2>;
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
                return _mm256_castpd_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::103
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<double, avx2>;
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
                return _mm256_castpd_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::103
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<double, avx2>;
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
                return _mm256_castpd_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::103
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<double, avx2>;
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
                return _mm256_castpd_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::103
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<double, avx2>;
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
                return _mm256_castpd_si256(data);
            }
        };
    } // end of namespace functors for template specialization of reinterpret for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<float, avx2>, simd<double, avx512>, Idof> {
            using Vec = simd<float, avx2>;
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
                return _mm512_cvtps_pd(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int8_t, avx2>, simd<int16_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx2>;
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
                return _mm512_cvtepi8_epi16(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int16_t, avx2>, simd<int32_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx2>;
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
                return _mm512_cvtepi16_epi32(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int32_t, avx2>, simd<int64_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx2>;
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
                return _mm512_cvtepi32_epi64(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint8_t, avx2>, simd<int16_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx2>;
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
                return _mm512_cvtepu8_epi16(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint8_t, avx2>, simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx2>;
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
                return _mm512_cvtepu8_epi16(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint16_t, avx2>, simd<int32_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx2>;
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
                return _mm512_cvtepu16_epi32(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint16_t, avx2>, simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx2>;
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
                return _mm512_cvtepu16_epi32(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint32_t, avx2>, simd<int64_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                return _mm512_cvtepu32_epi64(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::228
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint32_t, avx2>, simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                return _mm512_cvtepu32_epi64(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::304
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<float, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<float, avx2>;
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
                return _mm256_cvtps_epi32(_mm256_round_ps(data, _MM_FROUND_TO_ZERO));
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::304
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<float, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<float, avx2>;
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
                return _mm256_cvtps_epi32(_mm256_round_ps(data, _MM_FROUND_TO_ZERO));
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2', 'sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::309
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<double, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<double, avx2>;
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
                __m128i temp = _mm_cvtps_epi32(_mm_round_ps(_mm256_cvtpd_ps(_mm256_round_pd(data, _MM_FROUND_TO_ZERO)), _MM_FROUND_TO_ZERO));
                return _mm256_cvtepi32_epi64(temp);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2', 'sse']
         *      Yaml Source: primitive_data/primitives/convert.yaml::309
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<double, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<double, avx2>;
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
                __m128i temp = _mm_cvtps_epi32(_mm_round_ps(_mm256_cvtpd_ps(_mm256_round_pd(data, _MM_FROUND_TO_ZERO)), _MM_FROUND_TO_ZERO));
                return _mm256_cvtepi32_epi64(temp);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/convert.yaml::355
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int32_t, avx2>, simd<float, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
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
                return _mm256_cvtepi32_ps(data);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx', 'avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::360
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint32_t, avx2>, simd<float, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
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
                __m256 output = _mm256_cvtepi32_ps(data);

                __m256i mask = _mm256_srai_epi32(data, 31);
                __m256 correction = _mm256_castsi256_ps(_mm256_and_si256(mask, _mm256_set1_epi32((int)0x4f800000)));

                return _mm256_add_ps(output, correction);
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx', 'avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::371
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int64_t, avx2>, simd<double, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            using ToType = simd<double, avx2>;
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
                // https://stackoverflow.com/a/41223013
                __m256i magic_i_lo   = _mm256_set1_epi64x(0x4330000000000000);                /* 2^52               encoded as floating-point  */
                __m256i magic_i_hi32 = _mm256_set1_epi64x(0x4530000080000000);                /* 2^84 + 2^63        encoded as floating-point  */
                __m256i magic_i_all  = _mm256_set1_epi64x(0x4530000080100000);                /* 2^84 + 2^63 + 2^52 encoded as floating-point  */
                __m256d magic_d_all  = _mm256_castsi256_pd(magic_i_all);

                __m256i v_lo         = _mm256_blend_epi32(magic_i_lo, data, 0b01010101);      /* Blend the 32 lowest significant bits of v with magic_int_lo                            */
                __m256i v_hi         = _mm256_srli_epi64(data, 32);                           /* Extract the 32 most significant bits of v                                              */
                        v_hi         = _mm256_xor_si256(v_hi, magic_i_hi32);                  /* Flip the msb of v_hi and blend with 0x45300000                                         */
                __m256d v_hi_dbl     = _mm256_sub_pd(_mm256_castsi256_pd(v_hi), magic_d_all); /* Compute in double precision:                                                           */
                return _mm256_add_pd(v_hi_dbl, _mm256_castsi256_pd(v_lo));                    /* (v_hi - magic_d_all) + v_lo  Do not assume associativity of floating point addition !! */
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx', 'avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::388
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint64_t, avx2>, simd<double, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            using ToType = simd<double, avx2>;
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
                // https://stackoverflow.com/a/41223013
                __m256i magic_i_lo   = _mm256_set1_epi64x(0x4330000000000000);                /* 2^52        encoded as floating-point  */
                __m256i magic_i_hi32 = _mm256_set1_epi64x(0x4530000000000000);                /* 2^84        encoded as floating-point  */
                __m256i magic_i_all  = _mm256_set1_epi64x(0x4530000000100000);                /* 2^84 + 2^52 encoded as floating-point  */
                __m256d magic_d_all  = _mm256_castsi256_pd(magic_i_all);

                __m256i v_lo         = _mm256_blend_epi32(magic_i_lo, data, 0b01010101);      /* Blend the 32 lowest significant bits of v with magic_int_lo                                                   */
                __m256i v_hi         = _mm256_srli_epi64(data, 32);                           /* Extract the 32 most significant bits of v                                                                     */
                        v_hi         = _mm256_xor_si256(v_hi, magic_i_hi32);                  /* Blend v_hi with 0x45300000                                                                                    */
                __m256d v_hi_dbl     = _mm256_sub_pd(_mm256_castsi256_pd(v_hi), magic_d_all); /* Compute in double precision:                                                                                  */
                __m256d result       = _mm256_add_pd(v_hi_dbl, _mm256_castsi256_pd(v_lo));    /* (v_hi - magic_d_all) + v_lo  Do not assume associativity of floating point addition !!                        */
                return result;
            }
        };
    } // end of namespace functors for template specialization of cast for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "merge" (primitive merge).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::512
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct merge<simd<int32_t, avx2>, simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx2>;
            using ToType = simd<int32_t, avx512>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type) * ToType::vector_element_count() / Vec::vector_element_count()>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type) * ToType::vector_element_count() / Vec::vector_element_count()> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive merge is not supported by your hardware natively while it is forced by using native" );

                __m512i result;
                result = _mm512_inserti32x8(result, data[0], 0);
                result = _mm512_inserti32x8(result, data[1], 0);
                return result;
            }
        };
    } // end of namespace functors for template specialization of merge for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "merge" (primitive merge).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2', 'avx512f']
         *      Yaml Source: primitive_data/primitives/convert.yaml::512
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct merge<simd<uint32_t, avx2>, simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            using ToType = simd<uint32_t, avx512>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type) * ToType::vector_element_count() / Vec::vector_element_count()>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type) * ToType::vector_element_count() / Vec::vector_element_count()> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive merge is not supported by your hardware natively while it is forced by using native" );

                __m512i result;
                result = _mm512_inserti32x8(result, data[0], 0);
                result = _mm512_inserti32x8(result, data[1], 0);
                return result;
            }
        };
    } // end of namespace functors for template specialization of merge for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::596
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int8_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            using ToType = simd<int32_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                return { {
                  _mm256_cvtepi8_epi32(b),
                  _mm256_cvtepi8_epi32(_mm_bsrli_si128(b,8)),
                  _mm256_cvtepi8_epi32(c),
                  _mm256_cvtepi8_epi32(_mm_bsrli_si128(c,8))
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::610
         * @note: int to uint is unsafe... we should delete this
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint8_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            using ToType = simd<uint32_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi32(0xff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi8_epi32(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi32(_mm_bsrli_si128(b,8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi32(c), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi32(_mm_bsrli_si128(c,8)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::610
         * @note: int to uint is unsafe... we should delete this
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint8_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            using ToType = simd<int32_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi32(0xff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi8_epi32(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi32(_mm_bsrli_si128(b,8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi32(c), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi32(_mm_bsrli_si128(c,8)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::610
         * @note: int to uint is unsafe... we should delete this
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int8_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            using ToType = simd<uint32_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi32(0xff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi8_epi32(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi32(_mm_bsrli_si128(b,8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi32(c), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi32(_mm_bsrli_si128(c,8)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::626
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int8_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            using ToType = simd<int64_t, avx2>;
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

                auto const x = _mm256_extracti128_si256(data, 0);
                auto const y = _mm256_extracti128_si256(data, 1);
                return { {
                  _mm256_cvtepi8_epi64(x),
                  _mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 4)),
                  _mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 8)),
                  _mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 12)),
                  _mm256_cvtepi8_epi64(y),
                  _mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 4)),
                  _mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 8)),
                  _mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 12))
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::675
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint8_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            using ToType = simd<uint64_t, avx2>;
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

                auto const x = _mm256_extracti128_si256(data, 0);
                auto const y = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi64x(0xff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi8_epi64(x), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 4)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 12)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(y), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 4)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 12)), upper_zero),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::675
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint8_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            using ToType = simd<int64_t, avx2>;
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

                auto const x = _mm256_extracti128_si256(data, 0);
                auto const y = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi64x(0xff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi8_epi64(x), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 4)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 12)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(y), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 4)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 12)), upper_zero),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::675
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int8_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            using ToType = simd<uint64_t, avx2>;
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

                auto const x = _mm256_extracti128_si256(data, 0);
                auto const y = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi64x(0xff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi8_epi64(x), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 4)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(x, 12)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(y), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 4)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi8_epi64(_mm_bsrli_si128(y, 12)), upper_zero),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::694
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int16_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            using ToType = simd<int32_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                return { {
                    _mm256_cvtepi16_epi32(b),
                    _mm256_cvtepi16_epi32(c)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::706
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint16_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            using ToType = simd<uint32_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi32(0xffff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi16_epi32(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi32(c), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::706
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint16_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            using ToType = simd<int32_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi32(0xffff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi16_epi32(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi32(c), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::706
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int16_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            using ToType = simd<uint32_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi32(0xffff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi16_epi32(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi32(c), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::719
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int16_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            using ToType = simd<int64_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                return { {
                  _mm256_cvtepi16_epi64(b),
                  _mm256_cvtepi16_epi64(_mm_bsrli_si128(b,8)),
                  _mm256_cvtepi16_epi64(c),
                  _mm256_cvtepi16_epi64(_mm_bsrli_si128(c,8)),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::733
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint16_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            using ToType = simd<uint64_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi64x(0xffff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi16_epi64(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi64(_mm_bsrli_si128(b,8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi64(c), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi64(_mm_bsrli_si128(c,8)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::733
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint16_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            using ToType = simd<int64_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi64x(0xffff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi16_epi64(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi64(_mm_bsrli_si128(b,8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi64(c), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi64(_mm_bsrli_si128(c,8)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::733
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int16_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            using ToType = simd<uint64_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi64x(0xffff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi16_epi64(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi64(_mm_bsrli_si128(b,8)), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi64(c), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi16_epi64(_mm_bsrli_si128(c,8)), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::748
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int32_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            using ToType = simd<int64_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                return { {
                  _mm256_cvtepi32_epi64(b),
                  _mm256_cvtepi32_epi64(c),
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::760
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint32_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            using ToType = simd<uint64_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi64x(0xffffffff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi32_epi64(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi32_epi64(c), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::760
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint32_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            using ToType = simd<int64_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi64x(0xffffffff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi32_epi64(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi32_epi64(c), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::760
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int32_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            using ToType = simd<uint64_t, avx2>;
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

                auto const b = _mm256_extracti128_si256(data, 0);
                auto const c = _mm256_extracti128_si256(data, 1);
                auto const upper_zero = _mm256_set1_epi64x(0xffffffff);
                return { {
                  _mm256_and_si256(_mm256_cvtepi32_epi64(b), upper_zero),
                  _mm256_and_si256(_mm256_cvtepi32_epi64(c), upper_zero)
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int64_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            using ToType = simd<int64_t, avx2>;
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
                  data
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::773
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint64_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            using ToType = simd<int64_t, avx2>;
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
                  data
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::782
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<int64_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            using ToType = simd<uint64_t, avx2>;
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
                  data
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_up" (primitive convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::782
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_up<simd<uint64_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            using ToType = simd<uint64_t, avx2>;
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
                  data
                } };
            }
        };
    } // end of namespace functors for template specialization of convert_up for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_down" (primitive convert_down).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::960
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_down<simd<int32_t, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            using ToType = simd<int8_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_down is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm256_set1_epi32(0xff);
                const __m256i x =
                  _mm256_or_si256(
                    _mm256_or_si256(
                      _mm256_or_si256(
                        _mm256_and_si256(upper_zero, data[0]),
                        _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[1]),1)
                      ),
                      _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[2]), 2)
                    ),
                    _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[3]), 3)
                  );
                const __m256i y =
                  _mm256_shuffle_epi8(
                    x,
                    _mm256_set_epi32(
                      0xF0B0703,0xE0A0602, 0xD090501,0xC080400,
                      0xF0B0703,0xE0A0602, 0xD090501,0xC080400
                    )
                  );
                return _mm256_permutevar8x32_epi32(y, _mm256_set_epi32(7,3,6,2,5,1,4,0));
            }
        };
    } // end of namespace functors for template specialization of convert_down for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_down" (primitive convert_down).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::960
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_down<simd<uint32_t, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            using ToType = simd<uint8_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_down is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm256_set1_epi32(0xff);
                const __m256i x =
                  _mm256_or_si256(
                    _mm256_or_si256(
                      _mm256_or_si256(
                        _mm256_and_si256(upper_zero, data[0]),
                        _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[1]),1)
                      ),
                      _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[2]), 2)
                    ),
                    _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[3]), 3)
                  );
                const __m256i y =
                  _mm256_shuffle_epi8(
                    x,
                    _mm256_set_epi32(
                      0xF0B0703,0xE0A0602, 0xD090501,0xC080400,
                      0xF0B0703,0xE0A0602, 0xD090501,0xC080400
                    )
                  );
                return _mm256_permutevar8x32_epi32(y, _mm256_set_epi32(7,3,6,2,5,1,4,0));
            }
        };
    } // end of namespace functors for template specialization of convert_down for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_down" (primitive convert_down).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::999
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_down<simd<int32_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            using ToType = simd<int16_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_down is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm256_set1_epi32(0xffff);
                auto const d0 = _mm256_and_si256(upper_zero, data[0]);
                auto const d1 = _mm256_and_si256(upper_zero, data[1]);
                using zext = functors::cast<simd<Vec::base_type, sse>, simd<Vec::base_type, avx2>, Idof>;
                return
                  _mm256_shuffle_epi8(
                    _mm256_permute2x128_si256(
                      _mm256_or_si256(
                        zext::apply(
                          _mm256_extracti128_si256(
                            d0,
                            0
                          )
                        ),
                        _mm256_bslli_epi128(
                          zext::apply(
                            _mm256_extracti128_si256(
                              d0,
                              1
                            )
                          ),
                          2
                        )
                      ),
                      _mm256_or_si256(
                        zext::apply(
                          _mm256_extracti128_si256(
                            d1,
                            0
                          )
                        ),
                        _mm256_bslli_epi128(
                          zext::apply(
                            _mm256_extracti128_si256(
                              d1,
                              1
                            )
                          ),
                          2
                        )
                      ),
                      0x20
                    ),
                    _mm256_set_epi32(
                      0x0f0e0b0a, 0x07060302, 0x0d0c0908, 0x05040100,
                      0x0f0e0b0a, 0x07060302, 0x0d0c0908, 0x05040100
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of convert_down for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_down" (primitive convert_down).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::999
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_down<simd<uint32_t, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            using ToType = simd<uint16_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_down is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm256_set1_epi32(0xffff);
                auto const d0 = _mm256_and_si256(upper_zero, data[0]);
                auto const d1 = _mm256_and_si256(upper_zero, data[1]);
                using zext = functors::cast<simd<Vec::base_type, sse>, simd<Vec::base_type, avx2>, Idof>;
                return
                  _mm256_shuffle_epi8(
                    _mm256_permute2x128_si256(
                      _mm256_or_si256(
                        zext::apply(
                          _mm256_extracti128_si256(
                            d0,
                            0
                          )
                        ),
                        _mm256_bslli_epi128(
                          zext::apply(
                            _mm256_extracti128_si256(
                              d0,
                              1
                            )
                          ),
                          2
                        )
                      ),
                      _mm256_or_si256(
                        zext::apply(
                          _mm256_extracti128_si256(
                            d1,
                            0
                          )
                        ),
                        _mm256_bslli_epi128(
                          zext::apply(
                            _mm256_extracti128_si256(
                              d1,
                              1
                            )
                          ),
                          2
                        )
                      ),
                      0x20
                    ),
                    _mm256_set_epi32(
                      0x0f0e0b0a, 0x07060302, 0x0d0c0908, 0x05040100,
                      0x0f0e0b0a, 0x07060302, 0x0d0c0908, 0x05040100
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of convert_down for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_down" (primitive convert_down).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::1053
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_down<simd<int64_t, avx2>, simd<int8_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            using ToType = simd<int8_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_down is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm256_set1_epi64x(0xff);
                auto const perm = _mm256_set_epi32(7,5,3,1,6,4,2,0);
                auto const a = _mm256_permutevar8x32_epi32(_mm256_or_si256(
                  _mm256_and_si256(upper_zero, data[0]),
                  _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[1]), 4)), perm);
                auto const b = _mm256_permutevar8x32_epi32(_mm256_or_si256(
                  _mm256_and_si256(upper_zero, data[2]),
                  _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[3]), 4)), perm);
                auto const c = _mm256_permutevar8x32_epi32(_mm256_or_si256(
                  _mm256_and_si256(upper_zero, data[4]),
                  _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[5]), 4)), perm);
                auto const d = _mm256_permutevar8x32_epi32(_mm256_or_si256(
                  _mm256_and_si256(upper_zero, data[6]),
                  _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[7]), 4)), perm);
                auto const x = _mm256_or_si256(_mm256_or_si256(_mm256_or_si256(a, _mm256_bslli_epi128(b,1)), _mm256_bslli_epi128(c, 2)), _mm256_bslli_epi128(d, 3));
                auto const y = _mm256_shuffle_epi8(x, _mm256_set_epi32(0xF0B0703,0xE0A0602, 0xD090501,0xC080400, 0xF0B0703,0xE0A0602, 0xD090501,0xC080400));
                return _mm256_permutevar8x32_epi32(y, _mm256_set_epi32(7,3,6,2,5,1,4,0));
            }
        };
    } // end of namespace functors for template specialization of convert_down for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_down" (primitive convert_down).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::1053
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_down<simd<uint64_t, avx2>, simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            using ToType = simd<uint8_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_down is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm256_set1_epi64x(0xff);
                auto const perm = _mm256_set_epi32(7,5,3,1,6,4,2,0);
                auto const a = _mm256_permutevar8x32_epi32(_mm256_or_si256(
                  _mm256_and_si256(upper_zero, data[0]),
                  _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[1]), 4)), perm);
                auto const b = _mm256_permutevar8x32_epi32(_mm256_or_si256(
                  _mm256_and_si256(upper_zero, data[2]),
                  _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[3]), 4)), perm);
                auto const c = _mm256_permutevar8x32_epi32(_mm256_or_si256(
                  _mm256_and_si256(upper_zero, data[4]),
                  _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[5]), 4)), perm);
                auto const d = _mm256_permutevar8x32_epi32(_mm256_or_si256(
                  _mm256_and_si256(upper_zero, data[6]),
                  _mm256_bslli_epi128(_mm256_and_si256(upper_zero, data[7]), 4)), perm);
                auto const x = _mm256_or_si256(_mm256_or_si256(_mm256_or_si256(a, _mm256_bslli_epi128(b,1)), _mm256_bslli_epi128(c, 2)), _mm256_bslli_epi128(d, 3));
                auto const y = _mm256_shuffle_epi8(x, _mm256_set_epi32(0xF0B0703,0xE0A0602, 0xD090501,0xC080400, 0xF0B0703,0xE0A0602, 0xD090501,0xC080400));
                return _mm256_permutevar8x32_epi32(y, _mm256_set_epi32(7,3,6,2,5,1,4,0));
            }
        };
    } // end of namespace functors for template specialization of convert_down for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_down" (primitive convert_down).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::1076
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_down<simd<int64_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            using ToType = simd<int16_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_down is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm256_set1_epi64x(0xffff);
                auto const d0 = _mm256_and_si256(upper_zero, data[0]);
                auto const d1 = _mm256_and_si256(upper_zero, data[1]);
                auto const d2 = _mm256_and_si256(upper_zero, data[2]);
                auto const d3 = _mm256_and_si256(upper_zero, data[3]);
                using zext = functors::cast<simd<Vec::base_type, sse>, simd<Vec::base_type, avx2>, Idof>;
                return
                  _mm256_shuffle_epi8(
                    _mm256_permute2x128_si256(
                      _mm256_or_si256(
                        _mm256_or_si256(
                          zext::apply(_mm256_extracti128_si256(d0,0)),
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d0,1)),2)
                        ),
                        _mm256_or_si256(
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d1,0)),4),
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d1,1)),6)
                        )
                      ),
                      _mm256_or_si256(
                        _mm256_or_si256(
                          zext::apply(_mm256_extracti128_si256(d2,0)),
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d2,1)),2)
                        ),
                        _mm256_or_si256(
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d3,0)),4),
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d3,1)),6)
                        )
                      ),
                      0x20
                    ),
                    _mm256_set_epi32(
                      0x0f0e0706, 0x0d0c0504, 0x0b0a0302, 0x09080100,
                      0x0f0e0706, 0x0d0c0504, 0x0b0a0302, 0x09080100
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of convert_down for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_down" (primitive convert_down).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::1076
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_down<simd<uint64_t, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            using ToType = simd<uint16_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_down is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm256_set1_epi64x(0xffff);
                auto const d0 = _mm256_and_si256(upper_zero, data[0]);
                auto const d1 = _mm256_and_si256(upper_zero, data[1]);
                auto const d2 = _mm256_and_si256(upper_zero, data[2]);
                auto const d3 = _mm256_and_si256(upper_zero, data[3]);
                using zext = functors::cast<simd<Vec::base_type, sse>, simd<Vec::base_type, avx2>, Idof>;
                return
                  _mm256_shuffle_epi8(
                    _mm256_permute2x128_si256(
                      _mm256_or_si256(
                        _mm256_or_si256(
                          zext::apply(_mm256_extracti128_si256(d0,0)),
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d0,1)),2)
                        ),
                        _mm256_or_si256(
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d1,0)),4),
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d1,1)),6)
                        )
                      ),
                      _mm256_or_si256(
                        _mm256_or_si256(
                          zext::apply(_mm256_extracti128_si256(d2,0)),
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d2,1)),2)
                        ),
                        _mm256_or_si256(
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d3,0)),4),
                          _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d3,1)),6)
                        )
                      ),
                      0x20
                    ),
                    _mm256_set_epi32(
                      0x0f0e0706, 0x0d0c0504, 0x0b0a0302, 0x09080100,
                      0x0f0e0706, 0x0d0c0504, 0x0b0a0302, 0x09080100
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of convert_down for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_down" (primitive convert_down).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::1118
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_down<simd<int64_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            using ToType = simd<int32_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_down is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm256_set1_epi64x(0xffffffff);
                auto const d0 = _mm256_and_si256(upper_zero, data[0]);
                auto const d1 = _mm256_and_si256(upper_zero, data[1]);
                using zext = functors::cast<simd<Vec::base_type, sse>, simd<Vec::base_type, avx2>, Idof>;
                return
                  _mm256_shuffle_epi32(
                    _mm256_permute2x128_si256(
                      _mm256_or_si256(
                        zext::apply(_mm256_extracti128_si256(d0, 0)),
                        _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d0, 1)),4)
                      ),
                      _mm256_or_si256(
                        zext::apply(_mm256_extracti128_si256(d1, 0)),
                        _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d1, 1)),4)
                      ),
                      0x20
                    ),
                    0xd8
                  );
            }
        };
    } // end of namespace functors for template specialization of convert_down for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "convert_down" (primitive convert_down).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::1118
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct convert_down<simd<uint64_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            using ToType = simd<uint32_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)>>;
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
            static typename ToType::register_type apply(
                std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)> data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive convert_down is not supported by your hardware natively while it is forced by using native" );

                auto const upper_zero = _mm256_set1_epi64x(0xffffffff);
                auto const d0 = _mm256_and_si256(upper_zero, data[0]);
                auto const d1 = _mm256_and_si256(upper_zero, data[1]);
                using zext = functors::cast<simd<Vec::base_type, sse>, simd<Vec::base_type, avx2>, Idof>;
                return
                  _mm256_shuffle_epi32(
                    _mm256_permute2x128_si256(
                      _mm256_or_si256(
                        zext::apply(_mm256_extracti128_si256(d0, 0)),
                        _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d0, 1)),4)
                      ),
                      _mm256_or_si256(
                        zext::apply(_mm256_extracti128_si256(d1, 0)),
                        _mm256_bslli_epi128(zext::apply(_mm256_extracti128_si256(d1, 1)),4)
                      ),
                      0x20
                    ),
                    0xd8
                  );
            }
        };
    } // end of namespace functors for template specialization of convert_down for avx2 using uint64_t.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_AVX2_HPP