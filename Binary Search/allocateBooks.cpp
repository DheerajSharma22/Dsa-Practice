#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int &n, int &m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
            if (studentCount > m)
            {
                return false;
            }
        }
    }
    return true;
}

int sum(vector<int> &arr)
{
    int ans = 0;
    for (auto elm : arr)
        ans += elm;
    return ans;
}

int findPages(vector<int> &arr, int n, int m)
{
    if (n < m)
        return -1;
    int start = 0, end = sum(arr), ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size(), m = 2;

    cout << findPages(arr, n, m) << endl;
}