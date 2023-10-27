#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> powerset; // stores all subsets
    vector<int> subset;           // temporary subset which will be updated as the recursive function executes
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrack(nums, 0);
        return powerset;
    }

    void backtrack(vector<int> &nums, int start)
    {
        powerset.push_back(subset);

        for (int i = start; i < nums.size(); i++)
        {
            // recording all subsets that include nums[i]
            subset.push_back(nums[i]);
            backtrack(nums, i + 1);

            // remove nums[i] from the present subset and move further to explore subsets that don't contain nums[i]
            subset.pop_back();
        }
    }

    void print()
    {
        for (int i = 0; i < powerset.size(); i++)
        {
            for (int j = 0; j < powerset[i].size(); j++)
            {
                cout << powerset[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution sl;
    vector<int> nums = {1, 2, 3, 4};
    sl.subsets(nums);
    sl.print();
}
