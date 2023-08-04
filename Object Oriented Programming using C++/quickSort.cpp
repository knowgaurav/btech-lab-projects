#include <iostream>
#include <conio.h>

using namespace std;

void swap(int *arr, int i1, int i2)
{
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
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

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << ", ";
    }
}

int main()
{
    int myArr[5] = {3, 2, 5, 1, 0};
    int size = 5;

    quickSort(myArr, 0, size - 1);

    cout << "Array after sorting is: ";
    display(myArr, size);

    getch();
}