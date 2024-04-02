#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, vector<int> &b, int prev, int curr, map<pair<int, int>, int> &dp)
{
    if (curr >= a.size())
        return 0;
    if (dp.find({prev, curr}) != dp.end())
        return dp[{prev, curr}];

    int op1 = 1e9;
    if (prev < a[curr])
        op1 = solve(a, b, a[curr], curr + 1, dp);

    int op2 = 1e9;
    int index = upper_bound(b.begin(), b.end(), prev) - b.begin();
    if (index < b.size())
    {
        op2 = 1 + solve(a, b, b[index], curr + 1, dp);
    }

    return dp[{prev, curr}] = min(op1, op2);
}
int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
{
    sort(arr2.begin(), arr2.end());

    map<pair<int, int>, int> dp;

    int ans = solve(arr1, arr2, -1, 0, dp);
    return ans >= 1e9 ? -1 : ans;
}

int main()
{
}