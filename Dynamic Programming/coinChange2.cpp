#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (amount == 0)
        return 1;

    if (dp[index][amount] != -1)
        return dp[index][amount];

    int ans = 0;
    for (int i = index; i >= 0; i--)
    {
        if (coins[i] <= amount)
        {
            ans += solve(i, amount - coins[i], coins, dp);
        }
    }

    return dp[index][amount] = ans;
}

// Tabulation Ans.
int change(int Amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(Amount + 1, 0));

    // Base Case Conversion.
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    // Recurrence Conversion.
    for (int index = 0; index < n; index++)
    {
        for (int amount = 1; amount <= Amount; amount++)
        {
            int ans = 0;
            for (int i = index; i >= 0; i--)
            {
                if (coins[i] <= amount)
                {
                    ans += dp[i][amount - coins[i]];
                }
            }

            dp[index][amount] = ans;
        }
    }
    return dp[n - 1][Amount];
}

int main()
{
}