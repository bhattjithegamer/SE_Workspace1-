#include<iostream>
using namespace std;

class student 
{
    public:
    int a1,b1;

    public:
    int add(int a,int b)
    {
        return a + b;
    }

    public:
    int sub(int a,int b)
    {
        return a - b;
    }

    public:
    int mul(int a,int b)
    {
        return a * b;
    }

    public:
    int div1(int a,int b)
    {
        return a / b;
    }

    public:
    int mod(int a,int b)
    {
        return a % b;
    }


    void display()
    {
        cout<<"add is : "<<add(a1,b1)<<endl;
        cout<<"sub is : "<<sub(a1,b1)<<endl;
        cout<<"mul is : "<<mul(a1,b1)<<endl;
        cout<<"div is : "<<div1(a1,b1)<<endl;
        cout<<"mod is : "<<mod(a1,b1)<<endl;
    }
};

int main()
{
    int a,b;

    cout<<"enter first : ";
    cin>>a;

    cout<<"enter sec : ";
    cin>>b;

    student s1 = student();
    s1.a1 = a;
    s1.b1 = b;

    s1.display();


}