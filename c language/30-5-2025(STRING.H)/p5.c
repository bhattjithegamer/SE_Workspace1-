#include<stdio.h>

int main(){
    char a [50];

    printf("enter alpha");
    scanf("%s",&a);
    printf("%s",strupr(a));
    return 0;
}