#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(string &s, string &p, int i, int j, vector<vector<int>> &dp)
{

    if (i >= s.length() && j >= p.length())
        return true;
    if (i >= s.length())
    {
        while (j < p.length())
        {
            if (p[j] != '*')
                return false;
            j++;
        }

        return true;
    }
    if (j >= p.length())
        return false;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == p[j] || p[j] == '?')
    {
        return dp[i][j] = solve(s, p, i + 1, j + 1, dp);
    }
    else if (p[j] == '*')
    {
        return dp[i][j] = solve(s, p, i + 1, j, dp) || solve(s, p, i, j + 1, dp);
    }

    return dp[i][j] = false;
}

// Tabulation.
bool isMatch(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    dp[n][m] = true;

    for (int j = 0; j <= m; j++)
    {
        int k = j;
        bool ans = true;

        while (k < m)
        {
            if (p[k++] != '*')
            {
                dp[n][k] = false;
                ans = false;
                break;
            }
        }

        if (ans)
        {
            dp[n][j] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        dp[i][m] = false;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == p[j] || p[j] == '?')
            {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else if (p[j] == '*')
            {
                dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[0][0];
}

// Space Optimization.
bool isMatch(string s, string p)
{
    int n = s.length(), m = p.length();

    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    prev[m] = true;

    for (int j = 0; j <= m; j++)
    {
        int k = j;
        bool ans = true;

        while (k < m)
        {
            if (p[k++] != '*')
            {
                prev[k] = false;
                ans = false;
                break;
            }
        }

        if (ans)
        {
            prev[j] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        curr[m] = false;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            bool ans;
            if (s[i] == p[j] || p[j] == '?')
            {
                ans = prev[j + 1];
            }
            else if (p[j] == '*')
            {
                ans = prev[j] || curr[j + 1];
            }
            else
            {
                ans = false;
            }

            curr[j] = ans;
        }
        prev = curr;
    }

    return prev[0];
}

int main()
{
}