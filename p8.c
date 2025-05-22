#include<stdio.h>
#include<conio.h>

int main() {
    int num, r=0;

printf("add some number:  ");
    scanf("%d", &num);

    while (num) {
        r = r * 10 + num % 10;
     // r = 0 * 10 + num % 10;
        num = num / 10; 
    }

    printf("%d", r);

    return 0;
}
