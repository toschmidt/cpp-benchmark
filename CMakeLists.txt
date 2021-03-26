cmake_minimum_required(VERSION 3.14)
project(cpp-benchmark)

# Options for building the project
option(ENABLE_TESTING "Enable testing of the project." OFF)
option(ENABLE_BENCHMARKING "Enable benchmarking of the project." ON)
option(ENABLE_INSTALL "Enable installation of the library." ON)

# C++ Standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compilation Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -march=native")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -static-libasan -static-libubsan -fsanitize=address -fsanitize=leak -fsanitize=undefined")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} --coverage -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

# Standard Libraries
include(${CMAKE_SOURCE_DIR}/cmake/import/googlebenchmark.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/import/threads.cmake)

# Libraries
include(${CMAKE_SOURCE_DIR}/cmake/import/cpp-utility.cmake)

# Benchmark Generator
include(benchmark-generator/benchmark-generator.cmake)

# Implementation
add_subdirectory(src)

# Benchmark
add_subdirectory(benchmark)
