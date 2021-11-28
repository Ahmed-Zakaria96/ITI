#include <iostream>
#include <windows.h>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include <string.h>

class Employee{
    //data

    int id;
    char* name;
    int salary;

    //methods
    public:
    void setEmpID();
    void setEmpName();
    void setEmpSalary();

    int getEmpID();
    char* getEmpName();
    int getEmpSalary();

    //constructors
    //default
    Employee()
    {
        this->id = 0;
        name = new char [9];
        strcpy(this->name, "Employee");
        this->salary = 0;
    }
    //1 parameter constructor
    Employee(int empID)
    {
        this->id = empID;
        name = new char [9];
        strcpy(this->name, "Employee");
        this->salary = 0;
    }
    //2 parameters
    Employee(int empID, char empName[])
    {
        this->id = empID;
        name = new char [strlen(empName)+1];
        strcpy(this->name, empName);
        this->salary =0;
    }
    //3 parameters
    Employee(int empID, char empName[], int empSalary)
    {
        this->id = empID;
        name = new char [strlen(empName)+1];
        strcpy(this->name, empName);
        this->salary = empSalary;

    }
    //Destructor
    ~Employee(){
        delete(name);
    }

    // copy constructor
    Employee(Employee& emp){
        int nameSize;
        id = emp.id;
        salary = emp.salary;
        nameSize = strlen(emp.name);
        name = new char [nameSize+1];
        strcpy(name, emp.name);

    }

    //operator overloading
    Employee operator+(int salaryBouns);
    friend Employee operator+(int salaryBouns, Employee e);
    Employee operator++();
    Employee operator++(int d);
    Employee operator=(Employee e);
    int operator==(Employee e);
};

using namespace std;

int main()
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(console_color, 12);
    cout<<"Employee intialized with default constructor"<<endl;
    SetConsoleTextAttribute(console_color, 4);
    Employee e1;
    cout<<"ID: "<<e1.getEmpID()<<endl;
    cout<<"Name: "<<e1.getEmpName()<<endl;
    cout<<"Salary: "<<e1.getEmpSalary()<<endl;
    cout<<endl;

    SetConsoleTextAttribute(console_color, 11);
    cout<<"Employee intialized with id"<<endl;
    SetConsoleTextAttribute(console_color, 3);
    Employee e2(1);
    cout<<"ID: "<<e2.getEmpID()<<endl;
    cout<<"Name: "<<e2.getEmpName()<<endl;
    cout<<"Salary: "<<e2.getEmpSalary()<<endl;
    cout<<endl;

    SetConsoleTextAttribute(console_color, 14);
    cout<<"Employee intialized with 2 parameters constructor"<<endl;
    SetConsoleTextAttribute(console_color, 6);
    Employee e3(1, "ahmed");
    cout<<"ID: "<<e3.getEmpID()<<endl;
    cout<<"Name: "<<e3.getEmpName()<<endl;
    cout<<"Salary: "<<e3.getEmpSalary()<<endl;
    cout<<endl;

    SetConsoleTextAttribute(console_color, 10);
    cout<<"Employee intialized with 3 parameters"<<endl;
    SetConsoleTextAttribute(console_color, 2);
    Employee e4(2, "Zakaria", 5000);
    cout<<"ID: "<<e4.getEmpID()<<endl;
    cout<<"Name: "<<e4.getEmpName()<<endl;
    cout<<"Salary: "<<e4.getEmpSalary()<<endl;
    cout<<endl;

    SetConsoleTextAttribute(console_color, 15);
    cout<<"Change Employee one data"<<endl;
    e1.setEmpID();
    e1.setEmpName();
    e1.setEmpSalary();
    SetConsoleTextAttribute(console_color, 9);
    cout<<endl;
    cout<<"New Employee one data"<<endl;
    cout<<"ID: "<<e1.getEmpID()<<endl;
    cout<<"Name: "<<e1.getEmpName()<<endl;
    cout<<"Salary: "<<e1.getEmpSalary()<<endl;

    cout<<endl;
    cout<<endl;

    e1.setEmpName();

    int salaryBouuns;
    cout<<"Enter Salary bouns: ";
    cin>>salaryBouuns;

    cout<<"New salary: "<<(e1 + salaryBouuns).getEmpSalary()<<endl;
    cout<<"increase ID id++ "<< (e1++).getEmpID()<<endl;

    cout<<"increase ID ++id "<< (++e1).getEmpID()<<endl;

    if (e1 == e2 ){
        cout<<"Employee one == Employee two"<<endl;
    } else {
        cout<<"Employee one != Employee two"<<endl;
    }
    cout<<"incease salary (5 + e1) "<< (5+e1).getEmpSalary()<<endl;

    SetConsoleTextAttribute(console_color, 13);
}

void Employee::setEmpID(){
    cout<<"Enter Employee id: ";
    cin>>this->id;
}

void Employee::setEmpName(){
    int nameSize;
    char* nameChange;
    cout<<"Enter Name Size: ";
    cin>>nameSize;
    cout<<"Enter Employee Name: ";
    nameChange = new char [nameSize];
    cin>>nameChange;
    this->name = new char [strlen(nameChange)+1];
    strcpy(this->name, nameChange);
}
void Employee::setEmpSalary(){
    cout<<"Enter Employee salary: ";
    cin>>this->salary;
}

int Employee::getEmpID(){
    return this->id;
}
char* Employee::getEmpName(){
    return this->name;
}
int Employee::getEmpSalary(){
    return this->salary;
}

//operator overloading
Employee Employee::operator+(int salaryBouns){
    salary += salaryBouns;
    return *this;
}
Employee Employee::operator++(){
    id += 1;
    return *this;
}
Employee Employee::operator++(int d){
    Employee old = *this;
    id +=1;
    return old;
}
Employee Employee::operator=(Employee e){
    id = e.id;
    salary = e.salary;
    name = e.name;
}
int Employee::operator==(Employee e){
    return (id == e.id and !strcmp(name, e.name) and salary == e.salary);
}


Employee operator+(int salaryBouns, Employee e){
    e + salaryBouns;
    return e;
}
