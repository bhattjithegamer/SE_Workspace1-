#include<stdio.h>
#include<conio.h>

int main()
{
    int a,b=0,c=0;
    
    printf("enter number");
    scanf("%d",&a);
    
    while(a>0)
    {
        c=a%10;
        b+=c;
        a=a/10;
    }
    
    printf("sum is %d",b);
    
    return 0;
}