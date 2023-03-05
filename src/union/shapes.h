#include "../common.h"

class union_shape_base
{
public:
    union_shape_base() {}
    virtual f32 Area() = 0;
    virtual ~union_shape_base() {}
};

class union_square final : public union_shape_base
{
public:
    explicit union_square(f32 SideInit) : Side(SideInit) {}
    f32 Area() final {return Side*Side;}
    
private:
    f32 Side;
};

class union_rectangle final : public union_shape_base
{
public:
    explicit union_rectangle(f32 WidthInit, f32 HeightInit) : Width(WidthInit), Height(HeightInit) {}
    f32 Area() final {return Width*Height;}
    
private:
    f32 Width, Height;
};

class union_triangle final : public union_shape_base
{
public:
    explicit union_triangle(f32 BaseInit, f32 HeightInit) : Base(BaseInit), Height(HeightInit) {}
    f32 Area() final {return 0.5f*Base*Height;}
    
private:
    f32 Base, Height;
};

class union_circle final : public union_shape_base
{
public:
    explicit union_circle(f32 RadiusInit) : Radius(RadiusInit) {}
    f32 Area() final {return Pi32*Radius*Radius;}
    
private:
    f32 Radius;
};

enum class Type
{
    Square,
    Rectangle,
    Triangle,
    Circle
};

struct union_shape
{
    Type type;
    union 
    {
        union_square Square;
        union_rectangle Rectangle;
        union_triangle Triangle;
        union_circle Circle;
    };
};

f32 TotalAreaUnion(u32 ShapeCount, std::vector<union_shape>& Shapes);
