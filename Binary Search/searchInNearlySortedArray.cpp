#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int &n, int &key)
{
    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;
        if (mid - 1 >= 0 && arr[mid - 1] == key)
            return mid - 1;
        if (mid + 1 < n && arr[mid + 1] == key)
            return mid + 1;

        if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int n = arr.size();
    int key = 3;

    cout << "The ans is :- " << search(arr, n, key) << endl;
}