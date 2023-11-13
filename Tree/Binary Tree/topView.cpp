#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> topView(Node *root)
{
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        Node *node = q.front().first;
        int horizontalDist = q.front().second;
        q.pop();

        if (mp.find(horizontalDist) == mp.end())
            mp[horizontalDist] = node->data;

        if (node->left)
            q.push({node->left, horizontalDist - 1});
        if (node->right)
            q.push({node->right, horizontalDist + 1});
    }

    vector<int> ans;
    for (auto &it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}
int main()
{
}