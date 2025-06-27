#include <iostream>
using namespace std;

int q(int a, int b)
{
    int c = a + b;
    return c;
}

int r(int a, int b)
{
    int c = a - b;
    return c;
}

int s(int a, int b)
{
    int c = a * b;
    return c;
}

int t(int a, int b)
{
    int c = a / b;
    return c;
}

int u(int a, int b)
{
    int c = a % b;
    return c;
}
int main()
{
    int a, b, z;
    cout << "enter first : ";
    cin >> a;
    cout << "enter sec : ";
    cin >> b;

    z = q(a, b);
    cout << z << endl;
    z = r(a, b);
    cout << z << endl;
    z = s(a, b);
    cout << z << endl;
    z = t(a, b);
    cout << z << endl;
    z = u(a, b);
    cout << z << endl;
}