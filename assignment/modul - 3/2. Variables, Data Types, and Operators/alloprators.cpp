#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cout << "enter first :";
    cin >> a;
    cout << "enter sec :";
    cin >> b;

    c = a + b;
    cout << "your dem ans is :" << c << endl;
    c = a - b;
    cout << "your dem ans is :" << c << endl;
    c = a * b;
    cout << "your dem ans is :" << c << endl;
    c = a / b;
    cout << "your dem ans is :" << c << endl;
    c = a % b;
    cout << "your dem ans is :" << c;

    c = a > b;
    cout << "your dem ans is :" << c << endl;
    c = a < b;
    cout << "your dem ans is :" << c << endl;
    c = a <= b;
    cout << "your dem ans is :" << c << endl;
    c = a >= b;
    cout << "your dem ans is :" << c << endl;
    c = a != b;
     cout << "your dem ans is :" << c << endl;
    c = a == b;
     cout << "your dem ans is :" << c << endl;

    c = a && b;
    cout << "your dem ans is :" << c << endl;
    c = a || b;
    cout << "your dem ans is :" << c << endl;
    c = a != b;
    cout << "your dem ans is :" << c << endl;

    c = a & b;
    cout << "your dem ans is :" << c << endl;
    c = ~a;
    cout << "your dem ans is :" << c << endl;
    c = a ^ b;
    cout << "your dem ans is :" << c << endl;

    return 0;
}