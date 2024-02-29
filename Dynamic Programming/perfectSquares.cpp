#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = INT_MAX;
    int i = 1;
    for (; i * i <= n; i++)
    {
        int res = 1 + solve(n - (i * i), dp);
        ans = min(ans, res);
    }

    return dp[n] = ans;
}
int numSquares(int N)
{
    vector<int> dp(N + 1, 0);

    for (int n = 1; n <= N; n++)
    {
        int ans = INT_MAX;
        int i = 1;
        for (; i * i <= n; i++)
        {
            int res = 1 + dp[n - (i * i)];
            ans = min(ans, res);
        }

        dp[n] = ans;
    }

    return dp[N];
}

int main()
{
}