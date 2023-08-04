#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define CAP 5
int stack[CAP];
int top = -1;

int isFull();
int isEmpty();
void push();
int pop();
int peek();
void display();

void menu()
{
    printf("--- C Stacks using Arrays Demonstration --- \n\n");
    printf("Operations: \n");
    printf("   0. Menu\n");
    printf("   1. Push\n");
    printf("   2. Pop\n");
    printf("   3. Display\n");
    printf("   9. Quit\n");
}

int main()
{
    int ch, ele, data;
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
            printf("Enter the data to be inserted into the stack: \n");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            ele = pop();
            if (ele == -1)
            {
                printf("Stack is empty!");
            }
            else
            {
                printf("The element popped.");
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

void push(int element)
{
    if (isFull())
    {
        printf("Stack is Full!");
    }
    else
    {
        top++;
        stack[top] = element;
        printf("Element \"%d\" inserted on to the stack", element);
    }
}

int isFull()
{
    if (top == CAP - 1)
    {
        return 1;
    }
    else
        return 0;
}

int pop()
{
    int ele;
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        ele = stack[top];
        top--;
    }
    return top;
}

int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int peek()
{
    if (isEmpty())
        return 0;
    else
        return stack[top];
}

void display()
{
    if (isEmpty())
    {
        printf("No elements in the stack!");
    }
    else
    {
        printf("\nStacks elements are: \n");
        for (int i = top; i > -1; i--)
        {
            printf("| %d |\n", stack[i]);
        }
        printf("|-----|");
    }
}