#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int> arr, int n)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    vector<int> ans;
    for (auto elm : mp)
        if (elm.second > 1)
            ans.push_back(elm.first);
    for (int i = 1; i <= n; i++)
        if (mp.find(i) == mp.end())
            ans.push_back(i);

    return ans;
}

vector<int> findTwoElement1(vector<int> arr, int n)
{
    // code here
    int num1 = -1, sum1 = 0, sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]);

        if (arr[index - 1] < 0)
        {
            num1 = index;
        }
        else
        {
            arr[index - 1] *= -1;
        }

        sum1 += index;
        sum2 += i + 1;
    }

    return {num1, (sum2 - sum1) + num1};
}

int main()
{
    vector<int> ans = findTwoElement1({1, 3, 4, 2, 2}, 5);
    for (auto elm : ans)
        cout << elm << " ";
}