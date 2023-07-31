cmake_minimum_required(VERSION 3.13)
project(cidr24)

set(CMAKE_VERBOSE_MAKEFILE ON)

#find_package(IntelDPCPP REQUIRED)
#find_package(IntelSYCL REQUIRED)

set(project_cxx_standard 20)
set(release_cxx_flag "")
set(warnings "-Wall;-Wextra;-Wpedantic")
set(release_warnings "-Winline")

if (DEFINED BATCH_BUILD)
    set(BATCH_BUILD_DEFINITION "BATCH_BUILD")
else()
    set(BATCH_BUILD_DEFINITION "")
endif()

if (DEFINED LATEST)
	set(BUILD_LATEST_DEFINITION "BUILD_LATEST")
else()
	set(BUILD_LATEST_DEFINITION "")
endif()

set(LIBS pthread)

if (DEFINED BOARD)
    set(fpga_board ${BOARD})
else()
    set(fpga_board "intel_s10sx_pac:pac_s10_usm")
endif()
# set(fpga_board "/opt/intel/oneapi/intel_s10sx_pac:pac_s10_usm")
#set(fpga_board "intel_s10sx_pac:pac_s10_usm")
set(fpga_link_options -qactypes -fsycl -fintelfpga -fsycl-device-code-split=off -fsycl-unnamed-lambda)# -fsycl-help=fpga)

include(tools/tslgen/tsl.cmake)

create_tsl(
  TSLGENERATOR_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tools/tslgen"
  DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/tools/tslgen"
	TARGETS_FLAGS "oneAPIfpgaDev"
  USE_CONCEPTS
	LINK_OPTIONS ${fpga_link_options}
)
message(STATUS "TSL Include Directory: ${TSL_INCLUDE_DIRECTORY}")

add_subdirectory("${PROJECT_SOURCE_DIR}/tools/benchmark")


