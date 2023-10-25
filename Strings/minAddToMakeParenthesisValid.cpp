#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s)
{
    int closeCount = 0, openCount = 0;
    int count = 0;

    for (auto ch : s)
    {
        if (ch == '(')
            openCount++;
        else
        {
            if (openCount <= closeCount)
                closeCount--;
            else
                closeCount++;
        }
    }

    return abs(openCount - closeCount);
}
int main()
{
    cout << minAddToMakeValid("())(()") << endl;
}