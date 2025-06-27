#include <iostream>
using namespace std;

int student(int *a, int *b);

int student(int *a, int *b)
{
    int temp;
    cout << "before : " << a <<endl;
    cout << "before : " << b <<endl;

    temp = *a;
    *a = *b;
    *b = temp;

    cout << "after : " << a <<endl;
    cout << "after : " << b <<endl;
}
int main()
{
    int a = 10, b = 20;

    cout << "before : " << a <<endl;
    cout << "before : " << b <<endl;

    student(&a,&b);

    cout << "after : " << a <<endl;
    cout << "after : " << b <<endl;
}
