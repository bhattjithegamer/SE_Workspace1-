#include<stdio.h>

int main(){
    int num,selery[50];


    printf("enter number");
    scanf("%d",&num);

    for ( int i = 0; i < num; i++)
    {
        printf("\n  enter selery for emp : ");
        scanf("\n %d",&selery[i]);
    }

    for ( int i = 0; i < num; i++)
    {
        
        printf("selery is : %d",selery[i]);
    }
    
    
    return 0;
}