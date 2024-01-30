#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Info
{
public:
    int data, arr, index;

    Info(int data, int arr, int index)
    {
        this->data = data;
        this->arr = arr;
        this->index = index;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int> ans;
    priority_queue<Info *, vector<Info *>, compare> pq;

    for (int i = 0; i < K; i++)
    {
        Info *temp = new Info(arr[i][0], i, 0);
        pq.push(temp);
    }

    // Process remaining elements.
    while (!pq.empty())
    {
        int elm = pq.top()->data;
        int arrNo = pq.top()->arr;
        int index = pq.top()->index + 1;
        pq.pop();

        ans.push_back(elm);

        if (index < arr[arrNo].size())
        {
            Info *temp = new Info(arr[arrNo][index], arrNo, index);
            pq.push(temp);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 7}, {6, 8, 9}};
    vector<int> ans = mergeKArrays(arr, 3);
    for (auto elm : ans)
        cout << elm << " ";
}