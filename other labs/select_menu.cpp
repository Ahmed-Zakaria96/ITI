#include <iostream>
#include <windows.h>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//prototypes
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);
void gotoxy( int column, int line);
void display_menu();
void take_option(int first_number, int second_number, int select);
void select_option();
void clear_selection();
void wait();

int main()
{
    display_menu();
    select_option();
    return 0;
}
void select_option()
{
    int current = 1;
    int cursor = 8;
    gotoxy(1, cursor);
    printf(">");
    char ch;
    ch = getch();
    while (ch != -32)
    {
        gotoxy(1, 1);
        printf("use up and down arrows");
        ch = getch();
    }
    if (ch == -32)
    {
        ch = getch();

        while (ch != 13){

            ch = getch();
            if (ch == 72)
            {
                if (cursor == 8)
                {
                    cursor = 16;
                    current = 5;
                } else {
                    cursor -= 2;
                    current --;
                }

            } else if (ch == 80)
            {
                if (cursor == 16)
                {
                    cursor = 8;
                    current = 1;
                } else {
                    cursor += 2;
                    current ++;
                }
            }

            clear_selection();
            gotoxy(1, cursor);
            printf(">");
        }
        system("CLS");
        int first_number, second_number;
        cout<<"Enter First number"<<endl;
        cin>>first_number;
        cout<<"Enter second number"<<endl;
        cin>>second_number;
        take_option(first_number, second_number, current);
    }
}
void clear_selection()
{
    gotoxy(1, 8);
    printf(" ");
    gotoxy(1, 10);
    printf(" ");
    gotoxy(1, 12);
    printf(" ");
    gotoxy(1, 14);
    printf(" ");
    gotoxy(1, 16);
    printf(" ");
}
void gotoxy( int column, int line )
{
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
}

void display_menu()
{
    gotoxy(1, 1);
    cout<<"\n move up and down then enter to select"<<endl;
    gotoxy(1, 4);
    cout<<"Menu Select options"<<endl;
    gotoxy(2, 8);
    printf("1-add");
    gotoxy(2, 10);
    printf("2-subtract");
    gotoxy(2, 12);
    printf("3-multiply");
    gotoxy(2, 14);
    printf("4-divide");
    gotoxy(2, 16);
    printf("5-exit");
}

void take_option(int first_number, int second_number, int select)
{
    switch(select)
    {
    case 1:
        system("CLS");
        add(first_number, second_number);
        wait();
        break;
    case 2:
        system("CLS");
        subtract(first_number, second_number);
        wait();
        break;
    case 3:
        system("CLS");
        multiply(first_number, second_number);
        wait();
        break;
    case 4:
        system("CLS");
        divide(first_number, second_number);
        wait();
        break;
    case 5:
        cout<<"Exiting"<<endl;
        return;
    default:
        wait();
    }

}

void wait()
{

    char w;
    w = getch();
    while (!w)
    {
        w = getch();
    }
    system("CLS");
    display_menu();
    select_option();
}
//function body
void add(int a, int b)
{
    int z = a+b;
    cout<<"a + b = "<<z<<endl;
}

void subtract(int a, int b)
{
    int z = a-b;
    cout<<"a - b = "<<z<<endl;
}

void multiply(int a, int b)
{
    int z = a*b;
    cout<<"a * b = "<<z<<endl;
}

void divide(int a, int b)
{
    int z = a/b;
    cout<<"a / b = "<<z<<endl;
}
