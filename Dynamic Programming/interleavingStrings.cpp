#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization.
bool solve(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp)
{
    // Base Case
    if (i >= s1.size() && j >= s2.size())
        return true;
    if (i >= s1.size())
    {
        while (j < s2.size() && k < s3.size())
        {
            if (s2[j] != s3[k])
                return false;
            j++;
            k++;
        }
        return true;
    }
    if (j >= s2.size())
    {
        while (i < s1.size() && k < s3.size())
        {
            if (s1[i] != s3[k])
                return false;
            i++;
            k++;
        }
        return true;
    }

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (s1[i] != s3[k] && s2[j] != s3[k])
        return false;

    bool ans = false;
    if (s1[i] == s3[k])
    {
        ans = ans || solve(s1, s2, s3, i + 1, j, k + 1, dp);
    }

    if (s2[j] == s3[k])
    {
        ans = ans || solve(s1, s2, s3, i, j + 1, k + 1, dp);
    }

    return dp[i][j][k] = ans;
}

// Tabulation.
bool isInterleave(string s1, string s2, string s3)
{
    if (s1.size() + s2.size() != s3.size())
        return false;
    vector<vector<vector<int>>> dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, 0)));

    for (int i = 0; i <= s3.size(); i++)
    {
        dp[s1.size()][s2.size()][i] = true;
    }

    for (int j = 0; j < s2.size(); j++)
    {
        for (int k = 0; k < s3.size(); k++)
        {
            bool isTrue = true;
            int idx1 = j, idx2 = k;
            while (idx1 < s2.size() && idx2 < s3.size())
            {
                if (s2[idx1] != s3[idx2])
                {
                    isTrue = false;
                    break;
                }
                idx1++;
                idx2++;
            }
            dp[s1.size()][j][k] = isTrue;
        }
    }

    for (int j = 0; j < s1.size(); j++)
    {
        for (int k = 0; k < s3.size(); k++)
        {
            bool isTrue = true;
            int idx1 = j, idx2 = k;
            while (idx1 < s1.size() && idx2 < s3.size())
            {
                if (s1[idx1] != s3[idx2])
                {
                    isTrue = false;
                    break;
                }
                idx1++;
                idx2++;
            }
            dp[j][s2.size()][k] = isTrue;
        }
    }

    for (int i = s1.size() - 1; i >= 0; i--)
    {
        for (int j = s2.size() - 1; j >= 0; j--)
        {
            for (int k = s3.size() - 1; k >= 0; k--)
            {
                bool ans = false;
                if (s1[i] == s3[k])
                    ans = ans || dp[i + 1][j][k + 1];
                if (s2[j] == s3[k])
                    ans = ans || dp[i][j + 1][k + 1];

                dp[i][j][k] = ans;
            }
        }
    }

    return dp[0][0][0];
}

int main()
{
}