cmake_minimum_required(VERSION 3.16)

project(ConcordBot)

set(BUILD_VOICE_SUPPORT OFF CACHE BOOL "")
set(RUN_LDCONFIG OFF CACHE BOOL "")
set(DPP_INSTALL OFF CACHE BOOL "")
set(DPP_BUILD_TEST OFF CACHE BOOL "")

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Using system DPP")
    find_package(dpp REQUIRED)
    set(DPP_TARGET dpp::dpp)
else()
    message(STATUS "Using cloned DPP for debug mode")
    add_subdirectory(lib/DPP)
    include_directories(lib/DPP/include)
    set(DPP_TARGET dpp)
endif()

set(SRC_FILES src/main.cpp src/RandomNumberGenerator.cpp src/RandomNumberGenerator.h src/util.cpp src/util.h)


SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )

IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
ENDIF()



add_executable(ConcordBot ${SRC_FILES})

target_link_libraries(ConcordBot ${DPP_TARGET})

set_target_properties(ConcordBot PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

