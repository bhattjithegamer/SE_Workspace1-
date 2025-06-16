#include <stdio.h>

int main()
{
    int marks;

    printf("Enter student's marks (out of 100): ");
    scanf("%d", &marks);

    switch (marks / 10)
    {
    case 10:
    case 9:
        printf("Grade A\n");
        break;
    case 8:
    case 7:
        printf("Grade B\n");
        break;
    case 6:
    case 5:
        printf("Grade C\n");
        break;
    default:
        printf("Grade D\n");
    }

    return 0;
}
