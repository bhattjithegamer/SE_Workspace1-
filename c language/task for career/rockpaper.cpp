#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

class Player_move
{
public:
    char player[50];
    int round;
    int i, usermove, score = 0;
    

    int playerdata()
    {
        ofstream f1;
        f1.open("rockdata.txt");

        cout << "enter your name : ";
        cin.getline(player,50);

        cout << "how many round u want :   ";
        cin >> round;
        cin.ignore();

        f1<<"player is  : "<<player<<endl;
        // f1<<"rounds play : "<<round<<endl;
        f1.close();
       
        cout << "your name is : " << player << endl;
       
        return round;
    }

    void getusermove()
    {
        cout << "1 Rock" << endl;
        cout << "2 Paper" << endl;
        cout << "3 Sicssor" << endl;
        cout << "enter your move : ";
        cin >> usermove;
    }
};

class PcMove : public Player_move
{
public:
    int pcmove;

    void playgame()
    {
        srand(time(0));

        for (i = 1; i <= round; i++)
        {
            cout << "--round " << i << endl;
            getusermove();

            pcmove = (rand() % 3) + 1;

            cout << player << "move is :  " << getmovename(usermove) << endl;
            cout << "pc move is " << getmovename(pcmove) << endl;

            if (usermove == pcmove)
            {
                cout << "draw" << endl;
            }
            else if ((usermove == 1 && pcmove == 3) || (usermove == 2 && pcmove == 1) || (usermove == 3 && pcmove == 2))
            {
                score += 1;
                cout << "player score is : " << score << endl;
                cout << player << " won" << endl;
            }
            else
            {
                score += 1;
                cout << "pc score is : " << score << endl;
                cout << "pc won! " << endl;
            }
        }
    }

    string getmovename(int move)
    {
        if (move == 1)
        {
            return "rock";
        }

        else if (move == 2)
        {
            return "paper";
        }

        else if (move == 3)
        {
            return "scissor";
        }

        else
        {
            return "invalid ";
        }
    }
};

int main()
{
    PcMove p = PcMove();
    p.playerdata();
    p.playgame();
}