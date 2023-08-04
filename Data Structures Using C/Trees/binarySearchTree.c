#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct treeNode
{
    int data;
    struct treeNode *left, *right;
};

struct treeNode *tree1 = NULL;
struct treeNode *tree2 = NULL;

struct treeNode *createTreeNode(int data);
struct treeNode *insertNode(struct treeNode *tree, int data);
void preorderTraversal(struct treeNode *tree);
void inorderTraversal(struct treeNode *tree);
void postorderTraversal(struct treeNode *tree);
int findMin(struct treeNode *tree);
struct treeNode *deleteNode(struct treeNode *tree, int val);
int countNodes(struct treeNode *tree);
int treeHeight(struct treeNode *tree);
void deleteTree(struct treeNode *tree);

void menu()
{
    printf("--- C Binary Search Tree Demonstration --- \n\n");
    printf("\nEnter the Operations you wish to perform: \n");
    printf("   0. Menu\n");
    printf("   1. Insert Node\n");
    printf("   2. Delete Node\n");
    printf("   3. Display (Pre-Order)\n");
    printf("   4. Display (In-Order)\n");
    printf("   5. Display (Post-Order)\n");
    printf("   6. Count Number of Nodes\n");
    printf("   7. Height of Tree\n");
    printf("   8. Delete Tree\n");
    printf("   9. Quit\n");
}

int main()
{
    int ch, data;
    menu();

    while (1)
    {
        printf("\n\nEnter a command(0-8 or 9 to quit): ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            menu();
            break;
        case 1:
            printf("\n\nEnter the data to be inserted: ");
            scanf("%d", &data);
            tree1 = insertNode(tree1, data);
            break;
        case 2:
            printf("\n\nEnter the data to be deleted: ");
            scanf("%d", &data);
            tree1 = deleteNode(tree1, data);
            break;
        case 3:
            printf("\n\nPre-Order Traversal of the Tree: ");
            preorderTraversal(tree1);
            break;
        case 4:
            printf("\n\nIn-Order Traversal of the Tree: ");
            inorderTraversal(tree1);
            break;
        case 5:
            printf("\n\nPost-Order Traversal of the Tree: ");
            postorderTraversal(tree1);
            break;
        case 6:
            printf("\n\nNumber of Nodes in the Tree are: ");
            int count = countNodes(tree1);
            printf("%d", count);
            break;
        case 7:
            printf("\n\nHeight of the Tree is: ");
            int height = countNodes(tree1);
            printf("%d", height);
            break;
        case 8:
            deleteTree(tree1);
            printf("\n\nTree Deleted Successfully!");
            break;
        case 9:
            printf("\n\nTerminating, thank you for using!");
            getch();
            exit(1);
        default:
            printf("Invalid Input \n\n");
        }
        printf("\n\n");
    }
    getch();
    return 0;
}

struct treeNode *createTreeNode(int data)
{
    struct treeNode *node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct treeNode *insertNode(struct treeNode *tree, int data)
{
    struct treeNode *newNode = createTreeNode(data);
    if (tree == NULL)
    {
        tree = newNode;
    }
    else
    {
        struct treeNode *ptr, *parent = NULL;
        ptr = tree;
        while (ptr != NULL)
        {
            parent = ptr;
            if (data < ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if (data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
    return tree;
}

void preorderTraversal(struct treeNode *tree)
{
    if (tree != NULL)
    {
        printf("%d, ", tree->data);
        inorderTraversal(tree->left);
        inorderTraversal(tree->right);
    }
}

void inorderTraversal(struct treeNode *tree)
{
    if (tree != NULL)
    {
        inorderTraversal(tree->left);
        printf("%d, ", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct treeNode *tree)
{
    if (tree != NULL)
    {
        inorderTraversal(tree->left);
        inorderTraversal(tree->right);
        printf("%d, ", tree->data);
    }
}

int findMin(struct treeNode *tree)
{
    //Recursive Approach
    if (tree == NULL || tree->left == NULL)
        return tree->data;
    else
        return findMin(tree->left);

    //Iterative Approach
    // while (tree->left != NULL)
    // {
    //     tree = tree->left;
    // }
    // return tree;
}

struct treeNode *deleteNode(struct treeNode *tree, int val)
{
    if (tree == NULL)
        return NULL;
    if (val < tree->data)
        tree->left = deleteNode(tree->left, val);
    else if (val > tree->data)
        tree->right = deleteNode(tree->right, val);
    else
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            free(tree);
            return NULL;
        }
        else if (tree->left == NULL && tree->right != NULL)
        {
            struct treeNode *temp = tree->right;
            free(tree);
            return temp;
        }
        else if (tree->left != NULL && tree->right == NULL)
        {
            struct treeNode *temp = tree->left;
            free(tree);
            return temp;
        }
        else
        {
            int rightMin = findMin(tree->right);
            tree->data = rightMin;
            tree->right = deleteNode(tree->right, rightMin);
        }
    }
    return tree;
}

int countNodes(struct treeNode *tree)
{
    if (tree == NULL)
        return 0;
    else
        return (countNodes(tree->left) + countNodes(tree->right) + 1);

    //Alternative
    //return tree? (1+countNodes(tree->left)+countNodes(tree->right)): 0;
}

int treeHeight(struct treeNode *tree)
{
    if (tree == NULL)
        return 0;
    int leftHeight = treeHeight(tree->left);
    int rightHeight = treeHeight(tree->right);
    int h = 0;
    if (leftHeight > rightHeight)
        h = 1 + leftHeight;
    else
        h = 1 + rightHeight;

    return h;
}

void deleteTree(struct treeNode *tree)
{
    if (tree != NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}