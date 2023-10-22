#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    int freq[26] = {0};
    int n = s.size();

    int maxOccCharCount = INT_MIN;
    char maxOccChar;

    for (auto ch : s)
    {
        freq[ch - 'a']++;

        if (freq[ch - 'a'] > maxOccCharCount)
        {
            maxOccCharCount = freq[ch - 'a'];
            maxOccChar = ch;
        }
    };

    int index = 0;
    while (freq[maxOccChar - 'a'] > 0 && index < n)
    {
        s[index] = maxOccChar;
        index += 2;
        freq[maxOccChar - 'a']--;
    }

    if (freq[maxOccChar - 'a'] != 0)
        return "";

    for (int i = 0; i < 26; i++)
    {
        while (freq[i] > 0)
        {
            if (index >= n)
                index = 1;

            s[index] = i + 'a';
            index += 2;
            freq[i]--;
        }
    }

    return s;
}

int main()
{
}