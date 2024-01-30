#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Memoization.
int solve(vector<int> &price, int rodLength, int index, vector<vector<int>> &dp)
{
    if (rodLength == 0)
        return 0;

    if (dp[rodLength][index] != -1)
        return dp[rodLength][index];

    int include = 0;
    if (rodLength >= index + 1)
    {
        include = price[index] + solve(price, rodLength - (index + 1), index, dp);
    }

    int exclude = 0;
    if (index > 0)
        exclude = solve(price, rodLength, index - 1, dp);

    return dp[rodLength][index] = max(include, exclude);
}

// Tabulation.
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int rodLength = 0; rodLength <= n; rodLength++)
    {
        for (int index = 0; index < n; index++)
        {
            int include = 0;
            if (rodLength >= index + 1)
            {
                include = price[index] + dp[rodLength - (index + 1)][index];
            }

            int exclude = 0;
            if (index > 0)
                exclude = dp[rodLength][index - 1];

            dp[rodLength][index] = max(include, exclude);
        }
    }

    return dp[n][n - 1];
}

// Space Optimized.
int cutRod(vector<int> &price, int n)
{
	vector<int> prev(n+1, 0);
	vector<int> curr(n+1, 0);

	for (int N = 0; N <= n; N++) {
		prev[N] = N * price[0];
	}
	
	for (int index = 1; index < n; index++) {
		for (int rodLength = 0; rodLength <= n; rodLength++) {

			int include = 0;
			if (rodLength >= index+1) {
				include = price[index] + curr[rodLength - (index+1)];
			}

			int exclude = prev[rodLength];

			curr[rodLength] = max(include, exclude);
		}
		prev = curr;
	}

	return prev[n];
}


int main()
{
}