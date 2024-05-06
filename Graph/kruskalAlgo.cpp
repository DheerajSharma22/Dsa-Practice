#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> ranks;
vector<int> parent;

int find(int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = find(parent[node]);
}

void Union(int u, int v)
{
    int parentU = parent[u], parentV = parent[v];

    if (parentU == parentV)
        return;

    if (ranks[parentU] > ranks[parentV])
    {
        parent[parentV] = parentU;
    }
    else if (ranks[parentU] < ranks[parentV])
    {
        parent[parentU] = parentV;
    }
    else
    {
        parent[parentV] = parentU;
        ranks[parentU]++;
    }
}

int kruskalAlgo(vector<vector<int>> &mp, int V)
{
    // Initializing parent and rank vectors for dsu.
    parent.resize(V);
    ranks.resize(V, 0);
    for (int i = 0; i < V; i++)
        parent[i] = i;
        
    // Sorting the adj list basis on weight
    sort(mp.begin(), mp.end());
    int sum = 0; // Sum variable to calculate ans.

    for (auto &vec : mp)
    {
        int u = vec[1], v = vec[2], wt = vec[0];
        if (find(u) != find(v))
        {
            Union(u, v);
            sum += wt;
        }
    }

    return sum;
}

/*
    Algorithm Steps:
    1. sort the adj list basis on wt in increasing order.
    2. apply dsu in sorted list. (i.e. for an edge if it is unconnected in dsu then connect it and add its sum into the ans.)
*/

int main()
{
}