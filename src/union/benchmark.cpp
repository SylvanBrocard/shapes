#include <benchmark/benchmark.h>
#include "shapes.h"

class UnionShapesFixture : public benchmark::Fixture
{
public:
  std::vector<union_shape> Shapes;

  void SetUp(const ::benchmark::State &state)
  {
// #pragma omp simd
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex)
    {
      union_shape Shape;
      u32 ShapeType = rand() % 4;
      switch (ShapeType)
      {
      case 0:
      {
        f32 Side = rand() % 100;
        Shape.type = Type::Square;
        Shape.Square = union_square(Side);
        Shapes.emplace_back(Shape);
      }
      break;

      case 1:
      {
        f32 Width = rand() % 100;
        f32 Height = rand() % 100;
        Shape.type = Type::Rectangle;
        Shape.Rectangle = union_rectangle(Width, Height);
        Shapes.emplace_back(Shape);
      }
      break;

      case 2:
      {
        f32 Base = rand() % 100;
        f32 Height = rand() % 100;
        Shape.type = Type::Triangle;
        Shape.Triangle = union_triangle(Base, Height);
        Shapes.emplace_back(Shape);
      }
      break;

      case 3:
      {
        f32 Radius = rand() % 100;
        Shape.type = Type::Circle;
        Shape.Circle = union_circle(Radius);
        Shapes.emplace_back(Shape);
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

BENCHMARK_DEFINE_F(CleanerOOPShapesFixture, TotalAreaVTBLClean)
(benchmark::State &state)
{
  for (auto _ : state)
  {
    auto Accum = TotalAreaVTBLClean(ShapeCount, Shapes);
    benchmark::DoNotOptimize(Accum);
  }
}
BENCHMARK_REGISTER_F(CleanerOOPShapesFixture, TotalAreaVTBLClean)->Unit(benchmark::kMillisecond)->Setup(DoSetup);