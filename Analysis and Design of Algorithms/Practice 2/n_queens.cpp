#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

class NQueens
{
public:
    bool is_safe(vector<string> board, int row, int col, int n)
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

    void nQueensSolver(vector<vector<string>> &ans, vector<string> &board, int col, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        else
        {
            for (int row = 0; row < n; row++)
            {
                if (is_safe(board, row, col, n))
                {
                    board[row][col] = 'Q';
                    nQueensSolver(ans, board, col + 1, n);
                    board[row][col] = '.';
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for (int i = 0; i < n; i++)
            board.push_back(s);

        nQueensSolver(ans, board, 0, n);

        return ans;
    }
    // bool isSafe(int row, int col, vector<string> board, int n)
    // {
    //     int temp_r = row;
    //     int temp_c = col;

    //     while (row >= 0 && col >= 0)
    //     {
    //         if (board[row][col] == 'Q')
    //             return false;

    //         row--;
    //         col--;
    //     }

    //     row = temp_r;
    //     col = temp_c;

    //     while (col >= 0)
    //     {
    //         if (board[row][col] == 'Q')
    //             return false;

    //         col--;
    //     }

    //     row = temp_r;
    //     col = temp_c;

    //     while (row < n && col >= 0)
    //     {
    //         if (board[row][col] == 'Q')
    //             return false;

    //         row++;
    //         col--;
    //     }
    //     return true;
    // }

    // void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
    // {
    //     if (col == n)
    //     {
    //         ans.push_back(board);
    //         return;
    //     }
    //     else
    //     {
    //         for (int row = 0; row < n; row++)
    //         {
    //             if (isSafe(row, col, board, n))
    //             {
    //                 board[row][col] = 'Q';
    //                 solve(col + 1, ans, board, n);
    //                 board[row][col] = '.';
    //             }
    //         }
    //     }
    // }

    // vector<vector<string>> solveNQueens(int n)
    // {
    //     vector<vector<string>> ans;
    //     vector<string> board;
    //     string s(n, '.');

    //     for (int i = 0; i < n; i++)
    //         board.push_back(s);

    //     solve(0, ans, board, n);
    //     return ans;
    // }
};

void printBoard(vector<string> board, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    NQueens n;
    vector<vector<string>> ans = n.solveNQueens(8);

    cout << "No. of solutions found = " << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++)
        printBoard(ans[i], 8);

    getch();
    return 0;
}