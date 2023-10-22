#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count = 0;
bool solve(string &s, int i, int j)
{
    if (i >= j)
        return true;

    if (s[i] == s[j])
        return solve(s, i + 1, j - 1);
    else
    {
        if (count > 0)
            return false;

        count++;
        return solve(s, i + 1, j) || solve(s, i, j - 1);
    }
}
bool validPalindrome(string s)
{
    return solve(s, 0, s.size() - 1);
}

int main()
{
}