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

TreeNode *solve(vector<int> &nums, int start, int end)
{
    if (start > end)
        return NULL;
    if (start == end)
        return new TreeNode(nums[start]);

    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = solve(nums, start, mid - 1);
    root->right = solve(nums, mid + 1, end);

    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    TreeNode *root = solve(nums, 0, nums.size() - 1);
    return root;
}
int main()
{
}