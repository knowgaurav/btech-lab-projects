#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void copystr(char str[100], char copy[100]);
void print_ops();
void insertion(char str[100], int *len);
void deletion(char str[100], int *len);
void traversal(char str[100], int len);

int main()
{
    printf("This is a program to perform various operations on the string\n\n");
    char str[100], copy[100];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    int loop = 1;
    int choice;
    do
    {
        print_ops();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Oringinal String is:\n");
            puts(str);
            copystr(str, copy);
        }
        else if (choice == 2)
        {
            printf("String before insertion:\n");
            traversal(str, len);
            insertion(str, &len);
            printf("String after insertion is:\n");
            traversal(str, len);
        }
        else if (choice == 3)
        {
            printf("String before deletion is:\n");
            traversal(str, len);
            deletion(str, &len);
            printf("String after deletion is:\n");
            traversal(str, len);
        }
        else if (choice == 4)
        {
            printf("The traversed array is:\n");
            traversal(str, len);
        }
        else
            break;
    } while (loop);

    getch();
}

void print_ops()
{
    printf("Enter 1 to make a copy of the string\nEnter 2 to insert a character in the String\nEnter 3 to delete a character from the string\nEnter 4 to traverse the string\nEnter any other number to exit\n");
}

void copystr(char str[100], char copy[100])
{
    strcpy(copy, str);
    printf("The copied string is:\n");
    puts(copy);
}

void insertion(char str[100], int *len)
{
    int pos;
    char x;
    printf("Enter the element to insert: ");
    scanf(" %c", &x);
    printf("Enter the position at which you want to perform insertion: ");
    scanf("%d", &pos);
    if (*len + 1 < 50)
    {
        for (int i = (*len - 1); i >= pos; i--)
        {
            str[i + 1] = str[i];
        }
        str[pos] = x;
        (*len)++;
        printf("Insertion operation successful\n");
    }
    else
        printf("There no more space in the given array\n");
}

void traversal(char str[100], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void deletion(char str[100], int *len)
{
    printf("Enter the position at which you want to perform deletion: ");
    int pos;
    scanf("%d", &pos);
    if (pos <= *len - 1)
    {
        for (int i = pos; i < *len - 1; i++)
        {
            str[i] = str[i + 1];
        }
        (*len)--;
        printf("Deletion operation successful\n");
    }
    else
    {
        printf("Deletion at a position greater than length is not possible\n");
    }
}