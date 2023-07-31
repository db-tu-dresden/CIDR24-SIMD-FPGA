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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/definitions/convert/convert_oneAPIfpga.hpp
 * \date 2023-07-28
 * \brief Conversion primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_ONEAPIFPGA_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_ONEAPIFPGA_HPP

#include "../../declarations/convert.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/convert.yaml::141
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, oneAPIfpga, VectorSize>, simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            using ToType = simd<int32_t, oneAPIfpga, VectorSize>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                using U = typename ToType::register_type;
                U result{};
                #pragma unroll
                for (size_t i = 0; i < Vec::vector_element_count(); ++i ) {
                  result[i] = *reinterpret_cast< typename ToType::base_type const * >( &(data[i]) );
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/convert.yaml::141
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<float, oneAPIfpga, VectorSize>, simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpga, VectorSize>;
            using ToType = simd<uint32_t, oneAPIfpga, VectorSize>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                using U = typename ToType::register_type;
                U result{};
                #pragma unroll
                for (size_t i = 0; i < Vec::vector_element_count(); ++i ) {
                  result[i] = *reinterpret_cast< typename ToType::base_type const * >( &(data[i]) );
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for oneAPIfpga using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/convert.yaml::141
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, oneAPIfpga, VectorSize>, simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            using ToType = simd<int64_t, oneAPIfpga, VectorSize>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                using U = typename ToType::register_type;
                U result{};
                #pragma unroll
                for (size_t i = 0; i < Vec::vector_element_count(); ++i ) {
                  result[i] = *reinterpret_cast< typename ToType::base_type const * >( &(data[i]) );
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for oneAPIfpga using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "reinterpret" (primitive reinterpret).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/convert.yaml::141
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct reinterpret<simd<double, oneAPIfpga, VectorSize>, simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpga, VectorSize>;
            using ToType = simd<uint64_t, oneAPIfpga, VectorSize>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename ToType::register_type apply(
                const typename Vec::register_type data
            ) {
                using U = typename ToType::register_type;
                U result{};
                #pragma unroll
                for (size_t i = 0; i < Vec::vector_element_count(); ++i ) {
                  result[i] = *reinterpret_cast< typename ToType::base_type const * >( &(data[i]) );
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of reinterpret for oneAPIfpga using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_CONVERT_CONVERT_ONEAPIFPGA_HPP