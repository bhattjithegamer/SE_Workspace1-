#include <stdio.h>

int main()
{
    int a;

    printf(" 1.pizza \t\t price : 180 \n 2.burger \t\t price : 100 \n 3.dosa \t\t price : 120 \n 4.idli \t\t price : 50");

    printf("\n\n\t enter what u want");

    if (a == 1)
    {
        int quantity, b,total;
        
        printf("u selected pizaa");

        printf("enter quantity : ");
        scanf("%d ", &quantity);

        b = quantity * 180;
        printf("%d", &b);

       total = b ;

       printf("your total is : %d" , total);
        
    }

    return 0;
}