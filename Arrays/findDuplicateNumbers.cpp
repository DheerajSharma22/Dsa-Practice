#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findDuplicate1(vector<int> &nums)
{
    int fast = nums[0];
    int slow = nums[0];

    do
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
    } while (fast != slow);

    fast = nums[0];

    while (fast != slow)
    {
        fast = nums[fast];
        slow = nums[slow];
    }

    return slow;
}

int findDuplicate(vector<int> &arr)
{
    int ans = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int elm = abs(arr[i]);
        if (arr[elm - 1] < 0)
            return abs(arr[i]);
        arr[elm - 1] *= -1;
    }

    return ans;
}

int main()
{
}