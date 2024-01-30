#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Info
{
public:
    int data, arrNo, arrIndex;

    Info(int val, int no, int index)
    {
        data = val;
        arrNo = no;
        arrIndex = index;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>> &nums)
{
    vector<int> ans;
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<Info *, vector<Info *>, compare> pq;

    int k = nums.size();
    if (k == 0)
        return ans;

    // Store First K Element In Queue.
    for (int i = 0; i < k; i++)
    {
        Info *temp = new Info(nums[i][0], i, 0);
        pq.push(temp);
        mini = min(mini, nums[i][0]);
        maxi = max(maxi, nums[i][0]);
    }

    int ansStart = mini;
    int ansEnd = maxi;

    // Now Process Remaining Elements.
    while (!pq.empty())
    {
        // Get the element from the front of the queue.
        Info *temp = pq.top();
        int elem = temp->data;
        int arrNo = temp->arrNo;
        int arrIndex = temp->arrIndex;

        // Pop the element from queue which we have fetched from queue.
        pq.pop();

        // Update the mini
        mini = elem;

        // Try to store current element in ans
        int currDiff = maxi - mini;
        int ansDiff = ansEnd - ansStart;

        if (currDiff < ansDiff)
        {
            ansStart = mini;
            ansEnd = maxi;
        }

        // Check for next element
        if (arrIndex + 1 < nums[arrNo].size())
        {
            maxi = max(maxi, nums[arrNo][arrIndex + 1]);
            Info *temp = new Info(nums[arrNo][arrIndex + 1], arrNo, arrIndex + 1);
            pq.push(temp);
        }
        else
        {
            break;
        }
    }

    // vector<int> ans;
    ans.push_back(ansStart);
    ans.push_back(ansEnd);

    return ans;
}

int main()
{
}