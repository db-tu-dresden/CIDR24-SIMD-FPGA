#!/bin/bash
CWD=$(pwd)
#generate TSL static
mkdir -p "${CWD}/static_tsl"
python3 tools/tslgen/main.py --targets oneAPIfpgaDev --no-testing --no-draw-test-dependencies --no-workaround-warnings -o "${CWD}/static_tsl"

#create build directory
mkdir -p "${CWD}/build"
