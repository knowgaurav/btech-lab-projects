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

int length()
{
    struct node *temp = head;
    int count = 0;

    if (head != NULL)
    {
        do
        {
            temp = temp->link;
            count++;
        } while (temp != head);
    }

    return count;
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

void menu()
{
    printf("--- C Circular Linked List Demonstration --- \n\n");
    printf("Operations: \n");
    printf("0. Menu\n");
    printf("1. Append\n");
    printf("2. Display\n");
    printf("3. Search\n");
    printf("4. DeleteAtBegin\n");
    printf("5. Quit\n");
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
            display(head);
            break;

        case 3:
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

        case 4:
            deleteAtEnd();
            printf("\n\nThe list after deletion of the first element is: \n\n");
            display(head);
            break;

        case 5:
            exit(1);
        default:
            printf("Invalid Input \n\n");
        }

        printf("\n\n");
    }

    getch();
    return 0;
}