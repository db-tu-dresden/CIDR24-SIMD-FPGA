#ifndef TEST_CIDR_AGG_DATA_HPP
#define TEST_CIDR_AGG_DATA_HPP

#define FLUSH_SIZE 256*1024*1024

#include <cstdint>
#include <cstddef>
#include <random>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

namespace tuddbs{
  std::mt19937 generator(0x133742CAFFEEBABE);

  std::vector<size_t> data_sizes{4*1024, 4*1024*1024, 4ULL*1024*1024*1024};
  // std::vector<size_t> selectivities{0,20,40,60,80,100};
  std::vector<size_t> selectivities{0,50, 100};

  std::string beautify_size(size_t size) {
    if (size <= 1024) {
      return std::to_string(size) + "B";
    } else if ( size <= 1024*1024) {
      return std::to_string(size/1024) + "KiB";
    } else if ( size <= 1024*1024*1024) {
      return std::to_string(size/(1024*1024)) + "MiB";
    } else {
      return std::to_string(size/(1024*1024*1024)) + "GiB";
    }
  }

  template<typename T>
  size_t get_bitcount(size_t data_size) {
    return data_size / sizeof(T);
  }
  template<typename T>
  size_t get_bitmask_size(size_t data_size) {
    auto const element_count = get_bitcount<T>(data_size);
    //element count = number of bits;
    return element_count / 8;
  }

  template<typename T>
  std::string get_data_filename_from_size(size_t size, bool is_flush) {
    std::string filename("data_");
    if (is_flush) {
      filename += "flush_";
    }
    if (sizeof(T) == 1) {
      filename += "uint8_";
    } else if (sizeof(T) == 2) {
      filename += "uint16_";
    } else if (sizeof(T) == 4) {
      filename += "uint32_";
    } else if (sizeof(T) == 8) {
      filename += "uint64_";
    } else {
      filename += "UNKNOWNTYPE_";
    }
    filename += beautify_size(size);
    filename += ".dat";
    return filename;
  }

  template<typename T>
  std::string get_bitmask_filename_from_size_and_selectivity(size_t size, size_t selectivity, bool is_flush) {
    std::string filename("bitmask_");
    if (is_flush) {
      filename += "flush_";
    } else {
      filename += std::to_string(selectivity);
      filename += "_";
    }
    if (sizeof(T) == 1) {
      filename += "uint8_";
    } else if (sizeof(T) == 2) {
      filename += "uint16_";
    } else if (sizeof(T) == 4) {
      filename += "uint32_";
    } else if (sizeof(T) == 8) {
      filename += "uint64_";
    } else {
      filename += "UNKNOWNTYPE_";
    }
    filename += beautify_size(size);
    filename += "_";
    filename += beautify_size(get_bitmask_size<T>(size));
    filename += ".dat";
    return filename;
  }

  void write_bytes_to_file(void const * data, size_t size, std::string const & filename) {
    std::ofstream out(filename, std::ofstream::out|std::ios::binary);
    std::cerr << "Writing " << filename << std::endl;
    out.write(reinterpret_cast<char const *>(data), size);
    out.close();
  }

  void read_bytes_from_file(void * data, size_t size, std::string const & filename) {
    std::cerr << "Opening " << filename << std::endl;
    std::ifstream in(filename, std::ifstream::in|std::ios::binary);
    if (!in.is_open()) {
      std::cerr << "Could not open " << filename << std::endl;
      exit(1);
    }
    std::cerr << "Reading " << filename << std::endl;
    in.read(reinterpret_cast<char *>(data), size);
    in.close();
  }

}

#endif