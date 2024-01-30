#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    vector<vector<int>> ans;
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

    for (int i = 0; i < points.size(); i++)
    {
        int x = points[i][0], y = points[i][1];
        double dist = sqrt(x * x + y * y);

        pq.push({dist, {x, y}});
    }

    while (!pq.empty() && k--)
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        ans.push_back({x, y});
    }

    return ans;
}

int main()
{
}