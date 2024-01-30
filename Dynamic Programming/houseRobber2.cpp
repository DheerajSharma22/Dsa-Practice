#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization.
int solve(vector<int> &nums, int index, vector<int> &dp, int n)
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index] != -1)
        return dp[index];

    // Exclude.
    int exclude = solve(nums, index + 1, dp, n);

    // Include.
    int include = nums[index] + solve(nums, index + 2, dp, n);

    return dp[index] = max(include, exclude);
}

// Space Optimised
int solve(vector<int> &nums, int start, int end)
{
    int prev2 = 0;
    int prev1 = nums[start];

    for (int i = start + 1; i < end; i++)
    {
        // Exclude.
        int exclude = prev1;

        // Include.
        int include = nums[i] + prev2;

        int curr = max(include, exclude);

        prev2 = prev1;
        prev1 = curr;
    }

    return max(prev1, prev2);
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    return max(solve(nums, 1, n), solve(nums, 0, n - 1));
}


int main()
{
}