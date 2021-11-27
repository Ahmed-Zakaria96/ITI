#include "AreaCalculator.h"
#include <cstddef>
// constructor
AreaCalculator::AreaCalculator(int number, Shape** shapes)
{
    this->shapes = new Shape*[number];

    for(int i = 0; i < number; i++)
    {
        this->shapes[i] = shapes[i];
    }
}
// destructor
AreaCalculator::~AreaCalculator()
{
    delete(shapes);
}

// functions
float AreaCalculator::TotalArea(int number)
{
    float total = 0;
    for (int i = 0; i < number; i ++)
    {
        total += shapes[i]->Area();
    }
    return total;
}
