#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int topElm = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(topElm);
}

void reverseStack(stack<int> &st)
{
    if (st.empty())
        return;

    int topElm = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st, topElm);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}