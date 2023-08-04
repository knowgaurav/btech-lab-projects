#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

void append(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if (head == NULL)
    {
        head = temp;
        temp->link = head;
    }
    else
    {
        struct node *n;
        n = head;
        do
        {
            n = n->link;
        } while (n->link != head);
        n->link = temp;
        temp->link = head;
    }
}

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
