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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/convert/convert_scalar.hpp
 * \date 2023-07-22
 * \brief Conversion primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_SCALAR_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_SCALAR_HPP

#include "../../declarations/convert.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int8_t, scalar>, simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            using ToType = simd<int8_t, scalar>;
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
    } // end of namespace functors for template specialization of reinterpret for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint8_t, scalar>, simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            using ToType = simd<uint8_t, scalar>;
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
    } // end of namespace functors for template specialization of reinterpret for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int16_t, scalar>, simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            using ToType = simd<int16_t, scalar>;
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
    } // end of namespace functors for template specialization of reinterpret for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint16_t, scalar>, simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            using ToType = simd<uint16_t, scalar>;
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
    } // end of namespace functors for template specialization of reinterpret for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int32_t, scalar>, simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            using ToType = simd<int32_t, scalar>;
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
    } // end of namespace functors for template specialization of reinterpret for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint32_t, scalar>, simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            using ToType = simd<uint32_t, scalar>;
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
    } // end of namespace functors for template specialization of reinterpret for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<int64_t, scalar>, simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            using ToType = simd<int64_t, scalar>;
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
    } // end of namespace functors for template specialization of reinterpret for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<uint64_t, scalar>, simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            using ToType = simd<uint64_t, scalar>;
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
    } // end of namespace functors for template specialization of reinterpret for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: scalar.
         *        Data Type: float
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, scalar>, simd<float, scalar>, Idof> {
            using Vec = simd<float, scalar>;
            using ToType = simd<float, scalar>;
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
    } // end of namespace functors for template specialization of reinterpret for scalar using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: scalar.
         *        Data Type: double
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::135
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, scalar>, simd<double, scalar>, Idof> {
            using Vec = simd<double, scalar>;
            using ToType = simd<double, scalar>;
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
    } // end of namespace functors for template specialization of reinterpret for scalar using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::214
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int32_t, scalar>, simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, scalar>;
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
                return _mm_cvtsi32_si128(data);
            }
        };
    } // end of namespace functors for template specialization of cast for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::214
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int64_t, scalar>, simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, scalar>;
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
                return _mm_cvtsi64_si128(data);
            }
        };
    } // end of namespace functors for template specialization of cast for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::214
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint32_t, scalar>, simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, scalar>;
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
                return _mm_cvtsi32_si128(data);
            }
        };
    } // end of namespace functors for template specialization of cast for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/convert.yaml::214
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint64_t, scalar>, simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, scalar>;
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
                return _mm_cvtsi64_si128(data);
            }
        };
    } // end of namespace functors for template specialization of cast for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: scalar.
         *        Data Type: float
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::330
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<float, scalar>, simd<int32_t, scalar>, Idof> {
            using Vec = simd<float, scalar>;
            using ToType = simd<int32_t, scalar>;
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
                using T  = int32_t;
                return static_cast<T>(data);
            }
        };
    } // end of namespace functors for template specialization of cast for scalar using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: scalar.
         *        Data Type: double
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::330
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<double, scalar>, simd<int64_t, scalar>, Idof> {
            using Vec = simd<double, scalar>;
            using ToType = simd<int64_t, scalar>;
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
                using T = int64_t;
                return static_cast<T>(data);
            }
        };
    } // end of namespace functors for template specialization of cast for scalar using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::447
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint32_t, scalar>, simd<float, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            using ToType = simd<float, scalar>;
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
                using T  = float;
                return static_cast<T>(data);
            }
        };
    } // end of namespace functors for template specialization of cast for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::447
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<uint64_t, scalar>, simd<double, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            using ToType = simd<double, scalar>;
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
                using T = double;
                return static_cast<T>(data);
            }
        };
    } // end of namespace functors for template specialization of cast for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::447
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int32_t, scalar>, simd<float, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            using ToType = simd<float, scalar>;
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
                using T  = float;
                return static_cast<T>(data);
            }
        };
    } // end of namespace functors for template specialization of cast for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "cast" (primitive cast).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/convert.yaml::447
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct cast<simd<int64_t, scalar>, simd<double, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            using ToType = simd<double, scalar>;
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
                using T = double;
                return static_cast<T>(data);
            }
        };
    } // end of namespace functors for template specialization of cast for scalar using int64_t.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_SCALAR_HPP