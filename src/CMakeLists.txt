set(EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} -ltbb")
find_package(OpenMP)

file(GLOB_RECURSE benchmark_source_list "*.cpp")
message(STATUS "benchmark_source_list: ${benchmark_source_list}")
add_executable(shapes_benchmark ${benchmark_source_list})

add_executable(shapes_benchmark_parallel ${benchmark_source_list})
target_compile_definitions(shapes_benchmark_parallel PUBLIC PARALLEL=1)

if( supported )
    message(STATUS "IPO / LTO enabled")
    set_property(TARGET shapes_benchmark PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    set_property(TARGET shapes_benchmark_parallel PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
    message(STATUS "IPO / LTO not supported: <${error}>")
endif()
set_property(TARGET shapes_benchmark PROPERTY CXX_STANDARD 17)
set_property(TARGET shapes_benchmark_parallel PROPERTY CXX_STANDARD 17)

target_link_libraries(shapes_benchmark PUBLIC benchmark::benchmark)
target_link_libraries(shapes_benchmark_parallel PUBLIC benchmark::benchmark OpenMP::OpenMP_CXX)