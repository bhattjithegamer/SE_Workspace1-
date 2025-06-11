#include<stdio.h>
#include<conio.h>

int main()
{
    int i,j;
   
    for(i=0;i<=5;i++)
    {
        for(j=0;j<=i;j++)
        {
            char a = 'A'+i;
            printf("%c",a);
        }
        printf("\n");
    }
}