#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &heights, int &n, int index, vector<int> &dp, int &k)
{
    if (index >= n - 1)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int ans = INT_MAX;

    for (int i = 1; i <= k; i++)
    {
        int res = solve(heights, n, index + i, dp, k) + abs(heights[index] - heights[i]);
        ans = min(ans, res);
    }

    return ans;
}

int solveUsingTab(int n, vector<int> &heights, int &k)
{
    // Base case Conversion.
    vector<int> dp(n + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        int ans = INT_MAX;

        for (int i = 1; i <= k; i++)
        {
            int res = dp[index + i] + abs(heights[index] - heights[i]);
            ans = min(ans, res);
        }

        dp[index] = ans;
    }

    return dp[0];
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    int k = 2;
    return solveUsingTab(n, heights, k);
}

int main()
{
    vector<int> heights = {4, 8, 3, 10, 4, 4};
    int n = heights.size();

    cout << frogJump(n, heights) << endl;
    return 0;
}