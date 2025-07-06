#include <iostream>
using namespace std;

class parent
{
public:
    int add()
    {
        cout << "give the money " << endl;
        return 0;
    }
};

class child : public parent
{
public:
    int add()
    {
        cout << "tack the money " << endl;
         return 0;
    }
};

int main()
{
    child c = child();
     c.parent::add();
    c.add();

   
}