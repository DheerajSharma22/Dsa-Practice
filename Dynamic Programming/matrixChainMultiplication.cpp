#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int *arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + solve(arr, i, k, dp) + solve(arr, k + 1, j, dp);
        mini = min(steps, mini);
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    return solve(arr, 1, N - 1, dp);
}

// Tabulation
 
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        // return solve(arr, 1, N-1, dp);
        
        for (int i = N-1; i >= 1; i--) {
            for (int j = i+1; j < N; j++) {
                int mini = INT_MAX;
        
                for (int k = i; k < j; k++) {
                    int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(steps, mini);
                }
                
                dp[i][j] = mini;
            }
        }
        
        return dp[1][N-1];
    }

int main()
{
}