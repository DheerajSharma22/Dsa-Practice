#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minimumDeleteSumHelper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i >= s1.size())
    {
        int sum = 0;
        for (int k = j; k < s2.size(); k++)
        {
            sum += s2[k];
        }
        return sum;
    }

    if (j >= s2.size())
    {
        int sum = 0;
        for (int k = i; k < s1.size(); k++)
        {
            sum += s1[k];
        }
        return sum;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    if (s1[i] == s2[j])
        ans += minimumDeleteSumHelper(s1, s2, i + 1, j + 1, dp);
    else
    {
        int include = s1[i] + minimumDeleteSumHelper(s1, s2, i + 1, j, dp);
        int exclude = s2[j] + minimumDeleteSumHelper(s1, s2, i, j + 1, dp);
        ans += min(include, exclude);
    }

    return dp[i][j] = ans;
}

int minimumDeleteSumHelperTabulation(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base Case.
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][m] = s1[i] + dp[i + 1][m];
    }

    for (int i = m - 1; i >= 0; i--)
    {
        dp[n][i] = s2[i] + dp[n][i + 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;

            if (s1[i] == s2[j])
                ans += dp[i + 1][j + 1];
            else
            {
                int include = s1[i] + dp[i + 1][j];
                int exclude = s2[j] + dp[i][j + 1];

                ans += min(include, exclude);
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

int minimumDeleteSum(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return minimumDeleteSumHelper(s1, s2, 0, 0, dp);
}

int main()
{
}