#include<stdio.h>
#include<conio.h>
void main()
{

    int a,b;
    int add,sub,mul,div,mod;

    printf("Enter Value for a: ");
    scanf("%d",&a);

    
    printf("Enter Value for b: ");
    scanf("%d",&b);


    add = a+b;
    sub = a-b;
    mul = a*b;
    div = a/b;
    mod = a%b;

    printf("\n Addition is %d",add);
    printf("\n Substraction is %d",sub);
    printf("\n Multiplication is %d",mul);
    printf("\n Division is %d",div);
    printf("\n Modules is %d",mod);


    getch();
}