#!/bin/bash

SCRIPT_DIR=$(dirname "$(realpath "${BASH_SOURCE[0]}")")

if [ "$#" -eq 0 ]; then
  echo "No output directory specified. Using default one."
  OUT_DIR="${SCRIPT_DIR}/bin"
else
  OUT_DIR=$1
fi

BUILD_LOG="${OUT_DIR}/build.log"

echo "Script dir: ${SCRIPT_DIR}"
echo "Build log: ${BUILD_LOG}"
echo "Output directory: ${OUT_DIR}"

mkdir -p "${OUT_DIR}"

CLANG_VERSION=$(clang++ --version | head -n 1 | grep -oP '[0-9]+\.[0-9]+\.[0-9]+')
GCC_VERSION=$(g++ --version | head -n 1 | tr " " "\n" | grep -oP '[0-9]+\.[0-9]+\.[0-9]+$')
ICPX_VERSION=$(icpx --version | head -n 1 | grep -oP '[0-9]+\.[0-9]+\.[0-9]+' | head -n 1)

echo "clang++ version: $CLANG_VERSION" >> "${BUILD_LOG}" 2>&1
echo "g++ version: $GCC_VERSION" >> "${BUILD_LOG}" 2>&1
echo "icpx version: $ICPX_VERSION" >> "${BUILD_LOG}" 2>&1

BUILD_BEGIN=$(date +"%s")
echo "Starting build at $(date)" >> "${BUILD_LOG}"

#python3 ../../../tools/tslgen/main.py -o "${SCRIPT_DIR}"/tsl --targets sse sse2 sse3 sse4_1 sse4_2 avx avx2 avx512f avx512cd avx512bw avx512dq avx512vl

echo "clang++" >> "${BUILD_LOG}" 2>&1
clang++ -O3 -std=c++20 \
  -DCOMPILER=\"CLANG\" -DVERSION=\""${CLANG_VERSION}"\" -DARCH=\"all\" \
  -msse -msse2 -msse3 -msse4.1 -msse4.2 \
  -mavx -mavx2 \
  -mavx512f -mavx512cd -mavx512bw -mavx512dq -mavx512vl \
  -flto \
  -I "${SCRIPT_DIR}/tsl/include" \
  -o "${OUT_DIR}/modulo_clang_simd" "${SCRIPT_DIR}/modulo_simd.cpp" \
  -static 
  #>> "${BUILD_LOG}" 2>&1


BUILD_END=$(date +"%s")
echo "Finished build at $(date)" >> "${BUILD_LOG}" 2>&1
BUILD_TIME=$(($BUILD_END - $BUILD_BEGIN))
echo "Build took ${BUILD_TIME} seconds" >> "${BUILD_LOG}" 2>&1
