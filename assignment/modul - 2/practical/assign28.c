#include <stdio.h>

int main()
{
    int N, i;
    float sum = 0, average;

    printf("Enter how many numbers you want (N): ");
    scanf("%d", &N);

    int arr[N];

    printf("Enter %d numbers:\n", N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = sum / N;

    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f\n", average);

    return 0;
}
