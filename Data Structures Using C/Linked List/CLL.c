#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;
struct node *tail = NULL;

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp->link = head;
    }
    else
    {
        struct node *p = head;
        do
        {
            p = p->link;
        } while (p->link != head);
        p->link = temp;
        temp->link = head;
        tail = temp;
    }
}

void addAtBegin()
{
    struct node *temp, *tempH;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp->link = head;
    }
    else
    {
        tempH = head;
        temp->link = head;
        while (tempH->link != head)
        {
            tempH = tempH->link;
        }
        tempH->link = temp;
        head = temp;
    }
}

void addAt(int pos, int num)
{
    struct node *temp = NULL;
    int i;

    if (head == NULL)
    {
        printf("The list is empty!");
    }
    else if (pos == 1)
    {
        addAtBegin();
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = num;
        struct node *p = head;
        for (i = 2; i <= pos - 1; i++)
        {
            p = p->link;
        }
        temp->link = p->link;
        p->link = temp;
    }
}

void display(struct node *temp)
{
    if (temp->link == head)
    {
        printf("%d -> ", temp->data);
        return;
    }
    printf("%d -> ", temp->data);
    display(temp->link);
}

int search()
{
    struct node *temp = head;
    int num, index = 1;

    printf("Enter the data you wish to search: \n");
    scanf("%d", &num);

    do
    {
        if (head == NULL)
        {
            return -1;
        }
        if (temp->data == num)
        {
            return index;
        }
        temp = temp->link;
        index++;
    } while (temp != head);
    return -1;
}

void deleteAtBegin()
{
    struct node *temp, *p;
    p = temp = head;
    if (head == NULL)
    {
        printf("\nDeletion not possible!\n");
    }
    else
    {
        head = head->link;
        do
        {
            temp = temp->link;
        } while (temp->link != p);
        temp->link = head;
        free(p);
    }
}

void deleteAt()
{
    int loc;
    printf("\nEnter the location to be deleted: \n");
    scanf("%d", &loc);

    if (head == NULL)
    {
        printf("List is empty!");
    }

    else if (loc == 1)
    {
        deleteAtBegin();
    }

    else
    {
        struct node *p = head, *q;
        int i = 1;
        while (i != loc - 1)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
}

void menu()
{
    printf("--- C Circular Linked List // Lab Viva --- \n\n");
    printf("Operations: \n");
    printf("0. Menu\n");
    printf("1. Append\n");
    printf("2. AddAtBegin\n");
    printf("3. AddDataAt\n");
    printf("4. Display\n");
    printf("5. Search\n");
    printf("6. DeleteAtBegin\n");
    printf("7. DeleteAt\n");
    printf("8. Quit\n");
}

int main()
{
    int ch, loc, num, pos;
    menu();
    while (1)
    {

        printf("\nEnter a command(0-6 or 7 to quit): ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            menu();
            break;
        case 1:
            append();
            break;

        case 2:
            addAtBegin();
            printf("\n\nThe list after addition at first location is: \n\n");
            display(head);
            break;

        case 3:
            printf("\nEnter the location at which you wish to delete: \n");
            scanf("%d", &loc);
            printf("\nEnter the node data: \n");
            scanf("%d", &num);
            addAt(loc, num);
            printf("\n\nThe list after addition of a new element is: \n\n");
            display(head);
            break;

        case 4:
            display(head);
            break;

        case 5:
            pos = search();
            if (pos == -1)
            {
                printf("\nElement not found in the list!\n");
            }
            else
            {
                printf("\nElement found at location: %d\n", pos);
            }
            break;

        case 6:
            deleteAtBegin();
            printf("\n\nThe list after deletion of the first element is: \n\n");
            display(head);
            break;

        case 7:
            deleteAt();
            printf("\n\nThe list after deletion of the element is: \n\n");
            display(head);
            break;

        case 8:
            exit(1);
        default:
            printf("Invalid Input \n\n");
        }

        printf("\n\n");
    }

    getch();
    return 0;
}