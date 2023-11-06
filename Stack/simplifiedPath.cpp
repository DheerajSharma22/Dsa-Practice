#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void buildAns(stack<string> &st, string &ans)
{
    if (st.empty())
    {
        return;
    }

    string minTop = st.top();
    st.pop();

    buildAns(st, ans);
    ans += minTop;
}

string simplifyPath(string path)
{
    stack<string> st;

    for (int i = 0; i < path.size(); i++)
    {
        string currStr = "";

        currStr.push_back('/');
        int j = i + 1;
        while (path[j] != '/' && j < path.size())
        {
            currStr.push_back(path[j]);
            j++;
        }

        i = j - 1;

        if (currStr == "/" || currStr == "/.")
        {
            continue;
        }
        if (currStr != "/..")
        {
            st.push(currStr);
        }
        else if (!st.empty())
        {
            st.pop();
        }
    }

    string ans = st.empty() ? "/" : "";
    buildAns(st, ans);

    return ans;
}

int main()
{
}