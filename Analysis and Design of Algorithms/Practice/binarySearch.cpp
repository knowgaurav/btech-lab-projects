#include <iostream>
#include <conio.h>

using namespace std;

int binarySearch(int arr[], int l, int h, int key)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

int recursiveBS(int arr[], int l, int h, int key)
{

    if (l > h)
        return -1;

    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return recursiveBS(arr, mid + 1, h, key);
    else
        return recursiveBS(arr, l, mid, key);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    cout << binarySearch(arr, 0, 4, 2) << endl;
    cout << recursiveBS(arr, 0, 4, 2);

    getch();
    return 0;
}