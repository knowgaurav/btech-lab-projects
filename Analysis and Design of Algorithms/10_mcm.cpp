#include <iostream>
#include <conio.h>
#include <map>
#include <vector>

using namespace std;

class mcm
{
    int *arr;
    int **dp;
    int **bracket;
    int num;
    map<vector<int>, int> mp;

public:
    mcm(int n, int arr[])
    {
        this->num = n;
        this->arr = arr;
        dp = new int *[n];
        bracket = new int *[n];
        for (int i = 0; i < n; i++)
        {
            dp[i] = new int[n];
            bracket[i] = new int[n];
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = 0;
                bracket[i][j] = 0;
            }
    }

    void getMatrices()
    {
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
    }

    int minCost()
    {
        int i, j, k, L, q;

        for (i = 1; i < num; i++)
            dp[i][i] = 0;

        for (L = 2; L < num; L++)
        {
            for (i = 1; i < num - L + 1; i++)
            {
                j = i + L - 1;
                dp[i][j] = INT_MAX;
                for (k = i; k <= j - 1; k++)
                {
                    q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if (q < dp[i][j])
                    {
                        dp[i][j] = q;
                        bracket[i][j] = k;
                    }
                }
            }
        }
        return dp[1][num - 1];
    }

    int minCost_R(int i, int j)
    {
        if (i + 1 == j)
            return 0;

        if (mp.find({i, j}) != mp.end())
            return mp[{i, j}];

        int res = INT_MAX;
        for (int k = i + 1; k < j; k++)
            res = min(res, minCost_R(i, k) + minCost_R(k, j) + (arr[i] * arr[j] * arr[k]));

        mp[{i, j}] = res;
        return res;
    }

    void printDPMatrix()
    {
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                cout << dp[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void printBracketsMatrixChain(int i, int j, char &cur_name)
    {
        if (i == j)
        {
            cout << cur_name;
            cur_name++;
        }
        else
        {
            cout << "(";
            printBracketsMatrixChain(i, bracket[i][j], cur_name);
            printBracketsMatrixChain(bracket[i][j] + 1, j, cur_name);
            cout << ")";
        }
    }

    void printMap()
    {
        for (auto it : mp)
            cout << it.first[0] << ", " << it.first[1] << " = " << it.second << endl;
    }
};

int main()
{
    int n;
    int *arr = new int[n];
    cout << "Enter the number of matrices: ";
    cin >> n;

    cout << "\nEnter Matrices sizes: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mcm M(n, arr);

    cout << "\nMinimum Cost to multiply given " << n << " matrices is: ";
    cout << M.minCost() << endl;

    char name = 'A';
    cout << "\nOptimal Parenthesization is : ";
    M.printBracketsMatrixChain(1, n - 1, name);
    cout << endl;

    cout << "\nDP Matrix is: " << endl;
    M.printDPMatrix();

    getch();
    return 0;
}