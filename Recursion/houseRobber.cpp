#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int index)
{
    if (index >= nums.size())
    {
        return 0;
    }

    // Exclude.
    int exclude = solve(nums, index + 1);

    // Include.
    int include = nums[index] + solve(nums, index + 2);

    return max(include, exclude);
}
int main()
{
}