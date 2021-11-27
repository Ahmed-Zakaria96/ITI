#include <iostream>
#include <limits>
#include "colors.h"
#include "classes.h"


using namespace std;
using namespace CC;

// helper functions
void displayShapes();
Shape* switchSelection(int s, int& counter);

int main()
{
    ConsoleColor C;
    cout<<"Welcome to Shapes Area Calculator Program. \n \n"<<endl;

    int number, selection;
    int counter = 0;
    C.InputM();


    cout<<"How many shapes do you have?"<<endl;
    cin>>number;
    cout<<endl;

    C.Message();
    displayShapes();
    cout<<endl;

    /*
    {

    C.InputM();

    int dim1, dim2;
    cout<<"Enter Circle Dimension: ";
    cin>>dim1;
    Circle c(dim1);
    cout<<endl;

    cout<<"Enter Rectangle Dimensions: "<<endl;
    cout<<"Dimension 1: ";
    cin>>dim1;
    cout<<"Dimension 2: ";
    cin>>dim2;
    Rect r(dim1, dim2);
    cout<<endl;

    cout<<"Enter Square Dimension: ";
    cin>>dim1;
    Square s(dim1);
    cout<<endl;

    cout<<"Enter Triangle Dimensions: "<<endl;
    cout<<"Dimension 1: ";
    cin>>dim1;
    cout<<"Dimension 2: ";
    cin>>dim2;
    Triangle t(dim1, dim2);
    cout<<endl;

    C.DisplayData();
    cout<<"Area of Circle is "<<c.Area()<<endl;
    cout<<"Area of Rectangle is "<<r.Area()<<endl;
    cout<<"Area of Square is "<<s.Area()<<endl;
    cout<<"Area of Triangle is "<<t.Area()<<endl;
    }
    */

    C.InputM();

    Shape** shapes = new Shape*[number];
    int flag = 1;
    while (flag == 1)
    {
        if (counter < number )
        {
            cout<<"Select type of shape NO."<<counter +1<<": ";
            cin>>selection;
            if ( cin.fail() )
            {
                cout << "\n\tError -- Please choose only from available options [1 - 4]!\n";
                 // get rid of failure state
                cin.clear();
                 // discard 'bad' character(s)
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("pause");
                continue;
            } else {
                shapes[counter] = switchSelection(selection, counter);
            }
        } else {
            flag = 0;
        }

    }
    C.DisplayData();
    AreaCalculator ac(number, shapes);
    cout<<endl;
    cout<<"Total Area of shapes is "<<ac.TotalArea(number)<<endl;

    for (int i = 0; i < number; i++)
    {
        delete(shapes[i]);
    }
    C.InputM();
    return 0;
}

void displayShapes()
{
    cout<<"Available shapes: "<<endl;
    cout<<"\t1-Circle"<<endl;
    cout<<"\t2-Rectangle"<<endl;
    cout<<"\t3-Square"<<endl;
    cout<<"\t4-Triangle"<<endl;
}


Shape* switchSelection(int s, int& sc)
{
    int dim1, dim2;
    switch(s)
    {
    case 1:
        Circle* c;
        cout<<"Enter circle radius: ";
        cin>>dim1;
        c = new Circle(dim1);
        if ( c != NULL){
            sc +=1;
        }
        return c;
    case 2:
        Rect* r;
        cout<<"Enter rectangle dimension1: ";
        cin>>dim1;
        cout<<"Enter rectangle dimension2: ";
        cin>>dim2;
        r = new Rect(dim1, dim2);
        if ( r != NULL){
            sc +=1;
        }
        return r;
    case 3:
        Square* s;
        cout<<"Enter square dimension: ";
        cin>>dim1;
        s = new Square(dim1);
        if ( s != NULL){
            sc +=1;
        }
        return s;
    case 4:
        Triangle* t;
        cout<<"Enter triangle dimension1: ";
        cin>>dim1;
        cout<<"Enter triangle dimension2: ";
        cin>>dim2;
        t = new Triangle(dim1, dim2);
        if ( t != NULL){
            sc +=1;
        }
        return t;
    }
}

