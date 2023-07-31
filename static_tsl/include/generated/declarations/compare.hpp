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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/declarations/compare.hpp
 * \date 2023-07-28
 * \brief Compare primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_COMPARE_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_COMPARE_HPP

#include <tuple>

namespace tsl {

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_EQUAL_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "equal".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct equal{};
    }

    /*
     * \brief Compares two vector registers for equality.
     * \details todo.
     * \param vec_a Left vector.
     * \param vec_b Right vector.
     * \return Vector mask type indicating whether vec_a[*]==vec_b[*].
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::mask_type equal(
        const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
    ) {
        return functors::equal<Vec, Idof>::apply(
            vec_a, vec_b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_NEQUAL_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "nequal".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct nequal{};
    }

    /*
     * \brief Compares two vector registers for inequality.
     * \details todo.
     * \param vec_a Left vector.
     * \param vec_b Right vector.
     * \return Vector mask type indicating whether vec_a[*]==vec_b[*].
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::mask_type nequal(
        const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
    ) {
        return functors::nequal<Vec, Idof>::apply(
            vec_a, vec_b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_BETWEEN_INCLUSIVE_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "between_inclusive".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct between_inclusive{};
    }

    /*
     * \brief Checks if the values of a vector are in a specific range (min[*] <= d[*] <= max[*]).
     * \details todo.
     * \param vec_data Data vector.
     * \param vec_min Minimum vector.
     * \param vec_max Maximum vector.
     * \return Vector mask type indicating whether the data is in the given range.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::mask_type between_inclusive(
        const typename Vec::register_type vec_data, const typename Vec::register_type vec_min, typename Vec::register_type const vec_max
    ) {
        return functors::between_inclusive<Vec, Idof>::apply(
            vec_data, vec_min, vec_max
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_LESS_THAN_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "less_than".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct less_than{};
    }

    /*
     * \brief Tests whether left elements are smaller than the corresponding right ones.
     * \details todo.
     * \param vec_a Left vector.
     * \param vec_b Right vector.
     * \return Vector mask type indicating whether vec_a[*] < vec_b[*].
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::mask_type less_than(
        const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
    ) {
        return functors::less_than<Vec, Idof>::apply(
            vec_a, vec_b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_GREATER_THAN_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "greater_than".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct greater_than{};
    }

    /*
     * \brief Tests whether left elements are larger than or equal to the corresponding right ones.
     * \details todo.
     * \param vec_a Left vector.
     * \param vec_b Right vector.
     * \return Vector mask type indicating whether vec_a[*] < vec_b[*].
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::mask_type greater_than(
        const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
    ) {
        return functors::greater_than<Vec, Idof>::apply(
            vec_a, vec_b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_LESS_THAN_OR_EQUAL_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "less_than_or_equal".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct less_than_or_equal{};
    }

    /*
     * \brief Tests whether left elements are smaller than or equal to the corresponding right ones.
     * \details todo.
     * \param vec_a Left vector.
     * \param vec_b Right vector.
     * \return Vector mask type indicating whether vec_a[*] < vec_b[*].
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::mask_type less_than_or_equal(
        const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
    ) {
        return functors::less_than_or_equal<Vec, Idof>::apply(
            vec_a, vec_b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_GREATER_THAN_OR_EQUAL_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "greater_than_or_equal".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct greater_than_or_equal{};
    }

    /*
     * \brief Tests whether left elements are larger than the corresponding right ones.
     * \details todo.
     * \param vec_a Left vector.
     * \param vec_b Right vector.
     * \return Vector mask type indicating whether vec_a[*] < vec_b[*].
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::mask_type greater_than_or_equal(
        const typename Vec::register_type vec_a, const typename Vec::register_type vec_b
    ) {
        return functors::greater_than_or_equal<Vec, Idof>::apply(
            vec_a, vec_b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_UNEQUAL_ZERO_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "unequal_zero".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct unequal_zero{};
    }

    /*
     * \brief Checks if the vector register contains at least one value unequal zero.
     * \details todo.
     * \param vec Operating Vector
     * \return Result indicating if the vector register contains at least one value unequal to zero.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE bool unequal_zero(
        const typename Vec::register_type vec
    ) {
        return functors::unequal_zero<Vec, Idof>::apply(
            vec
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_COUNT_MATCHES_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "count_matches".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct count_matches{};
    }

    /*
     * \brief Counts number of matches of a chosen value within a vector register.
     * \details todo.
     * \param vec Operating Vector
     * \param val Compared value
     * \return Result of the count
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::base_type count_matches(
        const typename Vec::register_type vec, const typename Vec::base_type val
    ) {
        return functors::count_matches<Vec, Idof>::apply(
            vec, val
        );
    }

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_COMPARE_HPP