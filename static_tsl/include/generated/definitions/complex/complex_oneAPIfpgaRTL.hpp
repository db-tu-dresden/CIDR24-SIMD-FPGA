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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/definitions/complex/complex_oneAPIfpgaRTL.hpp
 * \date 2023-07-28
 * \brief Complex (composed) primitives that are highly application specific.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPLEX_COMPLEX_ONEAPIFPGARTL_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPLEX_COMPLEX_ONEAPIFPGARTL_HPP

#include <sycl/ext/intel/ac_types/ac_int.hpp>
#include <tuple>
#include "../../declarations/complex.hpp"
#include <tuple>

namespace tsl {

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear" (primitive pack_bits_linear).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::24
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                // we must not use std::is_signed_v<T> for the ac_int, since we don't want the sign bit to be populated.
                using BigIntT = ac_int<Vec::vector_size_b(), false>;//std::is_signed_v<T>>;
                BigIntT tmp_result{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  tmp_result |=  (BigIntT{data[i]}) << (bitwidth*i);
                }
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear" (primitive pack_bits_linear).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::24
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                // we must not use std::is_signed_v<T> for the ac_int, since we don't want the sign bit to be populated.
                using BigIntT = ac_int<Vec::vector_size_b(), false>;//std::is_signed_v<T>>;
                BigIntT tmp_result{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  tmp_result |=  (BigIntT{data[i]}) << (bitwidth*i);
                }
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear" (primitive pack_bits_linear).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::24
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                // we must not use std::is_signed_v<T> for the ac_int, since we don't want the sign bit to be populated.
                using BigIntT = ac_int<Vec::vector_size_b(), false>;//std::is_signed_v<T>>;
                BigIntT tmp_result{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  tmp_result |=  (BigIntT{data[i]}) << (bitwidth*i);
                }
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear" (primitive pack_bits_linear).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::24
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                // we must not use std::is_signed_v<T> for the ac_int, since we don't want the sign bit to be populated.
                using BigIntT = ac_int<Vec::vector_size_b(), false>;//std::is_signed_v<T>>;
                BigIntT tmp_result{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  tmp_result |=  (BigIntT{data[i]}) << (bitwidth*i);
                }
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear" (primitive pack_bits_linear).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::24
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                // we must not use std::is_signed_v<T> for the ac_int, since we don't want the sign bit to be populated.
                using BigIntT = ac_int<Vec::vector_size_b(), false>;//std::is_signed_v<T>>;
                BigIntT tmp_result{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  tmp_result |=  (BigIntT{data[i]}) << (bitwidth*i);
                }
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear" (primitive pack_bits_linear).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::24
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                // we must not use std::is_signed_v<T> for the ac_int, since we don't want the sign bit to be populated.
                using BigIntT = ac_int<Vec::vector_size_b(), false>;//std::is_signed_v<T>>;
                BigIntT tmp_result{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  tmp_result |=  (BigIntT{data[i]}) << (bitwidth*i);
                }
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear" (primitive pack_bits_linear).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::24
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                // we must not use std::is_signed_v<T> for the ac_int, since we don't want the sign bit to be populated.
                using BigIntT = ac_int<Vec::vector_size_b(), false>;//std::is_signed_v<T>>;
                BigIntT tmp_result{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  tmp_result |=  (BigIntT{data[i]}) << (bitwidth*i);
                }
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear" (primitive pack_bits_linear).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::24
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                // we must not use std::is_signed_v<T> for the ac_int, since we don't want the sign bit to be populated.
                using BigIntT = ac_int<Vec::vector_size_b(), false>;//std::is_signed_v<T>>;
                BigIntT tmp_result{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  tmp_result |=  (BigIntT{data[i]}) << (bitwidth*i);
                }
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike" (primitive pack_bits_treelike).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::77
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT tmp_result_int = tmp_result[Vec::vector_element_count()-2];
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result_int.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike" (primitive pack_bits_treelike).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::77
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT tmp_result_int = tmp_result[Vec::vector_element_count()-2];
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result_int.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike" (primitive pack_bits_treelike).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::77
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT tmp_result_int = tmp_result[Vec::vector_element_count()-2];
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result_int.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike" (primitive pack_bits_treelike).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::77
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT tmp_result_int = tmp_result[Vec::vector_element_count()-2];
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result_int.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike" (primitive pack_bits_treelike).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::77
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT tmp_result_int = tmp_result[Vec::vector_element_count()-2];
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result_int.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike" (primitive pack_bits_treelike).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::77
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT tmp_result_int = tmp_result[Vec::vector_element_count()-2];
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result_int.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike" (primitive pack_bits_treelike).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::77
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT tmp_result_int = tmp_result[Vec::vector_element_count()-2];
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result_int.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike" (primitive pack_bits_treelike).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::77
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = typename Vec::register_type;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static typename Vec::register_type apply(
                const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT tmp_result_int = tmp_result[Vec::vector_element_count()-2];
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = tmp_result_int.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                }
                return result;
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear_merge" (primitive pack_bits_linear_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::144
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear_merge<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;

