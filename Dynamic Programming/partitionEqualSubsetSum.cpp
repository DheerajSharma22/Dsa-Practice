#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Subset Sum Logic (Space Optimized).
bool isSubsetSum(vector<int> &arr, int &sum)
{
    // vector<bool> prev(sum+1);
    vector<bool> curr(sum + 1, 0);

    curr[0] = true;

    for (int i = 1; i < arr.size(); i++)
    {
        for (int target = sum; target >= 0; target--)
        {
            bool exclude = curr[target];

            bool include = false;
            if (target >= arr[i])
            {
                include = curr[target - arr[i]];
            }

            curr[target] = include | exclude;
        }

        // prev = curr;
    }

    return curr[sum];
}

bool canPartition(vector<int> &nums)
{
    if (nums.size() == 1)
        return false;

    int sum = 0;
    for (auto elem : nums)
    {
        sum += elem;
    }

    if (sum & 1)
        return false;

    int target = sum / 2;
    return isSubsetSum(nums, target);
}

int main()
{
}