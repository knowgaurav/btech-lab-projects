#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> A = {10, 29, 25, 30, 15};
    for (int ele : A)
        cout << ele << " ";
    cout << endl;
    // We want to update this array from index 1 to index 4 by 3

    // Building the difference array
    int d[6] = {0};

    for (int i = 0; i < 6; i++)
    {
        if (i == 0)
        {
            d[i] = A[i];
        }
        else
        {
            d[i] = A[i] - A[i - 1];
        }
    }

    // Update the range [L, R] by X
    int L = 1, R = 4, value = 3;

    d[L] = d[L] + value;
    d[R + 1] = d[R + 1] - value;

    // Find the prefix sum of the difference array
    for (int i = 1; i < 6; i++)
    {
        d[i] = d[i] + d[i - 1];
    }

    // Now query is updated
    for (int i = 0; i < 5; i++)
    {
        A[i] = d[i];
    }

    for (int ele : A)
        cout << ele << " ";

    return 0;
}