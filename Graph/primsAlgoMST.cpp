#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Minimum spanning tree using prims algorithm.

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V, 0);
    int sum = 0;

    // Push 0 as source in queue.
    pq.push({0, 0});

    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (!visited[node])
        {
            visited[node] = true;
            sum += wt;

            for (auto &nbr : adj[node])
            {
                int nbrWt = nbr[1];
                int nbrNode = nbr[0];

                pq.push({nbrWt, nbrNode});
            }
        }
    }

    return sum;
}

int main()
{
}