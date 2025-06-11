#include<stdio.h>
#include<conio.h>
void main()
{
    int num;

    printf("Enter Number: ");
    scanf("%d",&num);

    if(num%2==0)
    {
        printf("Number is EVEN");
    }
    else
    {
        printf("Number is ODD");
    }

    getch();
}