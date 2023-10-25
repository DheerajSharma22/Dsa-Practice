#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &s)
{
    if (s.size() == 1)
    {
        return 1;
    }

    int index = 0, count = 1;

    char prev = s[0];

    for (int i = 1; i < s.size(); i++)
    {
        if (prev == s[i])
        {
            count++;
        }
        else
        {
            s[index++] = prev;
            if (count > 1)
            {
                int start = index;
                while (count != 0)
                {
                    s[index++] = count % 10 + '0';
                    count /= 10;
                }
                reverse(s.begin() + start, s.begin() + index);
            }
            prev = s[i];
            count = 1;
        }
    }

    s[index++] = prev;
    if (count > 1)
    {
        int start = index;
        while (count != 0)
        {
            s[index++] = count % 10 + '0';
            count /= 10;
        }
        reverse(s.begin() + start, s.begin() + index);
    }

    return index;
}
int main()
{
}