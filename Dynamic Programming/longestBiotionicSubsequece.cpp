#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int longestBitonicSubsequence(vector<int>& nums, int n)
{
    vector<int> lis(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j] && 1 + lis[j] > lis[i])
            {
                lis[i] = 1 + lis[j];
            }
        }
    }

	vector<int> dis(n, 1);

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > nums[j] && 1 + dis[j] > dis[i])
            {
                dis[i] = 1 + dis[j];
            }
        }
    }

	int ans = 1;
	for (int i = 0; i < n; i++) {
		ans = max(ans, lis[i] + dis[i] - 1);
	}

	return ans;
}


int main () {
    
}