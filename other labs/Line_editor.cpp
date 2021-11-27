#include <iostream>
#include <windows.h>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <string>

using namespace std;

void leftStep(int& cursor);
void rightStep(int& cursor, int last, int a_s);
void home(int& cursor);
void endButtom(int& cursor, int last);

void gotoxy( int column, int line);

void insertChar(char l, int& cursor, int& last_element, char* arr, int& a_s);
void deleteChar(int& cursor,int& last_element, char* arr, int& a_s);

void printArray(int counter, int last, char* ar);

int main()
{
    // Color of the console
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console_color, 11);
    // variable to toggle on/off insert button
    int insertButton = 0;
    //accept array size from user and store it in a variable
    int ar_size;
    cout<<"Line Editor Program \n"<<endl;
    cout<<"Enter the line length. Max(50): ";
    cin>> ar_size;

    // dynamic allocate an array of size as user entered
    char* arrayStore;
    arrayStore = new char[ar_size];
    //check for allocation success
    if (arrayStore == NULL)
    {
        cout<<"Couldn't allocate memory"<<endl;
        return 1;
    }
    // variables to keep track of current cursor and last element added by user
    int counter = 0;
    int last_element = 0;

    // start listening to user clicks on keyboard
    char ch;
    // while cursor < size of the allocated memory keep listening
    while (counter < ar_size)
    {
        // record user click
        ch = getch();
        // check if it was extended key
        if (ch == -32)
        {
            // if yes check it value to identify action
            ch = getch();
            switch(ch)
            {
            case 77:
                rightStep(counter, last_element, ar_size);
                break;
            case 75:
                leftStep(counter);
                break;
            case 71:
                home(counter);
                break;
            case 79:
                endButtom(counter, last_element);
                break;
            case 83:
                deleteChar(counter, last_element, arrayStore, ar_size);
                printArray(counter, last_element, arrayStore);
                break;
            case 82:
                if (insertButton == 0)
                {
                    insertButton = 1;
                }
                else
                {
                    insertButton = 0;
                }

                break;
            }
            continue;

        }
        // if not extended key check if it is ...
        else if (ch == 13)  //enter key
        {
            cout<<"\n You Entered: "<<endl;
            for (int i = 0; i < last_element; i++)
            {
                cout<<arrayStore[i];
            }
            return 0;

        }
        else if (ch == 27)  //escape key
        {
            cout<<endl;
            cout<<"Terminating...."<<endl;
            return 0;
        }
        // else it is a character
        else
        {
            // first check insert on or off
            // if off
            if (insertButton == 0)
            {
                // if adding new char
                if (last_element == counter)
                {
                    SetConsoleTextAttribute(console_color, 10);
                    last_element +=1;
                }
                // if editing previous char
                else if (counter < last_element)
                {
                    SetConsoleTextAttribute(console_color, 7);
                }
                gotoxy(counter, 3);
                cout<<ch;
                // store the variable in the allocated array
                arrayStore[counter] = ch;
                // stop incrementing to stay in the while loop if the increment will break the condition
                if (counter == ar_size -1)
                {
                    continue;
                }
                counter +=1;
            }
            // if insert is on
            else
            {
                insertChar(ch, counter, last_element, arrayStore, ar_size);
                printArray(counter, last_element, arrayStore);
            }

        }
    }
    // free allocated memory
    delete(arrayStore);
    return 0;
}
// print stored array content
void printArray(int counter, int last, char* ar)
{
    gotoxy(0, 3);
    for (int x = 0; x <last; x++)
    {
        cout<<ar[x];
    }
    gotoxy(counter, 3);
}

// insert element into an array
void insertChar(char l, int& cursor,int& last, char* arr, int& a_s)
{
    for (int i = last + 1; i > cursor ; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[cursor] = l;
    last +=1;
    a_s += 1;
    cursor = cursor;
}

// delete an element from arrays
void deleteChar(int& cursor,int& last, char* arr, int& a_s)
{
    if (cursor < last)
    {
        for (int i = cursor; i < last; i++)
        {
            arr[i] = arr[i+1];
        }
        last -= 1;
        a_s -=1;
        gotoxy(a_s, 3);
        cout<<' ';
    }

}

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
}

void leftStep(int& cursor)
{
    if (cursor >0)
    {
        cursor -= 1;
        gotoxy(cursor, 3);
    }
}

void rightStep(int& cursor, int last, int a_s)
{
    if (cursor < last-1)
    {
        cursor += 1;
        gotoxy(cursor, 3);
    }
    else if (cursor + 1 >= a_s)
    {
        cursor = last-1;
    }

}

void home(int& cursor)
{
    cursor = 0;
    gotoxy(cursor, 3);
}

void endButtom(int& cursor, int last)
{
    cursor = last - 1;
    gotoxy(cursor, 3);
}
