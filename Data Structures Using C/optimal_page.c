#include <stdio.h>
#include <conio.h>
#define MAX 50

int n, page[MAX], f, fr[MAX], i;

void display()
{
    for (i = 0; i < f; i++)
    {
        printf("%d ", fr[i]);
    }
    //printf("\n");
}

void request()
{
    printf("\nEnter no.of frames: ");
    scanf("%d", &f);
    printf("\nEnter length of reference string: ");
    scanf("%d", &n);
    printf("\nEnter the reference string: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &page[i]);
    }
    for (i = 0; i < n; i++)
    {
        fr[i] = -1;
    }
}

void replace()
{
    int j, flag = 0, pf = 0;
    int max, lp[10], index, m;
    for (j = 0; j < f; j++)
    {
        fr[j] = page[j];
        flag = 1;
        pf++;
        printf("\nRequest %d: ", page[j]);
        display();
    }
    for (j = f; j < n; j++)
    {
        flag = 0;
        printf("\nRequest %d: ", page[j]);
        for (i = 0; i < f; i++)
        {
            if (fr[i] == page[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (i = 0; i < f; i++)
                lp[i] = 0;
            for (i = 0; i < f; i++)
            {
                for (m = j + 1; m < n; m++)
                {
                    if (fr[i] == page[m])
                    {
                        lp[i] = m - j;
                        break;
                    }
                }
            }
            max = lp[0];
            index = 0;
            for (i = 0; i < f; i++)
            {
                if (lp[i] == 0)
                {
                    index = i;
                    break;
                }
                else
                {
                    if (max < lp[i])
                    {
                        max = lp[i];
                        index = i;
                    }
                }
            }
            fr[index] = page[j];
            pf++;
            display();
        }
    }

    printf("\n\nNo of Page faults: %d", pf);
}
void main()
{
    printf("--- OPTIMAL PAGE REPLACEMENT ALGORITHM ---\n");
    request();
    replace();

    getch();
}