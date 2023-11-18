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

class info
{
public:
    bool isValid;
    int size, min, max;
};

class Solution
{
public:
    info solve(Node *currNode, int &maxBST)
    {
        if (currNode == NULL)
        {
            // isValid, size, min, max.
            return {true, 0, INT_MAX, INT_MIN};
        }

        // Information of left and right subtrees.
        info left = solve(currNode->left, maxBST);
        info right = solve(currNode->right, maxBST);

        info currInfo;

        // Size of current subtree.
        currInfo.size = left.size + right.size + 1;

        // Updating min and max for current subtree.
        currInfo.min = min(min(left.min, right.min), currNode->data);
        currInfo.max = max(max(left.max, right.max), currNode->data);

        if (left.isValid && right.isValid && (currNode->data > left.max && currNode->data < right.min))
        {
            currInfo.isValid = true;
        }
        else
        {
            currInfo.isValid = false;
        }

        if (currInfo.isValid == true)
        {
            maxBST = max(maxBST, currInfo.size);
        }

        return currInfo;
    }
    int largestBst(Node *root)
    {
        int ans = 0;
        solve(root, ans);

        return ans;
    }
};

int main()
{
}