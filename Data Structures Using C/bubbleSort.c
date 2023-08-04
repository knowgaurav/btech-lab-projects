#include <stdio.h>
#include <conio.h>

#define MAX 10

int main()
{
    int arr[MAX], i, j, temp, n, xchanges;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        xchanges = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                xchanges++;
            }
        }
        if (xchanges == 0)
            break;
    }
    printf("\nSorted list is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    getch();
    return 0;
}