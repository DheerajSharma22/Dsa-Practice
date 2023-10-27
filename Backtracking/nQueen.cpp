#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> leftCheck;
unordered_map<int, bool> upperLeftCheck;
unordered_map<int, bool> bottomLeftCheck;

void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans, int &n)
{
    vector<string> temp;
    for (int i = 0; i < n; i++)
    {
        string str = "";
        for (int j = 0; j < n; j++)
        {
            str.push_back(board[i][j]);
        }

        temp.push_back(str);
    }
    ans.push_back(temp);
}

// This approach takes O(n^2) time ans O(n) space.
bool isSafe(int row, int col, vector<vector<char>> board, int n)
{
    if (leftCheck[row] || upperLeftCheck[n - 1 + col - row] || bottomLeftCheck[row + col])
        return false;

    return true;
}

void solve(vector<vector<char>> board, int col, int n, vector<vector<string>> &ans)
{
    // Base Case
    if (col >= n)
    {
        storeSolution(board, ans, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            leftCheck[row] = true;
            upperLeftCheck[n - 1 + col - row] = true;
            bottomLeftCheck[row + col] = true;
            solve(board, col + 1, n, ans);
            board[row][col] = '.';
            leftCheck[row] = false;
            upperLeftCheck[n - 1 + col - row] = false;
            bottomLeftCheck[row + col] = false;
        }
    }
}

/* This approach takes O(n^3) time.
bool isSafe(int row, int col, vector<vector<char>> &board)
{
    for (int j = col; j >= 0; j--)
        if (board[row][j] == 'Q')
            return false;

    int i = row - 1;
    for (int j = col - 1; j >= 0; j--)
    {
        if (i >= 0 && board[i--][j] == 'Q')
            return false;
    }

    i = row + 1;
    for (int j = col - 1; j >= 0; j--)
    {
        if (i < board.size() && board[i++][j] == 'Q')
            return false;
    }

    return true;
}

void solve(vector<vector<char>> &board, int col, int &n, vector<vector<string>> &ans)
{
    if (col >= n)
    {
        storeSolution(board, ans, n);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, board))
        {
            board[i][col] = 'Q';

            solve(board, col + 1, n, ans);

            board[i][col] = '.';
        }
    }
}
*/

int main()
{
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> ans;

    solve(board, 0, n, ans);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}