#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int N, i;
    printf("Enter the number of terms (N): ");
    scanf("%d", &N);

    printf("Fibonacci sequence up to %d terms:\n", N);
    for (i = 0; i < N; i++)
    {
        printf("%d ", fibonacci(i));
    }

    return 0;
}
