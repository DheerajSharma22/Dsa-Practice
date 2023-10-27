#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void quickSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int pivot = end;

    int i = start - 1, j = start;
    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            ++i;
            swap(arr[i], arr[j]);
        }
        j++;
    }

    swap(arr[++i], arr[pivot]);

    quickSort(arr, start, i - 1);
    quickSort(arr, i + 1, end);
}

int main()
{
    vector<int> arr = {7, 2, 1, 8, 6, 3, 5, 4};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    for (auto elm : arr)
        cout << elm << " ";
}