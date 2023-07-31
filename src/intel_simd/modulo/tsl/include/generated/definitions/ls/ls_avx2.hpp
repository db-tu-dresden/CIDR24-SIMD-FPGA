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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/ls/ls_avx2.hpp
 * \date 2023-07-22
 * \brief Load/Store primitives
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_AVX2_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_AVX2_HPP

#include <array>
#include <cstring>
#include "../../declarations/ls.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_load_si256(reinterpret_cast<__m256i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_load_si256(reinterpret_cast<__m256i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_load_si256(reinterpret_cast<__m256i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_load_si256(reinterpret_cast<__m256i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_load_si256(reinterpret_cast<__m256i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_load_si256(reinterpret_cast<__m256i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_load_si256(reinterpret_cast<__m256i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::48
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_load_si256(reinterpret_cast<__m256i const *>(assume_aligned<Vec::vector_alignment()>(memory)));
            }
        };
    } // end of namespace functors for template specialization of load for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::52
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_load_ps(assume_aligned<Vec::vector_alignment()>(memory));
            }
        };
    } // end of namespace functors for template specialization of load for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load" (primitive load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::52
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_load_pd(assume_aligned<Vec::vector_alignment()>(memory));
            }
        };
    } // end of namespace functors for template specialization of load for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_loadu_si256( reinterpret_cast< __m256i const * >( memory ) );
            }
        };
    } // end of namespace functors for template specialization of loadu for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_loadu_si256( reinterpret_cast< __m256i const * >( memory ) );
            }
        };
    } // end of namespace functors for template specialization of loadu for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_loadu_si256( reinterpret_cast< __m256i const * >( memory ) );
            }
        };
    } // end of namespace functors for template specialization of loadu for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_loadu_si256( reinterpret_cast< __m256i const * >( memory ) );
            }
        };
    } // end of namespace functors for template specialization of loadu for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_loadu_si256( reinterpret_cast< __m256i const * >( memory ) );
            }
        };
    } // end of namespace functors for template specialization of loadu for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_loadu_si256( reinterpret_cast< __m256i const * >( memory ) );
            }
        };
    } // end of namespace functors for template specialization of loadu for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_loadu_si256( reinterpret_cast< __m256i const * >( memory ) );
            }
        };
    } // end of namespace functors for template specialization of loadu for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_loadu_si256( reinterpret_cast< __m256i const * >( memory ) );
            }
        };
    } // end of namespace functors for template specialization of loadu for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::141
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_loadu_ps(memory);
            }
        };
    } // end of namespace functors for template specialization of loadu for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "loadu" (primitive loadu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::141
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct loadu<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_loadu_pd(memory);
            }
        };
    } // end of namespace functors for template specialization of loadu for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::225
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                _mm256_store_si256(reinterpret_cast<__m256i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::225
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                _mm256_store_si256(reinterpret_cast<__m256i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::225
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                _mm256_store_si256(reinterpret_cast<__m256i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::225
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                _mm256_store_si256(reinterpret_cast<__m256i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::225
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                _mm256_store_si256(reinterpret_cast<__m256i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::225
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                _mm256_store_si256(reinterpret_cast<__m256i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::225
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                _mm256_store_si256(reinterpret_cast<__m256i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::225
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                _mm256_store_si256(reinterpret_cast<__m256i *>(assume_aligned<Vec::vector_alignment()>(memory)), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::229
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                _mm256_store_ps(assume_aligned<Vec::vector_alignment()>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "store" (primitive store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::229
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct store<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                _mm256_store_pd(assume_aligned<Vec::vector_alignment()>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of store for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::308
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                _mm256_storeu_si256(reinterpret_cast<__m256i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::308
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                _mm256_storeu_si256(reinterpret_cast<__m256i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::308
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                _mm256_storeu_si256(reinterpret_cast<__m256i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::308
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                _mm256_storeu_si256(reinterpret_cast<__m256i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::308
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                _mm256_storeu_si256(reinterpret_cast<__m256i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::308
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                _mm256_storeu_si256(reinterpret_cast<__m256i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::308
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                _mm256_storeu_si256(reinterpret_cast<__m256i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::308
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                _mm256_storeu_si256(reinterpret_cast<__m256i *>(memory), data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::312
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                _mm256_storeu_ps(memory, data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "storeu" (primitive storeu).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::312
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct storeu<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                _mm256_storeu_pd(memory, data);
            }
        };
    } // end of namespace functors for template specialization of storeu for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_array for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_array for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_array for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_array for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_array for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_array for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_array for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of to_array for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of to_array for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "to_array" (primitive to_array).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::370
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct to_array<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of to_array for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::430
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_set1_epi8(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::430
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_set1_epi16(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::430
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_set1_epi32(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::430
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_set1_epi8(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::430
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_set1_epi16(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::430
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_set1_epi32(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::434
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_set1_epi64x(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::434
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_set1_epi64x(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::438
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_set1_ps(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set1" (primitive set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::438
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set1<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_set1_pd(value);
            }
        };
    } // end of namespace functors for template specialization of set1 for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::500
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_setzero_si256();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::500
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_setzero_si256();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::500
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_setzero_si256();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::500
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_setzero_si256();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::500
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_setzero_si256();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::500
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_setzero_si256();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::500
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_setzero_si256();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::500
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_setzero_si256();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::504
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_setzero_ps();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set_zero" (primitive set_zero).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::504
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set_zero<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_setzero_pd();
            }
        };
    } // end of namespace functors for template specialization of set_zero for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::574
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_set_epi8(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::574
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_set_epi16(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::574
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_set_epi32(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::574
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_set_epi8(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::574
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_set_epi16(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::574
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_set_epi32(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::578
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_set_epi64x( args... );
            }
        };
    } // end of namespace functors for template specialization of set for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::578
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_set_epi64x( args... );
            }
        };
    } // end of namespace functors for template specialization of set for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::582
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_set_ps(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "set" (primitive set).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::582
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct set<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_set_pd(args...);
            }
        };
    } // end of namespace functors for template specialization of set for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::632
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of sequence for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::632
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of sequence for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::632
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of sequence for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::632
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of sequence for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::632
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of sequence for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::632
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of sequence for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::632
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of sequence for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::632
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of sequence for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::632
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of sequence for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "sequence" (primitive sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::632
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct sequence<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of sequence for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::700
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::700
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::700
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::700
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::700
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::700
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::700
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::700
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::700
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "custom_sequence" (primitive custom_sequence).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::700
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct custom_sequence<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of custom_sequence for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::914
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<uint64_t, avx2>, simd<uint64_t, avx2>, N, Idof> {
            using Vec = simd<uint64_t, avx2>;
            using IndicesType = simd<uint64_t, avx2>;
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
                return _mm256_mask_i64gather_epi64(source, reinterpret_cast<long long int const *>(memory), index, mask, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::914
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<int64_t, avx2>, simd<int64_t, avx2>, N, Idof> {
            using Vec = simd<int64_t, avx2>;
            using IndicesType = simd<int64_t, avx2>;
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
                return _mm256_mask_i64gather_epi64(source, reinterpret_cast<long long int const *>(memory), index, mask, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::919
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<uint32_t, avx2>, simd<uint32_t, avx2>, N, Idof> {
            using Vec = simd<uint32_t, avx2>;
            using IndicesType = simd<uint32_t, avx2>;
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
                return _mm256_mask_i32gather_epi32(source, reinterpret_cast<int const *>(memory), index, mask, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::919
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<int32_t, avx2>, simd<int32_t, avx2>, N, Idof> {
            using Vec = simd<int32_t, avx2>;
            using IndicesType = simd<int32_t, avx2>;
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
                return _mm256_mask_i32gather_epi32(source, reinterpret_cast<int const *>(memory), index, mask, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::924
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<float, avx2>, simd<float, avx2>, N, Idof> {
            using Vec = simd<float, avx2>;
            using IndicesType = simd<float, avx2>;
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
                return _mm256_mask_i32gather_ps(source, reinterpret_cast<float const *>(memory), index, mask, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_gather" (primitive gather).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::929
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_gather<simd<double, avx2>, simd<double, avx2>, N, Idof> {
            using Vec = simd<double, avx2>;
            using IndicesType = simd<double, avx2>;
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
                return _mm256_mask_i64gather_pd(source, reinterpret_cast<double const *>(memory), index, mask, N);
            }
        };
    } // end of namespace functors for template specialization of mask_gather for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1020
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<uint8_t, avx2>, N, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of scatter for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1020
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<int8_t, avx2>, N, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of scatter for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1020
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<uint16_t, avx2>, N, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of scatter for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1020
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<int16_t, avx2>, N, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of scatter for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1020
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<uint32_t, avx2>, N, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of scatter for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1020
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<int32_t, avx2>, N, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of scatter for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1020
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<uint64_t, avx2>, N, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of scatter for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1020
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<int64_t, avx2>, N, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of scatter for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1020
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<float, avx2>, N, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of scatter for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1020
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct scatter<simd<double, avx2>, N, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of scatter for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1147
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<uint8_t, avx2>, N, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of mask_scatter for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1147
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<int8_t, avx2>, N, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of mask_scatter for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1147
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<uint16_t, avx2>, N, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of mask_scatter for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1147
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<int16_t, avx2>, N, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of mask_scatter for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1147
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<uint32_t, avx2>, N, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of mask_scatter for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1147
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<int32_t, avx2>, N, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
    } // end of namespace functors for template specialization of mask_scatter for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1147
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<uint64_t, avx2>, N, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of mask_scatter for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1147
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<int64_t, avx2>, N, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
    } // end of namespace functors for template specialization of mask_scatter for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1147
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<float, avx2>, N, Idof> {
            using Vec = simd<float, avx2>;
            
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
    } // end of namespace functors for template specialization of mask_scatter for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_scatter" (primitive scatter).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1147
         */
        template<int N, ImplementationDegreeOfFreedom Idof>
        struct mask_scatter<simd<double, avx2>, N, Idof> {
            using Vec = simd<double, avx2>;
            
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
    } // end of namespace functors for template specialization of mask_scatter for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1323
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of compress_store for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1323
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
    } // end of namespace functors for template specialization of compress_store for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1323
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of compress_store for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1323
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
    } // end of namespace functors for template specialization of compress_store for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1341
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                _mm256_mask_compressstoreu_epi32(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1341
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                _mm256_mask_compressstoreu_epi32(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1341
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                _mm256_mask_compressstoreu_epi64(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1341
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                _mm256_mask_compressstoreu_epi64(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1345
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                _mm256_mask_compressstoreu_ps(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "compress_store" (primitive compress_store).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1345
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct compress_store<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                _mm256_mask_compressstoreu_pd(reinterpret_cast<void*>(memory), mask, data);
            }
        };
    } // end of namespace functors for template specialization of compress_store for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1404
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return tsl::load<Vec>(data_array.data());
                //return _mm256_load_si256(reinterpret_cast<__m256i const *>(data_array.data()));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1404
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return tsl::load<Vec>(data_array.data());
                //return _mm256_load_si256(reinterpret_cast<__m256i const *>(data_array.data()));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1404
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return tsl::load<Vec>(data_array.data());
                //return _mm256_load_si256(reinterpret_cast<__m256i const *>(data_array.data()));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1404
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return tsl::load<Vec>(data_array.data());
                //return _mm256_load_si256(reinterpret_cast<__m256i const *>(data_array.data()));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1424
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_mask_expandloadu_epi32(src, mask, reinterpret_cast<void const*>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1424
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_mask_expandloadu_epi32(src, mask, reinterpret_cast<void const*>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1424
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_mask_expandloadu_epi64(src, mask, reinterpret_cast<void const*>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1424
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_mask_expandloadu_epi64(src, mask, reinterpret_cast<void const*>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1428
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_mask_expandloadu_ps(src, mask, reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "expand_load" (primitive expand_load).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1428
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct expand_load<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_mask_expandloadu_pd(src, mask, reinterpret_cast<void const *>(memory));
            }
        };
    } // end of namespace functors for template specialization of expand_load for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint8_t, avx2>, simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            using ToType = simd<uint16_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi8_epi16(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint8_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            using ToType = simd<uint32_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi8_epi32(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint8_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            using ToType = simd<uint64_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi8_epi64(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint8_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            using ToType = simd<int16_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi8_epi16(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint8_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            using ToType = simd<int32_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi8_epi32(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint8_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            using ToType = simd<int64_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi8_epi64(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint16_t, avx2>, simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            using ToType = simd<uint32_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi16_epi32(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint16_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            using ToType = simd<uint64_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi16_epi64(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint16_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            using ToType = simd<int32_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi16_epi32(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint16_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            using ToType = simd<int64_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi16_epi64(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint32_t, avx2>, simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            using ToType = simd<uint64_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi32_epi64(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2', 'avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1450
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<uint32_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            using ToType = simd<int64_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_and_si256(
                    tsl::set1<ToType>(
                      (typename Vec::base_type)~0
                    ),
                    _mm256_cvtepi32_epi64(
                      _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                    )
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1465
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<int8_t, avx2>, simd<int16_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            using ToType = simd<int16_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_cvtepi8_epi16(
                    _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1465
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<int8_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            using ToType = simd<int32_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_cvtepi8_epi32(
                    _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1465
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<int8_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            using ToType = simd<int64_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_cvtepi8_epi64(
                    _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1465
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<int16_t, avx2>, simd<int32_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            using ToType = simd<int32_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_cvtepi16_epi32(
                    _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1465
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<int16_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            using ToType = simd<int64_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_cvtepi16_epi64(
                    _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "load_convert_up" (primitive load_convert_up).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1465
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct load_convert_up<simd<int32_t, avx2>, simd<int64_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            using ToType = simd<int64_t, avx2>;
            using return_type = typename ToType::register_type;
            using param_tuple_t = std::tuple<typename Vec::base_type const *>;
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
            static typename ToType::register_type apply(
                typename Vec::base_type const * memory
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive load_convert_up is not supported by your hardware natively while it is forced by using native" );

                return
                  _mm256_cvtepi32_epi64(
                    _mm_loadu_si128(reinterpret_cast<__m128i const *>(memory))
                  );
            }
        };
    } // end of namespace functors for template specialization of load_convert_up for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1535
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_mask_set1_epi8(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1535
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_mask_set1_epi16(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1535
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_mask_set1_epi8(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1535
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_mask_set1_epi16(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1539
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_mask_set1_epi32(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1539
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_mask_set1_epi64(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1539
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_mask_set1_epi32(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1539
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_mask_set1_epi64(src, mask, value);
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1543
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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

                return _mm256_castsi256_ps(_mm256_mask_set1_epi32(_mm256_castps_si256(src), mask, *reinterpret_cast<const int32_t*>(&value)));
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "masked_set1" (primitive masked_set1).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx', 'avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1548
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct masked_set1<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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

                return _mm256_castsi256_pd(_mm256_mask_set1_epi64(_mm256_castpd_si256(src), mask, *reinterpret_cast<const int64_t*>(&value)));
            }
        };
    } // end of namespace functors for template specialization of masked_set1 for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1630
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_maskz_mov_epi8(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1630
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_maskz_mov_epi16(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1630
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_maskz_mov_epi8(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1630
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_maskz_mov_epi16(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1634
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_maskz_mov_epi32(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1634
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_maskz_mov_epi64(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1634
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_maskz_mov_epi32(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1634
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_maskz_mov_epi64(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1638
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_maskz_mov_ps(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "maskz_mov" (primitive maskz_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1638
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct maskz_mov<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_maskz_mov_pd(mask, src);
            }
        };
    } // end of namespace functors for template specialization of maskz_mov for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1718
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint8_t, avx2>, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                return _mm256_mask_mov_epi8(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1718
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint16_t, avx2>, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                return _mm256_mask_mov_epi16(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1718
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int8_t, avx2>, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                return _mm256_mask_mov_epi8(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512bw', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1718
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int16_t, avx2>, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                return _mm256_mask_mov_epi16(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1722
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int32_t, avx2>, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                return _mm256_mask_mov_epi32(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1722
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<int64_t, avx2>, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                return _mm256_mask_mov_epi64(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1722
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint32_t, avx2>, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                return _mm256_mask_mov_epi32(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1722
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<uint64_t, avx2>, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                return _mm256_mask_mov_epi64(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1726
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<float, avx2>, Idof> {
            using Vec = simd<float, avx2>;
            
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
                return _mm256_mask_mov_ps(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "mask_mov" (primitive mask_mov).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx512f', 'avx512vl']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1726
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct mask_mov<simd<double, avx2>, Idof> {
            using Vec = simd<double, avx2>;
            
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
                return _mm256_mask_mov_pd(src, mask, data);
            }
        };
    } // end of namespace functors for template specialization of mask_mov for avx2 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1830
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint8_t, avx2>, Index, Idof> {
            using Vec = simd<uint8_t, avx2>;
            
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
                //return _mm256_extract_epi8(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx2 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1830
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint16_t, avx2>, Index, Idof> {
            using Vec = simd<uint16_t, avx2>;
            
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
                //return _mm256_extract_epi16(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx2 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int8_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1830
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int8_t, avx2>, Index, Idof> {
            using Vec = simd<int8_t, avx2>;
            
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
                //return _mm256_extract_epi8(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx2 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int16_t
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1830
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int16_t, avx2>, Index, Idof> {
            using Vec = simd<int16_t, avx2>;
            
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
                //return _mm256_extract_epi16(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx2 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1836
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint32_t, avx2>, Index, Idof> {
            using Vec = simd<uint32_t, avx2>;
            
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
                //return _mm256_extract_epi32(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx2 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx2.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1836
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<uint64_t, avx2>, Index, Idof> {
            using Vec = simd<uint64_t, avx2>;
            
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
                //return _mm256_extract_epi64(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx2 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int32_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1836
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int32_t, avx2>, Index, Idof> {
            using Vec = simd<int32_t, avx2>;
            
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
                //return _mm256_extract_epi32(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx2 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx2.
         *        Data Type: int64_t
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1836
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<int64_t, avx2>, Index, Idof> {
            using Vec = simd<int64_t, avx2>;
            
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
                //return _mm256_extract_epi64(data, Index);
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx2 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx2.
         *        Data Type: float
         *  Extension Flags: ['avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1842
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<float, avx2>, Index, Idof> {
            using Vec = simd<float, avx2>;
            
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
                /*__m256 temp = _mm256_permute_ps(data, _MM_SHUFFLE(Index, Index, Index, Index));
                return _mm256_cvtss_f32(temp);*/
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx2 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "extract_value" (primitive extract_value).
         * @details:
         * Target Extension: avx2.
         *        Data Type: double
         *  Extension Flags: ['avx2', 'avx']
         *      Yaml Source: primitive_data/primitives/ls.yaml::1849
         */
        template<const int Index, ImplementationDegreeOfFreedom Idof>
        struct extract_value<simd<double, avx2>, Index, Idof> {
            using Vec = simd<double, avx2>;
            
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
                /*__m256d temp = _mm256_permute4x64_pd(data, _MM_SHUFFLE(Index, Index, Index, Index));
                return _mm256_cvtsd_f64(temp);*/
            }
        };
    } // end of namespace functors for template specialization of extract_value for avx2 using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_LS_LS_AVX2_HPP