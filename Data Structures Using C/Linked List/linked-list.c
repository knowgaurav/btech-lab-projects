#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;
int len;

void append(void);
int length(void);
void display(void);
void addBegin(void);
void addAfter(void);
void delete (void);
int search(void);
void reverse(void);

void menu()
{
    printf("--- C Singly Linked List Demonstration --- \n\n");
    printf("Operations: \n");
    printf("0. Menu\n");
    printf("1. Append\n");
    printf("2. Addatabegin\n");
    printf("3. Addatafter\n");
    printf("4. Length\n");
    printf("5. Display\n");
    printf("6. Delete\n");
    printf("7. Search\n");
    printf("8. Reverse\n");
    printf("9. Quit\n");
}

void main()
{
    int ch;
    menu();
    while (1)
    {

        printf("\nEnter a command(0-8 or 9 to quit): ");
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
            addBegin();
            break;

        case 3:
            printf("The list before addition of a new element is: ");
            display();
            addAfter();
            printf("The list after addition of a new element is: ");
            display();
            break;

        case 4:
            len = length();
            printf("The length is %d\n", len);
            printf("The list is: ");
            display();
            break;

        case 5:
            display();
            break;

        case 6:
            printf("The list before deletion is: ");
            display();
            delete ();
            printf("The list after deletion is: ");
            display();
            break;

        case 7:
            search();
            break;

        case 8:
            printf("The list before reversal is: ");
            display();
            reverse();
            printf("The list after reversal is: ");
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
}

void append(void)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter Node data: \n");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *p;
        p = head;

        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void addBegin(void)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter Node data: \n");
    scanf("%d", &temp->data);
    temp->link = head;
    head = temp;
}

void addAfter(void)
{
    struct node *temp;
    int loc, len;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter Node data: \n");
    scanf("%d", &temp->data);
    temp->link = NULL;

    printf("\nEnter the location at which new node to be added: \n");
    scanf("%d", &loc);
    len = length();
    if (loc > len + 1 || loc < 0)
    {
        printf("\nInvalid Location!\n");
    }

    else if (loc == 1)
    {
        temp->link = head;
        head = temp;
    }

    else
    {
        struct node *p = head, *q;
        int i = 1;
        while (i < loc - 1)
        {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = temp;
        temp->link = q;
    }
}

void display(void)
{
    struct node *temp;
    temp = head;

    if (temp == NULL)
    {
        printf("\nThe list is empty!\n\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("NULL");
        printf("\n");
    }
}

int length(void)
{
    int count = 0;
    struct node *temp;
    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void delete (void)
{
    struct node *temp;
    int loc;
    printf("\nEnter the location to be deleted: \n");
    scanf("%d", &loc);

    if (loc > length())
    {
        printf("\nInvalid Location!\n");
    }

    else if (loc == 1)
    {
        temp = head;
        head = temp->link;
        temp->link = NULL;
        free(temp);
    }

    else
    {
        struct node *p = head, *q;
        int i = 1;
        while (i < loc - 1)
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

int search(void)
{
    int index = 0, key;
    struct node *temp;
    temp = head;

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    while (temp != NULL && temp->data != key)
    {
        index++;
        temp = temp->link;
    }

    if (index >= 0 && temp != NULL)
    {
        printf("Element found at index: %d\n\n", index + 1);
    }
    else
    {
        printf("Element not found in the list!\n\n");
    }
}

void reverse(void)
{
    int i, j, k, temp, len;
    struct node *p, *q;
    len = length();
    i = 0;
    j = len - 1;
    p = q = head;

    while (i < j)
    {
        k = 0;
        while (k < j)
        {
            q = q->link;
            k++;
        }
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        i++;
        j--;
        p = p->link;
        q = head;
    }
}
