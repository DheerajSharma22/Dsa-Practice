#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int currSum = 0, maxSum = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        currSum = max(currSum + nums[i], nums[i]);
        maxSum = max(currSum, maxSum);
    }

    return maxSum;
}

int main()
{
}