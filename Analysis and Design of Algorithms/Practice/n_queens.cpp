#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

using namespace std;

class NQUEENS
{
public:
    bool isSafe(int row, int col, vector<string> board, int n)
    {
        int temp_r = row;
        int temp_c = col;

        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;

            row--;
            col--;
        }

        row = temp_r;
        col = temp_c;

        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        col = temp_c;
        while (row < n && col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;

            row++;
            col--;
        }

        return true;
    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s('.', n);

        for (int i = 0; i < n; i++)
            board[i] = s;

        solve(0, board, ans, n);
        return ans;
    }
};

void printBoard(vector<string> board, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    NQUEENS n;

    vector<vector<string>> ans = n.solveNQueens(4);

    for (int i = 0; i < ans.size(); i++)
    {
        printBoard(ans[i], 4);
        cout << endl;
    }

    getch();
    return 0;
}