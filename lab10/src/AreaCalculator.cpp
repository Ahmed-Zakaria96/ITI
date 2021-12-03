#include "AreaCalculator.h"
#include <cstddef>
#include "Shape.h"

// constructor
AreaCalculator::AreaCalculator()
{
    this->number = 0;
    this->shapes = NULL;
}
AreaCalculator::AreaCalculator(int number, Shape** shapes)
{
    this->number = number;
    this->shapes = new Shape*[number];

    for(int i = 0; i < number; i++)
    {
        this->shapes[i] = shapes[i];
    }
}
// destructor
AreaCalculator::~AreaCalculator()
{
    for (int i = 0; i < number; i++ )
    {
        delete(shapes[i]);
    }
    delete(shapes);
}

// setter
void AreaCalculator::setShapes(Shape** shapes)
{
    this->shapes = shapes;
}
void AreaCalculator::setNumber(int number)
{
    this->number = number;
}

// getter

int AreaCalculator::getNumber()
{
    return number;
}
// functions
float AreaCalculator::TotalArea()
{
    float total = 0;
    for (int i = 0; i < number; i ++)
    {
        total += shapes[i]->Area();
    }
    return total;
}
