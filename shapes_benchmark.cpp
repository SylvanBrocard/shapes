#include <iostream>

#include <benchmark/benchmark.h>

#include "oopshapes.h"

class ShapesFixture : public benchmark::Fixture {
public:
  u32 ShapeCount = 1e8;
  shape_base **Shapes = new shape_base *[ShapeCount];

  void SetUp(const ::benchmark::State &state) {
    srand(time(NULL));
    #pragma omp simd
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex) {
        u32 ShapeType = rand() % 4;
        switch(ShapeType)
        {
            case 0:
            {
                f32 Side = rand() % 100;
                Shapes[ShapeIndex] = new square(Side);
            } break;
            
            case 1:
            {
                f32 Width = rand() % 100;
                f32 Height = rand() % 100;
                Shapes[ShapeIndex] = new rectangle(Width, Height);
            } break;
            
            case 2:
            {
                f32 Base = rand() % 100;
                f32 Height = rand() % 100;
                Shapes[ShapeIndex] = new triangle(Base, Height);
            } break;
            
            case 3:
            {
                f32 Radius = rand() % 100;
                Shapes[ShapeIndex] = new circle(Radius);
            } break;
        }
    }
  }

  void TearDown(const ::benchmark::State &state) {
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex) {
      delete Shapes[ShapeIndex];
    }
  }
};

BENCHMARK_DEFINE_F(ShapesFixture, TotalAreaVTBL)(benchmark::State &state) {
  for (auto _ : state) {
    f32 Accum = 0.0f;
    for (u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex) {
      Accum += Shapes[ShapeIndex]->Area();
    }
    std::cout << Accum << std::endl;
  }
}
BENCHMARK_REGISTER_F(ShapesFixture, TotalAreaVTBL)->UseRealTime()->Unit(benchmark::kSecond);

BENCHMARK_MAIN();