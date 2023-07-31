cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE ON)
add_library(tsl INTERFACE)
#set_target_properties(tsl PROPERTIES CXX_STANDARD 20)
target_compile_features(tsl INTERFACE cxx_std_20)

target_sources(tsl
   INTERFACE include/static/tsl_static.hpp
   INTERFACE include/tslintrin.hpp
   INTERFACE include/static/simd/simd_type.hpp
   INTERFACE include/static/simd/simd_type_concepts.hpp
   INTERFACE include/static/simd/simd_primitive_concepts.hpp
   INTERFACE include/static/utils/functional.hpp
   INTERFACE include/static/utils/type_concepts.hpp
   INTERFACE include/static/utils/type_helper.hpp
   INTERFACE include/static/utils/preprocessor.hpp
   INTERFACE include/generated/tsl_generated.hpp
   INTERFACE include/generated/extensions/simd/intel/oneAPIfpgaRTL.hpp
   INTERFACE include/generated/extensions/scalar.hpp
   INTERFACE include/generated/extensions/simd/intel/oneAPIfpga.hpp
   INTERFACE include/generated/declarations/ls.hpp
   INTERFACE include/generated/declarations/convert.hpp
   INTERFACE include/generated/declarations/memory.hpp
   INTERFACE include/generated/declarations/mask.hpp
   INTERFACE include/generated/declarations/compare.hpp
   INTERFACE include/generated/declarations/complex.hpp
   INTERFACE include/generated/declarations/binary.hpp
   INTERFACE include/generated/declarations/calc.hpp
   INTERFACE include/generated/declarations/misc.hpp
   INTERFACE include/generated/definitions/ls/ls_scalar.hpp
   INTERFACE include/generated/definitions/ls/ls_oneAPIfpga.hpp
   INTERFACE include/generated/definitions/ls/ls_oneAPIfpgaRTL.hpp
   INTERFACE include/generated/definitions/convert/convert_scalar.hpp
   INTERFACE include/generated/definitions/convert/convert_oneAPIfpga.hpp
   INTERFACE include/generated/definitions/convert/convert_oneAPIfpgaRTL.hpp
   INTERFACE include/generated/definitions/memory/memory_scalar.hpp
   INTERFACE include/generated/definitions/mask/mask_scalar.hpp
   INTERFACE include/generated/definitions/mask/mask_oneAPIfpga.hpp
   INTERFACE include/generated/definitions/mask/mask_oneAPIfpgaRTL.hpp
   INTERFACE include/generated/definitions/compare/compare_scalar.hpp
   INTERFACE include/generated/definitions/compare/compare_oneAPIfpga.hpp
   INTERFACE include/generated/definitions/compare/compare_oneAPIfpgaRTL.hpp
   INTERFACE include/generated/definitions/complex/complex_oneAPIfpga.hpp
   INTERFACE include/generated/definitions/complex/complex_oneAPIfpgaRTL.hpp
   INTERFACE include/generated/definitions/binary/binary_scalar.hpp
   INTERFACE include/generated/definitions/binary/binary_oneAPIfpga.hpp
   INTERFACE include/generated/definitions/binary/binary_oneAPIfpgaRTL.hpp
   INTERFACE include/generated/definitions/calc/calc_scalar.hpp
   INTERFACE include/generated/definitions/calc/calc_oneAPIfpga.hpp
   INTERFACE include/generated/definitions/calc/calc_oneAPIfpgaRTL.hpp
   INTERFACE include/generated/definitions/misc/misc_scalar.hpp
   INTERFACE include/generated/definitions/misc/misc_oneAPIfpga.hpp
   INTERFACE include/generated/definitions/misc/misc_oneAPIfpgaRTL.hpp
)
target_include_directories(tsl INTERFACE include/)
target_compile_options(tsl INTERFACE  -Wno-ignored-attributes -Wno-attributes -Wno-deprecated-declarations -flax-vector-conversions)
target_compile_definitions(tsl INTERFACE TSL_USE_CONCEPTS)
if (DEFINED TSL_LINK_OPTIONS)
   target_link_options(tsl INTERFACE ${TSL_LINK_OPTIONS})
endif()

# Add subdirectories containing supplementary libraries
add_subdirectory(supplementary/oneApiFPGA)
# Add includes if present
#target_include_directories(tsl INTERFACE supplementary/oneApiFPGA/include/)
target_include_directories(tsl INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/supplementary/oneApiFPGA/include> $<INSTALL_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/supplementary/oneApiFPGA/include )
# Add custom targets for supplementary libraries
add_dependencies(tsl libtslOneAPIFPGA)
