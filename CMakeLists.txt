cmake_minimum_required(VERSION 3.0.0)
project(boomershapes VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(OpenMP)

set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
add_subdirectory(benchmark)

set(EXPORT_COMPILE_COMMANDS ON)

add_executable(boomershapes main.cpp)
add_executable(boomershapes_benchmark shapes_benchmark.cpp)
target_link_libraries(boomershapes_benchmark PUBLIC benchmark::benchmark OpenMP::OpenMP_CXX)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
