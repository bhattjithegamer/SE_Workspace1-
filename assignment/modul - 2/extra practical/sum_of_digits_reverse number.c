#include <stdio.h>

int main()
{
    int number, digit, sum = 0, reverse = 0, temp;

    printf("Enter an integer: ");
    scanf("%d", &number);

    temp = number;

    while (temp != 0)
    {
        digit = temp % 10;
        sum += digit;
        reverse = reverse * 10 + digit;
        temp /= 10;
    }

    printf("\nResults:\n");
    printf("Sum of digits of %d = %d\n", number, sum);
    printf("Reverse of %d = %d\n", number, reverse);

    return 0;
}
