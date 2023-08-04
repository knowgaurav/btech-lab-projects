#include <iostream>
#include <conio.h>
#include <time.h>

//using Chrono library which provides the exact time and helps to find the time elapsed during execution of some part of code
#include <chrono>

using namespace std;

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int *createCopy(int arr[], int size)
{
    int *new_arr = new int[size];
    for (int i = 0; i < size; i++)
        new_arr[i] = arr[i];

    return new_arr;
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
            }
        }
    }
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
    }
}

void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Initializing Array with Random numbers less than 1000 with the help of srand() and rand() funtions
void initializeArray(int *arr, int size)
{
    srand(time(0));

    for (int i = 0; i < size; i++)
        arr[i] = 1 + (rand() % 1000);
}

void menu()
{
    cout << "--- C++ Basic Sorting Algorithms Analysis --- \n\n";
    cout << "Operations: \n";
    cout << "   0. Menu\n";
    cout << "   1. Initialize Array\n";
    cout << "   2. Bubble Sort\n";
    cout << "   3. Selection Sort\n";
    cout << "   4. Insertion Sort\n";
    cout << "   5. Display Array\n";
    cout << "   9. Quit\n";
}

int main()
{
    int num, len, key;
    int *count, *time, *arr;
    int ch;

    menu();
    while (1)
    {
        cout << "\nEnter a command(0-5 or 9 to quit): ";
        cin >> ch;

        switch (ch)
        {
        case 0:
            menu();
            break;
        case 1:
            cout << "Enter the length of the array: ";
            cin >> len;

            arr = new int[len];
            initializeArray(arr, len);
            break;
        case 2:
        {
            int *bubbleArr = createCopy(arr, len);

            auto start = chrono::steady_clock::now();
            bubbleSort(bubbleArr, len);
            auto end = chrono::steady_clock::now();

            cout << "Sorted Array by Bubble Sort is: ";
            printArray(bubbleArr, len);

            cout << "\n\nElapsed time in nanoseconds: "
                 << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
                 << " ns";
            cout << "\nElapsed time in seconds: "
                 << chrono::duration_cast<chrono::seconds>(end - start).count()
                 << " sec";
            break;
        }
        case 3:
        {

            int *selectionArr = createCopy(arr, len);

            auto start = chrono::steady_clock::now();
            selectionSort(selectionArr, len);
            auto end = chrono::steady_clock::now();

            cout << "Sorted Array by Selection Sort is: ";
            printArray(selectionArr, len);

            cout << "\n\nElapsed time in nanoseconds: "
                 << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
                 << " ns";
            cout << "\nElapsed time in seconds: "
                 << chrono::duration_cast<chrono::seconds>(end - start).count()
                 << " sec";
            break;
        }
        case 4:
        {
            int *insertionArr = createCopy(arr, len);

            auto start = chrono::steady_clock::now();
            insertionSort(insertionArr, len);
            auto end = chrono::steady_clock::now();

            cout << "Sorted Array by Insertion Sort is: ";
            printArray(insertionArr, len);

            cout << "\n\nElapsed time in nanoseconds: "
                 << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
                 << " ns";
            cout << "\nElapsed time in seconds: "
                 << chrono::duration_cast<chrono::seconds>(end - start).count()
                 << " sec";
            break;
        }
        case 5:
        {
            printArray(arr, len);
            break;
        }
        case 9:
            cout << "\nExiting, thanks for using!";
            getch();
            exit(1);
        default:
            cout << "Invalid Input \n\n";
            break;
        }
        cout << "\n";
    }

    delete[] arr;

    getch();
    return 0;
}