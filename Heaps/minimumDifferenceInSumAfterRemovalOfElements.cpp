#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long minimumDifference(vector<int> &nums)
{
    int size = nums.size();
    int n = size / 3;
    vector<long long> minPossibleSum(size, 0);
    vector<long long> maxPossibleSum(size, 0);
    minPossibleSum[0] = -1;
    maxPossibleSum[size - 1] = -1;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long sum = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        sum += nums[i];
        minHeap.push(nums[i]);

        if (minHeap.size() > n)
        {
            sum -= minHeap.top();
            minHeap.pop();
        }

        if (minHeap.size() == n)
        {
            maxPossibleSum[i] = sum;
        }
    }

    sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += nums[i];
        maxHeap.push(nums[i]);

        if (maxHeap.size() > n)
        {
            sum -= maxHeap.top();
            maxHeap.pop();
        }

        if (maxHeap.size() == n)
        {
            minPossibleSum[i] = sum;
        }
    }

    long long ans = LONG_LONG_MAX;
    for (int i = n - 1; i < size - n; i++)
    {
        ans = min(ans, minPossibleSum[i] - maxPossibleSum[i + 1]);
    }

    return ans;
}

int main()
{
}