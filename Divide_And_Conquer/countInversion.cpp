#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(long long arr[], int start, int mid, int end, long long int &count, vector<long long> &temp)
{
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            count += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    while (start <= end)
    {
        arr[start] = temp[start++];
    }
}
void mergeSort(long long arr[], int start, int end, long long int &count, vector<long long> &temp)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid, count, temp);
    mergeSort(arr, mid + 1, end, count, temp);

    merge(arr, start, mid, end, count, temp);
}
long long int inversionCount(long long arr[], long long N)
{
    long long int ans = 0;
    int start = 0, end = N - 1;
    vector<long long> temp(N);

    mergeSort(arr, start, end, ans, temp);

    return ans;
}

int main()
{
    long long arr[] = {2, 3, 4, 5, 6};
    long long n = 5;

    cout << "The ans is " << inversionCount(arr, n) << endl;
}