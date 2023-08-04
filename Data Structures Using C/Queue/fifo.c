#include <stdio.h>
#include <conio.h>

int i, j, nof, nors, flag = 0, ref[50], frm[50], pf = 0, victim = -1;

int main()
{

    printf("\nFIFI PAGE REPLACEMENT ALGORITHM");

    printf("\n Enter no.of frames...."); // Get number of frames from user
    scanf("%d", &nof);
    printf("Enter number of reference string..\n");

    scanf("%d", &nors);

    printf("\n Enter the reference string..");

    for (i = 0; i < nors; i++)

        scanf("%d", &ref[i]);

    printf("\nThe given reference string:");

    for (i = 0; i < nors; i++)

        printf("%4d", ref[i]);

    for (i = 1; i <= nof; i++)

        frm[i] = -1;

    printf("\n");

    for (i = 0; i < nors; i++) // For every page
    {

        flag = 0;
        // Flag to show availability of page in frame
        // Get the availability of required page in frame
        printf("\n\t Reference np%d->\t", ref[i]);

        for (j = 0; j < nof; j++)

        {

            if (frm[j] == ref[i])
            // If page found in frame
            {

                flag = 1; // Set flag to 1, showing that page is available in frame
                break;
                // Break the loop
            }
        }

        if (flag == 0)

        {

            pf++;

            victim++;

            victim = victim % nof;

            frm[victim] = ref[i];

            for (j = 0; j < nof; j++)

                printf("%4d", frm[j]);
        }
    }
    printf("\n\n\t\t No.of pages faults...%d", pf);

    getch();
    return 0;
}