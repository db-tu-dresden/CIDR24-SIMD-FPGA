#!/bin/bash
source ./current_build_vars.sh
echo "Build log: ${BUILD_LOG}"
echo "Output directory: ${OUTPUT}"
echo "Environment: ${ENVIRONMENT}"


BUILD_BEGIN=$(date +"%s")
echo "Starting build at $(date)" >> "${BUILD_LOG}"

if [[ "${ENVIRONMENT}" == "devcloud" ]]; then
  echo "Sourcing /data/intel_fpga/devcloudLoginToolSetup.sh" >> "${BUILD_LOG}" 2>&1
  source /data/intel_fpga/devcloudLoginToolSetup.sh >> "${BUILD_LOG}" 2>&1
  tools_setup -t S10OAPI
  echo "Sourcing /glob/development-tools/versions/oneapi/2022.3.1/oneapi/setvars.sh --force" >> "${BUILD_LOG}" 2>&1
  source /glob/development-tools/versions/oneapi/2022.3.1/oneapi/setvars.sh --force >> "${BUILD_LOG}" 2>&1
elif [[ "${ENVIRONMENT}" == "native" ]]; then
  echo "Sourcing /opt/intel/oneapi/setvars.sh" >> "${BUILD_LOG}" 2>&1
  source /opt/intel/oneapi/setvars.sh >> "${BUILD_LOG}" 2>&1
  echo "Adding Quartus Path (/opt/intel/oneapi/intelfpgadpcpp/2021.4.0/QuartusPrimePro/19.2/quartus/bin) to $PATH" >> "${BUILD_LOG}" 2>&1
  export PATH=/opt/intel/oneapi/intelfpgadpcpp/2021.4.0/QuartusPrimePro/19.2/quartus/bin:$PATH
fi

echo "Adding /glob/intel-python/python2/bin to PATH" >> "${BUILD_LOG}" 2>&1
export PATH=/glob/intel-python/python2/bin:$PATH >> "${BUILD_LOG}" 2>&1

if [[ "${ENVIRONMENT}" == "devcloud" ]]; then
  cd "${OUTPUT}"
  make bench_hadd_bigInt.fpga >> "${BUILD_LOG}" 2>&1
  make bench_filter_ui32_512.fpga >> "${BUILD_LOG}" 2>&1
  make bench_specific_filter_ui32_512.fpga >> "${BUILD_LOG}" 2>&1
  make bench_conflict_detection_ui32.fpga >> "${BUILD_LOG}" 2>&1
  make bench_specific_conflict_detection_ui32_512.fpga >> "${BUILD_LOG}" 2>&1
  make bench_specific_conflict_detection_ui64_512.fpga >> "${BUILD_LOG}" 2>&1
  make bench_specific_conflict_detection_ui64_1024.fpga >> "${BUILD_LOG}" 2>&1
  make bench_modulo_ui32.fpga >> "${BUILD_LOG}" 2>&1
  make bench_modulo_ui64.fpga >> "${BUILD_LOG}" 2>&1
elif [[ "${ENVIRONMENT}" == "native" ]]; then
  # cmake --build "${OUTPUT}" --target bench_hadd_bigInt.fpga >> "${BUILD_LOG}" 2>&1
  # cmake --build "${OUTPUT}" --target bench_filter_ui32_512.fpga >> "${BUILD_LOG}" 2>&1
  # cmake --build "${OUTPUT}" --target bench_specific_filter_ui32_512.fpga >> "${BUILD_LOG}" 2>&1
  # cmake --build "${OUTPUT}" --target bench_conflict_detection_ui32.fpga >> "${BUILD_LOG}" 2>&1
  # cmake --build "${OUTPUT}" --target bench_modulo_ui32.fpga >> "${BUILD_LOG}" 2>&1
  # cmake --build "${OUTPUT}" --target bench_modulo_ui64.fpga >> "${BUILD_LOG}" 2>&1
  # cmake --build "${OUTPUT}" --target bench_specific_conflict_detection_and_aggregate_ui64_512.fpga >> "${BUILD_LOG}" 2>&1

  # cmake --build "${OUTPUT}" --target bench_aggregate_plain.fpga >> "${BUILD_LOG}" 2>&1
  
  cmake --build "${OUTPUT}" --target bench_aggregate_autovec_ui64.fpga >> "${BUILD_LOG}" 2>&1
  cmake --build "${OUTPUT}" --target bench_specific_conflict_detection_and_aggregate_ui64_512.fpga >> "${BUILD_LOG}" 2>&1
  cmake --build "${OUTPUT}" --target bench_modulo_ui64_512_and_aggregate_outDevice.fpga >> "${BUILD_LOG}" 2>&1
  cmake --build "${OUTPUT}" --target bench_lzc_ui64_512_unrolled_and_aggregate_outDevice.fpga >> "${BUILD_LOG}" 2>&1
fi

BUILD_END=$(date +"%s")
echo "Finished build at $(date)" >> "${BUILD_LOG}" 2>&1
BUILD_TIME=$(($BUILD_END - $BUILD_BEGIN))
echo "Build took ${BUILD_TIME} seconds" >> "${BUILD_LOG}" 2>&1


# BUILD_LOG="$(pwd)/build_stratix10_2023-07-20T0555/build.log"
# OUTPUT="$(pwd)/cidr24/build_stratix10_2023-07-20T0555"
#qsub -l nodes=1:fpga_runtime:stratix10:ppn=2 -v BUILD_LOG="${BUILD_LOG}",OUTPUT="${OUTPUT}",ENVIRONMENT="${ENVIRONMENT}" -d . ./build_impl.sh
