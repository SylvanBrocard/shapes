#include "shapes.h"

/* ========================================================================
   LISTING 23
   ======================================================================== */

f32 TotalAreaVTBL(u32 ShapeCount, shape_base **Shapes)
{
    f32 Accum = 0.0f;
    #if PARALLEL
    #pragma omp parallel for reduction(+:Accum)
    #endif
    for(u32 ShapeIndex = 0; ShapeIndex < ShapeCount; ++ShapeIndex)
    {
        Accum += Shapes[ShapeIndex]->Area();
    }
    
    return Accum;
}
