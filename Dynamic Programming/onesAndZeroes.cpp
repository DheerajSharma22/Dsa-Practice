#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(vector<pair<int, int>> &arr, int m, int n, int index, vector<vector<vector<int>>> &dp)
{
    if (index >= arr.size())
        return 0;
    if (dp[m][n][index] != -1)
        return dp[m][n][index];

    // Include
    int include = 0;
    if (arr[index].first <= m && arr[index].second <= n)
    {
        include = 1 + solve(arr, m - arr[index].first, n - arr[index].second, index + 1, dp);
    }

    // Exclude
    int exclude = solve(arr, m, n, index + 1, dp);

    return dp[m][n][index] = max(include, exclude);
}

int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<pair<int, int>> zeroOneCount;

    for (auto str : strs)
    {
        int zeroCount = 0, oneCount = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '0')
                zeroCount++;
            else
                oneCount++;
        }
        zeroOneCount.push_back({zeroCount, oneCount});
    }

    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(strs.size() + 1, -1)));
    return solve(zeroOneCount, m, n, 0, dp);
}

// Tabulation
int findMaxForm(vector<string> &strs, int &M, int &N)
{
    vector<pair<int, int>> pairs;
    for (auto s : strs)
    {
        int zeroCount = 0, oneCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                zeroCount++;
            else
                oneCount++;
        }
        pairs.push_back({zeroCount, oneCount});
    }

    vector<vector<vector<int>>> dp(pairs.size() + 1, vector<vector<int>>(M + 1, vector<int>(N + 1, 0)));
    for (int index = pairs.size() - 1; index >= 0; index--)
    {
        for (int m = 0; m <= M; m++)
        {
            for (int n = 0; n <= N; n++)
            {
                // Include.
                int include = INT_MIN;
                if (m - pairs[index].first >= 0 && n - pairs[index].second >= 0)
                {
                    include = 1 + dp[index + 1][m - pairs[index].first][n - pairs[index].second];
                }

                int exclude = dp[index + 1][m][n];

                dp[index][m][n] = max(include, exclude);
            }
        }
    }

    return dp[0][M][N];
}

// Space Optimized.
int findMaxForm(vector<string> &strs, int &M, int &N)
{
    vector<pair<int, int>> pairs;
    for (auto s : strs)
    {
        int zeroCount = 0, oneCount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                zeroCount++;
            else
                oneCount++;
        }
        pairs.push_back({zeroCount, oneCount});
    }

    vector<vector<int>> curr(M + 1, vector<int>(N + 1, 0));
    vector<vector<int>> next(M + 1, vector<int>(N + 1, 0));
    for (int index = pairs.size() - 1; index >= 0; index--)
    {
        for (int m = 0; m <= M; m++)
        {
            for (int n = 0; n <= N; n++)
            {
                // Include.
                int include = INT_MIN;
                if (m - pairs[index].first >= 0 && n - pairs[index].second >= 0)
                {
                    include = 1 + next[m - pairs[index].first][n - pairs[index].second];
                }

                int exclude = next[m][n];

                curr[m][n] = max(include, exclude);
            }
        }
        next = curr;
    }

    return next[M][N];
}

int main()
{
}