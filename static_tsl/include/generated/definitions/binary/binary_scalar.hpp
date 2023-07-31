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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/definitions/binary/binary_scalar.hpp
 * \date 2023-07-28
 * \brief Bit manipulation primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_BINARY_BINARY_SCALAR_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_BINARY_BINARY_SCALAR_HPP

#include "../../declarations/binary.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::96
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
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
                return a & b;
            }
        };
    } // end of namespace functors for template specialization of binary_and for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::96
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
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
                return a & b;
            }
        };
    } // end of namespace functors for template specialization of binary_and for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::96
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
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
                return a & b;
            }
        };
    } // end of namespace functors for template specialization of binary_and for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::96
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
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
                return a & b;
            }
        };
    } // end of namespace functors for template specialization of binary_and for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::96
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
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
                return a & b;
            }
        };
    } // end of namespace functors for template specialization of binary_and for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::96
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
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
                return a & b;
            }
        };
    } // end of namespace functors for template specialization of binary_and for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::96
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
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
                return a & b;
            }
        };
    } // end of namespace functors for template specialization of binary_and for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::96
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
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
                return a & b;
            }
        };
    } // end of namespace functors for template specialization of binary_and for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: scalar.
         *        Data Type: float
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::100
         * @note: Benchmark what to use. Current implementation or: uint32_t c = (*((uint32_t *)&a) & *((uint32_t *)&b)); return *((float *)&c);
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<float, scalar>, Idof> {
            using Vec = simd<float, scalar>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive binary_and is not supported by your hardware natively while it is forced by using native" );

                float c = 0.0;
                auto a1 = reinterpret_cast<const unsigned char *>(&a);
                auto b1 = reinterpret_cast<const unsigned char *>(&b);
                auto c1 = reinterpret_cast<unsigned char *>(&c);
                c1[0] = a1[0] & b1[0];
                c1[1] = a1[1] & b1[1];
                c1[2] = a1[2] & b1[2];
                c1[3] = a1[3] & b1[3];
                return c;
            }
        };
    } // end of namespace functors for template specialization of binary_and for scalar using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: scalar.
         *        Data Type: double
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::115
         * @note: Benchmark what to use. Current implementation or: uint64_t c = (*((uint64_t *)&a) & *((uint64_t *)&b)); return *((double *)&c);
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<double, scalar>, Idof> {
            using Vec = simd<double, scalar>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive binary_and is not supported by your hardware natively while it is forced by using native" );

                double c = 0.0;
                auto a1 = reinterpret_cast<const unsigned char *>(&a);
                auto b1 = reinterpret_cast<const unsigned char *>(&b);
                auto c1 = reinterpret_cast<unsigned char *>(&c);
                c1[0] = a1[0] & b1[0];
                c1[1] = a1[1] & b1[1];
                c1[2] = a1[2] & b1[2];
                c1[3] = a1[3] & b1[3];
                c1[4] = a1[4] & b1[4];
                c1[5] = a1[5] & b1[5];
                c1[6] = a1[6] & b1[6];
                c1[7] = a1[7] & b1[7];
                return c;
            }
        };
    } // end of namespace functors for template specialization of binary_and for scalar using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::231
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
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
                return a | b;
            }
        };
    } // end of namespace functors for template specialization of binary_or for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::231
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
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
                return a | b;
            }
        };
    } // end of namespace functors for template specialization of binary_or for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::231
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
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
                return a | b;
            }
        };
    } // end of namespace functors for template specialization of binary_or for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::231
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
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
                return a | b;
            }
        };
    } // end of namespace functors for template specialization of binary_or for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::231
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
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
                return a | b;
            }
        };
    } // end of namespace functors for template specialization of binary_or for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::231
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
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
                return a | b;
            }
        };
    } // end of namespace functors for template specialization of binary_or for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::231
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
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
                return a | b;
            }
        };
    } // end of namespace functors for template specialization of binary_or for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::231
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
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
                return a | b;
            }
        };
    } // end of namespace functors for template specialization of binary_or for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: scalar.
         *        Data Type: float
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::235
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<float, scalar>, Idof> {
            using Vec = simd<float, scalar>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive binary_or is not supported by your hardware natively while it is forced by using native" );

                uint32_t r = *((uint32_t *)&a) | *((uint32_t *)&b); return *(float*)&r;
            }
        };
    } // end of namespace functors for template specialization of binary_or for scalar using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: scalar.
         *        Data Type: double
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::240
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<double, scalar>, Idof> {
            using Vec = simd<double, scalar>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive binary_or is not supported by your hardware natively while it is forced by using native" );

                uint64_t r = *((uint64_t *)&a) | *((uint64_t *)&b); return *(double*)&r;
            }
        };
    } // end of namespace functors for template specialization of binary_or for scalar using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::359
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
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
                return a ^ b;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::359
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
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
                return a ^ b;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::359
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
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
                return a ^ b;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::359
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
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
                return a ^ b;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::359
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
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
                return a ^ b;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::359
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
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
                return a ^ b;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::359
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
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
                return a ^ b;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::359
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
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
                return a ^ b;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: float
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::363
         * @note: Benchmark what to use. Current implementation or: uint32_t c = (*((uint32_t *)&a) ^ *((uint32_t *)&b)); return *((float *)&c);
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<float, scalar>, Idof> {
            using Vec = simd<float, scalar>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive binary_xor is not supported by your hardware natively while it is forced by using native" );

                float c = 0.0;
                auto a1 = reinterpret_cast<const unsigned char *>(&a);
                auto b1 = reinterpret_cast<const unsigned char *>(&b);
                auto c1 = reinterpret_cast<unsigned char *>(&c);
                c1[0] = a1[0] ^ b1[0];
                c1[1] = a1[1] ^ b1[1];
                c1[2] = a1[2] ^ b1[2];
                c1[3] = a1[3] ^ b1[3];
                return c;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for scalar using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: double
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::378
         * @note: Benchmark what to use. Current implementation or: uint64_t c = (*((uint64_t *)&a) ^ *((uint64_t *)&b)); return *((double *)&c);
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<double, scalar>, Idof> {
            using Vec = simd<double, scalar>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::register_type a, const typename Vec::register_type b
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive binary_xor is not supported by your hardware natively while it is forced by using native" );

                double c = 0.0;
                auto a1 = reinterpret_cast<const unsigned char *>(&a);
                auto b1 = reinterpret_cast<const unsigned char *>(&b);
                auto c1 = reinterpret_cast<unsigned char *>(&c);
                c1[0] = a1[0] ^ b1[0];
                c1[1] = a1[1] ^ b1[1];
                c1[2] = a1[2] ^ b1[2];
                c1[3] = a1[3] ^ b1[3];
                c1[4] = a1[4] ^ b1[4];
                c1[5] = a1[5] ^ b1[5];
                c1[6] = a1[6] ^ b1[6];
                c1[7] = a1[7] ^ b1[7];
                return c;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for scalar using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::459
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::459
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::459
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::459
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::459
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::459
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::459
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::459
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::552
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
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
                return data << shift;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::747
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<uint8_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::747
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<uint16_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::747
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<uint32_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::747
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<uint64_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::747
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<int8_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<int8_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::747
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<int16_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<int16_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::747
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<int32_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<int32_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::747
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<int64_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<int64_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::987
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<int8_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<int8_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::987
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<int16_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<int16_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::987
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<int32_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<int32_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::987
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<int64_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<int64_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::987
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<uint8_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::987
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<uint16_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::987
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<uint32_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::987
         */
        template<bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<uint64_t, scalar>, PreserveSign, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
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
                if constexpr ((std::is_signed_v<typename Vec::base_type>) && (!PreserveSign)) {
                  return static_cast<std::make_unsigned_t<typename Vec::register_type>>(data) >> shift;
                  //return (typename Vec::register_type)(((std::make_unsigned_t<typename Vec::register_type>)data) >> shift);
                } else {
                  return data >> shift;
                }
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1165
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
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
    } // end of namespace functors for template specialization of lzc_scalar for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1165
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
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
    } // end of namespace functors for template specialization of lzc_scalar for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1165
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
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
    } // end of namespace functors for template specialization of lzc_scalar for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1165
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
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
    } // end of namespace functors for template specialization of lzc_scalar for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1165
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
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
    } // end of namespace functors for template specialization of lzc_scalar for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1165
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
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
    } // end of namespace functors for template specialization of lzc_scalar for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1165
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
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
    } // end of namespace functors for template specialization of lzc_scalar for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1165
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
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
    } // end of namespace functors for template specialization of lzc_scalar for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1390
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
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
                return vec;
            }
        };
    } // end of namespace functors for template specialization of hor for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1390
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
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
                return vec;
            }
        };
    } // end of namespace functors for template specialization of hor for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1390
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
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
                return vec;
            }
        };
    } // end of namespace functors for template specialization of hor for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1390
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
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
                return vec;
            }
        };
    } // end of namespace functors for template specialization of hor for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1390
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
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
                return vec;
            }
        };
    } // end of namespace functors for template specialization of hor for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1390
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
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
                return vec;
            }
        };
    } // end of namespace functors for template specialization of hor for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1390
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
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
                return vec;
            }
        };
    } // end of namespace functors for template specialization of hor for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1390
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
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
                return vec;
            }
        };
    } // end of namespace functors for template specialization of hor for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: float
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1390
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<float, scalar>, Idof> {
            using Vec = simd<float, scalar>;
            
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
                return vec;
            }
        };
    } // end of namespace functors for template specialization of hor for scalar using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: scalar.
         *        Data Type: double
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1390
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct hor<simd<double, scalar>, Idof> {
            using Vec = simd<double, scalar>;
            
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
                return vec;
            }
        };
    } // end of namespace functors for template specialization of hor for scalar using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1577
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
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
                return ~vec;
            }
        };
    } // end of namespace functors for template specialization of inv for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1577
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
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
                return ~vec;
            }
        };
    } // end of namespace functors for template specialization of inv for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1577
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
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
                return ~vec;
            }
        };
    } // end of namespace functors for template specialization of inv for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1577
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
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
                return ~vec;
            }
        };
    } // end of namespace functors for template specialization of inv for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1577
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
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
                return ~vec;
            }
        };
    } // end of namespace functors for template specialization of inv for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1577
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
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
                return ~vec;
            }
        };
    } // end of namespace functors for template specialization of inv for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1577
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
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
                return ~vec;
            }
        };
    } // end of namespace functors for template specialization of inv for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1577
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
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
                return ~vec;
            }
        };
    } // end of namespace functors for template specialization of inv for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: scalar.
         *        Data Type: float
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1581
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<float, scalar>, Idof> {
            using Vec = simd<float, scalar>;
            
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
                union {
                  float val;
                  int32_t i_val;
                } u;
                u.val = vec;
                u.i_val = ~u.i_val;
                return u.val;
            }
        };
    } // end of namespace functors for template specialization of inv for scalar using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: scalar.
         *        Data Type: double
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/binary.yaml::1581
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct inv<simd<double, scalar>, Idof> {
            using Vec = simd<double, scalar>;
            
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
                union {
                  double val;
                  int64_t i_val;
                } u;
                u.val = vec;
                u.i_val = ~u.i_val;
                return u.val;
            }
        };
    } // end of namespace functors for template specialization of inv for scalar using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_BINARY_BINARY_SCALAR_HPP