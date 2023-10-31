#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    if (s.size() & 1)
        return false;
    stack<char> st;

    for (auto ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // Closing brackets.
            if (!st.empty())
            {
                char topElm = st.top();
                if (ch == ')' && topElm == '(')
                    st.pop();
                else if (ch == ']' && topElm == '[')
                    st.pop();
                else if (ch == '}' && topElm == '{')
                    st.pop();
                else
                    return false;
            }
            else
                return false;
        }
    }

    return st.empty();
}

int main()
{
}