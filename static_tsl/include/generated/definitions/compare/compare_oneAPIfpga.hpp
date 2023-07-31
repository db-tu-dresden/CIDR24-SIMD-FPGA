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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/definitions/compare/compare_oneAPIfpga.hpp
 * \date 2023-07-28
 * \brief Compare primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_ONEAPIFPGA_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_ONEAPIFPGA_HPP

#include "../../declarations/compare.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::134
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of equal for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::134
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of equal for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::134
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of equal for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::134
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of equal for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::134
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of equal for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::134
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of equal for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::134
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct equal<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of equal for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::134
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct equal<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of equal for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::134
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct equal<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of equal for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "equal" (primitive equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::134
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct equal<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of equal for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::293
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? 0 : checker;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of nequal for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::293
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? 0 : checker;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of nequal for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::293
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? 0 : checker;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of nequal for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::293
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? 0 : checker;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of nequal for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::293
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? 0 : checker;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of nequal for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::293
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? 0 : checker;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of nequal for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::293
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? 0 : checker;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of nequal for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::293
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? 0 : checker;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of nequal for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::293
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? 0 : checker;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of nequal for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "nequal" (primitive nequal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::293
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct nequal<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] == vec_b[i]) ? 0 : checker;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of nequal for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::371
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = ((vec_data[i] >= vec_min[i]) && (vec_data[i] <= vec_max[i])) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::371
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = ((vec_data[i] >= vec_min[i]) && (vec_data[i] <= vec_max[i])) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::371
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = ((vec_data[i] >= vec_min[i]) && (vec_data[i] <= vec_max[i])) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::371
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = ((vec_data[i] >= vec_min[i]) && (vec_data[i] <= vec_max[i])) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::371
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = ((vec_data[i] >= vec_min[i]) && (vec_data[i] <= vec_max[i])) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::371
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = ((vec_data[i] >= vec_min[i]) && (vec_data[i] <= vec_max[i])) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::371
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = ((vec_data[i] >= vec_min[i]) && (vec_data[i] <= vec_max[i])) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::371
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = ((vec_data[i] >= vec_min[i]) && (vec_data[i] <= vec_max[i])) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::371
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = ((vec_data[i] >= vec_min[i]) && (vec_data[i] <= vec_max[i])) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "between_inclusive" (primitive between_inclusive).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::371
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct between_inclusive<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::register_type, typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = ((vec_data[i] >= vec_min[i]) && (vec_data[i] <= vec_max[i])) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of between_inclusive for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::516
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] < vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::516
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] < vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::516
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] < vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::516
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] < vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::516
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] < vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::516
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] < vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::516
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] < vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::516
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] < vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::516
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] < vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than" (primitive less_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::516
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] < vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::658
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] > vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::658
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] > vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::658
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] > vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::658
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] > vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::658
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] > vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::658
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] > vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::658
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] > vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::658
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] > vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::658
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] > vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than" (primitive greater_than).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::658
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] > vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::811
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] <= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::811
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] <= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::811
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] <= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::811
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] <= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::811
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] <= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::811
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] <= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::811
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] <= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::811
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] <= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::811
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] <= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "less_than_or_equal" (primitive less_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::811
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] <= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of less_than_or_equal for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::965
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] >= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::965
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] >= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::965
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] >= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::965
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] >= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::965
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] >= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::965
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] >= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::965
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] >= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::965
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker = ~0;
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] >= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for oneAPIfpga using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::965
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<float, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] >= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "greater_than_or_equal" (primitive greater_than_or_equal).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/compare.yaml::965
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal<simd<double, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            
            using return_type = typename Vec::mask_type;
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
            static typename Vec::mask_type apply(
                const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
            ) {
                using T = typename Vec::register_type;
                T result{};
                // Create a value with all bits set to 1, regardless of underlying type
                typename Vec::base_type checker;
                memset((void*)&checker, 0xff, sizeof(checker));
                //
                #pragma unroll
                for(size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = (vec_a[i] >= vec_b[i]) ? checker : 0;
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of greater_than_or_equal for oneAPIfpga using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPARE_COMPARE_ONEAPIFPGA_HPP