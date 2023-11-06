#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    vector<pair<int, int>> cars;
    for (int i = 0; i < position.size(); i++)
    {
        cars.push_back({position[i], speed[i]});
    }
    sort(cars.begin(), cars.end());

    stack<float> st;
    for (auto car : cars)
    {
        float time = (target - car.first) / (float)car.second;
        while (!st.empty() && time >= st.top())
        {
            st.pop();
        }
        st.push(time);
    }

    return st.size();
}
int main()
{
}