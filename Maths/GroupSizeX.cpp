#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool hasGroupsSizeX(vector<int> &deck)
{
    unordered_map<int, int> count;
    int res = 0;
    for (int i : deck)
        count[i]++;
    for (auto i : count)
        res = __gcd(i.second, res);
    return res > 1;
}

int main()
{
    int n = 1 << 1;
    cout << n << endl;
}