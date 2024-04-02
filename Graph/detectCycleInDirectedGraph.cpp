#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/***************************************** Using DFS *********************************************/
bool isCyclicHelperDFS(vector<int> adj[], int src, vector<bool> &visited,
                       vector<bool> &callStack)
{
    visited[src] = true;
    callStack[src] = true;

    bool ans = false;
    for (int nbr : adj[src])
    {
        if (!visited[nbr] && isCyclicHelperDFS(adj, nbr, visited, callStack))
            return true;
        else if (callStack[nbr])
            return true;
    }

    callStack[src] = false;

    return ans;
}

bool isCyclicDFS(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<bool> callStack(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && isCyclicHelperDFS(adj, i, visited, callStack))
            return true;
    }

    return false;
}

/***************************************** Using BFS *********************************************/
bool isCyclicBFS(int V, vector<int> adj[])
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
    int count = 0; // To track count of visited nodes
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            count++;
        }
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
            {
                q.push(nbr);
                count++;
            }
        }
    }

    // If the count of visited nodes is not equal to no. of total nodes then return true else
    // false
    return count != V;
}

int main()
{
}