#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void solve(Node *root, int hd, map<int, int> &mp)
{
    if (!root)
        return;

    solve(root->left, hd + 1, mp);
    solve(root->right, hd + 1, mp);

    if (mp.find(hd) == mp.end())
        mp[hd] = root->data;
}
vector<int> leftView(Node *root)
{
    map<int, int> mp;
    vector<int> ans;

    solve(root, 0, mp);

    for (auto &it : mp)
        ans.push_back(it.second);
    return ans;
}

int main()
{
}