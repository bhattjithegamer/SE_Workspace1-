#include <iostream>
using namespace std;

class parent
{
public:
    int a = 5, b = 10;
};

class subparent1 : public parent
{
public:
    int c = 15;
};

class subparent2 : public parent
{
public:
    int d = 20;

    void display()
    {
        cout << "\n your a is" << a;
        cout << "\n your b is" << b;
    }
};

class child : public subparent1, subparent2
{
public:
    void display()
    {
        cout << "\n your c is" << c;
        cout << "\n your d is" << d;
    }
};
int main()
{
    subparent2 s2 = subparent2();
    s2.display();

    child c1 = child();
    c1.display();
}