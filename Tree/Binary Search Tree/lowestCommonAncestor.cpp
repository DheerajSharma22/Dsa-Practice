#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return NULL;

    if (p->val < root->val && q->val < root->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if (p->val > root->val && q->val > root->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }

    return root;
}

int main()
{
}