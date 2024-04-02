#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int index, int k, int n, vector<int>& dp) {
        if (index >= arr.size()) return 0;
        if (dp[index] != -1) return dp[index];
        
        int ans = INT_MIN, maxi = INT_MIN, len = 0;
        for (int i = index; i < min(n, index+k); i++) {
            len++;
            maxi = max(maxi, arr[i]);
            int res = (maxi*len) + solve(arr, i+1, k, n, dp);
            ans = max(res, ans);
        }

        return dp[index] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, 0, k, n, dp);
    }

int main () {
    
}