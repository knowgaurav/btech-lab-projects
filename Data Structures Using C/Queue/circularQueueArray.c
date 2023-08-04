#include <stdio.h>
#define MAX 5

int cqueue_arr[MAX];
int front = -1;
int rear = -1;

void enque(int item)
{
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("Queue Overflow \n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX - 1)
            rear = 0;
        else
            rear = rear + 1;
    }
    cqueue_arr[rear] = item;
}

void deque()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is : %d\n", cqueue_arr[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front = front + 1;
    }
}

void display()
{
    int front_pos = front, rear_pos = rear;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements :\n");
    if (front_pos <= rear_pos)
        while (front_pos <= rear_pos)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
    else
    {
        while (front_pos <= MAX - 1)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ", cqueue_arr[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

void menu()
{
    printf("--- C Circular Queue using Array Demonstration --- \n\n");
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
        int value;
        printf("\nEnter a command(0-3 or 9 to quit): ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Input the element for insertion in queue : ");
            scanf("%d", &value);
            enque(value);
            break;
        case 2:
            deque();
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

/*int main()
{
    int choice, item;
    do
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Input the element for insertion in queue : ");
            scanf("%d", &item);

            insert(item);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice != 4);

    return 0;
}*/
