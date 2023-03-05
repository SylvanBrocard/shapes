#include "shapes.h"

f32 TotalAreaVTBLClean(u32 ShapeCount, clean_shape_base **Shapes)
{
    // TODO: use iterator
    f32 Accum = 0.0f;
    for(u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex)
    {
        Accum += Shapes[ShapeIndex]->Area();
    }
    
    return Accum;
}
