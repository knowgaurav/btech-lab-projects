#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *head = NULL;
int len;

void append(int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (head == NULL)
    {
        head = temp;
        temp->left = head;
    }
    else
    {
        struct node *n = head;
        while (n->right != NULL)
        {
            n = n->right;
        }
        n->right = temp;
        temp->left = n;
    }
}

int length()
{
    int count = 0;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        count += 1;
        temp = temp->right;
    }
    return count;
}

void insertMiddle(int data, int loc)
{
    int i = 1, len = length();
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (loc > len + 1 || loc < 0)
    {
        printf("\nInvalid Location!\n");
    }
    else
    {
        struct node *p = head;
        while (i < loc)
        {
            p = p->right;
            i += 1;
        }
        temp->right = p->right;
        p->right->left = temp;
        temp->left = p;
        p->right = temp;
    }
}

void deletefirst()
{
    struct node *temp = head;
    head = head->right;
    head->left = NULL;
    free(temp);
}

void deleteend()
{
    struct node *temp = head;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    temp->left->right = NULL;
    free(temp);
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d <=> ", temp->data);
        temp = temp->right;
    }
    printf("NULL");

    /*printf("\n\n");

    struct node *temp2 = head;
    printf("%p <=>", head);
    do
    {
        printf("%p <=> ", temp2->right);
        temp2 = temp2->right;
    } while (temp2 != NULL);
    printf("#");*/
}

int main()
{
    append(111);
    append(10);
    append(20);
    append(30);
    append(40);
    append(999);

    //insertMiddle(100, 2);
    printf("Original linked list: \n");
    display();

    printf("\n\nAfter deletion at beginning and at end: \n");

    deletefirst();
    deleteend();

    //printf("%d", length());
    display();

    getch();
    return 0;
}