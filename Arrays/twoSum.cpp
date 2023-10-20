#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Approach 1:- Using Hashmap.
vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        int newTarget = target - nums[i];
        if (mp.find(newTarget) != mp.end())
        {
            ans.push_back(i);
            ans.push_back(mp[newTarget]);
            break;
        }
        mp[nums[i]] = i;
    }

    return ans;
}

// Approach 2 :-

int main()
{
    vector<int> nums = {3, 2, 4};

    vector<int> ans = twoSum(nums, 6);
    for (auto elm : ans)
        cout << elm << " ";

    cout << endl;
}