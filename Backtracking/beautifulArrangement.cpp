#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int n, int currNum, int &ans)
{
    if (currNum >= n + 1)
    {
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 0 && (i % currNum == 0 || currNum % i == 0))
        {
            arr[i] = currNum;
            solve(arr, n, currNum + 1, ans);
            arr[i] = 0;
        }
    }
}

int countArrangement(int n)
{
    int ans = 0;
    vector<int> arr(n + 1, 0);

    solve(arr, n, 1, ans);

    return ans;
}

int main()
{
}