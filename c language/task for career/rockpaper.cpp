#include <iostream>
using namespace std;

class Player_move
{
public:
    char player[50];
    int round;
    int i;

    int display()
    {
        cout << "enter your name : ";
        cin >> player;
        cout << "your name is : " << player << endl;

        cout << "how many round u want :   ";
        cin >> round;

        for (i = 1; i <= round; i++)
        {

            int usermove, pcmove;

            cout << "1 Rock" << endl;
            cout << "2 Paper" << endl;
            cout << "3 Sicssor" << endl;
            cout << "enter your move";
            cin >> usermove;
        }
    }
};

class PcMove : public Player_move
{
public:
    int usermove, pcmove;

    int display()
    {
        if (usermove == 1)
        {
            pcmove = 2;
        }

        else if (usermove == 2)
        {
            pcmove = 3;
        }

        else if (usermove == 3)
        {
            pcmove = 1;
        }

        else
        {
            cout << "invalid input ";
        }
    }
};

int main()
{
    Player_move p = Player_move();
    p.display();
}