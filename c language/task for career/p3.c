#include<stdio.h>

int main(){
    while (1)
    {
       
    
    int user,quantity,amount;
    char n,y;
    printf("1 Pizaa \t price = 180rs \n ");
    printf("2 Burger \t price = 100rs \n ");
    printf("3 Dosa \t price = 120rs \n");
    printf("4 Idli \t\t price = 50rs \n ");

    printf("enter what u want");
     scanf("%d",&user);

    if (user == 1)
    {
      printf("u have selected piza \n");
      printf("enter quantity : ");
      scanf("%d",&quantity);
      amount = quantity * 180;

      printf("amount is  : %d \n ",amount);
      printf("total amount is : %d",amount);

    }

    if (user == 2)
    {
      printf("u have selected Burger \n");
      printf("enter quantity : ");
      scanf("%d",&quantity);
      amount = quantity * 100;

      printf("amount is  : %d \n",amount);
      printf("total amount is : %d",amount);

    }


    if (user == 3)
    {
      printf("u have selected Dosa \n");
      printf("enter quantity : ");
      scanf("%d",&quantity);
      amount = quantity * 120;

      printf("amount is  : %d \n",amount);
      printf("total amount is : %d",amount);

    }


    if (user == 4)
    {
      printf("u have selected idli \n");
      printf("enter quantity : ");
      scanf("%d",&quantity);
      amount = quantity * 50;

      printf("amount is  : %d \n",amount);
      printf("total amount is : %d",amount);

    }
    
    }
    
    return 0;
}