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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert(Node *root, int data)
{
    if (!root)
    {
        return new Node(data);
    }

    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

Node *search(Node *root, int target)
{
    if (!root)
        return NULL;

    if (target == root->data)
        return root;
    else if (target < root->data)
        return search(root->left, target);

    return search(root->right, target);
}

Node *deleteNode(Node *root, int target)
{
    // Leaf & Null Node Case.
    if (!root)
        return NULL;

    if (root->data == target)
    {
        // Delete the node.

        // If the target node is a leaf node then simply delete it and return null.
        if (!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
        // If only has left child.
        else if (root->left && !root->right)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // If only has rightt child.
        else if (root->right && !root->left)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            // First find inorder predecessor.
            Node *temp = root->left;
            while (temp->right)
                temp = temp->right;

            // Update the current node data with inorder predecessor.
            root->data = temp->data;

            // Now delete the inorder predecessor.
            root->left = deleteNode(root->left, temp->data);
        }
    }
    else if (root->data < target)
    {
        // Search the node in right.
        root->right = deleteNode(root->right, target);
    }
    else
    {
        root->left = deleteNode(root->left, target);
    }

    return root;
}

void preOrder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insert(root, 29);
    insert(root, 5);
    insert(root, 15);
    insert(root, 1);
    insert(root, 9);
    insert(root, 7);
    insert(root, 12);
    insert(root, 30);
    insert(root, 25);
    insert(root, 40);
    insert(root, 45);
    insert(root, 42);

    inOrder(root);

    deleteNode(root, 9);

    inOrder(root);
}