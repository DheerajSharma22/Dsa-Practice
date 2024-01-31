#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lcsHelperSpaceOptimized(string &text1, string &text2)
{
    int n = text1.size(), m = text2.size();
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + prev[j + 1];
            }
            else
            {
                ans = max(prev[j], curr[j + 1]);
            }

            curr[j] = ans;
        }
        prev = curr;
    }

    return prev[0];
}

int canYouMake(string &s1, string &s2)
{
    int lcsLength = lcsHelperSpaceOptimized(s1, s2);
    int n = s1.size(), m = s2.size();
    return (n + m) - (2 * lcsLength);
}

int main()
{
}