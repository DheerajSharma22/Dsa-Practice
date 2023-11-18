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

TreeNode *buildTree(vector<int> &arr, int mini, int maxi, int &index)
{
    if (index >= arr.size())
        return NULL;

    if (!(arr[index] > mini && arr[index] < maxi))
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(arr[index++]);
    root->left = buildTree(arr, mini, root->val, index);
    root->right = buildTree(arr, root->val, maxi, index);

    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    long long int mini = INT_MIN;
    long long int maxi = INT_MAX;
    int index = 0;

    return buildTree(preorder, mini, maxi, index);
}

int main()
{
}