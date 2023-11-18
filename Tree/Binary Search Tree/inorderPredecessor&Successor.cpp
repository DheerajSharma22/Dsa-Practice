#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1, succ = -1;

    // Find the key node.
    TreeNode *temp = root;
    while (temp && temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    if (temp)
    {
        TreeNode *leftNode = temp->left, *rightNode = temp->right;
        while (leftNode)
        {
            pred = leftNode->data;
            leftNode = leftNode->right;
        }

        while (rightNode)
        {
            succ = rightNode->data;
            rightNode = rightNode->left;
        }
    }

    return {pred, succ};
}

int main()
{
}