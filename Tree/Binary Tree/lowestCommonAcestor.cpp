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
        left = right = NULL;
    }
};

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (!root)
        return NULL;
    if (root == p || root == q)
        return root;

    Node *leftAns = lowestCommonAncestor(root->left, p, q);
    Node *rightAns = lowestCommonAncestor(root->right, p, q);

    if (leftAns && rightAns)
        return root;
    if (leftAns && !rightAns)
        return leftAns;
    if (!leftAns && rightAns)
        return rightAns;

    return NULL;
}

int main()
{
    
}