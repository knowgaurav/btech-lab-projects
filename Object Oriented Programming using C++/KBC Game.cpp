#include <iostream>
#include <conio.h>

using namespace std;

int sizeOfArr(int arr[])
{
    int i = sizeof(arr) / sizeof(arr[0]);
    //for (i = 0; arr[i] != '\0'; i++);
    cout << "Size of A: " << sizeof(arr) << endl;
    cout << "Size of Arr[0]: " << sizeof(arr[0]) << endl;
    return i;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int size = sizeOfArr(arr);

    int i = sizeof(arr) / sizeof(arr[0]);
    //for (i = 0; arr[i] != '\0'; i++);
    cout << "Size of A: " << sizeof(arr) << endl;
    cout << "Size of Arr[0]: " << sizeof(arr[0]) << endl;

    cout << i << " " << size << endl;

    getch();
    return 0;
}