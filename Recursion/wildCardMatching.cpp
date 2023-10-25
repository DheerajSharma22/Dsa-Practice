#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isMatchingHelper(string &s, string &p, int i, int j)
{
    if (i >= s.size() && j >= p.size())
        return true;

    if (i >= s.size() && j < p.size())
    {
        while (j < p.size())
        {
            if (p[j] != '*')
                return false;
            j++;
        }

        return true;
    }

    if (p[j] == '?' || s[i] == p[j])
        return isMatchingHelper(s, p, i + 1, j + 1);

    if (p[j] == '*')
    {
        return isMatchingHelper(s, p, i, j + 1) || isMatchingHelper(s, p, i + 1, j);
    }

    return false;
}

int main()
{
}