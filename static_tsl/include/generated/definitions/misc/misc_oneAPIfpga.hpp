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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/definitions/misc/misc_oneAPIfpga.hpp
 * \date 2023-07-28
 * \brief Miscellaneous primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_MISC_MISC_ONEAPIFPGA_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_MISC_MISC_ONEAPIFPGA_HPP

#include "../../declarations/misc.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/misc.yaml::109
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint8_t, oneAPIfpga, VectorSize>, Idof> {
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                typename Vec::register_type result{};
                tsl::oneAPIfpgaFun::details::conflictReduce<Vec>(result, data, std::make_index_sequence<Vec::vector_element_count()-1>{});
                result[0] = 0;
                return result;
            }
        };
    } // end of namespace functors for template specialization of conflict for oneAPIfpga using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/misc.yaml::109
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int8_t, oneAPIfpga, VectorSize>, Idof> {
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                typename Vec::register_type result{};
                tsl::oneAPIfpgaFun::details::conflictReduce<Vec>(result, data, std::make_index_sequence<Vec::vector_element_count()-1>{});
                result[0] = 0;
                return result;
            }
        };
    } // end of namespace functors for template specialization of conflict for oneAPIfpga using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/misc.yaml::109
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint16_t, oneAPIfpga, VectorSize>, Idof> {
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                typename Vec::register_type result{};
                tsl::oneAPIfpgaFun::details::conflictReduce<Vec>(result, data, std::make_index_sequence<Vec::vector_element_count()-1>{});
                result[0] = 0;
                return result;
            }
        };
    } // end of namespace functors for template specialization of conflict for oneAPIfpga using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/misc.yaml::109
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int16_t, oneAPIfpga, VectorSize>, Idof> {
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                typename Vec::register_type result{};
                tsl::oneAPIfpgaFun::details::conflictReduce<Vec>(result, data, std::make_index_sequence<Vec::vector_element_count()-1>{});
                result[0] = 0;
                return result;
            }
        };
    } // end of namespace functors for template specialization of conflict for oneAPIfpga using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/misc.yaml::109
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint32_t, oneAPIfpga, VectorSize>, Idof> {
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                typename Vec::register_type result{};
                tsl::oneAPIfpgaFun::details::conflictReduce<Vec>(result, data, std::make_index_sequence<Vec::vector_element_count()-1>{});
                result[0] = 0;
                return result;
            }
        };
    } // end of namespace functors for template specialization of conflict for oneAPIfpga using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/misc.yaml::109
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int32_t, oneAPIfpga, VectorSize>, Idof> {
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                typename Vec::register_type result{};
                tsl::oneAPIfpgaFun::details::conflictReduce<Vec>(result, data, std::make_index_sequence<Vec::vector_element_count()-1>{});
                result[0] = 0;
                return result;
            }
        };
    } // end of namespace functors for template specialization of conflict for oneAPIfpga using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/misc.yaml::109
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint64_t, oneAPIfpga, VectorSize>, Idof> {
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                typename Vec::register_type result{};
                tsl::oneAPIfpgaFun::details::conflictReduce<Vec>(result, data, std::make_index_sequence<Vec::vector_element_count()-1>{});
                result[0] = 0;
                return result;
            }
        };
    } // end of namespace functors for template specialization of conflict for oneAPIfpga using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: oneAPIfpga.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/misc.yaml::109
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int64_t, oneAPIfpga, VectorSize>, Idof> {
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                typename Vec::register_type result{};
                tsl::oneAPIfpgaFun::details::conflictReduce<Vec>(result, data, std::make_index_sequence<Vec::vector_element_count()-1>{});
                result[0] = 0;
                return result;
            }
        };
    } // end of namespace functors for template specialization of conflict for oneAPIfpga using int64_t.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_MISC_MISC_ONEAPIFPGA_HPP