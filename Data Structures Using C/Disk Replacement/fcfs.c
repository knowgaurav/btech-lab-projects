#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
    int queue[20], n, head, i, j, k, seek = 0, max, diff;
    float avg;
    printf("--- FCFS DISK REPLACEMENT ALGORITHM ---\n\n");
    printf("Enter the max range of disk: ");
    scanf("%d", &max);
    printf("\nEnter the length of the request string: ");
    scanf("%d", &n);
    printf("\nEnter the request string: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &queue[i]);

    printf("\nThe request string is: ");
    for (i = 1; i <= n; i++)
        printf("%d ", queue[i]);

    printf("\n\nEnter the initial head position: ");
    scanf("%d", &head);
    queue[0] = head;
    int h = head;
    printf("\n");

    for (j = 0; j <= n - 1; j++)
    {
        diff = abs(queue[j + 1] - queue[j]);
        seek += diff;
        //h += queue[j];
        //printf("Disk head moves from %d to %d with seek %d\n", queue[j], queue[j + 1], diff);
        printf("Request %d: Disk head moves to %d\n", queue[j], queue[j]);
    }

    printf("\nTotal seek time is: %d", seek);
    // avg = seek / (float)n;

    // printf("\nAverage seek time is: %0.2f", avg);
    getch();
    return 0;
}