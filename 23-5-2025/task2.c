#include<stdio.h>
#include<conio.h>

int main()
{
    int a;
    int b;
    
    printf("enter first ");
    scanf("%d",&a);
    
    printf("enter first ");
    scanf("%d",&b);
    
    
    a = a + b; //12+6=18 value of a
    b = a - b; //18-6=12 value of b
    a = a - b; //18-12=6
    
    printf("\n a is %d",a);
    printf("\n b is %d",b);
    
    return 0;
    
}