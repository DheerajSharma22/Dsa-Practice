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

void iterativePreorder(Node *root)
{
    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        Node *frontNode = st.top();
        st.pop();
        cout << frontNode->data << " ";

        if (frontNode->right)
        {
            st.push(frontNode->right);
        }

        if (frontNode->left)
        {
            st.push(frontNode->left);
        }
    }
}

void iterativeInOrder(Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (curr || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

int main()
{
    Node *root = buildTree();
    iterativeInOrder(root);
}