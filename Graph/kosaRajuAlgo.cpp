#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// This algorithm is used to find number of strongly connected components.

/*
    step 1 :- Find topo sort of given graph.
    step 2 :- Now call dfs for every element according to topo sort.
*/

void findTopoSort(stack<int> &st, vector<int> &visited, int src, unordered_map<int, vector<int>> &adj)
{
    visited[src] = true;

    for (auto nbr : adj[src])
    {
        if (!visited[nbr])
        {
            findTopoSort(st, visited, nbr, adj);
        }
    }

    st.push(src);
}

void dfs(vector<int> &visited, unordered_map<int, vector<int>> &adj, int src)
{
    visited[src] = true;

    for (auto nbr : adj[src])
    {
        if (!visited[nbr])
        {
            dfs(visited, adj, nbr);
        }
    }
}

// Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>> &adj)
{
    // Create an adjacency list.
    unordered_map<int, vector<int>> mp;
    for (auto &vec : adj)
    {
        mp[vec[0]].push_back(vec[1]);
    }

    // Step 1 :- find topo sort.
    stack<int> st;             // To store topo sort.
    vector<int> visited(V, 0); // To store the element is visited or not.

    findTopoSort(st, visited, 0, mp);

    // Step 2 :- reverse all the edges.
    mp.clear();
    for (auto &vec : adj)
    {
        mp[vec[1]].push_back(vec[0]);
    }

    // Step 3 :-
    int ans = 0;
    for (int i = 0; i < V; i++)
        visited[i] = 0;
    while (!st.empty())
    {
        if (!visited[st.top()])
        {
            ans++;
            dfs(visited, mp, st.top());
        }

        st.pop();
    }

    return ans;
}

int main()
{
}