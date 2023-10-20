#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (mid + 1 < arr.size() && arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return start;
}
int main()
{
}