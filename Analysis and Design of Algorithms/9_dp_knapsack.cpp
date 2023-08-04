#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

class knapSack
{
    int n, W;
    vector<int> val;
    vector<int> wt;
    int **dp;

public:
    knapSack(int n, int W)
    {
        this->n = n;
        this->W = W;
        dp = new int *[n + 1];
        for (int i = 0; i < n + 1; i++)
            dp[i] = new int[W + 1];

        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0;

        for (int i = 0; i < W + 1; i++)
            dp[0][i] = 0;
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

    void printDPMatrix()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                cout << dp[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void findItems()
    {
        int i = n, k = W;
        vector<int> ans;
        while (i > 0 && k > 0)
        {
            if (dp[i][k] != dp[i - 1][k])
            {
                ans.push_back(i);
                k = k - wt[i - 1];
                i--;
            }
            else
                i--;
        }
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ", Value = " << val[ans[i] - 1] << ", Weight = " << wt[ans[i] - 1] << endl;
    }
};

int main()
{
    int n = 0, W = 0;
    cout << "Enter the number of items and weight of the knapsack: ";
    cin >> n >> W;

    knapSack K(n, W);

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        int val, wt;
        cout << "Enter the value and weight of the item " << i + 1 << ": ";
        cin >> val >> wt;
        K.insertItem(val, wt);
    }

    int ans = K.dp_knapsack();
    cout << "\nMax Value = " << ans;

    cout << "\n\nKnapSack Matrix is: " << endl;
    K.printDPMatrix();

    cout << "\n\nItem Selected in knapsack are: " << endl;
    K.findItems();

    getch();
    return 0;
}