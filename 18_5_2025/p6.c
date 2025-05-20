#include<stdio.h>
#include<conio.h>
void main()
{
   
    int num1,num2,add,sub,mul,div1;
    
    printf("\n Enter Number1");
    scanf("%d",&num1);
    
    printf("\n Enter Number2");
    scanf("%d",&num2);
   
   
    add = num1+num2;
    sub = num1-num2;
    mul = num1*num2;
    div1 = num1/num2;
    
    printf("\n Addition is %d",add);
    printf("\n Substraction is %d",sub);
    printf("\n Multiplication is %d",mul);
    printf("\n Division is %d",div1);
   
    
    getch();
   
}