#include <stdio.h>

int main()
{
    int mark;

    printf("Enter the student's marks (0-100): ");
    scanf("%d", &mark);

    if (mark < 0 || mark > 100)
    {
        printf("Invalid marks! Please enter a value between 0 and 100.\n");
    }
    else
    {
        if (mark > 90)
        {
            printf("Grade: A\n");
        }
        else if (mark > 75)
        {
            printf("Grade: B\n");
        }
        else if (mark > 50)
        {
            printf("Grade: C\n");
        }
        else
        {
            printf("Grade: D\n");
        }
    }

    return 0;
}
