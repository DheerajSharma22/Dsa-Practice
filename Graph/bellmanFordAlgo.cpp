#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> result(V, 1e8);
    result[S] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            if (result[u] != 1e8 && result[u] + wt < result[v])
            {
                result[v] = result[u] + wt;
            }
        }
    }

    // Code to detect -ve cylce
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], wt = edge[2];
        if (result[u] != 1e8 && result[u] + wt < result[v])
        {
            return {-1};
        }
    }

    return result;
}

int main()
{
}