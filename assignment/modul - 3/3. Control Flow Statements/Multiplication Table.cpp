#include<iostream>
using namespace std;

int main()
{
    int i,a;

    cout<<"enter number :";
    cin>>a;

    for ( i = 1; i <= 10; i++)
    {
      cout << a << "*" << i << "=" << a*i <<endl;
    }
    
}