#include<stdio.h>

int main(){
    
    int a,month = 12,total;

    printf("enter monthly selery : ");
    scanf("%d",&a);

    total = month * a;

    printf("\n %d",total);

    return 0;
}