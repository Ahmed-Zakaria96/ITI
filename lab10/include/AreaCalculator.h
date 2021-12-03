#ifndef AREACALCULATOR_H
#define AREACALCULATOR_H
#include <iostream>
#include "shape.h"

class AreaCalculator
{
    protected:
        Shape** shapes;
        int number;

    public:
        //constructor
        AreaCalculator();
        AreaCalculator(int number, Shape** shapes);
        ~AreaCalculator();

        // functions
        float TotalArea();

        void setShapes(Shape** shapes);
        void setNumber(int number);

        int getNumber();

};
#endif // AREACALCULATOR_H
