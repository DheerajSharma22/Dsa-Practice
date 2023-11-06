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
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        // if stack empty then ans is -1.
        if (st.empty())
        {
            ans[i] = n;
        }
        else
        {
            ans[i] = st.top();
        }

        st.push(i);
    }

    return ans;
}

vector<int> prevSmaller(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        // Pop greater elements from stack
        while (!st.empty() && arr[st.top()] >= arr[i])
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

        st.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> nextSmallerElm = nextSmaller(heights, n);
    vector<int> prevSmallerElm = prevSmaller(heights, n);

    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (nextSmallerElm[i] - prevSmallerElm[i] - 1) * heights[i]);
    }

    return ans;
}

int main()
{
}