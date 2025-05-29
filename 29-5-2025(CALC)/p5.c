#include <stdio.h>

int helo(int a, int b)
{
    int c = a + b;

    return c;
}

int main()
{

    printf("\n %d", helo(5, 5));
    printf("\n %d", helo(10, 10));
    return 0;
}