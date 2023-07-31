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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/mask/mask_scalar.hpp
 * \date 2023-07-22
 * \brief Mask related primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_SCALAR_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_SCALAR_HPP

#include "../../declarations/mask.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return (vec_mask)? 1 : 0;
            }
        };
    } // end of namespace functors for template specialization of to_integral for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return (vec_mask)? 1 : 0;
            }
        };
    } // end of namespace functors for template specialization of to_integral for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return (vec_mask)? 1 : 0;
            }
        };
    } // end of namespace functors for template specialization of to_integral for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return (vec_mask)? 1 : 0;
            }
        };
    } // end of namespace functors for template specialization of to_integral for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return (vec_mask)? 1 : 0;
            }
        };
    } // end of namespace functors for template specialization of to_integral for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return (vec_mask)? 1 : 0;
            }
        };
    } // end of namespace functors for template specialization of to_integral for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return (vec_mask)? 1 : 0;
            }
        };
    } // end of namespace functors for template specialization of to_integral for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return (vec_mask)? 1 : 0;
            }
        };
    } // end of namespace functors for template specialization of to_integral for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: scalar.
         *        Data Type: float
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<float, scalar>, Idof> {
            using Vec = simd<float, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return (vec_mask)? 1 : 0;
            }
        };
    } // end of namespace functors for template specialization of to_integral for scalar using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_integral" (primitive to_integral).
         * @details:
         * Target Extension: scalar.
         *        Data Type: double
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_integral<simd<double, scalar>, Idof> {
            using Vec = simd<double, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                const typename Vec::mask_type vec_mask
            ) {
                return (vec_mask)? 1 : 0;
            }
        };
    } // end of namespace functors for template specialization of to_integral for scalar using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_mask for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_mask for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_mask for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_mask for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_mask for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_mask for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_mask for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_mask for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: scalar.
         *        Data Type: float
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<float, scalar>, Idof> {
            using Vec = simd<float, scalar>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_mask for scalar using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_mask" (primitive to_mask).
         * @details:
         * Target Extension: scalar.
         *        Data Type: double
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_mask<simd<double, scalar>, Idof> {
            using Vec = simd<double, scalar>;
            
            using return_type = typename Vec::mask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask
            ) {
                return mask;
            }
        };
    } // end of namespace functors for template specialization of to_mask for scalar using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::932
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return true;
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::932
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return true;
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::932
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return true;
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::932
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return true;
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::932
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return true;
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::932
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return true;
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::932
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return true;
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::932
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return true;
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: scalar.
         *        Data Type: float
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::932
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<float, scalar>, Idof> {
            using Vec = simd<float, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return true;
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for scalar using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_true" (primitive integral_all_true).
         * @details:
         * Target Extension: scalar.
         *        Data Type: double
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::932
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_true<simd<double, scalar>, Idof> {
            using Vec = simd<double, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return true;
            }
        };
    } // end of namespace functors for template specialization of integral_all_true for scalar using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::959
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint8_t, scalar>, Idof> {
            using Vec = simd<uint8_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return false;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for scalar using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::959
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint16_t, scalar>, Idof> {
            using Vec = simd<uint16_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return false;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for scalar using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::959
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint32_t, scalar>, Idof> {
            using Vec = simd<uint32_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return false;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for scalar using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: scalar.
         *        Data Type: uint64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::959
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<uint64_t, scalar>, Idof> {
            using Vec = simd<uint64_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return false;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for scalar using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int8_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::959
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int8_t, scalar>, Idof> {
            using Vec = simd<int8_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return false;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for scalar using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int16_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::959
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int16_t, scalar>, Idof> {
            using Vec = simd<int16_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return false;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for scalar using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int32_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::959
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int32_t, scalar>, Idof> {
            using Vec = simd<int32_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return false;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for scalar using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: scalar.
         *        Data Type: int64_t
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::959
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<int64_t, scalar>, Idof> {
            using Vec = simd<int64_t, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return false;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for scalar using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: scalar.
         *        Data Type: float
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::959
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<float, scalar>, Idof> {
            using Vec = simd<float, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return false;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for scalar using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "integral_all_false" (primitive integral_all_false).
         * @details:
         * Target Extension: scalar.
         *        Data Type: double
         *  Extension Flags: []
         *      Yaml Source: primitive_data/primitives/mask.yaml::959
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct integral_all_false<simd<double, scalar>, Idof> {
            using Vec = simd<double, scalar>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                
            ) {
                return false;
            }
        };
    } // end of namespace functors for template specialization of integral_all_false for scalar using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MASK_MASK_SCALAR_HPP