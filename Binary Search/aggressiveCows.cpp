#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int mid, int k)
{
    int cow = arr[0], count = 1;

    for (int i = 1; i < arr.size(); i++)
    {
        if (abs(arr[i] - cow) >= mid)
        {
            cow = arr[i];
            count++;
        }
    }
    if (count >= k)
        return true;
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int start = 1, end = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(stalls, mid, k))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
}