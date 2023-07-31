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

echo "Building Data Generator" >> "${BUILD_LOG}"
g++ -O3 -std=c++17 -o "${OUT_DIR}/datagen" "${SCRIPT_DIR}/datagen.cpp" -static >> "${BUILD_LOG}" 2>&1

echo "g++ autovec noArch" >> "${BUILD_LOG}" 2>&1
g++ -O3 -std=c++17 -DCOMPILER=\"GCC\" -DVERSION=\""${GCC_VERSION}"\" -DARCH=\"noArch\" -flto -o "${OUT_DIR}/generic_gcc_noArch" "${SCRIPT_DIR}/generic.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "g++ autovec SSE" >> "${BUILD_LOG}" 2>&1
g++ -O3 -msse -msse2 -msse3 -msse4.1 -msse4.2 -std=c++17 -DCOMPILER=\"GCC\" -DVERSION=\""${GCC_VERSION}"\" -DARCH=\"sse\" -flto -o "${OUT_DIR}/generic_gcc_SSE" "${SCRIPT_DIR}/generic.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "g++ autovec AVX" >> "${BUILD_LOG}" 2>&1
g++ -O3 -mavx -mavx2 -std=c++17 -DCOMPILER=\"GCC\" -DVERSION=\""${GCC_VERSION}"\" -DARCH=\"avx\" -flto -o "${OUT_DIR}/generic_gcc_AVX" "${SCRIPT_DIR}/generic.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "g++ autovec AVX512" >> "${BUILD_LOG}" 2>&1
g++ -O3 -mavx512f -mavx512cd -mavx512bw -mavx512dq -mavx512vl -std=c++17 -DCOMPILER=\"GCC\" -DVERSION=\""${GCC_VERSION}"\" -DARCH=\"avx512\" -flto -o "${OUT_DIR}/generic_gcc_AVX512" "${SCRIPT_DIR}/generic.cpp" -static >> "${BUILD_LOG}" 2>&1

echo "g++ simd SSE" >> "${BUILD_LOG}" 2>&1
g++ -O3 -msse -msse2 -msse3 -msse4.1 -msse4.2 -std=c++17 -DSSE -DCOMPILER=\"GCC\" -DVERSION=\""${GCC_VERSION}"\" -DARCH=\"sse\" -flto -o "${OUT_DIR}/simd_gcc_SSE" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "g++ simd SSE + VL" >> "${BUILD_LOG}" 2>&1
g++ -O3 -msse -msse2 -msse3 -msse4.1 -msse4.2 -mavx512f -mavx512bw -mavx512vl -std=c++17 -DSSE -DAVX512VL -DCOMPILER=\"GCC\" -DVERSION=\""${GCC_VERSION}"\" -DARCH=\"sse\" -flto -o "${OUT_DIR}/simd_gcc_SSE_VL" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "g++ simd AVX" >> "${BUILD_LOG}" 2>&1
g++ -O3 -mavx -mavx2 -std=c++17 -DAVX -DCOMPILER=\"GCC\" -DVERSION=\""${GCC_VERSION}"\" -DARCH=\"avx\" -flto -o "${OUT_DIR}/simd_gcc_AVX" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "g++ simd AVX + VL" >> "${BUILD_LOG}" 2>&1
g++ -O3 -mavx -mavx2 -mavx512f -mavx512bw -mavx512vl -std=c++17 -DAVX -DAVX512VL -DCOMPILER=\"GCC\" -DVERSION=\""${GCC_VERSION}"\" -DARCH=\"avx\" -flto -o "${OUT_DIR}/simd_gcc_AVX_VL" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "g++ simd AVX512" >> "${BUILD_LOG}" 2>&1
g++ -O3 -mavx512f -mavx512cd -mavx512bw -mavx512dq -mavx512vl -std=c++17 -DAVX512 -DCOMPILER=\"GCC\" -DVERSION=\""${GCC_VERSION}"\" -DARCH=\"avx512\" -flto -o "${OUT_DIR}/simd_gcc_AVX512" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1

