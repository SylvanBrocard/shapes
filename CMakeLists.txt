cmake_minimum_required(VERSION 3.0.0)
project(boomershapes VERSION 0.1.0)

include(CTest)
enable_testing()

set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
add_subdirectory(benchmark)

add_executable(boomershapes main.cpp)
target_link_libraries(boomershapes benchmark::benchmark)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
