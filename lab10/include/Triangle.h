#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <Shape.h>


class Triangle : public Shape
{
    public:
        // constructor
        Triangle();
        Triangle(float d1, float d2);

        // functions
        float Area();

};

#endif // TRIANGLE_H
