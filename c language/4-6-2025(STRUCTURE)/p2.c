#include<stdio.h>
struct a9
{
   char name[50] ;
   char surname[50];
   int rollnum;
}a[50];

int main(){
 
    int user,i;

    printf("enter how many u want : ");
    scanf("%d",&user);

    for ( i = 0; i < user; i++)
    {
       printf("enter name : ");
       scanf("%s",&a[i].name);

        printf("enter surname : ");
       scanf("%s",&a[i].surname);

        printf("enter roll : ");
       scanf("%d",&a[i].rollnum);
    }
    
    for ( i = 0; i < user; i++)
    {
       printf("name is :%s",a[i].name);
       printf("surename is :%s",a[i].surname);
       printf("rollnum is :%d",a[i].rollnum);

    }
    
    return 0;
}