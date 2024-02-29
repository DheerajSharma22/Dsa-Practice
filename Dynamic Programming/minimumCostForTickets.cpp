#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &days, vector<int> &costs, int index, int &n, vector<int> &dp)
{
    if (index >= n)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    // One Day Pass
    int oneDayAns = costs[0] + solve(days, costs, index + 1, n, dp);

    // Seven Days Pass
    int i = index + 1;
    for (; i < n; i++)
        if ((days[index] - 1) + 7 < days[i])
            break;
    int sevenDaysAns = costs[1] + solve(days, costs, i, n, dp);

    // Thirty Days Pass
    i = index + 1;
    for (; i < n; i++)
        if ((days[index] - 1) + 30 < days[i])
            break;
    int thirtyDaysAns = costs[2] + solve(days, costs, i, n, dp);

    return dp[index] = min(oneDayAns, min(sevenDaysAns, thirtyDaysAns));
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n + 1, -1);
    return solve(days, costs, 0, n, dp);
}

int main()
{
}