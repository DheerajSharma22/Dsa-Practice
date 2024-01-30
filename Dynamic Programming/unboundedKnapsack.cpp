#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization.
int solve(vector<int> &profit, vector<int> &weight, int capacity, int index, vector<vector<int>> &dp)
{
    if (capacity == 0)
        return 0;

    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int exclude = 0;
    if (index > 0)
        exclude = solve(profit, weight, capacity, index - 1, dp);

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = profit[index] + solve(profit, weight, capacity - weight[index], index, dp);
    }

    return dp[index][capacity] = max(include, exclude);
}

// Tabulation.
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int index = 0; index < n; index++)
    {
        for (int capacity = 0; capacity <= w; capacity++)
        {
            int exclude = 0;
            if (index > 0)
                exclude = dp[index - 1][capacity];

            int include = 0;
            if (weight[index] <= capacity)
            {
                include = profit[index] + dp[index][capacity - weight[index]];
            }

            dp[index][capacity] = max(include, exclude);
        }
    }

    int ans = dp[n - 1][w];
    return ans == INT_MIN ? 0 : ans;
}

// Space Optimized.
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0);
    vector<int> curr(w + 1, 0);

    for (int index = 0; index < n; index++)
    {
        for (int capacity = 0; capacity <= w; capacity++)
        {
            int exclude = 0;
            if (index > 0)
                exclude = prev[capacity];

            int include = 0;
            if (weight[index] <= capacity)
            {
                include = profit[index] + curr[capacity - weight[index]];
            }

            curr[capacity] = max(include, exclude);
        }
        prev = curr;
    }

    int ans = prev[w];
    return ans == INT_MIN ? 0 : ans;
}

int main()
{
}