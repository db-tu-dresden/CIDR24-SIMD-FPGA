#ifndef TEST_CIDR_AGG_DATAGEN_HPP
#define TEST_CIDR_AGG_DATAGEN_HPP
#include <cstdint>
#include <cstddef>
#include <random>
#include <algorithm>
#include <iostream>
#include "data.hpp"

namespace tuddbs{

  void generate_bm_values(uint8_t * data, size_t bit_count, size_t selectivity, std::mt19937& generator) {
    if (selectivity == 0) {
      std::fill(data, data + (bit_count/8), 0);
      return;
    }
    if (selectivity == 100) {
      std::fill(data, data + (bit_count/8), 0xFF);
      return;
    }
    auto tmp_buffer = reinterpret_cast<uint8_t *>(malloc(bit_count));
    // std::cerr << "Bit count: " << bit_count << std::endl; 
    // std::cerr << "Selectivity: " << selectivity << std::endl; 
    // std::cerr << "max i = " << (selectivity * bit_count) << std::endl;  
    for (size_t i = 0; i < (((float)selectivity/100) * bit_count); ++i) {
      tmp_buffer[i] = 1;
    }
    std::shuffle(tmp_buffer, tmp_buffer + bit_count, generator);
    for (size_t i = 0; i < bit_count; i+=8 ) {
      uint8_t val = 0;
      for (size_t j = 0; j < 8; ++j) {
        val |= tmp_buffer[i+j] << j;
      }
      *data = val;
      ++data;
    }
    free(tmp_buffer);
  }

  template<typename T>
    void generate_values(T * data, size_t element_count, std::mt19937& generator) {
      std::uniform_int_distribution<T> distribution(1, 4);
      for (size_t i = 0; i < element_count; ++i) {
        // data[i] = distribution(generator);
        data[i] = (T)1;
      }
    }

}


#endif //TEST_CIDR_AGG_DATAGEN_HPP