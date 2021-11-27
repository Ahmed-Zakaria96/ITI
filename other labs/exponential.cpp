#include <iostream>

using namespace std;

int calculatePower(int x, int y);

int main()
{
    int base, power, result;

    cout << "Enter base number: "<<endl;;
    cin >> base;

    cout << "Enter power number(positive integer): "<<endl;
    cin >> power;

    result = calculatePower(base, power);
    cout << "Result = "<< result<<endl;

    return 0;
}

int calculatePower(int base, int power)
{
    if (power == 0)
        return 1;
    else
        return (base*calculatePower(base, power-1));
}
