#include "shapes.h"

f32 TotalAreaUnion(u32 ShapeCount, std::vector<union_shape>& Shapes)
{
    f32 Accum = 0.0f;
    #if PARALLEL
    #pragma omp parallel for reduction(+:Accum)
    #endif
    for(auto& Shape : Shapes)
    {
        switch(Shape.type)
        {
            case Type::Square:
            {
                Accum += Shape.Square.Area();
            } break;
            
            case Type::Rectangle:
            {
                Accum += Shape.Rectangle.Area();
            } break;
            
            case Type::Triangle:
            {
                Accum += Shape.Triangle.Area();
            } break;
            
            case Type::Circle:
            {
                Accum += Shape.Circle.Area();
            } break;
        }
    }
    
    return Accum;
}
