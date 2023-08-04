#include <iostream>
#include <conio.h>

using namespace std;

class MCM
{
    int n, *P;
    int **dp;
    int **brackets;

public:
    MCM(int n)
    {
        this->n = n;
        P = new int[n + 1];
        dp = new int *[n + 1];
        brackets = new int *[n + 1];

        for (int i = 0; i < n + 1; i++)
        {
            dp[i] = new int[n + 1];
            brackets[i] = new int[n + 1];
            for (int j = 0; j < n + 1; j++)
            {
                dp[i][j] = 0;
                brackets[i][j] = 0;
            }
        }
    }

    void getMatrices()
    {
        cout << "Enter Matrices Sizes: ";
        for (int i = 0; i <= n; i++)
            cin >> P[i];
    }

    int minCost()
    {
        int i, j, k, L, q;

        for (i = 0; i <= n; i++)
            dp[i][i] = 0;

        for (L = 2; L <= n; L++)
        {
            for (i = 1; i <= n - L + 1; i++)
            {
                j = i + L - 1;
                dp[i][j] = INT_MAX;
                for (k = i; k < j; k++)
                {
                    q = dp[i][k] + dp[k + 1][j] + P[i - 1] * P[k] * P[j];
                    if (q < dp[i][j])
                    {
                        dp[i][j] = q;
                        brackets[i][j] = k;
                    }
                }
            }
        }

        return dp[1][n];
    }

    void printDPMatix()
    {
        cout << endl;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
                cout << dp[i][j] << "\t";
            cout << endl;
        }
    }

    void printBrackets(int i, int j, char &curr_name)
    {
        if (i == j)
        {
            cout << curr_name;
            curr_name++;
        }
        else
        {
            cout << "(";
            printBrackets(i, brackets[i][j], curr_name);
            printBrackets(1 + brackets[i][j], j, curr_name);
            cout << ")";
        }
    }
};

int main()
{
    MCM m(4);

    m.getMatrices();

    cout << "\nMin Cost = " << m.minCost() << endl;

    char name = 'A';
    m.printBrackets(1, 4, name);

    m.printDPMatix();

    getch();
    return 0;
}