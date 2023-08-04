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

        l1 = s1.length();
        l2 = s2.length();

        dp = new int *[l1 + 1];

        for (int i = 0; i < l1 + 1; i++)
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
            {
                if (s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[l1][l2];
    }

    string printLCS()
    {
        int i = l1, j = l2;
        string lcs = "";
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                lcs.push_back(s1[i - 1]);
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

        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};

int main()
{
    LCS l("ABCBDAB", "BDCABA");

    cout << "Length of LCS = " << l.lcsLength() << endl;
    cout << "LCS is = " << l.printLCS() << endl;
    getch();
    return 0;
}