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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/definitions/calc/calc_oneAPIfpgaRTL.hpp
 * \date 2023-07-28
 * \brief This file contains arithmetic primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_CALC_CALC_ONEAPIFPGARTL_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_CALC_CALC_ONEAPIFPGARTL_HPP

#include "../../declarations/calc.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::130
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct add<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] + vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of add for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::130
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct add<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] + vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of add for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::130
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct add<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] + vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of add for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::130
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct add<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] + vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of add for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::130
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct add<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] + vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of add for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::130
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct add<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] + vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of add for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::130
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct add<simd<float, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] + vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of add for oneAPIfpgaRTL using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::130
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct add<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] + vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of add for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::130
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct add<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] + vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of add for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "add" (primitive add).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::130
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct add<simd<double, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] + vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of add for oneAPIfpgaRTL using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::268
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct sub<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] - vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of sub for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::268
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct sub<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] - vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of sub for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::268
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct sub<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] - vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of sub for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::268
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct sub<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] - vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of sub for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::268
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct sub<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] - vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of sub for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::268
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct sub<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] - vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of sub for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::268
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct sub<simd<float, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] - vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of sub for oneAPIfpgaRTL using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::268
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct sub<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] - vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of sub for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::268
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct sub<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] - vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of sub for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sub" (primitive sub).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::268
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct sub<simd<double, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] - vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of sub for oneAPIfpgaRTL using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::499
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mul<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] * vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mul for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::499
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mul<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] * vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mul for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::499
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mul<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] * vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mul for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::499
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mul<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] * vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mul for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::499
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mul<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] * vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mul for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::499
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mul<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] * vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mul for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::499
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mul<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] * vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mul for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::499
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mul<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] * vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mul for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::499
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mul<simd<float, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] * vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mul for oneAPIfpgaRTL using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mul" (primitive mul).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::499
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mul<simd<double, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] * vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mul for oneAPIfpgaRTL using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::548
         * @note: This is for testing reasons only and does *not* use any RTL codes.
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type value
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = value[i<<1] + value[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] + result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hadd for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::548
         * @note: This is for testing reasons only and does *not* use any RTL codes.
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type value
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = value[i<<1] + value[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] + result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hadd for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::548
         * @note: This is for testing reasons only and does *not* use any RTL codes.
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type value
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = value[i<<1] + value[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] + result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hadd for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::548
         * @note: This is for testing reasons only and does *not* use any RTL codes.
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type value
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = value[i<<1] + value[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] + result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hadd for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::548
         * @note: This is for testing reasons only and does *not* use any RTL codes.
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type value
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = value[i<<1] + value[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] + result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hadd for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::548
         * @note: This is for testing reasons only and does *not* use any RTL codes.
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type value
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = value[i<<1] + value[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] + result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hadd for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::548
         * @note: This is for testing reasons only and does *not* use any RTL codes.
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<float, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type value
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = value[i<<1] + value[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] + result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hadd for oneAPIfpgaRTL using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::548
         * @note: This is for testing reasons only and does *not* use any RTL codes.
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type value
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = value[i<<1] + value[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] + result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hadd for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::548
         * @note: This is for testing reasons only and does *not* use any RTL codes.
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type value
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = value[i<<1] + value[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] + result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hadd for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hadd" (primitive hadd).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::548
         * @note: This is for testing reasons only and does *not* use any RTL codes.
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hadd<simd<double, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type value
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = value[i<<1] + value[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  [[intel::fpga_register]] int previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll 
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] + result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hadd for oneAPIfpgaRTL using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::837
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct min<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of min for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::837
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct min<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of min for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::837
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct min<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of min for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::837
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct min<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of min for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::837
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct min<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of min for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::837
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct min<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of min for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::837
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct min<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of min for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::837
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct min<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of min for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::837
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct min<simd<float, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of min for oneAPIfpgaRTL using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "min" (primitive min).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::837
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct min<simd<double, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] < vec_b[i] ? vec_a[i] : vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of min for oneAPIfpgaRTL using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1010
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct div<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] / vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of div for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1010
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct div<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] / vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of div for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1010
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct div<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] / vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of div for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1010
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct div<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] / vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of div for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1010
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct div<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] / vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of div for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1010
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct div<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] / vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of div for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1010
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct div<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] / vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of div for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1010
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct div<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] / vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of div for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1010
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct div<simd<float, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] / vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of div for oneAPIfpgaRTL using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "div" (primitive div).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1010
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct div<simd<double, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec_a[i] / vec_b[i];
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of div for oneAPIfpgaRTL using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1228
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mod<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec[i] - ((vec[i] / val) * val);
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mod for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1228
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mod<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec[i] - ((vec[i] / val) * val);
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mod for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1228
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mod<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec[i] - ((vec[i] / val) * val);
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mod for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1228
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mod<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec[i] - ((vec[i] / val) * val);
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mod for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1228
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mod<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec[i] - ((vec[i] / val) * val);
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mod for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1228
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mod<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec[i] - ((vec[i] / val) * val);
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mod for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1228
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mod<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec[i] - ((vec[i] / val) * val);
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mod for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mod" (primitive mod).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1228
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct mod<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec, const typename Vec::base_type val
            ) {
                using T = typename Vec::register_type;
                T result; //initialize the result
                #pragma unroll
                for(int i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = vec[i] - ((vec[i] / val) * val);
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of mod for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmax" (primitive hmax).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1254
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmax<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] > data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] > result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmax for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmax" (primitive hmax).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1254
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmax<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] > data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] > result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmax for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmax" (primitive hmax).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1254
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmax<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] > data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] > result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmax for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmax" (primitive hmax).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1254
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmax<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] > data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] > result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmax for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmax" (primitive hmax).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1254
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmax<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] > data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] > result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmax for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmax" (primitive hmax).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1254
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmax<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] > data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] > result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmax for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmax" (primitive hmax).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1254
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmax<simd<float, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] > data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] > result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmax for oneAPIfpgaRTL using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmax" (primitive hmax).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1254
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmax<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] > data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] > result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmax for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmax" (primitive hmax).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1254
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmax<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] > data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] > result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmax for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmax" (primitive hmax).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1254
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmax<simd<double, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] > data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] > result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmax for oneAPIfpgaRTL using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmin" (primitive hmin).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1275
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmin<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] < data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] < result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmin for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmin" (primitive hmin).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1275
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmin<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] < data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] < result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmin for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmin" (primitive hmin).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1275
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmin<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] < data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] < result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmin for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmin" (primitive hmin).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1275
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmin<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] < data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] < result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmin for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmin" (primitive hmin).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1275
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmin<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] < data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] < result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmin for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmin" (primitive hmin).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1275
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmin<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] < data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] < result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmin for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmin" (primitive hmin).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1275
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmin<simd<float, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] < data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] < result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmin for oneAPIfpgaRTL using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmin" (primitive hmin).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1275
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmin<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] < data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] < result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmin for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmin" (primitive hmin).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1275
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmin<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] < data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] < result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmin for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "hmin" (primitive hmin).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/calc.yaml::1275
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct hmin<simd<double, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpgaRTL, VectorSize>;
            
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
                const typename Vec::register_type data
            ) {
                  [[intel::fpga_register]] typename Vec::base_type result_vec[Vec::vector_element_count()];
                  #pragma unroll
                  for (size_t i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                    result_vec[i] = data[i<<1] < data[(i<<1)+1] ? data[i<<1] : data[(i<<1)+1];
                  }
                  unsigned current_result_position = Vec::vector_element_count()>>1;
                  unsigned previous_stage_start_idx = 0;
                  //#pragma unroll cilog2((Vec::vector_element_count()>>2))
                  #pragma unroll
                  [[intel::loop_coalesce(Vec::vector_element_count()), intel::ivdep(result_vec)]] for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    #pragma ivdep
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      result_vec[current_result_position + i] = 
                        result_vec[previous_stage_start_idx + (i<<1)] < result_vec[previous_stage_start_idx + (i<<1)+1]
                        ? result_vec[previous_stage_start_idx + (i<<1)]
                        : result_vec[previous_stage_start_idx + (i<<1)+1];
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                  }

                return result_vec[Vec::vector_element_count()-2];
            }
        };
    } // end of namespace functors for template specialization of hmin for oneAPIfpgaRTL using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_CALC_CALC_ONEAPIFPGARTL_HPP