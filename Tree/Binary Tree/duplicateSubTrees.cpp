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

string solve(TreeNode *root, vector<TreeNode *> &ans, unordered_map<string, int> &count)
{
    if (!root)
        return "N";

    string left = solve(root->left, ans, count);
    string right = solve(root->right, ans, count);

    string curr = to_string(root->val) + "," + left + "," + right;

    if (count[curr] == 1)
    {
        ans.push_back(root);
    }

    count[curr]++;

    return curr;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{

    vector<TreeNode *> ans;
    unordered_map<string, int> count;
    solve(root, ans, count);
    return ans;
}

int main()
{
}