#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Fastest approach.
bool ans = true;
int maxDepth(TreeNode *&root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = 1 + maxDepth(root->left);
    int right = 1 + maxDepth(root->right);

    if (abs(left - right) > 1)
    {
        ans = false;
    }

    return max(left, right);
}

bool isBalanced(TreeNode *&root)
{
    maxDepth(root);

    return ans;
}

int main()
{
}