                BigIntT packed_data{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  packed_data |=  (BigIntT{(UnsignedT)data[i]}) << (bitwidth*i);
                }
                BigIntT packed_data_shifted = packed_data << bit_offset;
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear_merge for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear_merge" (primitive pack_bits_linear_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::144
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear_merge<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;

                BigIntT packed_data{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  packed_data |=  (BigIntT{(UnsignedT)data[i]}) << (bitwidth*i);
                }
                BigIntT packed_data_shifted = packed_data << bit_offset;
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear_merge for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear_merge" (primitive pack_bits_linear_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::144
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear_merge<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;

                BigIntT packed_data{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  packed_data |=  (BigIntT{(UnsignedT)data[i]}) << (bitwidth*i);
                }
                BigIntT packed_data_shifted = packed_data << bit_offset;
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear_merge for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear_merge" (primitive pack_bits_linear_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::144
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear_merge<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;

                BigIntT packed_data{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  packed_data |=  (BigIntT{(UnsignedT)data[i]}) << (bitwidth*i);
                }
                BigIntT packed_data_shifted = packed_data << bit_offset;
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear_merge for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear_merge" (primitive pack_bits_linear_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::144
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear_merge<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;

                BigIntT packed_data{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  packed_data |=  (BigIntT{(UnsignedT)data[i]}) << (bitwidth*i);
                }
                BigIntT packed_data_shifted = packed_data << bit_offset;
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear_merge for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear_merge" (primitive pack_bits_linear_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::144
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear_merge<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;

                BigIntT packed_data{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  packed_data |=  (BigIntT{(UnsignedT)data[i]}) << (bitwidth*i);
                }
                BigIntT packed_data_shifted = packed_data << bit_offset;
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear_merge for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear_merge" (primitive pack_bits_linear_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::144
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear_merge<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;

                BigIntT packed_data{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  packed_data |=  (BigIntT{(UnsignedT)data[i]}) << (bitwidth*i);
                }
                BigIntT packed_data_shifted = packed_data << bit_offset;
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear_merge for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_linear_merge" (primitive pack_bits_linear_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::144
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear_merge<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;

                BigIntT packed_data{0};
                #pragma unroll
                for (unsigned i = 0; i < Vec::vector_element_count(); ++i) {
                  packed_data |=  (BigIntT{(UnsignedT)data[i]}) << (bitwidth*i);
                }
                BigIntT packed_data_shifted = packed_data << bit_offset;
                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_linear_merge for oneAPIfpgaRTL using int64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike_merge" (primitive pack_bits_treelike_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::209
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike_merge<simd<uint8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT packed_data = tmp_result[Vec::vector_element_count()-2];
                BigIntT packed_data_shifted = packed_data << bit_offset;

                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike_merge for oneAPIfpgaRTL using uint8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike_merge" (primitive pack_bits_treelike_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::209
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike_merge<simd<uint16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT packed_data = tmp_result[Vec::vector_element_count()-2];
                BigIntT packed_data_shifted = packed_data << bit_offset;

                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike_merge for oneAPIfpgaRTL using uint16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike_merge" (primitive pack_bits_treelike_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::209
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike_merge<simd<uint32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT packed_data = tmp_result[Vec::vector_element_count()-2];
                BigIntT packed_data_shifted = packed_data << bit_offset;

                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike_merge for oneAPIfpgaRTL using uint32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike_merge" (primitive pack_bits_treelike_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: uint64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::209
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike_merge<simd<uint64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<uint64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT packed_data = tmp_result[Vec::vector_element_count()-2];
                BigIntT packed_data_shifted = packed_data << bit_offset;

                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike_merge for oneAPIfpgaRTL using uint64_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike_merge" (primitive pack_bits_treelike_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int8_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::209
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike_merge<simd<int8_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int8_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT packed_data = tmp_result[Vec::vector_element_count()-2];
                BigIntT packed_data_shifted = packed_data << bit_offset;

                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike_merge for oneAPIfpgaRTL using int8_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike_merge" (primitive pack_bits_treelike_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int16_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::209
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike_merge<simd<int16_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int16_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT packed_data = tmp_result[Vec::vector_element_count()-2];
                BigIntT packed_data_shifted = packed_data << bit_offset;

                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike_merge for oneAPIfpgaRTL using int16_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike_merge" (primitive pack_bits_treelike_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int32_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::209
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike_merge<simd<int32_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int32_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT packed_data = tmp_result[Vec::vector_element_count()-2];
                BigIntT packed_data_shifted = packed_data << bit_offset;

                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike_merge for oneAPIfpgaRTL using int32_t.

