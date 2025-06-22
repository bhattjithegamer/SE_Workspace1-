#include <stdio.h>
#include <math.h>

int main()
{
    int number, original, remainder, sum = 0, n = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    original = number;

    while (original != 0)
    {
        original /= 10;
        n++;
    }

    original = number;

     while (original != 0)
    {
        remainder = original % 10;
        sum += pow(remainder, n);
        original /= 10;
    }

    if (sum == number)
    {
        printf("%d is an Armstrong number.\n", number);
    }
    else
    {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}