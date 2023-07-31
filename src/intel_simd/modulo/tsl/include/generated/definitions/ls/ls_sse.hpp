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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/ls/ls_sse.hpp
 * \date 2023-07-22
 * \brief Load/Store primitives
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_SSE_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_SSE_HPP

#include <array>
#include "../../declarations/ls.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::57
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
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
                return _mm_load_si128(reinterpret_cast<__m128i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::57
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
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
                return _mm_load_si128(reinterpret_cast<__m128i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::57
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
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
                return _mm_load_si128(reinterpret_cast<__m128i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::57
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
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
                return _mm_load_si128(reinterpret_cast<__m128i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::57
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
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
                return _mm_load_si128(reinterpret_cast<__m128i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::57
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
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
                return _mm_load_si128(reinterpret_cast<__m128i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::57
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
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
                return _mm_load_si128(reinterpret_cast<__m128i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::57
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
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
                return _mm_load_si128(reinterpret_cast<__m128i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/ls.yaml::61
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
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
                return _mm_load_ps(assume_aligned<Vec::vector_alignment()>(memory));
            }
        };
    } // end of namespace functors for template specialization of load for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::65
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
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
                return _mm_load_pd(assume_aligned<Vec::vector_alignment()>(memory));
            }
        };
    } // end of namespace functors for template specialization of load for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::146
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
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
                return _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::146
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
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
                return _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::146
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
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
                return _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::146
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
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
                return _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::146
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
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
                return _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::146
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
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
                return _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::146
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
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
                return _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::146
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
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
                return _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/ls.yaml::150
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
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
                return _mm_loadu_ps(memory);
            }
        };
    } // end of namespace functors for template specialization of loadu for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::154
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
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
                return _mm_loadu_pd(memory);
            }
        };
    } // end of namespace functors for template specialization of loadu for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::234
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::234
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::234
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::234
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::234
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::234
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::234
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::234
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/ls.yaml::238
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
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
                _mm_store_ps(assume_aligned<Vec::vector_alignment()>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of store for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::242
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
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
                _mm_store_pd(assume_aligned<Vec::vector_alignment()>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of store for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::317
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
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
                _mm_storeu_si128(reinterpret_cast<__m128i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::317
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
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
                _mm_storeu_si128(reinterpret_cast<__m128i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::317
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
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
                _mm_storeu_si128(reinterpret_cast<__m128i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::317
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
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
                _mm_storeu_si128(reinterpret_cast<__m128i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::317
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
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
                _mm_storeu_si128(reinterpret_cast<__m128i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::317
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
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
                _mm_storeu_si128(reinterpret_cast<__m128i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::317
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
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
                _mm_storeu_si128(reinterpret_cast<__m128i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::317
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
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
                _mm_storeu_si128(reinterpret_cast<__m128i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/ls.yaml::321
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
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
                _mm_storeu_ps(memory, data);
            }
        };
    } // end of namespace functors for template specialization of storeu for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::325
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
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
                _mm_storeu_pd(memory, data);
            }
        };
    } // end of namespace functors for template specialization of storeu for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()>;
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
            static __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                tsl::store<Vec>(assume_aligned<Vec::vector_alignment()>(tmp.data()), data);
                return tmp;
            }
        };
    } // end of namespace functors for template specialization of to_array for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()>;
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
            static __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                tsl::store<Vec>(assume_aligned<Vec::vector_alignment()>(tmp.data()), data);
                return tmp;
            }
        };
    } // end of namespace functors for template specialization of to_array for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()>;
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
            static __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                tsl::store<Vec>(assume_aligned<Vec::vector_alignment()>(tmp.data()), data);
                return tmp;
            }
        };
    } // end of namespace functors for template specialization of to_array for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()>;
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
            static __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                tsl::store<Vec>(assume_aligned<Vec::vector_alignment()>(tmp.data()), data);
                return tmp;
            }
        };
    } // end of namespace functors for template specialization of to_array for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()>;
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
            static __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                tsl::store<Vec>(assume_aligned<Vec::vector_alignment()>(tmp.data()), data);
                return tmp;
            }
        };
    } // end of namespace functors for template specialization of to_array for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()>;
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
            static __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                tsl::store<Vec>(assume_aligned<Vec::vector_alignment()>(tmp.data()), data);
                return tmp;
            }
        };
    } // end of namespace functors for template specialization of to_array for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()>;
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
            static __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                tsl::store<Vec>(assume_aligned<Vec::vector_alignment()>(tmp.data()), data);
                return tmp;
            }
        };
    } // end of namespace functors for template specialization of to_array for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()>;
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
            static __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                tsl::store<Vec>(assume_aligned<Vec::vector_alignment()>(tmp.data()), data);
                return tmp;
            }
        };
    } // end of namespace functors for template specialization of to_array for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()>;
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
            static __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                tsl::store<Vec>(assume_aligned<Vec::vector_alignment()>(tmp.data()), data);
                return tmp;
            }
        };
    } // end of namespace functors for template specialization of to_array for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::378
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()>;
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
            static __attribute__((__aligned__(Vec::vector_alignment()))) std::array<typename Vec::base_type, Vec::vector_element_count()> apply(
                const typename Vec::register_type data
            ) {
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                tsl::store<Vec>(assume_aligned<Vec::vector_alignment()>(tmp.data()), data);
                return tmp;
            }
        };
    } // end of namespace functors for template specialization of to_array for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::443
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
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
                return _mm_set1_epi8(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::443
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
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
                return _mm_set1_epi16(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::443
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
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
                return _mm_set1_epi32(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::443
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
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
                return _mm_set1_epi8(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::443
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
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
                return _mm_set1_epi16(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::443
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
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
                return _mm_set1_epi32(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::447
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
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
                return _mm_set1_epi64x(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::447
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
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
                return _mm_set1_epi64x(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/ls.yaml::451
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
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
                return _mm_set1_ps(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::455
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
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
                return _mm_set1_pd(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::509
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
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
                return _mm_setzero_si128();
            }
        };
    } // end of namespace functors for template specialization of set_zero for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::509
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
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
                return _mm_setzero_si128();
            }
        };
    } // end of namespace functors for template specialization of set_zero for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::509
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
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
                return _mm_setzero_si128();
            }
        };
    } // end of namespace functors for template specialization of set_zero for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::509
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
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
                return _mm_setzero_si128();
            }
        };
    } // end of namespace functors for template specialization of set_zero for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::509
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
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
                return _mm_setzero_si128();
            }
        };
    } // end of namespace functors for template specialization of set_zero for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::509
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
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
                return _mm_setzero_si128();
            }
        };
    } // end of namespace functors for template specialization of set_zero for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::509
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
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
                return _mm_setzero_si128();
            }
        };
    } // end of namespace functors for template specialization of set_zero for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::509
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
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
                return _mm_setzero_si128();
            }
        };
    } // end of namespace functors for template specialization of set_zero for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::513
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
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
                return _mm_setzero_ps();
            }
        };
    } // end of namespace functors for template specialization of set_zero for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::513
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
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
                return _mm_setzero_pd();
            }
        };
    } // end of namespace functors for template specialization of set_zero for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::587
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            static constexpr bool parameters_queryable() {
                return false;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            template< typename... Ts >
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                Ts... args
            ) {
                return _mm_set_epi8(args...);
            }
        };
    } // end of namespace functors for template specialization of set for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::587
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            static constexpr bool parameters_queryable() {
                return false;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            template< typename... Ts >
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                Ts... args
            ) {
                return _mm_set_epi16(args...);
            }
        };
    } // end of namespace functors for template specialization of set for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::587
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            static constexpr bool parameters_queryable() {
                return false;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            template< typename... Ts >
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                Ts... args
            ) {
                return _mm_set_epi32(args...);
            }
        };
    } // end of namespace functors for template specialization of set for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::587
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            static constexpr bool parameters_queryable() {
                return false;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            template< typename... Ts >
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                Ts... args
            ) {
                return _mm_set_epi8(args...);
            }
        };
    } // end of namespace functors for template specialization of set for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::587
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            static constexpr bool parameters_queryable() {
                return false;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            template< typename... Ts >
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                Ts... args
            ) {
                return _mm_set_epi16(args...);
            }
        };
    } // end of namespace functors for template specialization of set for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::587
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            static constexpr bool parameters_queryable() {
                return false;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            template< typename... Ts >
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                Ts... args
            ) {
                return _mm_set_epi32(args...);
            }
        };
    } // end of namespace functors for template specialization of set for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::591
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            static constexpr bool parameters_queryable() {
                return false;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            template< typename... Ts >
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                Ts... args
            ) {
                return _mm_set_epi64x(args...);
            }
        };
    } // end of namespace functors for template specialization of set for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::591
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            static constexpr bool parameters_queryable() {
                return false;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            template< typename... Ts >
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                Ts... args
            ) {
                return _mm_set_epi64x(args...);
            }
        };
    } // end of namespace functors for template specialization of set for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse']
         *      Yaml Source: primitive_data/primitives/ls.yaml::595
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            static constexpr bool parameters_queryable() {
                return false;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            template< typename... Ts >
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                Ts... args
            ) {
                return _mm_set_ps(args...);
            }
        };
    } // end of namespace functors for template specialization of set for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::599
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            static constexpr bool parameters_queryable() {
                return false;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            template< typename... Ts >
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                Ts... args
            ) {
                return _mm_set_pd(args...);
            }
        };
    } // end of namespace functors for template specialization of set for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
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
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((T)Is)...
                  );
                };
                return seq_fun(std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of sequence for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
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
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((T)Is)...
                  );
                };
                return seq_fun(std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of sequence for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
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
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((T)Is)...
                  );
                };
                return seq_fun(std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of sequence for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
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
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((T)Is)...
                  );
                };
                return seq_fun(std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of sequence for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
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
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((T)Is)...
                  );
                };
                return seq_fun(std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of sequence for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
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
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((T)Is)...
                  );
                };
                return seq_fun(std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of sequence for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
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
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((T)Is)...
                  );
                };
                return seq_fun(std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of sequence for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
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
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((T)Is)...
                  );
                };
                return seq_fun(std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of sequence for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
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
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((T)Is)...
                  );
                };
                return seq_fun(std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of sequence for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
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
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((T)Is)...
                  );
                };
                return seq_fun(std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of sequence for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::715
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type, typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                typename Vec::base_type start, [[maybe_unused]] typename Vec::base_type stepwidth
            ) {
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  T const init, T const sw, std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((((T)(sizeof...(Is) - 1 - Is))*sw)+init)...
                  );
                };
                return seq_fun(start, stepwidth, std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of custom_sequence for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::715
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type, typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                typename Vec::base_type start, [[maybe_unused]] typename Vec::base_type stepwidth
            ) {
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  T const init, T const sw, std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((((T)(sizeof...(Is) - 1 - Is))*sw)+init)...
                  );
                };
                return seq_fun(start, stepwidth, std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of custom_sequence for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::715
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type, typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                typename Vec::base_type start, [[maybe_unused]] typename Vec::base_type stepwidth
            ) {
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  T const init, T const sw, std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((((T)(sizeof...(Is) - 1 - Is))*sw)+init)...
                  );
                };
                return seq_fun(start, stepwidth, std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of custom_sequence for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::715
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type, typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                typename Vec::base_type start, [[maybe_unused]] typename Vec::base_type stepwidth
            ) {
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  T const init, T const sw, std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((((T)(sizeof...(Is) - 1 - Is))*sw)+init)...
                  );
                };
                return seq_fun(start, stepwidth, std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of custom_sequence for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::715
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type, typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                typename Vec::base_type start, [[maybe_unused]] typename Vec::base_type stepwidth
            ) {
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  T const init, T const sw, std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((((T)(sizeof...(Is) - 1 - Is))*sw)+init)...
                  );
                };
                return seq_fun(start, stepwidth, std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of custom_sequence for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::715
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type, typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                typename Vec::base_type start, [[maybe_unused]] typename Vec::base_type stepwidth
            ) {
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  T const init, T const sw, std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((((T)(sizeof...(Is) - 1 - Is))*sw)+init)...
                  );
                };
                return seq_fun(start, stepwidth, std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of custom_sequence for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::715
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type, typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                typename Vec::base_type start, [[maybe_unused]] typename Vec::base_type stepwidth
            ) {
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  T const init, T const sw, std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((((T)(sizeof...(Is) - 1 - Is))*sw)+init)...
                  );
                };
                return seq_fun(start, stepwidth, std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of custom_sequence for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::715
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type, typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                typename Vec::base_type start, [[maybe_unused]] typename Vec::base_type stepwidth
            ) {
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  T const init, T const sw, std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((((T)(sizeof...(Is) - 1 - Is))*sw)+init)...
                  );
                };
                return seq_fun(start, stepwidth, std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of custom_sequence for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::715
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type, typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                typename Vec::base_type start, [[maybe_unused]] typename Vec::base_type stepwidth
            ) {
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  T const init, T const sw, std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((((T)(sizeof...(Is) - 1 - Is))*sw)+init)...
                  );
                };
                return seq_fun(start, stepwidth, std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of custom_sequence for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::715
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type, typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                typename Vec::base_type start, [[maybe_unused]] typename Vec::base_type stepwidth
            ) {
                using T = typename Vec::base_type;
                using sequence_type = typename std::conditional_t<std::is_integral_v<T>, T, uint64_t>;
                auto seq_fun= []<sequence_type... Is>(
                  T const init, T const sw, std::integer_sequence<sequence_type, Is...>
                ) {
                  return tsl::set<Vec>(
                    ((((T)(sizeof...(Is) - 1 - Is))*sw)+init)...
                  );
                };
                return seq_fun(start, stepwidth, std::make_integer_sequence<sequence_type, Vec::vector_element_count()>());
            }
        };
    } // end of namespace functors for template specialization of custom_sequence for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint8_t, sse>, simd<int8_t, sse>, N, Idof> {
            using Vec = simd<uint8_t, sse>;
            using IndicesType = simd<int8_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint8_t, sse>, simd<uint8_t, sse>, N, Idof> {
            using Vec = simd<uint8_t, sse>;
            using IndicesType = simd<uint8_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint16_t, sse>, simd<int16_t, sse>, N, Idof> {
            using Vec = simd<uint16_t, sse>;
            using IndicesType = simd<int16_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint16_t, sse>, simd<uint16_t, sse>, N, Idof> {
            using Vec = simd<uint16_t, sse>;
            using IndicesType = simd<uint16_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint32_t, sse>, simd<int32_t, sse>, N, Idof> {
            using Vec = simd<uint32_t, sse>;
            using IndicesType = simd<int32_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint32_t, sse>, simd<uint32_t, sse>, N, Idof> {
            using Vec = simd<uint32_t, sse>;
            using IndicesType = simd<uint32_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint64_t, sse>, simd<int64_t, sse>, N, Idof> {
            using Vec = simd<uint64_t, sse>;
            using IndicesType = simd<int64_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint64_t, sse>, simd<uint64_t, sse>, N, Idof> {
            using Vec = simd<uint64_t, sse>;
            using IndicesType = simd<uint64_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int8_t, sse>, simd<int8_t, sse>, N, Idof> {
            using Vec = simd<int8_t, sse>;
            using IndicesType = simd<int8_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int8_t, sse>, simd<uint8_t, sse>, N, Idof> {
            using Vec = simd<int8_t, sse>;
            using IndicesType = simd<uint8_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int16_t, sse>, simd<int16_t, sse>, N, Idof> {
            using Vec = simd<int16_t, sse>;
            using IndicesType = simd<int16_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int16_t, sse>, simd<uint16_t, sse>, N, Idof> {
            using Vec = simd<int16_t, sse>;
            using IndicesType = simd<uint16_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int32_t, sse>, simd<int32_t, sse>, N, Idof> {
            using Vec = simd<int32_t, sse>;
            using IndicesType = simd<int32_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int32_t, sse>, simd<uint32_t, sse>, N, Idof> {
            using Vec = simd<int32_t, sse>;
            using IndicesType = simd<uint32_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int64_t, sse>, simd<int64_t, sse>, N, Idof> {
            using Vec = simd<int64_t, sse>;
            using IndicesType = simd<int64_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int64_t, sse>, simd<uint64_t, sse>, N, Idof> {
            using Vec = simd<int64_t, sse>;
            using IndicesType = simd<uint64_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<float, sse>, simd<int32_t, sse>, N, Idof> {
            using Vec = simd<float, sse>;
            using IndicesType = simd<int32_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<float, sse>, simd<uint32_t, sse>, N, Idof> {
            using Vec = simd<float, sse>;
            using IndicesType = simd<uint32_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<double, sse>, simd<int64_t, sse>, N, Idof> {
            using Vec = simd<double, sse>;
            using IndicesType = simd<int64_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::812
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<double, sse>, simd<uint64_t, sse>, N, Idof> {
            using Vec = simd<double, sse>;
            using IndicesType = simd<uint64_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
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
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                auto const idx_array = tsl::to_array<IndicesType>(index);
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = *reinterpret_cast<typename Vec::base_type const *>(reinterpret_cast<char const*>(memory) + idx_array[i] * N);
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of gather for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::935
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<uint8_t, sse>, simd<uint8_t, sse>, N, Idof> {
            using Vec = simd<uint8_t, sse>;
            using IndicesType = simd<uint8_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const src_array = tsl::to_array<Vec>(source);
                auto const mask_array = tsl::to_array<Vec>(mask);
                if constexpr(N == 1) {
                  auto mem = reinterpret_cast<char const*>(memory);
                  for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                  }
                } else {
                  if constexpr(N == sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type const *>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                    }
                  } else {
                    auto mem = reinterpret_cast<char const*>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]*N];
                    }
                  }
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of mask_gather for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::935
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<uint16_t, sse>, simd<uint16_t, sse>, N, Idof> {
            using Vec = simd<uint16_t, sse>;
            using IndicesType = simd<uint16_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const src_array = tsl::to_array<Vec>(source);
                auto const mask_array = tsl::to_array<Vec>(mask);
                if constexpr(N == 1) {
                  auto mem = reinterpret_cast<char const*>(memory);
                  for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                  }
                } else {
                  if constexpr(N == sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type const *>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                    }
                  } else {
                    auto mem = reinterpret_cast<char const*>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]*N];
                    }
                  }
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of mask_gather for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::935
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<uint32_t, sse>, simd<uint32_t, sse>, N, Idof> {
            using Vec = simd<uint32_t, sse>;
            using IndicesType = simd<uint32_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const src_array = tsl::to_array<Vec>(source);
                auto const mask_array = tsl::to_array<Vec>(mask);
                if constexpr(N == 1) {
                  auto mem = reinterpret_cast<char const*>(memory);
                  for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                  }
                } else {
                  if constexpr(N == sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type const *>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                    }
                  } else {
                    auto mem = reinterpret_cast<char const*>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]*N];
                    }
                  }
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of mask_gather for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::935
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<uint64_t, sse>, simd<uint64_t, sse>, N, Idof> {
            using Vec = simd<uint64_t, sse>;
            using IndicesType = simd<uint64_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const src_array = tsl::to_array<Vec>(source);
                auto const mask_array = tsl::to_array<Vec>(mask);
                if constexpr(N == 1) {
                  auto mem = reinterpret_cast<char const*>(memory);
                  for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                  }
                } else {
                  if constexpr(N == sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type const *>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                    }
                  } else {
                    auto mem = reinterpret_cast<char const*>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]*N];
                    }
                  }
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of mask_gather for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::935
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<int8_t, sse>, simd<int8_t, sse>, N, Idof> {
            using Vec = simd<int8_t, sse>;
            using IndicesType = simd<int8_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const src_array = tsl::to_array<Vec>(source);
                auto const mask_array = tsl::to_array<Vec>(mask);
                if constexpr(N == 1) {
                  auto mem = reinterpret_cast<char const*>(memory);
                  for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                  }
                } else {
                  if constexpr(N == sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type const *>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                    }
                  } else {
                    auto mem = reinterpret_cast<char const*>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]*N];
                    }
                  }
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of mask_gather for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::935
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<int16_t, sse>, simd<int16_t, sse>, N, Idof> {
            using Vec = simd<int16_t, sse>;
            using IndicesType = simd<int16_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const src_array = tsl::to_array<Vec>(source);
                auto const mask_array = tsl::to_array<Vec>(mask);
                if constexpr(N == 1) {
                  auto mem = reinterpret_cast<char const*>(memory);
                  for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                  }
                } else {
                  if constexpr(N == sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type const *>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                    }
                  } else {
                    auto mem = reinterpret_cast<char const*>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]*N];
                    }
                  }
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of mask_gather for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::935
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<int32_t, sse>, simd<int32_t, sse>, N, Idof> {
            using Vec = simd<int32_t, sse>;
            using IndicesType = simd<int32_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const src_array = tsl::to_array<Vec>(source);
                auto const mask_array = tsl::to_array<Vec>(mask);
                if constexpr(N == 1) {
                  auto mem = reinterpret_cast<char const*>(memory);
                  for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                  }
                } else {
                  if constexpr(N == sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type const *>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                    }
                  } else {
                    auto mem = reinterpret_cast<char const*>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]*N];
                    }
                  }
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of mask_gather for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::935
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<int64_t, sse>, simd<int64_t, sse>, N, Idof> {
            using Vec = simd<int64_t, sse>;
            using IndicesType = simd<int64_t, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const src_array = tsl::to_array<Vec>(source);
                auto const mask_array = tsl::to_array<Vec>(mask);
                if constexpr(N == 1) {
                  auto mem = reinterpret_cast<char const*>(memory);
                  for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                  }
                } else {
                  if constexpr(N == sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type const *>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                    }
                  } else {
                    auto mem = reinterpret_cast<char const*>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]*N];
                    }
                  }
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of mask_gather for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::935
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<float, sse>, simd<float, sse>, N, Idof> {
            using Vec = simd<float, sse>;
            using IndicesType = simd<float, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const src_array = tsl::to_array<Vec>(source);
                auto const mask_array = tsl::to_array<Vec>(mask);
                if constexpr(N == 1) {
                  auto mem = reinterpret_cast<char const*>(memory);
                  for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                  }
                } else {
                  if constexpr(N == sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type const *>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                    }
                  } else {
                    auto mem = reinterpret_cast<char const*>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]*N];
                    }
                  }
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of mask_gather for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::935
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<double, sse>, simd<double, sse>, N, Idof> {
            using Vec = simd<double, sse>;
            using IndicesType = simd<double, sse>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_gather is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_size_B()) std::array<typename Vec::base_type, Vec::vector_element_count()> result{};
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const src_array = tsl::to_array<Vec>(source);
                auto const mask_array = tsl::to_array<Vec>(mask);
                if constexpr(N == 1) {
                  auto mem = reinterpret_cast<char const*>(memory);
                  for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                  }
                } else {
                  if constexpr(N == sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type const *>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]];
                    }
                  } else {
                    auto mem = reinterpret_cast<char const*>(memory);
                    for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                      result[i] = (mask_array[i] == 0) ? src_array[i] : mem[idx_array[i]*N];
                    }
                  }
                }
                return tsl::load<Vec>(result.data());
            }
        };
    } // end of namespace functors for template specialization of mask_gather for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1043
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<uint8_t, sse>, N, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if constexpr(N==sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                    mem[idx_array[i]] = val_array[i];
                  } else {
                    if constexpr(N==1) {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                    } else {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of scatter for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1043
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<uint16_t, sse>, N, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if constexpr(N==sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                    mem[idx_array[i]] = val_array[i];
                  } else {
                    if constexpr(N==1) {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                    } else {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of scatter for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1043
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<uint32_t, sse>, N, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if constexpr(N==sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                    mem[idx_array[i]] = val_array[i];
                  } else {
                    if constexpr(N==1) {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                    } else {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of scatter for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1043
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<uint64_t, sse>, N, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if constexpr(N==sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                    mem[idx_array[i]] = val_array[i];
                  } else {
                    if constexpr(N==1) {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                    } else {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of scatter for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1043
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<int8_t, sse>, N, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if constexpr(N==sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                    mem[idx_array[i]] = val_array[i];
                  } else {
                    if constexpr(N==1) {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                    } else {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of scatter for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1043
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<int16_t, sse>, N, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if constexpr(N==sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                    mem[idx_array[i]] = val_array[i];
                  } else {
                    if constexpr(N==1) {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                    } else {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of scatter for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1043
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<int32_t, sse>, N, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if constexpr(N==sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                    mem[idx_array[i]] = val_array[i];
                  } else {
                    if constexpr(N==1) {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                    } else {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of scatter for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1043
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<int64_t, sse>, N, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if constexpr(N==sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                    mem[idx_array[i]] = val_array[i];
                  } else {
                    if constexpr(N==1) {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                    } else {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of scatter for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1043
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<float, sse>, N, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if constexpr(N==sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                    mem[idx_array[i]] = val_array[i];
                  } else {
                    if constexpr(N==1) {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                    } else {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of scatter for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1043
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<double, sse>, N, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if constexpr(N==sizeof(typename Vec::base_type)) {
                    auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                    mem[idx_array[i]] = val_array[i];
                  } else {
                    if constexpr(N==1) {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                    } else {
                      *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of scatter for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1173
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<uint8_t, sse>, N, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const mask_array = tsl::to_array<Vec>(mask);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(mask_array[i] != 0) {
                    if constexpr(N==sizeof(typename Vec::base_type)) {
                      auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                      mem[idx_array[i]] = val_array[i];
                    } else {
                      if constexpr(N==1) {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                      } else {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                      }
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1173
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<uint16_t, sse>, N, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const mask_array = tsl::to_array<Vec>(mask);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(mask_array[i] != 0) {
                    if constexpr(N==sizeof(typename Vec::base_type)) {
                      auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                      mem[idx_array[i]] = val_array[i];
                    } else {
                      if constexpr(N==1) {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                      } else {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                      }
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1173
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<uint32_t, sse>, N, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const mask_array = tsl::to_array<Vec>(mask);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(mask_array[i] != 0) {
                    if constexpr(N==sizeof(typename Vec::base_type)) {
                      auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                      mem[idx_array[i]] = val_array[i];
                    } else {
                      if constexpr(N==1) {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                      } else {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                      }
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1173
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<uint64_t, sse>, N, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const mask_array = tsl::to_array<Vec>(mask);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(mask_array[i] != 0) {
                    if constexpr(N==sizeof(typename Vec::base_type)) {
                      auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                      mem[idx_array[i]] = val_array[i];
                    } else {
                      if constexpr(N==1) {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                      } else {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                      }
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1173
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<int8_t, sse>, N, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const mask_array = tsl::to_array<Vec>(mask);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(mask_array[i] != 0) {
                    if constexpr(N==sizeof(typename Vec::base_type)) {
                      auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                      mem[idx_array[i]] = val_array[i];
                    } else {
                      if constexpr(N==1) {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                      } else {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                      }
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1173
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<int16_t, sse>, N, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const mask_array = tsl::to_array<Vec>(mask);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(mask_array[i] != 0) {
                    if constexpr(N==sizeof(typename Vec::base_type)) {
                      auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                      mem[idx_array[i]] = val_array[i];
                    } else {
                      if constexpr(N==1) {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                      } else {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                      }
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1173
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<int32_t, sse>, N, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const mask_array = tsl::to_array<Vec>(mask);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(mask_array[i] != 0) {
                    if constexpr(N==sizeof(typename Vec::base_type)) {
                      auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                      mem[idx_array[i]] = val_array[i];
                    } else {
                      if constexpr(N==1) {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                      } else {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                      }
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1173
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<int64_t, sse>, N, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const mask_array = tsl::to_array<Vec>(mask);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(mask_array[i] != 0) {
                    if constexpr(N==sizeof(typename Vec::base_type)) {
                      auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                      mem[idx_array[i]] = val_array[i];
                    } else {
                      if constexpr(N==1) {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                      } else {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                      }
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1173
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<float, sse>, N, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const mask_array = tsl::to_array<Vec>(mask);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(mask_array[i] != 0) {
                    if constexpr(N==sizeof(typename Vec::base_type)) {
                      auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                      mem[idx_array[i]] = val_array[i];
                    } else {
                      if constexpr(N==1) {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                      } else {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                      }
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1173
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<double, sse>, N, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return false;
            }
            static constexpr bool native_supported() {
                return false;
            }
            TSL_NO_NATIVE_SUPPORT_WARNING
            TSL_FORCE_INLINE 
            static void apply(
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive mask_scatter is not supported by your hardware natively while it is forced by using native" );

                auto const val_array = tsl::to_array<Vec>(data);
                using offsetExt = typename Vec::transform_extension<Vec::offset_base_type>;
                auto const idx_array = tsl::to_array<offsetExt>(index);
                auto const mask_array = tsl::to_array<Vec>(mask);
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(mask_array[i] != 0) {
                    if constexpr(N==sizeof(typename Vec::base_type)) {
                      auto mem = reinterpret_cast<typename Vec::base_type *>(memory);
                      mem[idx_array[i]] = val_array[i];
                    } else {
                      if constexpr(N==1) {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[idx_array[i]]) = val_array[i];
                      } else {
                        *reinterpret_cast<typename Vec::base_type*>(&reinterpret_cast<uint8_t*>(memory)[(idx_array[i]<<(cilog2(N)))]) = val_array[i];
                      }
                    }
                  }
                }
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1554
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::base_type value
            ) {
                return _mm_mask_set1_epi8(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1554
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::base_type value
            ) {
                return _mm_mask_set1_epi16(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1554
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::base_type value
            ) {
                return _mm_mask_set1_epi8(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1554
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::base_type value
            ) {
                return _mm_mask_set1_epi16(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1558
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::base_type value
            ) {
                return _mm_mask_set1_epi32(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1558
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::base_type value
            ) {
                return _mm_mask_set1_epi64(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1558
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::base_type value
            ) {
                return _mm_mask_set1_epi32(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1558
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::base_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::base_type value
            ) {
                return _mm_mask_set1_epi64(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1562
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::base_type>;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::base_type value
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive masked_set1 is not supported by your hardware natively while it is forced by using native" );

                return _mm_castsi128_ps(_mm_mask_set1_epi32(_mm_castps_si128(src), mask, *reinterpret_cast<const int32_t*>(&value)));
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['avx', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1567
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::base_type>;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::base_type value
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive masked_set1 is not supported by your hardware natively while it is forced by using native" );

                return _mm_castsi128_pd(_mm_mask_set1_epi64(_mm_castpd_si128(src), mask, *reinterpret_cast<const int64_t*>(&value)));
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1643
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src
            ) {
                return _mm_maskz_mov_epi8(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1643
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src
            ) {
                return _mm_maskz_mov_epi16(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1643
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src
            ) {
                return _mm_maskz_mov_epi8(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1643
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src
            ) {
                return _mm_maskz_mov_epi16(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src
            ) {
                return _mm_maskz_mov_epi32(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src
            ) {
                return _mm_maskz_mov_epi64(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src
            ) {
                return _mm_maskz_mov_epi32(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1647
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src
            ) {
                return _mm_maskz_mov_epi64(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1651
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src
            ) {
                return _mm_maskz_mov_ps(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1651
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src
            ) {
                return _mm_maskz_mov_pd(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1731
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::register_type data
            ) {
                return _mm_mask_mov_epi8(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1731
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::register_type data
            ) {
                return _mm_mask_mov_epi16(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1731
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::register_type data
            ) {
                return _mm_mask_mov_epi8(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1731
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::register_type data
            ) {
                return _mm_mask_mov_epi16(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1735
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::register_type data
            ) {
                return _mm_mask_mov_epi32(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1735
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::register_type data
            ) {
                return _mm_mask_mov_epi64(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1735
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::register_type data
            ) {
                return _mm_mask_mov_epi32(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1735
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::register_type data
            ) {
                return _mm_mask_mov_epi64(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1739
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::register_type data
            ) {
                return _mm_mask_mov_ps(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1739
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const typename Vec::imask_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
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
                const typename Vec::register_type src, const typename Vec::imask_type mask, const typename Vec::register_type data
            ) {
                return _mm_mask_mov_pd(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1857
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint8_t, sse>, Index, Idof> {
            using Vec = simd<uint8_t, sse>;
            
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
                return data[Index];
                //return _mm_extract_epi8(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1857
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint32_t, sse>, Index, Idof> {
            using Vec = simd<uint32_t, sse>;
            
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
                return data[Index];
                //return _mm_extract_epi32(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1857
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint64_t, sse>, Index, Idof> {
            using Vec = simd<uint64_t, sse>;
            
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
                return data[Index];
                //return _mm_extract_epi64(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1857
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int8_t, sse>, Index, Idof> {
            using Vec = simd<int8_t, sse>;
            
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
                return data[Index];
                //return _mm_extract_epi8(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1857
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int32_t, sse>, Index, Idof> {
            using Vec = simd<int32_t, sse>;
            
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
                return data[Index];
                //return _mm_extract_epi32(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse4_1']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1857
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int64_t, sse>, Index, Idof> {
            using Vec = simd<int64_t, sse>;
            
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
                return data[Index];
                //return _mm_extract_epi64(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1863
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint16_t, sse>, Index, Idof> {
            using Vec = simd<uint16_t, sse>;
            
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
                return data[Index];
                //return _mm_extract_epi16(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1863
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int16_t, sse>, Index, Idof> {
            using Vec = simd<int16_t, sse>;
            
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
                return data[Index];
                //return _mm_extract_epi16(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1869
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<float, sse>, Index, Idof> {
            using Vec = simd<float, sse>;
            
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
                return data[Index];
                /*__m128 temp = _mm_shuffle_ps(data, data, _MM_SHUFFLE(Index, Index, Index, Index));
                return _mm_cvtss_f32(temp);*/
            }
        };
    } // end of namespace functors for template specialization of extract_value for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1876
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<double, sse>, Index, Idof> {
            using Vec = simd<double, sse>;
            
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
                return data[Index];
                /*__m128d temp = _mm_shuffle_pd(data, data, Index);
                return _mm_cvtsd_f64(temp);*/
            }
        };
    } // end of namespace functors for template specialization of extract_value for sse using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_SSE_HPP