#include <stdio.h>
#include <conio.h>

int main() {
    printf("This is the program to implement sparse matrix\n");

    //printf("\nEnter the number of rows and columns with a space between them: ");
    //scanf("%d %d", &m, &n);
    int matrix[5][6] =
    {
        { 0, 0, 0, 0, 9, 0 },
        { 0, 8, 0, 0, 0, 0 },
        { 4, 0, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 5 },
        { 0, 0, 2, 0, 0, 0 }
    };
    int m = 5, n = 6;
    int sparse[3][n];
    int c=0;
    /*printf("\nEnter the matrix Elements:\n");
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                sparse[0][c]=i;
                sparse[1][c]=j;
                sparse[2][c]=matrix[i][j];
                c++;
            }
        }
    }*/
    printf("\nOriginal Matrix:\n");
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Sparse Matrix:\n");
    for (int i=0; i<3; i++) {
        for (int j=0; j<c; j++) {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }
    int sp=0;
    printf("\nPrinting matrix using sparse matrix:\n");
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (sparse[0][sp]==i && sparse[1][sp]==j) {
                printf("%d ", sparse[2][sp]);

                sp++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
    getch();
    return 0;
}