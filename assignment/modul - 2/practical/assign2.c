#include <stdio.h>

int main()
{
    int a, b;

    printf("Enter first integer: ");
    scanf("%d", &a);

    printf("Enter second integer: ");
    scanf("%d", &b);

    printf("\n--- Arithmetic Operations ---\n");
    printf("Addition        (a + b) = %d\n", a + b);
    printf("Subtraction     (a - b) = %d\n", a - b);
    printf("Multiplication  (a * b) = %d\n", a * b);
    printf("Division        (a / b) = %d\n", b != 0 ? a / b : 0);
    printf("Modulus         (a %% b) = %d\n", b != 0 ? a % b : 0);

    printf("\n--- Relational Operations ---\n");
    printf("a == b : %d\n", a == b);
    printf("a != b : %d\n", a != b);
    printf("a > b  : %d\n", a > b);
    printf("a < b  : %d\n", a < b);
    printf("a >= b : %d\n", a >= b);
    printf("a <= b : %d\n", a <= b);

    printf("\n--- Logical Operations ---\n");
    printf("(a && b) : %d\n", a && b);
    printf("(a || b) : %d\n", a || b);
    printf("!a       : %d\n", !a);

    return 0;
}
