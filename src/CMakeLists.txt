# Header-Only Library (without source files):
add_library(cpp-benchmark INTERFACE)
target_include_directories(cpp-benchmark INTERFACE ${CMAKE_CURRENT_LIST_DIR})
#target_link_libraries(cpp-benchmark INTERFACE <dependencies>)

# Static Library (with source files):
# file(GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
# add_library(<project-name> INTERFACE ${CPP_FILES})
# target_include_directories(<project-name> INTERFACE ${CMAKE_CURRENT_LIST_DIR})
# target_link_libraries(<project-name> PRIVATE <dependencies>)

# For more information on library definitions in cmake see https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/

if (ENABLE_INSTALL)
    include(GNUInstallDirs)

    # Install the project's header files (destination is relative to CMAKE_INSTALL_PREFIX)
    # header-only libraries should keep their header files in the src folder
    # static libraries should have an additional directory (include) to keep the global header files
    install(
            DIRECTORY ${PROJECT_SOURCE_DIR}/src/
            DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
            FILES_MATCHING PATTERN "*.hpp"
    )
endif ()
