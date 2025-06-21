#include<iostream>
using namespace std;

struct student
{
  string name ;
  int rollno ;
};

int main()
{
    struct student s;
   

cout<<"enter your name : "<<endl;
cin>>s.name;
cout<<"enter your rollno : ";
cin>>s.rollno;

cout<<"ur name is  : "<<s.name;
cout<<"ur rollno is : "<<s.rollno;

}