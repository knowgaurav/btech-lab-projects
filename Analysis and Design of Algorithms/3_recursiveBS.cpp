// #include <iostream>
// #include <conio.h>
// #include <ctime>
// #include <time.h>
// #include <bits/stdc++.h>

// using namespace std;

// void printArray(int *arr, int size)
// {
//     int i;
//     for (i = 0; i < size; i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }

// int recursiveBS(int *arr, int l, int h, int key)
// {
//     if (l > h)
//         return -1;

//     int mid = (l + h) / 2;

//     if (key == arr[mid])
//         return mid;
//     else if (key < arr[mid])
//         return recursiveBS(arr, l, mid, key);
//     else
//         return recursiveBS(arr, mid + 1, h, key);
// }

// int main()
// {
//     time_t start, finish;

//     cout << "Enter the length of the array: ";
//     int len;
//     cin >> len;
//     int arr[len];
//     // int *arr = new int(len);

//     cout << "We would be checking for " << len << " times: ";

//     int z = len;
//     double time[len];

//     time(&start);
//     ios_base::sync_with_stdio(false);

//     cout << "\nEnter the elements of the array: ";
//     for (int i = 0; i < len; i++)
//         cin >> arr[i];

//     cout << "\nEnter the element to be searched: ";
//     int k;
//     cin >> k;

//     int pos = recursiveBS(arr, 0, len, k);

//     time(&end);

//     if (pos == -1)
//         cout << "\nElement not found!";
//     else
//         cout << "\nElement found at: " << pos + 1;

//     cout << "\nTime taken to find: " << difftime(finish, start) << "seconds";

//     // while (z < len)
//     // {
//     //     time_t start, finish;

//     //     int pos = recursiveBS(arr, 0, len, k);

//     //     if (pos == -1)
//     //         cout << "\nElement not found!";
//     //     else
//     //         cout << "\nElement found at: " << pos + 1;

//     //     cout << "\nTime taken to find: " << difftime(finish, start) << "seconds";

//     //     int temp = arr[pos];
//     //     arr[pos] = arr[pos % len];
//     //     arr[pos % len] = temp;

//     //     z++;
//     // }

//     // for (int i = 0; i < len; i++)
//     //     cout << "\nTime taken to find: " << time[i] << "seconds";

//     getch();
//     return 0;
// }

#include <iostream>
#include <ctime>
#include <conio.h>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int recursiveBS(int *arr, int l, int h, int key)
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2;

    if (key == arr[mid])
        return mid;
    else if (key < arr[mid])
        return recursiveBS(arr, l, mid, key);
    else
        return recursiveBS(arr, mid + 1, h, key);
}

int main()
{
    clock_t start, end;
    cout << "Enter the times to run the algorithm: ";
    int times;
    cin >> times;

    cout << "Enter the length of the array: ";
    int len;
    cin >> len;
    int arr[len];
    // int *arr = new int(len);

    cout << "\nEnter the elements of the array: ";
    for (int i = 0; i < len; i++)
        cin >> arr[i];

    // cout << "\nEnter the element to be searched: ";
    // int k;
    // cin >> k;

    // double time[len];

    // double start = clock();
    // int pos = recursiveBS(arr, 0, len, k);
    // double finish = clock();
    // if (pos == -1)
    //     cout << "\nElement not found!";
    // else
    //     cout << "\nElement found at: " << pos + 1;

    // cout << "\nTime taken to find: " << difftime(finish, start) << "seconds";
    int key;
    int z = 0;
    while (z < times)
    {
        cout << "\nWant to keep the same array: ";
        int ch;
        cin >> ch;

        if (ch == 0)
        {
            cout << "\nEnter the elements of the array: ";
            for (int i = 0; i < len; i++)
                cin >> arr[i];
        }

        cout << "Enter the element to be searched ";
        cin >> key;

        start = clock();
        int pos = recursiveBS(arr, 0, len, key);
        end = clock();

        if (pos == -1)
            cout << "\nElement not found!";
        else
            cout << "\nElement found at: " << pos + 1;

        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "\nTime taken to find: " << fixed
             << time_taken << setprecision(5)
             << "seconds";

        z++;
    }

    getch();
    return 0;
}

// #include <iostream>
// #include <ctime>
// #include <time.h>

// using namespace std;

// void printArray(int *arr, int size)
// {
//     int i;
//     for (i = 0; i < size; i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }

// int recursiveBS(int *arr, int l, int h, int key)
// {
//     if (l > h)
//         return -1;

//     int mid = (l + h) / 2;

//     if (key == arr[mid])
//         return mid;
//     else if (key < arr[mid])
//         return recursiveBS(arr, l, mid, key);
//     else
//         return recursiveBS(arr, mid + 1, h, key);
// }

// int main()
// {
//     cout << "Enter the times to run the algorithm: ";
//     int times;
//     cin >> times;

