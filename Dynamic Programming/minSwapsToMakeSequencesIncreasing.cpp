#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization.
int minSwapHelper(vector<int> &a, vector<int> &b, int index, int prev1, int prev2, vector<vector<int>> &dp, int isSwap)
{
    if (index >= a.size())
        return 0;
    if (dp[index][isSwap] != -1)
        return dp[index][isSwap];

    int include = INT_MAX;
    if (prev1 < b[index] && prev2 < a[index])
    {
        include = 1 + minSwapHelper(a, b, index + 1, b[index], a[index], dp, 1);
    }

    int exclude = INT_MAX;
    if (prev1 < a[index] && prev2 < b[index])
    {
        exclude = minSwapHelper(a, b, index + 1, a[index], b[index], dp, 0);
    }

    return dp[index][isSwap] = min(include, exclude);
}

// Tabulation
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> dp(nums1.size() + 10, vector<int>(2, 0));
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    for (int index = nums1.size() - 1; index >= 1; index--)
    {
        for (int isSwap = 1; isSwap >= 0; isSwap--)
        {
            int prev1 = nums1[index - 1], prev2 = nums2[index - 1];

            if (isSwap)
                swap(prev1, prev2);

            int include = INT_MAX;
            if (prev1 < nums2[index] && prev2 < nums1[index])
            {
                include = 1 + dp[index + 1][1];
            }

            int exclude = INT_MAX;
            if (prev1 < nums1[index] && prev2 < nums2[index])
            {
                exclude = dp[index + 1][0];
            }

            dp[index][isSwap] = min(include, exclude);
        }
    }

    return dp[1][0];
}

// Space Optimized.
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    // vector<vector<int>> dp(nums1.size()+10, vector<int>(2, 0));
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    vector<int> curr(2, 0);
    vector<int> next(2, 0);

    for (int index = nums1.size() - 1; index >= 1; index--)
    {
        for (int isSwap = 1; isSwap >= 0; isSwap--)
        {
            int prev1 = nums1[index - 1], prev2 = nums2[index - 1];

            if (isSwap)
                swap(prev1, prev2);

            int include = INT_MAX;
            if (prev1 < nums2[index] && prev2 < nums1[index])
            {
                include = 1 + next[1];
            }

            int exclude = INT_MAX;
            if (prev1 < nums1[index] && prev2 < nums2[index])
            {
                exclude = next[0];
            }

            curr[isSwap] = min(include, exclude);
        }
        next = curr;
    }

    return next[0];
}

int main()
{
}