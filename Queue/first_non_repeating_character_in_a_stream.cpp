#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    queue<char> q;
    unordered_map<char, int> count;
    string ans;

    for (auto ch : A)
    {
        count[ch]++;
        q.push(ch);

        // remove element that have frequency > 1.
        while (!q.empty())
        {
            if (count[q.front()] > 1)
                q.pop();
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
            ans.push_back('#');
    }

    return ans;
}
int main()
{
}