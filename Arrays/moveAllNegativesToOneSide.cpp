#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void segregateElements(int arr[], int n)
{
    vector<int> copy;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            copy.push_back(arr[i]);
    }

    if (copy.size() == 0)
        return;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            copy.push_back(arr[i]);
    }

    for (int i = 0; i < n; i++)
        arr[i] = copy[i];
}

int main()
{
}