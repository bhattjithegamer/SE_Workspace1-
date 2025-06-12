#include <stdio.h>

char num[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char cancel[] = {};

void structure()
{
    printf("---TIC-TAC-TOE---");

    printf("\n  ________________\n");
    printf(" |  %c |  %c |  %c | \n", num[1], num[2], num[3]);
    printf(" |____|____|____| \n");
    printf(" |  %c |  %c |  %c | \n", num[4], num[5], num[6]);
    printf(" |____|____|____| \n");
    printf(" |  %c |  %c |  %c | \n", num[7], num[8], num[9]);
    printf(" |____|____|____| \n");
}

void player1()
{

    char symbole = 'X';
    int input;

    structure();

    printf("\n enter 1 to 9 only \n");
    scanf("%d", &input);

    if (input < 1 || input > 9)
    {
        printf("invelid choice  ");
    }

    num[input] = symbole;
}

void player2()
{

    char symbole = 'O';
    int input;

    structure();

    printf("\n enter 1 to 9 only \n");
    scanf("%d", &input);

    if (input < 1 || input > 9)
    {
        printf("invelid choice  ");
    }

    num[input] = symbole;
}

char winner()
{
    if (num[1] != ' ' && num[1] == num[2] && num[2] == num[3])
        return num[1];
    if (num[4] != ' ' && num[4] == num[5] && num[5] == num[6])
        return num[4];
    if (num[7] != ' ' && num[7] == num[8] && num[8] == num[9])
        return num[7];

    if (num[1] != ' ' && num[1] == num[4] && num[4] == num[7])
        return num[1];
    if (num[2] != ' ' && num[2] == num[5] && num[5] == num[8])
        return num[2];
    if (num[3] != ' ' && num[3] == num[6] && num[6] == num[9])
        return num[3];

    if (num[1] != ' ' && num[1] == num[5] && num[5] == num[9])
        return num[1];
    if (num[3] != ' ' && num[3] == num[5] && num[5] == num[7])
        return num[3];
}

int main()
{

    int player = 1, i, j;

    char name[50];

    printf("enter your name : ");
    scanf("%s", &name);

    printf("enter your name : ");
    scanf("%s", &name);

    printf("player 1 name is : %s");
    printf("player 2 name is : %s");

    printf("\n what is your choice \n 1 - X \n 2 - O \n");
    scanf("%d", &player);

    if (player == 1)
    {
        int i;

        printf("\n player 1 choice is X ");
        printf("\n player 2 choice is O ");

        player1();
        for (i = 1; i <= 4; i++)
        {
            player2();
            player1();

            char win = winner();

            if (win != '\0')
            {
                printf("u won %c", win);
                break;
            }
        }
    }

    if (player == 2)
    {
        int i;
        printf("\n player 1 choice is O ");
        printf("\n player 2 choice is X ");
        player2();

        for (i = 1; i <= 4; i++)
        {
            player1();
            player2();

            char win = winner();

            if (win != '\0')
            {
                printf("u won %c", win);
            }
        }
    }

    else
    {
        printf("invelid");
    }

    structure();

    return 0;
}