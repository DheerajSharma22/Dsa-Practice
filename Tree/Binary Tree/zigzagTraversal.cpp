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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    bool flag = 1;

    while (!q.empty())
    {
        int width = q.size();
        vector<int> v(width);

        for (int i = 0; i < width; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            int index = flag ? i : width - i - 1;

            v[index] = node->val;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        flag = !flag;
        ans.push_back(v);
    }

    return ans;
}

int main()
{
}