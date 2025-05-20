#include<stdio.h>
#include<conio.h>
void main()
{
    int num;

    printf("Enter Number");
    scanf("%d",&num);

    if(num>0)
    {
        printf("Number is Positive");
    }
    else
    {
        printf("Number is Negative");
    }

    getch();
}