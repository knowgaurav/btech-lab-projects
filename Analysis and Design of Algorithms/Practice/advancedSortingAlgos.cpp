#include <iostream>
#include <conio.h>
#include <vector>
#include <chrono>

using namespace std;

void initializeArr(int arr[], int n)
{
    srand(time(0));

    for (int i = 0; i < n; i++)
        arr[i] = 1 + (rand() % 100);
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(vector<int> &arr, int p, int r)
{
    int i = p;
    int q = (p + r) / 2;
    int j = q + 1;

    vector<int> temp;

    while (i <= q and j <= r)
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

    int k = 0;
    for (int idx = p; idx <= r; idx++)
    {
        arr[idx] = temp[k];
        k++;
    }
}

void mergeSort(vector<int> &arr, int p, int r)
{
    if (p >= r)
        return;

    int q = (p + r) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q + 1, r);
    merge(arr, p, r);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int s, int e)
{
    // int pivot = arr[p];
    // int i = p;

    // for (int j = p + 1; j <= r; j++)
    // {
    //     if (arr[j] <= pivot)
    //     {
    //         i++;
    //         swap(&arr[j], &arr[i]);
    //     }
    // }
    // swap(&arr[p], &arr[i]);
    // return i;

    int pivot = arr[e];
    int count = 0;

    for (int i = s; i <= e; i++)
    {
        if (arr[i] < pivot)
        {
            count++;
        }
    }

    int pivotIdx = s + count;
    swap(arr[e], arr[pivotIdx]);

    int low = s, high = e;
    while (low < pivotIdx)
    {
        if (arr[low] >= arr[pivotIdx])
        {
            while (arr[high] > arr[pivotIdx])
            {
                high--;
            }
            swap(arr[low], arr[high]);
        }
        low++;
    }

    return pivotIdx;
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

int main()
{
    int q_arr[] = {10, 4, 5, 10, 1};
    vector<int> arr = {10, 5, 6, 2, 1};

    auto start = chrono::steady_clock::now();
    // mergeSort(arr, 0, 4);
    auto end = chrono::steady_clock::now();

    // for (int i : arr)
    //     cout << i << " ";
    // // printArr(arr, 5);

    // cout << "\nTime elapsed = " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns";

    initializeArr(q_arr, 5);
    printArr(q_arr, 5);

    cout << "\nSorting using Quick Sort: ";

    start = chrono::steady_clock::now();
    quickSort(q_arr, 0, 4);
    end = chrono::steady_clock::now();

    printArr(q_arr, 5);

    cout << "Time Elapsed = " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns";

    // getch();
    return 0;
}

// void merge(int arr[], int p, int q, int r)
// {
//     int n1 = q - p + 1;
//     int n2 = r - q;

//     cout << n1 << "-" << n2 << endl;

//     int *left = new int[n1];
//     int *right = new int[n2];

//     printArr(left, n1 + 1);
//     printArr(right, n2 + 1);

//     for (int i = 0; i <= n1; i++)
//         left[i] = arr[p + i - 1];

//     for (int j = 0; j <= n2; j++)
//         right[j] = arr[q + j];

//     left[n1] = INT_MAX;
//     right[n2] = INT_MAX;

//     int i = 0;
//     int j = 0;

//     for (int k = p; k < r; k++)
//     {
//         if (left[i] <= right[j])
//         {
//             arr[k] = left[i];
//             i++;
//         }
//         else
//         {
//             arr[k] = right[j];
//             j++;
//         }
//     }
// }

// void mergeSort(int arr[], int p, int r)
// {
//     if (p < r)
//     {
//         int q = (p + r) / 2;
//         mergeSort(arr, p, q);
//         mergeSort(arr, q + 1, r);
//         merge(arr, p, q, r);
//     }
// }