#include<stdio.h>
#include<conio.h>

int main()
{
    int a , b , c;
    float pi = 3.14;
    float d = 0.5;
    
    printf("\n 1 for Triangle");
    printf("\n 2 for Rectangle ");
    printf("\n 3 for circle \n");
    scanf("%d",&a);
    
    printf("enter first number:  ");
    scanf("%d",&b);
    
    printf("enter second number: ");
    scanf("%d",&c);
    
    switch(a)
    {
       case 1: printf("ans of Triangle: %f", d * b * c);
       break;
       
       case 2: printf("ans of Rectangle: %d", b * c);
       break;
       
       case 3: printf("ans of circle: %f", pi * b * c);
       break;
       
       default: printf("write a velid num.");
    }
    
    return 0;
}