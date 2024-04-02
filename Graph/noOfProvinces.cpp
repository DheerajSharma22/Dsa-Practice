#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &isConnected, vector<int> &visited, int i)
{
    visited[i] = true;

    for (int j = 0; j < isConnected.size(); j++)
    {
        if (!visited[j] && isConnected[i][j])
            dfs(isConnected, visited, j);
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size(), ans = 0;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(isConnected, visited, i);
            ans++;
        }
    }

    return ans;
}

int main()
{
}