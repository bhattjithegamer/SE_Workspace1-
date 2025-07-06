#include <iostream>
using namespace std;

class parent
{
public:
    int display(int a, int b)
    {
      return a + b;
    }
};

class child : public parent
{
public:
    parent::display;
    int display(int a, int b)
    {
        
        return a * b;
    }
};

int main()
{
    child c ;
    cout << "first sum is : " << c.parent::display(5,5);
    cout << "sec sum is : " << c.display(5,5);
}