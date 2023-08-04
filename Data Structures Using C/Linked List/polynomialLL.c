#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int num;
    int coeff;
    struct node *link;
};

struct node *head1;
struct node *head2;
struct node *addResult;
struct node *subResult;
struct node *multResult;

struct node *createPolyLL(struct node *head);
void display(struct node *head);
struct node *append(struct node *head, int num, int coeff);
struct node *addNodes(struct node *head1, struct node *head2, struct node *head3);
struct node *subNodes(struct node *head1, struct node *head2, struct node *head3);
struct node *multiplyNodes(struct node *head1, struct node *head2, struct node *head3);

void menu()
{
    printf("--- C Program for Polynomial Addition & Subtraction using LL --- \n\n");
    printf("Operations: \n");
    printf("   Press 0 : For Menu\n");
    printf("   Press 1 : To Enter 1st Polynomial Expression\n");
    printf("   Press 2 : To Enter 2nd Polynomial Expression\n");
    printf("   Press 3 : To Perform Addition\n");
    printf("   Press 4 : To Perform Subtraction\n");
    printf("   Press 5 : To Perform Multiplication\n");
    printf("   Press 9 : To Quit\n");
}

int main()
{
    int ch;
    menu();

    while (1)
    {
        printf("\n\n\nEnter a command(0-4 or 9 to quit): ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head1 = createPolyLL(head1);
            printf("\n\n=> First Polynomial Expression is: ");
            display(head1);
            break;
        case 2:
            head2 = createPolyLL(head2);
            printf("\n\n=> Second Polynomial Expression is: ");
            display(head2);
            break;
        case 3:
            addResult = addNodes(head1, head2, addResult);
            printf("\n\n=> Result of Addition Operation: ");
            display(addResult);
            break;
        case 4:
            subResult = subNodes(head1, head2, subResult);
            printf("\n\n=> Result of Subtraction Operation: ");
            display(subResult);
            break;
        case 5:
            multResult = multiplyNodes(head1, head2, multResult);
            printf("\n\n=> Result of Multiplication Operation: ");
            display(multResult);
            break;
        case 9:
            exit(1);

        default:
            printf("Invalid input!\n\n");
            break;
        }
    }

    getch();
    return 0;
}

struct node *createPolyLL(struct node *head)
{
    struct node *newNode, *ptr;
    int n, c, s, i = 1;
    printf("\nHow many variables you wish to insert? Enter: ");
    scanf("%d", &s);
    printf("\nEnter the number: ");
    scanf("%d", &n);
    printf("\nEnter it's coefficient: ");
    scanf("%d", &c);
    if (head == NULL)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->num = n;
        newNode->coeff = c;
        newNode->link = NULL;
        head = newNode;
    }
    else
    {
        struct node *next = head;
        struct node *temp;
        while (next != NULL)
        {
            temp = next->link;
            free(next);
            next = temp;
        }
        head = NULL;
        head = append(head, n, c);
        /*ptr = head;
        while (ptr->link != NULL)
            ptr = ptr->link;
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->num = n;
        newNode->coeff = c;
        newNode->link = NULL;
        ptr->link = newNode;*/
    }
    while (i <= s - 1)
    {
        printf("\nEnter the number: ");
        scanf("%d", &n);
        printf("\nEnter it's coefficient: ");
        scanf("%d", &c);
        i++;
        head = append(head, n, c);
    }

    return head;
}

void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("(%d)X^%d", ptr->num, ptr->coeff);
        if (ptr->link != NULL)
            printf(" + ");
        ptr = ptr->link;
    }
}

struct node *append(struct node *head, int num, int coeff)
{
    struct node *newNode, *ptr;
    if (head == NULL)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->num = num;
        newNode->coeff = coeff;
        newNode->link = NULL;
        head = newNode;
    }
    else
    {
        ptr = head;
        while (ptr->link != NULL)
            ptr = ptr->link;
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->num = num;
        newNode->coeff = coeff;
        newNode->link = NULL;
        ptr->link = newNode;
    }
    return head;
}

struct node *addNodes(struct node *head1, struct node *head2, struct node *head3)
{
    struct node *ptr1, *ptr2;
    ptr1 = head1, ptr2 = head2;
    int addNum, coeff;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->coeff == ptr2->coeff)
        {
            addNum = ptr1->num + ptr2->num;
            head3 = append(head3, addNum, ptr1->coeff);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->coeff > ptr2->coeff)
        {
            head3 = append(head3, ptr1->num, ptr1->coeff);
            ptr1 = ptr1->link;
        }
        else if (ptr1->coeff < ptr2->coeff)
        {
            head3 = append(head3, ptr2->num, ptr2->coeff);
            ptr2 = ptr2->link;
        }
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            head3 = append(head3, ptr2->num, ptr2->coeff);
            ptr2 = ptr2->link;
        }
    }
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            head3 = append(head3, ptr1->num, ptr1->coeff);
            ptr1 = ptr1->link;
        }
    }

    return head3;
}

struct node *subNodes(struct node *head1, struct node *head2, struct node *head3)
{
    struct node *ptr1, *ptr2;
    ptr1 = head1, ptr2 = head2;
    int addNum, coeff;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->coeff == ptr2->coeff)
        {
            addNum = ptr1->num - ptr2->num;
            head3 = append(head3, addNum, ptr1->coeff);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if (ptr1->coeff > ptr2->coeff)
        {
            head3 = append(head3, ptr1->num, ptr1->coeff);
            ptr1 = ptr1->link;
        }
        else if (ptr1->coeff < ptr2->coeff)
        {
            head3 = append(head3, ptr2->num, ptr2->coeff);
            ptr2 = ptr2->link;
        }
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            head3 = append(head3, ptr2->num, ptr2->coeff);
            ptr2 = ptr2->link;
        }
    }
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            head3 = append(head3, ptr1->num, ptr1->coeff);
            ptr1 = ptr1->link;
        }
    }

    return head3;
}

struct node *multiplyNodes(struct node *head1, struct node *head2, struct node *head3)
{
    struct node *ptr1 = head1, *ptr2 = head2;
    int multNum, coeff;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->coeff == ptr2->coeff)
        {
            multNum = ptr1->num * ptr2->num;
            coeff = ptr1->coeff + ptr2->coeff;
            head3 = append(head3, multNum, ptr1->coeff);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        /*else if (ptr1->coeff > ptr2->coeff)
        {
            head3 = append(head3, ptr1->num, ptr1->coeff);
            ptr1 = ptr1->link;
        }
        else if (ptr1->coeff < ptr2->coeff)
        {
            head3 = append(head3, ptr2->num, ptr2->coeff);
            ptr2 = ptr2->link;
        }*/
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            head3 = append(head3, ptr2->num, ptr2->coeff);
            ptr2 = ptr2->link;
        }
    }
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            head3 = append(head3, ptr1->num, ptr1->coeff);
            ptr1 = ptr1->link;
        }
    }
    return head3;
}
