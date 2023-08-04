#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct binaryHeap
{
    int *arr;
    int size;
    int length;
};

struct binaryHeap *heap1 = NULL;

struct binaryHeap *createBinaryHeap(int s);
int isEmpty(struct binaryHeap *heap);
void swap(struct binaryHeap *heap, int i, int j);
struct binaryHeap *insert(struct binaryHeap *heap, int data);
int findMax(struct binaryHeap *heap);
int deleteMax(struct binaryHeap *heap);
int sizeofHeap(struct binaryHeap *heap);
void display(struct binaryHeap *heap);

int main()
{
    heap1 = createBinaryHeap(10);
    heap1 = insert(heap1, 23);
    heap1 = insert(heap1, 12);
    heap1 = insert(heap1, 19);
    heap1 = insert(heap1, 35);
    heap1 = insert(heap1, 33);
    heap1 = insert(heap1, 42);
    heap1 = insert(heap1, 25);

    printf("%d ", deleteMax(heap1));

    display(heap1);

    getch();
    return 0;
}

struct binaryHeap *createBinaryHeap(int s)
{
    struct binaryHeap *newHeap = (struct binaryHeap *)malloc(sizeof(struct binaryHeap));
    newHeap->size = s;
    newHeap->arr = (int *)malloc(sizeof(int) * newHeap->size);
    newHeap->length = 0;
    return newHeap;
}

int isEmpty(struct binaryHeap *heap)
{
    if (heap->length == 0)
        return 1;
    return 0;
}

void swap(struct binaryHeap *heap, int i, int j)
{
    int temp = heap->arr[i];
    heap->arr[i] = heap->arr[j];
    heap->arr[j] = temp;
}

struct binaryHeap *insert(struct binaryHeap *heap, int data)
{
    int i = heap->length;
    heap->arr[i] = data;
    heap->length++;

    while (i != 0)
    {
        int parent = (i - 1) / 2;
        if (heap->arr[i] > heap->arr[parent])
        {
            swap(heap, i, parent);
            i = parent;
        }
        else
            break;
    }

    return heap;
}

int findMax(struct binaryHeap *heap)
{
    if (isEmpty(heap) == 1)
        return -1;
    return heap->arr[0];
}

int deleteMax(struct binaryHeap *heap)
{
    if (isEmpty(heap) == 1)
        return -1;
    int temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->length - 1];
    --heap->length;

    int i = 0;

    while (2 * i + 1 < heap->length)
    {
        if ((2 * i + 1) < heap->length && (2 * i + 2) < heap->length)
        {
            int k = heap->arr[2 * i + 1] > heap->arr[2 * i + 2] ? (2 * i + 1) : (2 * i + 2);

            if (heap->arr[0] < heap->arr[k])
            {
                swap(heap, 0, k);
                i = k;
            }
            else
                break;
        }
        else if (2 * i + 1 < heap->length)
        {
            int k = 2 * i + 1;

            if (heap->arr[0] < heap->arr[k])
            {
                swap(heap, 0, k);
                i = k;
            }
            else
                break;
        }
    }

    return temp;
}

int sizeofHeap(struct binaryHeap *heap)
{
    return heap->length;
}

void display(struct binaryHeap *heap)
{
    printf("\n\nThe Binary Heap is: [ ");
    for (int i = 0; i < heap->length; i++)
    {
        printf("%d, ", heap->arr[i]);
    }
    printf("]");
}