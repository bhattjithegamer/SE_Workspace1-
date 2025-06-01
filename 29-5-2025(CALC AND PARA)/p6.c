#include <stdio.h>

void shubham(int a, int b)
{
    int c = a + b;
    printf("%d", c);
}

int main()
{

    int a;
    int b;

    printf("enter a: ");
    scanf("%d", &a);

    printf("enter b: ");
    scanf("%d", &b);

    shubham(a, b);

    return 0;
}
