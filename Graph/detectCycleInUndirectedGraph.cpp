#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/***************************************** Using DFS *********************************************/
bool isCycleHelperDFS(vector<int> adj[], int src, unordered_map<int, bool> &visited, int parent)
{
    visited[src] = true;

    bool ans = false;
    for (int nbr : adj[src])
    {
        if (nbr == parent)
            continue;
        if (visited[nbr])
            return true;
        ans = ans || isCycleHelperDFS(adj, nbr, visited, src);
    }

    return ans;
}
bool isCycleDFS(int V, vector<int> adj[])
{
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && isCycleHelperDFS(adj, i, visited, -1))
            return true;
    }

    return false;
}

/***************************************** Using BFS *********************************************/
bool isCycleHelperBFS(vector<int> adj[], int src,
                      unordered_map<int, bool> &visited, vector<int> &parent)
{

    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int nbr : adj[front])
        {
            if (nbr == parent[front])
                continue;
            if (visited[nbr])
                return true;

            q.push(nbr);
            visited[nbr] = true;
            parent[nbr] = front;
        }
    }

    return false;
}
bool isCycleBFS(int V, vector<int> adj[])
{
    unordered_map<int, bool> visited;
    vector<int> parent(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && isCycleHelperBFS(adj, i, visited, parent))
            return true;
    }

    return false;
}

int main()
{
}