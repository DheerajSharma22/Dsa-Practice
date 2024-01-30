#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isCompleteTree(Node *root)
{
    if (!root)
        return true;

    queue<Node *> q;
    q.push(root);
    bool isNullFound = false;

    while (!q.empty())
    {
        // Step A :- Get Node From Front
        Node *temp = q.front();

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

bool solve(Node *root)
{
    if (!root)
        return true;
    if (root->left && root->data < root->left->data)
        return false;
    if (root->right && root->data < root->right->data)
        return false;

    return solve(root->left) && solve(root->right);
}

bool isHeap(struct Node *tree)
{
    if (!isCompleteTree(tree))
        return false;
    return solve(tree);
}

int main()
{
}