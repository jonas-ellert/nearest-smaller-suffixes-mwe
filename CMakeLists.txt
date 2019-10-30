cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project(xss-mwe CXX C)

# MWE without using the SDSL
include(ExternalProject)
ExternalProject_Add(
        xss SOURCE_DIR ${CMAKE_BINARY_DIR}/xss
        GIT_REPOSITORY https://github.com/jonas-ellert/nearest-smaller-suffixes
        CONFIGURE_COMMAND ""
        UPDATE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        EXCLUDE_FROM_ALL 1
)
include_directories(${CMAKE_BINARY_DIR}/xss/include)

add_executable(main_plain ${CMAKE_CURRENT_SOURCE_DIR}/main_plain.cpp)
add_dependencies(main_plain xss)


#MWE with the SDSL
include(ExternalProject)
ExternalProject_Add(
        fetch_sdsl PREFIX benchmark/sdsl
        GIT_REPOSITORY https://github.com/simongog/sdsl-lite
        GIT_TAG ddb0fbbc33bb183baa616f17eb48e261ac2a3672 # 1.8.1
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
        UPDATE_COMMAND ""
        EXCLUDE_FROM_ALL 1
)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/benchmark/sdsl/include)
find_library(sdsl ${CMAKE_CURRENT_BINARY_DIR}/benchmark/sdsl/lib/libsdsl.a)

add_executable(main_sdsl ${CMAKE_CURRENT_SOURCE_DIR}/main_sdsl.cpp)
add_dependencies(main_sdsl xss fetch_sdsl)
target_link_libraries(main_sdsl sdsl)
