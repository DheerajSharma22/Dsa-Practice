#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Avoid negative distance by maximizing it.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 1e9;
        }
    }

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};
    shortest_distance(matrix);

    for (auto &vec: matrix) {
        for (auto elm: vec) cout << elm << " ";
        cout << endl;
    }
}