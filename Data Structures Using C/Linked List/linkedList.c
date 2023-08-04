//SIngle Linked list Operation

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;
int len;

void append(void);
int length(void);
void display(void);
void adddatbegin() {}
void addataafter() {}
void delete () {}

void main()
{
    int ch;
    while (1)
    {
        printf("Single Linked List Operations: \n");
        printf("1. Append\n");
        printf("2. Addatabegin\n");
        printf("3. Addatafter\n");
        printf("4. Length\n");
        printf("5. Display\n");
        printf("6. Delete\n");
        printf("7. Quit\n");

        printf("Enter your choice: \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            append();
            break;

        case 2:
            adddatbegin();
            break;

        case 3:
            addataafter();
            break;

        case 4:
            len = length();
            printf("The length is %d\n\n", len);
            break;

        case 5:
            display();
            break;

        case 6:
            delete ();
            break;

        case 7:
            exit(1);
        default:
            printf("Invalid Input \n\n");
        }
    }

    getch();
}

void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter Node data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;

        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

int length()
{
    int count = 0;
    struct node *temp;
    temp = root;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void display()
{
    struct node *temp;
    temp = root;
    if (temp == NULL)
    {
        printf("List is empty!\n\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}