#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findOddOccElm(vector<int> &arr, int &n)
{
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        // Odd case
        if (mid & 1)
        {
            if (arr[mid] == arr[mid + 1])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (arr[mid] == arr[mid + 1])
            {
                start = mid + 2;
            }
            else
            {
                end = mid;
            }
        }
    }
    return arr[start];
}

int findOdd(vector<int> &arr, int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 4, 3, 6, 6, 4, 4};
    int n = arr.size();

    cout << "The odd occuring element is :- " << findOdd(arr, n) << endl;
}