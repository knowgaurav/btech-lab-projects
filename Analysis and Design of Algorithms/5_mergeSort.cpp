#include <iostream>
#include <ctime>
#include <conio.h>
#include <time.h>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

#define curr_time steady_clock::now()
#define nano_time duration_cast<nanoseconds>(end - start).count()
#define sec_time duration_cast<seconds>(end - start).count()

void merge(vector<int> &arr, int start, int end)
{
    int i = start;
    int m = (start + end) / 2;
    int j = m + 1;

    vector<int> temp;

    while (i <= m and j <= end)
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
    while (i <= m)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    int k = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[k];
        k++;
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

void insertionSort(vector<int> &arr, int size)
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

void printArray(vector<int> arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void initializeArray(vector<int> &arr, int size)
{
    arr.resize(size);
    srand(time(0));
    for (int i = 0; i < size; i++)
        arr[i] = 1 + (rand() % 1000);
}

void menu()
{
    cout << "--- C++ Merge Sort Algorithm Analysis --- \n\n";
    cout << "Operations: \n";
    cout << "   0. Menu\n";
    cout << "   1. Initialize Array\n";
    cout << "   2. Merge Sort\n";
    cout << "   3. Insertion Sort\n";
    cout << "   4. Display Array\n";
    cout << "   9. Quit\n";
}

int main()
{
    int len, ch;
    vector<int> arr;

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
            initializeArray(arr, len);
            break;
        case 2:
        {
            vector<int> mergeArr = arr;

            auto start = curr_time;
            mergeSort(mergeArr, 0, mergeArr.size() - 1);
            auto end = curr_time;

            cout << "Using Merge Sort:";
            cout << "\nElapsed time in nanoseconds: " << nano_time << " ns";
            cout << "\nElapsed time in seconds: " << sec_time << " sec";
            break;
        }
        case 3:
        {
            vector<int> insArr = arr;

            auto start = curr_time;
            insertionSort(insArr, insArr.size());
            auto end = curr_time;

            cout << "Using Insertion Sort:";
            cout << "\n\nElapsed time in nanoseconds: " << nano_time << " ns";
            cout << "\nElapsed time in seconds: " << sec_time << " sec";
            break;
        }
        case 4:
        {
            printArray(arr, len);
            break;
        }
        case 9:
            cout << "\nExiting, thanks for using!";
            getch();
            exit(1);
        default:
            cout << "Invalid Input\n";
            break;
        }
        cout << "\n";
    }
    getch();
    return 0;
}