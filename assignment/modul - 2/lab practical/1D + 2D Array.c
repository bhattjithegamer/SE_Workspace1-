#include <stdio.h>

int main()
{
    int arr1D[5];
    int i;

    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr1D[i]);
    }

    printf("\nYou entered (1D array): ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr1D[i]);
    }

    int matrix[3][3];
    int j, sum = 0;

    printf("\n\nEnter elements for 3x3 matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
            sum += matrix[i][j];
        }
    }

    printf("\nMatrix is:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of all elements in 3x3 matrix = %d\n", sum);

    return 0;
}
