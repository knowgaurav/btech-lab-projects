#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void merge(int *arr, int l, int m, int r);
void mergeSort(int *arr, int l, int r);
void swap(int *arr, int upb, int lwb);
int partition(int *arr, int s, int e);
void quickSort(int *arr, int s, int e);

void display(int *arr, int size)
{
    printf("\n\n[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("]");
}

void menu()
{
    printf("\n\n--- C Advanced Sorting Demonstration --- \n\n");
    printf("Operations: \n");
    printf("   0. Menu\n");
    printf("   1. Perform Merge Sort\n");
    printf("   2. Perform Quick Sort\n");
    printf("   3. Perform Heap Sort\n");
    printf("   4. Enter New Array\n");
    printf("   9. Quit\n");
}

int main()
{
    int *myArr, size, ch;

    printf("Enter the size of the array to be sorted: ");
    scanf("%d", &size);

    myArr = (int *)malloc(sizeof(int) * size);

    printf("\n\n");
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &myArr[i]);
    }

    menu();
    while (1)
    {
        printf("\n\n\nEnter a command(0-3 or 9 to quit): ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            menu();
            break;
        case 1:
            mergeSort(myArr, 0, size - 1);
            printf("\n\nSorting array using Merge Sort. Output: ");
            display(myArr, size);
            break;
        case 2:
            quickSort(myArr, 0, size - 1);
            printf("\n\nSorting array using Quick Sort. Output: ");
            display(myArr, size);
            break;
        case 3:
            quickSort(myArr, 0, size - 1);
            printf("\n\nSorting array using Heap Sort. Output: ");
            display(myArr, size);
            break;
        case 4:
            printf("\n\n");
            printf("Enter the new elements: ");
            for (int i = 0; i < size; i++)
            {
                scanf("%d", &myArr[i]);
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

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void merge(int *arr, int l, int m, int r)
{
    int size = r + 1;
    int i = l, j = m + 1, k = l;
    int *tempArr = (int *)malloc(sizeof(int) * size);

    while (i <= m && j <= r)
    {
        if (arr[i] < arr[j])
        {
            tempArr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            tempArr[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= m)
    {
        tempArr[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        tempArr[k] = arr[j];
        j++;
        k++;
    }

    for (int p = l; p < size; p++)
    {
        arr[p] = tempArr[p];
    }
}

void swap(int *arr, int upb, int lwb)
{
    int temp = arr[upb];
    arr[upb] = arr[lwb];
    arr[lwb] = temp;
}

int partition(int *arr, int s, int e)
{
    int pivot = arr[e];
    int pIndex = s;

    for (int i = s; i < e; i++)
    {
        if (arr[i] < pivot)
        {
            swap(arr, i, pIndex);
            pIndex++;
        }
    }
    swap(arr, e, pIndex);
    return pIndex;
}

void quickSort(int *arr, int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);
        quickSort(arr, s, p - 1);
        quickSort(arr, p + 1, e);
    }
}