#include<stdio.h>
#include<conio.h>

void main()
{
    int a;
    
    printf("enter your marks");
    scanf("%d",&a);
    
    if(a>=35)
    {
        printf("u r pass");
        
    }
    
    else
    {
        printf("try again");
    }
    getch();
}