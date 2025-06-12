#include<iostream>
using namespace std;

int main()
{
    int a,b,c;

   
   

    cout<<"enter num :";
    cin>>a;

    cout<<"enter sec :";
    cin>>b;

    c = a;
    a = b;
    b = c;

    cout<<"you have entered : "<<a<<endl;
    cout<<"you have entered  :"<<b<<endl;
}