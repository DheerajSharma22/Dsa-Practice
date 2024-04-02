
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    // Approach using kanh's algorithm.

    // Step 1 :- Calculate indegree
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int nbr : adj[i])
        {
            indegree[nbr]++;
        }
    }

    // Step 2 :- Create a queue and push elements that have indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Step 3 :- perform bfs and store ans
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // Push the ans
        ans.push_back(front);

        for (int nbr : adj[front])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    return ans;
}

int main()
{
}