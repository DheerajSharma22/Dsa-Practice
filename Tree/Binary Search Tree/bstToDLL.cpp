#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>

class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode<int> *Conver_BST_To_DLL(TreeNode<int> *root, TreeNode<int> *&head)
{
    if (!root)
    {
        return NULL;
    }

    Conver_BST_To_DLL(root->right, head);

    root->right = head;
    if (head)
    {
        head->left = root;
    }

    head = root;

    Conver_BST_To_DLL(root->left, head);
}
TreeNode<int> *bstToSortedDLL(TreeNode<int> *root)
{
    TreeNode<int> *head = NULL;
    Conver_BST_To_DLL(root, head);
    return head;
}

int main()
{
}