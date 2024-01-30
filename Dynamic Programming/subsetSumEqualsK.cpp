#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Subset S
bool solve(vector<int> &arr, int target, int index, vector<vector<int>> &dp)
{
    if (target < 0)
        return false;
    if (target == 0)
        return true;

    if (index == 0)
    {
        if (target - arr[index] == 0)
            return true;
        return false;
    }

    if (dp[index][target] != -1)
        return dp[index][target];

    // Exclude case.
    bool exclude = solve(arr, target, index - 1, dp);

    // Include case.
    bool include = solve(arr, target - arr[index], index - 1, dp);

    return dp[index][target] = include || exclude;
}

// Tabulation
bool solveUsingTab(vector<int> &arr, int &k, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base Case Conversion
    for (int index = 0; index < n; index++)
    {
        dp[index][0] = true;
    }
    if (arr[0] < k)
        dp[0][arr[0]] = true;

    // Convert Recurrence.
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            // Exclude case.
            bool exclude = dp[index - 1][target];

            // Include case.
            bool include = false;
            if (arr[index] <= target)
            {
                include = dp[index - 1][target - arr[index]];
            }

            dp[index][target] = include || exclude;
        }
    }

    return dp[n - 1][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return solveUsingTab(arr, k, n);
}

int main()
{
}