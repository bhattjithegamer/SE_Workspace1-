#include<stdio.h>

int main(){
    int a[5];

    a[0]=5;
    a[1]=6;
    a[2]=7;
    a[3]=8;
    a[4]=9;

    for ( int i = 0; i < 5; i++)
    {
       printf("\n %d",a[i]);
    }
    

    return 0;
}