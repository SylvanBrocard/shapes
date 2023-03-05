#include <iostream>

#include <benchmark/benchmark.h>

#include "oop/shapes.h"
#include "cstyle/shapes.h"

constexpr u32 ShapeCount = 1e7;

static void DoSetup(const benchmark::State& state) {
    srand(0);
}

class OOPShapesFixture : public benchmark::Fixture
{
public:
  shape_base **Shapes;

  void SetUp(const ::benchmark::State &state)
  {
    Shapes = new shape_base *[ShapeCount];
    // timespec *tp;
    // clock_gettime(CLOCK_REALTIME, tp);
// #pragma omp simd
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex)
    {
      u32 ShapeType = rand() % 4;
      switch (ShapeType)
      {
      case 0:
      {
        f32 Side = rand() % 100;
        Shapes[ShapeIndex] = new square(Side);
      }
      break;

      case 1:
      {
        f32 Width = rand() % 100;
        f32 Height = rand() % 100;
        Shapes[ShapeIndex] = new rectangle(Width, Height);
      }
      break;

      case 2:
      {
        f32 Base = rand() % 100;
        f32 Height = rand() % 100;
        Shapes[ShapeIndex] = new triangle(Base, Height);
      }
      break;

      case 3:
      {
        f32 Radius = rand() % 100;
        Shapes[ShapeIndex] = new circle(Radius);
      }
      break;
      }
    }
  }

  void TearDown(const ::benchmark::State &state)
  {
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex)
    {
      delete Shapes[ShapeIndex];
    }
    delete[] Shapes;
  }
};

BENCHMARK_DEFINE_F(OOPShapesFixture, TotalAreaVTBL)
(benchmark::State &state)
{
  for (auto _ : state)
  {
    auto Accum = TotalAreaVTBL(ShapeCount, Shapes);
    std::cout << Accum << std::endl;
  }
}
BENCHMARK_REGISTER_F(OOPShapesFixture, TotalAreaVTBL)->UseRealTime()->Unit(benchmark::kSecond)->Setup(DoSetup);

class OldShapesFixture : public benchmark::Fixture
{
public:
  shape_union *Shapes;

  void SetUp(const ::benchmark::State &state)
  {
    Shapes = new shape_union[ShapeCount];
    // timespec *tp;
    // clock_gettime(CLOCK_REALTIME, tp);
    srand(0);
// #pragma omp simd
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex)
    {
      u32 ShapeType = rand() % 4;
      switch (ShapeType)
      {
      case 0:
      {
        f32 Side = rand() % 100;
        Shapes[ShapeIndex].Type = Shape_Square;
        Shapes[ShapeIndex].Width = Side;
        Shapes[ShapeIndex].Height = Side;
      }
      break;

      case 1:
      {
        f32 Width = rand() % 100;
        f32 Height = rand() % 100;
        Shapes[ShapeIndex].Type = Shape_Rectangle;
        Shapes[ShapeIndex].Width = Width;
        Shapes[ShapeIndex].Height = Height;
      }
      break;

      case 2:
      {
        f32 Base = rand() % 100;
        f32 Height = rand() % 100;
        Shapes[ShapeIndex].Type = Shape_Triangle;
        Shapes[ShapeIndex].Width = Base;
        Shapes[ShapeIndex].Height = Height;
      }
      break;

      case 3:
      {
        f32 Radius = rand() % 100;
        Shapes[ShapeIndex].Type = Shape_Circle;
        Shapes[ShapeIndex].Width = Radius;
        Shapes[ShapeIndex].Height = Radius;
      }
      break;
      }
    }
  }

  void TearDown(const ::benchmark::State &state)
  {
    delete[] Shapes;
  }
};

BENCHMARK_DEFINE_F(OldShapesFixture, TotalAreaSwitch)
(benchmark::State &state)
{
  for (auto _ : state)
  {
    auto Accum = TotalAreaSwitch(ShapeCount, Shapes);
    std::cout << Accum << std::endl;
  }
}

BENCHMARK_REGISTER_F(OldShapesFixture, TotalAreaSwitch)->UseRealTime()->Unit(benchmark::kSecond)->Setup(DoSetup);

BENCHMARK_MAIN();