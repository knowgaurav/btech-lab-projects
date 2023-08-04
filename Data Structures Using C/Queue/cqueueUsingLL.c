#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *link;
};

struct node *head = NULL;
struct node *tail = NULL;

void enqueue(int data);
void dequeue();
void display();

void menu()
{
    printf("--- C Circular Queue using Linked List Demonstration --- \n\n");
    printf("Operations: \n");
    printf("   0. Menu\n");
    printf("   1. Enque\n");
    printf("   2. Deque\n");
    printf("   3. Display\n");
    printf("   9. Quit\n");
}

int main()
{
    int ch, ele;
    menu();
    while (1)
    {
        printf("\nEnter a command(0-3 or 9 to quit): ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            menu();
            break;
        case 1:
            printf("\n");
            printf("Enter the element: ");
            scanf("%d", &ele);
            enqueue(ele);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            printf("\n");
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

void enqueue(int data)
{
    struct node *newNode, *ptr;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num = data;
    newNode->link = newNode;
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        ptr = head;
        do
        {
            ptr = ptr->link;
        } while (ptr->link != head);
        ptr->link = newNode;
        tail = newNode;
        newNode->link = head;
    }
}

void dequeue()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("Queue is empty!");
    }
    if (head == tail)
    {
        printf("\nThe deleted element is: %d", head->num);
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->link;
        tail->link = head;
        printf("\nThe deleted element is: %d", ptr->num);
        free(ptr);
    }
}

void display()
{
    struct node *ptr = head;
    printf("| ");
    if (head == NULL)
    {
        printf("Queue is empty!");
    }
    else
    {
        do
        {
            printf("%d ", ptr->num);
            if (ptr->link != head)
                printf("| ");
            ptr = ptr->link;
        } while (ptr != head);
    }
    printf("|");
}