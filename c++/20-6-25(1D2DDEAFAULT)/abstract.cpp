#include <iostream>
using namespace std;

class a
{
    public:
    virtual void add() = 0;
};

class b : public a
{
    public:
    int rollno;

    void add()
    {
        cout << "enter your roll no. : ";
        cin >> rollno;
        cout<<"roll no is : "<<rollno;
    }
};

class c : public a
{
    public:
    string name;
    void add()
    {
        cout << "enter ur name : ";
        cin >> name;

        cout<<"your name is : "<<name;
    }
};

int main()
{
    b b1;
    c c1;

    b1.add();
    c1.add();

    return 0;
}