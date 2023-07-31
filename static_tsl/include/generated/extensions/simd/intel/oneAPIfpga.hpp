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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/extensions/simd/intel/oneAPIfpga.hpp
 * \date 2023-07-28
 * \brief Definition of the SIMD TargetExtension fpga for Intel fpga using oneAPI + icpx.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_EXTENSIONS_SIMD_INTEL_ONEAPIFPGA_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_EXTENSIONS_SIMD_INTEL_ONEAPIFPGA_HPP

#include <array>
#include <CL/sycl.hpp>
#include <sycl/ext/intel/fpga_extensions.hpp>
#include <dpc_common.hpp>
#include <climits>
#include <tslOneAPIfpgaHelper.hpp>
#include <tuple>

namespace tsl {

    struct oneAPIfpga {
          template<TSLArithmetic BaseType, std::size_t VectorSizeInBits = 512>
             struct types {
                using default_size_in_bits = std::integral_constant<std::size_t, VectorSizeInBits>;
                using register_t  = __attribute__((register))
                   std::array<BaseType, VectorSizeInBits/(sizeof(BaseType)*CHAR_BIT)>;
                using mask_t  = __attribute__((register))
                   std::array<BaseType, VectorSizeInBits/(sizeof(BaseType)*CHAR_BIT)>;
                using imask_t =
                   mask_t;
             };
       };

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_EXTENSIONS_SIMD_INTEL_ONEAPIFPGA_HPP