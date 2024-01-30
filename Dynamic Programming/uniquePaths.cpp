#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int m, int n, int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &dp)
{
    if (i == m - 1 || j == n - 1)
        return 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    // Move to right
    if (j + 1 < n && !visited[i][j + 1])
    {
        visited[i][j + 1] = true;
        ans += solve(m, n, i, j + 1, visited, dp);
        visited[i][j + 1] = false;
    }

    // Move to down
    if (i + 1 < m && !visited[i + 1][j])
    {
        visited[i + 1][j] = true;
        ans += solve(m, n, i + 1, j, visited, dp);
        visited[i + 1][j] = false;
    }

    return dp[i][j] = ans;
}
int uniquePaths(int m, int n)
{
    vector<vector<bool>> visited(m, vector<bool>(n, 0));
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m, n, 0, 0, visited, dp);
}

int main()
{
}