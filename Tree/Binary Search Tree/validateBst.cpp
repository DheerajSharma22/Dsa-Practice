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

bool solve(TreeNode *root, long long minRange, long long maxRange)
{
    if (!root)
        return true;
    if (!(root->val > minRange && root->val < maxRange))
        return false;

    bool left = solve(root->left, minRange, root->val);
    bool right = solve(root->right, root->val, maxRange);

    return left && right;
}
bool isValidBST(TreeNode *root)
{
    long long minRange = LLONG_MIN;
    long long maxRange = LLONG_MAX;

    return solve(root, minRange, maxRange);
}

int main()
{
}