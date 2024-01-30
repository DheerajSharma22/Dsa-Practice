#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    priority_queue<pair<int, int>> maxHeap;

    // Process first k window
    for (int i = 0; i < k; i++)
    {
        maxHeap.push({nums[i], i});
    }

    // Store ans of first window.
    ans.push_back(maxHeap.top().first);

    // Process remaining array
    for (int i = k; i < nums.size(); i++)
    {
        maxHeap.push({nums[i], i});

        // remove out of window elements.
        while (!maxHeap.empty() && i - maxHeap.top().second >= k)
            maxHeap.pop();

        // store ans.
        ans.push_back(maxHeap.top().first);
    }

    return ans;
}
int main()
{
}