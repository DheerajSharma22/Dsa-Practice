#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *insertInTree(Node *root, int val, int &succ)
{
    if (!root)
    {
        return new Node(val);
    }

    if (root->data > val)
    {
        succ = root->data;
        root->left = insertInTree(root->left, val, succ);
    }
    else
    {
        root->right = insertInTree(root->right, val, succ);
    }

    return root;
}
vector<int> findLeastGreater(vector<int> &arr, int n)
{
    vector<int> ans(n);
    Node *root = NULL;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int succ = -1;
        root = insertInTree(root, arr[i], succ);
        ans[i] = succ;
    }

    return ans;
}

int main()
{
}