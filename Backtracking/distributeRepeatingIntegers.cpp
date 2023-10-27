#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &quantity, unordered_map<int, int> &freq, int qIndex)
{
    if (qIndex >= quantity.size())
        return true;

    for (auto &curr : freq)
    {
        if (quantity[qIndex] <= curr.second)
        {
            curr.second -= quantity[qIndex];
            if (solve(quantity, freq, qIndex + 1))
                return true;
            curr.second += quantity[qIndex];
        }
    }

    return false;
}
bool canDistribute(vector<int> &nums, vector<int> &quantity)
{
    unordered_map<int, int> freq;
    for (auto elm : nums)
        freq[elm]++;
    sort(quantity.begin(), quantity.end(), greater<int>());

    return solve(quantity, freq, 0);
}

int main()
{
}