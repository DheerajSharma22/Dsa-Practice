#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s)
{
    stack<int> st;
    st.push(-1);
    int maxLength = 0;

    for (int i = 0; i < s.size(); i++)
    {
        // int currLength = 0;
        char ch = s[i];

        // Open Bracket Case
        if (ch == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int len = i - st.top();
                maxLength = max(len, maxLength);
            }
        }
    }

    return maxLength;
}

int main()
{
}