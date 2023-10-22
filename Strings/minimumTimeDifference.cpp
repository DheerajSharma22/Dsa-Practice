#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMinDifference(vector<string> &timePoints)
{
    int ans = INT_MAX;
    vector<int> minutes;

    for (auto str : timePoints)
    {
        int hour = stoi(str.substr(0, 2));
        int minute = stoi(str.substr(3, 2));

        minutes.push_back(hour * 60 + minute);
    }

    sort(minutes.begin(), minutes.end());

    for (int i = 0; i < minutes.size() - 1; i++)
    {
        ans = min(ans, minutes[i + 1] - minutes[i]);
    }

    if (minutes[0] + 1440 - minutes[minutes.size() - 1] < ans)
        return minutes[0] + 1440 - minutes[minutes.size() - 1];

    return ans;
}
int main()
{
}