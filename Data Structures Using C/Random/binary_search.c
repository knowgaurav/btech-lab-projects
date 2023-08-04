#include <stdio.h>
#include <conio.h>

int binarySearch(int A[], int n, int x)
{
    int low = 0, high = n - 1;
    if (low > high)
    {
        return -1;
    }
    else
    {
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
        return -2;
    }
}

int main()
{
    int A[4];
    int x = 0;
    printf("Enter the elements of the array\n");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter the number to be searched\n");
    scanf("%d", &x);
    int index = binarySearch(A, 5, x);

    if (index == -1)
    {
        printf("\nList not valid!");
    }
    else if (index == -2)
    {
        printf("\nNumber not found");
    }
    else
    {
        printf("\nNumber found at %d", index);
    }

    getch();
    return 0;
}