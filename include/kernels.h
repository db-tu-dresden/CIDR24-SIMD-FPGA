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
#ifndef CIDR24_KERNELS_H
#define CIDR24_KERNELS_H

namespace tuddbs {

  template<typename SimdT, typename InPtrT, typename OutPtrT>
    void leading_zero_count_kernel(
        OutPtrT out_ptr, InPtrT data_ptr, std::size_t element_count
    ) {
        auto const data_ptr_end = data_ptr + element_count;
        for (;data_ptr < data_ptr_end; data_ptr += SimdT::vector_element_count()) {
            auto const data_vec = tsl::loadu<SimdT>(data_ptr);
            auto const result_vec = tsl::lzc<SimdT>(data_vec);
            tsl::storeu<SimdT>(out_ptr, result_vec);
            out_ptr += SimdT::vector_element_count();
        }
    }

  template<typename SimdT, typename InPtrT, typename OutPtrT>
    void packbits_linear(
        OutPtrT out_ptr, InPtrT data_ptr, unsigned bitwidth, std::size_t element_count
    ) {
      // for the moment we make the following assumptions:
      // - bitwidth is const for whole data
      // - element_count is a multiple of SimdT::vector_element_count()
      using namespace tsl;
      auto const end_data_ptr = data_ptr + element_count;
      auto const offset_stepwidth = SimdT::vector_element_count() * bitwidth;
      while (data_ptr < end_data_ptr) {
        auto const chunk_end = data_ptr + SimdT::vector_size_b();
        typename SimdT::register_type result_vec{};
        int overflow;
        typename SimdT::register_type overflow_vec{};
        auto current_offset = 0;
        for(; data_ptr < chunk_end; data_ptr += SimdT::vector_element_count()){
          const auto data_vec = loadu<SimdT>(data_ptr);
          std::tie(result_vec, overflow, overflow_vec) = pack_bits_linear_merge<SimdT>(result_vec, current_offset, data_vec, bitwidth);
          if(overflow != -1){
            storeu<SimdT>(out_ptr, result_vec);
            out_ptr += SimdT::vector_element_count();
            result_vec = overflow_vec;
            current_offset = overflow;
          } else {
            current_offset += offset_stepwidth;
          }
        }
      }
    }
  
  template<typename SimdT, typename InPtrT, typename OutPtrT>
    void packbits_treelike(
        OutPtrT out_ptr, InPtrT data_ptr, unsigned bitwidth, std::size_t element_count
    ) {
      // for the moment we make the following assumptions:
      // - bitwidth is const for whole data
      // - element_count is a multiple of SimdT::vector_element_count()
      using namespace tsl;
      auto const end_data_ptr = data_ptr + element_count;
      auto const offset_stepwidth = SimdT::vector_element_count() * bitwidth;
      while (data_ptr < end_data_ptr) {
        auto const chunk_end = data_ptr + SimdT::vector_size_b();
        typename SimdT::register_type result_vec{};
        int overflow;
        typename SimdT::register_type overflow_vec{};
        auto current_offset = 0;
        for(; data_ptr < chunk_end; data_ptr += SimdT::vector_element_count()){
          const auto data_vec = loadu<SimdT>(data_ptr);
          std::tie(result_vec, overflow, overflow_vec) = pack_bits_treelike_merge<SimdT>(result_vec, current_offset, data_vec, bitwidth);
          if(overflow != -1){
            storeu<SimdT>(out_ptr, result_vec);
            out_ptr += SimdT::vector_element_count();
            result_vec = overflow_vec;
            current_offset = overflow;
          } else {
            current_offset += offset_stepwidth;
          }
        }
      }
    }

