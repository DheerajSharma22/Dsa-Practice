#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization.
int solve(vector<int> &prices, int i, bool buy, vector<vector<int>> &dp)
{
    if (i == prices.size() - 1)
    {
        return buy ? prices[i] : 0;
    }

    if (dp[i][buy] != -1)
        return dp[i][buy];

    // if already buy then sell stock.
    if (buy)
    {
        // Sell
        int sell = prices[i];

        // Not Sell
        int notSell = solve(prices, i + 1, buy, dp);

        return dp[i][buy] = max(sell, notSell);
    }

    // Buy
    int Buy = solve(prices, i + 1, true, dp) - prices[i];

    // Not Buy
    int notBuy = solve(prices, i + 1, buy, dp);

    return dp[i][buy] = max(Buy, notBuy);
}

// Tabulation.
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int buy = 1; buy >= 0; buy--)
    {
        dp[n - 1][buy] = buy ? prices[n - 1] : 0;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            // if already buy then sell stock.
            if (buy)
            {
                // Sell
                int sell = prices[i];

                // Not Sell
                int notSell = dp[i + 1][buy];

                dp[i][buy] = max(sell, notSell);
            }
            else
            {
                // Buy
                int Buy = dp[i + 1][true] - prices[i];

                // Not Buy
                int notBuy = dp[i + 1][buy];

                dp[i][buy] = max(Buy, notBuy);
            }
        }
    }

    return dp[0][0];
}

// Space Optimized.
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> prev(2, 0);
    vector<int> curr(2, 0);

    for (int buy = 1; buy >= 0; buy--)
    {
        prev[buy] = buy ? prices[n - 1] : 0;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            // if already buy then sell stock.
            if (buy)
            {
                // Sell
                int sell = prices[i];

                // Not Sell
                int notSell = prev[buy];

                curr[buy] = max(sell, notSell);
            }
            else
            {
                // Buy
                int Buy = prev[true] - prices[i];

                // Not Buy
                int notBuy = prev[buy];

                curr[buy] = max(Buy, notBuy);
            }
        }
        prev = curr;
    }

    return prev[0];
}

// Another Approach (Optimized).
int maxProfit(vector<int> &prices)
{
    int mini = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        maxProfit = max(maxProfit, prices[i] - mini);
        mini = min(mini, prices[i]);
    }

    return maxProfit;
}

int main()
{
}