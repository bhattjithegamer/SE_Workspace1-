#include <stdio.h>

int main()
{
    int a, b, c, largestCase, smallestCase;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        largestCase = 1;
    else if (b >= a && b >= c)
        largestCase = 2;
    else
        largestCase = 3;

    if (a <= b && a <= c)
        smallestCase = 1;
    else if (b <= a && b <= c)
        smallestCase = 2;
    else
        smallestCase = 3;

    switch (largestCase)
    {
    case 1:
        printf("Largest number is: %d\n", a);
        break;
    case 2:
        printf("Largest number is: %d\n", b);
        break;
    case 3:
        printf("Largest number is: %d\n", c);
        break;
    }

    switch (smallestCase)
    {
    case 1:
        printf("Smallest number is: %d\n", a);
        break;
    case 2:
        printf("Smallest number is: %d\n", b);
        break;
    case 3:
        printf("Smallest number is: %d\n", c);
        break;
    }

    return 0;
}
