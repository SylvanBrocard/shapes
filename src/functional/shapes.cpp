#include <numeric>
#include "shapes.h"

f32 TotalAreaFunc(u32 ShapeCount, std::vector<fun_shape> Shapes)
{
    auto Accum = std::transform_reduce(Shapes.begin(), Shapes.end(), 0.0f,
        // [](f32 Accum, f32 Shape) { return Accum + Shape; },
        std::plus{},
        [](fun_shape Shape) { return std::visit([](auto Shape) { return Shape.Area(); }, Shape); }
    );

    return Accum;
}