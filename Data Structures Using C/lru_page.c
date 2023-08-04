#include <stdio.h>
#include <conio.h>
#define MAX 50

int lrureplace(int nof, int *frm, int *lrucal, int *ref, int *recent)
{
    int i, j, temp1, temp2;
    for (i = 0; i < nof; i++)
    {
        temp1 = frm[i];
        lrucal[i] = recent[temp1];
    }
    temp2 = lrucal[0];
    for (j = 1; j < nof; j++)
    {
        if (temp2 > lrucal[j])
            temp2 = lrucal[j];
    }
    for (i = 0; i < nof; i++)
        if (ref[temp2] == frm[i])
            return i;
    return 0;
}

int main()
{
    printf("--- LRU PAGE REPLACEMENT ALGORITHM ---\n\n");
    int i, j, nof, nor, flag = 0, ref[MAX], frm[MAX], pf = 0, victim = -1;
    int recent[10], lrucal[MAX], count = 0;
    printf("Enter no. of Frames: ");
    scanf("%d", &nof);

    printf("\nEnter the length of the reference string: ");
    scanf("%d", &nor);

    printf("\nEnter the reference string: ");
    for (i = 0; i < nor; i++)
        scanf("%d", &ref[i]);

    printf("\nEntered reference string: ");
    for (i = 0; i < nor; i++)
        printf("%d ", ref[i]);

    for (i = 1; i <= nof; i++)
    {
        frm[i] = -1;
        lrucal[i] = 0;
    }
    for (i = 0; i < 10; i++)
        recent[i] = 0;
    printf("\n");
    for (i = 0; i < nor; i++)
    {
        flag = 0;
        printf("\nRequest %d: ", ref[i]);
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
            count++;
            if (count <= nof)
                victim++;
            else
                victim = lrureplace(nof, frm, lrucal, ref, recent);
            pf++;
            frm[victim] = ref[i];
            for (j = 0; j < nof; j++)
                printf("%d ", frm[j]);
        }
        recent[ref[i]] = i;
    }
    printf("\n\nNo.of page faults: %d", pf);

    getch();
    return 0;
}
