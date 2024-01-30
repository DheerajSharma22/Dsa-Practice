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

bool isCompleteTree(TreeNode *root)
{
    if (!root)
        return true;

    queue<TreeNode *> q;
    q.push(root);
    bool isNullFound = false;

    while (!q.empty())
    {
        // Step A :- Get Node From Front
        TreeNode *temp = q.front();

        // Step B :- Pop it from queue.
        q.pop();

        if (!temp)
        {
            isNullFound = true;
        }
        else
        {
            // Step D :-
            if (isNullFound)
            {
                return false;
            }
            q.push(temp->left);
            q.push(temp->right);
        }
    }

    return true;
}

int main()
{
}