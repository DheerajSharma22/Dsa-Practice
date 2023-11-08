#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& gas, vector<int>& cost) {
    int balance = 0;
    int deficit = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); i++) {
        balance += gas[i] - cost[i];
        if (balance < 0) {
            deficit += abs(balance);
            start = i+1;
            balance = 0;
        }
    }

    if (balance < deficit) return -1;

    return start;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 6, 2};

    cout << solve(gas, cost) << endl;
}