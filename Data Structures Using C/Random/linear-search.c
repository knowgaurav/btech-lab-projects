#include <stdio.h>
#include <conio.h>

int search(int array[], int a, int b)
{
    for (int i = 0; i < a; i++)
        if (array[i] == b)
            return i;
    return -1;
}
int main()
{
    int a, b;
    int array[100];
    printf("How many values: ");
    scanf("%d", &a);
    printf("Enter the values of the array: ");
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("Enter the value to be searched: ");
    scanf("%d", &b);
    int result = search(array, a, b);
    if (result == -1)
    {
        printf("Result not found");
    }
    else
    {
        printf("Element fount at: %d", result);
    }
    getch();
}