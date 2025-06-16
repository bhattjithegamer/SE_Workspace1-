#include <stdio.h>

int main()
{
    int i;

    printf("--- While Loop ---\n");
    i = 1;
    while (i <= 10)
    {
        printf("%d ", i);
        i++;
    }

    printf("\n\n--- For Loop ---\n");
    for (i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }

    printf("\n\n--- Do-While Loop ---\n");
    i = 1;
    do
    {
        printf("%d ", i);
        i++;
    } while (i <= 10);

    return 0;
}
