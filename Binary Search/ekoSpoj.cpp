#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &heights, int &m, int &mid)
{
    int cuttedWood = 0;

    for (int i = 0; i < heights.size(); i++) {
        if (heights[i] > mid) {
            cuttedWood += heights[i]-mid;
        }
    }

    if (cuttedWood >= m) return true;
    return false;
}

int solve(vector<int> &heights, int &n, int &m)
{
    int ans = -1;

    int start = 0, end = *max_element(heights.begin(), heights.end());

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(heights, m, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    int ans = solve(heights, n, m);
    cout << ans << endl;
}