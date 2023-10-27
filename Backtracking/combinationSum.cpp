#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &candidates, int target, int index, vector<vector<int>> &ans, vector<int> &output)
{
    if (target == 0)
    {
        ans.push_back(output);
        return;
    }
    if (index >= candidates.size() || target < 0)
        return;

    for (int i = index; i < candidates.size(); i++)
    {
        output.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i, ans, output);
        output.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> output;
    solve(candidates, target, 0, ans, output);

    return ans;
}

int main()
{
}