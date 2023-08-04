#include <stdio.h>
#include <conio.h>

#define MAX 10

int main()
{
    int arr[MAX], i, j, k, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++)
    {
        k = arr[i];
        for (j = i - 1; j >= 0 && k < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = k;
    }

    printf("\nThe Sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    getch();
    return 0;
}
