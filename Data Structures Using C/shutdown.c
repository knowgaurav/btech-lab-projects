#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char ch;
    time_t t;
    time(&t);
    printf("Do you wish to shut down your computer? (Y/N): ");
    scanf("%c", &ch);

    if (ch == 'y' || ch == 'Y')
    {
        system("C:\\WINDOWS\\System32\\shutdown /s"); //Windows Shutdown Command
    }
    else
    {
        printf("\n\nOkay, do let me know when you need to shut down.");
        printf("\nTime is: %s", ctime(&t));
    }

    getch();
    return 0;
}