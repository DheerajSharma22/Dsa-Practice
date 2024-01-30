#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization.
int lcsHelperMem(string &str1, string &str2, int idx1, int idx2, vector<vector<int>> &dp)
{
    if (idx1 >= str1.size() || idx2 >= str2.size())
        return 0;

    if (dp[idx1][idx2] != -1)
        return dp[idx1][idx2];

    // If chars matches.
    if (str1[idx1] == str2[idx2])
    {
        return dp[idx1][idx2] = 1 + lcsHelperMem(str1, str2, idx1 + 1, idx2 + 1, dp);
    }

    int ans1 = lcsHelperMem(str1, str2, idx1 + 1, idx2, dp);
    int ans2 = lcsHelperMem(str1, str2, idx1, idx2 + 1, dp);

    return dp[idx1][idx2] = max(ans1, ans2);
}

// Tabulation.
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int idx1 = n - 1; idx1 >= 0; idx1--)
    {
        for (int idx2 = m - 1; idx2 >= 0; idx2--)
        {
            // If chars matches.
            if (text1[idx1] == text2[idx2])
            {
                dp[idx1][idx2] = 1 + dp[idx1 + 1][idx2 + 1];
            }
            else
            {
                int ans1 = dp[idx1 + 1][idx2];
                int ans2 = dp[idx1][idx2 + 1];
                dp[idx1][idx2] = max(ans1, ans2);
            }
        }
    }

    return dp[0][0];
}

// Space Optimized.
int lcsHelperSpaceOptimized(string &text1, string &text2)
{
    int n = text1.size(), m = text2.size();
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + prev[j + 1];
            }
            else
            {
                ans = max(prev[j], curr[j + 1]);
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