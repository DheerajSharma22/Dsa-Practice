#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

/* 1st variant where you have to return array.
void inorderF(TreeNode *root, vector<int> &inorder)
{

    if (root == NULL)
    {

        return;
    }

    inorderF(root->left, inorder);

    inorder.push_back(root->data);

    inorderF(root->right, inorder);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)

{

    vector<int> inorder;

    inorderF(root1, inorder);

    inorderF(root2, inorder);

    sort(inorder.begin(), inorder.end());

    return inorder;
}

*/

/* 2nd variant where you have to return bst */
void convertBstToDLL(TreeNode *root, TreeNode *head)
{
    if (!root)
        return;

    convertBstToDLL(root->right, head);

    root->right = head;

    if (head != NULL)
        head->left = root;

    head = root;

    convertBstToDLL(root->left, head);
}

TreeNode *merge(TreeNode *head1, TreeNode *head2)
{
    TreeNode *ans = NULL;
    TreeNode *temp = NULL;

    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            if (ans == NULL)
            {
                ans = head1;
                temp = head1;
            }
            else
            {
                temp->right = head1;
                head1->left = temp;
                temp = temp->right;
                head1 = head1->right;
            }
        }
        else
        {
            if (ans == NULL)
            {
                ans = head2;
                temp = head2;
            }
            else
            {
                temp->right = head2;
                head2->left = temp;
                temp = temp->right;
                head2 = head2->right;
            }
        }
    }

    while (head1)
    {
        temp->right = head1;
        head1->left = temp;
        temp = temp->right;
        head1 = head1->right;
    }
    while (head2)
    {
        temp->right = head2;
        head2->left = temp;
        temp = temp->right;
        head2 = head1->right;
    }
    return ans;
}

int getLength(TreeNode *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->right;
    }

    return count;
}

TreeNode *buildTree(TreeNode *head, int n)
{
    if (n <= 0 || !head)
        return NULL;

    TreeNode *leftTree = buildTree(head, n / 2);

    TreeNode *root = head;
    root->left = leftTree;

    head = head->right;

    root->right = buildTree(head, n - n / 2 - 1);

    return root;
}

TreeNode *mergeTwoBst(TreeNode *root1, TreeNode *root2)
{
    // Step 1 :- Convert Bst to Sorted DLL.
    TreeNode *head1 = NULL;
    convertBstToDLL(root1, head1);
    TreeNode *head2 = NULL;
    convertBstToDLL(root2, head2);

    // Step 2 :- Merge two sorted linked lists.
    TreeNode *head = merge(head1, head2);

    // Step 3 :- Sorted linked list to bst.
    // Find length of linked list
    int n = getLength(head);

    return buildTree(head, n);
}

void print(TreeNode *root)
{
    if (!root)
        return;

    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main()
{
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(4);

    TreeNode *ans = mergeTwoBst(root1, root2);

    cout << "Printing the ans :- " << endl;
    print(root1);
}