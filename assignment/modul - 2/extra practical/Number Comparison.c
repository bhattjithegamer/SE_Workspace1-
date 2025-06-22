#include <stdio.h>

int main()
{
    int num1, num2, num3;
    int larg, small;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 >= num2 && num1 >= num3)
        larg = num1;
    else if (num2 >= num1 && num2 >= num3)
        larg = num2;
    else
        larg = num3;

    if (num1 <= num2 && num1 <= num3)
        small = num1;
    else if (num2 <= num1 && num2 <= num3)
        small = num2;
    else
        small = num3;

    printf("\nUsing If-Else:\n");
    printf("Largest Number: %d\n", larg);
    printf("Smallest Number: %d\n", small);

    return 0;
}
