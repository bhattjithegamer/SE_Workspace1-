#include <stdio.h>
#include <math.h>

int isArmstrong(int num)
{
    int original = num, sum = 0, digits = 0, temp;

    temp = num;
    while (temp > 0)
    {
        digits++;
        temp /= 10;
    }

    temp = num;
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }

    return (sum == original);
}

int main()
{
    int number;

    printf("Enter a number to check if it's an Armstrong number: ");
    scanf("%d", &number);

    if (isArmstrong(number))
        printf("%d is an Armstrong number.\n", number);
    else
        printf("%d is NOT an Armstrong number.\n", number);

    printf("\nArmstrong numbers between 1 and 1000 are:\n");
    for (int i = 1; i <= 1000; i++)
    {
        if (isArmstrong(i))
            printf("%d ", i);
    }

    return 0;
}
