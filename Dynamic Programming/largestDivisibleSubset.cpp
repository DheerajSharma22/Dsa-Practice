#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 1), hash(n);
    int lastIndex = 0;
    int maxi = 1;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }

        if (maxi < dp[i])
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(nums[lastIndex]);

    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }

    reverse(temp.begin(), temp.end());
    return temp;
}

int main()
{
}