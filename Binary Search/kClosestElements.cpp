#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getLowerBound(vector<int> &arr, int &key)
{
    int start = 0, end = arr.size() - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;

        else if (arr[mid] < key)
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
    vector<int> arr = {7, 36, 38, 41, 102, 107, 142, 191, 254, 265, 289, 317, 351, 371, 447, 530, 548, 645, 649, 663, 665, 674, 712, 724, 730, 742, 758, 779, 806, 843, 860, 869, 891, 943};
    int k = 6, x = 38;

    int lowerBound = getLowerBound(arr, x);
    int start = lowerBound, end = lowerBound + 1;

    if (arr[start] == x)
    {
        start--;
        k++;
    };

    vector<int> ans;
    while (end - start <= k)
    {
        if (abs(arr[start] - x) >= abs(arr[end] - x))
            ans.push_back(arr[end++]);
        else if (abs(arr[start] - x) < abs(arr[end] - x))
            ans.push_back(arr[start--]);
    }

    cout << "Printing the ans :- " << endl;
    for (auto elm : ans)
        cout << elm << " ";
}