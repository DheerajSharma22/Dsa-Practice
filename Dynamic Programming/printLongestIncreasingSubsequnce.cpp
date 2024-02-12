#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> printLIS(vector<int> &arr, int &n)
{
    vector <int> dp(n, 1), hash(n);
    int lastIndex = 0;
    int maxi = 1;

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j] && 1 + dp[j] > dp[i])
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
    temp.push_back(arr[lastIndex]);

    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(), temp.end());
    return temp;
}

int main()
{

    vector<int> arr = {5, 4, 11, 1, 16, 8};
    int n = arr.size();

    vector<int> ans = printLIS(arr, n);

    for (auto elm: ans) cout << elm << " ";
}