#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 5

void push();
void pop();
void display();
int queue_array[MAX];
int rear = -1;
int front = -1;

void menu()
{
    printf("--- C Queue using Array Demonstration --- \n\n");
    printf("Operations: \n");
    printf("   0. Menu\n");
    printf("   1. Push\n");
    printf("   2. Pop\n");
    printf("   3. Display\n");
    printf("   9. Quit\n");
}

int main()
{
    int ch;
    menu();
    while (1)
    {
        printf("\nEnter a command(0-3 or 9 to quit): ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 9:
            exit(1);
        default:
            printf("Invalid Input \n\n");
        }

        printf("\n\n");
    }

    getch();
    return 0;
}

void push()
{
    int element;
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else
    {
        if (front == -1)
            front = 0;
        printf("Enter queue element: ");
        scanf("%d", &element);
        rear = rear + 1;
        queue_array[rear] = element;
        printf("Element \"%d\" inserted on to the queue.", element);
    }
}

void pop()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
        return;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty!\n");
    else
    {
        printf("Queue elements are: \n");
        for (i = front; i <= rear; i++)
            printf("| %d |\n", queue_array[i]);
        printf("|-----|");
        printf("\n");
    }
}