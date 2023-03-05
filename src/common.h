#pragma once

#include <stdint.h>
#include <benchmark/benchmark.h>

#define PARALLEL 1

using f32 = float;
using u32 = uint32_t;

constexpr f32 Pi32 = 3.14159265359f;
constexpr u32 ShapeCount = 1e7;

void DoSetup(const benchmark::State& state);