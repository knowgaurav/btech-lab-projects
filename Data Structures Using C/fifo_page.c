#include <stdio.h>
#include <conio.h>
#define MAX 50

int main()
{
    printf("--- FIFO PAGE REPLACEMENT ALGORITHM ---\n\n");

    int i, j, nof, nors, flag = 0, ref[MAX], frm[MAX], pf = 0, victim = -1;

    printf("Enter the no. of frames: ");
    scanf("%d", &nof);
    printf("\nEnter the length of reference string: ");
    scanf("%d", &nors);
    printf("\nEnter the reference string: ");
    for (i = 0; i < nors; i++)
        scanf("%d", &ref[i]);

    printf("\nThe given reference string: ");
    for (i = 0; i < nors; i++)
        printf("%d ", ref[i]);

    for (i = 0; i < nof; i++)
        frm[i] = -1;

    printf("\n");

    for (i = 0; i < nors; i++)
    {
        flag = 0;
        printf("\n Request %d: ", ref[i]);
        for (j = 0; j < nof; j++)
        {
            if (frm[j] == ref[i])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            pf++;
            victim++;
            victim %= nof;
            frm[victim] = ref[i];

            for (j = 0; j < nof; j++)
            {
                printf("%d ", frm[j]);
            }
        }
    }

    printf("\n\nNo.of pages faults: %d", pf);

    getch();
    return 0;
}