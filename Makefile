ALL_CXXFLAGS=-Wall -std=c++20 $(CXXFLAGS)

BOARD=intel_s10sx_pac:pac_s10_usm##<-- !!!!!!! please set me accordingly !!!!!!! 
COMPILER=icpx
COMPILER_VERSION=2022.3.1#<-- !!!!!!! please set me accordingly !!!!!!! 
PLATFORM=stratix10.graz#<-- !!!!!!! please set me accordingly !!!!!!! 
LATEST=#<-- @Christian pls delete the value: should be value LATEST on devcloud... but it just doesn't work

# Directories
INC_DIRS := ./include ./static_tsl/include ./static_tsl/supplementary/oneApiFPGA/include ./tools/benchmark/include
LIB_DIRS := build

# Defines
DEFINES := COMPILER="\"$(COMPILER)\"" VERSION="\"$(COMPILER_VERSION)\"" PLATFORM="\"$(PLATFORM)\"" $(LATEST) FPGA_HARDWARE CMAKE_EXPORT_COMPILE_COMMANDS=1 BATCH_BUILD FPGA_WRITE_TO_DEV

# Files
INCS := $(wildcard )
LIBS := tuddbs_benchmark pthread

BENCHMARK_SOURCES := $(wildcard tools/benchmark/src/*.cpp) $(wildcard tools/benchmark/src/filewriter/*.cpp) $(wildcard tools/benchmark/src/hardware/*.cpp) $(wildcard tools/benchmark/src/measurement/*.cpp)

emu_tess: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-fintelfpga -fsycl-device-code-split=off \
	-qactypes \
	-o build/$@.fpga.emu \
	src/specific_conflict_detection_test_u64_512.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)


bench_conflict_detection_unrolled_and_aggregate_ui64_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/specific_conflict_detection_test_u64_512.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_conflict_detection_unrolled_and_aggregate_ui64_VL1K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/specific_conflict_detection_test_u64_1024.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_conflict_detection_unrolled_and_aggregate_ui32_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/specific_conflict_detection_test_u32_512.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_plain_bigint: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_plain_smallint: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_smallint_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_smallint_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_smallint_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_smallint_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_smallint_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_smallint_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_smallint_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_smallint_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_bigint_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_bigint_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_bigint_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_bigint_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_bigint_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_bigint_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_bigint_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_bigint_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui8_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui8_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui8_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui8_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui8_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui8_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui8_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui8_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui16_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui16_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui16_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui16_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui16_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui16_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui16_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui16_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui32_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui32_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui32_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui32_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui32_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui32_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui32_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui32_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui64_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui64_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui64_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui64_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui64_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui64_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui64_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_aggregate_autovec_ui64_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/intel_simd/filtered_agg/aggregate_autovec_bench_oneApi.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_smallint_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_smallint_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_smallint_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_smallint_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_smallint_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_smallint_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_smallint_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_smallint_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_bigint_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_bigint_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_bigint_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_bigint_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_bigint_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_bigint_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_bigint_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_bigint_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui8_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui8_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui8_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui8_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui8_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui8_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui8_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui8_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui16_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui16_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui16_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui16_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui16_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui16_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui16_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui16_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui32_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui32_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui32_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui32_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui32_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui32_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui32_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui32_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui64_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui64_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui64_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui64_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui64_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui64_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui64_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_lzc_unrolled_and_aggregate_outDevice_ui64_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/lzc_unrolled_and_aggregate_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_smallint_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_smallint_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_smallint_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_smallint_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_smallint_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_smallint_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_smallint_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_smallint_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_bigint_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_bigint_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_bigint_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_bigint_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_bigint_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_bigint_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_bigint_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_bigint_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui8_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui8_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui8_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui8_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui8_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui8_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui8_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui8_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui16_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui16_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui16_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui16_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui16_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui16_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui16_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui16_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui32_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui32_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui32_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui32_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui32_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui32_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui32_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui32_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui64_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui64_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui64_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui64_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui64_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui64_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui64_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_modulo_and_aggregate_outDevice_ui64_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/modulo_test_and_aggregate.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_smallint_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_smallint_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_smallint_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_smallint_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_smallint_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_smallint_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_smallint_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_smallint_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DUI16 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_bigint_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_bigint_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_bigint_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_bigint_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_bigint_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_bigint_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_bigint_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_bigint_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DUI64 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui8_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui8_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui8_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui8_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui8_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui8_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui8_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui8_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI8 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui16_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui16_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui16_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui16_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui16_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui16_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui16_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui16_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI16 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui32_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui32_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui32_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui32_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui32_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui32_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui32_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui32_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI32 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui64_VL128_to_512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL128 -DVL256 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui64_VL1K_to_4K: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL1024 -DVL2048 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui64_VL128: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL128 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui64_VL256: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL256 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui64_VL512: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL512 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui64_VL1k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL1024 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui64_VL2k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL2048 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

bench_hadd_ui64_VL4k: benchmark.so
	icpx \
	-fsycl $(ALL_CXXFLAGS) -v \
	$(foreach L,$(INC_DIRS),-I$L) \
	$(foreach D,$(DEFINES),-D$D) \
	-DUI64 -DVL4096 \
	-fintelfpga -Xshardware -fsycl-device-code-split=off \
	-Xssave-temps \
	-reuse-exe=build/$@.fpga -Xsoutput-report-folder=build/$@.prj \
	-Xsboard=$(BOARD) \
	-qactypes -fsycl-unnamed-lambda \
	-o build/$@.fpga \
	src/hadd_test.cpp $(foreach D,$(LIB_DIRS),-L$D) $(foreach L,$(LIBS),-l$L)

benchmark.so:
	icpx -shared -O2 $(ALL_CXXFLAGS) -fPIC -Itools/benchmark/include -o build/libtuddbs_benchmark.so $(BENCHMARK_SOURCES)