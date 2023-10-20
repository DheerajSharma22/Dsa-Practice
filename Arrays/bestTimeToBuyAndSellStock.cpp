#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr)
{
    int profit = 0, mini = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        profit = max(profit, arr[i] - mini);
        mini = min(mini, arr[i]);
    }

    return profit;
}

int main()
{
}