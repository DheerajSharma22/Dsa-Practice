#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void solve(Node *&root, map<int, vector<int>> &mp, int hd)
{
    if (root == NULL)
    {
        return;
    }

    mp[hd].push_back(root->data);

    solve(root->left, mp, hd + 1);
    solve(root->right, mp, hd);
}
vector<int> diagonal(Node *root)
{
    map<int, vector<int>> mp;
    vector<int> ans;

    solve(root, mp, 0);

    for (auto it : mp)
    {
        auto &v = it.second;
        for (auto i : v)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{
}