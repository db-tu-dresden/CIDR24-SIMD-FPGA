#!/bin/bash
SCRIPT_DIR=$(dirname "$(realpath "${BASH_SOURCE[0]}")")
PWD=$(pwd)

helpFunction() 
{
   echo ""
   echo "Usage: $0 -r REPEATS -p WD"
   echo -e "\t-r Number of experiment repetitions (Default: ${SCRIPT_DIR}/bin)"
   echo -e "\t-o Working directory"
   exit 1 # Exit script after printing help
}

while getopts "r:p:" opt
do
   case "$opt" in
      r ) REPEATS="$OPTARG" ;;
      p ) WORKDIR="$OPTARG" ;;
      ? ) helpFunction ;; # Print helpFunction in case parameter is non-existent
   esac
done

if [ -z "${REPEATS}" ]; then
  echo "Number of experiment repetitions not specified. Using default value of 30."
  REPEATS=30
fi
if [ -z "${WORKDIR}" ]; then
  echo "Working directory not specified. Using default value of ${SCRIPT_DIR}/bin."
  WORKDIR="${SCRIPT_DIR}/bin"
fi

cd "${WORKDIR}"
echo "Running filtered_agg experiments"
echo "g++ autovec noArch --repeats ${REPEATS}" >> log.txt 2>&1
echo "g++ autovec noArch --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_gcc_noArch  --repeats "${REPEATS}" >> log.txt 2>&1
echo "g++ autovec SSE --repeats ${REPEATS}" >> log.txt 2>&1
echo "g++ autovec SSE --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_gcc_SSE  --repeats "${REPEATS}" >> log.txt 2>&1
echo "g++ autovec AVX --repeats ${REPEATS}" >> log.txt 2>&1
echo "g++ autovec AVX --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_gcc_AVX  --repeats "${REPEATS}" >> log.txt 2>&1
echo "g++ autovec AVX512 --repeats ${REPEATS}" >> log.txt 2>&1
echo "g++ autovec AVX512 --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_gcc_AVX512  --repeats "${REPEATS}" >> log.txt 2>&1
echo "clang++ autovec noArch --repeats ${REPEATS}" >> log.txt 2>&1
echo "clang++ autovec noArch --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_clang_noArch  --repeats "${REPEATS}" >> log.txt 2>&1
echo "clang++ autovec SSE --repeats ${REPEATS}" >> log.txt 2>&1
echo "clang++ autovec SSE --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_clang_SSE  --repeats "${REPEATS}" >> log.txt 2>&1
echo "clang++ autovec AVX --repeats ${REPEATS}" >> log.txt 2>&1
echo "clang++ autovec AVX --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_clang_AVX  --repeats "${REPEATS}" >> log.txt 2>&1
echo "clang++ autovec AVX512 --repeats ${REPEATS}" >> log.txt 2>&1
echo "clang++ autovec AVX512 --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_clang_AVX512  --repeats "${REPEATS}" >> log.txt 2>&1
echo "icpx autovec noArch --repeats ${REPEATS}" >> log.txt 2>&1
echo "icpx autovec noArch --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_icpx_noArch  --repeats "${REPEATS}" >> log.txt 2>&1
echo "icpx autovec SSE --repeats ${REPEATS}" >> log.txt 2>&1
echo "icpx autovec SSE --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_icpx_SSE  --repeats "${REPEATS}" >> log.txt 2>&1
echo "icpx autovec AVX --repeats ${REPEATS}" >> log.txt 2>&1
echo "icpx autovec AVX --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_icpx_AVX  --repeats "${REPEATS}" >> log.txt 2>&1
echo "icpx autovec AVX512 --repeats ${REPEATS}" >> log.txt 2>&1
echo "icpx autovec AVX512 --repeats ${REPEATS}"
numactl -C 0 -m 0 ./generic_icpx_AVX512  --repeats "${REPEATS}" >> log.txt 2>&1

echo "g++ simd SSE --repeats ${REPEATS}" >> log.txt 2>&1
echo "g++ simd SSE --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_gcc_SSE  --repeats "${REPEATS}" >> log.txt 2>&1
echo "g++ simd SSE_VL --repeats ${REPEATS}" >> log.txt 2>&1
echo "g++ simd SSE_VL --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_gcc_SSE_VL  --repeats "${REPEATS}" >> log.txt 2>&1
echo "g++ simd AVX --repeats ${REPEATS}" >> log.txt 2>&1
echo "g++ simd AVX --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_gcc_AVX  --repeats "${REPEATS}" >> log.txt 2>&1
echo "g++ simd AVX_VL --repeats ${REPEATS}" >> log.txt 2>&1
echo "g++ simd AVX_VL --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_gcc_AVX_VL  --repeats "${REPEATS}" >> log.txt 2>&1
echo "g++ simd AVX512 --repeats ${REPEATS}" >> log.txt 2>&1
echo "g++ simd AVX512 --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_gcc_AVX512  --repeats "${REPEATS}" >> log.txt 2>&1
echo "clang++ simd SSE --repeats ${REPEATS}" >> log.txt 2>&1
echo "clang++ simd SSE --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_clang_SSE  --repeats "${REPEATS}" >> log.txt 2>&1
echo "clang++ simd SSE_VL --repeats ${REPEATS}" >> log.txt 2>&1
echo "clang++ simd SSE_VL --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_clang_SSE_VL  --repeats "${REPEATS}" >> log.txt 2>&1
echo "clang++ simd AVX --repeats ${REPEATS}" >> log.txt 2>&1
echo "clang++ simd AVX --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_clang_AVX  --repeats "${REPEATS}" >> log.txt 2>&1
echo "clang++ simd AVX_VL --repeats ${REPEATS}" >> log.txt 2>&1
echo "clang++ simd AVX_VL --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_clang_AVX_VL  --repeats "${REPEATS}" >> log.txt 2>&1
echo "clang++ simd AVX512 --repeats ${REPEATS}" >> log.txt 2>&1
echo "clang++ simd AVX512 --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_clang_AVX512  --repeats "${REPEATS}" >> log.txt 2>&1
echo "icpx simd SSE --repeats ${REPEATS}" >> log.txt 2>&1
echo "icpx simd SSE --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_icpx_SSE  --repeats "${REPEATS}" >> log.txt 2>&1
echo "icpx simd SSE_VL --repeats ${REPEATS}" >> log.txt 2>&1
echo "icpx simd SSE_VL --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_icpx_SSE_VL  --repeats "${REPEATS}" >> log.txt 2>&1
echo "icpx simd AVX --repeats ${REPEATS}" >> log.txt 2>&1
echo "icpx simd AVX --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_icpx_AVX  --repeats "${REPEATS}" >> log.txt 2>&1
echo "icpx simd AVX_VL --repeats ${REPEATS}" >> log.txt 2>&1
echo "icpx simd AVX_VL --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_icpx_AVX_VL  --repeats "${REPEATS}" >> log.txt 2>&1
echo "icpx simd AVX512 --repeats ${REPEATS}" >> log.txt 2>&1
echo "icpx simd AVX512 --repeats ${REPEATS}"
numactl -C 0 -m 0 ./simd_icpx_AVX512  --repeats "${REPEATS}" >> log.txt 2>&1

cd "${PWD}"