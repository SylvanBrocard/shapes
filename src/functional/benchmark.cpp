#include <benchmark/benchmark.h>
#include "shapes.h"

class FunShapesFixture : public benchmark::Fixture
{
public:
  std::vector<fun_shape> Shapes;

  void SetUp(const ::benchmark::State &state)
  {
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex)
    {
      u32 ShapeType = rand() % 4;
      switch (ShapeType)
      {
      case 0:
      {
        f32 Side = rand() % 100;
        Shapes.push_back(fun_square(Side));
      }
      break;

      case 1:
      {
        f32 Width = rand() % 100;
        f32 Height = rand() % 100;
        Shapes.push_back(fun_rectangle(Width, Height));
      }
      break;

      case 2:
      {
        f32 Base = rand() % 100;
        f32 Height = rand() % 100;
        Shapes.push_back(fun_triangle(Base, Height));
      }
      break;

      case 3:
      {
        f32 Radius = rand() % 100;
        Shapes.push_back(fun_circle(Radius));
      }
      break;
      }
    }
  }

  void TearDown(const ::benchmark::State &state)
  {
    Shapes.clear();
  }
};

BENCHMARK_DEFINE_F(FunShapesFixture, TotalAreaFunc)
(benchmark::State &state)
{
  for (auto _ : state)
  {
    auto Accum = TotalAreaFunc(ShapeCount, Shapes);
    benchmark::DoNotOptimize(Accum);
  }
}
BENCHMARK_REGISTER_F(FunShapesFixture, TotalAreaFunc)->Unit(benchmark::kMillisecond)->Setup(DoSetup);