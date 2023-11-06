#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// O(N) & O(N)
int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);

    while (st.size() > 1)
    {
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();

        if (M[A][B] == 1)
        {
            st.push(B);
        }
        else
        {
            st.push(A);
        }
    }

    int candidate = st.top();
    st.pop();

    for (int j = 0; j < n; j++)
    {
        if (candidate != j && (M[candidate][j] == 1 || M[j][candidate] == 0))
            return -1;
    }

    return candidate;
}

// O(N^2) & O(N)
int celebrity(vector<vector<int>> &M, int n)
{
    vector<int> candidates;
    for (int i = 0; i < n; i++)
    {
        if (M[0][i] == 1)
            candidates.push_back(i);
    }

    if (candidates.size() == 0)
        candidates.push_back(0);

    for (int cand : candidates)
    {
        bool celebrity = true;
        for (int i = 1; i < n; i++)
        {
            if (i == cand)
                continue;
            if (M[i][cand] != 1)
            {
                celebrity = false;
                break;
            }
        }

        if (celebrity)
        {
            for (int j = 0; j < n; j++)
            {
                if (M[cand][j] == 1)
                {
                    celebrity = false;
                }
            }

            if (celebrity)
                return cand;
        }
    }

    return -1;
}
int main()
{
}