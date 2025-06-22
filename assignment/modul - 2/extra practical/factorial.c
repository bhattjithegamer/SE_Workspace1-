#include <stdio.h>

unsigned long long factorial_recursive(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

unsigned long long factorial_iterative(int n)
{
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int number;

    printf("Enter a number to calculate factorial: ");
    scanf("%d", &number);

    printf("Factorial (Recursive) = %llu\n", factorial_recursive(number));
    printf("Factorial (Iterative) = %llu\n", factorial_iterative(number));

    return 0;
}
