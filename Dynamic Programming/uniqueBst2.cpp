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

// Recursive
vector<TreeNode *> generateTreeHelper(int start, int end)
{
    if (start > end)
        return {NULL};
    if (start == end)
        return {new TreeNode(start)};

    vector<TreeNode *> ans;

    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> left = generateTreeHelper(start, i - 1);
        vector<TreeNode *> right = generateTreeHelper(i + 1, end);
        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }

    return ans;
}
vector<TreeNode *> generateTrees(int n)
{
    return generateTreeHelper(1, n);
}

// Memoization
map<pair<int, int>, vector<TreeNode *>> dp;
vector<TreeNode *> allPossibleBST(int start, int end)
{
    if (start > end)
        return {NULL};
    if (start == end)
        return {new TreeNode(start)};

    if (dp.find({start, end}) != dp.end())
        return dp[{start, end}];

    vector<TreeNode *> ans;
    for (int i = start; i <= end; i++)
    {
        auto left = allPossibleBST(start, i - 1);
        auto right = allPossibleBST(i + 1, end);

        // Create combinations for left and right trees.
        for (int j = 0; j < left.size(); j++)
        {
            for (int k = 0; k < right.size(); k++)
            {
                TreeNode *root = new TreeNode(i);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }

    return dp[{start, end}] = ans;
}
vector<TreeNode *> generateTrees(int n)
{
    return allPossibleBST(1, n);
}

int main()
{
}