  template<typename SimdT, typename InPtrT, typename BufferPtrT, typename OutPtrT, typename OutBwPtrT>
    size_t bitpacking_FPGA_specialized_compress(
      OutPtrT out_cmpr_ptr, 
      OutBwPtrT out_bw_ptr,
      InPtrT data_ptr, BufferPtrT data_buffer_ptr, std::size_t batch_element_count, std::size_t element_count
    ) {
      // for the moment we make the following assumptions:
      // - element_count is a multiple of SimdT::vector_element_count()
      using namespace tsl;
      using UnsignedSimdT = typename SimdT::template transform_extension<typename SimdT::offset_base_type>;
  
      auto const out_bw_ptr_orig = out_bw_ptr;
      auto const end_data_ptr = data_ptr + element_count;
      auto current_offset = 0;
      typename SimdT::register_type result_vec{};
      int overflow;
      typename SimdT::register_type overflow_vec{};
      for (;data_ptr < end_data_ptr; data_ptr += batch_element_count) {
        typename SimdT::register_type logical_ORed_data{};
        for (size_t i = 0; i < batch_element_count; i += SimdT::vector_element_count()) {
          auto const data_vec = loadu<SimdT>(data_ptr + i);
          logical_ORed_data = binary_or<SimdT>(logical_ORed_data, data_vec);
          storeu<SimdT>(data_buffer_ptr + i, data_vec);
        }
        auto leading_zero_count = lzc<SimdT>(logical_ORed_data);
        // storeu<UnsignedSimdT>(out_bw_ptr, leading_zero_count);
        // out_bw_ptr += UnsignedSimdT::vector_element_count();
        auto minimum_leading_zero_count = hmin<UnsignedSimdT>(leading_zero_count);
        unsigned const bitwidth = (sizeof(typename SimdT::base_type)*CHAR_BIT) - minimum_leading_zero_count;
        *out_bw_ptr++ = bitwidth;
        auto const offset_stepwidth = SimdT::vector_element_count() * bitwidth;
        for (size_t i = 0; i < batch_element_count; i += SimdT::vector_element_count()) {
          auto const data_vec = loadu<SimdT>(data_buffer_ptr + i);
          std::tie(result_vec, overflow, overflow_vec) = pack_bits_linear_merge<SimdT>(result_vec, current_offset, data_vec, bitwidth);
          if(overflow != -1){
            storeu<SimdT>(out_cmpr_ptr, result_vec);
            out_cmpr_ptr += SimdT::vector_element_count();
            result_vec = overflow_vec;
            current_offset = overflow;
          } else {
            current_offset += offset_stepwidth;
          }
        }
      }
      if (current_offset != 0) {
        storeu<SimdT>(out_cmpr_ptr, result_vec);
        out_cmpr_ptr += SimdT::vector_element_count();
      }
      return out_bw_ptr - out_bw_ptr_orig;
    }

  template<typename SimdT, typename InPtrT, typename BufferPtrT, typename OutPtrT, typename OutBwPtrT>
    size_t bitpacking_horizontal_compress(
      OutPtrT out_cmpr_ptr,
      OutBwPtrT out_bw_ptr,
      InPtrT data_ptr, BufferPtrT data_buffer_ptr, std::size_t element_count
    ) {
      using namespace tsl;

      std::size_t batch_element_count = SimdT::vector_size_b();
      auto const end_data_ptr = data_ptr + element_count;

      for (;data_ptr < end_data_ptr; data_ptr += batch_element_count) {
        typename SimdT::register_type logical_ORed_data{};
        for (std::size_t i = 0; i < batch_element_count; i += SimdT::vector_element_count()) {
          auto const data_vec = loadu<SimdT>(data_ptr + i);
          logical_ORed_data = binary_or<SimdT>(logical_ORed_data, data_vec);
          storeu<SimdT>(data_buffer_ptr + i, data_vec); //this is not part of the classic implementation. However, as we want ONE code base for all kernels, we need to store the data in the buffer to be able to process it from the FPGA
        }
        auto logical_ORed = hor<SimdT>(logical_ORed_data);
      }
    }
    
}

#endif //CIDR24_KERNELS_H