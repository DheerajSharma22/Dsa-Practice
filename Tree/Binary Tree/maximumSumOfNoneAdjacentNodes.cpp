#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

pair<int, int> solve(Node *root)
{
    if (!root)
        return {0, 0};

    auto left = solve(root->left);
    auto right = solve(root->right);

    // Include Case
    int a = left.second + right.second + root->data;

    // Exclude Case
    int b = max(left.second, left.first) + max(right.second, right.first);

    return {a, b};
}
// Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root)
{
    auto ans = solve(root);

    return max(ans.first, ans.second);
}

int main()
{
}