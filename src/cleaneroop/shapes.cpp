#include "shapes.h"

f32 TotalAreaVTBLClean(u32 ShapeCount, std::vector<std::unique_ptr<clean_shape_base>>& Shapes)
{
    f32 Accum = 0.0f;
    for(auto& Shape : Shapes)
    {
        Accum += Shape->Area();
    }
    
    return Accum;
}
