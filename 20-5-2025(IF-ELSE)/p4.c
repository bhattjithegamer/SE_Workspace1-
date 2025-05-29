#include<stdio.h>
#include<conio.h>

void main()
{
    
    int age;
    
    printf("enter your age");
    scanf("%d",&age);
    
    if(age>=101)
    {
        printf("enter velid");
    }
    
    else if(age>=18)
    {
        printf("u can vot");
        
        if(age>=60)
        {
            printf(" u r senior");
        }
        
        else
        {
            printf(" young human");
        }
    }
    
    else{
        printf("u can't vot");
    }
}