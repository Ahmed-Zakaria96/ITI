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
    cout<<"\n\nWelcome to Shapes Area Calculator Program. \n\n"<<endl;

    // number of shapes and user menu selection of shape
    int number, selection;
    int counter = 0;

    C.White();
    // display shapes menu
    displayShapes();
    cout<<endl;

    C.Blue();
    // get shapes groups number
    int groupsNumber;
    cout<<"Enter Number of groups: ";
    cin>>groupsNumber;
    // counter to keep track of group
    int groupCounter = 0;

    // create array of AreaCalculator of users size
    AreaCalculator* aG;
    aG = new AreaCalculator [groupsNumber];
    // check for null
    if (aG == NULL)
    {
        return 1;
    }
    // create flag to for groups loop
    int check = 1;
    while (check == 1)
    {
        // check number of groups created
        if (groupCounter < groupsNumber)
        {
            C.Purple();
            cout<<"Group "<<groupCounter+1<<": "<<endl;
            C.LWhite();
            // ask your for each group number of shapes
            cout<<"How many shapes do you have?"<<endl;
            cin>>number;

            // create an array of pointer to shapes of user shape count
            Shape** shapes = new Shape*[number];

            // fill the array with shapes
            int flag = 1;
            while (flag == 1)
            {
                // if entered shapes count < user number of shapes
                if (counter < number )
                {
                    C.LPurple();
                    // ask user to select type of shape from menu
                    cout<<"Select type of shape NO."<<counter +1<<": ";
                    cin>>selection;
                    // if user is not friendly
                    if ( cin.fail() )
                    {
                        C.Red();
                        cout << "\n\tError -- Please choose only from available options [1 - 4]!\n";
                         // get rid of failure state
                        cin.clear();
                         // discard 'bad' character(s)
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("pause");
                        continue;
                    } else {
                        // if user is nice switch his selection to shapes and store it in shapes array
                        // keep track of shapes and increase counter inside switchselect
                        C.Grey();
                        shapes[counter] = switchSelection(selection, counter);
                    }
                } else {
                    // exit loop
                    counter = 0;
                    flag = 0;
                }

            }
            // after taking shapes info add them to AreaCalculator array aG
            aG[groupCounter].setShapes(shapes);
            aG[groupCounter].setNumber(number);
            // increase group counter
            groupCounter +=1;
            cout<<endl;
        } else {
            //groups count is filled exit loop
            check = 0;
        }

    }


    for (int i = 0; i < groupsNumber; i++)
    {
        C.Purple();
        cout<<"Group "<<i+1<<":"<<endl;
        C.LPurple();
        cout<<"Number of shapes: "<<aG[i].getNumber()<<endl;
        C.Green();
        cout<<"Total Area is: "<<aG[i].TotalArea()<<endl;
        cout<<endl;
    }
    // free memory
    delete[](aG);

    C.White();
    return 0;
}

void displayShapes()
{
    cout<<"Available shapes:"<<endl;
    cout<<"\t1-Circle \t2-Rectangle \t3-Square \t4-Triangle"<<endl;
}

// switch user selection of shape and create appropriate shape
Shape* switchSelection(int s, int& sc)
{
    int dim1, dim2;
    switch(s)
    {
    case 1:
        Circle* c;
        cout<<"Enter Circle radius: ";
        cin>>dim1;
        c = new Circle(dim1);
        if ( c != NULL){
            sc +=1;
        }
        return c;
    case 2:
        Rect* r;
        cout<<"Enter Rectangle dimension1: ";
        cin>>dim1;
        cout<<"Enter Rectangle dimension2: ";
        cin>>dim2;
        r = new Rect(dim1, dim2);
        if ( r != NULL){
            sc +=1;
        }

        return r;
    case 3:
        Square* s;
        cout<<"Enter Square dimension: ";
        cin>>dim1;
        s = new Square(dim1);
        if ( s != NULL){
            sc +=1;
        }
        return s;
    case 4:
        Triangle* t;
        cout<<"Enter Triangle dimension1: ";
        cin>>dim1;
        cout<<"Enter Triangle dimension2: ";
        cin>>dim2;
        t = new Triangle(dim1, dim2);
        if ( t != NULL){
            sc +=1;
        }
        return t;
    }
}