echo "clang++ autovec noArch" >> "${BUILD_LOG}" 2>&1
clang++ -O3 -std=c++17 -DCOMPILER=\"CLANG\" -DVERSION=\""${CLANG_VERSION}"\" -DARCH=\"noArch\" -flto -o "${OUT_DIR}/generic_clang_noArch" "${SCRIPT_DIR}/generic.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "clang++ autovec SSE" >> "${BUILD_LOG}" 2>&1
clang++ -O3 -msse -msse2 -msse3 -msse4.1 -msse4.2 -std=c++17 -DCOMPILER=\"CLANG\" -DVERSION=\""${CLANG_VERSION}"\" -DARCH=\"sse\" -flto -o "${OUT_DIR}/generic_clang_SSE" "${SCRIPT_DIR}/generic.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "clang++ autovec AVX" >> "${BUILD_LOG}" 2>&1
clang++ -O3 -mavx -mavx2 -std=c++17 -DCOMPILER=\"CLANG\" -DVERSION=\""${CLANG_VERSION}"\" -DARCH=\"avx\" -flto -o "${OUT_DIR}/generic_clang_AVX" "${SCRIPT_DIR}/generic.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "clang++ autovec AVX512" >> "${BUILD_LOG}" 2>&1
clang++ -O3 -mavx512f -mavx512cd -mavx512bw -mavx512dq -mavx512vl -std=c++17 -DCOMPILER=\"CLANG\" -DVERSION=\""${CLANG_VERSION}"\" -DARCH=\"avx512\" -flto -o "${OUT_DIR}/generic_clang_AVX512" "${SCRIPT_DIR}/generic.cpp" -static >> "${BUILD_LOG}" 2>&1

echo "clang++ simd SSE" >> "${BUILD_LOG}" 2>&1
clang++ -O3 -msse -msse2 -msse3 -msse4.1 -msse4.2 -std=c++17 -DSSE -DCOMPILER=\"CLANG\" -DVERSION=\""${CLANG_VERSION}"\" -DARCH=\"sse\" -flto -o "${OUT_DIR}/simd_clang_SSE" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "clang++ simd SSE + VL" >> "${BUILD_LOG}" 2>&1
clang++ -O3 -msse -msse2 -msse3 -msse4.1 -msse4.2 -mavx512f -mavx512bw -mavx512vl -std=c++17 -DSSE -DAVX512VL -DCOMPILER=\"CLANG\" -DVERSION=\""${CLANG_VERSION}"\" -DARCH=\"sse\" -flto -o "${OUT_DIR}/simd_clang_SSE_VL" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "clang++ simd AVX" >> "${BUILD_LOG}" 2>&1
clang++ -O3 -mavx -mavx2 -std=c++17 -DAVX -DCOMPILER=\"CLANG\" -DVERSION=\""${CLANG_VERSION}"\" -DARCH=\"avx\" -flto -o "${OUT_DIR}/simd_clang_AVX" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "clang++ simd AVX + VL" >> "${BUILD_LOG}" 2>&1
clang++ -O3 -mavx -mavx2 -mavx512f -mavx512bw -mavx512vl -std=c++17 -DAVX -DAVX512VL -DCOMPILER=\"CLANG\" -DVERSION=\""${CLANG_VERSION}"\" -DARCH=\"avx\" -flto -o "${OUT_DIR}/simd_clang_AVX_VL" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "clang++ simd AVX512" >> "${BUILD_LOG}" 2>&1
clang++ -O3 -mavx512f -mavx512cd -mavx512bw -mavx512dq -mavx512vl -std=c++17 -DAVX512 -DCOMPILER=\"CLANG\" -DVERSION=\""${CLANG_VERSION}"\" -DARCH=\"avx512\" -flto -o "${OUT_DIR}/simd_clang_AVX512" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1

