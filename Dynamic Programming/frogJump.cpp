#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &heights, int &n, int index, vector<int> &dp)
{
    if (index >= n - 1)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int ans = 0;

    int stepOf1 = solve(heights, n, index + 1, dp) + abs(heights[index] - heights[index + 1]);
    int stepOf2 = solve(heights, n, index + 2, dp) + abs(heights[index] - heights[index + 2]);

    return dp[index] = min(stepOf1, stepOf2);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return solve(heights, n, 0, dp);
}

int main()
{
    vector<int> heights = {4, 8, 3, 10, 4, 4};
    int n = heights.size();

    cout << frogJump(n, heights) << endl;
    return 0;
}
