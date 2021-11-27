#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

int main()
{
    char char_array[11];
    cout<<"Please enter a string of 10 chars"<<endl;
    for (int i = 0; i < 10; i++)
    {
        char ch;
        ch = getche();
        char_array[i] = ch;
    }
    char_array[10] = '\0';
    cout<<endl;
    cout<<"You Entered "<<endl;
    for (int i = 0; i < 11; i++)
    {
        cout<<char_array[i];
    }
    cout<<endl;
    return 0;
}
