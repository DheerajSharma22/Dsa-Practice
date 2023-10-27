#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &arr, int i, int j, vector<string> &ans, string res,
           vector<vector<bool>> &visited)
{
    if (i == arr.size() - 1 && j == arr.size() - 1)
        ans.push_back(res);

    // Down
    if (i + 1 < arr.size() && arr[i + 1][j] != 0 && !visited[i + 1][j])
    {
        visited[i][j] = true;
        solve(arr, i + 1, j, ans, res + "D", visited);
        visited[i][j] = false;
    }

    // Right
    if (j + 1 < arr.size() && arr[i][j + 1] != 0 && !visited[i][j + 1])
    {
        visited[i][j] = true;
        solve(arr, i, j + 1, ans, res + "R", visited);
        visited[i][j] = false;
    }

    // Left
    if (j - 1 >= 0 && arr[i][j - 1] != 0 && !visited[i][j - 1])
    {
        visited[i][j] = true;
        solve(arr, i, j - 1, ans, res + "L", visited);
        visited[i][j] = false;
    }

    // Up
    if (i - 1 >= 0 && arr[i - 1][j] != 0 && !visited[i - 1][j])
    {
        visited[i][j] = true;
        solve(arr, i - 1, j, ans, res + "U", visited);
        visited[i][j] = false;
    }
}
int main()
{
}