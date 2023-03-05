#include <benchmark/benchmark.h>
#include "shapes.h"

class CleanerOOPShapesFixture : public benchmark::Fixture
{
public:
  std::vector<std::unique_ptr<clean_shape_base>> Shapes;

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
        Shapes.emplace_back(std::make_unique<clean_square>(Side));
      }
      break;

      case 1:
      {
        f32 Width = rand() % 100;
        f32 Height = rand() % 100;
        Shapes.emplace_back(std::make_unique<clean_rectangle>(Width, Height));
      }
      break;

      case 2:
      {
        f32 Base = rand() % 100;
        f32 Height = rand() % 100;
        Shapes.emplace_back(std::make_unique<clean_triangle>(Base, Height));
      }
      break;

      case 3:
      {
        f32 Radius = rand() % 100;
        Shapes.emplace_back(std::make_unique<clean_circle>(Radius));
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
BENCHMARK_REGISTER_F(CleanerOOPShapesFixture, TotalAreaVTBLClean)->UseRealTime()->Unit(benchmark::kSecond)->Setup(DoSetup);