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
 * \file /home/jpietrzyk/Own/Work/cidr24/static_tsl/include/generated/declarations/complex.hpp
 * \date 2023-07-28
 * \brief Complex (composed) primitives that are highly application specific.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : d6b9087 (d6b9087007de4b8d3b3a4cd3e2d0f2c524c1f86c)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_COMPLEX_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_COMPLEX_HPP

#include <tuple>

namespace tsl {

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_PACK_BITS_LINEAR_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "pack_bits_linear".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear{};
    }

    /*
     * \brief Packs elements from a vector together using a fixed bitwidth.
     * \details Packs elements from a vector together using a fixed bitwidth. The bitwidth
    must be less than the number of bits in the vector's base type.
    The elements are packed together in little-endian order, i.e. the least
    significant bits of the first element are used first.

     * \param data Data vector.
     * \param bitwidth Bitwidth of each element.
     * \return Vector containing packed elements.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type pack_bits_linear(
        const typename Vec::register_type data, const unsigned bitwidth
    ) {
        return functors::pack_bits_linear<Vec, Idof>::apply(
            data, bitwidth
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_PACK_BITS_TREELIKE_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "pack_bits_treelike".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike{};
    }

    /*
     * \brief Packs elements from a vector together using a fixed bitwidth.
     * \details Packs elements from a vector together using a fixed bitwidth. The bitwidth
    must be less than the number of bits in the vector's base type.
    The elements are packed together in little-endian order, i.e. the least
    significant bits of the first element are used first.
    Example: Assuming 8 values in vector, bitwidth=3
      result = data
      stage=1, i=0, bitwidth=3: result[ 8] = (result[ 0]) | (result[ 1] <<  3) ==> ([0: 5] filled)
      stage=1, i=1, bitwidth=3: result[ 9] = (result[ 2]) | (result[ 3] <<  3) ==> ([0: 5] filled)
      stage=1, i=2, bitwidth=3: result[10] = (result[ 4]) | (result[ 5] <<  3) ==> ([0: 5] filled)
      stage=1, i=3, bitwidth=3: result[11] = (result[ 6]) | (result[ 7] <<  3) ==> ([0: 5] filled)

      stage=2, i=0, bitwidth=3: result[12] = (result[ 8]) | (result[ 9] <<  6) ==> ([0:11] filled)
      stage=2, i=1, bitwidth=3: result[13] = (result[10]) | (result[11] <<  6) ==> ([0:11] filled)

      stage=3, i=0, bitwidth=3: result[14] = (result[12]) | (result[13] << 12) ==> ([0:23] filled)

      return result[2*Vec::vector_element_count()-2];

     * \param data Data vector.
     * \param bitwidth Bitwidth of each element.
     * \return Vector containing packed elements.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE typename Vec::register_type pack_bits_treelike(
        const typename Vec::register_type data, const unsigned bitwidth
    ) {
        return functors::pack_bits_treelike<Vec, Idof>::apply(
            data, bitwidth
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_PACK_BITS_LINEAR_MERGE_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "pack_bits_linear_merge".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_linear_merge{};
    }

    /*
     * \brief 
     * \details Packs elements from two vector registers together using a fixed bitwidth. The bitwidth
    must be less than the number of bits in the vector's base type.
    The elements are packed together in little-endian order, i.e. the least
    significant bits of the first element are used first.
    The 'src' operand is assumed to be packed already. The 'bit_offset' parameter indicates
    the bit offset of the last set bit in the 'src' operand. The 'data' operand is packed
    and merged with the 'src' operand. The 'bitwidth' parameter indicates the bitwidth of
    each element in the 'data' operand.

     * \param src Source register which is used for merging (assumed to be packed already).
     * \param bit_offset Bit offset of the last set bit.
     * \param data Data vector.
     * \param bitwidth Bitwidth of each element.
     * \return Tuple containing the merged vector, an int indicating whether the data vector had an overflow (-1: false, >=0 new offset) and the overflow.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE std::tuple<typename Vec::register_type, int, typename Vec::register_type> pack_bits_linear_merge(
        const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
    ) {
        return functors::pack_bits_linear_merge<Vec, Idof>::apply(
            src, bit_offset, data, bitwidth
        );
    }

    namespace functors {
        // Definition of a preprocessor variable to detect overload ambiguity.
        #define TSL_FUNCTORS_PACK_BITS_TREELIKE_MERGE_STRUCT_DEFINED
        // Forward declaration of implementation struct for TSL-primitive "pack_bits_treelike_merge".
        template<VectorProcessingStyle Vec, ImplementationDegreeOfFreedom Idof>
        struct pack_bits_treelike_merge{};
    }

    /*
     * \brief 
     * \details Packs elements from two vector registers together using a fixed bitwidth. The bitwidth
    must be less than the number of bits in the vector's base type.
    The elements are packed together in little-endian order, i.e. the least
    significant bits of the first element are used first.
    The 'src' operand is assumed to be packed already. The 'bit_offset' parameter indicates
    the bit offset of the last set bit in the 'src' operand. The 'data' operand is packed
    and merged with the 'src' operand. The 'bitwidth' parameter indicates the bitwidth of
    each element in the 'data' operand.

     * \param src Source register which is used for merging (assumed to be packed already).
     * \param bit_offset Bit offset of the last set bit.
     * \param data Data vector.
     * \param bitwidth Bitwidth of each element.
     * \return Tuple containing the merged vector, an int indicating whether the data vector had an overflow (-1: false, >=0 new offset) and the overflow.
     */
    template<
        VectorProcessingStyle Vec,
        ImplementationDegreeOfFreedom Idof = workaround
    >
    [[nodiscard]] TSL_FORCE_INLINE std::tuple<typename Vec::register_type, int, typename Vec::register_type> pack_bits_treelike_merge(
        const typename Vec::register_type src, const unsigned bit_offset, const typename Vec::register_type data, const unsigned bitwidth
    ) {
        return functors::pack_bits_treelike_merge<Vec, Idof>::apply(
            src, bit_offset, data, bitwidth
        );
    }

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_STATIC_TSL_INCLUDE_GENERATED_DECLARATIONS_COMPLEX_HPP