#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minStoneSum(vector<int> &piles, int k)
{
    priority_queue<int> pq;
    for (auto pile : piles)
        pq.push(pile);

    while (!pq.empty())
    {
        int top = pq.top();
        pq.pop();
        top -= top / 2;
        k--;

        pq.push(top);
        if (k == 0)
            break;
    }

    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    return ans;
}

int main()
{
}