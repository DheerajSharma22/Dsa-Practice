#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &triangle, int &n, int i, int j, vector<vector<int>> &dp)
{
    int m = i + 1;
    if (i >= n || j >= m)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];

    int op1 = triangle[i][j] + solve(triangle, n, i + 1, j, dp);

    int op2 = triangle[i][j] + solve(triangle, n, i + 1, j + 1, dp);

    return dp[i][j] = min(op1, op2);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n + 10, vector<int>(n + 10, 1e9));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int op1 = triangle[i][j] + dp[i + 1][j];
            int op2 = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(op1, op2);
        }
    }

    return dp[0][0] - 1e9;
}

/* Space Optimization

int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<int> curr(n+10, 1e9);
        vector<int> next(n+10, 1e9);

        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int op1 = triangle[i][j] + curr[j];
                int op2 = triangle[i][j] + curr[j+1];

                next[j] = min(op1, op2);
            }
            curr = next;
        }

        return next[0] - 1e9;
    }
*/

int main()
{
}
