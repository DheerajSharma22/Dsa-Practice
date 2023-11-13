#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
void print_left(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
        return;

    // cout << root->data << " ";
    ans.push_back(root->data);
    if (root->left)
    {
        print_left(root->left, ans);
    }
    else
    {
        print_left(root->right, ans);
    }
}

void print_leaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    // cout << root->data << " ";
    print_leaf(root->left, ans);
    print_leaf(root->right, ans);
}

void print_right(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right)
    {
        print_right(root->right, ans);
    }
    else
    {
        print_right(root->left, ans);
    }
    ans.push_back(root->data);
}
vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return ans;
    }
    ans.push_back(root->data);
    print_left(root->left, ans);
    print_leaf(root, ans);
    print_right(root->right, ans);

    return ans;
}

int main()
{
}