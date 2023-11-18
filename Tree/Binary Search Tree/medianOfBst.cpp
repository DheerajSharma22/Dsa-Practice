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

int findNodes(Node *root)
{
    Node *curr = root;
    int n = 0;

    while (curr)
    {
        if (curr->left == NULL)
        {
            n++;
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }

            if (!pred->right)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                n++;
                curr = curr->right;
            }
        }
    }
    return n;
}

float findActualMedian(Node *root, int &n)
{
    Node *curr = root;
    int i = 0;

    int odd1 = (n + 1) / 2, odd1Val = -1;
    int even1 = (n / 2), even1Val = -1;
    int even2 = (n / 2) + 1, even2Val = -1;

    while (curr)
    {
        if (curr->left == NULL)
        {
            i++;
            if (i == odd1)
                odd1Val = curr->data;
            if (i == even1)
                even1Val = curr->data;
            if (i == even2)
                even2Val = curr->data;
            curr = curr->right;
        }
        else
        {
            Node *pred = curr->left;
            while (pred->right != curr && pred->right)
            {
                pred = pred->right;
            }

            if (!pred->right)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;
                i++;
                if (i == odd1)
                    odd1Val = curr->data;
                if (i == even1)
                    even1Val = curr->data;
                if (i == even2)
                    even2Val = curr->data;
                curr = curr->right;
            }
        }
    }

    float median = 0;
    if ((n & 1) == 0)
    {
        // EVEN CASE
        median = (even1Val + even2Val) / 2.0;
    }
    else
    {
        // ODD CASE
        median = odd1Val;
    }

    return median;
}

float findMedian(struct Node *root)
{
    int n = findNodes(root);

    return findActualMedian(root, n);
}

/* Another Approach.
void storeInorder(Node* root, vector<int>& inorder) {
    if (!root) return;

    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

float findMedian(struct Node *root)
{
    vector<int> inorder;
    storeInorder(root, inorder);
    int n = inorder.size();

    if (inorder.size()&1) {
        return inorder[n/2];
    }

    return float(inorder[(n/2)-1] + inorder[n/2]) / 2;
}*/

int main()
{
}