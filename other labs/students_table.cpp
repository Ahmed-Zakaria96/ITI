#include <iostream>

using namespace std;

//helper function
void display_table();
void calculate_sum();
void calculate_avg();

//2d array declared golbal to allow helper function to use it outside main
int student_grades[4][5];

int main()
{
    //take user input about students data and store it in the global variable
    for (int student = 0; student < 3; student++)
    {
        for (int sub = 0; sub < 4; sub++)
        {
            cout<<"Enter student "<<student+1<< " grades"<<endl;
            cout<<"Sub "<<sub+1<<endl;
            cin>>student_grades[student][sub];
        }
    }
    //calculate sum of each student grade and update global variable
    calculate_sum();
    //calculate avg of each subject  and update global variable
    calculate_avg();
    //display data after completion
    display_table();
    return 0;
}

//funtion to calculate summ of each student grades
void calculate_sum()
{
    //loop through students subjects sum grades and store sum in global variable
    for (int student = 0; student < 3; student++)
    {
        int student_sum = 0;
        for (int sub = 0; sub < 4; sub++)
        {
            student_sum += student_grades[student][sub];
        }
        student_grades[student][4] = student_sum;
    }
}
//funtion to calculate avg of each student grades
void calculate_avg()
{
    //loop through subject and sum students grades and store avg in global variable
    for (int col = 0; col < 4; col++)
    {
        int student_count = 0;
        int sub_sum = 0;
        for (int row=0; row <3; row++)
        {
            sub_sum += student_grades[row][col];
            student_count ++;
        }
        student_grades[3][col] = sub_sum /student_count;
    }
}

//display data as table
//notice if u use same number the table will look good else consider the result not the look :D
void display_table()
{
    //first print student and subjects grades
    cout<<"Student      sub1    sub2    sub3    sub4    sum"<<endl;
    for (int i = 0; i < 3 ;i++)
    {
        cout<<"STD"<<i+1<<"          ";
        for (int x = 0; x < 5; x++)
        {
            cout<<student_grades[i][x]<<"       ";
        }
        cout<<endl;
    }
    //then print the avg for each subject
    cout<<"AVG           ";
    for (int a = 0; a < 4; a++)
    {

        cout<<student_grades[3][a]<<"       ";
    }
    cout<<endl;
}
