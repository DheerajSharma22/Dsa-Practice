#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(string &digits, int index, unordered_map<int, string> &mapping, string output, vector<string> &ans)
{
    if (index >= digits.size())
    {
        ans.push_back(output);
        return;
    }

    string str = mapping[digits[index] - '0'];
    for (int i = 0; i < str.size(); i++)
    {
        solve(digits, index + 1, mapping, output + str[i], ans);
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
        return ans;

    unordered_map<int, string> mapping;
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    solve(digits, 0, mapping, "", ans);

    return ans;
}

int main()
{
}