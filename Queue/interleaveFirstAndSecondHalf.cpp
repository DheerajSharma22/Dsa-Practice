#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeQueue(queue<int> &q)
{
    queue<int> q2;
    vector<int> ans;
    int n = q.size();

    for (int i = 0; i < n / 2; i++)
    {
        q2.push(q.front());
        q.pop();
    }

    while (!q2.empty())
    {
        ans.push_back(q2.front());
        q2.pop();
        ans.push_back(q.front());
        q.pop();
    }

    return ans;
}

int main()
{
}