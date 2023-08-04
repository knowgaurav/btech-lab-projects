#include <stdio.h>
#include <conio.h>
#include <string.h>

void reverseArray(char *str)
{
    int l = 0;
    char *start, *end, temp;
    while (str[l] != '\0')
    {
        l++;
    }
    start = str;
    end = str;
    for (int i = 0; i < l - 1; i++)
        end++;
    //*end = str[l - 1];
    for (int i = 0; i < l / 2; i++)
    {
        temp = *end;
        *end = *start;
        *start = temp;
        start++;
        end--;
    }
}

int main()
{
    char str[15];
    printf("The string is: \n");
    fgets(str, 15, stdin);
    reverseArray(str);
    printf("\nReverse of the string: %s", str);
    getch();
    return 0;
}
