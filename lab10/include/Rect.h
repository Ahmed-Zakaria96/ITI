#ifndef RECT_H
#define RECT_H

#include <Shape.h>


class Rect : public Shape
{
    public:
        //constructors
        Rect();
        Rect(float d1, float d2);

        // functions
        float Area();

};

#endif // RECT_H
