#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

class Knapsack
{
    int n, W;
    vector<int> val;
    vector<int> wt;
    int **dp;

public:
    Knapsack(int n, int w)
    {
        this->n = n;
        this->W = w;
        dp = new int *[n + 1];

        for (int i = 0; i < n + 1; i++)
            dp[i] = new int[W + 1];

        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;

        for (int j = 0; j < W + 1; j++)
            dp[0][j] = 0;
    }

    void insertItem(int val, int wt)
    {
        this->val.push_back(val);
        this->wt.push_back(wt);
    }

    int dp_knapsack()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (wt[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                {
                    int inc = dp[i - 1][j - wt[i - 1]] + val[i - 1];
                    int exc = dp[i - 1][j];
                    dp[i][j] = max(inc, exc);
                }
            }
        }

        return dp[n][W];
    }

    void findItems()
    {
        int i = n, j = W;
        vector<int> items;

        while (i > 0 && j > 0)
        {
            if (dp[i][j] != dp[i - 1][j])
            {
                items.push_back(i);
                j = j - wt[i - 1];
                i--;
            }
            else
                i--;
        }

        cout << "\n\nItems included are: " << endl;
        for (int k = 0; k < items.size(); k++)
            cout << items[i] << ", value: " << val[items[k] - 1] << ", wight: " << wt[items[k] - 1] << endl;
    }

    void printMatrix()
    {
        cout << endl;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
                cout << dp[i][j] << "\t";
            cout << endl;
        }
    }
};

int main()
{
    int n = 4, wt = 10;

    Knapsack k(n, wt);

    k.insertItem(10, 5);
    k.insertItem(40, 4);
    k.insertItem(30, 6);
    k.insertItem(50, 3);

    cout << "Max Value: " << k.dp_knapsack();
    k.findItems();

    k.printMatrix();

    getch();
    return 0;
}