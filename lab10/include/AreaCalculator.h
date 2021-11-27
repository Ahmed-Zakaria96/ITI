#ifndef AREACALCULATOR_H
#define AREACALCULATOR_H
#include <iostream>
#include "shape.h"

class AreaCalculator
{
    protected:
        Shape** shapes;

    public:
        //constructor
        AreaCalculator(int number, Shape** shapes);
        ~AreaCalculator();

        // functions
        float TotalArea(int number);
};

#endif // AREACALCULATOR_H
