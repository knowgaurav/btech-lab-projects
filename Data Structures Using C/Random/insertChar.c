#include <stdio.h>
#include <conio.h>

int main()
{
    char *ch;
    printf("Enter the String: ");
    gets(ch);
    printf("\nEnter character you wish to insert: ");
    char chr;
    scanf("%c", &chr);
    printf("\nEnter the position at which you wish to insert the character: ");
    int index, temp = 0;
    scanf("%d", &index);
    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (i != index)
        {
            ch[temp] = ch[i];
            temp++;
        }
        else if (i == index)
        {
            ch[temp] = chr;
            temp++;
        }
    }
    printf("%s", ch);
    getch();
    return 0;
}