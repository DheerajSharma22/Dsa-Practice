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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<pair<TreeNode *, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> mp;
    q.push({root, {0, 0}});

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        TreeNode *&node = front.first;
        auto &coordinate = front.second;
        int &row = coordinate.first;
        int &col = coordinate.second;
        mp[col][row].insert(node->val);
        if (node->left)
            q.push({node->left, {row + 1, col - 1}});
        if (node->right)
            q.push({node->right, {row + 1, col + 1}});
    }

    // Copying the ans from map
    for (auto it : mp)
    {
        auto &colMap = it.second;
        vector<int> vLine;

        for (auto colMapIt : colMap)
        {
            auto &mset = colMapIt.second;
            vLine.insert(vLine.end(), mset.begin(), mset.end());
        }

        ans.push_back(vLine);
    }

    return ans;
}

int main()
{
}