#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve(Node *root, int node, int &k, int &ans)
{
    if (!root)
        return false;
    if (root->data == node)
        return true;

    bool leftAns = solve(root->left, node, k, ans);
    bool rightAns = solve(root->right, node, k, ans);

    if (leftAns || rightAns)
    {
        k--;
    }

    if (k == 0)
    {
        ans = root->data;
        k = -1;
    }

    return leftAns || rightAns;
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    solve(root, node, k, ans);
    return ans;
}

int main()
{
}