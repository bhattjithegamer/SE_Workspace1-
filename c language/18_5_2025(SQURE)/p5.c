#include<stdio.h>
#include<conio.h>
void main()
{
   
    int num,square,cube;
    
    printf("Enter Number");
    scanf("%d",&num);
    
    square = num*num;
    cube = num*num*num;

    printf("\n Square is %d",square);
    printf("\n Cube is %d",cube);
    
    getch();
   
}