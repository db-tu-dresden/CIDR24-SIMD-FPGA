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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/declarations/convert.hpp
 * \date 2023-07-22
 * \brief Conversion primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DECLARATIONS_CONVERT_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DECLARATIONS_CONVERT_HPP

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

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_SPLIT_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "split".
        template<VectorProcessingStyle Vec, typename ToType, ImplementationDegreeOfFreedom Idof>
        struct split{};
    }

    /*
     * \brief todo.
     * \details todo.
     * \param data todo.
     * \return Array containing the registers with the split up data
     */
    template<
        VectorProcessingStyle Vec,
        typename ToType, ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type) * Vec::vector_element_count() / ToType::vector_element_count()> split(
        const typename Vec::register_type data
    ) {
        return functors::split<Vec, ToType, Idof>::apply(
            data
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_MERGE_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "merge".
        template<VectorProcessingStyle Vec, typename ToType, ImplementationDegreeOfFreedom Idof>
        struct merge{};
    }

    /*
     * \brief todo.
     * \details todo.
     * \param data todo.
     * \return SIMD register containing the merged register data
     */
    template<
        VectorProcessingStyle Vec,
        typename ToType, ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename ToType::register_type merge(
        std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type) * ToType::vector_element_count() / Vec::vector_element_count()> data
    ) {
        return functors::merge<Vec, ToType, Idof>::apply(
            data
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_CONVERT_UP_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "convert_up".
        template<VectorProcessingStyle Vec, typename ToType, ImplementationDegreeOfFreedom Idof>
        struct convert_up{};
    }

    /*
     * \brief todo.
     * \details todo.
     * \param data todo.
     * \return Array containing the upconverted simd registers.
     */
    template<
        VectorProcessingStyle Vec,
        typename ToType, ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE std::array<typename ToType::register_type, sizeof(typename ToType::base_type)/sizeof(typename Vec::base_type)> convert_up(
        const typename Vec::register_type data
    ) {
        return functors::convert_up<Vec, ToType, Idof>::apply(
            data
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_CONVERT_DOWN_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "convert_down".
        template<VectorProcessingStyle Vec, typename ToType, ImplementationDegreeOfFreedom Idof>
        struct convert_down{};
    }

    /*
     * \brief todo.
     * \details todo.
     * \param data todo.
     * \return SIMD register containing the down-converted data.
     */
    template<
        VectorProcessingStyle Vec,
        typename ToType, ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename ToType::register_type convert_down(
        std::array<typename Vec::register_type, sizeof(typename Vec::base_type)/sizeof(typename ToType::base_type)> data
    ) {
        return functors::convert_down<Vec, ToType, Idof>::apply(
            data
        );
    }

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DECLARATIONS_CONVERT_HPP