//     cout << "Enter the length of the array: ";
//     int len;
//     cin >> len;
//     // int arr[10];
//     int *arr = new int(len);

//     cout << "\nEnter the elements of the array: ";
//     for (int i = 0; i < len; i++)
//         cin >> arr[i];

//     // cout << "\nEnter the element to be searched: ";
//     // int k;
//     // cin >> k;

//     // double time[len];

//     // double start = clock();
//     // int pos = recursiveBS(arr, 0, len, k);
//     // double finish = clock();
//     // if (pos == -1)
//     //     cout << "\nElement not found!";
//     // else
//     //     cout << "\nElement found at: " << pos + 1;

//     // cout << "\nTime taken to find: " << difftime(finish, start) << "seconds";

//     int z=0;
//     while (z < times)
//     {
//         cout << "\nWant to keep the same array: ";
//         int ch;
//         cin >> ch;

//         if(ch == 0){
//                 cout << "\nEnter the elements of the array: ";
//                 for (int i = 0; i < len; i++)
//                 cin >> arr[i];
//         }

//         cout << "Enter the element to be searched ";
//         cin >> key;

//         double start = clock();
//         int pos = recursiveBS(arr, 0, len, k);
//         double finish = clock();

//         if (pos == -1)
//             cout << "\nElement not found!";
//         else
//             cout << "\nElement found at: " << pos + 1;

//         cout << "\nTime taken to find: " << difftime(finish, start) << "seconds";

//         z++;
//     }

//     delete[] arr;
//     // getch();
//     return 0;
// }

// #include <iostream>
// #include <conio.h>
// #include <ctime>
// #include <time.h>
// #include <bits/stdc++.h>

// using namespace std;

// void printArray(int *arr, int size)
// {
//     int i;
//     for (i = 0; i < size; i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }

// int recursiveBS(int *arr, int l, int h, int key)
// {
//     if (l > h)
//         return -1;

//     int mid = (l + h) / 2;

//     if (key == arr[mid])
//         return mid;
//     else if (key < arr[mid])
//         return recursiveBS(arr, l, mid, key);
//     else
//         return recursiveBS(arr, mid + 1, h, key);
// }

// int main()
// {
//     time_t start, finish;

//     cout << "Enter the length of the array: ";
//     int len;
//     cin >> len;
//     int arr[len];
//     // int *arr = new int(len);

//     cout << "We would be checking for " << len << " times: ";

//     int z = len;
//     double time[len];

//     time(&start);
//     ios_base::sync_with_stdio(false);

//     cout << "\nEnter the elements of the array: ";
//     for (int i = 0; i < len; i++)
//         cin >> arr[i];

//     cout << "\nEnter the element to be searched: ";
//     int k;
//     cin >> k;

//     int pos = recursiveBS(arr, 0, len, k);

//     time(&end);

//     if (pos == -1)
//         cout << "\nElement not found!";
//     else
//         cout << "\nElement found at: " << pos + 1;

//     cout << "\nTime taken to find: " << difftime(finish, start) << "seconds";

//     // while (z < len)
//     // {
//     //     time_t start, finish;

//     //     int pos = recursiveBS(arr, 0, len, k);

//     //     if (pos == -1)
//     //         cout << "\nElement not found!";
//     //     else
//     //         cout << "\nElement found at: " << pos + 1;

//     //     cout << "\nTime taken to find: " << difftime(finish, start) << "seconds";

//     //     int temp = arr[pos];
//     //     arr[pos] = arr[pos % len];
//     //     arr[pos % len] = temp;

//     //     z++;
//     // }

//     // for (int i = 0; i < len; i++)
//     //     cout << "\nTime taken to find: " << time[i] << "seconds";

//     getch();
//     return 0;
// }

#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
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

int main()
{
    clock_t start, end;
    cout << "Enter the times to run the algorithm: ";
    int times;
    cin >> times;

    cout << "\nEnter the length of the array: ";
    int len;
    cin >> len;
    int arr[100];

    cout << "\nEnter the elements of the array: ";
    for (int i = 0; i < len; i++)
        cin >> arr[i];

    int key;
    int z = 0;
    while (z < times)
    {
        // cout << "\nWant to keep the same array: ";
        // int ch;
        // cin >> ch;

        // if (ch == 0)
        // {
        //     cout << "\nEnter the length of the array: ";
        //     int len;
        //     cin >> len;

        //     cout << "\nEnter the elements of the array: ";
        //     for (int i = 0; i < len; i++)
        //         cin >> arr[i];
        // }

        cout << "Enter the element to be searched ";
        cin >> key;

        double start = clock();
        int pos = recursiveBS(arr, 0, len, key);
        double end = clock();

        if (pos == -1)
            cout << "\nElement not found!";
        else
            cout << "\nElement found at: " << pos + 1;

        cout << "\nTime taken to find: " << difftime(end, start)
             << "seconds";

        z++;
    }

    return 0;
}