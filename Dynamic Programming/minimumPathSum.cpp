#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return grid[i][j];
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = INT_MAX, right = INT_MAX;

    // Right move.
    if (j - 1 >= 0)
    {
        right = grid[i][j] + solve(grid, i, j - 1, dp);
    }

    // Down Move
    if (i - 1 >= 0)
    {
        down = grid[i][j] + solve(grid, i - 1, j, dp);
    }

    return dp[i][j] = min(down, right);
}

int solveUsingTab(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }

            int down = INT_MAX, right = INT_MAX;

            // Right move.
            if (j - 1 >= 0)
            {
                right = grid[i][j] + dp[i][j - 1];
            }

            // Down Move
            if (i - 1 >= 0)
            {
                down = grid[i][j] + dp[i - 1][j];
            }

            dp[i][j] = min(down, right);
        }
    }

    return dp[m - 1][n - 1];
}

int minPathSum(vector<vector<int>> &grid)
{
    return solveUsingTab(grid);
}

int main()
{
}