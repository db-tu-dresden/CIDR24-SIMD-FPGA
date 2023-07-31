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

echo "Running lzc experiments"
echo "g++ version --repeats ${REPEATS}" >> log.txt 2>&1
echo "g++ version --repeats ${REPEATS}"
numactl -C 0 -m 0 ./lzc_gcc_simd --size 4KiB --repeats "${REPEATS}" >> log.txt 2>&1
numactl -C 0 -m 0 ./lzc_gcc_simd --size 4MiB --repeats "${REPEATS}" >> log.txt 2>&1
numactl -C 0 -m 0 ./lzc_gcc_simd --size 4GiB --repeats "${REPEATS}" >> log.txt 2>&1
echo "clang++ version --repeats ${REPEATS}" >> log.txt 2>&1
echo "clang++ version --repeats ${REPEATS}"
numactl -C 0 -m 0 ./lzc_clang_simd --size 4KiB --repeats "${REPEATS}" >> log.txt 2>&1
numactl -C 0 -m 0 ./lzc_clang_simd --size 4MiB --repeats "${REPEATS}" >> log.txt 2>&1
numactl -C 0 -m 0 ./lzc_clang_simd --size 4GiB --repeats "${REPEATS}" >> log.txt 2>&1
echo "icpx version --repeats ${REPEATS}" >> log.txt 2>&1
echo "icpx version --repeats ${REPEATS}"
numactl -C 0 -m 0 ./lzc_icpx_simd --size 4KiB --repeats "${REPEATS}" >> log.txt 2>&1
numactl -C 0 -m 0 ./lzc_icpx_simd --size 4MiB --repeats "${REPEATS}" >> log.txt 2>&1
numactl -C 0 -m 0 ./lzc_icpx_simd --size 4GiB --repeats "${REPEATS}" >> log.txt 2>&1

cd "${PWD}"