#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (j >= t.size())
        return 1;
    if (i >= s.size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int count = 0;
    if (s[i] == t[j])
    {
        count += solve(s, t, i + 1, j + 1, dp);
    }

    count += solve(s, t, i + 1, j, dp);

    return dp[i][j] = count;
}

int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (j >= t.size())
        return 1;
    if (i >= s.size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int count = 0;
    if (s[i] == t[j])
    {
        count += solve(s, t, i + 1, j + 1, dp);
    }

    count += solve(s, t, i + 1, j, dp);

    return dp[i][j] = count;
}

int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (j >= t.size())
        return 1;
    if (i >= s.size())
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int count = 0;
    if (s[i] == t[j])
    {
        count += solve(s, t, i + 1, j + 1, dp);
    }

    count += solve(s, t, i + 1, j, dp);

    return dp[i][j] = count;
}

// Tabulation.
int numDistinct(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (j == m - 1)
                dp[i][m] = 1;

            long double count = 0;
            if (s[i] == t[j])
            {
                count += dp[i+1][j + 1];
            }

            count += dp[i+1][j];

            dp[i][j] = count;
        }
    }

    return dp[0][0];
}

// 2 array optimization.
int numDistinct(string s, string t)
{
    int n = s.size(), m = t.size();
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<long double> prev(m + 1, 0);
    vector<long double> curr(m + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (j == m - 1)
                prev[m] = 1;

            long double count = 0;
            if (s[i] == t[j])
            {
                count += prev[j + 1];
            }

            count += prev[j];

            curr[j] = count;
        }
        prev = curr;
    }

    return curr[0];
}

int main()
{
}