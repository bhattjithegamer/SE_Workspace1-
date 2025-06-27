#include <iostream>
using namespace std;

int main()
{
    int marks;

    cout << "enter marks of student : ";
    cin >> marks;

    if (marks > 100)
    {
        cout << "enter valid input";
    }

    else if (marks >= 80)
    {
        cout << "u r pass";

        if (marks >= 80)
        {
            cout << " your grade is A";
        }
    }

    else if (marks >= 60)
    {
        cout << "distiction";

        if (marks >= 60)
        {
            cout << " your grade is B";
        }
    }

    else if (marks >= 50)
    {
        cout << " need to study ";

        if (marks >= 50)
        {
            cout << " your grade is C";
        }
    }

    else
    {
        cout << "tray again ";
    }
}