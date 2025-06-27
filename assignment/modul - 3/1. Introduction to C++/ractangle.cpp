#include <iostream>
using namespace std;

class ractengle
{
public:
    int a, b, c;

    int display()
    {
        cout << "enter len :";
        cin >> a;

        cout << "enter wid :";
        cin >> b;

        c = a * b;

        cout << c;
        return 0;
    }
};

int main()
{
    ractengle r1 = ractengle();
    r1.display();

    return 0;
}