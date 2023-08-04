#include <iostream>
#include <conio.h>

using namespace std;

void inplaceHeapSort(int input[], int n)
{
    //Build the heap in input array
    for (int i = 0; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (input[childIndex] < input[parentIndex])
            {
                swap(input[childIndex], input[parentIndex]);
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    //Remove elements
    int size = n;

    while (size > 1)
    {
        int temp = input[0];
        input[0] = input[size - 1];
        input[size - 1] = temp;

        size--;

        int parentIndex = 0;
        int leftChild, rightChild;
        leftChild = (2 * parentIndex) + 1;
        rightChild = (2 * parentIndex) + 2;

        while (leftChild < size)
        {
            int minIndex = parentIndex;
            if (input[minIndex] > input[leftChild])
                minIndex = leftChild;
            if (rightChild < size && input[rightChild] < input[minIndex])
                minIndex = rightChild;
            if (minIndex == parentIndex)
                break;

            swap(input[minIndex], input[parentIndex]);
            parentIndex = minIndex;
            leftChild = (2 * parentIndex) + 1;
            rightChild = (2 * parentIndex) + 2;
        }
    }
}

int main()
{
    int input[] = {5, 1, 2, 0, 8};
    int size = 5;
    inplaceHeapSort(input, size);
    for (int i = size - 1; i >= 0; i--)
    {
        cout << input[i] << " ";
    }

    getch();
    return 0;
}