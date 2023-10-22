#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isLetter(string &s, int i)
{
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
    {
        return true;
    }

    return false;
}

string reverseOnlyLetters(string s)
{
    int i = 0, j = s.size() - 1;

    while (i < j)
    {
        if (isLetter(s, i) && isLetter(s, j))
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        else if (isLetter(s, i) && !isLetter(s, j))
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return s;
}

int main()
{
}