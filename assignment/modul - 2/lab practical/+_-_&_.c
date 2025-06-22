#include <stdio.h>

int main()
{
    int a, b;

    printf("Enter first number (a): ");
    scanf("%d", &a);

    printf("Enter second number (b): ");
    scanf("%d", &b);

    printf("\n--- Arithmetic Operations ---\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    if (b != 0)
    {
        printf("a / b = %d\n", a / b);
        printf("a %% b = %d\n", a % b);
    }
    else
    {
        printf("Division and modulo by zero not allowed!\n");
    }

    printf("\n--- Relational Operations ---\n");
    printf("a > b  = %d\n", a > b);
    printf("a < b  = %d\n", a < b);
    printf("a >= b = %d\n", a >= b);
    printf("a <= b = %d\n", a <= b);
    printf("a == b = %d\n", a == b);
    printf("a != b = %d\n", a != b);

    printf("\n--- Logical Operations ---\n");
    printf("(a != 0) && (b != 0) = %d\n", (a != 0) && (b != 0));
    printf("(a != 0) || (b != 0) = %d\n", (a != 0) || (b != 0));
    printf("!(a == b) = %d\n", !(a == b));

    return 0;
}
