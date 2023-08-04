#include <iostream>
#include <conio.h>

using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int size)
{
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
                printArray(arr, size);
            }
        }
    }
}

int main()
{
    cout << "Enter the lenght of the array: ";
    int len;
    cin >> len;
    int *arr = new int(len);

    cout << "\nEnter the elements of the array: ";
    for (int i = 0; i < len; i++)
        cin >> arr[i];

    bubbleSort(arr, len);

    cout << "\n\nFinal Sorted Array: " << endl;
    printArray(arr, len);

    getch();
    return 0;
}
