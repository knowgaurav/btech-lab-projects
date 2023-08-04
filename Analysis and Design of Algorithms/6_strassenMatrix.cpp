#include <iostream>
#include <conio.h>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define curr_time steady_clock::now()
#define s_nano_time duration_cast<nanoseconds>(s_end - s_start).count()
#define n_nano_time duration_cast<nanoseconds>(n_end - n_start).count()

void getInput(int arr[2][2])
{
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> arr[i][j];
}

void printArray(int arr[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << arr[i][j] << " ";

        cout << "\n";
    }
}

int main()
{
    int a[2][2], b[2][2], c[2][2], d[2][2];
    int p1, p2, p3, p4, p5, p6, p7;

    cout << "Enter the 4 elements of first matrix: ";
    getInput(a);

    cout << "Enter the 4 elements of second matrix: ";
    getInput(b);

    auto s_start = curr_time;
    p1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    p2 = (a[1][0] + a[1][1]) * b[0][0];
    p3 = a[0][0] * (b[0][1] - b[1][1]);
    p4 = a[1][1] * (b[1][0] - b[0][0]);
    p5 = (a[0][0] + a[0][1]) * b[1][1];
    p6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    p7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    c[0][0] = p1 + p4 - p5 + p7;
    c[0][1] = p3 + p5;
    c[1][0] = p2 + p4;
    c[1][1] = p1 - p2 + p3 + p6;
    auto s_end = curr_time;

    auto n_start = curr_time;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            d[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                d[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    auto n_end = curr_time;

    cout << "\nArray Multiplication using Strassen's algorithm:\n";
    printArray(c);
    cout << "Elapsed time in nanoseconds: " << s_nano_time << " ns";

    cout << "\n\nArray Multiplication using Naive Approach:\n";
    printArray(d);
    cout << "Elapsed time in nanoseconds: " << n_nano_time << " ns";

    return 0;
}