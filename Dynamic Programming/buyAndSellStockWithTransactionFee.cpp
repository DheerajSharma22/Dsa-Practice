#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, int i, bool buy, int fee, vector<vector<int>> &dp)
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
        int sell = prices[i] + solve(prices, i, !buy, fee, dp);

        // Not Sell
        int notSell = solve(prices, i + 1, buy, fee, dp);

        return dp[i][buy] = max(sell, notSell);
    }

    // Buy
    int Buy = (solve(prices, i + 1, !buy, fee, dp) - prices[i]) - fee;

    // Not Buy
    int notBuy = solve(prices, i + 1, buy, fee, dp);

    return dp[i][buy] = max(Buy, notBuy);
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solve(prices, 0, 0, fee, dp);
}

int main()
{
}