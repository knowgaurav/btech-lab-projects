#include <iostream>
#include <conio.h>

using namespace std;

void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int *arr, int size)
{
    int i, j, min;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr, min, i);
        printArray(arr, size);
    }
}

int main()
{
    cout << "Enter the length of the array: ";
    int len;
    cin >> len;
    int *arr = new int(len);

    cout << "\nEnter the elements of the array: ";
    for (int i = 0; i < len; i++)
        cin >> arr[i];

    selectionSort(arr, len);

    cout << "\nFinal Sorted Array: " << endl;
    printArray(arr, len);

    getch();
    return 0;
}