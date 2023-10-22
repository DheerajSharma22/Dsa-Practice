#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Not Working Fine.
int findMissingElm(vector<int> &arr, int &n)
{
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (mid == arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return start;
}

// Working Approach.
int findMissElm(vector<int> &arr, int n)
{
    int total = n * (n + 1) / 2;
    int sum = 0;

    for (auto curr: arr) sum+=curr;

    return total - sum;
}

int main()
{
    vector<int> arr = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int n = arr.size();

    cout << findMissElm(arr, n) << endl;
}