#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization.
int solve(vector<vector<int>> &grid, int row, int col1, int col2, vector<vector<vector<int>>> &dp)
{
    if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
    {
        return -1e9;
    }

    if (row == grid.size() - 1)
    {
        if (col1 == col2)
            return grid[row][col1];
        return grid[row][col1] + grid[row][col2];
    }

    if (dp[row][col1][col2] != -1)
        return dp[row][col1][col2];

    int maxi = 0;

    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (col1 == col2)
            {
                int res = grid[row][col1] + solve(grid, row + 1, col1 + i, col2 + j, dp);
                maxi = max(res, maxi);
            }
            else
            {
                int res = grid[row][col1] + grid[row][col2] + solve(grid, row + 1, col1 + i, col2 + j, dp);
                maxi = max(res, maxi);
            }
        }
    }

    return dp[row][col1][col2] = maxi;
}

// Tabulation.
int solveUsingTab(vector<vector<int>> &grid, int &N, int &M)
{
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(M, -1)));

    // Base Case Conversion.
    for (int col1 = 0; col1 < M; col1++)
    {
        for (int col2 = 0; col2 < M; col2++)
        {
            if (col1 == col2)
                dp[N - 1][col1][col2] = grid[N - 1][col1];
            else
                dp[N - 1][col1][col2] = grid[N - 1][col1] + grid[N - 1][col2];
        }
    }

    // Converting recurrence.
    for (int row = N - 2; row >= 0; row--)
    {
        for (int col1 = M - 1; col1 >= 0; col1--)
        {
            for (int col2 = 0; col2 < M; col2++)
            {

                int maxi = 0;
                for (int i = -1; i < 2; i++)
                {
                    for (int j = -1; j < 2; j++)
                    {
                        int value = 0;
                        if (col1 == col2)
                            value = grid[row][col1];
                        else
                            value = grid[row][col1] + grid[row][col2];

                        if (col1 + i >= 0 && col2 + j >= 0 && col1 + i < M && col2 + j < M)
                        {
                            value += dp[row + 1][col1 + i][col2 + j];
                        }
                        else
                        {
                            value += -1e8;
                        }

                        maxi = max(maxi, value);
                    }
                }

                dp[row][col1][col2] = maxi;
            }
        }
    }

    return dp[0][0][M - 1];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int ans = solveUsingTab(grid, n, m);
    return ans;
}

int main()
{
}