#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char binaryTree[10];

int root(char key)
{
    if (binaryTree[0] != '\0')
        printf("Tree already has a root");
    else
        binaryTree[0] = key;
}

int setLeft(char key, int parent)
{
    if (binaryTree[parent] == '\0')
    {
        printf("\n Can't set child at %d, no parent found");
    }
    else
        binaryTree[(parent * 2) + 1] = key;
    return 0;
}

int setRight(char key, int parent)
{
    if (binaryTree[parent] == '\0')
        printf("\n Can't set child at %d, no parent found");
    else
        binaryTree[(2 * parent) + 2] = key;
}

int printBinaryTree()
{
    for (int i = 0; i < sizeof(binaryTree); i++)
    {
        if (binaryTree[i] != '\0')
        {
            printf("%c ", binaryTree[i]);
        }
        else
            printf("# ");
    }
    return 0;
}

void menu()
{
    printf("\nEnter the Operations you wish to perform: \n");
    printf("   0. Menu\n");
    printf("   1. Set Left\n");
    printf("   2. Set Right\n");
    printf("   3. Display\n");
    printf("   9. Quit\n");
}

int main()
{
    int p, ch;
    char r, k1, k2;

    printf("--- C Trees using Arrays Demonstration --- \n\n");
    printf("Enter the Tree Parent: ");
    scanf("%d", &r);
    root(r);
    printf("\nTree Initilized Successfully!\n");
    menu();
    while (1)
    {
        printf("\n\nEnter a command(0-3 or 9 to quit): ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            menu();
            break;
        case 1:
            printf("\nEnter the Parent: ");
            scanf("%d", &p);
            printf("Enter the data to be inserted into the left sub-tree: ");
            scanf("%d", &k1);
            setLeft(k1, p);
            break;

        case 2:
            printf("\nEnter the Parent: ");
            scanf("%d", &p);
            printf("Enter the data to be inserted into the right sub-tree: ");
            scanf("%d", &k2);
            setRight(k2, p);
            break;

        case 3:
            printf("The Binary Tree in Array is: ");
            printBinaryTree();
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