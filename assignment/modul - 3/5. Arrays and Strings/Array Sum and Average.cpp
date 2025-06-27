#include <iostream>
using namespace std;

int main()
{
    int num, sum = 0, i;
    float avg;

    cout << "enter any 5 number : ";
    for (i = 0; i < 5; i++)
    {
        cin >> num;
        sum += num;
    }
    avg = sum / 5;

    cout<<"sum is : "<<sum<<endl;
    cout<<"avg is : "<<avg;
}