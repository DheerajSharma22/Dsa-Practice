#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;
vector<int> dijkstra(int V, unordered_map<int, vector<Pair>> &adj, int S)
{
    // Step 1 :- Create a min heap and push source(S) node with path size 0initially.
    // Create a distance array to store distances of nodes from source(S).
    vector<int> dist(V, INT_MAX); // Initially distance is INT_MAX because we have to find minimum.
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    pq.push({0, S});
    dist[S] = 0;

    // Step 2 :- Loop while min heap is not empty
    while (!pq.empty())
    {
        // Step 3 :- Take out front element's distance and node value of min heap
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        // Step 4 :- Visit neighbours and update their distance if minimum.
        for (auto nbr : adj[node])
        {
            int nbrNode = nbr.first, nbrWt = nbr.second;
            if (wt + nbrWt < dist[nbrNode])
            {
                dist[nbrNode] = wt + nbrWt;
                pq.push({nbrWt + wt, nbrNode});
            }
        }
    }

    // Step 5 :- Return the ans
    return dist;
}

int main()
{
    unordered_map<int, vector<Pair>> adj;
    adj[0].push_back({1, 1});
    adj[1].push_back({0, 1});
    adj[0].push_back({2, 6});
    adj[2].push_back({0, 6});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    int V = 3, S = 2;
    vector<int> ans = dijkstra(V, adj, S);
    for (auto elm: ans) cout << elm << " ";
    return 0;
}