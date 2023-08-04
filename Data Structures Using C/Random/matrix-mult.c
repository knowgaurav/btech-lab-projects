#include <stdio.h>
#include <conio.h>

void multiplyMatrices(int A[10][10], int B[10][10], int C[10][10], int arows, int acolumns, int brows, int bcolumns)
{
    for (int i = 0; i < arows; i++)
        for (int j = 0; j < bcolumns; j++)
            C[i][j] = 0;

    int sum = 0;
    for (int i = 0; i < arows; i++)
    {
        for (int j = 0; j < bcolumns; j++)
        {
            for (int k = 0; k < brows; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
            sum = 0;
        }
    }
}

void printMatrix(int A[10][10], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[10][10], B[10][10], C[10][10];
    int arows, acolumns, brows, bcolumns;
    printf("Enter the rows and columns of 1st Matrix\n");
    scanf("%d %d", &arows, &acolumns);

    printf("\nEnter the elements of first matrix\n");
    for (int i = 0; i < arows; i++)
        for (int j = 0; j < acolumns; j++)
            scanf("%d", &A[i][j]);

    printf("\nEnter the rows and columns of 2nd Matrix\n");
    scanf("%d %d", &brows, &bcolumns);

    printf("\nEnter the elements of second matrix\n");
    for (int i = 0; i < brows; i++)
        for (int j = 0; j < bcolumns; j++)
            scanf("%d", &B[i][j]);

    if (bcolumns != arows)
    {
        printf("\nMatrix Multiplication cannot be performed\n");
    }
    else
    {
        printf("\nMultiplication can be done!\n");
        multiplyMatrices(A, B, C, arows, acolumns, brows, bcolumns);
        printf("Here's the result: \n");
        printMatrix(C, arows, bcolumns);
    }

    getch();
}
