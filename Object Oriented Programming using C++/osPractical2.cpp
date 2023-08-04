#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

#define MAX 30

int main()
{
    int i, j, n, t, bt[MAX], wt[MAX], tat[MAX];
    float awt = 0, atat = 0;
    cout << "--- Shortest Job First (SJF, Non Preemptive) Algorithm in C++ ---\n";
    cout << "\nEnter the number of processes: ";
    cin >> n;
    cout << "\nEnter the burst time of the processes: \n";
    for (i = 0; i < n; i++)
    {
        cout << "Burst Time of process " << i + 1 << ": ";
        cin >> bt[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;
                // t = wt[j];
                // wt[j] = wt[j + 1];
                // wt[j + 1] = t;
            }
        }
    }

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\t";
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
        tat[i] = wt[i] + bt[j];
        awt += wt[i];
        atat += tat[i];
        cout << "\n"
             << i + 1 << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }
    awt /= n;
    atat /= n;
    cout << "\n\nAverage Wating time: ";
    cout << awt;
    cout << "\nAverage Turn around time: ";
    cout << atat;

    getch();
    return 0;
}