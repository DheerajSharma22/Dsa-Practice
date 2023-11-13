#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int findPos(int arr[], int &element, int &start, int &end)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

Node *solve(int inorder[], int preorder[], int &preIndex, int inStart, int inEnd, int n)
{
    if (inStart > inEnd || preIndex >= n)
    {
        return NULL;
    }

    int element = preorder[preIndex++];
    Node *root = new Node(element);
    int index = findPos(inorder, element, inStart, inEnd);

    root->left = solve(inorder, preorder, preIndex, inStart, index - 1, n);
    root->right = solve(inorder, preorder, preIndex, index + 1, inEnd, n);

    return root;
}
int main()
{
}