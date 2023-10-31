#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int countRev(string s)
{
    if (s.size() & 1)
        return -1;

    stack<char> st;
    int ans = 0;

    for (auto ch : s)
    {
        if (ch == '{')
        {
            st.push('{');
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push('}');
            }
        }
    }

    while (!st.empty())
    {
        char ch1 = st.top();
        st.pop();

        char ch2;
        if (!st.empty())
        {
            ch2 = st.top();
            st.pop();
        }

        if (ch1 == ch2)
            ans += 1;
        else
            ans += 2;
    }

    return ans;
}
int main()
{
}