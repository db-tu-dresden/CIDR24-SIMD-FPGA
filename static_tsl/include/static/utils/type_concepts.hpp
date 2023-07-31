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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/static/utils/type_concepts.hpp
 * \date 2023-07-28
 * \brief TODO.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_STATIC_UTILS_TYPE_CONCEPTS_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_STATIC_UTILS_TYPE_CONCEPTS_HPP

#include "type_helper.hpp"
#include <tuple>

namespace tsl {

    #ifdef TSL_USE_CONCEPTS
    #   include <concepts> //this is ugly, but the generator does not support conditional includes
        template<typename T>
        concept TSLArithmetic = std::is_arithmetic_v<T>;

        template<typename T>
        concept TSL_Tuple = is_tuple<T>::value;
    #else
    #   define TSLArithmetic typename
    #   define TSL_Tuple typename
    #endif

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_STATIC_UTILS_TYPE_CONCEPTS_HPP