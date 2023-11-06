#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string decodeString(string s)
{
    stack<string> st;
    string ans;

    for (auto ch : s)
    {
        // Close Bracket Case.
        if (ch == ']')
        {
            string str;
            while (!st.empty() && st.top() != "[")
            {
                str += st.top();
                st.pop();
            }
            st.pop();

            string digit = "";
            while (!st.empty() && (st.top() >= "0" && st.top() <= "9"))
            {
                digit += st.top();
                st.pop();
            }

            reverse(digit.begin(), digit.end());
            int num = stoi(digit);

            string temp = str;
            for (int i = 1; i < num; i++)
                str += temp;

            st.push(str);
        }
        else
        {
            string res = "";
            res += ch;
            st.push(res);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
}