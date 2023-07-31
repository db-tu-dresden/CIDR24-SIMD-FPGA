#!/bin/bash
helpFunction() 
{
   echo ""
   echo "Usage: $0 -m MODE -t TARGET -e ENV -o OUTPUT"
   echo -e "\t-m Mode of the build (emu, hw). hw will create the fpga images."
   echo -e "\t-t Target FPGA card (stratix10, agilex). MUST be specified."
   echo -e "\t-e Environment (devcloud, native). MUST be specified."
   echo -e "\t-o Specify output directory for building. Default is ./build_<TARGET>_<DATE>"
   exit 1 # Exit script after printing help
}
AvailModes=("emu" "hw")
AvailTargets=("stratix10" "agilex")
AvailEnvironments=("devcloud" "native")
PWD=$(pwd)

while getopts "m:t:o:e:" opt
do
   case "$opt" in
      m ) MODE="$OPTARG" ;;
      t ) TARGET="$OPTARG" ;;
      e ) ENVIRONMENT="$OPTARG" ;;
      o ) OUTPUT="$OPTARG" ;;
      ? ) helpFunction ;; # Print helpFunction in case parameter is non-existent
   esac
done

# Print helpFunction in case parameters are empty
if [ -z "$TARGET" ]; then
   echo "TARGET must be specified";
   helpFunction
   exit 0
elif [[ ! " ${AvailTargets[*]} " =~ " ${TARGET} " ]]; then
    echo "Invalid Target specified. Specify either 'stratix10' or 'agilex'.";
    helpFunction
    exit 0
fi
if [ -z "$ENVIRONMENT" ]; then
   echo "ENVIRONMENT must be specified";
   helpFunction
   exit 0
elif [[ ! " ${AvailEnvironments[*]} " =~ " ${ENVIRONMENT} " ]]; then
    echo "Invalid Environment specified. Specify either 'devcloud' or 'native'.";
    helpFunction
    exit 0
fi

if [ -z "$MODE" ]; then
   echo "No Mode specified. Using emu.";
   MODE="emu"
elif [[ ! " ${AvailModes[*]} " =~ " ${MODE} " ]]; then
    echo "Invalid Mode specified. Using emu.";
    MODE="emu"
fi

if [ -z "$OUTPUT" ]; then
  OUTPUT="${PWD}/build_${TARGET}_$(date +"%FT%H%M")"
