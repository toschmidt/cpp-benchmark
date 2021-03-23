# Static Library (with source files and header files in separate directory):
file(GLOB_RECURSE CPP_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_library(cpp-benchmark STATIC ${CPP_FILES})
target_include_directories(cpp-benchmark
        PUBLIC $<INSTALL_INTERFACE:include> $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(cpp-benchmark PRIVATE cpp-utility googlebenchmark)

if (ENABLE_INSTALL)
    include(GNUInstallDirs)

    # Install the project's header files (destination is relative to CMAKE_INSTALL_PREFIX)
    # header-only libraries should keep their header files in the src folder
    # static libraries should have an additional directory (include) to keep the global header files
    install(
            DIRECTORY ${PROJECT_SOURCE_DIR}/include/
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
            FILES_MATCHING PATTERN "*.hpp"
    )
endif ()
