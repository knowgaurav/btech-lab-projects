#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void append(int);
int length(void);
void display(void);
void addBegin(void);
void addAt(void);
void delete (void);
int search(void);
//void reverse(void);

void append(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    //printf("Enter the node data: \n");
    //scanf("%d", &temp->data);
    temp->data = data;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
        temp->link = head;
    }
    else
    {
        struct node *p;
        for (p = head->link; p->link != head; p = p->link)
        {
        }
        p->link = temp;
        temp->link = head;
    }
}

void addAtBegin()
{
    struct node *tempHead;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data: \n");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
        temp->link = head;
    }
    else
    {
        tempHead = head;
        temp->link = head;
        while (tempHead->link != head)
        {
            tempHead = tempHead->link;
        }
        tempHead->link = temp;
        head = temp;
    }
}

void addAt()
{
    int loc, len = length();
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the location at which new node to be added: \n");
    scanf("%d", &loc);

    if (loc > len || loc < 1)
    {
        printf("Invalid Location!");
    }
    else
    {
        struct node *p = head, *q;
        printf("Enter the node data: \n");
        scanf("%d", &newNode->data);
        newNode->link = NULL;
        if (loc == 1)
        {
            p = head;
            newNode->link = head;
            while (p->link != head)
            {
                p = p->link;
            }
            p->link = newNode;
            head = newNode;
        }
        else if (loc <= len)
        {
            int i = 1;
            while (i < loc - 1)
            {
                p = p->link;
                i++;
            }
            q = p->link;
            p->link = newNode;
            newNode->link = q;
        }
        /*else if (loc == len)
        {
            int i = 1;
            while(p->link!=head){
                p = p->link;
            }
            q = p->link;
            p->link = newNode;
            newNode->link = q;
        }*/
    }
}

/*void display()
{
    struct node *temp;
    temp = head;
    if (temp == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        do
        {
            printf("%d", temp->data);
            temp = temp->link;
        } while (temp != head);
        /*for (temp = head->link; temp != head; temp = temp->link)
        {
            printf("%d", temp->data);
        }
    }
}*/

void display()
{
    struct node *temp;
    temp = head;
    printf("head -> ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != head);
    printf("head");

    printf("\n\n");

    printf("CLL Node Locations are: ");
    do
    {
        printf("%p -> ", temp->link);
        if (temp->link == head)
        {
            printf("%p -> ", (struct node *)temp->link->link);
        }
        temp = temp->link;
    } while (temp != head);
    printf("#");
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

int search()
{
    int index = 0, key;

    printf("Enter the element to be searched\n");
    scanf("%d", &key);

    struct node *current = head;

    // Iterate till end of list
    do
    {
        // Nothing to look into
        if (current == NULL)
            return -1;

        if (current->data == key)
            return index;

        current = current->link;
        index++;
    } while (current != head);

    // Element not found in list
    return -1;
}

void deleteAtBegin()
{
    struct node *temp, *p;
    p = temp = head;
    head = head->link;
    do
    {
        temp = temp->link;
    } while (temp->link != p);
    temp->link = head;
    free(p);
}

void deleteAtEnd()
{
    struct node *p, *q;
    p = q = head;
    int i = 1, len = length();
    if (len == 1)
    {
        free(head);
    }
    else
    {
        while (i < len - 1)
        {
            p = p->link;
        }
        q = p->link;
        p->link = head;
        q->link = NULL;
        free(q);
    }
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

    if (head == NULL)
    {
        printf("List is empty!");
    }

    else if (loc == 1)
    {
        struct node *r, *s;
        r = s = head;
        head = head->link;
        do
        {
            r = r->link;
        } while (r->link != s);
        r->link = head;
        free(s);
    }

    else
    {
        struct node *p = head, *q;
        int i = 1, len = length();
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

int main()
{
    for (int i = 0; i < 3; i++)
    {
        int k;
        scanf("%d", &k);
        append(k);
    }
    display();

    printf("\n\n");

    delete ();
    display();
    /*
    printf("\n\n");
    
    deleteAtBegin();
    display();
    
    printf("\n\n");
    
    deleteAtEnd();
    display();
    
    printf("\n\n");
    
    deleteAtEnd();
    display();
    
    addAt();
    printf("\n\n");

    display();

    printf("\n\n");

    int index = search();

    if (index == -1)
        printf("not found in list.\n");
    else
        printf("found at %d position.\n", (index + 1));

    //printf("\n\n%d is the length\n\n", length());
    
    addAtBegin();
    addAtBegin();
    display();

    printf("\n\n%d is the length\n\n", length());*/

    getch();
    return 0;
}