#include<iostream>
using namespace std;

class a5
{

    public:
   int a1(int a , int b)
    {
        return a + b;
    }
};
class a6
{    
    public:
    int a1(int a,int b)
    {
         return a * b;
    }
};

int main()
{
    a5 a1;
    a6 a2;

    cout<<a1.a1(3,4)<<endl;
    cout<<a2.a1(5,6);
}
