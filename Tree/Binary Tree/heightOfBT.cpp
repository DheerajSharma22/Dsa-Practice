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

int height(Node *root)
{
    if (!root)
        return 0;

    int leftHeight = 1 + height(root->left);
    int rightHeight = 1 + height(root->right);

    return max(leftHeight, rightHeight);
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

    levelOrder(root);
    cout << endl;
    cout << height(root) << endl;
}