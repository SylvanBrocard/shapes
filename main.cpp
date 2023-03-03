#include <stdio.h>
#include "types.h"

/* ========================================================================
   LISTING 22
   ======================================================================== */

class shape_base
{
public:
    shape_base() {}
    virtual f32 Area() = 0;
};

class square : public shape_base
{
public:
    square(f32 SideInit) : Side(SideInit) {}
    virtual f32 Area() {return Side*Side;}
    
private:
    f32 Side;
};

class rectangle : public shape_base
{
public:
    rectangle(f32 WidthInit, f32 HeightInit) : Width(WidthInit), Height(HeightInit) {}
    virtual f32 Area() {return Width*Height;}
    
private:
    f32 Width, Height;
};

class triangle : public shape_base
{
public:
    triangle(f32 BaseInit, f32 HeightInit) : Base(BaseInit), Height(HeightInit) {}
    virtual f32 Area() {return 0.5f*Base*Height;}
    
private:
    f32 Base, Height;
};

class circle : public shape_base
{
public:
    circle(f32 RadiusInit) : Radius(RadiusInit) {}
    virtual f32 Area() {return Pi32*Radius*Radius;}
    
private:
    f32 Radius;
};

/* ========================================================================
   LISTING 23
   ======================================================================== */

f32 TotalAreaVTBL(u32 ShapeCount, shape_base **Shapes)
{
    f32 Accum = 0.0f;
    for(u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex)
    {
        Accum += Shapes[ShapeIndex]->Area();
    }
    
    return Accum;
}

/* ========================================================================
   LISTING 24
   ======================================================================== */

f32 TotalAreaVTBL4(u32 ShapeCount, shape_base **Shapes)
{
    f32 Accum0 = 0.0f;
    f32 Accum1 = 0.0f;
    f32 Accum2 = 0.0f;
    f32 Accum3 = 0.0f;
    
    u32 Count = ShapeCount/4;
    while(Count--)
    {
        Accum0 += Shapes[0]->Area();
        Accum1 += Shapes[1]->Area();
        Accum2 += Shapes[2]->Area();
        Accum3 += Shapes[3]->Area();
        
        Shapes += 4;
    }
    
    f32 Result = (Accum0 + Accum1 + Accum2 + Accum3);
    return Result;
}

int main(int, char**) {
    square Square(2.0f);
    rectangle Rectangle(2.0f, 3.0f);
    triangle Triangle(2.0f, 3.0f);
    circle Circle(2.0f);
    
    shape_base *Shapes[] =
    {
        &Square,
        &Rectangle,
        &Triangle,
        &Circle,
    };
    
    f32 TotalArea = TotalAreaVTBL(4, Shapes);
    printf("Total area: %f\n", TotalArea);

    return 0;
}
