#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(string s, int i, int j)
{
    int count = 0;
    while (i >= 0 && j < s.size() && s[i] == s[j])
    {
        i--;
        j++;
        count++;
    }

    return count;
}

int countSubstrings(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        ans += solve(s, i, i + 1);
        ans += solve(s, i, i);
    }

    return ans;
}

int main()
{
}