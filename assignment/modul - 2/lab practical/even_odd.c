#include <stdio.h>

int main()
{
    int num, month;

    printf("Enter a number to check even or odd: ");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("The number %d is Even.\n", num);
    }
    else
    {
        printf("The number %d is Odd.\n", num);
    }

    printf("\nEnter month number (1-12): ");
    scanf("%d", &month);

    printf("Month Name: ");
    switch (month)
    {
    case 1:
        printf("January\n");
        break;
    case 2:
        printf("February\n");
        break;
    case 3:
        printf("March\n");
        break;
    case 4:
        printf("April\n");
        break;
    case 5:
        printf("May\n");
        break;
    case 6:
        printf("June\n");
        break;
    case 7:
        printf("July\n");
        break;
    case 8:
        printf("August\n");
        break;
    case 9:
        printf("September\n");
        break;
    case 10:
        printf("October\n");
        break;
    case 11:
        printf("November\n");
        break;
    case 12:
        printf("December\n");
        break;
    default:
        printf("Invalid month number!\n");
    }

    return 0;
}
