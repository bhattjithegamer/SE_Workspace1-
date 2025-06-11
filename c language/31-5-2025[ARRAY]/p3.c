#include<stdio.h>

int main(){
    int marks[50],i;

    for ( i = 0; i <= 5; i++)
    {
        printf("\n your marks ");
        scanf("\n %d",&marks[i]);
    }

for ( i = 0; i <= 5; i++)
{
   printf("\n %d ur marks is ",marks[i]);
}

    
    return 0;
}