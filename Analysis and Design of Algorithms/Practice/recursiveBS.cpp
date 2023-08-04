#include <iostream>
#include <ctime>
#include <conio.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define curr_time steady_clock::now()
#define nano_time duration_cast<nanoseconds>(end - start).count()
#define sec_time duration_cast<seconds>(end - start).count()

void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void initializeArray(int *arr, int size, int n)
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = (i + 1) * n;
}

int recursiveBS(int *arr, int l, int h, int key)
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2;

    if (key == arr[mid])
        return mid;
    else if (key < arr[mid])
        return recursiveBS(arr, l, mid - 1, key);
    else
        return recursiveBS(arr, mid + 1, h, key);
}

int search(int *arr, int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void menu()
{
    cout << "--- C++ Recursive Binary Search Analysis --- \n\n";
    cout << "Operations: \n";
    cout << "   0. Menu\n";
    cout << "   1. Initialize Array\n";
    cout << "   2. Binary Search\n";
    cout << "   3. Linear Search\n";
    cout << "   4. Display Array\n";
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
        cout << "\nEnter a command(0-3 or 9 to quit): ";
        cin >> ch;

        switch (ch)
        {
        case 0:
            menu();
            break;
        case 1:
            cout << "Enter the number: ";
            cin >> num;
            cout << "Enter the length: ";
            cin >> len;

            arr = new int[len];
            initializeArray(arr, len, num);
            break;
        case 2:
        {
            cout << "Entered element to be searched: ";
            cin >> key;

            auto start = curr_time;
            int pos = recursiveBS(arr, 0, len - 1, key);
            auto end = curr_time;

            if (pos == -1)
                cout << "\nElement not found!";
            else
                cout << "\nElement found at: " << pos + 1;

            cout << "\n\nElapsed time in nanoseconds: " << nano_time << " ns";

            cout << "\nElapsed time in seconds: " << sec_time << " sec";

            break;
        }
        case 3:
        {
            cout << "Entered element to be searched: ";
            cin >> key;

            auto start = chrono::steady_clock::now();
            int pos = search(arr, len, key);
            auto end = chrono::steady_clock::now();

            if (pos == -1)
                cout << "\nElement not found!";
            else
                cout << "\nElement found at: " << pos + 1;

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
            printArray(arr, len);
            break;
        }
        case 9:
            exit(1);
        default:
            cout << "Invalid Input \n\n";
        }
        cout << "\n";
    }

    delete[] arr;
    getch();
    return 0;
}
