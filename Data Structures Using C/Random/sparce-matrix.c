#include <stdio.h>
#include <conio.h>

int main()
{
    int A[10][10], B[10][3], rows = 5, cols = 6, k = 0;
    printf("Enter the order of the matrix: \n");
    scanf("%d %d", &rows, &cols);
    printf("\nEnter the element of the matrix: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nThe element of the matrix are: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d", A[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (A[i][j] != 0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }

    printf("\nThe element of the sparse matrix are: \n");
    printf("i j value\n");
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d", B[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    int sp = 0;
    printf("\nPrinting matrix using sparse matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (B[sp][0] == i && B[sp][1] == j)
            {
                printf("%d ", B[sp][2]);

                sp++;
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    getch();
    return 0;
}