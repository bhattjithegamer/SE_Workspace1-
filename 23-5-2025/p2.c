#include<stdio.h>
#include<conio.h>

int main()
{
    int num,i;
    long int factorial = 1;
    
    printf("enter num : ");
    scanf("%d",&num);
    
    for (i=1;i<=num; i++)
    {
    factorial = factorial * i;
    
    }
    
    printf("%d : %ld ", num,factorial);
    
    return 0;
}