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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/definitions/binary/binary_oneAPIfpga.hpp
 * \date 2023-07-28
 * \brief Bit manipulation primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_BINARY_BINARY_ONEAPIFPGA_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_BINARY_BINARY_ONEAPIFPGA_HPP

#include <sycl/ext/intel/ac_types/ac_int.hpp>
#include "../../declarations/binary.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::135
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] & b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_and for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::135
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] & b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_and for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::135
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] & b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_and for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::135
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] & b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_and for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::135
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] & b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_and for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::135
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] & b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_and for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::135
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] & b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_and for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_and" (primitive binary_and).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::135
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_and<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] & b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_and for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::246
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] | b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_or for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::246
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] | b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_or for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::246
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] | b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_or for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::246
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] | b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_or for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::246
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] | b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_or for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::246
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] | b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_or for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::246
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] | b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_or for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_or" (primitive binary_or).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::246
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_or<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] | b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_or for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::398
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] ^ b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::398
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] ^ b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::398
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] ^ b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::398
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] ^ b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::398
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] ^ b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::398
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] ^ b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::398
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] ^ b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "binary_xor" (primitive binary_xor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::398
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct binary_xor<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = a[i] ^ b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of binary_xor for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::466
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << (typename Vec::base_type) shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::466
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << (typename Vec::base_type) shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::466
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << (typename Vec::base_type) shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::466
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << (typename Vec::base_type) shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::466
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << (typename Vec::base_type) shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::466
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << (typename Vec::base_type) shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::466
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << (typename Vec::base_type) shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::466
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << (typename Vec::base_type) shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::559
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::559
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::559
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::559
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::559
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::559
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::559
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_left_vector" (primitive shift_left).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::559
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] << shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_left_vector for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::758
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<uint8_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::758
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<int8_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::758
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<uint16_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::758
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<int16_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::758
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<uint32_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::758
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<int32_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::758
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<uint64_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::758
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right<simd<int64_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::998
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<uint8_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::998
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<int8_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::998
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<uint16_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::998
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<int16_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::998
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<uint32_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::998
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<int32_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::998
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<uint64_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "shift_right_vector" (primitive shift_right).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::998
         */
        template<std::size_t VectorSize, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector<simd<int64_t, oneAPIfpga, VectorSize>, PreserveSign, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = data[i] >> shift[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of shift_right_vector for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1094
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::offset_base_register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_register_type apply(
                const typename Vec::register_type data
            ) {
                typename Vec::offset_base_register_type result{};
                using base_t = typename Vec::base_type;
                // as the current version of oneAPI does not properly implement ac_int::leading_sign() we "reimplemented" it
                // /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/lib/oclfpga/include/sycl/ext/intel/ac_types/ac_int.hpp
                using bitInt = ac_int<(sizeof(base_t)*CHAR_BIT), false>;
                #pragma unroll
                for(size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  bitInt val(data[idx]);
                  int k = (sizeof(base_t)*CHAR_BIT)-1;
                  #pragma unroll
                  for(; k >= 0 && val[k] == 0; k--) {}
                  result[idx] = (sizeof(base_t)*CHAR_BIT-1) - k;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of lzc for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1094
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::offset_base_register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_register_type apply(
                const typename Vec::register_type data
            ) {
                typename Vec::offset_base_register_type result{};
                using base_t = typename Vec::base_type;
                // as the current version of oneAPI does not properly implement ac_int::leading_sign() we "reimplemented" it
                // /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/lib/oclfpga/include/sycl/ext/intel/ac_types/ac_int.hpp
                using bitInt = ac_int<(sizeof(base_t)*CHAR_BIT), false>;
                #pragma unroll
                for(size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  bitInt val(data[idx]);
                  int k = (sizeof(base_t)*CHAR_BIT)-1;
                  #pragma unroll
                  for(; k >= 0 && val[k] == 0; k--) {}
                  result[idx] = (sizeof(base_t)*CHAR_BIT-1) - k;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of lzc for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1094
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::offset_base_register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_register_type apply(
                const typename Vec::register_type data
            ) {
                typename Vec::offset_base_register_type result{};
                using base_t = typename Vec::base_type;
                // as the current version of oneAPI does not properly implement ac_int::leading_sign() we "reimplemented" it
                // /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/lib/oclfpga/include/sycl/ext/intel/ac_types/ac_int.hpp
                using bitInt = ac_int<(sizeof(base_t)*CHAR_BIT), false>;
                #pragma unroll
                for(size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  bitInt val(data[idx]);
                  int k = (sizeof(base_t)*CHAR_BIT)-1;
                  #pragma unroll
                  for(; k >= 0 && val[k] == 0; k--) {}
                  result[idx] = (sizeof(base_t)*CHAR_BIT-1) - k;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of lzc for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1094
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::offset_base_register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_register_type apply(
                const typename Vec::register_type data
            ) {
                typename Vec::offset_base_register_type result{};
                using base_t = typename Vec::base_type;
                // as the current version of oneAPI does not properly implement ac_int::leading_sign() we "reimplemented" it
                // /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/lib/oclfpga/include/sycl/ext/intel/ac_types/ac_int.hpp
                using bitInt = ac_int<(sizeof(base_t)*CHAR_BIT), false>;
                #pragma unroll
                for(size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  bitInt val(data[idx]);
                  int k = (sizeof(base_t)*CHAR_BIT)-1;
                  #pragma unroll
                  for(; k >= 0 && val[k] == 0; k--) {}
                  result[idx] = (sizeof(base_t)*CHAR_BIT-1) - k;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of lzc for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1094
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::offset_base_register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_register_type apply(
                const typename Vec::register_type data
            ) {
                typename Vec::offset_base_register_type result{};
                using base_t = typename Vec::base_type;
                // as the current version of oneAPI does not properly implement ac_int::leading_sign() we "reimplemented" it
                // /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/lib/oclfpga/include/sycl/ext/intel/ac_types/ac_int.hpp
                using bitInt = ac_int<(sizeof(base_t)*CHAR_BIT), false>;
                #pragma unroll
                for(size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  bitInt val(data[idx]);
                  int k = (sizeof(base_t)*CHAR_BIT)-1;
                  #pragma unroll
                  for(; k >= 0 && val[k] == 0; k--) {}
                  result[idx] = (sizeof(base_t)*CHAR_BIT-1) - k;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of lzc for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1094
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::offset_base_register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_register_type apply(
                const typename Vec::register_type data
            ) {
                typename Vec::offset_base_register_type result{};
                using base_t = typename Vec::base_type;
                // as the current version of oneAPI does not properly implement ac_int::leading_sign() we "reimplemented" it
                // /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/lib/oclfpga/include/sycl/ext/intel/ac_types/ac_int.hpp
                using bitInt = ac_int<(sizeof(base_t)*CHAR_BIT), false>;
                #pragma unroll
                for(size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  bitInt val(data[idx]);
                  int k = (sizeof(base_t)*CHAR_BIT)-1;
                  #pragma unroll
                  for(; k >= 0 && val[k] == 0; k--) {}
                  result[idx] = (sizeof(base_t)*CHAR_BIT-1) - k;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of lzc for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1094
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::offset_base_register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_register_type apply(
                const typename Vec::register_type data
            ) {
                typename Vec::offset_base_register_type result{};
                using base_t = typename Vec::base_type;
                // as the current version of oneAPI does not properly implement ac_int::leading_sign() we "reimplemented" it
                // /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/lib/oclfpga/include/sycl/ext/intel/ac_types/ac_int.hpp
                using bitInt = ac_int<(sizeof(base_t)*CHAR_BIT), false>;
                #pragma unroll
                for(size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  bitInt val(data[idx]);
                  int k = (sizeof(base_t)*CHAR_BIT)-1;
                  #pragma unroll
                  for(; k >= 0 && val[k] == 0; k--) {}
                  result[idx] = (sizeof(base_t)*CHAR_BIT-1) - k;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of lzc for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1094
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::offset_base_register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_register_type apply(
                const typename Vec::register_type data
            ) {
                typename Vec::offset_base_register_type result{};
                using base_t = typename Vec::base_type;
                // as the current version of oneAPI does not properly implement ac_int::leading_sign() we "reimplemented" it
                // /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/lib/oclfpga/include/sycl/ext/intel/ac_types/ac_int.hpp
                using bitInt = ac_int<(sizeof(base_t)*CHAR_BIT), false>;
                #pragma unroll
                for(size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  bitInt val(data[idx]);
                  int k = (sizeof(base_t)*CHAR_BIT)-1;
                  #pragma unroll
                  for(; k >= 0 && val[k] == 0; k--) {}
                  result[idx] = (sizeof(base_t)*CHAR_BIT-1) - k;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of lzc for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1094
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::offset_base_register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_register_type apply(
                const typename Vec::register_type data
            ) {
                typename Vec::offset_base_register_type result{};
                using base_t = typename Vec::base_type;
                // as the current version of oneAPI does not properly implement ac_int::leading_sign() we "reimplemented" it
                // /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/lib/oclfpga/include/sycl/ext/intel/ac_types/ac_int.hpp
                using bitInt = ac_int<(sizeof(base_t)*CHAR_BIT), false>;
                #pragma unroll
                for(size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  bitInt val(data[idx]);
                  int k = (sizeof(base_t)*CHAR_BIT)-1;
                  #pragma unroll
                  for(; k >= 0 && val[k] == 0; k--) {}
                  result[idx] = (sizeof(base_t)*CHAR_BIT-1) - k;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of lzc for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1094
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::offset_base_register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::offset_base_register_type apply(
                const typename Vec::register_type data
            ) {
                typename Vec::offset_base_register_type result{};
                using base_t = typename Vec::base_type;
                // as the current version of oneAPI does not properly implement ac_int::leading_sign() we "reimplemented" it
                // /glob/development-tools/versions/oneapi/2023.0.1/oneapi/compiler/2023.0.0/linux/lib/oclfpga/include/sycl/ext/intel/ac_types/ac_int.hpp
                using bitInt = ac_int<(sizeof(base_t)*CHAR_BIT), false>;
                #pragma unroll
                for(size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  bitInt val(data[idx]);
                  int k = (sizeof(base_t)*CHAR_BIT)-1;
                  #pragma unroll
                  for(; k >= 0 && val[k] == 0; k--) {}
                  result[idx] = (sizeof(base_t)*CHAR_BIT-1) - k;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of lzc for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1171
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
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
                return details::clz_recursive<typename Vec::base_type, typename Vec::offset_base_type>::apply(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1171
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
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
                return details::clz_recursive<typename Vec::base_type, typename Vec::offset_base_type>::apply(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1171
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
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
                return details::clz_recursive<typename Vec::base_type, typename Vec::offset_base_type>::apply(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1171
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
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
                return details::clz_recursive<typename Vec::base_type, typename Vec::offset_base_type>::apply(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1171
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
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
                return details::clz_recursive<typename Vec::base_type, typename Vec::offset_base_type>::apply(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1171
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
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
                return details::clz_recursive<typename Vec::base_type, typename Vec::offset_base_type>::apply(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1171
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
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
                return details::clz_recursive<typename Vec::base_type, typename Vec::offset_base_type>::apply(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "lzc_scalar" (primitive lzc).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1171
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
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
                return details::clz_recursive<typename Vec::base_type, typename Vec::offset_base_type>::apply(data);
            }
        };
    } // end of namespace functors for template specialization of lzc_scalar for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1396
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
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
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = vec[i<<1] | vec[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] | result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hor for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1396
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
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
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = vec[i<<1] | vec[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] | result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hor for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1396
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
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
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = vec[i<<1] | vec[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] | result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hor for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1396
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
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
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = vec[i<<1] | vec[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] | result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hor for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1396
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
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
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = vec[i<<1] | vec[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] | result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hor for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1396
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
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
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = vec[i<<1] | vec[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] | result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hor for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1396
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hor<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
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
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = vec[i<<1] | vec[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] | result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hor for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1396
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hor<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
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
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = vec[i<<1] | vec[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] | result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hor for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1396
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hor<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
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
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = vec[i<<1] | vec[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] | result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hor for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hor" (primitive hor).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1396
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hor<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
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
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = vec[i<<1] | vec[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] | result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hor for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1600
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = ~vec[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of inv for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1600
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = ~vec[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of inv for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1600
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = ~vec[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of inv for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1600
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = ~vec[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of inv for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1600
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = ~vec[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of inv for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1600
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = ~vec[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of inv for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1600
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct inv<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = ~vec[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of inv for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "inv" (primitive inv).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/binary.yaml::1600
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct inv<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
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
                using T = typename Vec::register_type;
                T result{};
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = ~vec[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of inv for oneAPIfpga using int64_t.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_BINARY_BINARY_ONEAPIFPGA_HPP