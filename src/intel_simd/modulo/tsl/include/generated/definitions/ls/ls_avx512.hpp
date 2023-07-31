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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/ls/ls_avx512.hpp
 * \date 2023-07-22
 * \brief Load/Store primitives
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_AVX512_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_AVX512_HPP

#include <cstring>
#include "../../declarations/ls.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::39
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_load_si512(reinterpret_cast<void const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::39
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_load_si512(reinterpret_cast<void const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::39
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_load_si512(reinterpret_cast<void const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::39
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_load_si512(reinterpret_cast<void const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::39
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_load_si512(reinterpret_cast<void const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::39
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_load_si512(reinterpret_cast<void const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::39
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_load_si512(reinterpret_cast<void const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::39
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_load_si512(reinterpret_cast<void const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_load_ps(reinterpret_cast<void const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::43
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_load_pd(reinterpret_cast<void const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::128
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_loadu_si512(reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::128
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_loadu_si512(reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::128
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_loadu_si512(reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::128
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_loadu_si512(reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::128
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_loadu_si512(reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::128
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_loadu_si512(reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::128
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_loadu_si512(reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::128
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_loadu_si512(reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::132
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_loadu_ps(reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::132
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_loadu_pd(reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of loadu for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::216
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                _mm512_store_si512(reinterpret_cast<void*>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::216
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                _mm512_store_si512(reinterpret_cast<void*>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::216
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                _mm512_store_si512(reinterpret_cast<void*>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::216
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                _mm512_store_si512(reinterpret_cast<void*>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::216
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                _mm512_store_si512(reinterpret_cast<void*>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::216
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                _mm512_store_si512(reinterpret_cast<void*>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::216
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                _mm512_store_si512(reinterpret_cast<void*>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::216
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                _mm512_store_si512(reinterpret_cast<void*>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::220
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                _mm512_store_ps(reinterpret_cast<void*>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::220
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                _mm512_store_pd(reinterpret_cast<void*>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                _mm512_storeu_si512(reinterpret_cast<void*>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                _mm512_storeu_si512(reinterpret_cast<void*>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                _mm512_storeu_si512(reinterpret_cast<void*>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                _mm512_storeu_si512(reinterpret_cast<void*>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                _mm512_storeu_si512(reinterpret_cast<void*>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                _mm512_storeu_si512(reinterpret_cast<void*>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                _mm512_storeu_si512(reinterpret_cast<void*>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                _mm512_storeu_si512(reinterpret_cast<void*>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::303
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                _mm512_storeu_ps(reinterpret_cast<void*>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::303
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                _mm512_storeu_pd(reinterpret_cast<void*>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::362
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
    } // end of namespace functors for template specialization of to_array for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::362
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
    } // end of namespace functors for template specialization of to_array for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::362
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
    } // end of namespace functors for template specialization of to_array for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::362
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
    } // end of namespace functors for template specialization of to_array for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::362
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
    } // end of namespace functors for template specialization of to_array for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::362
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
    } // end of namespace functors for template specialization of to_array for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::362
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
    } // end of namespace functors for template specialization of to_array for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::362
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
    } // end of namespace functors for template specialization of to_array for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::362
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
    } // end of namespace functors for template specialization of to_array for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::362
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
    } // end of namespace functors for template specialization of to_array for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::421
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_set1_epi8(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::421
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_set1_epi16(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::421
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_set1_epi32(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::421
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_set1_epi64(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::421
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_set1_epi8(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::421
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_set1_epi16(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::421
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_set1_epi32(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::421
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_set1_epi64(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::425
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_set1_ps(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::425
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_set1_pd(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_setzero_si512();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_setzero_si512();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_setzero_si512();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_setzero_si512();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_setzero_si512();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_setzero_si512();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_setzero_si512();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::491
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_setzero_si512();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::495
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_setzero_ps();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::495
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_setzero_pd();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::565
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_set_epi8(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::565
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_set_epi16(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::565
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_set_epi32(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::565
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_set_epi64(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::565
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_set_epi8(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::565
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_set_epi16(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::565
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_set_epi32(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::565
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_set_epi64(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::569
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_set_ps(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::569
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_set_pd(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
    } // end of namespace functors for template specialization of sequence for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
    } // end of namespace functors for template specialization of sequence for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
    } // end of namespace functors for template specialization of sequence for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
    } // end of namespace functors for template specialization of sequence for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
    } // end of namespace functors for template specialization of sequence for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
    } // end of namespace functors for template specialization of sequence for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
    } // end of namespace functors for template specialization of sequence for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
    } // end of namespace functors for template specialization of sequence for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
    } // end of namespace functors for template specialization of sequence for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
    } // end of namespace functors for template specialization of sequence for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::685
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::685
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::685
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::685
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::685
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::685
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::685
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::685
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::685
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::685
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint32_t, avx512>, simd<int32_t, avx512>, N, Idof> {
            using Vec = simd<uint32_t, avx512>;
            using IndicesType = simd<int32_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_epi32(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint32_t, avx512>, simd<uint32_t, avx512>, N, Idof> {
            using Vec = simd<uint32_t, avx512>;
            using IndicesType = simd<uint32_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_epi32(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int32_t, avx512>, simd<int32_t, avx512>, N, Idof> {
            using Vec = simd<int32_t, avx512>;
            using IndicesType = simd<int32_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_epi32(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int32_t, avx512>, simd<uint32_t, avx512>, N, Idof> {
            using Vec = simd<int32_t, avx512>;
            using IndicesType = simd<uint32_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_epi32(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint64_t, avx512>, simd<int64_t, avx512>, N, Idof> {
            using Vec = simd<uint64_t, avx512>;
            using IndicesType = simd<int64_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i64gather_epi64(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint64_t, avx512>, simd<uint64_t, avx512>, N, Idof> {
            using Vec = simd<uint64_t, avx512>;
            using IndicesType = simd<uint64_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i64gather_epi64(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int64_t, avx512>, simd<int64_t, avx512>, N, Idof> {
            using Vec = simd<int64_t, avx512>;
            using IndicesType = simd<int64_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i64gather_epi64(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int64_t, avx512>, simd<uint64_t, avx512>, N, Idof> {
            using Vec = simd<int64_t, avx512>;
            using IndicesType = simd<uint64_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i64gather_epi64(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<float, avx512>, simd<int32_t, avx512>, N, Idof> {
            using Vec = simd<float, avx512>;
            using IndicesType = simd<int32_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_ps(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<float, avx512>, simd<uint32_t, avx512>, N, Idof> {
            using Vec = simd<float, avx512>;
            using IndicesType = simd<uint32_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_ps(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<double, avx512>, simd<int64_t, avx512>, N, Idof> {
            using Vec = simd<double, avx512>;
            using IndicesType = simd<int64_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i64gather_pd(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::787
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<double, avx512>, simd<uint64_t, avx512>, N, Idof> {
            using Vec = simd<double, avx512>;
            using IndicesType = simd<uint64_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i64gather_pd(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::801
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint64_t, avx512>, simd<int32_t, avx2>, N, Idof> {
            using Vec = simd<uint64_t, avx512>;
            using IndicesType = simd<int32_t, avx2>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_epi64(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::801
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<uint64_t, avx512>, simd<uint32_t, avx2>, N, Idof> {
            using Vec = simd<uint64_t, avx512>;
            using IndicesType = simd<uint32_t, avx2>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_epi64(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::801
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int64_t, avx512>, simd<int32_t, avx2>, N, Idof> {
            using Vec = simd<int64_t, avx512>;
            using IndicesType = simd<int32_t, avx2>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_epi64(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::801
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<int64_t, avx512>, simd<uint32_t, avx2>, N, Idof> {
            using Vec = simd<int64_t, avx512>;
            using IndicesType = simd<uint32_t, avx2>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_epi64(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::801
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<double, avx512>, simd<int32_t, avx2>, N, Idof> {
            using Vec = simd<double, avx512>;
            using IndicesType = simd<int32_t, avx2>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_pd(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::801
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct gather<simd<double, avx512>, simd<uint32_t, avx2>, N, Idof> {
            using Vec = simd<double, avx512>;
            using IndicesType = simd<uint32_t, avx2>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const void*, const typename IndicesType::register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const void* memory, const typename IndicesType::register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_i32gather_pd(index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of gather for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::898
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<uint32_t, avx512>, simd<uint32_t, avx512>, N, Idof> {
            using Vec = simd<uint32_t, avx512>;
            using IndicesType = simd<uint32_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_mask_i32gather_epi32(source, mask, index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::898
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<uint64_t, avx512>, simd<uint64_t, avx512>, N, Idof> {
            using Vec = simd<uint64_t, avx512>;
            using IndicesType = simd<uint64_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_mask_i64gather_epi64(source, mask, index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::898
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<int32_t, avx512>, simd<int32_t, avx512>, N, Idof> {
            using Vec = simd<int32_t, avx512>;
            using IndicesType = simd<int32_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_mask_i32gather_epi32(source, mask, index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::898
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<int64_t, avx512>, simd<int64_t, avx512>, N, Idof> {
            using Vec = simd<int64_t, avx512>;
            using IndicesType = simd<int64_t, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_mask_i64gather_epi64(source, mask, index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::903
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<float, avx512>, simd<float, avx512>, N, Idof> {
            using Vec = simd<float, avx512>;
            using IndicesType = simd<float, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_mask_i32gather_ps(source, mask, index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::908
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<double, avx512>, simd<double, avx512>, N, Idof> {
            using Vec = simd<double, avx512>;
            using IndicesType = simd<double, avx512>;
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const void*, const typename IndicesType::offset_base_register_type, std::integral_constant<int, N>>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type mask, const typename Vec::register_type source, const void* memory, const typename IndicesType::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                return _mm512_mask_i64gather_pd(source, mask, index, memory, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1004
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<uint32_t, avx512>, N, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_i32scatter_epi32(
                   memory, index, data, N
                );
            }
        };
    } // end of namespace functors for template specialization of scatter for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1004
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<int32_t, avx512>, N, Idof> {
            using Vec = simd<int32_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_i32scatter_epi32(
                   memory, index, data, N
                );
            }
        };
    } // end of namespace functors for template specialization of scatter for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1004
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<uint64_t, avx512>, N, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_i64scatter_epi64(
                   memory, index, data, N
                );
            }
        };
    } // end of namespace functors for template specialization of scatter for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1004
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<int64_t, avx512>, N, Idof> {
            using Vec = simd<int64_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_i64scatter_epi64(
                   memory, index, data, N
                );
            }
        };
    } // end of namespace functors for template specialization of scatter for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1011
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<float, avx512>, N, Idof> {
            using Vec = simd<float, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_i32scatter_ps(memory, index, data, N);
            }
        };
    } // end of namespace functors for template specialization of scatter for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1015
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<double, avx512>, N, Idof> {
            using Vec = simd<double, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_i64scatter_pd(memory, index, data, N);
            }
        };
    } // end of namespace functors for template specialization of scatter for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1131
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<uint32_t, avx512>, N, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_mask_i32scatter_epi32(
                   memory, mask, index, data, N
                );
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1131
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<int32_t, avx512>, N, Idof> {
            using Vec = simd<int32_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_mask_i32scatter_epi32(
                   memory, mask, index, data, N
                );
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1131
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<uint64_t, avx512>, N, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_mask_i64scatter_epi64(
                   memory, mask, index, data, N
                );
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1131
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<int64_t, avx512>, N, Idof> {
            using Vec = simd<int64_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_mask_i64scatter_epi64(
                   memory, mask, index, data, N
                );
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1138
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<float, avx512>, N, Idof> {
            using Vec = simd<float, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_mask_i32scatter_ps(memory, mask, index, data, N);
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1142
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<double, avx512>, N, Idof> {
            using Vec = simd<double, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, void*, const typename Vec::offset_base_register_type, std::integral_constant<int, N>>;
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
                const typename Vec::mask_type mask, const typename Vec::register_type data, void* memory, const typename Vec::offset_base_register_type index, [[maybe_unused]] std::integral_constant<int, N> scale
            ) {
                _mm512_mask_i64scatter_pd(memory, mask, index, data, N);
            }
        };
    } // end of namespace functors for template specialization of mask_scatter for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1292
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, typename Vec::base_type*, const typename Vec::register_type>;
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
                const typename Vec::imask_type mask, typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                _mm512_mask_compressstoreu_epi32(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1292
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, typename Vec::base_type*, const typename Vec::register_type>;
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
                const typename Vec::imask_type mask, typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                _mm512_mask_compressstoreu_epi32(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1292
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, typename Vec::base_type*, const typename Vec::register_type>;
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
                const typename Vec::imask_type mask, typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                _mm512_mask_compressstoreu_epi64(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1292
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, typename Vec::base_type*, const typename Vec::register_type>;
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
                const typename Vec::imask_type mask, typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                _mm512_mask_compressstoreu_epi64(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1296
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, typename Vec::base_type*, const typename Vec::register_type>;
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
                const typename Vec::imask_type mask, typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                _mm512_mask_compressstoreu_ps(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1296
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, typename Vec::base_type*, const typename Vec::register_type>;
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
                const typename Vec::imask_type mask, typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                _mm512_mask_compressstoreu_pd(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1304
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, typename Vec::base_type*, const typename Vec::register_type>;
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
                const typename Vec::imask_type mask, typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive compress_store is not supported by your hardware natively while it is forced by using native" );

                auto const orig_mem = memory;
                auto const data_array = tsl::to_array<Vec>(data);
                typename Vec::base_type safe[Vec::vector_element_count()];
                std::memcpy(reinterpret_cast<void*>(safe), reinterpret_cast<void const *>(memory), Vec::vector_size_B());
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  *memory = data_array[i];
                  memory += (mask>>i)&0b1;
                }
                if(((mask>>Vec::vector_element_count())&0b1) == 0) {
                  *memory = safe[memory-orig_mem];
                }
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1304
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, typename Vec::base_type*, const typename Vec::register_type>;
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
                const typename Vec::imask_type mask, typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive compress_store is not supported by your hardware natively while it is forced by using native" );

                auto const orig_mem = memory;
                auto const data_array = tsl::to_array<Vec>(data);
                typename Vec::base_type safe[Vec::vector_element_count()];
                std::memcpy(reinterpret_cast<void*>(safe), reinterpret_cast<void const *>(memory), Vec::vector_size_B());
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  *memory = data_array[i];
                  memory += (mask>>i)&0b1;
                }
                if(((mask>>Vec::vector_element_count())&0b1) == 0) {
                  *memory = safe[memory-orig_mem];
                }
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1304
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, typename Vec::base_type*, const typename Vec::register_type>;
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
                const typename Vec::imask_type mask, typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive compress_store is not supported by your hardware natively while it is forced by using native" );

                auto const orig_mem = memory;
                auto const data_array = tsl::to_array<Vec>(data);
                typename Vec::base_type safe[Vec::vector_element_count()];
                std::memcpy(reinterpret_cast<void*>(safe), reinterpret_cast<void const *>(memory), Vec::vector_size_B());
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  *memory = data_array[i];
                  memory += (mask>>i)&0b1;
                }
                if(((mask>>Vec::vector_element_count())&0b1) == 0) {
                  *memory = safe[memory-orig_mem];
                }
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1304
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
            using return_type = void;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, typename Vec::base_type*, const typename Vec::register_type>;
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
                const typename Vec::imask_type mask, typename Vec::base_type* memory, const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive compress_store is not supported by your hardware natively while it is forced by using native" );

                auto const orig_mem = memory;
                auto const data_array = tsl::to_array<Vec>(data);
                typename Vec::base_type safe[Vec::vector_element_count()];
                std::memcpy(reinterpret_cast<void*>(safe), reinterpret_cast<void const *>(memory), Vec::vector_size_B());
                #pragma unroll
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  *memory = data_array[i];
                  memory += (mask>>i)&0b1;
                }
                if(((mask>>Vec::vector_element_count())&0b1) == 0) {
                  *memory = safe[memory-orig_mem];
                }
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1372
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type, typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::imask_type mask, const typename Vec::register_type src, typename Vec::base_type* memory
            ) {
                return _mm512_mask_expandloadu_epi32(src, mask, reinterpret_cast<void*>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1372
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type, typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::imask_type mask, const typename Vec::register_type src, typename Vec::base_type* memory
            ) {
                return _mm512_mask_expandloadu_epi32(src, mask, reinterpret_cast<void*>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1372
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type, typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::imask_type mask, const typename Vec::register_type src, typename Vec::base_type* memory
            ) {
                return _mm512_mask_expandloadu_epi64(src, mask, reinterpret_cast<void*>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1372
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type, typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::imask_type mask, const typename Vec::register_type src, typename Vec::base_type* memory
            ) {
                return _mm512_mask_expandloadu_epi64(src, mask, reinterpret_cast<void*>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1376
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type, typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::imask_type mask, const typename Vec::register_type src, typename Vec::base_type* memory
            ) {
                return _mm512_mask_expandloadu_ps(src, mask, reinterpret_cast<void*>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1376
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type, typename Vec::base_type*>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::imask_type mask, const typename Vec::register_type src, typename Vec::base_type* memory
            ) {
                return _mm512_mask_expandloadu_pd(src, mask, reinterpret_cast<void*>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1384
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type, typename Vec::base_type*>;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src, typename Vec::base_type* memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive expand_load is not supported by your hardware natively while it is forced by using native" );

                //@todo: optimizable
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> data_array;
                auto src_array = tsl::to_array<Vec>(src);
                auto mem = memory;
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(((mask>>i)&0b1)==0) {
                    data_array[i] = src_array[i];
                  } else {
                    data_array[i] = *mem;
                    ++mem;
                  }
                }
                return _mm512_load_si512(reinterpret_cast<void const *>(data_array.data()));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1384
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type, typename Vec::base_type*>;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src, typename Vec::base_type* memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive expand_load is not supported by your hardware natively while it is forced by using native" );

                //@todo: optimizable
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> data_array;
                auto src_array = tsl::to_array<Vec>(src);
                auto mem = memory;
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(((mask>>i)&0b1)==0) {
                    data_array[i] = src_array[i];
                  } else {
                    data_array[i] = *mem;
                    ++mem;
                  }
                }
                return _mm512_load_si512(reinterpret_cast<void const *>(data_array.data()));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1384
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type, typename Vec::base_type*>;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src, typename Vec::base_type* memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive expand_load is not supported by your hardware natively while it is forced by using native" );

                //@todo: optimizable
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> data_array;
                auto src_array = tsl::to_array<Vec>(src);
                auto mem = memory;
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(((mask>>i)&0b1)==0) {
                    data_array[i] = src_array[i];
                  } else {
                    data_array[i] = *mem;
                    ++mem;
                  }
                }
                return _mm512_load_si512(reinterpret_cast<void const *>(data_array.data()));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1384
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type, typename Vec::base_type*>;
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
                const typename Vec::imask_type mask, const typename Vec::register_type src, typename Vec::base_type* memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive expand_load is not supported by your hardware natively while it is forced by using native" );

                //@todo: optimizable
                alignas(Vec::vector_alignment()) std::array<typename Vec::base_type, Vec::vector_element_count()> data_array;
                auto src_array = tsl::to_array<Vec>(src);
                auto mem = memory;
                for(std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  if(((mask>>i)&0b1)==0) {
                    data_array[i] = src_array[i];
                  } else {
                    data_array[i] = *mem;
                    ++mem;
                  }
                }
                return _mm512_load_si512(reinterpret_cast<void const *>(data_array.data()));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1518
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_mask_set1_epi8(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1518
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_mask_set1_epi16(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1518
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_mask_set1_epi8(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1518
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_mask_set1_epi16(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1522
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_mask_set1_epi32(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1522
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_mask_set1_epi64(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1522
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_mask_set1_epi32(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1522
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_mask_set1_epi64(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1526
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_castsi512_ps(_mm512_mask_set1_epi32(_mm512_castps_si512(src), mask, *reinterpret_cast<const int32_t*>(&value)));
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1530
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_castsi512_pd(_mm512_mask_set1_epi64(_mm512_castpd_si512(src), mask, *reinterpret_cast<const int64_t*>(&value)));
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_maskz_mov_epi8(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_maskz_mov_epi16(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_maskz_mov_epi8(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1617
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_maskz_mov_epi16(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1621
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_maskz_mov_epi32(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1621
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_maskz_mov_epi64(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1621
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_maskz_mov_epi32(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1621
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_maskz_mov_epi64(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1625
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_maskz_mov_ps(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1625
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_maskz_mov_pd(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1705
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                return _mm512_mask_mov_epi8(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1705
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                return _mm512_mask_mov_epi16(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1705
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                return _mm512_mask_mov_epi8(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1705
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                return _mm512_mask_mov_epi16(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1709
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_mask_mov_epi32(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1709
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_mask_mov_epi64(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1709
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_mask_mov_epi32(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1709
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_mask_mov_epi64(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1713
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
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
                return _mm512_mask_mov_ps(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1713
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
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
                return _mm512_mask_mov_pd(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1786
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int8_t, avx512>, Index, Idof> {
            using Vec = simd<int8_t, avx512>;
            
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
                /*__m512i idx = _mm512_set1_epi8(Index);
                __m512i result = _mm512_shuffle_epi8(data, idx);
                return (int8_t)_mm_extract_epi8(_mm512_castsi512_si128(result), 0);*/
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1786
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint8_t, avx512>, Index, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
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
                /*__m512i idx = _mm512_set1_epi8(Index);
                __m512i result = _mm512_shuffle_epi8(data, idx);
                return (uint8_t)_mm_extract_epi8(_mm512_castsi512_si128(result), 0);*/
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1794
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint16_t, avx512>, Index, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
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
                /*__m128i lane = _mm512_extracti32x4_epi32(data, Index / 8);
                return (uint16_t)_mm_extract_epi16(lane, Index % 8);*/
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1794
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int16_t, avx512>, Index, Idof> {
            using Vec = simd<int16_t, avx512>;
            
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
                /*__m128i lane = _mm512_extracti32x4_epi32(data, Index / 8);
                return (int16_t)_mm_extract_epi16(lane, Index % 8);*/
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1801
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint32_t, avx512>, Index, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                /*__m512i mask = _mm512_set_epi32(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, Index);

                __m512i permuted = _mm512_permutexvar_epi32(mask, data);
                return _mm_cvtsi128_si32(_mm512_castsi512_si128(permuted));
                */
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1801
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int32_t, avx512>, Index, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                /*__m512i mask = _mm512_set_epi32(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, Index);

                __m512i permuted = _mm512_permutexvar_epi32(mask, data);
                return _mm_cvtsi128_si32(_mm512_castsi512_si128(permuted));
                */
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1801
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<float, avx512>, Index, Idof> {
            using Vec = simd<float, avx512>;
            
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
                /*__m512i mask = _mm512_set_epi32(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, Index);

                __m512 permuted = _mm512_permutexvar_ps(mask, data);
                return _mm_cvtss_f32(_mm512_castps512_ps128(permuted));
                */
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1815
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint64_t, avx512>, Index, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                /*__m512i mask = _mm512_set_epi64(0, 0, 0, 0, 0, 0, 0, Index);

                __m512i permuted = _mm512_permutexvar_epi64(mask, data);
                return _mm_cvtsi128_si64(_mm512_castsi512_si128(permuted));
                */
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1815
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int64_t, avx512>, Index, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                /*__m512i mask = _mm512_set_epi64(0, 0, 0, 0, 0, 0, 0, Index);

                __m512i permuted = _mm512_permutexvar_epi64(mask, data);
                return _mm_cvtsi128_si64(_mm512_castsi512_si128(permuted));
                */
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1815
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<double, avx512>, Index, Idof> {
            using Vec = simd<double, avx512>;
            
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
                /*__m512i mask = _mm512_set_epi64(0, 0, 0, 0, 0, 0, 0, Index);

                __m512d permuted = _mm512_permutexvar_pd(mask, data);
                return _mm_cvtsd_f64(_mm512_castpd512_pd128(permuted));
                */
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx512 using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_AVX512_HPP