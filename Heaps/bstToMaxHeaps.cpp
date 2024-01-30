#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

void inorder(Node *root, vector<int> &arr)
{
    if (!root)
        return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void postorder(Node *root, vector<int> &arr, int &i)
{
    if (!root)
        return;

    postorder(root->left, arr, i);
    postorder(root->right, arr, i);

    root->data = arr[i++];
}

void convertToMaxHeapUtil(Node *root)
{
    vector<int> arr;
    int i = 0;
    inorder(root, arr);
    postorder(root, arr, i);
}

int main()
{
}