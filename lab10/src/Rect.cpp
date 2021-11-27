#include "Rect.h"

// constructors
Rect::Rect()
{
    //default constructor
}

Rect::Rect(float d1, float d2):Shape(d1, d2)
{
    //do nothing
}

// calculate area
float Rect::Area()
{
    return (dim1 * dim2);
}
