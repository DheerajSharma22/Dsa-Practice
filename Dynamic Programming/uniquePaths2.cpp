#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &obstacleGrid, int m, int n, int i, int j, vector<vector<int>> &dp)
{
    if (i == m - 1 && j == n - 1)
    {
        return obstacleGrid[i][j] == 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    // Move to right
    if (j + 1 < n && obstacleGrid[i][j + 1] != 1)
    {
        ans += solve(obstacleGrid, m, n, i, j + 1, dp);
    }

    // Move to down
    if (i + 1 < m && obstacleGrid[i + 1][j] != 1)
    {
        ans += solve(obstacleGrid, m, n, i + 1, j, dp);
    }

    return dp[i][j] = ans;
}

int solveUsingTab(vector<vector<int>> &obstacleGrid, int m, int n)
{
    // Base Case.
    if (obstacleGrid[0][0] == 1)
        return 0;

    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 && j == n - 1 && !obstacleGrid[i][j])
            {
                dp[i][j] = 1;
                continue;
            }

            long long int ans = 0;

            // Move to right
            if (j + 1 < n && obstacleGrid[i][j + 1] != 1)
            {
                ans += dp[i][j + 1];
            }

            // Move to down
            if (i + 1 < m && obstacleGrid[i + 1][j] != 1)
            {
                ans += dp[i + 1][j];
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    return solveUsingTab(obstacleGrid, m, n);
}

int main()
{
}