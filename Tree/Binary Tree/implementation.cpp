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

Node *buildTree()
{
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    Node *root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void preorder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postOrder(Node *root)
{
    if (!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        auto frontNode = q.front();
        q.pop();

        if (!frontNode)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
            continue;
        }
        cout << frontNode->data << " ";

        if (frontNode->left)
        {
            q.push(frontNode->left);
        }

        if (frontNode->right)
        {
            q.push(frontNode->right);
        }
    }
}


int main()
{
    Node *root = buildTree();

    preorder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
}