#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr)
{
    int candidate = arr[0], count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            candidate = arr[i];
        }

        count = candidate == arr[i] ? count + 1 : count - 1;
    }
    return candidate;
}

int main()
{
}