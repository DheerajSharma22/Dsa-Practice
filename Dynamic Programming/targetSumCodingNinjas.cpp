#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

// Count Subset With Given Sum K Question Logic.
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    // vector<vector<int>> dp(n, vector<int>(k+1, 0));
    vector<int> prev(k + 1, 0);
    vector<int> curr(k + 1, 0);

    // Base Case Conversion.
    for (int target = 0; target <= k; target++)
    {
        if (target == 0 && arr[0] == 0)
            prev[0] = 2;
        else if (target == 0 || target == arr[0])
            prev[target] = 1;
        else
            prev[target] = 0;
    }

    // Converting Recurrence.
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= k; target++)
        {
            int ans = 0;

            if (arr[index] <= target)
            {
                ans += prev[target - arr[index]];
            }

            // If we do not take the ith element.
            ans += prev[target];

            curr[target] = ans;
        }
        prev = curr;
    }

    return prev[k];
}

// Partition With Given Difference Question Logic.
int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (auto elm : arr)
        totalSum += elm;

    if ((totalSum - d) < 0 || (totalSum - d) & 1)
        return 0;
    int target = (totalSum - d) / 2;

    return findWays(arr, target);
}


// Current Question Logic.
int targetSum(int n, int target, vector<int> &arr)
{
    return countPartitions(n, target, arr);
}

int main()
{
}