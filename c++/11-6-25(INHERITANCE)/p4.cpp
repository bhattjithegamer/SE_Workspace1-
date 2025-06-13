#include<iostream>
using namespace std;

class parent1{
public:

int a,b;

};

class parent2{

public:

int c,d;
};

class child : public parent1,parent2
{
public:

void display()
{
    cout<<"\n a is";
    cin>>a;
    cout<<"\n b is";
    cin>>b;
    cout<<"\n c is";
    cin>>c;
    cout<<"\n d is";
    cin>>d;

    cout<<"your a b c d is "<<a<<b<<c<<d;
}

};

int main()

{

    child c1 = child();
    c1.display(); 

}