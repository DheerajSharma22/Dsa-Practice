#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{
    string ans;

    for (auto ch : s)
    {
        if (!ans.empty() && ch == ans.back())
        {
            ans.pop_back();
        }
        else
            ans.push_back(ch);
    }
    return ans;
}
    
int main()
{
    string s = "abbaca";
    cout << removeDuplicates(s) << endl;
}