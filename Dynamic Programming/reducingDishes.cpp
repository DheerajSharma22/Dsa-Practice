#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(vector<int> &satisfaction, int index, int dishNo, vector<vector<int>> &dp)
{
    if (index >= satisfaction.size())
        return 0;

    if (dp[index][dishNo] != -1)
        return dp[index][dishNo];

    int include = (satisfaction[index] * dishNo) + solve(satisfaction, index + 1, dishNo + 1, dp);

    int exclude = solve(satisfaction, index + 1, dishNo, dp);

    return dp[index][dishNo] = max(include, exclude);
}

// Tabulation
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
    sort(satisfaction.begin(), satisfaction.end());

    for (int index = n - 1; index >= 0; index--)
    {
        for (int likeCof = n; likeCof >= 1; likeCof--)
        {
            // Include
            int include = (satisfaction[index] * likeCof) + dp[index + 1][likeCof + 1];

            // Exclude
            int exclude = 0 + dp[index + 1][likeCof];

            dp[index][likeCof] = max(include, exclude);
        }
    }

    return dp[0][1];
}

// Space Optimization
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<int> curr(n + 2, 0);
    vector<int> next(n + 2, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        for (int likeCof = n; likeCof >= 1; likeCof--)
        {
            // Include
            int include = (satisfaction[index] * likeCof) + next[likeCof + 1];

            // Exclude
            int exclude = 0 + next[likeCof];

            curr[likeCof] = max(include, exclude);
        }
        next = curr;
    }

    return curr[1];
}

int main()
{
}