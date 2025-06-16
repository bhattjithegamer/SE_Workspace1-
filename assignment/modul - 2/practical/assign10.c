#include <stdio.h>

int main()
{
    int num = 10;
    int *ptr;

    ptr = &num;

    printf("Original value of num: %d\n", num);
    printf("Address of num: %p\n", &num);
    printf("Pointer ptr holds: %p\n", ptr);
    printf("Value at ptr: %d\n", *ptr);

    *ptr = 20;

    printf("\nAfter modifying value using pointer:\n");
    printf("New value of num: %d\n", num);

    return 0;
}
