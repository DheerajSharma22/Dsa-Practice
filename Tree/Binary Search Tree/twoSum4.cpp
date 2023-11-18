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

bool search(TreeNode *root, TreeNode *curr, int k)
{
    if (!root)
        return false;
    if (root->val == k && root != curr)
        return true;

    else if (root->val < k)
        return search(root->right, curr, k);
    return search(root->left, curr, k);
}
bool solve(TreeNode *root, TreeNode *curr, int k)
{
    if (!curr)
        return false;

    if (search(root, curr, k - curr->val))
        return true;

    bool left = solve(root, curr->left, k);
    bool right = solve(root, curr->right, k);

    return left || right;
}
bool findTarget(TreeNode *root, int k)
{
    return solve(root, root, k);
}


// Approach 2.
void storeInorder(TreeNode *root, vector<int> &arr)
{
    if (!root)
        return;

    storeInorder(root->left, arr);
    arr.push_back(root->val);
    storeInorder(root->right, arr);
}

bool findTarget(TreeNode *root, int k)
{
    vector<int> arr;
    storeInorder(root, arr);

    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == k)
            return true;

        if (arr[i] + arr[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return false;
}

int main()
{
}