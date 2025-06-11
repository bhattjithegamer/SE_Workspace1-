#include<stdio.h>

void interchange (int a , int b)
{
int c;

c = a;
a = b;
b = c;

printf("a = %d , b = %d",a,b);
}
int main(){
    
 int   a = 100 , b = 200;

 printf("a = %d , b =%d",a,b);
 interchange(a,b);
 printf("a = %d , b =%d",a,b);
    return 0;
}