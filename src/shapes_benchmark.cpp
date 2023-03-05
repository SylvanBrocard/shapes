#include <iostream>

#include <benchmark/benchmark.h>

#include "common.h"

void DoSetup(const benchmark::State& state) {
    srand(0);
}

BENCHMARK_MAIN();