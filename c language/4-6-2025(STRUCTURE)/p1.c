#include<stdio.h>

struct a8
{
   char name[50];
   char surname[50];
}a;



int main(){
    
    printf("enter ur name  : ");
    scanf("%s",a.name);

    printf("enter ur name  : ");
    scanf("%s",a.surname);


    printf("your name is  : %s", a.name);
    printf("your surname is  : %s", a.surname);

    return 0;
}