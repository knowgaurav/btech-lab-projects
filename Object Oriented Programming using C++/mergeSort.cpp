#include <iostream>
#include <conio.h>

using namespace std;

void merge(int *arr, int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    int temp[5];

    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = *(arr + j);
            j++;
            k++;
        }
    }

    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int p = l; p <= r; p++)
    {
        *(arr + p) = *(temp + p);
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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

    mergeSort(myArr, 0, size - 1);

    cout << "Array after sorting is: ";
    display(myArr, size);

    getch();
}