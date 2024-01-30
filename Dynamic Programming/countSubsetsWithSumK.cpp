#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

// MEMOIZATION.
int solve(vector<int> &arr, int k, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (k == 0 && arr[0] == 0)
            return 2;
        if (k == 0 || k == arr[0])
            return 1;
        return 0;
    }

    if (dp[index][k] != -1)
        return dp[index][k];

    int ans = 0;

    if (arr[index] <= k)
    {
        ans += solve(arr, k - arr[index], index - 1, dp);
    }

    // If we do not take the ith element.
    ans += solve(arr, k, index - 1, dp);

    return dp[index][k] = ans % mod;
}


// Tabulation.
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, 0));

    // Base Case Conversion.
    for (int target = 0; target <= k; target++)
    {
        if (target == 0 && arr[0] == 0)
            dp[0][0] = 2;
        else if (target == 0 || target == arr[0])
            dp[0][target] = 1;
        else
            dp[0][target] = 0;
    }

    // Converting Recurrence.
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= k; target++)
        {
            int ans = 0;

            if (arr[index] <= target)
            {
                ans += dp[index-1][target - arr[index]];
            }

            // If we do not take the ith element.
            ans += dp[index-1][target];

            dp[index][target] = ans % mod;
        }
    }

    return dp[n-1][k];
}


// Space Optimized.
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> prev(k + 1, 0);
    vector<int> curr(k + 1, 0);

    // Base Case Conversion.
    for (int target = 0; target <= k; target++)
    {
        if (target == 0 && arr[0] == 0)
            prev[0] = 2;
        else if (target == 0 || target == arr[0])
            prev[target] = 1;
        else
            prev[target] = 0;
    }

    // Converting Recurrence.
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= k; target++)
        {
            int ans = 0;

            if (arr[index] <= target)
            {
                ans += prev[target - arr[index]];
            }

            // If we do not take the ith element.
            ans += prev[target];

            curr[target] = ans % mod;
        }
        prev = curr;
    }

    return prev[k];
}

int main()
{
}