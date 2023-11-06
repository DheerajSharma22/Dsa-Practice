#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (auto ch : s)
    {
        if (ch == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                return true;
            }

            while (!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'))
            {
                st.pop();
            }
            st.pop();
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            continue;
        }
        else
        {
            if (st.empty())
            {
                if (ch == '(')
                {
                    st.push(ch);
                }
                continue;
            }
            st.push(ch);
        }
    }

    return !st.empty();
}

int main()
{
}