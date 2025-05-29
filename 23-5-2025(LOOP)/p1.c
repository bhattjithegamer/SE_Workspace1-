#include<stdio.h>
#include<conio.h>

int main(){
    
   int a,b,c;
   
   printf("enter num  ");
   scanf("%d",&b);
   
   for(a=1;a<=10;a++)
   {
       c = b * a;
       
       printf("\n %d * %d = %d",b,a,c);
       
   }
    
}