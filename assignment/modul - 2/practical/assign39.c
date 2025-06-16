#include <stdio.h>

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * fact(n - 1);
}

int binomial(int n, int k)
{
    return fact(n) / (fact(k) * fact(n - k));
}

void printRow(int row, int col)
{
    if (col > row)
        return;
    printf("%4d", binomial(row, col));
    printRow(row, col + 1);
}

void printPascal(int current, int total)
{
    if (current == total)
        return;

    for (int space = 0; space < total - current - 1; space++)
        printf("  ");

    printRow(current, 0);
    printf("\n");

    printPascal(current + 1, total);
}

int main()
{
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    printPascal(0, n);

    return 0;
}
