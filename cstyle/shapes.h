#include "../common.h"

enum shape_type : u32
{
    Shape_Square,
    Shape_Rectangle,
    Shape_Triangle,
    Shape_Circle,
    
    Shape_Count,
};

struct shape_union
{
    shape_type Type;
    f32 Width;
    f32 Height;
};

f32 TotalAreaSwitch(u32 ShapeCount, shape_union* Shape);
