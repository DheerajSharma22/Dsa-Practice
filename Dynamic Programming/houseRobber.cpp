#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int index, vector<int> &dp)
{
    if (index >= nums.size())
    {
        return 0;
    }
    if (dp[index] != -1)
        return dp[index];

    // Exclude.
    int exclude = solve(nums, index + 1, dp);

    // Include.
    int include = nums[index] + solve(nums, index + 2, dp);

    return dp[index] = max(include, exclude);
}

int rob(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    int ans = solve(nums, 0, dp);
    return ans;
}

int main()
{
}