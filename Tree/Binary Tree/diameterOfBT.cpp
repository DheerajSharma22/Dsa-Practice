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
        left = NULL;
        right = NULL;
    }
};

int height(TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int left = 1 + height(node->left);
    int right = 1 + height(node->right);

    return max(left, right);
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);
    int finalHeight = height(root->left) + height(root->right);

    return max(left, max(right, finalHeight));
}

/* Fastest way to find diameter
int ans = 0;
int height(TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int currDiameter = left + right;
    ans = max(ans, currDiameter);

    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    height(root);
    return ans;
}
*/

int main()
{
}