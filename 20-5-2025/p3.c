#include<stdio.h>
#include<conio.h>

void main()
{
    int a;
    
    printf("enter your marks");
    scanf("%d",&a);
    
     if(a>=101)
    {
        printf("enter velid marks");
    }
    
    
    else if(a>=100)
    {
        printf("u got A grade");
    }
    
    
    else if(a>=80)
    {
        printf("u got B grade");
    }
    
    else if(a>=60)
    {
        printf("u got C grade");
    }
    
    else
    {
        printf("try again my brother");
    }
}