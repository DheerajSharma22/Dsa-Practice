#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solveUsingTab(vector<vector<int>> &points, int &n)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Initialize the DP table for the first day (day 0)
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    // Iterate through the days starting from day 1
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            // Iterate through the tasks for the current day
            for (int task = 0; task <= 2; task++)
            {
                if (task != last)
                {
                    // Calculate the points for the current activity and add it to the
                    // maximum points obtained on the previous day (recursively calculated)
                    int activity = points[day][task] + dp[day - 1][task];
                    // Update the maximum points for the current day and last activity
                    dp[day][last] = max(dp[day][last], activity);
                }
            }
        }
    }

    // The maximum points for the last day with any activity can be found in dp[n-1][3]
    return dp[n - 1][3];
}

int solve(vector<vector<int>> &points, int &n, int row, int lastPerformed, vector<vector<int>> &dp)
{
    if (row == n - 1)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != lastPerformed)
            {
                maxi = max(maxi, points[n - 1][i]);
            }
        }

        return maxi;
    };

    if (dp[row][lastPerformed + 1] != -1)
        return dp[row][lastPerformed + 1];

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != lastPerformed)
        {
            int res = points[row][i] + solve(points, n, row + 1, i, dp);
            maxi = max(maxi, res);
        }
    }

    return dp[row][lastPerformed + 1] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n + 1, vector<int>(4, -1));
    return solve(points, n, 0, -1, dp);
}

int main()
{
}