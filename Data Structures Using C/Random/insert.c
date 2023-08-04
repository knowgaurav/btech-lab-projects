#include <stdio.h>
#include <conio.h>

void insertElement(int A[10], int n)
{
    int index, ele;
    printf("Enter the location at which you want to add a new element: ");
    scanf("%d", &index);
    if (index < 1 || index > n)
    {
        printf("Location not valid!");
    }
    else
    {
        printf("Enter the element to be added: ");
        scanf("%d", &ele);
        for (int i = n; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = ele;
    }

    printf("The array is after insertion is: ");
    for (int i = 1; i <= n + 1; i++)
    {
        printf("%d ", A[i]);
    }
}

void deleteElement(int A[10], int n)
{
    int index;
    printf("Enter the location of the element to be deleted: ");
    scanf("%d", &index);

    if (index < 1 || index > n)
    {
        printf("Invalid location!");
    }
    else
    {
        for (int i = index; i <= n; i++)
        {
            A[i] = A[i + 1];
        }
    }

    printf("The array is after deletion is: ");
    for (int i = 1; i <= n - 1; i++)
    {
        printf("%d ", A[i]);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int A[10];
    printf("Enter the elements of the array: ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("which operation do you want to perform?\nPress 1 for Insertion, Press 2 for deletion: ");
    int input;
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        insertElement(A, n);
        break;

    case 2:
        deleteElement(A, n);
        break;

    default:
        printf("\nError! Input is not correct.");
        break;
    }

    getch();
    return 0;
}