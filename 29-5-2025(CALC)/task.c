#include <stdio.h>
#include <math.h>
#include<stdlib.h>

int main()
{

    while (1)
    {
        
    
    
    int a;

    printf("\n select operation for following ");

    printf("\n 1.addition \t\t 2.subtraction \n 3.multiplication \t 4.divison \n 5.modulation \t\t 6.squre \n 7.sqrt \t\t 8.exit \n select 1 to 8 :  ");
    scanf("%d", &a);

   if (a == 1)								
        {
            int n, i, number, sum = 0;

            printf("\n enter number u want");
            scanf("%d", &n);

            for (i = 1; i <= n; i++)
            {
                printf("\n enter num : ");
                scanf("%d", &number);
                sum += number;
            }
               
            
             printf("sum of your numbers %d \n : ", sum);
        }

    else if (a == 2)
    {
        int a, b, c;
        printf("enter num 1 : ");
        scanf("%d", &a);

        printf("enter num 2 : ");
        scanf("%d", &b);
        c = a - b;
        printf("sub of two value : %d", c);
    }

    else if (a == 3)
    {
        int a, b, c;

        printf("enter num 1 : ");
        scanf("%d", &a);

        printf("enter num 2 : ");
        scanf("%d", &b);
        c = a * b;
        printf("mul of two value : %d", c);
    }

    else if (a == 4)
    {
        int a, b, c;
        printf("enter num 1 : ");
        scanf("%d", &a);

        printf("enter num 2 : ");
        scanf("%d", &b);

        c = a / b;
        printf("div of two value : %d", c);
    }

    else if (a == 5)
    {
        int a, b, c;
        printf("enter num 1 : ");
        scanf("%d", &a);

        printf("enter num 2 : ");
        scanf("%d", &b);
        c = a % b;
        printf("mod of two value :%d ", c);
    }

    else if (a == 6)
    {
        int a, b;
        printf("enter num 1 : ");
        scanf("%d", &a);

        b = a * a;
        printf("mod of two value : %d", b);
    }

    else if (a == 7)
    {
        int a;
        printf("enter num 1 : ");
        scanf("%d", &a);

        printf("\n %f", sqrt(a));
    }

    else if (a == 8)
    {
        
       
            
            exit(0);
        
    }
    }
    return 0;
}