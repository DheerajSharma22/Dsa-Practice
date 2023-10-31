#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s)
{
    stack<int> st;
    int count = 0;

    for (auto ch : s)
    {
        if (ch == '(')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                count++;
            }
        }
    }

    return count + st.size();
    ;
}
int main()
{
}