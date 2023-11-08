#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)
{

    queue<long long> q;
    vector<long long> ans;

    // Process the first window of k.
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            q.push(i);
    }

    // Store the ans of first window.
    if (q.empty())
        ans.push_back(0);
    else
        ans.push_back(A[q.front()]);

    // Now process the remaining from (i.e. from k to n-1).
    for (int i = K; i < N; i++)
    {
        // Remove the out of window element.
        while (!q.empty() && i - q.front() >= K)
            q.pop();

        // check if current element is negative.
        if (A[i] < 0)
            q.push(i);


        // store the ans for current window.
        if (q.empty())
            ans.push_back(0);
        else
            ans.push_back(A[q.front()]);
    }

    // return the ans.
    return ans;
}

int main()
{
}