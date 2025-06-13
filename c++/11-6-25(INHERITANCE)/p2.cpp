#include <iostream>
using namespace std;

class parent
{
public:
    int a = 50, b = 100,c;
};

class child : public parent
{
    public:
    void display()
    {
    cout<<"\n a is"<<a;
    cout<<"\n b is"<<b;

    c = a;
    a = b;
    b = c;

    cout<<"\n now a is :"<<a;
    cout<<"\n now b is :"<<b;
    }
};

int main()
{
    child c1 = child();
    c1.display();

    
}