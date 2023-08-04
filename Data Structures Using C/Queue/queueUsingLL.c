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

void enque(int data);
void deque();
void display();

void menu()
{
    printf("--- C Queue using Linked List Demonstration --- \n\n");
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
            enque(ele);
            break;

        case 2:
            deque();
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

void enque(int data)
{
    struct node *newNode, *ptr = head;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->num = data;
    newNode->link = NULL;
    if (ptr == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = newNode;
        tail = newNode;
    }
}

void deque()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("Queue is empty!");
    }
    else
    {
        head = head->link;
        printf("The deleted element is: %d\n", ptr->num);
        free(ptr);
    }
}

void display()
{
    struct node *ptr = head;
    printf("| ");
    if (ptr == NULL)
    {
        printf("Queue is empty! ");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->num);
            if (ptr->link != NULL)
                printf("| ");
            ptr = ptr->link;
        }
    }
    printf("|");
}
