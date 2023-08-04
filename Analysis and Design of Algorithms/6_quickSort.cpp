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

int partition(vector<int> &A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(A[i], A[j]);
        }
    } while (i < j);

    swap(A[low], A[j]);
    return j;
}

void quickSort(vector<int> &A, int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

void initializeArray(vector<int> &arr, int size)
{
    arr.resize(size);
    srand(time(0));
    for (int i = 0; i < size; i++)
        arr[i] = 1 + (rand() % 1000);
}

void printArray(vector<int> arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void menu()
{
    cout << "--- C++ Quick Sort Algorithm Analysis --- \n\n";
    cout << "Operations: \n";
    cout << "   0. Menu\n";
    cout << "   1. Initialize Array\n";
    cout << "   2. Quick Sort\n";
    cout << "   3. Display Array\n";
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
            vector<int> quickArr = arr;

            auto start = curr_time;
            quickSort(quickArr, 0, quickArr.size() - 1);
            auto end = curr_time;

            cout << "Sorted Array: \n";
            printArray(quickArr, quickArr.size() - 1);

            cout << "\nUsing Quick Sort, Array Length = " << len;
            cout << "\nElapsed time in nanoseconds: " << nano_time << " ns";
            cout << "\nElapsed time in seconds: " << sec_time << " sec";
            break;
        }
        case 3:
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
