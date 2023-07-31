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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/extensions/simd/intel/avx2.hpp
 * \date 2023-07-22
 * \brief Definition of the SIMD TargetExtension avx2.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_EXTENSIONS_SIMD_INTEL_AVX2_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_EXTENSIONS_SIMD_INTEL_AVX2_HPP

#include "immintrin.h"
#include <tuple>

namespace tsl {

    struct avx2 {
          template<TSLArithmetic BaseType, std::size_t VectorSizeInBits = 256>
             struct types {
                using default_size_in_bits = std::integral_constant<std::size_t, VectorSizeInBits>;
                using register_t __attribute__((__vector_size__(VectorSizeInBits/8),__may_alias__,__aligned__(VectorSizeInBits/8))) = 
                   BaseType;
                using mask_t  = 
                   register_t;
                using imask_t =
                   TSL_DEP_TYPE(
                      (sizeof(BaseType)==1),
                      uint32_t,
                      TSL_DEP_TYPE(
                         (sizeof(BaseType)==2),
                         uint16_t,
                         uint8_t
                      )
                   );
             };
       };

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_EXTENSIONS_SIMD_INTEL_AVX2_HPP