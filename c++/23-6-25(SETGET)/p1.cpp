#include<iostream>
using namespace std;

class parent
{
    public:
    int x,y;
    parent()
    {
         cout<<"this is default";
    }
    parent(int a , int b)
    {
        cout<<"parametrized constructor called";
        x = a;
        y = b;
    }
    parent(const parent &c)
    {
        x = c.x;
        y = c.y;
        
        cout<<"copy constructor called\n"<<endl;
        
    }
    void add()
    {
        cout << x << " "<< y <<"\n";
    }
};


int main()
{
    parent obj(20,30);
    parent obj2(obj);
    obj2.add();
}