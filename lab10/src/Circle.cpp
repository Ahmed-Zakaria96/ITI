#include "Circle.h"

// constructor
Circle::Circle()
{
    // default constructor
}
Circle::Circle(float d):Shape(d)
{
    // do nothing
}

// Calculate area function
float Circle::Area()
{
    return (dim1 * dim2 * 3.14);
}
