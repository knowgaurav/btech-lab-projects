#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *head = NULL;

void append(int data)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *p = head;
        while (p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }
}

void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <=> ", temp->data);
        temp = temp->right;
    }
    printf("NULL");
}

int main()
{
    append(10);
    append(20);
    append(30);
    append(40);

    display();

    getch();
    return 0;
}
