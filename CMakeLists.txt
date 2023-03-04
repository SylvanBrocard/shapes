cmake_minimum_required(VERSION 3.0.0)
project(boomershapes VERSION 0.1.0)

list(APPEND CMAKE_CXX_FLAGS "-fuse-ld=lld")

include(CTest)
enable_testing()

set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
set(BENCHMARK_ENABLE_LTO ON)
add_subdirectory(benchmark)

set(EXPORT_COMPILE_COMMANDS ON)

add_executable(boomershapes_benchmark shapes_benchmark.cpp oopshapes.cpp oldshapes.cpp)
target_link_libraries(boomershapes_benchmark PUBLIC benchmark::benchmark)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
