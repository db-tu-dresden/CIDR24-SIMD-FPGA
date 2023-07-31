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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/generated/declarations/misc.hpp
 * \date 2023-07-22
 * \brief Miscellaneous primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DECLARATIONS_MISC_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DECLARATIONS_MISC_HPP

#include <tuple>

namespace tsl {

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_CONFLICT_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "conflict".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct conflict{};
    }

    /*
     * \brief Checks whether all elements are unique in a register.
     * \details todo.
     * \param data Data vector.
     * \return Vector containing result of the uniqueness check.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type conflict(
        [[maybe_unused]] const typename Vec::register_type data
    ) {
        return functors::conflict<Vec, Idof>::apply(
            data
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_IMASK_CONFLICT_FREE_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "imask_conflict_free".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct imask_conflict_free{};
    }

    /*
     * \brief Checks whether all elements are unique in a register and returns a mask indicating which elements don't have preceeding conflicts.
     * \details todo.
     * \param mask Mask indicating which lanes should be considered for conflict detection. Be aware, that non-valid lanes can still conflict with others.
     * \param data Data vector.
     * \return integral mask containing result of the uniqueness check.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
        #ifdef TSL_FUNCTORS_CONFLICT_FREE_STRUCT_DEFINED
        , typename std::enable_if_t<
            !std::is_same_v<
                typename functors::conflict_free<Vec, Idof>::param_tuple_t,
                typename functors::imask_conflict_free<Vec, Idof>::param_tuple_t
            >,
            std::nullptr_t
        > = nullptr
        #endif
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::imask_type conflict_free(
        [[maybe_unused]] const typename Vec::imask_type mask, [[maybe_unused]] const typename Vec::register_type data
    ) {
        return functors::imask_conflict_free<Vec, Idof>::apply(
            mask, data
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_BLEND_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "blend".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct blend{};
    }

    /*
     * \brief Blends two registers using provided bitmask.
     * \details todo.
     * \param control If control[i] == 0, the corresponding value from left register is used, from right otherwise.
     * \param left Left data.
     * \param right Right data.
     * \return Vector containing blended data.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type blend(
        const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right
    ) {
        return functors::blend<Vec, Idof>::apply(
            control, left, right
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_BLEND_ADD_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "blend_add".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct blend_add{};
    }

    /*
     * \brief Blends or add two registers using provided bitmask
     * \details todo.
     * \param control todo.
     * \param left Left data.
     * \param right Right data.
     * \param adder Adder data.
     * \return todo.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type blend_add(
        const typename Vec::mask_type control, const typename Vec::register_type left, const typename Vec::register_type right, const typename Vec::register_type adder
    ) {
        return functors::blend_add<Vec, Idof>::apply(
            control, left, right, adder
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_UNDEFINED_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "undefined".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct undefined{};
    }

    /*
     * \brief Returns a vector register with undefined data inside.
     * \details todo.
     * \return SIMD reigster
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type undefined(
        
    ) {
        return functors::undefined<Vec, Idof>::apply(
            
        );
    }

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_GENERATED_DECLARATIONS_MISC_HPP