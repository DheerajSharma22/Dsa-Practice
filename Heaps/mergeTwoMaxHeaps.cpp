#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int n, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> ans;
    for (auto elm : a)
        ans.push_back(elm);
    for (auto elm : b)
        ans.push_back(elm);

    for (int i = (ans.size() - 1) / 2; i >= 0; i--)
    {
        heapify(ans, ans.size() - 1, i);
    }

    return ans;
}

/* Optimisized Approach
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
    {
        int i = 0, j = 0;
        vector<int> ans;

        while (i < n && j < m) {
            if (b[j] > a[i]) {
                ans.push_back(b[j++]);
            }else {
                ans.push_back(a[i++]);
            }
        }

        while (i < n) {
            ans.push_back(a[i++]);
        }

        while (j < m) {
            ans.push_back(b[j++]);
        }

        return ans;
    }
*/
int main()
{
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    int n = a.size(), m = b.size();

    vector<int> ans = mergeHeaps(a, b, n, m);
    for (auto elm : ans)
        cout << elm << " ";
    cout << endl;
}