#include <iostream>
using namespace std;

class student
{
public:
    int age = 20;
   static int rollno;

    

    void display()

    {
        rollno++;
        cout << "\n age is : " << age;
        cout << "\n rollno is : " <<rollno;
    }
};

int student :: rollno = 1;
int main()
{

    student s1 = student();
    student s2 = student();
    student s3 = student();

    s1.display();
    s2.display();
    s3.display();
}