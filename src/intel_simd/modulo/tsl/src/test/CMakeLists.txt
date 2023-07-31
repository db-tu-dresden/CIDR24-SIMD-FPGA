cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(tsl_test
   catch_manager.cpp
   compare_unit_test.cpp
   binary_unit_test.cpp
   calc_unit_test.cpp
   ls_unit_test.cpp
   mask_unit_test.cpp
   convert_unit_test.cpp
)
target_compile_features(tsl_test PUBLIC cxx_std_17)
target_link_libraries(tsl_test tsl)
