#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(string &output, int open, int close, vector<string> &ans)
{
    if (open == 0 && close == 0)
    {
        ans.push_back(output);
        return;
    }

    if (open > 0)
    {
        output.push_back('(');
        solve(output, open - 1, close, ans);
        output.pop_back();
    }

    if (open < close)
    {
        output.push_back(')');
        solve(output, open, close - 1, ans);
        output.pop_back();
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string output;

    solve(output, n, n, ans);

    return ans;
}

int main()
{
}