#include <stdio.h>

int main()
{
    int number, i, Prime;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    Prime = 1;

    if (number <= 1)
    {
        Prime = 0;
    }
    else
    {
        for (i = 2; i <= number / 2; i++)
        {
            if (number % i == 0)
            {
                Prime = 0;
                break;
            }
        }
    }

    if (Prime)
        printf("%d is a prime number.\n", number);
    else
        printf("%d is not a prime number.\n", number);

    printf("Prime numbers between 1 and %d are:\n", number);
    for (int n = 2; n <= number; n++)
    {
        Prime = 1;
        for (i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                Prime = 0;
                break;
            }
        }
        if (Prime)
            printf("%d ", n);
    }

    printf("\n");
    return 0;
}
