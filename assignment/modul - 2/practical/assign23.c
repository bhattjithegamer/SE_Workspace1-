#include <stdio.h>

int main()
{
    int num, start, end, i;

    printf("Enter a number for multiplication table: ");
    scanf("%d", &num);

    printf("Enter start of the range: ");
    scanf("%d", &start);

    printf("Enter end of the range: ");
    scanf("%d", &end);

    printf("\nMultiplication Table of %d from %d to %d:\n", num, start, end);

    for (i = start; i <= end; i++)
    {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}
