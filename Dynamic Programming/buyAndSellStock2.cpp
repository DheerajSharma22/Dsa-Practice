#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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
        int sell = prices[i] + solve(prices, i, !buy, dp);

        // Not Sell
        int notSell = solve(prices, i + 1, buy, dp);

        return dp[i][buy] = max(sell, notSell);
    }

    // Buy
    int Buy = solve(prices, i + 1, !buy, dp) - prices[i];

    // Not Buy
    int notBuy = solve(prices, i + 1, buy, dp);

    return dp[i][buy] = max(Buy, notBuy);
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            // if already buy then sell stock.
            if (buy)
            {
                // Sell
                int sell = prices[i] + dp[i + 1][0];

                // Not Sell
                int notSell = dp[i + 1][1];

                dp[i][buy] = max(sell, notSell);
            }
            else
            {
                // Buy
                int Buy = dp[i + 1][1] - prices[i];

                // Not Buy
                int notBuy = dp[i + 1][0];

                dp[i][buy] = max(Buy, notBuy);
            }
        }
    }

    return dp[0][0];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> prev(2, 0);
    vector<int> curr(2, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 1; buy >= 0; buy--)
        {
            // if already buy then sell stock.
            if (buy)
            {
                // Sell
                int sell = prices[i] + prev[0];

                // Not Sell
                int notSell = prev[1];

                curr[buy] = max(sell, notSell);
            }
            else
            {
                // Buy
                int Buy = prev[1] - prices[i];

                // Not Buy
                int notBuy = prev[0];

                curr[buy] = max(Buy, notBuy);
            }
        }

        prev = curr;
    }

    return prev[0];
}

// Optimized T.C - O(n) & S.C. - O(1)
int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int mini = INT_MAX;

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] - mini > 0)
        {
            profit += prices[i] - mini;
            mini = prices[i];
        }
        else
        {
            mini = min(prices[i], mini);
        }
    }

    return profit;
}

int main()
{
}