#include "Shape.h"

// constructors
Shape::Shape()
{
    dim1 = dim2 = 0.0;
}
Shape::Shape(float d)
{
    dim1 = dim2 = d;
}
Shape::Shape(float d1, float d2)
{
    dim1 = d1;
    dim2 = d2;
}

// destructor
Shape::~Shape()
{
    //dtor
}

// setters
void Shape::setDim1(float d1)
{
    dim1 = d1;
}

void Shape::setDim2(float d2)
{
    dim2 = d2;
}

// getters
float Shape::getDim1()
{
    return dim1;
}

float Shape::getDim2()
{
    return dim2;
}


