#ifndef SRC_INTEL_SIMD_INCLUDE_UTILS_HPP
#define SRC_INTEL_SIMD_INCLUDE_UTILS_HPP
#include <chrono>
#include <sys/stat.h>
#include <string>
#include <regex>
#include <iostream>
#include <iomanip>
#include <fstream>
		
constexpr long operator""_B(unsigned long long const x) {
  return x;
}

constexpr long operator""_KiB(unsigned long long const x) {
  return 1024L * x;
}

constexpr long operator""_MiB(unsigned long long const x) {
  return 1024L * 1024L * x;
}

constexpr long operator""_GiB(unsigned long long const x) {
  return 1024L * 1024L * 1024L * x;
}

constexpr long operator""_KB(unsigned long long const x) {
  return 1000 * x;
}

constexpr long operator""_MB(unsigned long long const x) {
  return 1000L * 1000L * x;
}

constexpr long operator""_GB(unsigned long long const x) {
  return 1000L * 1000L * 1000L * x;
}

std::ostream& data_size_to_ostream(std::ostream& out, size_t data_size) {
  if (data_size < 1024) {
    out << data_size << " B";
  } else if (data_size < 1024 * 1024) {
    out << data_size / 1024 << " KiB";
  } else if (data_size < 1024 * 1024 * 1024) {
    out << data_size / (1024 * 1024) << " MiB";
  } else {
    out << data_size / (1024 * 1024 * 1024) << " GiB";
  }
  return out;
}

namespace tuddbs {
  size_t strToByte(std::string param) {
    std::regex opt_ex("([0-9]*)([a-zA-Z]*)");
    std::smatch matches;
    size_t multiplier = 1;
    size_t size = 0;
    std::map<std::string, size_t> suffixes = {
      {"kib", 1024},
      {"mib", 1024 * 1024},
      {"gib", 1024 * 1024 * 1024}};
    if (std::regex_search(param, matches, opt_ex)) {
      size = stoll(matches[1].str());
      std::string suffix = matches[2].str();
      std::transform(suffix.begin(), suffix.end(), suffix.begin(), [](unsigned char c) { return std::tolower(c); });
      bool found_suffix = false;
      for (auto pair : suffixes) {
        if (pair.first == suffix) {
          multiplier = pair.second;
          found_suffix = true;
          break;
        }
      }
      if (!found_suffix) {
        std::cerr << "Unrecognized suffix: " << param << std::endl;
        exit(-1);
      }
    } else {
      std::cerr << "Inproper command. Could not deduce size for: " << param << std::endl;
      exit(-2);
    }
    return size * multiplier;
  }

  std::string get_cpu_name() {
    std::regex cpu_regex("model name\\s*:\\s*(.*)");
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;
    std::smatch matches;

    while (std::getline(cpuinfo, line)) {
      if (std::regex_search(line, matches, cpu_regex)) {
        return matches[1].str();
      }
    }
    return "Unknown CPU";
  }
}  // namespace tuddbs

namespace file_logging {
  static std::ofstream current_log_file;

  // Variadic output of custom values
  template<bool flush, typename Logging, typename... Loggings>
    void log_to_file(Logging arg, Loggings... args) {
      current_log_file << arg;
      using expander = int[];
      (void)expander{0, (void(current_log_file << '\t' << std::forward<Loggings>(args)), 0)...};
      if ( flush ) current_log_file << std::endl;
    };

  template <typename T>
    auto concat_pointer_to_string(T const * ptr, size_t count, size_t start = 0) {
      std::stringstream ss;
      auto data = ptr + start;
      ss << "[";
      for (size_t i = 0; i < count; ++i) {
        ss << data[i];
        if (i < count - 1) {
          ss << ", ";
        }
      }
      ss << "]";
      return ss.str();
    }

  std::string get_current_time_as_string() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d_%H-%M-%S");
    return ss.str();
  }

  void open_log_file(std::string path_to_file) {
    // std::filesystem::path path(path_to_file);
    // const std::string bufferPath = path.remove_filename();
    // std::filesystem::create_directories(bufferPath);
    current_log_file.open(path_to_file, std::ios::app);
    if (!current_log_file.is_open()) {
      std::cerr << "Could not open log file: \"" << path_to_file << "\" Terminating." << std::endl;
      exit(-20);
    }
  }

  void close_log_file() {
    current_log_file.close();
  }
}  // namespace file_logging

namespace tuddbs{ 

  auto current_time() {
    return std::chrono::high_resolution_clock::now();
  }
  auto time_diff(std::chrono::high_resolution_clock::time_point const & start, std::chrono::high_resolution_clock::time_point const & end) {
    return static_cast<size_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
  }

  auto throughput(size_t data_size_in_byte, size_t time_in_ns) {
    return (static_cast<double>(data_size_in_byte) / (1024.0*1024.0)) / (static_cast<double>(time_in_ns) / 1000000000.0);
  }

  bool fileExists(const char * filename) {
    struct stat buf;
    if (stat(filename, &buf) != -1) {
      return true;
    }
    return false;
  }
}
#endif //SRC_INTEL_SIMD_INCLUDE_UTILS_HPP