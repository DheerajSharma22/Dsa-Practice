#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int sum = 0, minLen = INT_MAX;

    int start = 0;
    for (int end = 0; end < nums.size(); end++)
    {
        sum += nums[end];

        while (sum == target)
        {
            minLen = min(minLen, (end - start) + 1);

            sum -= nums[start];
            start++;
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}

int main()
{
    vector<int> arr = {1,2,3};
    int target = 5;

    cout << minSubArrayLen(target, arr) << endl;
}