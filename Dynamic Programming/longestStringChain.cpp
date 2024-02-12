#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool checkPossible(string &a, string &b)
{
    if (a.size() != b.size() + 1)
        return false;

    int i = 0, j = 0;
    while (i < a.size())
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }

    if (i == a.size() && j == b.size())
        return true;
    return false;
}

bool static comp(string &a, string &b)
{
    return a.size() < b.size();
}

int longestStrChain(vector<string> &words)
{
    int n = words.size();

    sort(words.begin(), words.end(), comp);
    vector<int> dp(n, 1);
    int maxi = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (checkPossible(words[i], words[j]) && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
            }
        }

        if (maxi < dp[i])
            maxi = dp[i];
    }

    return maxi;
}

int main()
{
}