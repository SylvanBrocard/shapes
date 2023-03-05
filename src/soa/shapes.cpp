#include <numeric>
#include "shapes.h"

#if PARALLEL
#include <execution>
#define PAR std::execution::par,
#else
#define PAR
#endif

void soa_squares::Add(f32 Side)
{
    this->Side.push_back(Side);
}

void soa_rectangles::Add(f32 Width, f32 Height)
{
    this->Width_Height.push_back(std::make_tuple(Width, Height));
}

void soa_triangles::Add(f32 Base, f32 Height)
{
    this->Base_Height.push_back(std::make_tuple(Base, Height));
}

void soa_circles::Add(f32 Radius)
{
    this->Radius.push_back(Radius);
}

f32 soa_squares::AreaSum()
{
    return std::transform_reduce(PAR this->Side.begin(), this->Side.end(), 0.0f, std::plus<f32>(), [](f32 Side)
                                 { return Side * Side; });
}

f32 soa_rectangles::AreaSum()
{

    return std::transform_reduce(PAR this->Width_Height.begin(), this->Width_Height.end(), 0.0f, std::plus<f32>(), [](std::tuple<f32, f32> Width_Height)
                                 { return std::get<0>(Width_Height) * std::get<1>(Width_Height); });
}

f32 soa_triangles::AreaSum()
{

    return std::transform_reduce(PAR this->Base_Height.begin(), this->Base_Height.end(), 0.0f, std::plus<f32>(), [](std::tuple<f32, f32> Base_Height)
                                 { return 0.5f * std::get<0>(Base_Height) * std::get<1>(Base_Height); });
}

f32 soa_circles::AreaSum()
{
    return std::transform_reduce(PAR this->Radius.begin(), this->Radius.end(), 0.0f, std::plus<f32>(), [](f32 Radius)
                                 { return Pi32 * Radius * Radius; });
}

f32 TotalAreaSoA(u32 ShapeCount, ShapeCollection &Shapes)
{
    f32 Accum = 0.0f;
    Accum += Shapes.Squares.AreaSum();
    Accum += Shapes.Rectangles.AreaSum();
    Accum += Shapes.Triangles.AreaSum();
    Accum += Shapes.Circles.AreaSum();

    return Accum;
}
