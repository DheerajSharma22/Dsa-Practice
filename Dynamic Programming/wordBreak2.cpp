#include <iostream>
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<string>> dp;
vector<string> solve(string &s, unordered_map<string, int> &dict, int index)
{
    if (index >= s.size())
        return {""};

    if (dp.find(index) != dp.end())
        return dp[index];

    vector<string> ans;
    string word = "";

    for (int i = index; i < s.size(); i++)
    {
        word.push_back(s[i]);
        if (dict.find(word) == dict.end())
            continue;

        auto right = solve(s, dict, i + 1);
        for (string eachRightPart : right)
        {
            string endPart;
            if (eachRightPart.size() > 0)
                endPart = " " + eachRightPart;
            ans.push_back(word + endPart);
        }
    }

    return dp[index] = ans;
}

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    unordered_map<string, int> dict;

    // Storing occurence of every word of wordDict to optimize the find operation.
    for (auto word : wordDict)
        dict[word] = 1;

    return solve(s, dict, 0);
}

int main()
{
}