#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    int total_length = (end - start) + 1;
    int gap = (total_length / 2) + (total_length % 2);

    while (gap > 0)
    {
        int i = start, j = start + gap;

        while (j <= end)
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
            i++;
            j++;
        }

        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main()
{
    vector<int> arr = {1, 5, 4, 3, 2, 6};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    for (auto elm : arr)
        cout << elm << " ";
}