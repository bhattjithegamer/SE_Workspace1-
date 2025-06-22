#include <stdio.h>

int main()
{
    int num, i, j, prime;

    printf("Enter a number to print all primes up to it: ");
    scanf("%d", &num);

    printf("Prime numbers between 1 and %d are:\n", num);

    for (i = 2; i <= num; i++)
    {
        prime = 1;

        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                prime = 0;
                break;
            }
        }

        if (prime)
            printf("%d ", i);
    }

    printf("\n");
    return 0;
}
