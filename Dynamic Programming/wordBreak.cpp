#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(string &word, vector<string> &wordDict)
{
    for (auto str : wordDict)
        if (str == word)
            return true;
    return false;
}

// Memoization
bool solve(string &s, vector<string> &wordDict, int index, vector<int> &dp)
{
    if (index >= s.size())
        return true;
    if (dp[index] != -1)
        return dp[index];

    string word = "";
    bool ans = false;
    for (int i = index; i < s.size(); i++)
    {
        word.push_back(s[i]);
        if (check(word, wordDict))
            ans = ans || solve(s, wordDict, i + 1, dp);
    }

    return dp[index] = ans;
}

// Tabulation
bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();

    unordered_map<string, int> wordsCount;
    for (auto word : wordDict)
        wordsCount[word]++;

    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int index = n - 1; index >= 0; index--)
    {
        string word = "";
        bool ans = dp[index];
        for (int i = index; i < n; i++)
        {
            word.push_back(s[i]);
            if (wordsCount[word])
                ans = ans || dp[i + 1];
        }

        dp[index] = ans;
    }

    return dp[0];
}

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    vector<int> dp(n + 1, -1);
    return solve(s, wordDict, 0, dp);
}

int main()
{
}