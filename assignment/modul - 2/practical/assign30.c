#include <stdio.h>

int fib_recursive(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_iterative(int n)
{
    int a = 0, b = 1, temp, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main()
{
    int n;
    printf("Enter the term number (n): ");
    scanf("%d", &n);

    printf("Fibonacci (Recursive) at position %d: %d\n", n, fib_recursive(n));

    printf("Fibonacci (Iterative) at position %d: %d\n", n, fib_iterative(n));

    return 0;
}
