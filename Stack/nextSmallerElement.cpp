#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        // Pop greater elements from stack
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        // if stack empty then ans is -1.
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }

        st.push(arr[i]);
    }

    return ans;
}

int main()
{
}