#include <memory>
#include "../common.h"

class clean_shape_base
{
public:
    clean_shape_base() {}
    virtual f32 Area() = 0;
    virtual ~clean_shape_base() {}
};

class clean_square final : public clean_shape_base
{
public:
    explicit clean_square(f32 SideInit) : Side(SideInit) {}
    f32 Area() final {return Side*Side;}
    
private:
    f32 Side;
};

class clean_rectangle final : public clean_shape_base
{
public:
    explicit clean_rectangle(f32 WidthInit, f32 HeightInit) : Width(WidthInit), Height(HeightInit) {}
    f32 Area() final {return Width*Height;}
    
private:
    f32 Width, Height;
};

class clean_triangle final : public clean_shape_base
{
public:
    explicit clean_triangle(f32 BaseInit, f32 HeightInit) : Base(BaseInit), Height(HeightInit) {}
    f32 Area() final {return 0.5f*Base*Height;}
    
private:
    f32 Base, Height;
};

class clean_circle final : public clean_shape_base
{
public:
    explicit clean_circle(f32 RadiusInit) : Radius(RadiusInit) {}
    f32 Area() final {return Pi32*Radius*Radius;}
    
private:
    f32 Radius;
};

f32 TotalAreaVTBLClean(u32 ShapeCount, std::vector<std::unique_ptr<clean_shape_base>>& Shapes);
