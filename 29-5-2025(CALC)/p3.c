#include <stdio.h>

int main()
{

    int a = 5;
    int b;

    printf("\n value of a is :%d", a);
    a++;
    printf("\n value of a is: %d", a);

    ++a;
    printf("\n value of a is : %d", a);

    b = --a;
    printf("\n value of a is : %d", a);
    printf("\n value of b is : %d", b);

    b = a++;
    printf("\n value of a is : %d", a);
    printf("\n value of b is : %d", b);

    return 0;
}