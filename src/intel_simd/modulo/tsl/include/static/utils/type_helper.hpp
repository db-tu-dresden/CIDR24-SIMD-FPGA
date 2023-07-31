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
 * \file /home/jpietrzyk/Own/Work/cidr24/src/intel_simd/modulo/tsl/include/static/utils/type_helper.hpp
 * \date 2023-07-22
 * \brief TODO.
 * \note
 * Git-Local Url : /home/jpietrzyk/Own/Work/cidr24/tools/tslgen
 * Git-Remote Url: git@github.com:db-tu-dresden/TVLGen.git
 * Git-Branch    : fpga
 * Git-Commit    : 3be6c91 (3be6c91a83377bc829a0d7d5c0e26b515b87e178)
 *
 */
#ifndef TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_STATIC_UTILS_TYPE_HELPER_HPP
#define TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_STATIC_UTILS_TYPE_HELPER_HPP

#include <cstddef>
#include <type_traits>
#include <typeinfo>
#include <cxxabi.h>
#include <memory>
#include <string>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <tuple>
#include <cstdint>
#include <tuple>

namespace tsl {

    enum class modifier {
        HEX,
        DEC,
        OCT,
        BIN
    };

    template<class T>
    std::string type_name( ) {
        typedef typename std::remove_reference<T>::type TR;
        std::unique_ptr<char, void (*)(void *)> own (
            abi::__cxa_demangle( typeid( TR ).name(), nullptr,nullptr, nullptr ),
            std::free
        );
        std::string r = own != nullptr ? own.get() : typeid( TR ).name();
        if(std::is_const<TR>::value) {
            r += " const";
        }
        if (std::is_volatile<TR>::value) {
            r += " volatile";
            }
        if (std::is_lvalue_reference<T>::value) {
            r += "&";
        } else if(std::is_rvalue_reference<T>::value) {
            r += "&&";
        }
        return r;
    }
    #define TYPENAME(x) type_name<decltype(x)>()
         

    template<typename T>
    struct is_tuple_impl : std::false_type { };   

    template<typename... Ts>
    struct is_tuple_impl<std::tuple<Ts...>> : std::true_type {};

    template<typename T>
    struct is_tuple : is_tuple_impl<std::remove_cv_t<T>> {};

    template<typename /*LEFT_TUPLE*/, typename /*RIGHT_TUPLE*/>
    struct join_tuples {};
    template<typename... LEFT, typename... RIGHT>
    struct join_tuples<std::tuple<LEFT...>, std::tuple<RIGHT...>> {
      using type = std::tuple<LEFT..., RIGHT...>;
    };

    template<typename T, unsigned N>
    struct generate_tuple_type {
      using left  = typename generate_tuple_type<T, N/2>::type;
      using right = typename generate_tuple_type<T, N/2 + N%2>::type;
      using type  = typename join_tuples<left, right>::type;
    };

    template<typename T>
    struct generate_tuple_type<T, 1> {
      using type = std::tuple<T>;
    };

    template<typename T>
    struct generate_tuple_type<T, 0> {
      using type = std::tuple<>;
    };

    using offset_t = std::size_t;

    constexpr unsigned cilog2(unsigned val) { return val ? 1 + cilog2(val >> 1) : -1; }

    #ifndef __cpp_lib_assume_aligned
        //c++20-standard - copied source from https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1007r1.pdf
        template<std::size_t N, typename T>
        constexpr T* assume_aligned(T* ptr) noexcept {
    #   if defined(__clang__) || (defined(__GNUC__) && !defined(__ICC))
            return reinterpret_cast<T*>(__builtin_assume_aligned(ptr, N));
    #   elif defined(_MSC_VER)
            if ((reinterpret_cast<std::uintptr_t>(ptr) & ((1 << N) - 1)) == 0) {
                return ptr;
            } else {
                __assume(0);
            }
    #   elif defined(__ICC)
            switch (N) {
                case 2: __assume_aligned(ptr, 2); break;
                case 4: __assume_aligned(ptr, 4); break;
                case 8: __assume_aligned(ptr, 8); break;
                case 16: __assume_aligned(ptr, 16); break;
                case 32: __assume_aligned(ptr, 32); break;
                case 64: __assume_aligned(ptr, 64); break;
                case 128: __assume_aligned(ptr, 128); break;
            }
            return ptr;
    #   else
            return ptr;
    #   endif
    }
    #else
        using std::assume_aligned;
    #endif

    template<bool is_signed, std::size_t bit_width> struct integral_type;

    template<bool is_signed, std::size_t bit_width>
    using integral_type_t = typename integral_type<is_signed, bit_width>::type;

    template<std::size_t bit_width>
    struct integral_type<true, bit_width> { using type = std::make_signed_t<integral_type_t<false, bit_width>>; };

    template<> struct integral_type<false, 8> { using type = std::uint8_t; };
    template<> struct integral_type<false, 16> { using type = std::uint16_t; };
    template<> struct integral_type<false, 32> { using type = std::uint32_t; };
    template<> struct integral_type<false, 64> { using type = std::uint64_t; };

} // end of namespace tsl
#endif //TUD_D2RG_TSL_HOME_JPIETRZYK_OWN_WORK_CIDR24_SRC_INTEL_SIMD_MODULO_TSL_INCLUDE_STATIC_UTILS_TYPE_HELPER_HPP