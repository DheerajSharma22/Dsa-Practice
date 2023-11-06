#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<double> getCollisionTimes(vector<vector<int>> &cars)
{
    int n = cars.size();
    vector<double> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        int currPos = cars[i][0];
        int currSpeed = cars[i][1];

        while (!st.empty() && cars[st.top()][1] >= currSpeed)
        {
            st.pop();
        }

        while (!st.empty())
        {
            double collisionTime = (double)(cars[st.top()][0] - currPos) / (currSpeed - cars[st.top()][1]);

            if (ans[st.top()] == -1 || collisionTime <= ans[st.top()])
            {
                ans[i] = collisionTime;
                break;
            }
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

int main()
{
}