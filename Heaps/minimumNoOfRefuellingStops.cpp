#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    int stops = 0;
    int dist = 0;
    int fuel = startFuel;
    int i = 0;
    priority_queue<pair<int, int>> pq;

    while (true)
    {
        while (i < stations.size())
        {
            if (stations[i][0] <= dist + fuel)
            {
                pq.push({stations[i][1], stations[i][0]});
                ++i;
            }
            else
                break;
        }

        // Travel full level of fuel
        dist += fuel;
        fuel = 0;

        // If target is reached
        if (dist >= target)
            break;

        // If no stations arrived.
        if (pq.empty())
            return -1;

        // Refuel the car
        fuel = (dist - pq.top().second) + pq.top().first;
        dist = pq.top().second;
        pq.pop();
        ++stops;
    }

    return stops;
}

int main()
{
}