#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void DFS(vector<bool> &visited, vector<int> adj[], int src)
{
    visited[src] = true;
    for (int nbr : adj[src])
        if (!visited[nbr])
            DFS(visited, adj, nbr);
}

bool isConnected(int V, vector<int> adj[])
{
    // Step 1 :- find the node whose degree is greater than zero
    int nonZeroDegreeElem = 0;
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() > 0)
        {
            nonZeroDegreeElem = i;
            break;
        }
    }

    // Now call dfs with this nonZeroDegreeElem
    vector<bool> visited(V, 0);
    DFS(visited, adj, nonZeroDegreeElem);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && adj[i].size() > 0)
            return false;
    }

    return true;
}

int isEulerCircuit(int V, vector<int> adj[])
{
    if (!isConnected(V, adj))
        return 0;

    int countOddDegreeElements = 0;

    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() & 1)
            countOddDegreeElements++;
    }

    if (countOddDegreeElements == 2)
        return 1;
    if (countOddDegreeElements == 0)
        return 2;

    return 0;
}

int main()
{
}