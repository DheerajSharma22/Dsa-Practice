#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q)
{
    if (q.empty())
        return;

    int elm = q.front();
    q.pop();

    reverse(q);

    q.push(elm);
}

int main()
{
    queue<int> q;
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    cout << "Before reverse" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    
    reverse(q);

    cout << endl
         << "After reverse" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}