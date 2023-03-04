#include "oldshapes.h"

/* ========================================================================
   LISTING 25
   ======================================================================== */

static f32 GetAreaSwitch(shape_union Shape)
{
    f32 Result = 0.0f;
    
    switch(Shape.Type)
    {
        case Shape_Square: {Result = Shape.Width*Shape.Width;} break;
        case Shape_Rectangle: {Result = Shape.Width*Shape.Height;} break;
        case Shape_Triangle: {Result = 0.5f*Shape.Width*Shape.Height;} break;
        case Shape_Circle: {Result = Pi32*Shape.Width*Shape.Width;} break;
        
        case Shape_Count: {} break;
    }
    
    return Result;
}

f32 TotalAreaSwitch(u32 ShapeCount, shape_union* Shape)
{
    f32 Accum = 0.0f;
    for(u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex)
    {
        Accum += GetAreaSwitch(Shape[ShapeIndex]);
    }
    
    return Accum;
}
