#include <stdio.h>
#include "shapes.h"

/* ========================================================================
   LISTING 23
   ======================================================================== */

f32 TotalAreaVTBLClean(u32 ShapeCount, clean_shape_base **Shapes)
{
    f32 Accum = 0.0f;
    for(u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex)
    {
        Accum += Shapes[ShapeIndex]->Area();
    }
    
    return Accum;
}
