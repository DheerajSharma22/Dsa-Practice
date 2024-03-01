#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<TreeNode*, int> dp;

    int solve(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;

        if (dp.find(root) != dp.end()) return dp[root];

        // Include Case
        int include = root -> val;
        if (root -> left) include += solve(root->left->left) + solve(root->left->right);
        if (root -> right) include+= solve(root->right->right) + solve(root->right->left);

        // Exclude Case
        int exclude = solve(root->left) + solve(root->right);

        return dp[root] = max(include, exclude);
    }
    int rob(TreeNode* root) {
        return solve(root);
    }

int main () {
    
}