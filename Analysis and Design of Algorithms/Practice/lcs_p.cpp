#include <iostream>
#include <conio.h>
#include <string>
#include <algorithm>

using namespace std;

class LCS
{
    string s1, s2;
    int l1, l2;
    int **dp;

public:
    LCS(string s1, string s2)
    {
        this->s1 = s1;
        this->s2 = s2;
        cout << this->s1 << " " << this->s2;
        l1 = this->s1.length();
        l2 = this->s2.length();
        dp = new int *[l1 + 1];

        for (int i = 0; i <= l1; i++)
            dp[i] = new int[l2 + 1];
    }

    int lcsLength()
    {
        for (int i = 0; i <= l1; i++)
            dp[i][0] = 0;

        for (int j = 0; j <= l2; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

        return dp[l1][l2];
    }

    void printDPMatrix()
    {
        cout << endl;
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
        int i = l1, j = l2;
        string ans = "";

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
        cout << "\nLongest Common Subsequence is: " << ans;
    }
};

int main()
{
    string s1 = "ABCBDAB", s2 = "BDCABA";

    LCS l(s1, s2);

    cout << "\n\nLCS Length = " << l.lcsLength();
    l.printDPMatrix();
    l.printLCS();

    getch();
    return 0;
}