#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
    stack<pair<int, int>> st;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int currSpan = 1;

        while (!st.empty() && price >= st.top().first)
        {
            auto elm = st.top();
            currSpan += elm.second;
            st.pop();
        }

        st.push({price, currSpan});
        return currSpan;
    }
};

int main()
{
    vector<int> arr = {100,80,60,70,60,75,85};

    StockSpanner s;

    for (auto elm: arr) {
        cout << s.next(elm) << " ";
    }
}