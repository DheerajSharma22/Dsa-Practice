#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid + 1 < arr.size() && mid - 1 >= 0 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;

        if (arr[mid] < arr[0])
        {
            end = mid;
        }
        else
        {
            start = mid+1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};

    cout << pivotIndex(arr) << endl;
}