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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/definitions/misc/misc_sse.hpp
 * \date 2023-07-22
 * \brief Miscellaneous primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MISC_MISC_SSE_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MISC_MISC_SSE_HPP

#include "../../declarations/misc.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::62
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
                _mm_store_si128(reinterpret_cast<__m128i*>(conflicts.data()), _mm_setzero_si128());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::62
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
                _mm_store_si128(reinterpret_cast<__m128i*>(conflicts.data()), _mm_setzero_si128());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::62
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
                _mm_store_si128(reinterpret_cast<__m128i*>(conflicts.data()), _mm_setzero_si128());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::62
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
                _mm_store_si128(reinterpret_cast<__m128i*>(conflicts.data()), _mm_setzero_si128());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::62
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
                _mm_store_si128(reinterpret_cast<__m128i*>(conflicts.data()), _mm_setzero_si128());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::62
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
                _mm_store_si128(reinterpret_cast<__m128i*>(conflicts.data()), _mm_setzero_si128());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::62
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
                _mm_store_si128(reinterpret_cast<__m128i*>(conflicts.data()), _mm_setzero_si128());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "conflict" (primitive conflict).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::62
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct conflict<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
                _mm_store_si128(reinterpret_cast<__m128i*>(conflicts.data()), _mm_setzero_si128());
                for(unsigned ref = 1; ref < Vec::vector_element_count(); ++ref) {
                  for(unsigned cur = 0; cur < ref; ++cur) {
                    if(tmp[ref] == tmp[cur]) {
                      conflicts[ref] |= (1<<cur);
                    }
                  }
                }
                return _mm_load_si128(reinterpret_cast<__m128i const*>(conflicts.data()));
            }
        };
    } // end of namespace functors for template specialization of conflict for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::196
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
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
    } // end of namespace functors for template specialization of imask_conflict_free for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::196
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
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
    } // end of namespace functors for template specialization of imask_conflict_free for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::196
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
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
    } // end of namespace functors for template specialization of imask_conflict_free for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::196
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
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
    } // end of namespace functors for template specialization of imask_conflict_free for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::196
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
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
    } // end of namespace functors for template specialization of imask_conflict_free for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::196
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
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
    } // end of namespace functors for template specialization of imask_conflict_free for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::196
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
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
    } // end of namespace functors for template specialization of imask_conflict_free for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "imask_conflict_free" (primitive conflict_free).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::196
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
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
                _mm_store_si128(reinterpret_cast<__m128i*>(tmp.data()), data);
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
    } // end of namespace functors for template specialization of imask_conflict_free for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::268
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<uint8_t, sse>, Idof> {
            using Vec = simd<uint8_t, sse>;
            
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
                return _mm_or_si128(_mm_andnot_si128(control, left), _mm_and_si128(control,right));
            }
        };
    } // end of namespace functors for template specialization of blend for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::268
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<int8_t, sse>, Idof> {
            using Vec = simd<int8_t, sse>;
            
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
                return _mm_or_si128(_mm_andnot_si128(control, left), _mm_and_si128(control,right));
            }
        };
    } // end of namespace functors for template specialization of blend for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::268
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<uint16_t, sse>, Idof> {
            using Vec = simd<uint16_t, sse>;
            
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
                return _mm_or_si128(_mm_andnot_si128(control, left), _mm_and_si128(control,right));
            }
        };
    } // end of namespace functors for template specialization of blend for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::268
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<int16_t, sse>, Idof> {
            using Vec = simd<int16_t, sse>;
            
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
                return _mm_or_si128(_mm_andnot_si128(control, left), _mm_and_si128(control,right));
            }
        };
    } // end of namespace functors for template specialization of blend for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::268
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<int32_t, sse>, Idof> {
            using Vec = simd<int32_t, sse>;
            
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
                return _mm_or_si128(_mm_andnot_si128(control, left), _mm_and_si128(control,right));
            }
        };
    } // end of namespace functors for template specialization of blend for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::268
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<uint32_t, sse>, Idof> {
            using Vec = simd<uint32_t, sse>;
            
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
                return _mm_or_si128(_mm_andnot_si128(control, left), _mm_and_si128(control,right));
            }
        };
    } // end of namespace functors for template specialization of blend for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::268
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<int64_t, sse>, Idof> {
            using Vec = simd<int64_t, sse>;
            
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
                return _mm_or_si128(_mm_andnot_si128(control, left), _mm_and_si128(control,right));
            }
        };
    } // end of namespace functors for template specialization of blend for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::268
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<uint64_t, sse>, Idof> {
            using Vec = simd<uint64_t, sse>;
            
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
                return _mm_or_si128(_mm_andnot_si128(control, left), _mm_and_si128(control,right));
            }
        };
    } // end of namespace functors for template specialization of blend for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::272
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<float, sse>, Idof> {
            using Vec = simd<float, sse>;
            
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
                return _mm_or_ps(_mm_andnot_ps(control, left), _mm_and_ps(control,right));
            }
        };
    } // end of namespace functors for template specialization of blend for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "blend" (primitive blend).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['avx2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::272
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct blend<simd<double, sse>, Idof> {
            using Vec = simd<double, sse>;
            
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
                return _mm_or_pd(_mm_andnot_pd(control, left), _mm_and_pd(control,right));
            }
        };
    } // end of namespace functors for template specialization of blend for sse using double.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::349
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<uint8_t, sse>, Idof> {
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
                return _mm_undefined_si128();
            }
        };
    } // end of namespace functors for template specialization of undefined for sse using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: sse.
         *        Data Type: int8_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::349
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<int8_t, sse>, Idof> {
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
                return _mm_undefined_si128();
            }
        };
    } // end of namespace functors for template specialization of undefined for sse using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::349
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<uint16_t, sse>, Idof> {
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
                return _mm_undefined_si128();
            }
        };
    } // end of namespace functors for template specialization of undefined for sse using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: sse.
         *        Data Type: int16_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::349
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<int16_t, sse>, Idof> {
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
                return _mm_undefined_si128();
            }
        };
    } // end of namespace functors for template specialization of undefined for sse using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::349
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<uint32_t, sse>, Idof> {
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
                return _mm_undefined_si128();
            }
        };
    } // end of namespace functors for template specialization of undefined for sse using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: sse.
         *        Data Type: int32_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::349
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<int32_t, sse>, Idof> {
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
                return _mm_undefined_si128();
            }
        };
    } // end of namespace functors for template specialization of undefined for sse using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: sse.
         *        Data Type: uint64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::349
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<uint64_t, sse>, Idof> {
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
                return _mm_undefined_si128();
            }
        };
    } // end of namespace functors for template specialization of undefined for sse using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: sse.
         *        Data Type: int64_t
         *  Extension Flags: ['sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::349
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<int64_t, sse>, Idof> {
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
                return _mm_undefined_si128();
            }
        };
    } // end of namespace functors for template specialization of undefined for sse using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: sse.
         *        Data Type: float
         *  Extension Flags: ['sse', 'sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<float, sse>, Idof> {
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
                return _mm_undefined_ps();
            }
        };
    } // end of namespace functors for template specialization of undefined for sse using float.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "undefined" (primitive undefined).
         * @details:
         * Target Extension: sse.
         *        Data Type: double
         *  Extension Flags: ['sse', 'sse2']
         *      Yaml Source: primitive_data/primitives/misc.yaml::353
         */
        template<ImplementationDegreeOfFreedom Idof>
        struct undefined<simd<double, sse>, Idof> {
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
                return _mm_undefined_pd();
            }
        };
    } // end of namespace functors for template specialization of undefined for sse using double.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DEFINITIONS_MISC_MISC_SSE_HPP