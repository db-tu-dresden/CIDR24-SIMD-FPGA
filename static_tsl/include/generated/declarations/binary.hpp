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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/declarations/binary.hpp
 * \date 2023-07-28
 * \brief Bit manipulation primitives.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_BINARY_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_BINARY_HPP

#include <tuple>

namespace tsl {

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_BINARY_AND_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "binary_and".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct binary_and{};
    }

    /*
     * \brief Binary ANDs two vector registers.
     * \details todo.
     * \param a First vector.
     * \param b Second vector.
     * \return Vector containing result of the binary AND.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type binary_and(
        const typename Vec::register_type a, const typename Vec::register_type b
    ) {
        return functors::binary_and<Vec, Idof>::apply(
            a, b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_BINARY_OR_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "binary_or".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct binary_or{};
    }

    /*
     * \brief Binary ANDs two vector registers.
     * \details todo.
     * \param a First vector.
     * \param b Second vector.
     * \return Vector containing result of the binary AND.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type binary_or(
        const typename Vec::register_type a, const typename Vec::register_type b
    ) {
        return functors::binary_or<Vec, Idof>::apply(
            a, b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_BINARY_XOR_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "binary_xor".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct binary_xor{};
    }

    /*
     * \brief Binary XORs two vector registers.
     * \details todo.
     * \param a First vector.
     * \param b Second vector.
     * \return Vector containing result of the binary XOR.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type binary_xor(
        const typename Vec::register_type a, const typename Vec::register_type b
    ) {
        return functors::binary_xor<Vec, Idof>::apply(
            a, b
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_SHIFT_LEFT_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "shift_left".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct shift_left{};
    }

    /*
     * \brief Arithmetic shift of data to the left by n bits.
     * \details todo.
     * \param data Data.
     * \param shift Amount of bits, data should be shifted.
     * \return Vector containing result of the right shift.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type shift_left(
        const typename Vec::register_type data, const unsigned int shift
    ) {
        return functors::shift_left<Vec, Idof>::apply(
            data, shift
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_SHIFT_LEFT_VECTOR_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "shift_left_vector".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct shift_left_vector{};
    }

    /*
     * \brief Shifts data to left by n bits (shifting in 0).
     * \details todo.
     * \param data Data.
     * \param shift Amount of bits, data should be shifted.
     * \return Vector containing result of the left shift.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
        #ifdef TSL_FUNCTORS_SHIFT_LEFT_STRUCT_DEFINED
        , typename std::enable_if_t<
            !std::is_same_v<
                typename functors::shift_left<Vec, Idof>::param_tuple_t,
                typename functors::shift_left_vector<Vec, Idof>::param_tuple_t
            >,
            std::nullptr_t
        > = nullptr
        #endif
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type shift_left(
        const typename Vec::register_type data, const typename Vec::register_type shift
    ) {
        return functors::shift_left_vector<Vec, Idof>::apply(
            data, shift
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_SHIFT_RIGHT_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "shift_right".
        template<VectorProcessingStyle Vec, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right{};
    }

    /*
     * \brief Arithmetic shift of data to the right by n bits.
     * \details Shifts in zeros or ones depending on (i) the most significant bit of a data value, (ii) the data type and (iii) the value of PreserveSign.
    For unsigned data type, the PreserveSign parameter and the most significant bit does not have any effect on the value of the bits shifted in (always shifts in 0).
    For signed data types, the PreserveSign parameter and the most significant bit determine the value of the shift in.
    If PreserveSign is set to false, 0 is shifted in, otherwise the most significant bit is shifted in.
    Note: The value of shift is __not__ checked for validity to omit branching and unnecessary instructions. Consequently, if shift is larger than the number
    of bits in the data type, the result will likely differ between the scalar and the SIMD implementations:
    Scalar: value >> (shift % (sizeof(typename Vec::base_type) * CHAR_BIT))
    SIMD: 0.

     * \param data Data.
     * \param shift Amount of bits, data should be shifted.
     * \return Vector containing result of the right shift.
     */
    template<
        VectorProcessingStyle Vec,
        bool PreserveSign = true, ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type shift_right(
        const typename Vec::register_type data, const unsigned int shift
    ) {
        return functors::shift_right<Vec, PreserveSign, Idof>::apply(
            data, shift
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_SHIFT_RIGHT_VECTOR_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "shift_right_vector".
        template<VectorProcessingStyle Vec, bool PreserveSign, ImplementationDegreeOfFreedom Idof>
        struct shift_right_vector{};
    }

    /*
     * \brief Arithmetic shift of data to the right by n bits.
     * \details todo.
     * \param data Data.
     * \param shift Amount of bits, data should be shifted.
     * \return Vector containing result of the left shift.
     */
    template<
        VectorProcessingStyle Vec,
        bool PreserveSign = true, ImplementationDegreeOfFreedom Idof = workaround
        #ifdef TSL_FUNCTORS_SHIFT_RIGHT_STRUCT_DEFINED
        , typename std::enable_if_t<
            !std::is_same_v<
                typename functors::shift_right<Vec, PreserveSign, Idof>::param_tuple_t,
                typename functors::shift_right_vector<Vec, PreserveSign, Idof>::param_tuple_t
            >,
            std::nullptr_t
        > = nullptr
        #endif
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type shift_right(
        const typename Vec::register_type data, const typename Vec::register_type shift
    ) {
        return functors::shift_right_vector<Vec, PreserveSign, Idof>::apply(
            data, shift
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_LZC_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "lzc".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct lzc{};
    }

    /*
     * \brief Leading zeros counter.
     * \details todo.
     * \param data First vector.
     * \return Vector containing leading zeros number.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::offset_base_register_type lzc(
        const typename Vec::register_type data
    ) {
        return functors::lzc<Vec, Idof>::apply(
            data
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_LZC_SCALAR_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "lzc_scalar".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct lzc_scalar{};
    }

    /*
     * \brief todo.
     * \details todo.
     * \param data Value.
     * \return Number of leading zeros.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
        #ifdef TSL_FUNCTORS_LZC_STRUCT_DEFINED
        , typename std::enable_if_t<
            !std::is_same_v<
                typename functors::lzc<Vec, Idof>::param_tuple_t,
                typename functors::lzc_scalar<Vec, Idof>::param_tuple_t
            >,
            std::nullptr_t
        > = nullptr
        #endif
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::offset_base_type lzc(
        const typename Vec::base_type data
    ) {
        return functors::lzc_scalar<Vec, Idof>::apply(
            data
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_HOR_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "hor".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct hor{};
    }

    /*
     * \brief Operates horizontal OR on vector register
     * \details todo.
     * \param vec Operating Vector
     * \return Result of the horizontal OR
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::base_type hor(
        const typename Vec::register_type vec
    ) {
        return functors::hor<Vec, Idof>::apply(
            vec
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_INV_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "inv".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct inv{};
    }

    /*
     * \brief Bitwise invertion values in vector Register.
     * \details todo.
     * \param vec Operating Vector
     * \return Result of the invertion.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type inv(
        const typename Vec::register_type vec
    ) {
        return functors::inv<Vec, Idof>::apply(
            vec
        );
    }

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_BINARY_HPP