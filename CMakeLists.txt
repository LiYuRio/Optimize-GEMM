project(gemm)
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_library(GEMM STATIC
  gemm/reference_gemm.cpp
  gemm/random_matrix.cpp
  gemm/timer.cpp
)

target_include_directories(GEMM
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(test)
