#include <stdio.h>

int main()
{
    int mat1[3][3], mat2[3][3], result[3][3];
    int i, j, k, choice;

    printf("Matrix Operation Program\n");
    printf("1. Add two 2x2 matrices\n");
    printf("2. Add two 3x3 matrices\n");
    printf("3. Multiply two 3x3 matrices\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nEnter elements of first 2x2 matrix:\n");
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                printf("mat1[%d][%d]: ", i, j);
                scanf("%d", &mat1[i][j]);
            }
        }

        printf("\nEnter elements of second 2x2 matrix:\n");
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                printf("mat2[%d][%d]: ", i, j);
                scanf("%d", &mat2[i][j]);
            }
        }

        printf("\nResultant 2x2 Matrix after Addition:\n");
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                result[i][j] = mat1[i][j] + mat2[i][j];
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        break;

    case 2:
        printf("\nEnter elements of first 3x3 matrix:\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("mat1[%d][%d]: ", i, j);
                scanf("%d", &mat1[i][j]);
            }
        }

        printf("\nEnter elements of second 3x3 matrix:\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("mat2[%d][%d]: ", i, j);
                scanf("%d", &mat2[i][j]);
            }
        }

        printf("\nResultant 3x3 Matrix after Addition:\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                result[i][j] = mat1[i][j] + mat2[i][j];
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        break;

    case 3:
        printf("\nEnter elements of first 3x3 matrix:\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("mat1[%d][%d]: ", i, j);
                scanf("%d", &mat1[i][j]);
            }
        }

        printf("\nEnter elements of second 3x3 matrix:\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("mat2[%d][%d]: ", i, j);
                scanf("%d", &mat2[i][j]);
            }
        }

        printf("\nResultant 3x3 Matrix after Multiplication:\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                result[i][j] = 0;
                for (k = 0; k < 3; k++)
                {
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
        break;

    default:
        printf("Invalid Choice!\n");
    }

    return 0;
}
