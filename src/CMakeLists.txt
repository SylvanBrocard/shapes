set(EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE benchmark_source_list "*.cpp")
message(STATUS "benchmark_source_list: ${benchmark_source_list}")
add_executable(shapes_benchmark ${benchmark_source_list})

if( supported )
    message(STATUS "IPO / LTO enabled")
    set_property(TARGET shapes_benchmark PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
    message(STATUS "IPO / LTO not supported: <${error}>")
endif()
set_property(TARGET shapes_benchmark PROPERTY CXX_STANDARD 17)

target_link_libraries(shapes_benchmark PUBLIC benchmark::benchmark)