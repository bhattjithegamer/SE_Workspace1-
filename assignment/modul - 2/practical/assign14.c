#include <stdio.h>

int main()
{
    int num1, num2;
    char op;
    int result;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter operator (+, -, *, /, %%): ");
    scanf(" %c", &op);

    printf("Enter second number: ");
    scanf("%d", &num2);

    switch (op)
    {
    case '+':
        result = num1 + num2;
        printf("Result = %d\n", result);
        break;
    case '-':
        result = num1 - num2;
        printf("Result = %d\n", result);
        break;
    case '*':
        result = num1 * num2;
        printf("Result = %d\n", result);
        break;
    case '/':
        if (num2 != 0)
            printf("Result = %d\n", num1 / num2);
        else
            printf("Error: Cannot divide by zero!\n");
        break;
    case '%':
        if (num2 != 0)
            printf("Result = %d\n", num1 % num2);
        else
            printf("Error: Cannot take modulo by zero!\n");
        break;
    default:

        printf("Invalid operator! Please use +, -, *, /, or %%.\n");
    }

    return 0;
}
