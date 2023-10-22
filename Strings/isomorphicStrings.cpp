#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, char> mp, mp2;

    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) != mp.end() && t[i] != mp[s[i]])
            return false;
        if (mp2.find(t[i]) != mp2.end() && s[i] != mp2[t[i]])
            return false;

        mp2[t[i]] = s[i];
        mp[s[i]] = t[i];
    }
    return true;
}

// Another approach is using strings instead of map.

int main()
{
}