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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/definitions/ls/ls_oneAPIfpga.hpp
 * \date 2023-07-28
 * \brief Load/Store primitives
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_ONEAPIFPGA_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_ONEAPIFPGA_HPP

#include "../../declarations/ls.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::80
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                auto mem = assume_aligned<Vec::vector_alignment()>(memory);
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = mem[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of load for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::80
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct load<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                auto mem = assume_aligned<Vec::vector_alignment()>(memory);
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = mem[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of load for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::80
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                auto mem = assume_aligned<Vec::vector_alignment()>(memory);
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = mem[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of load for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::80
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct load<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                auto mem = assume_aligned<Vec::vector_alignment()>(memory);
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = mem[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of load for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::80
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                auto mem = assume_aligned<Vec::vector_alignment()>(memory);
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = mem[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of load for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::80
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct load<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                auto mem = assume_aligned<Vec::vector_alignment()>(memory);
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = mem[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of load for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::80
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct load<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                auto mem = assume_aligned<Vec::vector_alignment()>(memory);
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = mem[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of load for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::80
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                auto mem = assume_aligned<Vec::vector_alignment()>(memory);
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = mem[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of load for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::80
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct load<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                auto mem = assume_aligned<Vec::vector_alignment()>(memory);
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = mem[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of load for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::80
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct load<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                auto mem = assume_aligned<Vec::vector_alignment()>(memory);
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = mem[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of load for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::169
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = memory[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of loadu for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::169
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = memory[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of loadu for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::169
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = memory[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of loadu for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::169
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = memory[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of loadu for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::169
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = memory[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of loadu for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::169
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = memory[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of loadu for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::169
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = memory[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of loadu for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::169
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = memory[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of loadu for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::169
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = memory[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of loadu for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::169
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::base_type* memory
            ) {
                using T = typename Vec::register_type;
                T reg; //initialize the result
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  reg[idx] = memory[idx];
                }
                return reg;
            }
        };
    } // end of namespace functors for template specialization of loadu for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::257
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of store for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::257
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct store<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of store for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::257
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of store for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::257
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct store<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of store for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::257
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of store for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::257
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct store<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of store for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::257
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct store<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of store for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::257
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of store for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::257
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct store<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of store for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::257
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct store<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of store for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::340
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of storeu for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::340
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of storeu for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::340
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of storeu for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::340
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of storeu for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::340
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of storeu for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::340
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of storeu for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::340
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of storeu for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::340
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of storeu for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::340
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of storeu for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::340
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<typename Vec::base_type*, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return true;
            }
            
            TSL_FORCE_INLINE 
            static void apply(
                typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                #pragma unroll
                for (size_t idx = 0; idx < Vec::vector_element_count(); idx++) {
                  memory[idx] = data[idx];
                }
            }
        };
    } // end of namespace functors for template specialization of storeu for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::470
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::base_type value
            ) {
                using T = typename Vec::register_type;
                T result;
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = value;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set1 for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::470
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::base_type value
            ) {
                using T = typename Vec::register_type;
                T result;
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = value;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set1 for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::470
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::base_type value
            ) {
                using T = typename Vec::register_type;
                T result;
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = value;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set1 for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::470
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::base_type value
            ) {
                using T = typename Vec::register_type;
                T result;
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = value;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set1 for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::470
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::base_type value
            ) {
                using T = typename Vec::register_type;
                T result;
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = value;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set1 for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::470
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::base_type value
            ) {
                using T = typename Vec::register_type;
                T result;
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = value;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set1 for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::470
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set1<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::base_type value
            ) {
                using T = typename Vec::register_type;
                T result;
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = value;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set1 for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::470
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::base_type value
            ) {
                using T = typename Vec::register_type;
                T result;
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = value;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set1 for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::470
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::base_type value
            ) {
                using T = typename Vec::register_type;
                T result;
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = value;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set1 for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::470
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set1<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                const typename Vec::base_type value
            ) {
                using T = typename Vec::register_type;
                T result;
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = value;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set1 for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::518
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set_zero for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::518
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set_zero for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::518
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set_zero for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::518
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set_zero for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::518
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set_zero for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::518
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set_zero for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::518
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set_zero for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::518
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set_zero for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::518
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set_zero for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/ls.yaml::518
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::register_type;
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
            static typename Vec::register_type apply(
                
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of set_zero for oneAPIfpga using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_ONEAPIFPGA_HPP