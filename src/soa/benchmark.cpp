#include <benchmark/benchmark.h>
#include "shapes.h"

class SoAShapesFixture : public benchmark::Fixture
{
public:
  ShapeCollection Shapes;

  void SetUp(const ::benchmark::State &state)
  {
// #pragma omp simd
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex)
    {
      u32 ShapeType = rand() % 4;
      switch (ShapeType)
      {
      case 0:
      {
        f32 Side = rand() % 100;
        Shapes.Squares.Add(Side);
      }
      break;

      case 1:
      {
        f32 Width = rand() % 100;
        f32 Height = rand() % 100;
        Shapes.Rectangles.Add(Width, Height);
      }
      break;

      case 2:
      {
        f32 Base = rand() % 100;
        f32 Height = rand() % 100;
        Shapes.Triangles.Add(Base, Height);
      }
      break;

      case 3:
      {
        f32 Radius = rand() % 100;
        Shapes.Circles.Add(Radius);
      }
      break;
      }
    }
  }

  void TearDown(const ::benchmark::State &state) {}
};

BENCHMARK_DEFINE_F(SoAShapesFixture, TotalAreaSoA)
(benchmark::State &state)
{
  for (auto _ : state)
  {
    auto Accum = TotalAreaSoA(ShapeCount, Shapes);
    benchmark::DoNotOptimize(Accum);
  }
}
BENCHMARK_REGISTER_F(SoAShapesFixture, TotalAreaSoA)->Unit(benchmark::kMillisecond)->Setup(DoSetup);