/*
Copyright 2023 Database Research Group, TU Dresden

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef CIDR24_DATA_H
#define CIDR24_DATA_H




#include <algorithm>
#include <array>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <tuple>
#include <utility>
#include <vector>
#include <cstring>
#include <climits>

#include <sycl.h>
// Template Vector Library (tsl) main header
#include <tslintrin.hpp>


using namespace sycl;
using namespace std::chrono;

namespace tuddbs {
    template<typename T, typename RetT = typename std::conditional_t<(sizeof(T) < 4),
            std::make_unsigned_t < T>, std::conditional_t<(sizeof(T) == 4), uint32_t, uint64_t>>>
    void fill_buffers_systematic(T *in, RetT *out_fpga, RetT *out_cpu, size_t buffer_count) {
        auto casted_in = reinterpret_cast<RetT *>(in);
        casted_in[0] = 0;
        {
            std::size_t i = 0;
            using namespace tsl;
            for (; i < (sizeof(T) * CHAR_BIT); ++i) {
                casted_in[i + 1] = (RetT) 1 << i;
            }
            std::mt19937 engine(0xc01dbadc00ffee);
            std::uniform_int_distribution <RetT> dist(0, std::numeric_limits<RetT>::max());
            for (; i < buffer_count; ++i) {
                casted_in[i] = dist(engine);
            }
        }
        for (std::size_t i = 0; i < buffer_count; ++i) {
            out_fpga[i] = 0x80;
            out_cpu[i] = 0x80;  //use 128 to check whether the index was overwritten, since 128 can not be a result of clz.
        }
    }

    template<typename T, typename RetT = typename std::conditional_t<(sizeof(T) < 4),
            std::make_unsigned_t < T>, std::conditional_t<(sizeof(T) == 4), uint32_t, uint64_t>>>
    void fill_buffers_random(T *in, RetT *out_fpga, RetT *out_cpu, size_t buffer_count) {
        auto casted_in = reinterpret_cast<RetT *>(in);
        std::mt19937 engine(0xc01dbadc00ffee);
        std::uniform_int_distribution <RetT> dist(0, std::numeric_limits<RetT>::max());
        for (size_t i = 0; i < buffer_count; ++i) {
            casted_in[i] = dist(engine);
            out_fpga[i] = 0x80;
            out_cpu[i] = 0x80;
        }
    }

    template<typename T>
    void fill_buffer_random_in_range(T* buffer, size_t buffer_count, T range_lower, T range_upper) {
        std::mt19937 engine(0xc01dbadc00ffee);
        std::uniform_int_distribution<T> dist(range_lower, range_upper);
        for (size_t i = 0; i < buffer_count; ++i) {
            buffer[i] = dist(engine);
        }
    }

    template<typename T>
    void fill_buffer_with_value(T* buffer, size_t buffer_count, T value) {
        for (size_t i = 0; i < buffer_count; ++i) {
            buffer[i] = value;
        }
    }
    template<typename T>
    void fill_bufer_random_up_to_bitwidth(T* buffer, size_t buffer_count, unsigned upper_bitwidth) {
        std::mt19937 engine(0xc01dbadc00ffee);
        using UnsignedT = 
            std::conditional_t<(sizeof(T)<4),
                std::make_unsigned_t<T>,
                std::conditional_t<(sizeof(T)==4), uint32_t, uint64_t>>;
        std::uniform_int_distribution<UnsignedT> dist(
            0, 
            upper_bitwidth == (sizeof(UnsignedT)*CHAR_BIT) ? std::numeric_limits<UnsignedT>::max() : (1<<upper_bitwidth)-1
        );
        for (size_t i = 0; i < buffer_count; ++i) {
            buffer[i] = dist(engine);
        }
    }

    template<typename T>
    void fill_buffer_with_outliers(T* buffer, size_t buffer_count, uint64_t lower_bw, uint64_t upper_bw, float outlier_prob) {
        assert(lower_bw <= upper_bw);
        assert(lower_bw < (sizeof(T)*CHAR_BIT));
        std::mt19937 engine(0xc01dbadc00ffee);
        using UnsignedT = 
            std::conditional_t<(sizeof(T)<4),
                std::make_unsigned_t<T>,
                std::conditional_t<(sizeof(T)==4), uint32_t, uint64_t>>;
        auto unsigned_buffer = reinterpret_cast<UnsignedT*>(buffer);
        UnsignedT lower_bw_msb = 1<<(lower_bw-1);
        UnsignedT upper_bw_msb = 1<<(upper_bw-1);
        std::uniform_int_distribution<UnsignedT> dist_lower(0, lower_bw_msb);
        std::uniform_int_distribution<UnsignedT> dist_upper(0, upper_bw_msb);
        std::uniform_real_distribution<float> dist_prob(0, 1);
        for (size_t i = 0; i < buffer_count; ++i) {
            if (dist_prob(engine) < outlier_prob) {
                unsigned_buffer[i] = (dist_upper(engine) | upper_bw_msb);
            } else {
                unsigned_buffer[i] = (dist_lower(engine) | lower_bw_msb);
            }
        }
    }

    template<typename T>
    void fill_bufer_random_with_bitwidth(T* buffer, size_t buffer_count, unsigned upper_bitwidth) {
        std::mt19937 engine(0xc01dbadc00ffee);
        T mask = static_cast<T>(1) << (upper_bitwidth-1);
        using UnsignedT = 
            std::conditional_t<(sizeof(T)<4),
                std::make_unsigned_t<T>,
                std::conditional_t<(sizeof(T)==4), uint32_t, uint64_t>>;
        std::uniform_int_distribution<UnsignedT> dist(
            0, 
            upper_bitwidth == (sizeof(UnsignedT)*CHAR_BIT) ? std::numeric_limits<UnsignedT>::max() : (1<<upper_bitwidth)-1
        );
        for (size_t i = 0; i < buffer_count; ++i) {
            buffer[i] = dist(engine) | mask;
        }
    }




    template<typename T>
    void fill_buffer_with_zero(T* buffer, size_t buffer_count) {
        for (size_t i = 0; i < buffer_count; ++i) {
            buffer[i] = 0;
        }
    }

    template<typename T, typename RetT = typename std::conditional_t<(sizeof(T) < 4),
            std::make_unsigned_t < T>, std::conditional_t<(sizeof(T) == 4), uint32_t, uint64_t>>>
    void fill_buffers_random(T *in, RetT *out_fpga, size_t buffer_count) {
        auto casted_in = reinterpret_cast<RetT *>(in);
        std::mt19937 engine(0xc01dbadc00ffee);
        std::uniform_int_distribution <RetT> dist(0, std::numeric_limits<RetT>::max());
        for (size_t i = 0; i < buffer_count; ++i) {
            casted_in[i] = dist(engine);
            out_fpga[i] = 0x80;
        }
    }

    enum class MALLOC_TARGET {
        HOST,
        DEVICE
    };

    template<typename T>
    auto create_buffer(queue *q, MALLOC_TARGET target, size_t buffer_size, size_t alignment = 0) {
        T * buffer;
        if (target == MALLOC_TARGET::HOST) {
          if (alignment == 0) {
            if ((buffer = malloc_host<T>(buffer_size, *q)) == nullptr) {
              std::cerr << "ERROR: could not allocate space on host" << std::endl;
              std::terminate();
            }
          } else {
            if ((buffer = aligned_alloc_host<T>(alignment, buffer_size, *q)) == nullptr) {
              std::cerr << "ERROR: could not allocate space on host" << std::endl;
              std::terminate();
            }
          }
        } else {
          if (alignment == 0) {
            if ((buffer = malloc_device<T>(buffer_size, *q)) == nullptr) {
              std::cerr << "ERROR: could not allocate space on device" << std::endl;
              std::terminate();
            }
          } else {
            if ((buffer = aligned_alloc_device<T>(alignment, buffer_size, *q)) == nullptr) {
              std::cerr << "ERROR: could not allocate space on device" << std::endl;
              std::terminate();
            }
          }
        }
        return buffer;
    }

    template<typename T>
    auto create_buffers_with_host(queue *q, size_t buffer_size = 0) {
        using FPGAT = tsl::simd<T, tsl::oneAPIfpga, 128>;
        T *in;
        T *out_fpga;
        T *out_cpu;
        size_t buffer_count;
        if (buffer_size == 0) {
            buffer_count = (sizeof(T) * CHAR_BIT);
            if (buffer_count < FPGAT::vector_element_count()) {
                buffer_count = FPGAT::vector_element_count(); //Now we have at least as many elements within our buffers as fit into 2 single vectors
            }
            buffer_count <<= 1; //As we start our test with 0 we want to test 1 element more than the number of digits.
        } else {
            buffer_count = buffer_size / sizeof(T);
        }

        // Allocate input/output data in pinned host memory / USM
        if ((in = malloc_host<T>(buffer_count, *q)) == nullptr) {
            std::cerr << "ERROR: could not allocate space for 'in'" << std::endl;
            std::terminate();
        }
        if ((out_fpga = malloc_host<T>(buffer_count, *q)) == nullptr) {
            std::cerr << "ERROR: could not allocate space for 'out_fpga'" << std::endl;
            std::terminate();
        }
        if ((out_cpu = malloc_host<T>(buffer_count, *q)) == nullptr) {
            std::cerr << "ERROR: could not allocate space for 'out_cpu'" << std::endl;
            std::terminate();
        }
        return std::make_tuple(in, out_fpga, out_cpu, buffer_count);
    }

    template<typename T>
    auto create_buffers(queue *q, size_t buffer_size = 0) {
        using FPGAT = tsl::simd<T, tsl::oneAPIfpga, 128>;
        T *in;
        T *out_fpga;
        size_t buffer_count;
        if (buffer_size == 0) {
            buffer_count = (sizeof(T) * CHAR_BIT);
            if (buffer_count < FPGAT::vector_element_count()) {
                buffer_count = FPGAT::vector_element_count(); //Now we have at least as many elements within our buffers as fit into 2 single vectors
            }
            buffer_count <<= 1; //As we start our test with 0 we want to test 1 element more than the number of digits.
        } else {
            buffer_count = buffer_size / sizeof(T);
        }

        // Allocate input/output data in pinned host memory / USM
        if ((in = malloc_host<T>(buffer_count, *q)) == nullptr) {
            std::cerr << "ERROR: could not allocate space for 'in'" << std::endl;
            std::terminate();
        }
        if ((out_fpga = malloc_host<T>(buffer_count, *q)) == nullptr) {
            std::cerr << "ERROR: could not allocate space for 'out_fpga'" << std::endl;
            std::terminate();
        }
        return std::make_tuple(in, out_fpga, buffer_count);
    }

    template<typename T, typename RetT>
    void remove_buffers(queue *q, T *in, RetT *out_fpga, RetT *out_cpu) {
        sycl::free(out_cpu, *q);
        sycl::free(out_fpga, *q);
        sycl::free(in, *q);
    }

    template<typename T, typename RetT>
    void remove_buffers(queue *q, T *in, RetT *out_fpga) {
        sycl::free(out_fpga, *q);
        sycl::free(in, *q);
    }
    
    template<typename T>
    void remove_buffer(queue *q, T *buff) {
        sycl::free(buff, *q);
    }
}
#endif
