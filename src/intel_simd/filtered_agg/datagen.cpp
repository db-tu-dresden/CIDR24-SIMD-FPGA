#include "../include/datagen.hpp"
#include "../include/data.hpp"

template<typename T>
void generate_data() {
  for (auto const size : tuddbs::data_sizes) {
    // Data
    {
      auto data_filename = tuddbs::get_data_filename_from_size<T>(size, false);
      auto data = reinterpret_cast<T *>(malloc(size));
      std::cerr << "Generating " << data_filename << std::endl;
      tuddbs::generate_values<T>(data, size / sizeof(T), tuddbs::generator);
      std::ofstream data_ostream(data_filename, std::ofstream::out|std::ios::binary);
      std::cerr << "Writing " << data_filename << std::endl;
      data_ostream.write(reinterpret_cast<char *>(data), size);
      data_ostream.close();
      free(data);
    }
    {
      auto flush_data_filename = tuddbs::get_data_filename_from_size<T>(FLUSH_SIZE, true);
      auto flush_data = reinterpret_cast<T *>(malloc(FLUSH_SIZE));
      std::cerr << "Generating " << flush_data_filename << std::endl;
      tuddbs::generate_values<T>(flush_data, FLUSH_SIZE / sizeof(T), tuddbs::generator);
      std::ofstream flush_data_ostream(flush_data_filename, std::ofstream::out|std::ios::binary);
      std::cerr << "Writing " << flush_data_filename << std::endl;
      flush_data_ostream.write(reinterpret_cast<char *>(flush_data), size);
      flush_data_ostream.close();
      free(flush_data);
    }
    // Bitmasks
    {
      for (auto const selectivity : tuddbs::selectivities) {
        auto bm_filename = tuddbs::get_bitmask_filename_from_size_and_selectivity<T>(size, selectivity, false);
        auto bm = reinterpret_cast<uint8_t *>(malloc(tuddbs::get_bitmask_size<T>(size)));
        std::cerr << "Generating " << bm_filename << std::endl;
        tuddbs::generate_bm_values(bm, tuddbs::get_bitcount<T>(size), selectivity, tuddbs::generator);
        std::ofstream bm_ostream(bm_filename, std::ofstream::out|std::ios::binary);
        std::cerr << "Writing " << bm_filename << std::endl;
        bm_ostream.write(reinterpret_cast<char *>(bm), tuddbs::get_bitmask_size<T>(size));
        bm_ostream.close();
        free(bm);
      }
    }
    {
      auto flush_bm_filename = tuddbs::get_bitmask_filename_from_size_and_selectivity<T>(FLUSH_SIZE, 1, true);
      auto flush_bm = reinterpret_cast<uint8_t *>(malloc(tuddbs::get_bitmask_size<T>(FLUSH_SIZE)));
      std::cerr << "Generating " << flush_bm_filename << std::endl;
      tuddbs::generate_bm_values(flush_bm, tuddbs::get_bitcount<T>(FLUSH_SIZE), 1, tuddbs::generator);
      std::ofstream flush_bm_ostream(flush_bm_filename, std::ofstream::out|std::ios::binary);
      
      flush_bm_ostream.write(reinterpret_cast<char *>(flush_bm), tuddbs::get_bitmask_size<T>(FLUSH_SIZE));
      flush_bm_ostream.close();
      free(flush_bm);
    }
  }

}
int main() {
  generate_data<uint8_t>();
  generate_data<uint16_t>();
  generate_data<uint32_t>();
  generate_data<uint64_t>();
  return 0;
}
