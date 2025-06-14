#include<iostream>
using namespace std;

class a5
{

public:

   int a1(int a , int b)
    {
        return a + b;
    }
public:
   int a1(int a,int b,int c)
    {
         return a * b * c;
    }
};

int main()
{
    a5 a = a5();

    cout<<a.a1(3,4)<<endl;
    cout<<a.a1(5,6,2);
}
