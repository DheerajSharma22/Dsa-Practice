#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1 :- using hash map.
int findPairs(vector<int> &nums, int &k)
{
    unordered_map<int, int> a;
    for (int i : nums)
        a[i]++;

    int ans = 0;
    for (auto x : a)
    {
        if (k == 0 && x.second > 1)
        {
            ans++;
        }
        else if (a.find(x.first + k) != a.end())
            ans++;
    }

    return ans;
}

int main()
{
    vector<int> arr = {3, 1, 4, 1, 5};
    int k = 2;

    cout << "The ans is :- " << findPairs(arr, k) << endl;
}