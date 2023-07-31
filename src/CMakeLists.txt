##############################################
#                Working tests               #
##############################################
# create_fpga_emu_target(test_pack_bits ${CMAKE_CURRENT_SOURCE_DIR}/pack_bits_test.cpp)
# create_fpga_emu_target(test_lzc ${CMAKE_CURRENT_SOURCE_DIR}/lzc_test.cpp)
# create_fpga_emu_target(test_bitpacking ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp)





if (DEFINED BATCH_BUILD)
  # create_fpga_target(bench_hadd_smallInt ${CMAKE_CURRENT_SOURCE_DIR}/hadd_test.cpp DEFINITIONS UI8 UI16)
  create_fpga_target(bench_hadd_bigInt ${CMAKE_CURRENT_SOURCE_DIR}/hadd_test.cpp DEFINITIONS UI32)

  # create_fpga_target(bench_filter_ui8_128   ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI8 ELC16)
  # create_fpga_target(bench_filter_ui8_256   ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI8 ELC32)
  # create_fpga_target(bench_filter_ui8_512   ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI8 ELC64)
  # create_fpga_target(bench_filter_ui8_1024  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI8 ELC128)
  # create_fpga_target(bench_filter_ui8_2048  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI8 ELC256)

  # create_fpga_target(bench_filter_ui16_128  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI16 ELC8)
  # create_fpga_target(bench_filter_ui16_256  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI16 ELC16)
  # create_fpga_target(bench_filter_ui16_512  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI16 ELC32)
  # create_fpga_target(bench_filter_ui16_1024 ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI16 ELC64)
  # create_fpga_target(bench_filter_ui16_2048 ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI16 ELC128)

  # create_fpga_target(bench_filter_ui32_128  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI32 ELC4)
  # create_fpga_target(bench_filter_ui32_256  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI32 ELC8)
  create_fpga_target(bench_filter_ui32_512  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI32 ELC16)
  create_fpga_target(bench_specific_filter_ui32_512  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/specific_oneAPI.cpp)
  # create_fpga_target(bench_filter_ui32_1024 ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI32 ELC32)
  # create_fpga_target(bench_filter_ui32_2048 ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI32 ELC64)

  # create_fpga_target(bench_filter_ui64_128  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI64 ELC2)
  # create_fpga_target(bench_filter_ui64_256  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI64 ELC4)
  # create_fpga_target(bench_filter_ui64_512  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI64 ELC8)
  # create_fpga_target(bench_filter_ui64_1024 ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI64 ELC16)
  # create_fpga_target(bench_filter_ui64_2048 ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI64 ELC32)

  create_fpga_target(bench_aggregate_plain ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/aggregate_bench_oneApi.cpp DEFINITIONS UI32 UI64)

  create_fpga_target(bench_aggregate_autovec_ui64 ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp DEFINITIONS UI64 VL128 VL256 VL512)


  
  # create_fpga_target(bench_conflict_detection_ui16 ${CMAKE_CURRENT_SOURCE_DIR}/conflict_detection_test.cpp DEFINITIONS UI16)
  create_fpga_target(bench_conflict_detection_ui32 ${CMAKE_CURRENT_SOURCE_DIR}/conflict_detection_test.cpp DEFINITIONS UI32)
  # create_fpga_target(bench_conflict_detection_ui64 ${CMAKE_CURRENT_SOURCE_DIR}/conflict_detection_test.cpp DEFINITIONS UI64)
  create_fpga_target(bench_specific_conflict_detection_ui32_512 ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_test_u32_512.cpp)
  create_fpga_target(bench_specific_conflict_detection_ui64_512 ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_test_u64_512.cpp)
  create_fpga_target(bench_specific_conflict_detection_ui64_1024 ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_test_u64_1024.cpp)
  create_fpga_target( bench_specific_conflict_detection_ui32_512_outDevice  ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_test_u32_512.cpp DEFINITIONS FPGA_WRITE_TO_DEV)
  create_fpga_target( bench_specific_conflict_detection_ui64_512_outDevice  ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_test_u64_512.cpp DEFINITIONS FPGA_WRITE_TO_DEV)
  create_fpga_target(bench_specific_conflict_detection_ui64_1024_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_test_u64_1024.cpp DEFINITIONS FPGA_WRITE_TO_DEV)

  create_fpga_target(bench_specific_conflict_detection_and_aggregate_ui32_512  ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_and_aggregate_test_u32_512.cpp)
  create_fpga_target(bench_specific_conflict_detection_and_aggregate_ui64_512  ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_and_aggregate_test_u64_512.cpp)
  create_fpga_target(bench_specific_conflict_detection_and_aggregate_ui64_1024 ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_and_aggregate_test_u64_1024.cpp)

  create_fpga_target(bench_modulo_ui32 ${CMAKE_CURRENT_SOURCE_DIR}/modulo_test.cpp DEFINITIONS UI32 VL512 VL1024)
  create_fpga_target(bench_modulo_ui64 ${CMAKE_CURRENT_SOURCE_DIR}/modulo_test.cpp DEFINITIONS UI64 VL512 VL1024)
  create_fpga_target(bench_modulo_ui32_512_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/modulo_test.cpp DEFINITIONS UI32 VL512 FPGA_WRITE_TO_DEV)
  create_fpga_target(bench_modulo_ui64_512_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/modulo_test.cpp DEFINITIONS UI64 VL512 FPGA_WRITE_TO_DEV)
  create_fpga_target(bench_modulo_ui32_512_and_aggregate_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/modulo_test_and_aggregate.cpp DEFINITIONS UI32 VL512 FPGA_WRITE_TO_DEV)
  create_fpga_target(bench_modulo_ui64_512_and_aggregate_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/modulo_test_and_aggregate.cpp DEFINITIONS UI64 VL512 FPGA_WRITE_TO_DEV)

  create_fpga_target( bench_lzc_ui32_512 ${CMAKE_CURRENT_SOURCE_DIR}/lzc_test.cpp DEFINITIONS UI32 VL512)
  create_fpga_target(bench_lzc_ui32_1024 ${CMAKE_CURRENT_SOURCE_DIR}/lzc_test.cpp DEFINITIONS UI32 VL1024)
  create_fpga_target( bench_lzc_ui64_512 ${CMAKE_CURRENT_SOURCE_DIR}/lzc_test.cpp DEFINITIONS UI64 VL512)
  create_fpga_target(bench_lzc_ui64_1024 ${CMAKE_CURRENT_SOURCE_DIR}/lzc_test.cpp DEFINITIONS UI64 VL1024)

  create_fpga_target(bench_lzc_ui32_512_unrolled_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/lzc_unrolled_test.cpp DEFINITIONS UI32 VL512 FPGA_WRITE_TO_DEV)
  create_fpga_target(bench_lzc_ui32_1024_unrolled_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/lzc_unrolled_test.cpp DEFINITIONS UI32 VL1024 FPGA_WRITE_TO_DEV)
  create_fpga_target(bench_lzc_ui64_512_unrolled_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/lzc_unrolled_test.cpp DEFINITIONS UI64 VL512 FPGA_WRITE_TO_DEV)
  create_fpga_target(bench_lzc_ui64_1024_unrolled_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/lzc_unrolled_test.cpp DEFINITIONS UI64 VL1024 FPGA_WRITE_TO_DEV)

  create_fpga_target( bench_lzc_ui32_512_unrolled_and_aggregate_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/lzc_unrolled_and_aggregate_test.cpp DEFINITIONS UI32 VL512 FPGA_WRITE_TO_DEV)
  create_fpga_target(bench_lzc_ui32_1024_unrolled_and_aggregate_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/lzc_unrolled_and_aggregate_test.cpp DEFINITIONS UI32 VL1024 FPGA_WRITE_TO_DEV)
  create_fpga_target( bench_lzc_ui64_512_unrolled_and_aggregate_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/lzc_unrolled_and_aggregate_test.cpp DEFINITIONS UI64 VL512 FPGA_WRITE_TO_DEV)
  create_fpga_target(bench_lzc_ui64_1024_unrolled_and_aggregate_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/lzc_unrolled_and_aggregate_test.cpp DEFINITIONS UI64 VL1024 FPGA_WRITE_TO_DEV)
