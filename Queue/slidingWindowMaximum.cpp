#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> q;

    // Process the first window of k.
    for (int i = 0; i < k; i++)
    {
        // Remove elments which are smaller than current element from queue.
        while (!q.empty() && nums[q.back()] < nums[i])
        {
            q.pop_back();
        }

        q.push_back(i);
    }

    // store ans of first window.
    ans.push_back(nums[q.front()]);

    // Process remaining elements.
    for (int i = k; i < nums.size(); i++)
    {
        // Remove out of window elements.
        while (!q.empty() && i - q.front() >= k)
            q.pop_front();

        // Remove elments which are smaller than current element from queue.
        while (!q.empty() && nums[q.back()] < nums[i])
            q.pop_back();

        // Push current element.
        q.push_back(i);

        // store ans.
        ans.push_back(nums[q.front()]);
    }

    return ans;
}

int main()
{
}