cmake_minimum_required(VERSION 3.9.0)
project(boomershapes VERSION 0.1.0)

if( ${CMAKE_CXX_COMPILER} MATCHES ".*clang.*" )
    list(APPEND CMAKE_CXX_FLAGS "-fuse-ld=lld")
endif()

include(CTest)
enable_testing()

include(CheckIPOSupported)
check_ipo_supported(RESULT supported OUTPUT error)

set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
set(BENCHMARK_ENABLE_LTO ON)
add_subdirectory(benchmark)

set(EXPORT_COMPILE_COMMANDS ON)

add_executable(boomershapes_benchmark shapes_benchmark.cpp oopshapes.cpp oldshapes.cpp)

if( supported )
    message(STATUS "IPO / LTO enabled")
    set_property(TARGET boomershapes_benchmark PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
    message(STATUS "IPO / LTO not supported: <${error}>")
endif()

target_link_libraries(boomershapes_benchmark PUBLIC benchmark::benchmark)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
