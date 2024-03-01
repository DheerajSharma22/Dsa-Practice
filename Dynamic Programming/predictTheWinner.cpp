#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int predictTheWinnerHelper(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
{
    if (start == end)
    {
        return nums[start];
    }

    if (dp[start][end] != -1)
        return dp[start][end];

    // Calculating The Difference.
    int diffByStart = nums[start] - predictTheWinnerHelper(nums, start + 1, end, dp);
    int diffByEnd = nums[end] - predictTheWinnerHelper(nums, start, end - 1, dp);

    return dp[start][end] = max(diffByStart, diffByEnd);
}

int predictTheWinnerHelperTab(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][i] = nums[i];

    int i = n;
    for (int start = n - 1; start >= 0; start--)
    {
        for (int end = i; end < n; end++)
        {
            long long diffByStart = nums[start] - dp[start + 1][end];
            long long diffByEnd = nums[end] - dp[start][end - 1];

            dp[start][end] = max(diffByStart, diffByEnd);
        }
        i--;
    }

    return dp[0][n - 1];
}
bool predictTheWinner(vector<int> &nums)
{

    return predictTheWinnerHelperTab(nums) >= 0;
}

int main()
{
}