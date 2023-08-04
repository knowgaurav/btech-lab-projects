#include <iostream>
#include <conio.h>
#include <vector>
#include <chrono>

using namespace std;

void insertionSort(int arr[], int n)
{
    for (int j = 1; j < n; j++)
    {
        int i = j - 1;
        int key = arr[j];

        while (i >= 0 && arr[i] > key)
        {
            swap(arr[i + 1], arr[i]);
            i--;
        }

        arr[i + 1] = key;
    }
}

void merge(int arr[], int p, int r)
{
    int i = p;
    int q = (p + r) / 2;
    int j = q + 1;
    vector<int> temp;

    while (i <= q && j <= r)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= q)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= r)
    {
        temp.push_back(arr[j]);
        j++;
    }

    i = 0;
    for (int k = p; k <= r; k++)
    {
        arr[k] = temp[i];
        i++;
    }
}

void mergeSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, r);
    }
}

void printArr(int arr[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
}

int main()
{

    int arr[] = {10, 2, 1, 8, 9};

    auto start = chrono::steady_clock::now();
    mergeSort(arr, 0, 4);
    auto end = chrono::steady_clock::now();

    printArr(arr, 5);

    cout << "\n\nTime elapsed = " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns";

    int arr_2[] = {10, 2, 1, 8, 9};

    start = chrono::steady_clock::now();
    insertionSort(arr_2, 5);
    end = chrono::steady_clock::now();

    printArr(arr_2, 5);

    cout << "\nTime Elapsed = " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns";

    getch();
    return 0;
}