fi
if [ -d "$OUTPUT" ]; then
  echo "Directory ${OUTPUT} already exists. Cleaning first."
  read -p "Continue (y/n)? " choice
  case "$choice" in
    y|Y|j|J ) rm -rf "${OUTPUT}"/* ;;
    n|N ) exit 0 ;;
    * ) exit 0 ;;
  esac
else 
  echo "Creating directory ${OUTPUT}"
  mkdir -p "${OUTPUT}"
fi
if [ ! -d "${OUTPUT}/bin" ]; then
  echo "Creating ${OUTPUT}/bin"
  mkdir -p "${OUTPUT}/bin"
fi

BUILD_LOG="${OUTPUT}/build.log"
touch "${BUILD_LOG}"


RUN_SCRIPT="${OUTPUT}/bin/setup.sh"
touch "${RUN_SCRIPT}"
chmod +x "${RUN_SCRIPT}"
echo "Creating run script (${RUN_SCRIPT})" >> "${BUILD_LOG}" 2>&1
echo "#!/bin/bash" >> ${RUN_SCRIPT}

if [[ "${ENVIRONMENT}" == "devcloud" ]]; then
  BOARD_NAME="/opt/intel/oneapi/intel_s10sx_pac:pac_s10_usm"
  echo "Setting up environment for Stratix 10 for devcloud (BOARD_NAME=${BOARD_NAME})." >> "${BUILD_LOG}" 2>&1
  
  echo "source /data/intel_fpga/devcloudLoginToolSetup.sh" >> ${RUN_SCRIPT}
  echo "tools_setup -t S10OAPI" >> ${RUN_SCRIPT}
  echo "source /glob/development-tools/versions/oneapi/2022.3.1/oneapi/setvars.sh --force" >> ${RUN_SCRIPT}
  echo "aocl initialize acl0 pac_s10_usm" >> ${RUN_SCRIPT}
else
  if [[ "${TARGET}" == "stratix10" ]]; then
    BOARD_NAME="intel_s10sx_pac:pac_s10_usm"
    echo "Setting up environment for Stratix 10 for native environemnt (BOARD_NAME=${BOARD_NAME})." >> "${BUILD_LOG}" 2>&1

    echo "source /opt/intel/oneapi/setvars.sh" >> ${RUN_SCRIPT}
    echo "source /opt/intel/oneapi/intelfpgadpcpp/latest/env/vars.sh" >> ${RUN_SCRIPT}
    echo "source /opt/intel/oneapi/intelfpgadpcpp/latest/env/vars_a10gx_s10sx.sh" >> ${RUN_SCRIPT}
    echo "aocl initialize acl0 pac_s10_usm" >> ${RUN_SCRIPT}
  elif [[ "${TARGET}" == "agilex" ]]; then
    BOARD_NAME="UNKNOWN"
    echo "Setting up environment for Agilex for native environemnt (BOARD_NAME=${BOARD_NAME})." >> "${BUILD_LOG}" 2>&1
    echo "PLEASE SPECIFY BOARD_NAME in build.sh for Agilex."
    exit 1
    echo "source /opt/intel/oneapi/setvars.sh" >> ${RUN_SCRIPT}
    echo "aocl initialize acl0 <<BOARD_NAME>>" >> ${RUN_SCRIPT}
  fi
fi

if [[ "${MODE}" == "emu" ]]; then
  echo "Generating Build Environment for emu mode (no FPGA images)."
  CXX=icpx cmake -S . -B "${OUTPUT}" -DBOARD="${BOARD_NAME}" >> "${BUILD_LOG}" 2>&1
  if [ $? -ne 0 ]; then
    echo "CMake failed"
    exit 1
  fi
else
  echo "Generating Build Environment for hw mode (FPGA images)."
  CXX=icpx cmake -S . -B "${OUTPUT}" -DBATCH_BUILD=TRUE -DBOARD="${BOARD_NAME}" >> "${BUILD_LOG}" 2>&1
  if [ $? -ne 0 ]; then
    echo "CMake failed"
    exit 1
  fi
fi

echo "Creating current_build_vars.sh" >> "${BUILD_LOG}" 2>&1
CBVARS="${PWD}/current_build_vars.sh"
touch "${CBVARS}"
chmod +x "${CBVARS}"
echo "#!/bin/bash" >> ${CBVARS}
echo "BUILD_LOG=${BUILD_LOG}" >> ${CBVARS}
echo "OUTPUT=${OUTPUT}" >> ${CBVARS}
echo "ENVIRONMENT=${ENVIRONMENT}" >> ${CBVARS}

if [[ "${MODE}" == "emu" ]]; then
  echo "Building project directly (only generting emulator code + reports)."
  cmake --build "${OUTPUT}" #>> "${BUILD_LOG}" 2>&1
  exit $?
else
  if [[ "${ENVIRONMENT}" == "devcloud" ]]; then
    echo "Building project using qsub (generating FPGA images)."
    qsub -l nodes=1:fpga_runtime:stratix10:ppn=2 -d . ./build_impl.sh
    # qsub -l nodes=1:fpga_compile:ppn=2 -l walltime=23:00:00 -v BUILD_LOG="${BUILD_LOG}",OUTPUT="${OUTPUT}",ENVIRONMENT="${ENVIRONMENT}" -d . ./build_impl.sh
  else
    echo "Building project (generating FPGA images)."
    ./build_impl.sh "${BUILD_LOG}" "${OUTPUT}" "${ENVIRONMENT}"
  fi
fi
