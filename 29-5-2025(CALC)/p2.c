#include <stdio.h>

int main()
{
    int a = 0, b = 5;

    if (a && b)
    {
        printf("hello");
    }

    if (!(a && b))
    {
        printf("hii");
    }

    return 0;
}