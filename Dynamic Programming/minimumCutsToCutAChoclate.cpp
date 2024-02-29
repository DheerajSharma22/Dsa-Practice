#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

int solve(vector<int> &cuts, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solve(cuts, i, k - 1, dp) + solve(cuts, k + 1, j, dp);
        ans = min(ans, cost);
    }

    return dp[i][j] = ans;
}

int cost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = i; j <= c; j++)
        {
            // if (i > j) continue;

            int ans = INT_MAX;
            for (int k = i; k <= j; k++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                ans = min(ans, cost);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][c];
}
int main()
{
}