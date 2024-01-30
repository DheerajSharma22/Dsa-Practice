#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solveUsingTab(vector<int> &arr, int &k, int n, vector<vector<int>> &dp)
{
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

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n, vector<int>(totalSum + 1, 0));

    solveUsingTab(arr, totalSum, n, dp);

    int ans = INT_MAX;

    for (int i = 1; i <= totalSum; i++)
    {
        if (dp[n - 1][i])
        {
            int sum1 = i;
            int sum2 = abs(totalSum - sum1);
            ans = min(ans, abs(sum1 - sum2));
        }
    }

    return ans;
}

int main()
{
}