#!/bin/bash

PWD=$(pwd)
./src/intel_simd/lzc/build.sh
cd "${PWD}"
./src/intel_simd/conflict_detection/build.sh
cd "${PWD}"
./src/intel_simd/filtered_agg/build.sh
cd "${PWD}"