cmake_minimum_required(VERSION 3.13)

project(MyFirstPass LANGUAGES CXX)

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard to conform to")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_library(MyFirstPass MODULE MyFirstPass.cpp)

set_target_properties(MyFirstPass PROPERTIES
  COMPILE_FLAGS "-fno-rtti"
)

