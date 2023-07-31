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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/declarations/calc.hpp
 * \date 2023-07-28
 * \brief This file contains arithmetic primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_CALC_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_CALC_HPP

#include <tuple>

namespace tsl {

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_ADD_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "add".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct add{};
    }

    /*
     * \brief Adds two vector registers.
     * \details todo.
     * \param vec_a First vector.
     * \param vec_b Second vector.
     * \return Vector containing result of the addition.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type add(
        const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
    ) {
        return functors::add<Vec, Idof>::apply(
            vec_a, vec_b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_SUB_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "sub".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct sub{};
    }

    /*
     * \brief Subtracts two vector registers.
     * \details todo.
     * \param vec_a First vector.
     * \param vec_b Second vector.
     * \return Vector containing result of the subtraction.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type sub(
        const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
    ) {
        return functors::sub<Vec, Idof>::apply(
            vec_a, vec_b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_MUL_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "mul".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct mul{};
    }

    /*
     * \brief Multiplies two vector registers.
     * \details todo.
     * \param vec_a First vector.
     * \param vec_b Second vector.
     * \return Vector containing result of the multiplication.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type mul(
        const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
    ) {
        return functors::mul<Vec, Idof>::apply(
            vec_a, vec_b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_HADD_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "hadd".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct hadd{};
    }

    /*
     * \brief Reduces the elements to a sum.
     * \details todo.
     * \param value Input vector.
     * \return Scalar value after adding all elements in the vector.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::base_type hadd(
        const typename Vec::register_type value
    ) {
        return functors::hadd<Vec, Idof>::apply(
            value
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_MIN_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "min".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct min{};
    }

    /*
     * \brief compares the values of 2 vectors and returns a vector with the minimum of each corrisponding values
     * \details todo.
     * \param vec_a First vector
     * \param vec_b Second vector
     * \return Vector containing result of the comparison
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type min(
        const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
    ) {
        return functors::min<Vec, Idof>::apply(
            vec_a, vec_b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_DIV_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "div".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct div{};
    }

    /*
     * \brief Divides two vector registers.
     * \details todo.
     * \param vec_a First vector.
     * \param vec_b Second vector.
     * \return Vector containing result of the division.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type div(
        const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
    ) {
        return functors::div<Vec, Idof>::apply(
            vec_a, vec_b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_MOD_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "mod".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct mod{};
    }

    /*
     * \brief Operates the modulo operation on one datavector modulo one input value.
     * \details todo.
     * \param vec Input Vector
     * \param val Modulo value
     * \return Resulting Vector
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type mod(
        const typename Vec::register_type vec, const typename Vec::base_type val
    ) {
        return functors::mod<Vec, Idof>::apply(
            vec, val
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_HMAX_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "hmax".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct hmax{};
    }

    /*
     * \brief Reduces the elements to the maximum value.
     * \details todo.
     * \param data Input vector.
     * \return Scalar value after adding all elements in the vector.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::base_type hmax(
        const typename Vec::register_type data
    ) {
        return functors::hmax<Vec, Idof>::apply(
            data
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_HMIN_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "hmin".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct hmin{};
    }

    /*
     * \brief Reduces the elements to the maximum value.
     * \details todo.
     * \param data Input vector.
     * \return Scalar value after adding all elements in the vector.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::base_type hmin(
        const typename Vec::register_type data
    ) {
        return functors::hmin<Vec, Idof>::apply(
            data
        );
    }

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_CALC_HPP