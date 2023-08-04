#include <stdio.h>
#include <conio.h>
//06
int main()
{
    char *str, nwch;
    //07
    int ind, pos, nw = 0;
    //08
    printf("\nEnter string: ");
    //09
    gets(str);
    //10
    printf("\nEnter character you want to insert: ");
    //11
    nwch = getchar();
    //12
    printf("\nEnter position where you want to insert new character(start with 0): ");
    //13
    scanf("%d", &pos);
    //14
    for (ind = 0; str[ind] != '\0'; ind++) //sorry got a typo here XD
                                           //15
    {
        //16
        if (ind != pos)
        //17
        {
            //18
            str[nw] = str[ind];
            //19
            nw++;
            //20
        }
        else if (ind == pos)
        {
            str[nw] = nwch;
            nw++;
        }
    }
    printf("\n%s", str);
    getch();
    return 0;
}
void insertElement(char *ch, int n, int option)
{
    if (option == 1)
    {
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
    }
    else if (option == 2)
    {
        int index2;
        printf("\n\nEnter the location of the element to be deleted: ");
        scanf("%d", &index2);
        for (int i = index2; i <= n; i++)
        {
            ch[i] = ch[i + 1];
        }
        printf("%s", ch);
    }
    else
    {
        printf("Option not valid");
    }
}