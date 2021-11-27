#ifndef SHAPE_H
#define SHAPE_H

class Shape

    {
    protected:
        float dim1, dim2;

    public:
        // constructors
        Shape();
        Shape(float d);
        Shape(float d1, float d2);
        // destructor
        virtual ~Shape();

        // setters
        void setDim1(float d1);
        void setDim2(float d2);

        // getters
        float getDim1();
        float getDim2();

        // virtual function
        virtual float Area() = 0;



};



#endif // SHAPE_H
