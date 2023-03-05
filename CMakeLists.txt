cmake_minimum_required(VERSION 3.9.0)
project(shapes VERSION 0.1.0)

if( ${CMAKE_CXX_COMPILER} MATCHES ".*clang.*" )
    set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -fuse-ld=lld")
endif()

include(CTest)
enable_testing()

include(CheckIPOSupported)
check_ipo_supported(RESULT supported OUTPUT error)

set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
set(BENCHMARK_ENABLE_LTO ON)
add_subdirectory(benchmark)

add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