echo "icpx autovec noArch" >> "${BUILD_LOG}" 2>&1
icpx -O3 -std=c++17 -DCOMPILER=\"ICPX\" -DVERSION=\""${ICPX_VERSION}"\" -DARCH=\"noArch\" -ipo -o "${OUT_DIR}/generic_icpx_noArch" "${SCRIPT_DIR}/generic.cpp" -static -static-intel  >> "${BUILD_LOG}" 2>&1
echo "icpx autovec SSE" >> "${BUILD_LOG}" 2>&1
icpx -O3 -msse -msse2 -msse3 -msse4.1 -msse4.2 -std=c++17 -DCOMPILER=\"ICPX\" -DVERSION=\""${ICPX_VERSION}"\" -DARCH=\"sse\" -ipo -o "${OUT_DIR}/generic_icpx_SSE" "${SCRIPT_DIR}/generic.cpp" -static -static-intel >> "${BUILD_LOG}" 2>&1
echo "icpx autovec AVX" >> "${BUILD_LOG}" 2>&1
icpx -O3 -mavx -mavx2 -std=c++17 -DCOMPILER=\"ICPX\" -DVERSION=\""${ICPX_VERSION}"\" -DARCH=\"avx\" -ipo -o "${OUT_DIR}/generic_icpx_AVX" "${SCRIPT_DIR}/generic.cpp" -static -static-intel >> "${BUILD_LOG}" 2>&1
echo "icpx autovec AVX512" >> "${BUILD_LOG}" 2>&1
icpx -O3 -mavx512f -mavx512cd -mavx512bw -mavx512dq -mavx512vl -std=c++17 -DCOMPILER=\"ICPX\" -DVERSION=\""${ICPX_VERSION}"\" -DARCH=\"avx512\" -ipo -o "${OUT_DIR}/generic_icpx_AVX512" "${SCRIPT_DIR}/generic.cpp" -static -static-intel >> "${BUILD_LOG}" 2>&1

echo "icpx simd SSE" >> "${BUILD_LOG}" 2>&1
icpx -O3 -msse -msse2 -msse3 -msse4.1 -msse4.2 -std=c++17 -DSSE -DCOMPILER=\"ICPX\" -DVERSION=\""${ICPX_VERSION}"\" -DARCH=\"sse\" -flto -o "${OUT_DIR}/simd_icpx_SSE" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "icpx simd SSE + VL" >> "${BUILD_LOG}" 2>&1
icpx -O3 -msse -msse2 -msse3 -msse4.1 -msse4.2 -mavx512f -mavx512bw -mavx512vl -std=c++17 -DSSE -DAVX512VL -DCOMPILER=\"ICPX\" -DVERSION=\""${ICPX_VERSION}"\" -DARCH=\"sse\" -flto -o "${OUT_DIR}/simd_icpx_SSE_VL" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "icpx simd AVX" >> "${BUILD_LOG}" 2>&1
icpx -O3 -mavx -mavx2 -std=c++17 -DAVX -DCOMPILER=\"ICPX\" -DVERSION=\""${ICPX_VERSION}"\" -DARCH=\"avx\" -flto -o "${OUT_DIR}/simd_icpx_AVX" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "icpx simd AVX + VL" >> "${BUILD_LOG}" 2>&1
icpx -O3 -mavx -mavx2 -mavx512f -mavx512bw -mavx512vl -std=c++17 -DAVX -DAVX512VL -DCOMPILER=\"ICPX\" -DVERSION=\""${ICPX_VERSION}"\" -DARCH=\"avx\" -flto -o "${OUT_DIR}/simd_icpx_AVX_VL" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1
echo "icpx simd AVX512" >> "${BUILD_LOG}" 2>&1
icpx -O3 -mavx512f -mavx512cd -mavx512bw -mavx512dq -mavx512vl -std=c++17 -DAVX512 -DCOMPILER=\"ICPX\" -DVERSION=\""${ICPX_VERSION}"\" -DARCH=\"avx512\" -flto -o "${OUT_DIR}/simd_icpx_AVX512" "${SCRIPT_DIR}/simd.cpp" -static >> "${BUILD_LOG}" 2>&1


BUILD_END=$(date +"%s")
echo "Finished build at $(date)" >> "${BUILD_LOG}" 2>&1
BUILD_TIME=$(($BUILD_END - $BUILD_BEGIN))
echo "Build took ${BUILD_TIME} seconds" >> "${BUILD_LOG}" 2>&1