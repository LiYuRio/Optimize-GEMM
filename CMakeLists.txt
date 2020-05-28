project(gemm)
cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)

add_library(GEMM STATIC
  gemm/reference_gemm.cpp
  gemm/random_matrix.cpp
)

target_include_directories(GEMM
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(test)
