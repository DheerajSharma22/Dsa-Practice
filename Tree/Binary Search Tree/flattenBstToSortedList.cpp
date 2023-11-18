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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void solve(TreeNode<int> *root, TreeNode<int> *&temp)
{
    if (!root)
        return;

    solve(root->left, temp);

    temp->right = new TreeNode<int>(root->data);
    temp = temp->right;

    solve(root->right, temp);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    TreeNode<int> *ans = new TreeNode<int>(-1);
    TreeNode<int> *temp = ans;

    solve(root, temp);

    temp = ans;
    ans = ans->right;
    temp->right = NULL;
    free(temp);
    return ans;
}

/* Another Approach by storing inorder traversal
void storeInorder(TreeNode<int> *root, vector<int> &inorder) {
    if (!root) return;

    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorder;
    storeInorder(root, inorder);

    TreeNode<int>* ans = new TreeNode<int>(inorder[0]);
    TreeNode<int>* temp = ans;
    for (int i = 1; i < inorder.size(); i++) {
        TreeNode<int>* toAdd = new TreeNode<int>(inorder[i]);
        temp -> right = toAdd;
        temp = temp -> right;
    }

    return ans;
}
*/

int main()
{
}