#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &arr, int row, int col, vector<vector<int>> &dp)
{
    if (row >= arr.size() || col >= arr[0].size())
        return 1e9;

    if (dp[row][col] != -1)
        return dp[row][col];

    int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    if (col - 1 >= 0)
        op1 = arr[row][col] + solve(arr, row + 1, col - 1, dp);

    op2 = arr[row][col] + solve(arr, row + 1, col, dp);

    if (col + 1 < arr[0].size())
        op3 = arr[row][col] + solve(arr, row + 1, col + 1, dp);

    return dp[row][col] = min(op1, min(op2, op3));
}

int solveUsingTabulation(vector<vector<int>> &Matrix, int &N, int &startCol, vector<vector<int>> &dp)
{
    for (int i = 0; i < N; i++)
        dp[N - 1][i] = Matrix[N - 1][i];

    for (int row = N - 2; row >= 0; row--)
    {
        for (int col = N - 1; col >= startCol; col--)
        {
            // Bottom Left
            int bottomLeft = Matrix[row][col];
            if (col > 0)
            {
                bottomLeft += dp[row + 1][col - 1];
            }
            else
                bottomLeft = 1e9;

            // Bottom
            int bottom = Matrix[row][col];
            if (col < N)
            {
                bottom += dp[row + 1][col];
            }
            else
                bottom = 1e9;

            // Bottom Right
            int bottomRight = Matrix[row][col];
            if (col < N - 1)
            {
                bottomRight += dp[row + 1][col + 1];
            }
            else
                bottomRight = 1e9;

            dp[row][col] = min(bottom, min(bottomLeft, bottomRight));
        }
    }
    return dp[0][startCol];
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int mini = solveUsingTabulation(matrix, n, i, dp);
        ans = min(mini, ans);
    }

    return ans;
}

int main()
{
}