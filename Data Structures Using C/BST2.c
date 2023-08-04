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
    struct Node *temp, *parent, *ptr;
    ptr = root;
    parent = NULL;

    while (ptr != NULL)
    {
        parent = ptr;
        if (key < ptr->data)
            ptr = ptr->lchild;
        else if (key > ptr->data)
            ptr = ptr->rchild;
        else
        {
            printf("Duplicate Key!\n");
            return root;
        }
    }

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = key;
    temp->lchild = NULL;
    temp->rchild = NULL;

    if (parent == NULL)
    {
        root = temp;
    }
    else if (key < parent->data)
    {
        parent->lchild = temp;
    }
    else
    {
        parent->rchild = temp;
    }
    return root;
}

struct Node *delete (struct Node *root, int dkey)
{
    struct Node *par, *ptr, *child, *succ, *parsucc;
    ptr = root;
    par = NULL;

    while (ptr != NULL)
    {
        if (dkey == ptr->data)
            break;
        par = ptr;

        if (dkey < ptr->data)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }

    if (ptr == NULL)
    {
        printf("\nGiven delete key is not present!\n");
        return root;
    }
    if (ptr->lchild != NULL && ptr->rchild != NULL)
    {
        parsucc = par;
        succ = ptr->rchild;
        while (succ->lchild != NULL)
        {
            parsucc = succ;
            succ = succ->lchild;
        }
        ptr->data = succ->data;
        ptr = succ;
        par = parsucc;
    }

    if (ptr->lchild != NULL)
    {
        child = ptr->lchild;
    }
    else
    {
        child = ptr->rchild;
    }
    if (par == NULL)
    {
        root = child;
    }
    else if (ptr == par->lchild)
    {
        par->lchild = child;
    }
    else
    {
        par->rchild = child;
    }
    free(ptr);
    return root;
}

void inOrder(struct Node *head)
{
    if (head)
    {
        inOrder(head->lchild);
        printf("%d : ", head->data);
        inOrder(head->rchild);
    }
}

void r_upper_half(int a[10], int n)
{
    int b[10][10], i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (i + j <= n - 1)
                b[i][j] = a[j];
            else
                b[i][j] = 0;
    }
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d", b[i][j]);
    }
}

void SwapArray(int A[], int N)
{
    int i, j, temp;
    /* cout<<”\nThe elements before doing the desired alterations…”;
for(i=0;i<N;i++)
cout<<A[i]<<’\t’; */
    for (i = 0; i < N - 1; i += 2)
    {
        temp = A[i];
        A[i] = A[i + 1];
        A[i + 1] = temp;
    }
    /* cout<<”\nThe elements after completed the desired
alterations…”;
for(i=0;i<N;i++)
cout<<A[i]<<’\t’; */
}

void menu()
{
    printf("--- C Binary Search Tree Demonstration --- \n\n");
    printf("Operations: \n");
    printf("   0. Menu\n");
    printf("   1. Insert\n");
    printf("   2. Delete\n");
    printf("   3. Display (Inorder)\n");
    printf("   9. Quit\n");
}

int main()
{
    int ch, ele, dele;

    printf("Enter the root of the BST: ");
    scanf("%d", &ele);
    root = insert(root, ele);
    printf("\nBST initialized successfully!\n\n");

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
            printf("\nEnter the key to be inserted: ");
            scanf("%d", &ele);
            root = insert(root, ele);
            break;
        case 2:
            printf("\nEnter the key to be deleted: ");
            scanf("%d", &dele);
            root = delete (root, dele);
            break;
        case 3:
            printf("\nBST Inorder Display: ");
            inOrder(root);
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