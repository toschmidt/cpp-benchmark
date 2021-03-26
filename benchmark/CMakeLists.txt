if (ENABLE_BENCHMARKING)

    file(GLOB_RECURSE BENCHMARK_CPP_FILES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
    file(GLOB_RECURSE BENCHMARK_HPP_FILES ${CMAKE_CURRENT_LIST_DIR}/*.hpp)

    add_executable(benchmark ${BENCHMARK_CPP_FILES} ${BENCHMARK_HPP_FILES})

    # Link the benchmark with the project's library
    target_link_libraries(benchmark PRIVATE cpp-benchmark googlebenchmark)


    # generate benchmarks for the definitions in the generated folder
    generate_benchmarks_from_folder(${CMAKE_SOURCE_DIR}/benchmark BENCHMARKS)

    # header only library to link the generated benchmarks with
    add_library(benchmark_lib INTERFACE)
    target_include_directories(benchmark_lib INTERFACE ${CMAKE_SOURCE_DIR}/benchmark)

    foreach (target ${BENCHMARKS})
        target_link_libraries(${target} PRIVATE cpp-benchmark googlebenchmark benchmark_lib)
    endforeach ()
endif ()
