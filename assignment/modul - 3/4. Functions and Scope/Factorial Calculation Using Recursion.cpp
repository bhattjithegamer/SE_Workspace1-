#include <iostream>
using namespace std;

int fun(int a)
{
    if (a == 0 || a == 1)

        return 1;

    else
        return a * fun(a - 1);
}

int main()
{
    int num;
    cout << "enter number : ";
    cin >> num;

    cout <<fun(num)<<endl;
}