#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

class MCM
{
    int n;
    vector<int> P;
    int **dp, **brackets;

public:
    MCM(int num)
    {
        n = num;
        dp = new int *[num + 1];
        brackets = new int *[num + 1];

        for (int i = 0; i < num + 1; i++)
        {
            dp[i] = new int[num + 1];
            brackets[i] = new int[num + 1];
            for (int j = 0; j < num + 1; j++)
                dp[i][j] = 0;
        }
    }

    void getMatrices(int i)
    {
        P.push_back(i);
    }

    int minCost()
    {
        int i, j, k, L, q;

        for (i = 1; i <= n; i++)
            dp[i][i] = 0;

        for (L = 2; L <= n; L++)
        {
            for (int i = 1; i <= n - L + 1; i++)
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
            printBrackets(brackets[i][j] + 1, j, curr_name);
            cout << ")";
        }
    }

    void printMatrix()
    {
        cout << endl;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << dp[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    MCM m(4);

    m.getMatrices(2);
    m.getMatrices(3);
    m.getMatrices(6);
    m.getMatrices(4);
    m.getMatrices(5);

    cout << "Cost = " << m.minCost() << endl;
    char name = 'A';
    m.printBrackets(1, 4, name);

    m.printMatrix();

    getch();
    return 0;
}