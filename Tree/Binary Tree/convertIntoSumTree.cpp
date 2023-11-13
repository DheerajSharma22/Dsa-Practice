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

int changeTree(Node *node)
{
    if (!node)
        return 0;

    int left = changeTree(node->left);
    int right = changeTree(node->right);

    int val = node->data;
    node->data = left + right;

    return val + node->data;
}
void toSumTree(Node *node)
{
    changeTree(node);
}

int main()
{
}