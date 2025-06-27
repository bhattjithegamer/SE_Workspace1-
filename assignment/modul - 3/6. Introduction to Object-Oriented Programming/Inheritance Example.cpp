#include <iostream>
using namespace std;

class person
{
public:
    string name;
    int age;
};
class teacher : public person
{
    public:
    string address;
    int salery;

    int display()
    {
        cout << "enter name : ";
        cin >> name;
        cout << "enter age : ";
        cin >> age;
        cout << "enter address : ";
        cin >> address;
        cout << "enter salery : ";
        cin >> salery;
    }
};

class student : public person
{
    public:
    string name1;
    int rollno;

    int display()
    {
        
        cout << "enter name of student : ";
        cin >> name1;
        cout << "enter name : ";
        cin >> rollno;
    }
};

int main()
{
    teacher t = teacher();
    student s = student();

    t.display();
    s.display();
}