#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a;
    int b;
    int c;
    cout << "inter x_square value"<< endl;
    cin >> a;
    cout << "inter x value"<< endl;
    cin >> b;
    cout << "inter constant value"<< endl;
    cin >> c;

    float sol_x1, sol_x2, delta;

    if (a != 0)
    {
        delta = sqrt((b*b) - (4*a*c));
        sol_x1 = ((-b) - delta)/ (2*a);
        sol_x2 = ((-b) + delta)/(2*a);
    }

    cout << "x1 solution "<< sol_x1 << endl;
    cout << "x2 solution " << sol_x2 << endl;
    return 0;
}
