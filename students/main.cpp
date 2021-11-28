#include <iostream>
#include <limits>
#include<stdlib.h>

struct student {
        int id;
        char name[50];
        int grades[5];
};

using namespace std;
void addStudent(int& position, student* stdData, int ar_size);
void displayMenu();

void displayStudent(student* stdData, int ar_size, int position);
void displayAll(student* studentArray, int ar_size, int position);
void printStudent (student* stdData, int index);

int main()
{
    cout<<"Students track program"<<endl;

    int position = 0;
    int userInput;

    displayMenu();

    int studentNumber;
    cout<<"Enter Number of sudents : ";
    cin>>studentNumber;

    student* studentArray;
    studentArray = new student[studentNumber];
    if (studentArray != NULL)
    {

        int check = 1;
        while (check == 1){
            cout<<"Enter you select: ";
            cin>>userInput;
            if ( cin.fail())
            {
                cout << "\n\tError -- Please choose only from available options [1 - 4]!\n";
                 // get rid of failure state
                cin.clear();

                 // discard 'bad' character(s)
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("pause");
                continue;
            }
            if (userInput == 1)
            {
                addStudent(position, studentArray, studentNumber);
            } else if (userInput == 2)
            {
                displayStudent(studentArray, studentNumber, position);
            } else if (userInput == 3){
                displayAll(studentArray, studentNumber, position);
            } else if (userInput == 4){
                check = 0;
            }
        }
    } else {
        cout<<"Couldn't allocate memory"<<endl;
        cout<<"Exiting..."<<endl;
    }
    delete(studentArray);
    return 0;

}

void addStudent(int& position, student* stdData, int ar_size)
{
    if ( position < ar_size )
    {
        cout<<"Enter student data: "<<endl;
        cout<<"Enter id: ";
        cin>>stdData[position].id;

        cout<<"Enter name: ";
        cin>>stdData[position].name;

        for (int i = 0; i < 5; i++)
        {
            cout<<"Enter subject "<<i+1<<" grade: ";
            cin>>stdData[position].grades[i];

        }
        position +=1;
    } else {
        cout<<"Array is Full cant add more"<<endl;
    }

}

void displayMenu()
{
    cout<< "Chose a option to perform a task"<<endl;
    cout<< "1- Add"<<endl;
    cout<< "2- Display"<<endl;
    cout<< "3- Display all"<<endl;
    cout<< "4- Exit"<<endl;
}

void displayStudent(student* stdData, int ar_size, int position)
{
    int index;
    cout<<"Enter student Number: ";
    cin>>index;
    int sum=0;
    if (index >= 1 and index <= ar_size and index <= position)
    {
        cout<<"Student Name: "<< stdData[index-1].name<<endl;
        cout<<"Student ID: "<< stdData[index-1].id<<endl;
        for (int i=0; i < 5; i++)
        {
            cout<<stdData[index-1].grades[i];
            sum += stdData[index-1].grades[i];
        }
        cout<<"Student grades Sum: "<< sum <<endl;
    }
    else {
        cout<<"Not a valid student"<<endl;
    }

}

void displayAll(student* stdData, int ar_size, int position)
{
    for (int i = 0; i < position; i++)
    {
        printStudent(stdData, i);
    }
}

void printStudent (student* stdData, int index){
    int sum;
    cout<<"Students"<<endl;

    for (int i = 0; i < 5; i ++)
    {
        sum += stdData[index].grades[i];
    }
    cout<<"Student ID: "<< stdData[index].id<<endl;
    cout<<"Student Name: "<< stdData[index].name<<endl;
    cout<<"Student Grades Sum: "<< sum <<endl;
}
