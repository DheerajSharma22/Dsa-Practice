#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingElements(vector<int> &arr, int &n)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]) - 1;
        if (arr[index] < 0) continue;
        arr[index]*=-1;
    }

    for (int i =0; i < n; i++) {
        if (arr[i] >= 0) ans.push_back(i+1);
    }

    return ans;
}

vector<int> findMissingElementsInPlaceSorting(vector<int> &arr, int &n)
{
    vector<int> ans;

    int i = 0;
    while (i < n) {
        int index = arr[i] - 1;
        if (arr[index] != arr[i]) swap(arr[index], arr[i]);
        else i++;
    }

    for (int i =0; i < n; i++) {
        if (arr[i] != i+1) ans.push_back(i+1);
    }

    return ans;
}


int main()
{
    vector<int> arr = {1, 2, 3, 4, 4, 7, 7};
    int n = arr.size();

    vector<int> ans = findMissingElementsInPlaceSorting(arr, n);
    for (auto elm : ans)
        cout << elm << " ";

    cout << endl;
}