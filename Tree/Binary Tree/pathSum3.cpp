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

int ans = 0;
void pathSumFromOneRoot(TreeNode *root, long long sum)
{
    if (!root)
        return;

    if (root->val == sum)
        ans++;

    pathSumFromOneRoot(root->left, sum - root->val);
    pathSumFromOneRoot(root->right, sum - root->val);
}

void pathSumHelper(TreeNode *root, long long sum)
{
    if (!root)
        return;

    pathSumFromOneRoot(root, sum);

    pathSumHelper(root->left, sum);
    pathSumHelper(root->right, sum);
}

int pathSum(TreeNode *root, long long targetSum)
{
    pathSumHelper(root, targetSum);
    return ans;
}
int main()
{
}