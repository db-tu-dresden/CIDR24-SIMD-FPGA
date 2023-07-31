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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/static/simd/simd_type.hpp
 * \date 2023-07-28
 * \brief TODO.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_STATIC_SIMD_SIMD_TYPE_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_STATIC_SIMD_SIMD_TYPE_HPP

#include "../utils/type_concepts.hpp"
#include "../utils/type_helper.hpp"
#include "simd_type_concepts.hpp"
#include <array>
#include <tuple>

namespace tsl {

    template<
          TSLArithmetic BaseType,
    #ifdef TSL_USE_CONCEPTS
          TargetExtension<BaseType> TargetExtensionType,
    #else
          class TargetExtensionType,
    #endif
          std::size_t VectorSizeInBits = TargetExtensionType::template types<BaseType>::default_size_in_bits::value
       >
       struct simd {
          using base_type = BaseType;
          using target_extension = TargetExtensionType;

          using register_type = typename TargetExtensionType::template types<BaseType, VectorSizeInBits>::register_t;
          using mask_type = typename TargetExtensionType::template types<BaseType, VectorSizeInBits>::mask_t;
          using imask_type = typename TargetExtensionType::template types<BaseType, VectorSizeInBits>::imask_t;

          using offset_base_type = typename
             TSL_DEP_TYPE(
                (sizeof(base_type)==1),
                   uint8_t,
                   TSL_DEP_TYPE(
                      (sizeof(base_type)==2),
                         uint16_t,
                         TSL_DEP_TYPE(
                            (sizeof(base_type)==4),
                               uint32_t,
                               uint64_t
                         )
                   )
             );
          using offset_base_register_type = typename TargetExtensionType::template types<offset_base_type, VectorSizeInBits>::register_t;
          
          template<TSLArithmetic OtherType>
          using transform_type = 
             std::conditional_t<
                (sizeof(BaseType) >= sizeof(OtherType)),
                typename TargetExtensionType::template types<OtherType, VectorSizeInBits>::register_t,
                std::array<
                   typename TargetExtensionType::template types<OtherType, VectorSizeInBits>::register_t,
                   sizeof(OtherType)/sizeof(BaseType)
                >                     
             >;
          template<TSLArithmetic OtherType>
          using transform_extension = simd<OtherType, TargetExtensionType, VectorSizeInBits>;
          //using offset_register_type = std::array<typename TargetExtensionType::template types<offset_t, VectorSizeInBits>::register_t, sizeof(offset_t)/sizeof(BaseType)>;


          static inline constexpr bool register_type_is_pointer_v = std::is_pointer_v<register_type>;

          static constexpr bool is_register_type_pointer() {
             return register_type_is_pointer_v;
          }
          static constexpr /*should be consteval, but clang does not eat this */ std::size_t vector_size_b() {
             return VectorSizeInBits;
          }
          static constexpr std::size_t vector_size_B() {
             return vector_element_count() * sizeof( base_type );
          }
          static constexpr std::size_t vector_element_count() {
             return VectorSizeInBits / ( sizeof( base_type ) * 8 );
          }
          static constexpr std::size_t vector_alignment() {
             if constexpr( vector_size_B() > 32 ) {
                return 64;
             } else {
                return vector_size_B();
             }
          }
          static constexpr std::size_t vector_mask_ratio() {
             return ( sizeof( mask_type ) * 8 ) / vector_element_count();
          }
          static constexpr std::size_t mask_shift() {
             return vector_element_count();
          }
       };

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_STATIC_SIMD_SIMD_TYPE_HPP