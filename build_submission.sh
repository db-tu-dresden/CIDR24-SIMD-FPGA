#!/bin/bash
source /data/intel_fpga/devcloudLoginToolSetup.sh
tools_setup -t S10OAPI
source /glob/development-tools/versions/oneapi/2022.3.1/oneapi/setvars.sh --force
export PATH=/glob/intel-python/python2/bin:$PATH

make bench_hadd_bigint_VL128_to_512 >> build/build_hadd_bigint_VL128_to_512.log 2>&1
make bench_modulo_and_aggregate_outDevice_bigint_VL128_to_512 >> build/build_modulo_and_aggregate_outDevice_bigint_VL128_to_512.log 2>&1
make bench_lzc_unrolled_and_aggregate_outDevice_bigint_VL128_to_512 >> build/build_lzc_unrolled_and_aggregate_outDevice_bigint_VL128_to_512.log 2>&1
make bench_aggregate_autovec_bigint_VL128_to_512 >> build/build_aggregate_autovec_bigint_VL128_to_512.log 2>&1
make bench_aggregate_plain_bigint >> build/build_aggregate_plain_bigint.log 2>&1
make bench_conflict_detection_unrolled_and_aggregate_ui64_VL512 >> build/build_conflict_detection_unrolled_and_aggregate_ui64_VL512.log 2>&1

#make bench_hadd_bigint_VL1K_to_4K >> build/build_hadd_bigint_VL1K_to_4K.log 2>&1
#make bench_modulo_and_aggregate_outDevice_bigint_VL1K_to_4K >> build/build_modulo_and_aggregate_outDevice_bigint_VL1K_to_4K.log 2>&1
#make bench_lzc_unrolled_and_aggregate_outDevice_bigint_VL1K_to_4K >> build/build_lzc_unrolled_and_aggregate_outDevice_bigint_VL1K_to_4K.log 2>&1
#make bench_aggregate_autovec_bigint_VL1K_to_4K >> build/build_aggregate_autovec_bigint_VL1K_to_4K.log 2>&1
#make bench_conflict_detection_unrolled_and_aggregate_ui64_VL1K >> build/build_conflict_detection_unrolled_and_aggregate_ui64_VL1K.log 2>&1