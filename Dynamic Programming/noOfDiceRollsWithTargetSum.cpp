#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// Memoization
int solve(int n, int k, int target, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (target == 0)
            return 1;
        return 0;
    };
    if (target < 0)
        return 0;

    if (dp[n][target] != -1)
        return dp[n][target];

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans = ((ans % MOD) + (solve(n - 1, k, target - i, dp) % MOD)) % MOD;
    }

    return dp[n][target] = ans;
}

// Tabulation
int numRollsToTarget(int N, int K, int T)
{
    vector<vector<int>> dp(N + 10, vector<int>(T + 10, 0));
    dp[0][0] = 1;

    for (int n = 1; n <= N; n++)
    {
        for (int target = 1; target <= T; target++)
        {
            int ans = 0;
            for (int i = 1; i <= K; i++)
            {
                if (target - i >= 0)
                {
                    ans = ((ans % MOD) + (dp[n - 1][target - i] % MOD)) % MOD;
                }
            }

            dp[n][target] = ans;
        }
    }

    return dp[N][T];
}

// Space Optimized
int numRollsToTarget(int N, int K, int T)
{
    vector<int> prev(T + 1, 0);
    vector<int> curr(T + 1, 0);
    prev[0] = 1;

    for (int n = 1; n <= N; n++)
    {
        for (int target = 1; target <= T; target++)
        {
            int ans = 0;
            for (int i = 1; i <= K; i++)
            {
                if (target - i >= 0)
                {
                    ans = ((ans % MOD) + (prev[target - i] % MOD)) % MOD;
                }
            }

            curr[target] = ans;
        }
        prev = curr;
    }

    return curr[T];
}

int main()
{
}