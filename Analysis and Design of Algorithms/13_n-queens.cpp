#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

class nQueen
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

        col = temp_c;
        row = temp_r;
        while (col >= 0)
        {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = temp_r;
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

    void solve(int r, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (r == n)
        {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++)
        {
            if (isSafe(r, c, board, n))
            {
                board[r][c] = 'Q';
                solve(r + 1, board, ans, n);
                board[r][c] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
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
    nQueen n;
    int size;
    cout << "Enter the size of the board: ";
    cin >> size;

    vector<vector<string>> ans = n.solveNQueens(size);

    cout << "\nTotal number of solutions are: " << ans.size() << endl
         << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        printBoard(ans[i], size);
        cout << endl;
    }
}