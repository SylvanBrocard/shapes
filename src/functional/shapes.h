#include "../common.h"
#include <variant>

class fun_square final
{
public:
    explicit fun_square(f32 SideInit) : Side(SideInit) {}
    f32 Area() {return Side*Side;}
    
private:
    f32 Side;
};

class fun_rectangle final
{
public:
    explicit fun_rectangle(f32 WidthInit, f32 HeightInit) : Width(WidthInit), Height(HeightInit) {}
    f32 Area() {return Width*Height;}
    
private:
    f32 Width, Height;
};

class fun_triangle final
{
public:
    explicit fun_triangle(f32 BaseInit, f32 HeightInit) : Base(BaseInit), Height(HeightInit) {}
    f32 Area() {return 0.5f*Base*Height;}
    
private:
    f32 Base, Height;
};

class fun_circle final
{
public:
    explicit fun_circle(f32 RadiusInit) : Radius(RadiusInit) {}
    f32 Area() {return Pi32*Radius*Radius;}
    
private:
    f32 Radius;
};

using fun_shape=std::variant<fun_square, fun_rectangle, fun_triangle, fun_circle>;

f32 TotalAreaFunc(u32 ShapeCount, std::vector<fun_shape> Shapes);
