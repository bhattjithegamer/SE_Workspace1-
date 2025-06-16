#include <stdio.h>
#include<stdlib.h>
int shubham()
{
    int user, quantity, amount;
   
   
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
        amount = quantity * 180;

        printf("amount is  : %d \n ", amount);
        printf("total amount is : %d", amount);
    }

    if (user == 2)
    {
        printf("u have selected Burger \n");
        printf("enter quantity : ");
        scanf("%d", &quantity);
        amount = quantity * 100;

        printf("amount is  : %d \n", amount);
        printf("total amount is : %d", amount);
    }

    if (user == 3)
    {
        printf("u have selected Dosa \n");
        printf("enter quantity : ");
        scanf("%d", &quantity);
        amount = quantity * 120;

        printf("amount is  : %d \n", amount);
        printf("total amount is : %d", amount);
    }

    if (user == 4)
    {
        printf("u have selected idli \n");
        printf("enter quantity : ");
        scanf("%d", &quantity);
        amount = quantity * 50;

        printf("amount is  : %d \n", amount);
        printf("total amount is : %d", amount);
    }
 printf("u want to purchase ? Y , N" );
    
}
int main()
{
     char N, Y;
     int user;
   
    printf("u want to purchase ? Y , N" );

    if (user == Y)
    {
       shubham();
    }

    else
    {
        exit (0);    
    }

    return 0;
}