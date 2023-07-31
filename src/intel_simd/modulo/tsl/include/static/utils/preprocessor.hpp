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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/static/utils/preprocessor.hpp
 * \date 2023-07-22
 * \brief TODO.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_STATIC_UTILS_PREPROCESSOR_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_STATIC_UTILS_PREPROCESSOR_HPP

#include <tuple>

namespace tsl {

    #ifndef TSL_FORCE_INLINE
    #   if defined(__clang__) || defined(__GNUC__)
    #       define TSL_FORCE_INLINE inline __attribute__((always_inline))
    #   elif defined(_MSC_VER)
    #       define TSL_FORCE_INLINE inline __forceinline
    #   endif
    #endif
    #ifndef TSL_NO_NATIVE_SUPPORT_WARNING
    #   define TSL_NO_NATIVE_SUPPORT_WARNING [[deprecated("This primitive is not supported by your hardware natively. Thus, a workaround is used.")]]
    #endif
    #ifndef TSL_DEP_TYPE
    #   define TSL_DEP_TYPE(CONDITION, IFBRANCH, ELSEBRANCH) std::conditional_t<CONDITION, IFBRANCH, ELSEBRANCH>
    #endif
    #ifndef TSL_CVAL
    #   define TSL_CVAL(type, value) std::integral_constant<type,value>{}
    #endif

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_STATIC_UTILS_PREPROCESSOR_HPP