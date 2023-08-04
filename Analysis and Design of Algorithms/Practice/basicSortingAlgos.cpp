#include <iostream>
#include <conio.h>
#include <chrono>

using namespace std;

void printArr(int arr[], int n);

void initializeArr(int *arr, int n)
{
    srand(time(0));

    for (int i = 0; i < n; i++)
        arr[i] = 1 + (rand() % 100);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int *arr, int n)
{
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
        {
            printArr(arr, n);
            break;
        }
    }
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(int *arr, int n)
{
    for (int j = 1; j < n; j++)
    {
        int i = j - 1;
        int key = arr[j];

        while (i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1] = key;
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    int size = 10;
    int *arr = new int[size];
    initializeArr(arr, size);

    cout << "Before using Bubble Sort: ";
    printArr(arr, size);

    auto start = chrono::steady_clock::now();
    bubbleSort(arr, size);
    auto end = chrono::steady_clock::now();

    cout << "After using Bubble Sort: ";
    printArr(arr, size);

    cout << "Time elapsed = " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns\n\n";

    initializeArr(arr, size);
    cout << "Before using Insertion Sort: ";
    printArr(arr, size);

    start = chrono::steady_clock::now();
    insertionSort(arr, size);
    end = chrono::steady_clock::now();

    cout << "After using Insertion Sort: ";
    printArr(arr, size);

    cout << "Time elapsed = " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns\n\n";

    initializeArr(arr, size);
    cout << "Before using Selection Sort: ";
    printArr(arr, size);

    start = chrono::steady_clock::now();
    selectionSort(arr, size);
    end = chrono::steady_clock::now();

    cout << "After using Selection Sort: ";
    printArr(arr, size);

    cout << "Time elapsed = " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns\n\n";

    getch();
    return 0;
}