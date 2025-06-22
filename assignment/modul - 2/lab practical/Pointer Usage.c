#include <stdio.h>

int main()
{
    int num = 10;
    int *ptr;

    ptr = &num;

    printf("Original value of num: %d\n", num);
    printf("Address of num: %p\n", ptr);

    *ptr = 25;

    printf("Modified value of num using pointer: %d\n", num);

    return 0;
}
