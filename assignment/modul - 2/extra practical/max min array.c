#include <stdio.h>

int main()
{
    int arr[10], i, j, a;
    int max, min;

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    max = min = arr[0];

    for (i = 1; i < 10; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    printf("\nMaximum Value: %d\n", max);
    printf("Minimum Value: %d\n", min);

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                a = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = a;
            }
        }
    }

    // Print sorted array
    printf("\nArray in Ascending Order:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
