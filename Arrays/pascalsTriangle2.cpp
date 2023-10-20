#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    ans.push_back({1});

    for (int row = 1; row <= numRows; row++)
    {
        vector<int> prevRow = ans[row - 1];
        vector<int> currRow;

        currRow.push_back(1);
        for (int i = 1; i < prevRow.size(); i++)
        {
            currRow.push_back(prevRow[i - 1] + prevRow[i]);
        }
        currRow.push_back(1);
        ans.push_back(currRow);
    }

    return ans;
}

int main()
{
    vector<vector<int>> ans = generate(5);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}