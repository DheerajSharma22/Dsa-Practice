#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int firstOcc(vector<int> &arr, int &key, int &n)
{
    int start = 0, end = n - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1;
        }

        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int lastOcc(vector<int> &arr, int &key, int &n)
{
    int start = 0, end = n - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;
        }

        else if (arr[mid] > key)
        {
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
    vector<int> arr = {1, 2, 2, 3, 3, 3, 3, 4, 5};
    int n = arr.size();
    int key = 3;

    cout << "The first occurence of " << key << " is :- " << lastOcc(arr, key, n) << endl;
}