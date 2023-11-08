#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q, int k)
{
    if (q.empty() || k == 0)
        return;

    int elm = q.front();
    q.pop();

    reverse(q, k - 1);

    q.push(elm);
}

queue<int> modifyQueue(queue<int> q, int k)
{
    reverse(q, k);
    int n = q.size() - k;
    while (n--)
    {
        int elm = q.front();
        q.pop();
        q.push(elm);
    }
    return q;
}

int main()
{
}