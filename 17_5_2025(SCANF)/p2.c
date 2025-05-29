#include<stdio.h>
#include<conio.h>

void main ()
{
    int p,r,n,i,ans;
    
    printf("enter principal :");
    scanf("%d",&p);
    
    printf("enter rate : ");
    scanf("%d",&r);
    
    printf("enter year : ");
    scanf("%d",&n);
    
    i = p*r*n/100;
    ans = i + p;
    
    printf("your i is %d",ans);
    

}