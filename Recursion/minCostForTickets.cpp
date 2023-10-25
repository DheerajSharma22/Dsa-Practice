#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minCostTickets(vector<int> &days, vector<int> &costs, int index)
{
    if (index >= days.size())
        return 0;

    int oneDayAns = costs[0] + minCostTickets(days, costs, index + 1);

    int i = index;
    for (; i < days.size(); i++)
    {
        if (days[i] >= days[index] + 7)
            break;
    }
    int sevenDaysAns = costs[1] + minCostTickets(days, costs, i);

    i = index;
    for (; i < days.size(); i++)
    {
        if (days[i] >= days[index] + 30)
            break;
    }

    int thirtyDaysAns = costs[2] + minCostTickets(days, costs, i);

    return min(oneDayAns, min(sevenDaysAns, thirtyDaysAns));
}

int main()
{
}