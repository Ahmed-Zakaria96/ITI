#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"


class Circle : public Shape
{
    public:
        // constructor
        Circle();
        Circle(float d);

        // functions
        float Area();



};

#endif // CIRCLE_H
