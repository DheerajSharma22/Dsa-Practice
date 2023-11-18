#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right, *left;
};

void solve(Node *root, bool &ans, map<int, bool> &mp)
{
    if (!root)
    {
        return;
    }
    // Leaf Nodes
    mp[root->data] = true;
    if (!root->left && !root->right)
    {
        int x = root->data - 1 == 0 ? root->data : root->data - 1;
        if (mp[root->data + 1] && mp[x])
        {
            ans = true;
            return;
        }
    }

    solve(root->left, ans, mp);
    solve(root->right, ans, mp);
}
bool isDeadEnd(Node *root)
{
    bool ans = false;
    map<int, bool> mp;

    solve(root, ans, mp);

    return ans;
}

int main()
{
}