#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// By path compression
int find(vector<int> &parent, int elm)
{
    if (parent[elm] == elm)
        return elm;
    return parent[elm] = find(parent, parent[elm]);
}

// By rank
void Union(int u, int v, vector<int> &rank, vector<int> &parent)
{
    int parent_of_u = find(parent, u);
    int parent_of_v = find(parent, v);

    if (parent_of_u == parent_of_v)
        return;

    if (rank[parent_of_u] > rank[parent_of_v])
    {
        parent[parent_of_v] = parent_of_u;
        rank[parent_of_u]++;
    }
    else if (rank[parent_of_v] > rank[parent_of_u])
    {
        parent[parent_of_u] = parent_of_v;
        rank[parent_of_v]++;
    }
    else
    {
        parent[parent_of_v] = parent_of_u;
        rank[parent_of_u]++;
    }
}

// By size
void Union(int u, int v, vector<int> &size, vector<int> &parent)
{
    int parent_of_u = find(parent, u);
    int parent_of_v = find(parent, v);

    if (parent_of_u == parent_of_v)
        return;

    if (size[parent_of_u] > size[parent_of_v])
    {
        parent[parent_of_v] = parent_of_u;
        size[parent_of_u] += size[parent_of_v];
    }
    else if (size[parent_of_v] > size[parent_of_u])
    {
        parent[parent_of_u] = parent_of_v;
        size[parent_of_v] += size[parent_of_u];
    }
    else
    {
        parent[parent_of_v] = parent_of_u;
        size[parent_of_u] += size[parent_of_v];
    }
}

int main()
{
}