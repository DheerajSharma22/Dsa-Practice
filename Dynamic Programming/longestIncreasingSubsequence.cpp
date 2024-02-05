#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization.
int solve(vector<int> &nums, int index, int prev, vector<vector<int>> &dp)
{
    if (index >= nums.size())
        return 0;

    if (dp[index][prev + 1] != -1)
        return dp[index][prev + 1];

    // Exclude
    int exclude = solve(nums, index + 1, prev, dp);

    // Include
    int include = 0;
    if (prev == -1 || nums[index] > nums[prev])
    {
        include = 1 + solve(nums, index + 1, index, dp);
    }

    return dp[index][prev + 1] = max(include, exclude);
}

// Tabulation.
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 10, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int prev = index - 1; prev >= -1; prev--)
        {
            // Exclude
            int exclude = dp[index + 1][prev + 1];

            // Include
            int include = 0;
            if (prev == -1 || nums[index] > nums[prev])
            {
                include = 1 + dp[index + 1][index + 1];
            }

            dp[index][prev + 1] = max(include, exclude);
        }
    }

    return dp[0][0];
}

// Space Optimization.
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    vector<int> prevArr(n + 1, 0);
    vector<int> currArr(n + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int prev = index - 1; prev >= -1; prev--)
        {
            // Exclude
            int exclude = prevArr[prev + 1];

            // Include
            int include = 0;
            if (prev == -1 || nums[index] > nums[prev])
            {
                include = 1 + prevArr[index + 1];
            }

            currArr[prev + 1] = max(include, exclude);
        }
        prevArr = currArr;
    }

    return prevArr[0];
} 

int main()
{
}