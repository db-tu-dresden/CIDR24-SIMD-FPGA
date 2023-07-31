#!/bin/bash
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
  echo "Working directory not specified. Taking the defaults from the executables."
  WORKDIR="${SCRIPT_DIR}/bin"
fi


./src/intel_simd/lzc/run.sh -r "${REPEATS}"
cd "${PWD}"
./src/intel_simd/conflict_detection/run.sh -r "${REPEATS}"
cd "${PWD}"
./src/intel_simd/filtered_agg/run.sh -r "${REPEATS}"
cd "${PWD}"