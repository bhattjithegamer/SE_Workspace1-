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

    student s1 = student(12,34);
    student s2 = student(132,364);
    student s3 = student(129,3874);

    s1.display();
    s2.display();
    s3.display();

}