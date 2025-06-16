#include <stdio.h>

int factorial(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int binomial(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main()
{
    int n;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        for (int space = 0; space < n - i - 1; space++)
            printf("  ");

        for (int j = 0; j <= i; j++)
            printf("%4d", binomial(i, j));
        printf("\n");
    }

    return 0;
}
