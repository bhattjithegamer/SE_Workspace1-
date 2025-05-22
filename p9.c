#include<stdio.h>
#include<conio.h>

int main()
{
    int a,b;
    int c = 0;
    
    printf("enter any number");
    scanf("%d",&a);
    
    while(a>0)
    {
        b = a%10;
        
        if(b>c)
        {
            c = b;
        }
     a=a/10;   
    }
    
    printf("this is max %d",c);
    
    return 0;
    
}