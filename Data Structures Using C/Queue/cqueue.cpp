#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;

bool isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enque(int value)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue is full!");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = (rear + 1) % SIZE;
            A[rear] = value;
        }
    }
}

void deque()
{
    if (isEmpty())
    {
        printf("Queue is empty!");
    }
    else
    {
        if (front == rear)
            front = rear - 1;
        else
            front = (front + 1) % SIZE;
    }
}

void showFront()
{
    if (isEmpty())
        printf("Queue is empty!");
    else
        printf("Element at the front of the queue is: %d", A[front]);
}

void displayQueue()
{
    if (isEmpty())
    {
        printf("Queue is empty!");
    }
    else
    {
        int i;
        if (front <= rear)
        {
            for (i = front; i < rear; i++)
                printf("%d", A[i]);
        }
        else
        {
            i = front;
            while (i < SIZE)
            {
                printf("%d ->", A[i]);
                i++;
            }
            i = 0;
            while (i < rear)
            {
                printf("%d", A[i]);
                i++;
            }
        }
    }
}

int main()
{

    enque(100);
    enque(200);
    enque(300);

    displayQueue();

    getch();
    return 0;
}