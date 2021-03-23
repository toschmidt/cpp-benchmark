if (ENABLE_BENCHMARKING)

    file(GLOB_RECURSE BENCHMARK_CPP_FILES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
    file(GLOB_RECURSE BENCHMARK_HPP_FILES ${CMAKE_CURRENT_LIST_DIR}/*.hpp)

    add_executable(benchmark ${BENCHMARK_CPP_FILES} ${BENCHMARK_HPP_FILES})

    # Link the benchmark with the project's library
    target_link_libraries(benchmark PRIVATE cpp-benchmark googlebenchmark)

endif ()
