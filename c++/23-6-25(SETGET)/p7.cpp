#include<iostream>
using namespace std;

class parent
{
protected:
int a;
};

class child : public parent
{
    public:
    void setid(int id)
    {
        a = id;
    }

    int getid()
    {
        return a;
    }
};

int main()
{
    child c;
    c.setid(5);
    cout<<"id:"<<c.getid();
}