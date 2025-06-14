#include<iostream>
using namespace std;

class student
{
public:
    int add(int a , int b)
    {
        return a + b;
    }
public:
    double add(double a , double b)
    {
         return a * b;
    }
};

int main()
{
    student s1 = student();
   cout<<s1.add(1,2);
     cout<<s1.add(3.0,4.0);
}