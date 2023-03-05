#include <memory>
#include "../common.h"

class soa_shapes_base
{
public:
    virtual f32 AreaSum() = 0;
};

class soa_squares final : public soa_shapes_base
{
public:
    void Add(f32 Side);
    f32 AreaSum() final;

private:
    std::vector<f32> Side;
};

class soa_rectangles final : public soa_shapes_base
{
public:
    void Add(f32 Width, f32 Height);
    f32 AreaSum() final;

private:
    std::vector<std::tuple<f32, f32>> Width_Height;
};

class soa_triangles final : public soa_shapes_base
{
public:
    void Add(f32 Base, f32 Height);
    f32 AreaSum() final;

private:
    std::vector<std::tuple<f32, f32>> Base_Height;
};

class soa_circles final : public soa_shapes_base
{
public:
    void Add(f32 Radius);
    f32 AreaSum() final;

private:
    std::vector<f32> Radius;
};

struct ShapeCollection
{
    soa_squares Squares;
    soa_rectangles Rectangles;
    soa_triangles Triangles;
    soa_circles Circles;
};

f32 TotalAreaSoA(u32 ShapeCount, ShapeCollection &Shapes);
