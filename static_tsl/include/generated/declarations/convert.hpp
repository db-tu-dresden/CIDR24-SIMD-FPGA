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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/declarations/convert.hpp
 * \date 2023-07-28
 * \brief Conversion primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_CONVERT_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_CONVERT_HPP

#include <tuple>

namespace tsl {

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_REINTERPRET_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "reinterpret".
        template<VectorProcessingStyle Vec, typename ToType, ImplementationDegreeOfFreedom Idof>
        struct reinterpret{};
    }

    /*
     * \brief todo.
     * \details todo.
     * \param data todo.
     * \return Casted register.
     */
    template<
        VectorProcessingStyle Vec,
        typename ToType, ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename ToType::register_type reinterpret(
        const typename Vec::register_type data
    ) {
        return functors::reinterpret<Vec, ToType, Idof>::apply(
            data
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_CAST_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "cast".
        template<VectorProcessingStyle Vec, typename ToType, ImplementationDegreeOfFreedom Idof>
        struct cast{};
    }

    /*
     * \brief todo.
     * \details todo.
     * \param data todo.
     * \return Casted SIMD register.
     */
    template<
        VectorProcessingStyle Vec,
        typename ToType, ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename ToType::register_type cast(
        const typename Vec::register_type data
    ) {
        return functors::cast<Vec, ToType, Idof>::apply(
            data
        );
    }

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_CONVERT_HPP