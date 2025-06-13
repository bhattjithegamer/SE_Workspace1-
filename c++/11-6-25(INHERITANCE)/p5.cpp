#include<iostream>
using namespace std;

class parent
{
public:
int a=1,b=2,c=3,d=4;
};

class child1 : public parent
{
public:

void display()
{
cout<<"your a is : "<<a;
cout<<"your b is : "<<b;
}

};

class child2 : public parent
{
public:
void display(){
cout<<"your c is : "<<c;
cout<<"your d is : "<<d;
}
};

int main()
{
    child1 c1 = child1();
    c1.display();

    child2 c2 = child2();
    c2.display();

}