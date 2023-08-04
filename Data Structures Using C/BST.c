#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *root = NULL;

struct Node *insert(struct Node *root, int key)
{
    struct Node *head = root;
    struct Node *parent = NULL, *new;

    if (head == NULL)
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        new->data = key;
        new->lchild = new->rchild = NULL;
        head = new;
        return head;
    }
    while (head != NULL)
    {
        parent = head;
        if (key < head->data)
            head = head->lchild;
        else if (key > head->data)
            head = head->rchild;
        else
            return head;
    }
    new = (struct Node *)malloc(sizeof(struct Node));
    new->data = key;
    new->lchild = new->rchild = NULL;
    if (key < parent->data)
        parent->lchild = new;
    else
        parent->rchild = new;

    return root;
}

void inOrder(struct Node *head)
{
    if (head)
    {
        inOrder(head->lchild);
        printf("%d", head->data);
        inOrder(head->rchild);
    }
}

int main()
{
    root = insert(root, 50);
    root = insert(root, 70);

    inOrder(root);

    getch();
    return 0;
}