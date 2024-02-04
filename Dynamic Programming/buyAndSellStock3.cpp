#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(vector<int> &prices, int index, bool isBuyed, int transactions, vector<vector<vector<int>>> &dp)
{
    if (transactions >= 2 || index >= prices.size())
        return 0;

    if (dp[index][isBuyed][transactions] != -1)
        return dp[index][isBuyed][transactions];

    if (isBuyed)
    { // You can sell
        int sell = prices[index] + solve(prices, index + 1, !isBuyed, transactions + 1, dp);
        int notSell = solve(prices, index + 1, isBuyed, transactions, dp);

        return dp[index][isBuyed][transactions] = max(sell, notSell);
    }
    else
    {
        int buy = solve(prices, index + 1, !isBuyed, transactions, dp) - prices[index];
        int notBuy = solve(prices, index + 1, isBuyed, transactions, dp);

        return dp[index][isBuyed][transactions] = max(buy, notBuy);
    }
}

// Tabulation.
int solveUsingTab(vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        for (int isBuyAllowed = 0; isBuyAllowed < 2; isBuyAllowed++)
        {
            for (int limit = 1; limit < 3; limit++)
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
    return dp[0][1][2];
}

// Space Optimized.
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int isBuyAllowed = 0; isBuyAllowed < 2; isBuyAllowed++)
        {
            for (int limit = 1; limit < 3; limit++)
            {
                int profit = 0;
                if (isBuyAllowed)
                {
                    int include = -prices[i] + prev[0][limit];
                    int exclude = 0 + prev[1][limit];

                    profit = max(include, exclude);
                }
                else
                {
                    int include = prices[i] + prev[1][limit - 1];
                    int exclude = prev[0][limit];

                    profit = max(include, exclude);
                }

                curr[isBuyAllowed][limit] = profit;
            }
        }
        prev = curr;
    }

    return prev[1][2];
}
int main()
{
}