#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Tabulation Of Lcs.
string longestCommonSubsequence(string text1, string text2)
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

    int len = dp[0][0];
    string ans = "";
    for (int i = 0; i <= len; i++)
        ans.push_back('0');

    // Now Generating string.
    int i = 0, j = 0, index = 0;
    while (i < n && j < m)
    {
        if (text1[i] == text2[j])
        {
            ans[index++] = text1[i];
            i++;
            j++;
        }
        else if (dp[i][j + 1] > dp[i + 1][j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return ans;
}


string shortestCommonSupersequence(string a, string b)
{
    int n = a.size(), m = b.size();

    string lcs = longestCommonSubsequence(a, b);
    string ans = "";

    int i = 0, j = 0, k = 0;
    while (i < n && j < m && k < lcs.size())
    {
        if (a[i] == b[j] && b[j] == lcs[k])
        {
            ans.push_back(a[i]);
            i++;
            j++;
            k++;
        }
        else if (a[i] == lcs[k] && b[j] != lcs[k])
        {
            ans.push_back(b[j++]);
        }
        else
        {
            ans.push_back(a[i++]);
        }
    }

    while (i < n)
    {
        ans.push_back(a[i++]);
    }

    while (j < m)
    {
        ans.push_back(b[j++]);
    }

    return ans;
}

int main()
{
}