    namespace functors {
        /**
         * @brief: Template specialization of implementation for "pack_bits_treelike_merge" (primitive pack_bits_treelike_merge).
         * @details:
         * Target Extension: oneAPIfpgaRTL.
         *        Data Type: int64_t
         *  Extension Flags: ['oneAPIfpgaDev']
         *      Yaml Source: primitive_data/primitives/complex.yaml::209
         */
        template<std::size_t VectorSize, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike_merge<simd<int64_t, oneAPIfpgaRTL, VectorSize>, Idof> {
            using Vec = simd<int64_t, oneAPIfpgaRTL, VectorSize>;
            
            using return_type = std::tuple<typename Vec::register_type, int, typename Vec::register_type>;
            using param_tuple_t = std::tuple<const typename Vec::register_type, const unsigned, const typename Vec::register_type, const unsigned>;
            static constexpr bool parameters_queryable() {
                return true;
            }
            static constexpr bool has_return_value() {
                return true;
            }
            static constexpr bool native_supported() {
                return true;
            }
            [[nodiscard]] 
            TSL_FORCE_INLINE 
            static std::tuple<typename Vec::register_type, int, typename Vec::register_type> apply(
                const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
            ) {
                using T = typename Vec::base_type;
                using UnsignedT = std::make_unsigned_t<T>;
                using BigIntT = ac_int<Vec::vector_size_b(), false>;
                //we are wasting some space here, but it is easier to implement (and maybe even more efficient)
                BigIntT tmp_result[Vec::vector_element_count()];
                #pragma unroll
                for (unsigned int i = 0; i < (Vec::vector_element_count()>>1); ++i) {
                  tmp_result[i] = BigIntT{(UnsignedT)data[(i<<1)]} | (BigIntT{(UnsignedT)data[(i<<1)+1]} << bitwidth);
                }
                unsigned current_result_position = Vec::vector_element_count()>>1;
                unsigned previous_stage_start_idx = 0;
                unsigned current_stage = 1;
                #pragma unroll cilog2((Vec::vector_element_count()>>1))
                for(size_t current_upper_idx = (Vec::vector_element_count()>>2); current_upper_idx >= 1; current_upper_idx>>=1) {
                    #pragma unroll
                    for(size_t i = 0; i < current_upper_idx; ++i) {
                      tmp_result[current_result_position + i] =
                          tmp_result[previous_stage_start_idx + (i<<1)] | (tmp_result[previous_stage_start_idx + (i<<1)+1] << (bitwidth<<current_stage));
                    }
                    current_result_position += current_upper_idx;
                    previous_stage_start_idx += current_upper_idx<<1;
                    ++current_stage;
                }
                BigIntT packed_data = tmp_result[Vec::vector_element_count()-2];
                BigIntT packed_data_shifted = packed_data << bit_offset;

                typename Vec::register_type result{};
                #pragma unroll
                for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                  result[i] = src[i] | (T)(packed_data_shifted.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT))));
                }
                // check for overflow
                auto new_bitwidth = (bit_offset + bitwidth * Vec::vector_element_count());
                if (new_bitwidth >= Vec::vector_size_b()) {
                  new_bitwidth -= Vec::vector_size_b();
                  packed_data >>= (bitwidth * Vec::vector_element_count() - new_bitwidth);
                  typename Vec::register_type overflow_result{};
                  #pragma unroll
                  for (std::size_t i = 0; i < Vec::vector_element_count(); ++i) {
                    overflow_result[i] = packed_data.template slc<(sizeof(T)*CHAR_BIT)>((unsigned)(i*(sizeof(T)*CHAR_BIT)));
                  }
                  return std::make_tuple(result, new_bitwidth, overflow_result);
                }
                return std::make_tuple(result, -1, data);
            }
        };
    } // end of namespace functors for template specialization of pack_bits_treelike_merge for oneAPIfpgaRTL using int64_t.

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DEFINITIONS_COMPLEX_COMPLEX_ONEAPIFPGARTL_HPP