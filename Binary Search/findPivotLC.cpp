#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &arr)
{
    int totalSum = 0, leftSum = 0;

    for (auto elm : arr)
        totalSum += elm;

    for (int i = 0; i < arr.size(); i++)
    {
        if (leftSum * 2 == totalSum - arr[i])
            return i;
        leftSum += arr[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {1,7,3,6,5,6};
    cout << "ans is :- " << pivotIndex(arr) << endl;
}