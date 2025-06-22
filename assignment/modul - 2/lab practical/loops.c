#include <stdio.h>

int main()
{
    int i;

    printf("Numbers from 1 to 10 using while loop:\n");
    i = 1;
    while (i <= 10)
    {
        printf("%d ", i);
        i++;
    }

    printf("\n\n");

    printf("Numbers from 1 to 10 using for loop:\n");
    for (i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }

    printf("\n\n");

    printf("Numbers from 1 to 10 using do-while loop:\n");
    i = 1;
    do
    {
        printf("%d ", i);
        i++;
    } while (i <= 10);

    printf("\n");

    return 0;
}
