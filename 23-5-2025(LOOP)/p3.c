#include<stdio.h>
#include<conio.h>

int main()
{
    int num1=0,num2=1,next=0,num;
    
    printf("how many num u want");
    scanf("%d",&num);
    
    while(num > 0)
    
    {
        printf("%d,",next);
        next = num1+num2;
        num1=num2;
        num2=next;
        num--;
        
        
    }
    
    return 0;
    
}