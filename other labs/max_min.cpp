#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int max_number =  -numeric_limits<int>::max();
    int min_number = numeric_limits<int>::max();

    int ar[11];
    cout<<"Enter you desired array length(Not more than 10)"<<endl;
    int numbers_count;
    cin>>numbers_count;
    for (int i = 0; i < numbers_count; i++)
    {
        cout<<"Enter number "<<i + 1<<endl;
        int number;
        cin>>number;
        ar[i] = number;
    }

    //min
    for (int i = 0; i < numbers_count; i++)
    {
        if (ar[i] > max_number)
        {
            max_number = ar[i];
        }
    }

    //max
    for (int i = 0; i < numbers_count; i++)
    {
        if (ar[i] < min_number)
        {
            min_number = ar[i];
        }
    }

    cout<<"max = "<<max_number<<endl;
    cout<<"min = "<<min_number<<endl;

}
