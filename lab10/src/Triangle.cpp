#include "Triangle.h"

// constructor
Triangle::Triangle()
{
    // default constructor
}
Triangle::Triangle(float d1, float d2):Shape(d1, d2)
{
    // do nothing
}

// calculate area
float Triangle::Area()
{
    return (0.5 * dim1 * dim2);
}
