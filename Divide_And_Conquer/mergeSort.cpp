#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    // Calculating Length Of Right & Left Array.
    int leftArrLength = mid - start + 1;
    int rightArrLength = end - mid;

    // Creating Left Array
    int *leftArr = new int[leftArrLength];

    // Creating Right Array
    int *rightArr = new int[rightArrLength];

    int k = start;
    // Copying Value to Left Array
    for (int i = 0; i < leftArrLength; i++)
    {
        leftArr[i] = arr[k++];
    }

    k = mid + 1;
    // Copying Value to Left Array
    for (int i = 0; i < rightArrLength; i++)
    {
        rightArr[i] = arr[k++];
    }

    // Now Merging Both Arrays.
    int leftIndex = 0, rightIndex = 0;
    int mainArrayIndex = start;

    while (leftIndex < leftArrLength && rightIndex < rightArrLength)
    {
        if (leftArr[leftIndex] < rightArr[rightIndex])
        {
            arr[mainArrayIndex] = leftArr[leftIndex++];
        }
        else
        {
            arr[mainArrayIndex] = rightArr[rightIndex++];
        }
        mainArrayIndex++;
    }

    while (leftIndex < leftArrLength)
    {
        arr[mainArrayIndex++] = leftArr[leftIndex++];
    }

    while (rightIndex < rightArrLength)
    {
        arr[mainArrayIndex++] = rightArr[rightIndex++];
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