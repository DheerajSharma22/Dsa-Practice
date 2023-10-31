#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    if (st.top() <= x)
    {
        st.push(x);
        return;
    }

    int topElm = st.top();
    st.pop();

    insertSorted(st, x);

    st.push(topElm);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
        return;

    int topElm = st.top();
    st.pop();

    sortStack(st);

    insertSorted(st, topElm);
}

int main()
{
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(5);
    st.push(1);
    st.push(4);

    sortStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}