function(create_fpga_emu_target target mainFile)
    set(exec_target_name ${target}.fpga.emu)
    add_executable(${exec_target_name} ${mainFile})
    cmake_parse_arguments(ADDITIONAL_ARGS "" "" "DEFINITIONS;OPTIONS;SYCLOPTIONS" ${ARGN})
    if(DEFINED ADDITIONAL_ARGS_DEFINITIONS)
      target_compile_definitions(${exec_target_name} PUBLIC ${ADDITIONAL_ARGS_DEFINITIONS})
    endif()
    if(DEFINED ADDITIONAL_ARGS_OPTIONS)
      target_compile_options(${exec_target_name} PUBLIC ${ADDITIONAL_ARGS_OPTIONS})
    endif()
    target_compile_definitions(${exec_target_name} PRIVATE COMPILER="${CMAKE_CXX_COMPILER}" VERSION="${CMAKE_CXX_COMPILER_VERSION}")
    target_compile_definitions(${exec_target_name} PRIVATE FPGA_EMULATOR CMAKE_EXPORT_COMPILE_COMMANDS=1 ${BATCH_BUILD_DEFINITION} ${BUILD_LATEST_DEFINITION})
    target_include_directories(${exec_target_name} PRIVATE ${PROJECT_SOURCE_DIR}/include ${TSL_INCLUDE_DIRECTORY} ${PROJECT_SOURCE_DIR}/tools/benchmark/include)
    target_link_libraries(${exec_target_name} PRIVATE tsl tuddbs_benchmark)
    set_target_properties(${exec_target_name} PROPERTIES CXX_STANDARD ${project_cxx_standard})
    target_compile_options(${exec_target_name} PRIVATE -fsycl ${release_cxx_flag} ${warnings} ${release_warnings} -fintelfpga -qactypes)
    target_link_options(${exec_target_name} PRIVATE -fsycl -fintelfpga -qactypes)
    target_link_libraries(${exec_target_name} PRIVATE pthread)

    
    # set_target_properties(${exec_target_name} PROPERTIES OUTPUT_NAME ${target}.fpga.emu)

    set(report_target_name ${target}_report)
    add_executable(${report_target_name} ${mainFile})
    if(DEFINED ADDITIONAL_ARGS_DEFINITIONS)
      target_compile_definitions(${report_target_name} PUBLIC ${ADDITIONAL_ARGS_DEFINITIONS})
    endif()
    if(DEFINED ADDITIONAL_ARGS_OPTIONS)
      target_compile_options(${report_target_name} PUBLIC ${ADDITIONAL_ARGS_OPTIONS})
    endif()
    target_compile_definitions(${report_target_name} PRIVATE COMPILER="${CMAKE_CXX_COMPILER}" VERSION="${CMAKE_CXX_COMPILER_VERSION}")
    target_compile_definitions(${report_target_name} PRIVATE FPGA_EMULATOR CMAKE_EXPORT_COMPILE_COMMANDS=1 ${BATCH_BUILD_DEFINITION} ${BUILD_LATEST_DEFINITION})
    target_include_directories(${report_target_name} PRIVATE ${PROJECT_SOURCE_DIR}/include ${TSL_INCLUDE_DIRECTORY} ${PROJECT_SOURCE_DIR}/tools/benchmark/include)
    target_link_libraries(${report_target_name} PRIVATE tsl tuddbs_benchmark)
    set_target_properties(${report_target_name} PROPERTIES CXX_STANDARD ${project_cxx_standard})
    target_compile_options(${report_target_name} PRIVATE -fsycl ${release_cxx_flag} ${warnings} ${release_warnings} -fintelfpga -Xshardware ${ADDITIONAL_ARGS_SYCLOPTIONS} -Xsboard=${fpga_board} -Xssave-temps -fsycl-link -qactypes)
    target_link_options(${report_target_name} PRIVATE -fsycl -fintelfpga -Xshardware ${ADDITIONAL_ARGS_SYCLOPTIONS} -Xsboard=${fpga_board} -Xssave-temps -fsycl-link -qactypes)
    target_link_libraries(${report_target_name} PRIVATE pthread)
    set_target_properties(${report_target_name} PROPERTIES OUTPUT_NAME ${report_target_name})

    install(TARGETS ${exec_target_name} ${report_target_name} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")
endfunction()

function(create_fpga_target target mainFile)
	if (DEFINED LATEST)
		set(BUILD_BOARD "-Xstarget=${fpga_board}")
	else()
		set(BUILD_BOARD "-Xsboard=${fpga_board}")
	endif()

    set(target_name ${target}.fpga)
    set(reuse_exe "${CMAKE_CURRENT_BINARY_DIR}/${target_name}")
    add_executable(${target_name} ${mainFile})
    cmake_parse_arguments(ADDITIONAL_ARGS "" "" "DEFINITIONS;OPTIONS;SYCLOPTIONS" ${ARGN})
    if(DEFINED ADDITIONAL_ARGS_DEFINITIONS)
      target_compile_definitions(${target_name} PUBLIC ${ADDITIONAL_ARGS_DEFINITIONS})
    endif()
    if(DEFINED ADDITIONAL_ARGS_OPTIONS)
      target_compile_options(${target_name} PUBLIC ${ADDITIONAL_ARGS_OPTIONS})
    endif()
    target_compile_definitions(${target_name} PRIVATE COMPILER="${CMAKE_CXX_COMPILER}" VERSION="${CMAKE_CXX_COMPILER_VERSION}")
    target_compile_definitions(${target_name} PRIVATE FPGA_HARDWARE CMAKE_EXPORT_COMPILE_COMMANDS=1 ${BATCH_BUILD_DEFINITION} ${BUILD_LATEST_DEFINITION})
    target_include_directories(${target_name} PRIVATE ${PROJECT_SOURCE_DIR}/include ${TSL_INCLUDE_DIRECTORY} ${PROJECT_SOURCE_DIR}/tools/benchmark/include)
    target_link_libraries(${target_name} PRIVATE tsl tuddbs_benchmark)
    set_target_properties(${target_name} PROPERTIES CXX_STANDARD ${project_cxx_standard})
    # target_compile_options(${target_name} PRIVATE -fsycl ${release_cxx_flag} ${warnings} ${release_warnings} -fintelfpga -Xshardware -Xsboard=${fpga_board} -Xsprofile -Xssave-temps -reuse-exe=${reuse_exe} -fsycl-link -qactypes)
    # target_link_options(${target_name} PRIVATE -fsycl -fintelfpga -Xshardware -Xsboard=${fpga_board} -Xsprofile -Xssave-temps -reuse-exe=${reuse_exe} -fsycl-link -qactypes)
    target_compile_options(${target_name} PRIVATE -fsycl ${release_cxx_flag} ${warnings} ${release_warnings} -fintelfpga -Xshardware ${ADDITIONAL_ARGS_SYCLOPTIONS} -fsycl-device-code-split=off -Xssave-temps -reuse-exe=${reuse_exe} -Xsoutput-report-folder=${target}.prj ${BUILD_BOARD} -qactypes)
    target_link_options(${target_name} PRIVATE -fsycl -fintelfpga -Xshardware ${ADDITIONAL_ARGS_SYCLOPTIONS} -fsycl-device-code-split=off -Xssave-temps -reuse-exe=${reuse_exe} -Xsoutput-report-folder=${target}.prj ${BUILD_BOARD} -qactypes)
    
    target_link_libraries(${target_name} PRIVATE pthread)

    install(TARGETS ${target_name} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/bin")
    
endfunction()

# add_subdirectory(test)
add_subdirectory(src)



