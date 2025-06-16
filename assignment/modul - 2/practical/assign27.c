#include <stdio.h>

int main()
{
    int A[3][3], B[3][3], sum[3][3], product[3][3];
    int i, j, k;

    printf("Enter elements of 3x3 Matrix A:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of 3x3 Matrix B:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            product[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                product[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nSum of 3x3 matrices:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    printf("\nProduct of 3x3 matrices:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}
