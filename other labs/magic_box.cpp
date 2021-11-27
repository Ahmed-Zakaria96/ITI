#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>

using namespace std;


void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    // i asumed we are working with 3x3 and derived the conditions based on that
    // so i didnt ask user for input if the size of the box differs we will need to derive another algorithm
    int col = 1;
    int row = 0;
    int counter = 0;
    int current = 1;

    gotoxy(col, row);
    printf("%d", current);


    for (int i = 0; i < 8; i ++)
    {
        // the sequence is going as 2 time col -1 and row +1 then 1 time col -1 only and loops
        if (counter == 2){
            if (col+1 >2)
            {
                col = 0;
            } else{
                col ++;
            }
            current ++;
            gotoxy(col, row);
            printf("%d", current);
            counter = 0;
            continue;
        }

        if(row+1 > 2 )
        {
            row = 0;

        } else{
            row ++;
        }
        if (col-1<0){
            col = 2;

        } else {
            col --;
        }
        counter ++;
        current ++;
        gotoxy(col, row);
        printf("%d", current);
    }
    getch();
    return 0;
}
