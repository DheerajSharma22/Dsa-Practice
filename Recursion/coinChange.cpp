#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &coins, int amount, int index)
{
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;
    if (index >= coins.size())
        return INT_MAX;

    int ans = INT_MAX;
    for (int i = index; i < coins.size(); i++)
    {
        int res = solve(coins, amount - coins[i], index + 1);
        if (res != INT_MAX)
        {
            ans = min(res + 1, ans);
        }
    }

    return ans;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "The ans is :- " << solve(coins, amount, 0) << endl;
}