else()
  # create_fpga_emu_target(test_hadd_ui8 ${CMAKE_CURRENT_SOURCE_DIR}/hadd_test.cpp DEFINITIONS UI8)
  # create_fpga_emu_target(test_hadd_ui16 ${CMAKE_CURRENT_SOURCE_DIR}/hadd_test.cpp DEFINITIONS UI16)
  # create_fpga_emu_target(test_hadd_ui32 ${CMAKE_CURRENT_SOURCE_DIR}/hadd_test.cpp DEFINITIONS UI32)
  # create_fpga_emu_target(test_hadd_ui64 ${CMAKE_CURRENT_SOURCE_DIR}/hadd_test.cpp DEFINITIONS UI64)

  # create_fpga_emu_target(test_filter_ui8 ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI8)
  # create_fpga_emu_target(test_filter_ui16 ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI16)

  # create_fpga_emu_target(test_filter_ui32_512 ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI32 ELC16)
  # create_fpga_emu_target(test_specific_filter_ui32_512  ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/specific_oneAPI.cpp)

  # create_fpga_emu_target(test_filter_ui64 ${CMAKE_CURRENT_SOURCE_DIR}/intel_simd/filtered_agg/generic_oneApi.cpp DEFINITIONS UI64)

  # create_fpga_emu_target(test_conflict_detection_ui16 ${CMAKE_CURRENT_SOURCE_DIR}/conflict_detection_test.cpp DEFINITIONS UI16)
  # create_fpga_emu_target(test_conflict_detection_ui32 ${CMAKE_CURRENT_SOURCE_DIR}/conflict_detection_test.cpp DEFINITIONS UI32)
  # create_fpga_emu_target(test_conflict_detection_ui64 ${CMAKE_CURRENT_SOURCE_DIR}/conflict_detection_test.cpp DEFINITIONS UI64)

  # create_fpga_emu_target(test_bitpacking_ui8_128 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI8 VL128)
  # create_fpga_emu_target(test_bitpacking_ui8_256 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI8 VL256)
  # create_fpga_emu_target(test_bitpacking_ui8_512 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI8 VL512)
  # create_fpga_emu_target(test_bitpacking_ui8_1024 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp DEFINITIONS UI8 VL1024)
  # create_fpga_emu_target(test_bitpacking_ui8_2048 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp DEFINITIONS UI8 VL2048)

  # create_fpga_emu_target(test_bitpacking_ui16_128 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI16 VL128)
  # create_fpga_emu_target(test_bitpacking_ui16_256 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI16 VL256)
  # create_fpga_emu_target(test_bitpacking_ui16_512 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI16 VL512)
  # create_fpga_emu_target(test_bitpacking_ui16_1024 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp DEFINITIONS UI16 VL1024)
  # create_fpga_emu_target(test_bitpacking_ui16_2048 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp DEFINITIONS UI16 VL2048)

  # create_fpga_emu_target(test_bitpacking_ui32_128 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI32 VL128)
  # create_fpga_emu_target(test_bitpacking_ui32_256 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI32 VL256)
  # create_fpga_emu_target(test_bitpacking_ui32_512 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI32 VL512)
  # create_fpga_emu_target(test_bitpacking_ui32_1024 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp DEFINITIONS UI32 VL1024)
  # create_fpga_emu_target(test_bitpacking_ui32_2048 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp DEFINITIONS UI32 VL2048)

  # create_fpga_emu_target(test_bitpacking_ui64_128 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI64 VL128)
  # create_fpga_emu_target(test_bitpacking_ui64_256 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI64 VL256)
  # create_fpga_emu_target(test_bitpacking_ui64_512 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp  DEFINITIONS UI64 VL512)
  # create_fpga_emu_target(test_bitpacking_ui64_1024 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp DEFINITIONS UI64 VL1024)
  # create_fpga_emu_target(test_bitpacking_ui64_2048 ${CMAKE_CURRENT_SOURCE_DIR}/bitpacking_test.cpp DEFINITIONS UI64 VL2048)

  # create_fpga_emu_target(test_modulo_ui32 ${CMAKE_CURRENT_SOURCE_DIR}/modulo_test.cpp DEFINITIONS UI32 VL512 VL1024)
  # create_fpga_emu_target(test_modulo_ui64 ${CMAKE_CURRENT_SOURCE_DIR}/modulo_test.cpp DEFINITIONS UI64 VL512 VL1024)
  # create_fpga_emu_target(test_specific_conflict_detection_and_aggregate_ui32_512  ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_and_aggregate_test_u32_512.cpp)
  # create_fpga_emu_target(test_specific_conflict_detection_and_aggregate_ui64_512  ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_and_aggregate_test_u64_512.cpp)
  # create_fpga_emu_target(test_specific_conflict_detection_and_aggregate_ui64_1024 ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_and_aggregate_test_u64_1024.cpp)

  # create_fpga_emu_target(test_lzc_ui32outDevice ${CMAKE_CURRENT_SOURCE_DIR}/lzc_test.cpp DEFINITIONS UI32 VL512 VL1024)
  # create_fpga_emu_target(test_lzc_ui64outDevice ${CMAKE_CURRENT_SOURCE_DIR}/lzc_test.cpp DEFINITIONS UI64 VL512 VL1024)

  #create_fpga_emu_target(test_specific_conflict_detection_ui64_512_outDevice  ${CMAKE_CURRENT_SOURCE_DIR}/specific_conflict_detection_test_u64_512.cpp DEFINITIONS FPGA_WRITE_TO_DEV)

  create_fpga_emu_target( bench_lzc_ui64_512_unrolled_and_aggregate_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/lzc_unrolled_and_aggregate_test.cpp DEFINITIONS UI64 VL512 FPGA_WRITE_TO_DEV)
  create_fpga_emu_target(bench_modulo_ui64_512_and_aggregate_outDevice ${CMAKE_CURRENT_SOURCE_DIR}/modulo_test_and_aggregate.cpp DEFINITIONS UI64 VL512 FPGA_WRITE_TO_DEV)
endif()

##############################################
#                  ToDo tests                #
##############################################

# create_fpga_emu_target(test_cmp_between ${CMAKE_CURRENT_SOURCE_DIR}/cmp_between_test.cpp)
# create_fpga_emu_target(test_modulo ${CMAKE_CURRENT_SOURCE_DIR}/modulo_test.cpp)
# create_fpga_emu_target(test_multiply ${CMAKE_CURRENT_SOURCE_DIR}/multiply_test.cpp)

# create_fpga_emu_target(test_executor ${CMAKE_CURRENT_SOURCE_DIR}/executor_test.cpp)
