#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &candidates, int target, int index, vector<vector<int>> &ans, vector<int> &output)
{
    if (index >= candidates.size())
    {
        if (target == 0)
            ans.push_back(output);
        return;
    }
    if (target == 0)
    {
        ans.push_back(output);
        return;
    }
    if (target < 0)
        return;

    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        output.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1, ans, output);
        output.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> output;
    solve(candidates, target, 0, ans, output);

    return ans;
}

int main()
{
}