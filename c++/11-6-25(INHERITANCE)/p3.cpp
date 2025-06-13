#include<iostream>
using namespace std;

class gparent
{
    public:
int a = 1,b = 2;
};

class parent : public gparent
{
    public:
int c = 3,d = 4;
};

class child : public parent
{
    public:
    void display(){
cout<<"a is : "<<a;
cout<<"\n b is : "<<b;
cout<<"\n c is : "<<c;
cout<<"\n d is : "<<d;
    }
};

int main()
{
    child c1 = child();
    c1.display();

}