#include <stdio.h>
#include <time.h>

long long factorial_recursive(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

long long factorial_iterative(int n)
{
    long long fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int num;
    clock_t start, end;
    double time_recursive, time_iterative;

    printf("Enter a number: ");
    scanf("%d", &num);

    start = clock();
    long long fact_rec = factorial_recursive(num);
    end = clock();
    time_recursive = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    long long fact_itr = factorial_iterative(num);
    end = clock();
    time_iterative = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nRecursive Factorial of %d = %lld\n", num, fact_rec);
    printf("Time taken (recursive): %f seconds\n", time_recursive);

    printf("\nIterative Factorial of %d = %lld\n", num, fact_itr);
    printf("Time taken (iterative): %f seconds\n", time_iterative);

    return 0;
}
