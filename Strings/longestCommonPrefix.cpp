#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    string ans = "";

    string temp1 = strs[0], temp2 = strs[strs.size() - 1];
    for (int i = 0; i < temp1.size() && i < temp2.size(); i++)
    {
        if (temp1[i] != temp2[i])
            break;
        ans.push_back(temp1[i]);
    }

    return ans;
}

int main()
{
}