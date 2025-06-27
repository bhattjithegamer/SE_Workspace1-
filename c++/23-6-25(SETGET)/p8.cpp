#include <iostream>
using namespace std;

class circle
{
private:
    int age;

public:
    void setage(int a)
    {
        age = a;
    }

    int getage()
    {
        return age;
    }
};

int main()
{
    circle c = circle();
    c.setage(50);
     cout<< c.getage();
}