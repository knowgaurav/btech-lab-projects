#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void insertionSort(int *arr, int n);
void bubbleSort(int *arr, int n);
void selectionSort(int *arr, int n);

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void menu()
{
    printf("\n\n--- C Sorting Demonstration --- \n\n");
    printf("Operations: \n");
    printf("   0. Menu\n");
    printf("   1. Perform Insertion Sort\n");
    printf("   2. Perform Bubble Sort\n");
    printf("   3. Perform Selection Sort\n");
    printf("   4. Enter new array\n");
    printf("   9. Quit\n");
}

int main()
{
    int *arr, size, ch;

    printf("Enter the size of the array to be sorted: ");
    scanf("%d", &size);

    arr = (int *)malloc(sizeof(int) * size);

    printf("\n\n");
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    menu();
    while (1)
    {
        printf("\n\nEnter a command(0-3 or 9 to quit): ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            menu();
            break;
        case 1:
            insertionSort(arr, size);
            printf("\n\nSorting array using Insertion Sort. Output: ");
            display(arr, size);
            break;
        case 2:
            bubbleSort(arr, size);
            printf("\n\nSorting array using Bubble Sort. Output: ");
            display(arr, size);
            break;
        case 3:
            selectionSort(arr, size);
            printf("\n\nSorting array using Selection Sort. Output: ");
            display(arr, size);
            break;
        case 4:
            printf("\n\n");
            printf("Enter the elements: ");
            for (int i = 0; i < size; i++)
            {
                scanf("%d", &arr[i]);
            }
            break;
        case 9:
            exit(1);
        default:
            printf("\n\nInvalid Input!");
        }
        //printf("\n");
    }

    getch();
    return 0;
}

void insertionSort(int *arr, int n)
{
    int i, j, k;

    for (i = 1; i < n; i++)
    {
        k = arr[i];
        for (j = i - 1; j >= 0 && k < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = k;
    }
}

void bubbleSort(int *arr, int n)
{
    int i, j, temp, xchanges;

    for (i = 0; i < n - 1; i++)
    {
        xchanges = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                xchanges++;
            }
        }
        if (xchanges == 0)
            break;
    }
}

void selectionSort(int *arr, int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        if (i != min)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}