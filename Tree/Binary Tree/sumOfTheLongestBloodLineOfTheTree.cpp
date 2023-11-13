#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

pair<int, int> solve(Node *root)
{
    if (!root)
        return {0, 0};
    if (!root->left && !root->right)
        return {root->data, 1};

    auto left = solve(root->left);
    auto right = solve(root->right);

    if (left.second == right.second)
        return {max(left.first, right.first) + root->data, left.second + 1};
    else if (left.second > right.second)
        return {left.first + root->data, left.second + 1};

    return {right.first + root->data, right.second + 1};
}
int sumOfLongRootToLeafPath(Node *root)
{
    return solve(root).first;
}

int main()
{
}