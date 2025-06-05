#include<stdio.h>

int main(){
    int a[2][2] ,b[2][2],result[2][2];
    int i,j,k;
    
    printf("enter the first : ");
    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 2; j++)
        {
            scanf("\n %d",&a[i][j]);
        }
        
    }

     printf("enter the sec : ");
    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 2; j++)
        {
            scanf("%d",&b[i][j]);
        }
        
    }


    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 2; j++)
        {
           result[i][j] = 0;
           for ( k = 0; k < 2; k++)
           {
            result[i][j] += a[i][k] * b[k][j];
           }
           
        }
        
    }


    for ( i = 0; i < 2; i++)
    {
        for ( j = 0; j < 2; j++)
        {
            printf(" %d",result[i][j]);
        }
        printf("\n");
        
    }
    
    return 0;
}