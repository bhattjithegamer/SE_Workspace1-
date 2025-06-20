#include <stdio.h>
#include <stdlib.h>
int shubham()
{
    int user, quantity, rupiya;

    printf("1 Pizaa \t price = 180rs \n ");
    printf("2 Burger \t price = 100rs \n ");
    printf("3 Dosa \t price = 120rs \n");
    printf("4 Idli \t\t price = 50rs \n ");

    printf("enter what u want");
    scanf("%d", &user);

    if (user == 1)
    {
        printf("u have selected piza \n");
        printf("enter quantity : ");
        scanf("%d", &quantity);
        rupiya = quantity * 180;
        printf("rupiya is  : %d \n ", rupiya);
        printf("total rupiya is : %d", rupiya);
    }

    if (user == 2)
    {
        printf("u have selected Burger \n");
        printf("enter quantity : ");
        scanf("%d", &quantity);
        rupiya = quantity * 100;
        printf("rupiya is  : %d \n", rupiya);
        printf("total rupiya is : %d", rupiya);
    }

    if (user == 3)
    {
        printf("u have selected Dosa \n");
        printf("enter quantity : ");
        scanf("%d", &quantity);
        rupiya = quantity * 120;
        printf("rupiya is  : %d \n", rupiya);
        printf("total rupiya is : %d", rupiya);
    }

    if (user == 4)
    {
        printf("u have selected idli \n");
        printf("enter quantity : ");
        scanf("%d", &quantity);
        rupiya = quantity * 50;
        printf("rupiya is  : %d \n", rupiya);
        printf("total rupiya is : %d", rupiya);
        return 0;
    }
}
int main()
{
    char user;
    do
    {
        shubham();
        printf("\n u want to purchase ? Y , N");
        getchar();
        scanf("%c", &user);
    } while (user == 'Y' || user == 'y');

    printf("tnx for shopping! ");

    return 0;
}