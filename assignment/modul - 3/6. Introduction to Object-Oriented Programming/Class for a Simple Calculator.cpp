#include <iostream>
using namespace std;

class calculator
{
public:
    int display()
    {
        int user, num, i, sum = 0, a;
        cout << "enter what u want : 1 - add , 2 - sub , 3 - mul , 4 - div";
        cin >> user;

        if (user == 1)
        {
            cout << "u selected sum : " << endl;
            cout << "how many number u want : ";
            cin >> a;

            for (i = 0; i < a; i++)
            {
                cin >> num;
                sum += num;
            }
            cout << "sum is : " << sum;
        }

        else if (user == 2)
        {
            int z;
            cout << "u selected sub : " << endl;
            cout << "how many number u want : ";
            cin >> a;
            if (a > 0)
            {
                cin >> z;
                for (i = 1; i < a; i++)
                {
                    cin >> num;
                    z -= num;
                }
                cout << "sub is : " << z;
            }
        }

        else if (user == 3)
        {
            int x;
            cout << "u selected mul : " << endl;
            cout << "how many number u want : ";
            cin >> a;
            if (a > 0)
            {
                cin >> x;
                for (i = 1; i < a; i++)
                {
                    cin >> num;
                    x *= num;
                }
                cout << "mul is : " << x;
            }
        }

        else if (user == 4)
        {
            int y;
            cout << "u selected div : " << endl;
            cout << "how many number u want : ";
            cin >> a;
            if (a > 0)
            {
                cin >> y;
                for (i = 1; i < a; i++)
                {
                    cin >> num;
                    y /= num;
                }
                cout << "div is : " << y;
            }
        }
    }
};

int main()
{
    calculator c;
    c.display();

    return 0;
}