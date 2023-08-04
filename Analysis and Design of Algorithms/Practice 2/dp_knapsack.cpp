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
    Knapsack(int n, int W)
    {
        this->n = n;
        this->W = W;
        dp = new int *[n + 1];

        for (int i = 0; i <= n; i++)
            dp[i] = new int[W + 1];
    }

    void insertItem(int val, int wt)
    {
        this->val.push_back(val);
        this->wt.push_back(wt);
    }

    int maxValue()
    {
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int j = 0; j <= W; j++)
            dp[0][j] = 0;

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

        cout << "\n\nItems included in the knapsack are: \n";
        for (int i = 0; i < items.size(); i++)
            cout << items[i] << ", Val = " << val[items[i] - 1] << ", Wt = " << wt[items[i] - 1] << endl;
    }
};

int main()
{
    Knapsack k(4, 10);

    k.insertItem(10, 5);
    k.insertItem(40, 4);
    k.insertItem(30, 6);
    k.insertItem(50, 3);

    cout << "Max Value = " << k.maxValue();
    k.findItems();

    getch();
    return 0;
}