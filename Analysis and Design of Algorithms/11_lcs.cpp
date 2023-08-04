#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>

using namespace std;

class lcs
{
    string s1, s2;
    int l1, l2;
    int **dp;

public:
    lcs(string s1, string s2)
    {
        this->s1 = s1;
        this->s2 = s2;

        l1 = this->s1.length(), l2 = this->s2.length();

        dp = new int *[l1 + 1];
        for (int i = 0; i < l1 + 1; i++)
        {
            dp[i] = new int[l2 + 1];
        }
    }

    int commonSubsequence()
    {
        for (int i = 0; i < l1 + 1; i++)
            dp[i][0] = 0;

        for (int j = 0; j < l2 + 1; j++)
            dp[0][j] = 0;

        for (int i = 1; i < l1 + 1; i++)
        {
            for (int j = 1; j < l2 + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[l1][l2];
    }

    void printDPMatrix()
    {
        for (int i = 0; i <= l1; i++)
        {
            for (int j = 0; j <= l2; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printLCS()
    {
        string ans = "";
        int i = l1, j = l2;

        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans.push_back(s1[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
        reverse(ans.begin(), ans.end());

        cout << "Longest Common Subsequence is: " << ans;
    }
};

int main()
{
    string s1, s2;
    cout << "Enter two strings: " << endl;
    cin >> s1;
    cin >> s2;

    lcs l(s1, s2);

    cout << "\nSize of the longest common subsequence is: " << l.commonSubsequence() << endl
         << endl;

    l.printLCS();

    cout << endl
         << endl;
    cout << "DP Matrix is: " << endl;
    l.printDPMatrix();

    getch();
    return 0;
}