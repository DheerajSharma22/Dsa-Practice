#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[index++] = nums[i];
        }
    }

    return index;
}
int main()
{
}