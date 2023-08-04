#include <iostream>
#include <conio.h>

using namespace std;

int partition(int arr[], int p, int r)
{
    int pivot = arr[p];
    int i = p;

    for (int j = p + 1; j <= r; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[p], arr[i]);
    return i;
}

void quickSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
}

int main()
{
    int arr[] = {10, 2, 1, 8, 9};
    quickSort(arr, 0, 4);

    printArr(arr, 5);

    getch();
    return 0;
}