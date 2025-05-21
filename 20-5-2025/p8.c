#include<stdio.h>
#include<conio.h>

int main()
{
    int a;
    float b,c;
    
    printf("\n 1 number for +");
    printf("\n 2 number for -");
    printf("\n 3 number for *");
    printf("\n 4 number for / \n");
    scanf("%d",&a);
    
    printf("first number:");
    scanf("%f",&b);
    
    printf("second number:");
    scanf("%f",&c);
    
    switch(a)
    {
        case 1: printf("\n sum is %f", b + c);
        break;
        
        case 2: printf("\n sub is %f", b - c);
        break;
        
        case 3: printf("\n mul is %f", b * c);
        break;
        
        case 4: 
        
        if (c != 0)
           printf("\n div is %f", b / c);
             
        else
           printf("\n enter velid");
           break;
        
        default : 
           printf("\n enter velid number");
           break;
    }
    
    return 0;
    
}