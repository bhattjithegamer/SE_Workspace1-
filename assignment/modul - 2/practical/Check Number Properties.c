#include <stdio.h>

int main()
{
    int digit;

    printf("Enter an integer: ");
    scanf("%d", &digit);

    if (digit % 2 == 0)
    {
        printf("The digit is even.\n");
    }
    else
    {
        printf("The digit is odd.\n");
    }

    if (digit > 0)
    {
        printf("The digit is positive.\n");
    }
    else if (digit < 0)
    {
        printf("The digit is negative.\n");
    }
    else
    {
        printf("The digit is zero.\n");
    }

    if ((digit % 3 == 0) && (digit % 5 == 0))
    {
        printf("The digit is a multiple of both 3 and 5.\n");
    }
    else
    {
        printf("The digit is NOT a multiple of both 3 and 5.\n");
    }

    return 0;
}
