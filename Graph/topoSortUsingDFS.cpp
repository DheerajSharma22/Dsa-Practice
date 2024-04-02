#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void topoSortHelper(vector<int> adj[], int src, vector<int> &visited, stack<int> &st)
{
    visited[src] = true;

    for (int nbr : adj[src])
    {
        if (!visited[nbr])
            topoSortHelper(adj, nbr, visited, st);
    }

    st.push(src);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topoSortHelper(adj, i, visited, st);
    }

    int i = 0;
    while (!st.empty())
    {
        visited[i++] = st.top();
        st.pop();
    }

    return visited;
}

int main()
{
}