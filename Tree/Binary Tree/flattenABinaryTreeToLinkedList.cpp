#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void flatten(TreeNode *root)
{
    if (root == NULL)
        return;

    TreeNode *current, *predecessor;
    current = root;

    while (current != NULL)
    {
        if (current->left != NULL)
        {
            predecessor = current->left;
            while (predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }

            predecessor->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}
int main()
{
}