#include<iostream>
using namespace std;

class student
{
    public:
    int age , rollno;

    student(int age, int rollno)
    {
        this->age=age;
        this->rollno=rollno;
    }

    void display()
    {
        cout<<"\n age is : "<<age;
        cout<<"\n rollno is : "<<rollno;
    }
};

int main(){

    int age , rollno;
    cout<<"enter your age : ";
    cin>>age;

    cout<<"enter rollno";
    cin>>rollno;

    student s1 = student(age,rollno);
    

    s1.display();
    

}