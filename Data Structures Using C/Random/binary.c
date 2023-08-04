#include <stdio.h>
#include <conio.h>

int binarySearch(int A[], int n, int x)
{

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (x == A[mid])
            return mid;
        else if (x < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int A[] = {2, 4, 5, 7, 13, 14, 15, 23};
    int x = 5;
    int index = binarySearch(A, 8, x);

    printf("Number found at %d", index);

    return 0;
}