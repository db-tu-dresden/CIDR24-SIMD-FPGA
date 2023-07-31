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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/definitions/mask/mask_oneAPIfpgaRTL.hpp
 * \date 2023-07-28
 * \brief Mask related primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_ONEAPIFPGARTL_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_ONEAPIFPGARTL_HPP

#include "../../declarations/mask.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/mask.yaml::330
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::mask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_vector for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/mask.yaml::330
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::mask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_vector for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/mask.yaml::330
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::mask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_vector for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/mask.yaml::330
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::mask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_vector for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/mask.yaml::330
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::mask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_vector for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/mask.yaml::330
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::mask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_vector for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/mask.yaml::330
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::mask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_vector for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/mask.yaml::330
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::mask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_vector for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: float
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/mask.yaml::330
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<float, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<float, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::mask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_vector for oneAPIfpgaRTL using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_vector" (primitive to_vector).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: double
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/mask.yaml::330
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct to_vector<simd<double, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<double, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::mask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_vector for oneAPIfpgaRTL using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_ONEAPIFPGARTL_HPP