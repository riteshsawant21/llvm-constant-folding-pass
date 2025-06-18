cmake_minimum_required(VERSION 3.13)
project(CustomPasses LANGUAGES CXX)

find_package(LLVM REQUIRED CONFIG)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
include(AddLLVM)

add_subdirectory(passes)

