#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char *ch;
    printf("Enter the String: ");
    fgets(ch, 10, stdin);
    int n = strlen(ch);

    printf("\nEnter character you wish to insert: ");
    char chr;
    scanf("%c", &chr);
    printf("\nEnter the position at which you wish to insert the character: ");
    int index, temp = 0;
    scanf("%d", &index);
    for (int i = n; i >= index; i--)
    {
        ch[i + 1] = ch[i];
    }
    ch[index] = chr;
    printf("%s", ch);

    int index2;
    printf("\n\nEnter the location of the element to be deleted: ");
    scanf("%d", &index2);
    for (int i = index2; i <= n; i++)
    {
        ch[i] = ch[i + 1];
    }
    printf("%s", ch);

    getch();
    return 0;
}