#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization.
int solve(vector<int> &prices, int i, bool isBuyAllowed, int limit, vector<vector<vector<int>>> &dp)
{
    if (limit == 0 || i >= prices.size())
        return 0;

    int profit = 0;
    if (isBuyAllowed)
    {
        int include = -prices[i] + solve(prices, i + 1, 0, limit, dp);
        int exclude = 0 + solve(prices, i + 1, 1, limit, dp);

        profit = max(include, exclude);
    }
    else
    {
        int include = prices[i] + solve(prices, i + 1, 1, limit - 1, dp);
        int exclude = solve(prices, i + 1, 0, limit, dp);

        profit = max(include, exclude);
    }

    return dp[i][isBuyAllowed][limit] = profit;
}

// Tabulation.
int maxProfit(int k, vector<int> &prices)
{
    vector<vector<vector<int>>> dp(prices.size() + 10, vector<vector<int>>(2, vector<int>(k + 10, 0)));
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int isBuyAllowed = 0; isBuyAllowed < 2; isBuyAllowed++)
        {
            for (int limit = 1; limit <= k; limit++)
            {
                int profit = 0;
                if (isBuyAllowed)
                {
                    int include = -prices[i] + dp[i + 1][0][limit];
                    int exclude = 0 + dp[i + 1][1][limit];

                    profit = max(include, exclude);
                }
                else
                {
                    int include = prices[i] + dp[i + 1][1][limit - 1];
                    int exclude = dp[i + 1][0][limit];

                    profit = max(include, exclude);
                }

                dp[i][isBuyAllowed][limit] = profit;
            }
        }
    }
    return dp[0][1][k];
}

// Space Optimization
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
    vector<vector<int>> prev(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
        for (int isBuyAllowed = 0; isBuyAllowed <= 1; isBuyAllowed++)
        {
            for (int limit = 1; limit <= k; limit++)
            {
                int profit;
                if (isBuyAllowed)
                {
                    int buy = prev[0][limit] - prices[index];
                    int notBuy = prev[1][limit];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[index] + prev[1][limit - 1];
                    int notSell = prev[0][limit];

                    profit = max(sell, notSell);
                }

                curr[isBuyAllowed][limit] = profit;
            }
        }
        prev = curr;
    }

    return prev[1][k];
}

int main()
{
}