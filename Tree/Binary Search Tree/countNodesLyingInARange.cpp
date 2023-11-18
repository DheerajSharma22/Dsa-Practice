#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int getCount(Node *root, int l, int h)
{
    if (!root)
        return 0;

    int ans = 0;
    if (root->data <= h && root->data >= l)
        ans++;

    ans += getCount(root->left, l, h);
    ans += getCount(root->right, l, h);

    return ans;
}

int main()
{
}