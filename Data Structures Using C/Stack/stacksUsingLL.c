#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;

void push()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter stack data: \n");
    scanf("%d", &temp->data);
    temp->link = top;
    top = temp;
}

int pop()
{
    struct node *temp = top;
    if (temp == NULL)
    {
        return -1;
    }
    else
    {
        int n = temp->data;
        top = top->link;
        free(temp);
        return n;
    }
}

void display(void)
{
    struct node *temp;
    temp = top;

    if (temp == NULL)
    {
        printf("\nThe stack is empty!\n\n");
    }
    else
    {
        printf("\n");
        while (temp != NULL)
        {
            printf("| %d |\n", temp->data);
            temp = temp->link;
        }
        printf("|-----|");
        printf("\n");
    }
}

void menu()
{
    printf("--- C Stacks using Linked List Demonstration --- \n\n");
    printf("Operations: \n");
    printf("   0. Menu\n");
    printf("   1. Push\n");
    printf("   2. Pop\n");
    printf("   3. Display\n");
    printf("   9. Quit\n");
}

int main()
{
    int ch, ele;

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
            push();
            break;

        case 2:
            ele = pop();
            if (ele == -1)
            {
                printf("Stack is empty!");
            }
            else
            {
                printf("The element popped is: %d", ele);
            }
            break;

        case 3:
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
    return 0;
}