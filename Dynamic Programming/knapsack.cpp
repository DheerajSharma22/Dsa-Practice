#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization Method.
int solve(int *val, int *wt, int capacity, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (wt[index] <= capacity)
            return val[index];
        return 0;
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    // Include.
    int include = 0;
    if (wt[index] <= capacity)
        include = val[index] + solve(val, wt, capacity - wt[index], index - 1, dp);

    // Exclude.
    int exclude = solve(val, wt, capacity, index - 1, dp);

    return dp[index][capacity] = max(include, exclude);
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    return solve(val, wt, W, n - 1, dp);
}

// Tabulation Method.
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Base Case Conversion.
    for (int i = 0; i <= W; i++)
    {
        if (wt[0] <= i)
            dp[0][i] = val[0];
    }

    // Recurrence Conversion.
    for (int index = 1; index < n; index++)
    {
        for (int capacity = 1; capacity <= W; capacity++)
        {
            int include = 0;
            if (wt[index] <= capacity)
                include = val[index] + dp[index - 1][capacity - wt[index]];

            // Exclude.
            int exclude = dp[index - 1][capacity];

            dp[index][capacity] = max(include, exclude);
        }
    }

    return dp[n - 1][W];
}

// Space Optimized.
int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> prev(W + 1, 0);
    vector<int> curr(W + 1, 0);

    // Base Case Conversion.
    for (int i = 0; i <= W; i++)
    {
        if (wt[0] <= i)
            prev[i] = val[0];
    }

    // Recurrence Conversion.
    for (int index = 1; index < n; index++)
    {
        for (int capacity = 1; capacity <= W; capacity++)
        {
            int include = 0;
            if (wt[index] <= capacity)
                include = val[index] + prev[capacity - wt[index]];

            // Exclude.
            int exclude = prev[capacity];

            curr[capacity] = max(include, exclude);
        }
        prev = curr;
    }

    return prev[W];
}

int main()
{
}