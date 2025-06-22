#include <stdio.h>

int main()
{
    int a, i;
    float sum = 0, avg;

    printf("Enter the number of elements (N): ");
    scanf("%d", &a);

    int arr[a];

        printf("Enter %d numbers:\n", a);
    for (i = 0; i < a; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    avg = sum / a;

    printf("\nSum of array elements = %.2f\n", sum);
    printf("Average = %.2f\n", avg);

    return 0;
}
