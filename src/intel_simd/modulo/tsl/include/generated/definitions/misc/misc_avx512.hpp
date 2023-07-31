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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/misc/misc_avx512.hpp
 * \date 2023-07-22
 * \brief Miscellaneous primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MISC_MISC_AVX512_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MISC_MISC_AVX512_HPP

#include "../../declarations/misc.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f', 'avx512cd']
         *      Yaml Source: primitive_data/primitives/misc.yaml::18
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
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
                return _mm512_conflict_epi32(data);
            }
        };
    } // end of namespace functors for template specialization of conflict for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f', 'avx512cd']
         *      Yaml Source: primitive_data/primitives/misc.yaml::18
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
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
                return _mm512_conflict_epi64(data);
            }
        };
    } // end of namespace functors for template specialization of conflict for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f', 'avx512cd']
         *      Yaml Source: primitive_data/primitives/misc.yaml::18
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
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
                return _mm512_conflict_epi32(data);
            }
        };
    } // end of namespace functors for template specialization of conflict for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f', 'avx512cd']
         *      Yaml Source: primitive_data/primitives/misc.yaml::18
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
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
                return _mm512_conflict_epi64(data);
            }
        };
    } // end of namespace functors for template specialization of conflict for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive conflict is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> conflicts{};
                _mm512_store_si512(reinterpret_cast<void*>(tmp.data()), data);
                _mm512_store_si512(reinterpret_cast<void*>(conflicts.data()), _mm512_setzero_si512());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm512_load_si512(reinterpret_cast<void const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive conflict is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> conflicts{};
                _mm512_store_si512(reinterpret_cast<void*>(tmp.data()), data);
                _mm512_store_si512(reinterpret_cast<void*>(conflicts.data()), _mm512_setzero_si512());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm512_load_si512(reinterpret_cast<void const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive conflict is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> conflicts{};
                _mm512_store_si512(reinterpret_cast<void*>(tmp.data()), data);
                _mm512_store_si512(reinterpret_cast<void*>(conflicts.data()), _mm512_setzero_si512());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm512_load_si512(reinterpret_cast<void const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::22
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type>;
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
                [[maybe_unused]] const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive conflict is not supported by your hardware natively while it is forced by using native" );

                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> conflicts{};
                _mm512_store_si512(reinterpret_cast<void*>(tmp.data()), data);
                _mm512_store_si512(reinterpret_cast<void*>(conflicts.data()), _mm512_setzero_si512());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm512_load_si512(reinterpret_cast<void const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f', 'avx512cd']
         *      Yaml Source: primitive_data/primitives/misc.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                [[maybe_unused]] const typename Vec::imask_type mask, [[maybe_unused]] const typename Vec::register_type data
            ) {
                auto const conflict_reg = _mm512_maskz_conflict_epi32(mask, data);
                auto const mask_reg = _mm512_set1_epi32(mask);
                auto const cleaned_conflict_reg = _mm512_and_si512(conflict_reg, mask_reg);
                return _mm512_mask_cmpeq_epi32_mask(mask, cleaned_conflict_reg, _mm512_setzero_si512());
            }
        };
    } // end of namespace functors for template specialization of imask_conflict_free for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f', 'avx512cd']
         *      Yaml Source: primitive_data/primitives/misc.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                [[maybe_unused]] const typename Vec::imask_type mask, [[maybe_unused]] const typename Vec::register_type data
            ) {
                auto const conflict_reg = _mm512_maskz_conflict_epi64(mask, data);
                auto const mask_reg = _mm512_set1_epi64(mask);
                auto const cleaned_conflict_reg = _mm512_and_si512(conflict_reg, mask_reg);
                return _mm512_mask_cmpeq_epi64_mask(mask, cleaned_conflict_reg, _mm512_setzero_si512());
            }
        };
    } // end of namespace functors for template specialization of imask_conflict_free for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f', 'avx512cd']
         *      Yaml Source: primitive_data/primitives/misc.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                [[maybe_unused]] const typename Vec::imask_type mask, [[maybe_unused]] const typename Vec::register_type data
            ) {
                auto const conflict_reg = _mm512_maskz_conflict_epi32(mask, data);
                auto const mask_reg = _mm512_set1_epi32(mask);
                auto const cleaned_conflict_reg = _mm512_and_si512(conflict_reg, mask_reg);
                return _mm512_mask_cmpeq_epi32_mask(mask, cleaned_conflict_reg, _mm512_setzero_si512());
            }
        };
    } // end of namespace functors for template specialization of imask_conflict_free for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f', 'avx512cd']
         *      Yaml Source: primitive_data/primitives/misc.yaml::137
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
            using return_type = typename Vec::imask_type;
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
            static typename Vec::imask_type apply(
                [[maybe_unused]] const typename Vec::imask_type mask, [[maybe_unused]] const typename Vec::register_type data
            ) {
                auto const conflict_reg = _mm512_maskz_conflict_epi64(mask, data);
                auto const mask_reg = _mm512_set1_epi64(mask);
                auto const cleaned_conflict_reg = _mm512_and_si512(conflict_reg, mask_reg);
                return _mm512_mask_cmpeq_epi64_mask(mask, cleaned_conflict_reg, _mm512_setzero_si512());
            }
        };
    } // end of namespace functors for template specialization of imask_conflict_free for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::145
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
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
            static typename Vec::imask_type apply(
                [[maybe_unused]] const typename Vec::imask_type mask, [[maybe_unused]] const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive imask_conflict_free is not supported by your hardware natively while it is forced by using native" );

                typename Vec::imask_type result = 0;
                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                _mm512_store_si512(reinterpret_cast<void*>(tmp.data()), data);
                typename Vec::imask_type pos = 2;
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  if(((mask>>ref)&0b1)==1) {
                    for(unsigned cur = 0; cur < ref; ++cur) {
                      if(((mask>>cur)&0b1)==1) {
                        if(tmp[ref] == tmp[cur]) {
                          result |= pos;
                          break;
                        }
                      }
                    }
                  }
                  pos <<= 1;
                }
                return (~result & mask);
            }
        };
    } // end of namespace functors for template specialization of imask_conflict_free for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::145
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
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
            static typename Vec::imask_type apply(
                [[maybe_unused]] const typename Vec::imask_type mask, [[maybe_unused]] const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive imask_conflict_free is not supported by your hardware natively while it is forced by using native" );

                typename Vec::imask_type result = 0;
                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                _mm512_store_si512(reinterpret_cast<void*>(tmp.data()), data);
                typename Vec::imask_type pos = 2;
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  if(((mask>>ref)&0b1)==1) {
                    for(unsigned cur = 0; cur < ref; ++cur) {
                      if(((mask>>cur)&0b1)==1) {
                        if(tmp[ref] == tmp[cur]) {
                          result |= pos;
                          break;
                        }
                      }
                    }
                  }
                  pos <<= 1;
                }
                return (~result & mask);
            }
        };
    } // end of namespace functors for template specialization of imask_conflict_free for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::145
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
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
            static typename Vec::imask_type apply(
                [[maybe_unused]] const typename Vec::imask_type mask, [[maybe_unused]] const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive imask_conflict_free is not supported by your hardware natively while it is forced by using native" );

                typename Vec::imask_type result = 0;
                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                _mm512_store_si512(reinterpret_cast<void*>(tmp.data()), data);
                typename Vec::imask_type pos = 2;
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  if(((mask>>ref)&0b1)==1) {
                    for(unsigned cur = 0; cur < ref; ++cur) {
                      if(((mask>>cur)&0b1)==1) {
                        if(tmp[ref] == tmp[cur]) {
                          result |= pos;
                          break;
                        }
                      }
                    }
                  }
                  pos <<= 1;
                }
                return (~result & mask);
            }
        };
    } // end of namespace functors for template specialization of imask_conflict_free for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::145
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
            using return_type = typename Vec::imask_type;
            using param_tuple_t = std::tuple<const typename Vec::imask_type, const typename Vec::register_type>;
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
            static typename Vec::imask_type apply(
                [[maybe_unused]] const typename Vec::imask_type mask, [[maybe_unused]] const typename Vec::register_type data
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive imask_conflict_free is not supported by your hardware natively while it is forced by using native" );

                typename Vec::imask_type result = 0;
                alignas(Vec::vector_alignment())
                  std::array<typename Vec::base_type, Vec::vector_element_count()> tmp{};
                _mm512_store_si512(reinterpret_cast<void*>(tmp.data()), data);
                typename Vec::imask_type pos = 2;
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  if(((mask>>ref)&0b1)==1) {
                    for(unsigned cur = 0; cur < ref; ++cur) {
                      if(((mask>>cur)&0b1)==1) {
                        if(tmp[ref] == tmp[cur]) {
                          result |= pos;
                          break;
                        }
                      }
                    }
                  }
                  pos <<= 1;
                }
                return (~result & mask);
            }
        };
    } // end of namespace functors for template specialization of imask_conflict_free for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/misc.yaml::244
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right
            ) {
                return _mm512_mask_blend_epi8(control, left, right);
            }
        };
    } // end of namespace functors for template specialization of blend for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/misc.yaml::244
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right
            ) {
                return _mm512_mask_blend_epi8(control, left, right);
            }
        };
    } // end of namespace functors for template specialization of blend for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/misc.yaml::244
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right
            ) {
                return _mm512_mask_blend_epi16(control, left, right);
            }
        };
    } // end of namespace functors for template specialization of blend for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/misc.yaml::244
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right
            ) {
                return _mm512_mask_blend_epi16(control, left, right);
            }
        };
    } // end of namespace functors for template specialization of blend for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right
            ) {
                return _mm512_mask_blend_epi32(control, left, right);
            }
        };
    } // end of namespace functors for template specialization of blend for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right
            ) {
                return _mm512_mask_blend_epi32(control, left, right);
            }
        };
    } // end of namespace functors for template specialization of blend for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right
            ) {
                return _mm512_mask_blend_epi64(control, left, right);
            }
        };
    } // end of namespace functors for template specialization of blend for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::248
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right
            ) {
                return _mm512_mask_blend_epi64(control, left, right);
            }
        };
    } // end of namespace functors for template specialization of blend for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::252
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<float, avx512>, Idof> {
            using Vec = simd<float, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right
            ) {
                return _mm512_mask_blend_ps(control, left, right);
            }
        };
    } // end of namespace functors for template specialization of blend for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::252
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<double, avx512>, Idof> {
            using Vec = simd<double, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right
            ) {
                return _mm512_mask_blend_pd(control, left, right);
            }
        };
    } // end of namespace functors for template specialization of blend for avx512 using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend_add" (primitive blend_add).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend_add<simd<uint32_t, avx512>, Idof> {
            using Vec = simd<uint32_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type, const typename Vec::register_type>;
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
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right, const typename Vec::register_type adder
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive blend_add is not supported by your hardware natively while it is forced by using native" );

                auto const right_added_part = _mm512_add_epi32(right, adder);
                return _mm512_mask_blend_epi32(control, right_added_part, left);
            }
        };
    } // end of namespace functors for template specialization of blend_add for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend_add" (primitive blend_add).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend_add<simd<int32_t, avx512>, Idof> {
            using Vec = simd<int32_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type, const typename Vec::register_type>;
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
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right, const typename Vec::register_type adder
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive blend_add is not supported by your hardware natively while it is forced by using native" );

                auto const right_added_part = _mm512_add_epi32(right, adder);
                return _mm512_mask_blend_epi32(control, right_added_part, left);
            }
        };
    } // end of namespace functors for template specialization of blend_add for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend_add" (primitive blend_add).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend_add<simd<uint64_t, avx512>, Idof> {
            using Vec = simd<uint64_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type, const typename Vec::register_type>;
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
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right, const typename Vec::register_type adder
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive blend_add is not supported by your hardware natively while it is forced by using native" );

                auto const right_added_part = _mm512_add_epi64(right, adder);
                return _mm512_mask_blend_epi64(control, right_added_part, left);
            }
        };
    } // end of namespace functors for template specialization of blend_add for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend_add" (primitive blend_add).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::299
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend_add<simd<int64_t, avx512>, Idof> {
            using Vec = simd<int64_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type, const typename Vec::register_type>;
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
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right, const typename Vec::register_type adder
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive blend_add is not supported by your hardware natively while it is forced by using native" );

                auto const right_added_part = _mm512_add_epi64(right, adder);
                return _mm512_mask_blend_epi64(control, right_added_part, left);
            }
        };
    } // end of namespace functors for template specialization of blend_add for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend_add" (primitive blend_add).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/misc.yaml::306
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend_add<simd<uint8_t, avx512>, Idof> {
            using Vec = simd<uint8_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type, const typename Vec::register_type>;
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
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right, const typename Vec::register_type adder
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive blend_add is not supported by your hardware natively while it is forced by using native" );

                auto const right_added_part = _mm512_add_epi8(right, adder);
                return _mm512_mask_blend_epi8(control, right_added_part, left);
            }
        };
    } // end of namespace functors for template specialization of blend_add for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend_add" (primitive blend_add).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/misc.yaml::306
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend_add<simd<int8_t, avx512>, Idof> {
            using Vec = simd<int8_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type, const typename Vec::register_type>;
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
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right, const typename Vec::register_type adder
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive blend_add is not supported by your hardware natively while it is forced by using native" );

                auto const right_added_part = _mm512_add_epi8(right, adder);
                return _mm512_mask_blend_epi8(control, right_added_part, left);
            }
        };
    } // end of namespace functors for template specialization of blend_add for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend_add" (primitive blend_add).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/misc.yaml::306
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend_add<simd<uint16_t, avx512>, Idof> {
            using Vec = simd<uint16_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type, const typename Vec::register_type>;
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
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right, const typename Vec::register_type adder
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive blend_add is not supported by your hardware natively while it is forced by using native" );

                auto const right_added_part = _mm512_add_epi16(right, adder);
                return _mm512_mask_blend_epi16(control, right_added_part, left);
            }
        };
    } // end of namespace functors for template specialization of blend_add for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend_add" (primitive blend_add).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f', 'avx512bw']
         *      Yaml Source: primitive_data/primitives/misc.yaml::306
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend_add<simd<int16_t, avx512>, Idof> {
            using Vec = simd<int16_t, avx512>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::mask_type, const typename Vec::register_type, const typename Vec::register_type, const typename Vec::register_type>;
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
                const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right, const typename Vec::register_type adder
            ) {
                static_assert( !std::is_same_v< Idof, native >, "The primitive blend_add is not supported by your hardware natively while it is forced by using native" );

                auto const right_added_part = _mm512_add_epi16(right, adder);
                return _mm512_mask_blend_epi16(control, right_added_part, left);
            }
        };
    } // end of namespace functors for template specialization of blend_add for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::331
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<uint8_t, avx512>, Idof> {
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
                return _mm512_undefined_epi32();
            }
        };
    } // end of namespace functors for template specialization of undefined for avx512 using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int8_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::331
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<int8_t, avx512>, Idof> {
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
                return _mm512_undefined_epi32();
            }
        };
    } // end of namespace functors for template specialization of undefined for avx512 using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::331
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<uint16_t, avx512>, Idof> {
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
                return _mm512_undefined_epi32();
            }
        };
    } // end of namespace functors for template specialization of undefined for avx512 using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int16_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::331
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<int16_t, avx512>, Idof> {
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
                return _mm512_undefined_epi32();
            }
        };
    } // end of namespace functors for template specialization of undefined for avx512 using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::331
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<uint32_t, avx512>, Idof> {
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
                return _mm512_undefined_epi32();
            }
        };
    } // end of namespace functors for template specialization of undefined for avx512 using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int32_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::331
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<int32_t, avx512>, Idof> {
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
                return _mm512_undefined_epi32();
            }
        };
    } // end of namespace functors for template specialization of undefined for avx512 using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: avx512.
         *        Data Type: uint64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::331
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<uint64_t, avx512>, Idof> {
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
                return _mm512_undefined_epi32();
            }
        };
    } // end of namespace functors for template specialization of undefined for avx512 using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: avx512.
         *        Data Type: int64_t
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::331
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<int64_t, avx512>, Idof> {
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
                return _mm512_undefined_epi32();
            }
        };
    } // end of namespace functors for template specialization of undefined for avx512 using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: avx512.
         *        Data Type: float
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::335
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<float, avx512>, Idof> {
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
                return _mm512_undefined_ps();
            }
        };
    } // end of namespace functors for template specialization of undefined for avx512 using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: avx512.
         *        Data Type: double
         *  Extension Flags: ['avx512f']
         *      Yaml Source: primitive_data/primitives/misc.yaml::335
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<double, avx512>, Idof> {
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
                return _mm512_undefined_pd();
            }
        };
    } // end of namespace functors for template specialization of undefined for avx512 using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MISC_MISC_AVX512_HPP